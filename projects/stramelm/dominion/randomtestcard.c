#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_mem(void const *vp, size_t n)
{
  // http://stackoverflow.com/questions/5349896/print-a-struct-in-c
  unsigned char const *p = vp;
  size_t i;
  for (i=0; i<n; i++) {
    printf("%02x%s", p[i],
      i==0 ? "" : i % 16 == 15 ? "\n" : i % 4 == 3 ? " " : "");
  }
  putchar('\n');
};

int main(int argc, char *argv[]) {

  printf("CARD TEST #1: SMITHY\n\n");

  srand(time(NULL));

  // set dominion cards - arbitrary for this test
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy};

  int np, pn, hp; // number of players, player number, hand position
  int i, j, changed, seed;
  int r, calls = 0; // result of test smithy, number of calls to smithy
  int pass[] = {0, 0, 0, 0, 0, 0}, fail[] = {0, 0, 0, 0, 0, 0}, t; // test cnt
  int before, after; // ints used to assess pass/fail criteria

  for (i = 0; i < 100; i++) { // 100 different sets of input conds to test
    t = -1;
    np = rand() % (MAX_PLAYERS - 1)  + 2; // random number players
    seed = rand() % 100 + 1; // random seed value between 1 and 100

    // create, initialize, and copy game state
    struct gameState* state = malloc(sizeof(struct gameState));
    initializeGame(np, k, seed, state);
    struct gameState* copy = malloc(sizeof(struct gameState));
    memcpy(copy, state, sizeof(struct gameState));

    // random player number and hand position for this test
    pn = rand() % np; // randomnly choose player 1 to np (index 0 to np - 1)
    hp = rand() % 5; // randomnly choose hand position (0 to 4)

    // run the test
    r = smithyCardEffect(pn, hp, state);
    calls++;

    // -------------------------------------------------------------------------
    // REQT #1: FUNCTION SUCCESSFULLY COMPLETES
    // -------------------------------------------------------------------------
    t++;
    if (r == 0) { pass[t]++; } else {
      fail[t]++;
      if (fail[t] == 1) { // first failure of this test
        printf("Inputs that caused first failure of ...\n");
        printf("FUNCTION SUCCESSFULLY COMPLETES\n");
        printf("pn=%d\n", pn);
        printf("hp=%d\n", hp);
        printf("state=\n");
        print_mem(state, sizeof(*state));
      }
    }

    // -------------------------------------------------------------------------
    // REQT #2: CURRENT PLAYER SHOULD REC'V 3 CARDS,
    // BUT SMITHY TO BE DISCARDED, NET 2 IN HAND
    // -------------------------------------------------------------------------
    before = copy->handCount[pn];
    after = state->handCount[pn];
    t++;
    if (after - before == 2) { pass[t]++; } else {
      fail[t]++;
      if (fail[t] == 1) { // first failure of this test
        printf("Inputs that caused first failure of ...\n");
        printf("CURRENT PLAYER SHOULD REC'V 3 CARDS,\n");
        printf("BUT SMITHY TO BE DISCARDED, NET 2 IN HAND\n");
        printf("pn=%d\n", pn);
        printf("hp=%d\n", hp);
        printf("state=\n");
        print_mem(state, sizeof(*state));
      }
    }

    // -------------------------------------------------------------------------
    // REQT #3: 3 CARDS SHOULD COME FROM HIS OWN PILE,
    // BUT SMITHY WILL BE ADDED BACK TO THE DISCARD, NET -2
    // -------------------------------------------------------------------------
    before = copy->discardCount[pn] + copy->deckCount[pn];
    after = state->discardCount[pn] + state->deckCount[pn];
    t++;
    if (after - before == 2) { pass[t]++; } else {
      fail[t]++;
      if (fail[t] == 1) { // first failure of this test
        printf("Inputs that caused first failure of ...\n");
        printf("CARDS SHOULD COME FROM HIS OWN PILE,\n");
        printf("BUT SMITHY WILL BE ADDED BACK TO THE DISCARD, NET -2\n");
        printf("pn=%d\n", pn);
        printf("hp=%d\n", hp);
        printf("state=\n");
        print_mem(state, sizeof(*state));
      }
    }

    // -------------------------------------------------------------------------
    // REQT #4: NO STATE CHANGE FOR OTHER PLAYER(S)
    // -------------------------------------------------------------------------
    t++;
    for (j = 1; j <= np; j++) { // j represents other player indices

      if (j == pn) { continue; } // skip is we are on the current player

      before = copy->handCount[j];
      after = state->handCount[j];

      if (after == before) { pass[t]++; } else {
        fail[t]++;
        if (fail[t] == 1) { // first failure of this test
          printf("Inputs that caused first failure of ...\n");
          printf("NO STATE CHANGE FOR OTHER PLAYER(S)\n");
          printf("pn=%d\n", pn);
          printf("hp=%d\n", hp);
          printf("state=\n");
          print_mem(state, sizeof(*state));
        }
      }

      before = copy->discardCount[j] + copy->deckCount[j];
      after = state->discardCount[j] + state->deckCount[j];

      if (after == before) { pass[t]++; } else {
        fail[t]++;
        if (fail[t] == 1) { // first failure of this test
          printf("Inputs that caused first failure of ...\n");
          printf("NO STATE CHANGE FOR OTHER PLAYER(S)\n");
          printf("pn=%d\n", pn);
          printf("hp=%d\n", hp);
          printf("state=\n");
          print_mem(state, sizeof(*state));
        }
      }
    }

    // -------------------------------------------------------------------------
    // REQT #5: NO STATE CHANGE FOR VICTORY CARD PILE
    // -------------------------------------------------------------------------
    changed = -1; // false = -1, true = 0
    for (j = 1; j <= 3; j++) {
      before = copy->supplyCount[j];
      after = state->supplyCount[j];
      if (before != after) {
        changed = 0;
        break;
      }
    }
    t++;
    if (changed == -1) { pass[t]++; } else {
      fail[t]++;
      if (fail[t] == 1) { // first failure of this test
        printf("Inputs that caused first failure of ...\n");
        printf("NO STATE CHANGE FOR VICTORY CARD PILE\n");
        printf("pn=%d\n", pn);
        printf("hp=%d\n", hp);
        printf("state=\n");
        print_mem(state, sizeof(*state));
      }
    }

    // -------------------------------------------------------------------------
    // REQT #6: NO STATE CHANGE FOR KINGDOM CARD PILE
    // -------------------------------------------------------------------------
    changed = -1; // false = -1, true = 0
    for (j = 7; j <= 26; j++) {
      before = copy->supplyCount[j];
      after = state->supplyCount[j];
      if (before != after) {
        changed = 0;
        break;
      }
    }
    t++;
    if (changed == -1) { pass[t]++; } else {
      fail[t]++;
      if (fail[t] == 1) { // first failure of this test
        printf("Inputs that caused first failure of ...\n");
        printf("NO STATE CHANGE FOR KINGDOM CARD PILE\n");
        printf("pn=%d\n", pn);
        printf("hp=%d\n", hp);
        printf("state=\n");
        print_mem(state, sizeof(*state));
      }
    }

    // clean up
    free(state);
    free(copy);

  }

  // print summary reports from tests that were run

  t = -1;
  printf("\nTOTAL CALLS TO smithyCardEffect(): %d\n\n", calls);

  t++;
  printf("FUNCTION SUCCESSFULLY COMPLETES\n");
  printf("-------------------------------\n");
  printf("Pass: %d\n", pass[t]);
  printf("Fail: %d\n\n", fail[t]);

  t++;
  printf("CURRENT PLAYER SHOULD REC'V 3 CARDS,\n");
  printf("BUT SMITHY TO BE DISCARDED, NET 2 IN HAND\n");
  printf("-------------------------------\n");
  printf("Pass: %d\n", pass[t]);
  printf("Fail: %d\n\n", fail[t]);

  t++;
  printf("3 CARDS SHOULD COME FROM HIS OWN PILE,\n");
  printf("BUT SMITHY WILL BE ADDED BACK TO THE DISCARD, NET -2\n");
  printf("-------------------------------\n");
  printf("Pass: %d\n", pass[t]);
  printf("Fail: %d\n\n", fail[t]);

  t++;
  printf("NO STATE CHANGE FOR OTHER PLAYER(S)\n");
  printf("-------------------------------\n");
  printf("Pass: %d\n", pass[t]);
  printf("Fail: %d\n\n", fail[t]);

  t++;
  printf("NO STATE CHANGE FOR VICTORY CARD PILE\n");
  printf("-------------------------------\n");
  printf("Pass: %d\n", pass[t]);
  printf("Fail: %d\n\n", fail[t]);

  t++;
  printf("NO STATE CHANGE FOR KINGDOM CARD PILE\n");
  printf("-------------------------------\n");
  printf("Pass: %d\n", pass[t]);
  printf("Fail: %d\n\n", fail[t]);

  return 0;
}


