#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("CARD TEST #3: COUNCIL ROOM\n");

  // setup dummy game with 2 players
  int np = 2;
  int k[10] = {adventurer, council_room, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy};
  int seed = 333; // arbitrary seed value
  struct gameState* state = malloc(sizeof(struct gameState));
  initializeGame(np, k, seed, state);

  // make copy of gamestate
  struct gameState* copy = malloc(sizeof(struct gameState));
  memcpy(copy, state, sizeof(struct gameState));

  // use council_room card for player 2 (index 1), hand posiition 0
  int r = council_roomCardEffect(1, 3, state);

  // REQT: FUNCTION SUCCESSFULLY COMPLETES
  if (r == 0) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: CARD EXECUTION\n");

  // REQT: NUMBER OF BUYS SHOULD BE 2 INSTEAD OF 1
  int before = copy->numBuys;
  int after = state->numBuys;
  if (after - before == 1) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: NUMBER OF BUYS WENT FROM %d TO %d\n", before, after);
  printf("        EXPECTATION IS +1 BUYS\n");

  // REQT: CURRENT PLAYER SHOULD REC'V 4 CARDS, BUT COUNCIL_ROOM TO BE DISCARDED, NET 3
  int pNum = 1;
  before = copy->handCount[pNum];
  after = state->handCount[pNum];
  if (after - before == 3) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: CURRENT PLAYER CARDS IN HAND WENT FROM %d TO %d\n", before, after);
  printf("        EXPECTATION IS +3 CARDS\n");

  // REQT: 4 CARDS SHOULD COME FROM HIS OWN PILE, BUT COUNCIL_ROOM WILL BE ADDED BACK TO THE DISCARD, NET -3
  before = copy->discardCount[pNum] + copy->deckCount[pNum];
  after = state->discardCount[pNum] + state->deckCount[pNum];
  if (before - after == 3) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: CURRENT PLAYER CARDS IN DECK/DISCARD WENT FROM %d TO %d\n", before, after);
  printf("        EXPECTATION IS -3 CARDS\n");

  // REQT: OTHER PLAYERS MUST DRAW ONE CARD (player 1, index 0)
  pNum = 0;
  before = copy->handCount[pNum];
  after = state->handCount[pNum];
  if (after - before == 1) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: OTHER PLAYER CARDS IN HAND WENT FROM %d TO %d\n", before, after);
  printf("        EXPECTATION IS +1 CARDS\n");

  before = copy->discardCount[pNum] + copy->deckCount[pNum];
  after = state->discardCount[pNum] + state->deckCount[pNum];
  if (before - after == 1) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: OTHER PLAYER CARDS IN DECK/DISCARD WENT FROM %d TO %d\n", before, after);
  printf("        EXPECTATION IS -1 CARDS\n");

  // REQT: NO STATE CHANGE FOR VICTORY CARD PILE
  int changed = -1;
  int i;
  for (i = 1; i <= 3; i++) {
    before = copy->supplyCount[i];
    after = state->supplyCount[i];
    if (before != after) {
      changed = 0;
      break;
    }
  }
  if (changed == -1) {
    printf("PASSED: NO CHANGE TO VICTORY CARD PILE\n");
  }
  else {
    printf("FAILED: VICTORY CARD PILE CHANGED\n");
  }
  printf("        EXPECTATION IS NO CHANGE\n");

  // REQT: NO STATE CHANGE FOR KINGDOM CARD PILE
  changed = -1;
  for (i = 7; i <= 26; i++) {
    before = copy->supplyCount[i];
    after = state->supplyCount[i];
    if (before != after) {
      changed = 0;
      break;
    }
  }
  if (changed == -1) {
    printf("PASSED: NO CHANGE TO KINGDOM CARD PILE\n");
  }
  else {
    printf("FAILED: KINGDOM CARD PILE CHANGED\n");
  }
  printf("        EXPECTATION IS NO CHANGE\n");

  // clean up
  printf("--------------------\n");
  free(state);
  free(copy);
  return 0;
}
