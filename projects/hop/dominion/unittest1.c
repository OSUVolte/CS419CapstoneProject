#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "rngs.h"

int main(){

   struct gameState state;
   int currentPlayer = 0;
   state.numPlayers = 2;
   state.whoseTurn = 0;
   state.hand[currentPlayer][0] = adventurer;
   state.hand[currentPlayer][1] = feast;
   state.hand[currentPlayer][2] = remodel;
   state.hand[currentPlayer][3] = tribute;
   state.hand[currentPlayer][4] = steward;
   state.handCount[currentPlayer] = 5;
   state.handCount[1] = 0;
   state.numActions = 1;
   state.numBuys = 1;
   
   /* business requirements
      
      description: testing handCard(int handNum, struct gameState *state), 
      which returns the index of a player's card held at handNum. The index 
      references the position of that card in the CARD enumeration.
         
      1. Manual initialization of cards in hand. Function should return card
         number. adventurer = 7, feast = 9, remodel = 12, tribute = 19, and 
         steward = 18.
      2. No state changes should occur at all.  

      end requirements*/
   printf("<----------BEGIN unittest1-handCard() ---------->\n\n");

// ----------------- TEST 1 ---------------------------------------------------
   printf(" TEST 1: Cards in hands revealed appropriately.\n");
   printf("    card: %i, expected: 7\n", handCard(0, &state));
   printf("    card: %i, expected: 9\n", handCard(1, &state));
   printf("    card: %i, expected: 12\n", handCard(2, &state));
   printf("    card: %i, expected: 19\n", handCard(3, &state));
   printf("    card: %i, expected: 18\n", handCard(4, &state));
   assert(handCard(0, &state) == 7);
   assert(handCard(1, &state) == 9);
   assert(handCard(2, &state) == 12);
   assert(handCard(3, &state) == 19);
   assert(handCard(4, &state) == 18);

// ----------------- TEST 2 ---------------------------------------------------
   printf("\n"); 
   printf(" TEST 2: No state changes should occur.\n");
   printf("    hand count = %i, expected = 5\n", state.handCount[0]);
   printf("    Player's turn = %i, expected = 0\n", state.whoseTurn);
   printf("    No. Actions = %i, expected = 1\n", state.numActions);
   printf("    No. Buys = %i, expected = 1\n", state.numBuys);
   assert(state.handCount[0] == 5);
   assert(state.whoseTurn == 0);
   assert(state.numActions == 1);
   assert(state.numBuys == 1);   
   printf("\n<----------END unittest1-handCard() ---------->\n\n");

   return 0;
}
