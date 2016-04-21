/*
 * cardtest2.c
 * unit test for the adventurer card
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
   struct gameState G;
   struct gameState testG;
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
   int numPlayers = 2;
   int seed = 1000;
   int curPlayer = 0;
   int otherPlayer = 1;
   int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
   int newCards = 2;
   // initialize the game state and player cards
   initializeGame(numPlayers, k, seed, &G);
   printf("---------- Testing adventurer card ----------\n"); 
   // copy the game state to a test case
   memcpy(&testG, &G, sizeof(struct gameState));
   
   //play adventurer card on testG check handCount
   cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
   printf("check current players state\n");
   printf("hand count = %d, expected = %d\n", testG.handCount[curPlayer], G.handCount[curPlayer] + newCards -1); // -1 for the discarded adventurer card
   //check adventurer card on testG check deckCount
   printf("deck count should be at least two less than control\n");
   printf("deck count = %d, control = %d\n", testG.deckCount[curPlayer], G.deckCount[curPlayer]);
   //check that other players state is not changed
   printf("check other players state\n");
   printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
   //check smithy card on testG check deckCount
   printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
   
   return 0;
}