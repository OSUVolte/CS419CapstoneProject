#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("UNIT TEST #1: isGameOver()\n");

  // setup dummy game state
  int np = 2;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy};
  int seed = 111; // arbitrary seed value
  struct gameState* state = malloc(sizeof(struct gameState));
  initializeGame(np, k, seed, state);

  // -------------------------------------------------------------------------------------
  // REQT: SHOULD RETURN 0 (FALSE) IF ALL CARDS ARE NON-EMPTY
  // -------------------------------------------------------------------------------------
  int i;
  for (i = 0; i <= state->supplyCount[treasure_map]; i++) {
    state->supplyCount[i] = 1;
  }

  int r = isGameOver(state);
  if (r == 0) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: RETURN VALUE = %d\n", r);
  printf("        EXPECTATION IS r = 0\n");

  // -------------------------------------------------------------------------------------
  // REQT: SHOULD RETURN 1 (TRUE) IF PROVINCE CARDS ARE EMPTY
  // -------------------------------------------------------------------------------------
  state->supplyCount[province] = 0;

  r = isGameOver(state);
  if (r == 1) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: RETURN VALUE = %d\n", r);
  printf("        EXPECTATION IS r = 1\n");

  // -------------------------------------------------------------------------------------
  // REQT: SHOULD RETURN 0 (FALSE) IF ONLY ONE NON-PROVINCE CARD IS EMPTY
  // -------------------------------------------------------------------------------------
  state->supplyCount[province] = 1;
  state->supplyCount[curse] = 0; // first value in enum CARD

  r = isGameOver(state);
  if (r == 0) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: RETURN VALUE = %d\n", r);
  printf("        EXPECTATION IS r = 0\n");

  // -------------------------------------------------------------------------------------
  // REQT: SHOULD RETURN 0 (FALSE) IF ONLY TWO NON-PROVINCE CARDS ARE EMPTY
  // -------------------------------------------------------------------------------------
  state->supplyCount[province] = 1;
  state->supplyCount[curse] = 0; // first value in enum CARD
  state->supplyCount[treasure_map] = 0; // last value in enum CARD

  r = isGameOver(state);
  if (r == 0) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: RETURN VALUE = %d\n", r);
  printf("        EXPECTATION IS r = 0\n");

  // -------------------------------------------------------------------------------------
  // REQT: SHOULD RETURN 1 (TRUE) IF THREE NON-PROVINCE CARDS ARE EMPTY
  // -------------------------------------------------------------------------------------
  state->supplyCount[province] = 1;
  state->supplyCount[curse] = 0; // first value in enum CARD
  state->supplyCount[treasure_map] = 0; // last value in enum CARD
  state->supplyCount[smithy] = 0; // middle value in enum CARD

  r = isGameOver(state);
  if (r == 1) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: RETURN VALUE = %d\n", r);
  printf("        EXPECTATION IS r = 1\n");

  // -------------------------------------------------------------------------------------
  // REQT: SHOULD RETURN 1 (TRUE) IF THREE NON-PROVINCE CARDS ARE EMPTY
  // -------------------------------------------------------------------------------------
  state->supplyCount[province] = 1;
  state->supplyCount[curse] = 0; // first value in enum CARD
  state->supplyCount[sea_hag] = 0; // (last - 1) value in enum CARD
  state->supplyCount[smithy] = 0; // middle value in enum CARD

  r = isGameOver(state);
  if (r == 1) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: RETURN VALUE = %d\n", r);
  printf("        EXPECTATION IS r = 1\n");

  // -------------------------------------------------------------------------------------
  // REQT: SHOULD RETURN 1 (TRUE) IF THREE NON-PROVINCE CARDS ARE EMPTY
  // -------------------------------------------------------------------------------------
  state->supplyCount[province] = 1;
  state->supplyCount[curse] = 0; // first value in enum CARD
  state->supplyCount[salvager] = 0; // (last - 2) value in enum CARD
  state->supplyCount[smithy] = 0; // middle value in enum CARD

  r = isGameOver(state);
  if (r == 1) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: RETURN VALUE = %d\n", r);
  printf("        EXPECTATION IS r = 1\n");

  // clean up
  printf("--------------------\n");
  free(state);

  return 0;
}
