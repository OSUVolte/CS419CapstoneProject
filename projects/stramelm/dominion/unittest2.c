#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("UNIT TEST #2: scoreFor()\n");

  // setup dummy game state
  int np = 2;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy};
  int seed = 222; // arbitrary seed value
  struct gameState* state = malloc(sizeof(struct gameState));
  initializeGame(np, k, seed, state);

  // -------------------------------------------------------------------------------------
  // REQT: POPULATE ALL CARD LOCATIONS (HAND, DECK, DISCARD) W/ UNIQUE QUANTITIES OF EACH CARD
  //                                   NUMCARDS CURSE ESTATE DUCHY PROVINCE GARDENS GREATHALL TOTAL
  //       1 OF EACH CARD IN HAND      27          -1    1      3     6        1    --           10
  //       2 OF EACH CARD IN DECK      54          -2    2      6     12       2    --           20
  //       3 OF EACH CARD IN DISCARD   81          -3    3      9     18       3    --           30
  //       TOTAL                       162         -6    6      18    36       6    162/10=16    76
  //
  //       scoreFor() SHOULD RETURN A TOTAL SCORE OF 76
  // -------------------------------------------------------------------------------------
  int i;
  int pNum = 1;
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

  int r = scoreFor(pNum, state);
  if (r == 76) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: RETURN VALUE = %d\n", r);
  printf("        EXPECTATION IS r = 76\n");

  // -------------------------------------------------------------------------------------
  // REQT: POPULATE ALL CARD LOCATIONS (HAND ONLY)
  //                                   NUMCARDS CURSE ESTATE DUCHY PROVINCE GARDENS GREATHALL TOTAL
  //       1 OF EACH CARD IN HAND      27          -1    1      3     6        1    27/10=2      12
  //
  //       scoreFor() SHOULD RETURN A TOTAL SCORE OF 12
  // -------------------------------------------------------------------------------------
  state->handCount[pNum] = 0;
  state->deckCount[pNum] = 0;
  state->discardCount[pNum] = 0;
  for (i = 0; i <= treasure_map; i++) {
    state->hand[pNum][i] = i;
    state->handCount[pNum] += 1;
  }

  r = scoreFor(pNum, state);
  if (r == 12) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: RETURN VALUE = %d\n", r);
  printf("        EXPECTATION IS r = 12\n");

  // -------------------------------------------------------------------------------------
  // REQT: POPULATE ALL CARD LOCATIONS (DECK ONLY)
  //                                   NUMCARDS CURSE ESTATE DUCHY PROVINCE GARDENS GREATHALL TOTAL
  //       2 OF EACH CARD IN DECK      54          -2    2      6     12       2    54/10=5      25
  //
  //       scoreFor() SHOULD RETURN A TOTAL SCORE OF 25
  // -------------------------------------------------------------------------------------
  state->handCount[pNum] = 0;
  state->deckCount[pNum] = 0;
  state->discardCount[pNum] = 0;
  for (i = 0; i <= treasure_map; i++) {
    state->deck[pNum][i] = i;
    state->deck[pNum][i + treasure_map + 1] = i;
    state->deckCount[pNum] += 2;
  }

  r = scoreFor(pNum, state);
  if (r == 25) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: RETURN VALUE = %d\n", r);
  printf("        EXPECTATION IS r = 25\n");

  // -------------------------------------------------------------------------------------
  // REQT: POPULATE ALL CARD LOCATIONS (DISCARD ONLY)
  //                                   NUMCARDS CURSE ESTATE DUCHY PROVINCE GARDENS GREATHALL TOTAL
  //       3 OF EACH CARD IN DISCARD   81          -3    3      9     18       3    81/10=8      38
  //
  //       scoreFor() SHOULD RETURN A TOTAL SCORE OF 38
  // -------------------------------------------------------------------------------------
  state->handCount[pNum] = 0;
  state->deckCount[pNum] = 0;
  state->discardCount[pNum] = 0;
  for (i = 0; i <= treasure_map; i++) {
    state->discard[pNum][i] = i;
    state->discard[pNum][i + treasure_map + 1] = i;
    state->discard[pNum][i + treasure_map + 1 + treasure_map + 1] = i;
    state->discardCount[pNum] += 3;
  }

  r = scoreFor(pNum, state);
  if (r == 38) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: RETURN VALUE = %d\n", r);
  printf("        EXPECTATION IS r = 38\n");

  // -------------------------------------------------------------------------------------
  // REQT: CHECK INVIDUAL SCORES FOR EACH CARD TYPE BY FEEDING IN ONE CARD AT A TIME
  //       scoreFor() return val is card dependent
  // -------------------------------------------------------------------------------------
  state->handCount[pNum] = 1;
  state->deckCount[pNum] = 0;
  state->discardCount[pNum] = 0;
  for (i = 0; i <= treasure_map; i++) {
    state->hand[pNum][0] = i;
    r = scoreFor(pNum, state);
	if (i == 0) { // curse
      if (r == -1) {
        printf("PASS");
      }
	  else {
	    printf("FAIL");
	  }
	  printf("ED: RETURN VALUE = %d\n", r);
	  printf("        EXPECTATION IS r = -1\n");
    }
	else if (i == 1) { // estate
      if (r == 1) {
        printf("PASS");
      }
	  else {
	    printf("FAIL");
	  }
	  printf("ED: RETURN VALUE = %d\n", r);
	  printf("        EXPECTATION IS r = 1\n");
    }
	else if (i == 2) { // duchy
      if (r == 3) {
        printf("PASS");
      }
	  else {
	    printf("FAIL");
	  }
	  printf("ED: RETURN VALUE = %d\n", r);
	  printf("        EXPECTATION IS r = 3\n");
    }
	else if (i == 3) { // province
      if (r == 6) {
        printf("PASS");
      }
	  else {
	    printf("FAIL");
	  }
	  printf("ED: RETURN VALUE = %d\n", r);
	  printf("        EXPECTATION IS r = 6\n");
    }
	else if (i == 16) { // great hall
      if (r == 1) {
        printf("PASS");
      }
	  else {
	    printf("FAIL");
	  }
	  printf("ED: RETURN VALUE = %d\n", r);
	  printf("        EXPECTATION IS r = 1\n");
    }
	else { // all others
      if (r == 0) {
        printf("PASS");
      }
	  else {
	    printf("FAIL");
	  }
	  printf("ED: RETURN VALUE = %d\n", r);
	  printf("        EXPECTATION IS r = 0\n");
    }
  }

  // clean up
  printf("--------------------\n");
  free(state);

  return 0;
}
