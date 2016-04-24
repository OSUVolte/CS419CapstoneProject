#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("UNIT TEST #4: updateCoins()\n");

  // setup dummy game state
  int np = 2;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy};
  int seed = 444; // arbitrary seed value
  struct gameState* state = malloc(sizeof(struct gameState));
  initializeGame(np, k, seed, state);

  // -------------------------------------------------------------------------------------
  // REQT: CHECK CALCULATION WITH ONLY COPPER CARDS IN HAND
  // -------------------------------------------------------------------------------------
  int pNum = 1;
  state->handCount[pNum] = 0;

  int i;
  for (i = 0; i <= 2; i++) {
    state->hand[pNum][i] = 4;
    updateCoins(pNum, state, 0);
    if (state->coins == (i * 1)) { printf("PASS"); } else { printf("FAIL"); }
    printf("ED: COINS = %d\n", state->coins);
    printf("        EXPECTATION IS COINS = %d\n", (i * 1));
    state->handCount[pNum] += 1;
  }

  // -------------------------------------------------------------------------------------
  // REQT: CHECK CALCULATION WITH ONLY SILVER CARDS IN HAND
  // -------------------------------------------------------------------------------------
  state->handCount[pNum] = 0;

  for (i = 0; i <= 2; i++) {
    state->hand[pNum][i] = 5;
    updateCoins(pNum, state, 0);
    if (state->coins == (i * 2)) { printf("PASS"); } else { printf("FAIL"); }
    printf("ED: COINS = %d\n", state->coins);
    printf("        EXPECTATION IS COINS = %d\n", (i * 2));
    state->handCount[pNum] += 1;
  }

  // -------------------------------------------------------------------------------------
  // REQT: CHECK CALCULATION WITH ONLY GOLD CARDS IN HAND
  // -------------------------------------------------------------------------------------
  state->handCount[pNum] = 0;

  for (i = 0; i <= 2; i++) {
    state->hand[pNum][i] = 6;
    updateCoins(pNum, state, 0);
    if (state->coins == (i * 3)) { printf("PASS"); } else { printf("FAIL"); }
    printf("ED: COINS = %d\n", state->coins);
    printf("        EXPECTATION IS COINS = %d\n", (i * 3));
    state->handCount[pNum] += 1;
  }

  // -------------------------------------------------------------------------------------
  // REQT: CHECK CALCULATION WITH NO CARDS
  // -------------------------------------------------------------------------------------
  state->handCount[pNum] = 0;

  updateCoins(pNum, state, 0);
  if (state->coins == 0) { printf("PASS"); } else { printf("FAIL"); }
  printf("ED: COINS = %d\n", state->coins);
  printf("        EXPECTATION IS COINS = %d\n", 0);

  // -------------------------------------------------------------------------------------
  // REQT: CHECK CALCULATION WITH A BONUS BUT NO COIN CARDS
  // -------------------------------------------------------------------------------------
  state->handCount[pNum] = 0;

  for (i = 0; i <= 2; i++) {
    updateCoins(pNum, state, i);
    if (state->coins == i) { printf("PASS"); } else { printf("FAIL"); }
    printf("ED: COINS = %d\n", state->coins);
    printf("        EXPECTATION IS COINS = %d\n", i);
  }

  // -------------------------------------------------------------------------------------
  // REQT: CHECK CALCULATION WITH A COMBINATION OF BONUS + COIN CARDS IN HAND
  // -------------------------------------------------------------------------------------
  state->handCount[pNum] = 3;

  state->hand[pNum][0] = 4;
  state->hand[pNum][1] = 5;
  state->hand[pNum][2] = 6;
  updateCoins(pNum, state, 2);
  if (state->coins == 8) { printf("PASS"); } else { printf("FAIL"); }
  printf("ED: COINS = %d\n", state->coins);
  printf("        EXPECTATION IS COINS = %d\n", 8);

  // -------------------------------------------------------------------------------------
  // REQT: CHECK CALCULATION WITH A COMBINATION OF BONUS + COIN CARDS IN DECK
  //       DECK CARDS SHOULD NOT BE COUNTED
  // -------------------------------------------------------------------------------------
  state->handCount[pNum] = 0;
  state->deckCount[pNum] = 3;

  state->deck[pNum][0] = 4;
  state->deck[pNum][1] = 5;
  state->deck[pNum][2] = 6;
  updateCoins(pNum, state, 2);
  if (state->coins == 2) { printf("PASS"); } else { printf("FAIL"); }
  printf("ED: COINS = %d\n", state->coins);
  printf("        EXPECTATION IS COINS = %d\n", 2);

  // -------------------------------------------------------------------------------------
  // REQT: CHECK CALCULATION WITH A COMBINATION OF BONUS + COIN CARDS IN DISCARD
  //       DISCARD CARDS SHOULD NOT BE COUNTED
  // -------------------------------------------------------------------------------------
  state->handCount[pNum] = 0;
  state->discardCount[pNum] = 3;

  state->discard[pNum][0] = 4;
  state->discard[pNum][1] = 5;
  state->discard[pNum][2] = 6;
  updateCoins(pNum, state, 2);
  if (state->coins == 2) { printf("PASS"); } else { printf("FAIL"); }
  printf("ED: COINS = %d\n", state->coins);
  printf("        EXPECTATION IS COINS = %d\n", 2);

  // -------------------------------------------------------------------------------------
  // REQT: CHECK CALCULATION WITH ALL NON-COIN AND OUT-OF-RANGE CARD NUMBERS
  // -------------------------------------------------------------------------------------
  state->handCount[pNum] = 0;

  for (i = -1; i <= (treasure_map + 1); i++) {
	if (i == 4 || i == 5 || i == 6) {
      state->hand[pNum][i] = 0;
	}
	else {
      state->hand[pNum][i] = i;
	}
    state->handCount[pNum] += 1;
  }
  updateCoins(pNum, state, 0);
  if (state->coins == 0) { printf("PASS"); } else { printf("FAIL"); }
  printf("ED: COINS = %d\n", state->coins);
  printf("        EXPECTATION IS COINS = %d\n", 0);

  // -------------------------------------------------------------------------------------
  // REQT: VALIDATE THAT COIN STATE PRIOR TO CALL DOESN'T AFFECT ANSWER
  // -------------------------------------------------------------------------------------
  int before;
  for (i = 0; i <=2; i++) {
    state->coins = (i + 1) * 3;
    state->handCount[pNum] = 3;

    state->hand[pNum][0] = 4;
    state->hand[pNum][1] = 5;
    state->hand[pNum][2] = 6;
    before = state->coins;
    updateCoins(pNum, state, 2);
    if (state->coins == 8) { printf("PASS"); } else { printf("FAIL"); }
    printf("ED: BEFORE COINS = %d, AFTER COINS = %d\n", before, state->coins);
    printf("        EXPECTATION IS AFTER COINS = %d\n", 8);
  }

  // clean up
  printf("--------------------\n");
  free(state);

  return 0;
}
