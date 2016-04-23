#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("CARD TEST #2: ADVENTURER\n");

  // setup dummy game with 2 players
  int np = 2;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy};
  int seed = 767; // arbitrary seed value
  struct gameState* state = malloc(sizeof(struct gameState));
  initializeGame(np, k, seed, state);

  // make copy of gamestate
  struct gameState* copy = malloc(sizeof(struct gameState));
  memcpy(copy, state, sizeof(struct gameState));

  // use adventurer card for player 2 (index 1)
  int r = adventurerCardEffect(1, state);

  // REQT: FUNCTION SUCCESSFULLY COMPLETES
  if (r == 0) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: CARD EXECUTION\n");

  // REQT: CURRENT PLAYER SHOULD REC'V 2 TOTAL CARDS, BUT ADVENTURER TO BE DISCARDED, NET 1
  int pNum = 1;
  int before = copy->handCount[pNum];
  int after = state->handCount[pNum];
  if (after - before == 1) { // TOTAL CARDS
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: CURRENT PLAYER CARDS IN HAND WENT FROM %d TO %d\n", before, after);

  // REQT: BOTH CARDS REC'VD BY CURRENT PLAYER SHOULD BE TREASURE CARDS
  before = 0;
  after = 0;
  int i;
  int card;
  for (i = 0; i < copy->handCount[pNum]; i++) {
	card = copy->hand[pNum][i];
    if (card >= 4 && card <= 6) {
      before++;
	}
  }
  for (i = 0; i < state->handCount[pNum]; i++) {
	card = state->hand[pNum][i];
    if (card >= 4 && card <= 6) {
      after++;
	}
  }  if (after - before == 2) { // TREASURE CARDS
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: CURRENT PLAYER TREASURE CARDS IN HAND WENT FROM %d TO %d\n", before, after);

  // REQT: 2 CARDS SHOULD COME FROM HIS OWN PILE, BUT ADVENTURER WILL BE ADDED, NET -1
  before = copy->discardCount[pNum] + copy->deckCount[pNum];
  after = state->discardCount[pNum] + state->deckCount[pNum];
  if (before - after == 1) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: CURRENT PLAYER CARDS IN DISCARD+DECK WENT FROM %d TO %d\n", before, after);

  // REQT: NO STATE CHANGE FOR OTHER PLAYER (player 1, index 0)
  pNum = 0;
  before = copy->handCount[pNum];
  after = state->handCount[pNum];
  if (after == before) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: OTHER PLAYER CARDS IN HAND WENT FROM %d TO %d\n", before, after);

  before = copy->discardCount[pNum] + copy->deckCount[pNum];
  after = state->discardCount[pNum] + state->deckCount[pNum];
  if (after == before) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: OTHER PLAYER CARDS IN DISCARD+DECK WENT FROM %d TO %d\n", before, after);

  // REQT: NO STATE CHANGE FOR VICTORY CARD PILE
  int changed = -1;
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

  // clean up
  printf("--------------------\n");
  free(state);
  free(copy);
  return 0;
}
