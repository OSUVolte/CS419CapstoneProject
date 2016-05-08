#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printState(struct gameState *state) {
  int i, j;

  printf("  state->numPlayers=%d\n", state->numPlayers);

  printf("  state->supplyCount=[");
  for (i = 0; i <= treasure_map; i++) {
    printf("%d", state->supplyCount[i]);
    if (i != treasure_map) {
      printf(" ");
    }
  }  printf("]\n");

  printf("  state->embargoTokens=[");
  for (i = 0; i <= treasure_map; i++) {
    printf("%d", state->embargoTokens[i]);
    if (i != treasure_map) {
      printf(" ");
    }
  }
  printf("]\n");

  printf("  state->outpostPlayed=%d\n", state->outpostPlayed);
  printf("  state->outpostTurn=%d\n", state->outpostTurn);
  printf("  state->whoseTurn=%d\n", state->whoseTurn);
  printf("  state->phase=%d\n", state->phase);
  printf("  state->numActions=%d\n", state->numActions);
  printf("  state->coins=%d\n", state->coins);
  printf("  state->numBuys=%d\n", state->numBuys);

  for (i = 0; i < state->numPlayers; i++) {
    printf("  state->player %d:\n", i);
    printf("    handCount=%d\n", state->handCount[i]);
    printf("    hand=[");
    for (j = 0; j < state->handCount[i]; j++) {
      printf("%d", state->hand[i][j]);
      if (j + 1 != state->handCount[i]) {
        printf(" ");
      }
    }
    printf("]\n");
    printf("    deckCount=%d\n", state->deckCount[i]);
    printf("    deck=[");
    for (j = 0; j < state->deckCount[i]; j++) {
      printf("%d", state->deck[i][j]);
      if (j + 1 != state->deckCount[i]) {
        printf(" ");
      }
    }
    printf("]\n");
    printf("    discardCount=%d\n", state->discardCount[i]);
    printf("    discard=[");
    for (j = 0; j < state->discardCount[i]; j++) {
      printf("%d", state->discard[i][j]);
      if (j + 1 != state->discardCount[i]) {
        printf(" ");
      }
    }
    printf("]\n");
  }

  printf("  state->playedCardCount=%d\n", state->playedCardCount);
  printf("  state->playedCards=[");
  for (i = 0; i < state->playedCardCount; i++) {
    printf("%d", state->playedCards[i]);
    if (i + 1 != state->playedCardCount) {
      printf(" ");
    }
  }
  printf("]\n");

  fflush(stdout);
}

void printMemory(void const *memLoc, int totalSize, int numBytes)
{
  unsigned const char *mem = memLoc;
  int i;

  if (numBytes > totalSize || numBytes < 0) {
    numBytes = totalSize;
  }

  for (i = 0; i < numBytes; i++) {
    if ((i % 16) == 0 && i != 0) {
      printf("\n");
    }
    if ((i % 4) == 0) {
      printf(" ");
    }
    printf("%02x", mem[i]);
  }

  printf("\n");
  fflush(stdout);
};

void randomizeMemory(void *memLoc, int totalSize)
{
  unsigned char *mem = memLoc;
  int i;

  for (i = 0; i < totalSize; i++) {
    mem[i] = rand() % 256;
  }
};

int main(int argc, char *argv[]) {

  printf("CARD TEST #1: SMITHY\n");

  srand(time(NULL));

  // set dominion cards - arbitrary for this test
  int kc[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy};
  //int maxBytes = 32;
  int np, pn, hp; // number of players, player number, hand position
  int i, j, k, changed, seed;
  int r, calls = 0; // result of test smithy, number of calls to smithy
  int pass[] = {0, 0, 0, 0, 0, 0}, fail[] = {0, 0, 0, 0, 0, 0}, t; // test cnt
  int before, after; // ints used to assess pass/fail criteria

  for (i = 0; i < 100000; i++) { // different sets of input conds to test
    t = -1;

    struct gameState* state;
    struct gameState* copy;

    np = rand() % (MAX_PLAYERS - 1)  + 2; // random number players

    // random player number and hand position for this test
    pn = rand() % np; // randomnly choose player 1 to np (index 0 to np - 1)
    hp = rand() % 5; // randomnly choose hand position (0 to 4)

    if (i % 2 == 0) { // gameState created via initializeGame() w/ random inputs

      // create/initialize state
      state = malloc(sizeof(struct gameState));
      seed = rand() % 100 + 1; // random seed value between 1 and 100
      initializeGame(np, kc, seed, state);
    }
    else { // gameState completely random bytes (similar to lecture example)

      // create/initialize state
      state = malloc(sizeof(struct gameState));
      randomizeMemory(state, sizeof(*state));

      // the following statements help the segfaults go away
      // and make the cards in the deck/discard/hand more rational
      state->numPlayers = np;
      for (j = 0; j < np; j++) {
        state->deckCount[j] = rand() % MAX_DECK + 1;
        for (k = 0; k < state->deckCount[j]; k++) {
          state->deck[j][k] = rand() % 27;
        }
        state->discardCount[j] = rand() % MAX_DECK + 1;
        for (k = 0; k < state->discardCount[j]; k++) {
          state->discard[j][k] = rand() % 27;
        }
        state->handCount[j] = rand() % MAX_HAND + 1;
        for (k = 0; k < state->handCount[j]; k++) {
          state->hand[j][k] = rand() % 27;
        }
      }
      state->playedCardCount = rand() % MAX_DECK + 1;
    }

    // copy game state
    copy = malloc(sizeof(struct gameState));
    memcpy(copy, state, sizeof(struct gameState));

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
        printf("\nInputs that caused first failure of REQT #1...\n");
        printf("  FUNCTION SUCCESSFULLY COMPLETES\n");
        printf("  pn=%d\n", pn);
        printf("  hp=%d\n", hp);
        printState(state);
        //printf("1st %d bytes of state=\n", maxBytes);
        //printMemory(state, sizeof(*state), maxBytes);
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
        printf("\nInputs that caused first failure of REQT #2...\n");
        printf("  CURRENT PLAYER SHOULD REC'V 3 CARDS,\n");
        printf("  BUT SMITHY TO BE DISCARDED, NET 2 IN HAND\n");
        printf("  pn=%d\n", pn);
        printf("  hp=%d\n", hp);
        printState(state);
        //printf("1st %d bytes of state=\n", maxBytes);
        //printMemory(state, sizeof(*state), maxBytes);
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
        printf("\nInputs that caused first failure of REQT #3...\n");
        printf("  CARDS SHOULD COME FROM HIS OWN PILE,\n");
        printf("  BUT SMITHY WILL BE ADDED BACK TO THE DISCARD, NET -2\n");
        printf("  pn=%d\n", pn);
        printf("  hp=%d\n", hp);
        printState(state);
        //printf("1st %d bytes of state=\n", maxBytes);
        //printMemory(state, sizeof(*state), maxBytes);
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
          printf("\nInputs that caused first failure of REQT #4a...\n");
          printf("  NO STATE CHANGE FOR OTHER PLAYER(S)\n");
          printf("  pn=%d\n", pn);
          printf("  hp=%d\n", hp);
          printState(state);
          //printf("1st %d bytes of state=\n", maxBytes);
          //printMemory(state, sizeof(*state), maxBytes);
        }
      }

      before = copy->discardCount[j] + copy->deckCount[j];
      after = state->discardCount[j] + state->deckCount[j];

      if (after == before) { pass[t]++; } else {
        fail[t]++;
        if (fail[t] == 1) { // first failure of this test
          printf("\nInputs that caused first failure of REQT #4b...\n");
          printf("  NO STATE CHANGE FOR OTHER PLAYER(S)\n");
          printf("  pn=%d\n", pn);
          printf("  hp=%d\n", hp);
          printState(state);
          //printf("1st %d bytes of state=\n", maxBytes);
          //printMemory(state, sizeof(*state), maxBytes);
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
        printf("\nInputs that caused first failure of REQT #5...\n");
        printf("  NO STATE CHANGE FOR VICTORY CARD PILE\n");
        printf("  pn=%d\n", pn);
        printf("  hp=%d\n", hp);
        printState(state);
        //printf("1st %d bytes of state=\n", maxBytes);
        //printMemory(state, sizeof(*state), maxBytes);
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
        printf("\nInputs that caused first failure of REQT #6...\n");
        printf("  NO STATE CHANGE FOR KINGDOM CARD PILE\n");
        printf("  pn=%d\n", pn);
        printf("hp=%d\n", hp);
        printState(state);
        //printf("1st %d bytes of state=\n", maxBytes);
        //printMemory(state, sizeof(*state), maxBytes);
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


