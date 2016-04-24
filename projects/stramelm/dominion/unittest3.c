#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("UNIT TEST #3: fullDeckCount()\n");

  // setup dummy game state
  int np = 2;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy};
  int seed = 333; // arbitrary seed value
  struct gameState* state = malloc(sizeof(struct gameState));
  initializeGame(np, k, seed, state);

  // -------------------------------------------------------------------------------------
  // REQT: POPULATE ALL COMPLETELY W/ UNIQUE QUANTITIES OF EACH CARD
  //
  //       fullDeckCount() SHOULD RETURN A TOTAL COUNT OF {CARD DEPENDENT} FOR EACH CARD TYPE
  // -------------------------------------------------------------------------------------
  int i, j, r;
  int pNum = 1;
  for (i = 0; i <= treasure_map; i++) {
    state->handCount[pNum] = 0;
    state->deckCount[pNum] = 0;
    state->discardCount[pNum] = 0;
	for (j = 0; j <= i; j++) {
      state->hand[pNum][j] = i;
      state->handCount[pNum] += 1;
      state->deck[pNum][j] = i;
      state->deckCount[pNum] += 1;
      state->discard[pNum][j] = i;
      state->discardCount[pNum] += 1;
	}
	r = fullDeckCount(pNum, i, state);
    if (r == 3 * (i + 1)) {
      printf("PASS");
    }
    else {
      printf("FAIL");
    }
    printf("ED: CARDID = %d, RETURN VALUE = %d\n", i, r);
    printf("        EXPECTATION IS r = %d\n", 3 * (i + 1));
  }
  initializeGame(np, k, seed, state);

  // -------------------------------------------------------------------------------------
  // REQT: POPULATE ALL CARD LOCATIONS (HAND, DECK, DISCARD) W/ UNIQUE QUANTITIES OF EACH CARD
  //       1 OF EACH CARD IN HAND
  //       2 OF EACH CARD IN DECK
  //       3 OF EACH CARD IN DISCARD
  //       THIS WILL SUM TO A TOTAL OF 6 CARDS FOR ANY PARTICULAR TYPE
  //
  //       fullDeckCount() SHOULD RETURN A TOTAL COUNT OF 6 FOR EACH CARD TYPE
  // -------------------------------------------------------------------------------------
  state->handCount[pNum] = 0;
  state->deckCount[pNum] = 0;
  state->discardCount[pNum] = 0;
  for (i = 0; i <= treasure_map; i++) {
    state->hand[pNum][i] = i;
    state->handCount[pNum] += 1;

    state->deck[pNum][i] = i;
    state->deck[pNum][i + treasure_map + 1] = i;
    state->deckCount[pNum] += 2;

    state->discard[pNum][i] = i;
    state->discard[pNum][i + treasure_map + 1] = i;
    state->discard[pNum][i + treasure_map + 1 + treasure_map + 1] = i;
    state->discardCount[pNum] += 3;
  }

  for (i = 0; i <= treasure_map; i++) {
    r = fullDeckCount(pNum, i, state);
    if (r == 6) {
      printf("PASS");
    }
    else {
      printf("FAIL");
    }
    printf("ED: CARDID = %d, RETURN VALUE = %d\n", i, r);
    printf("        EXPECTATION IS r = 6\n");
  }
  initializeGame(np, k, seed, state);

  // -------------------------------------------------------------------------------------
  // REQT: LOOK AT CARDS OUT OF BOUNDS (CARDS THAT DON'T EXIST)
  //
  //       fullDeckCount() SHOULD RETURN A TOTAL COUNT OF 0
  // -------------------------------------------------------------------------------------
  i = -1;
  r = fullDeckCount(pNum, i, state);
  if (r == 0) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: CARDID = %d, RETURN VALUE = %d\n", i, r);
  printf("        EXPECTATION IS r = 0\n");

  i = treasure_map + 1;
  r = fullDeckCount(pNum, i, state);
  if (r == 0) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: CARDID = %d, RETURN VALUE = %d\n", i, r);
  printf("        EXPECTATION IS r = 0\n");

  // clean up
  printf("--------------------\n");
  free(state);

  return 0;
}
