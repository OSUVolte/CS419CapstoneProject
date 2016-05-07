#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
  printf("CARD TEST #1: SMITHY\n\n");

  srand(time(NULL));

  // set dominion cards - arbitrary for this test
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy};

  int np, pn, hp; // number of players, player number, hand position
  int i, j, changed, seed;
  int r, calls = 0; // result of test smithy, number of calls to smithy
  int pass[] = {0, 0, 0, 0, 0, 0}, fail[] = {0, 0, 0, 0, 0, 0}, t; // count of tests
  int before, after; // ints used to assess pass/fail criteria

  for (i = 0; i < 100; i++) { // set up 100 different sets of input conditions to test
    t = -1;
    np = rand() % 3 + 2; // random number of players between 2 and 4
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

    // -------------------------------------------------------------------------------------
    // REQT #1: FUNCTION SUCCESSFULLY COMPLETES
    // -------------------------------------------------------------------------------------
    t++;
    if (r == 0) { pass[t]++; } else {
		fail[t]++;
		if (fail[t] == 1) { // first failure of this test
          printf("Inputs that caused first failure of ... FUNCTION SUCCESSFULLY COMPLETES\n");
		  printf("pn=%d\n", pn);
		  printf("hp=%d\n\n", hp);
		}
	}

    // -------------------------------------------------------------------------------------
    // REQT #2: CURRENT PLAYER SHOULD REC'V 3 CARDS, BUT SMITHY TO BE DISCARDED, NET 2 IN HAND
    // -------------------------------------------------------------------------------------
    before = copy->handCount[pn];
    after = state->handCount[pn];
    t++;
    if (after - before == 2) { pass[t]++; } else {
		fail[t]++;
		if (fail[t] == 1) { // first failure of this test
          printf("Inputs that caused first failure of ... CURRENT PLAYER SHOULD REC'V 3 CARDS, BUT SMITHY TO BE DISCARDED, NET 2 IN HAND\n");
		  printf("pn=%d\n", pn);
		  printf("hp=%d\n\n", hp);
		}
	}

    // -------------------------------------------------------------------------------------
    // REQT #3: 3 CARDS SHOULD COME FROM HIS OWN PILE, BUT SMITHY WILL BE ADDED BACK TO THE DISCARD, NET -2
    // -------------------------------------------------------------------------------------
    before = copy->discardCount[pn] + copy->deckCount[pn];
    after = state->discardCount[pn] + state->deckCount[pn];
    t++;
    if (after - before == 2) { pass[t]++; } else {
		fail[t]++;
		if (fail[t] == 1) { // first failure of this test
          printf("Inputs that caused first failure of ... 3 CARDS SHOULD COME FROM HIS OWN PILE, BUT SMITHY WILL BE ADDED BACK TO THE DISCARD, NET -2\n");
		  printf("pn=%d\n", pn);
		  printf("hp=%d\n\n", hp);
		}
	}

    // -------------------------------------------------------------------------------------
    // REQT #4: NO STATE CHANGE FOR OTHER PLAYER(S)
    // -------------------------------------------------------------------------------------
    t++;
    for (j = 1; j <= np; j++) { // is this case j represents other player indices
	  if (j == pn) { continue; } // skip is we are on the current player

      before = copy->handCount[j];
      after = state->handCount[j];
      if (after == before) { pass[t]++; } else {
		fail[t]++;
		if (fail[t] == 1) { // first failure of this test
          printf("Inputs that caused first failure of ... NO STATE CHANGE FOR OTHER PLAYER(S)\n");
		  printf("pn=%d\n", pn);
		  printf("hp=%d\n\n", hp);
		  }
	  }

      before = copy->discardCount[j] + copy->deckCount[j];
      after = state->discardCount[j] + state->deckCount[j];
      if (after == before) { pass[t]++; } else {
		fail[t]++;
		if (fail[t] == 1) { // first failure of this test
          printf("Inputs that caused first failure of ... NO STATE CHANGE FOR OTHER PLAYER(S)\n");
		  printf("pn=%d\n", pn);
		  printf("hp=%d\n\n", hp);
		  }
	  }
    }

    // -------------------------------------------------------------------------------------
    // REQT #5: NO STATE CHANGE FOR VICTORY CARD PILE
    // -------------------------------------------------------------------------------------
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
          printf("Inputs that caused first failure of ... NO STATE CHANGE FOR VICTORY CARD PILE\n");
		  printf("pn=%d\n", pn);
		  printf("hp=%d\n\n", hp);
		}
	}

    // -------------------------------------------------------------------------------------
    // REQT #6: NO STATE CHANGE FOR KINGDOM CARD PILE
    // -------------------------------------------------------------------------------------
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
          printf("Inputs that caused first failure of ... NO STATE CHANGE FOR KINGDOM CARD PILE\n");
		  printf("pn=%d\n", pn);
		  printf("hp=%d\n\n", hp);
		}
	}

    // clean up
    free(state);
    free(copy);

}

  t = -1;
  printf("TOTAL CALLS TO smithyCardEffect(): %d\n\n", calls);

  t++;
  printf("FUNCTION SUCCESSFULLY COMPLETES\n");
  printf("-------------------------------\n");
  printf("Pass: %d\n", pass[t]);
  printf("Fail: %d\n\n", fail[t]);

  t++;
  printf("CURRENT PLAYER SHOULD REC'V 3 CARDS, BUT SMITHY TO BE DISCARDED, NET 2 IN HAND\n");
  printf("-------------------------------\n");
  printf("Pass: %d\n", pass[t]);
  printf("Fail: %d\n\n", fail[t]);

  t++;
  printf("3 CARDS SHOULD COME FROM HIS OWN PILE, BUT SMITHY WILL BE ADDED BACK TO THE DISCARD, NET -2\n");
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

  for (i = 0; i < 6; i++) {
	  printf("pass = %d, fail = %d\n", pass[i], fail[i]);

}
  return 0;
}
