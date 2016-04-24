#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main(){

   struct gameState state, saveState;
   int numCardsToDraw = 5;
   int numPlayers = 2, j = 0;
   int kingdom[10] = {council_room, mine, gardens, feast, ambassador, tribute, 
                     steward, minion, sea_hag, treasure_map};
   int seed = 788;

   initializeGame(numPlayers, kingdom, seed, &state);
   int currentPlayer = state.whoseTurn;
   // Remove cards drawn from player
   for (j = 0 ; j < 5 ; ++j){
      discardCard(j, currentPlayer, &state,0);
   }
   // Save the state as-is
   memcpy(&saveState, &state, sizeof(struct gameState));
   
   /* business requirements
      
      description: testing drawCard(int player, struct gameState *state), which
      places a card in player's hand.

      1. Draw 5 cards. Current player should receive exactly 5 cards.
      2. Cards should have been drawn from player's pile.
      3. No state changes should occur for the other player.  

      end requirements*/
   printf("<----------BEGIN unittest3-drawCard()---------->\n\n");
   printf(" Initial deck count: %i\n", state.deckCount[currentPlayer]);

// ----------------- TEST 1 ---------------------------------------------------
   printf(" TEST 1: Verify cards are drawn and placed into player's hand.\n");
   // Draw 5 cards.
   for (j = 0 ; j < numCardsToDraw ; ++j){
      drawCard(currentPlayer, &state);
      printf("    card %i is of type: %i, expected: type != -1\n", j, state.hand[currentPlayer][j]);
      assert(state.hand[currentPlayer][j] != -1);
   }

   printf("    Number of cards in hand: %i, expected: %i\n", state.handCount[currentPlayer], numCardsToDraw);
   assert(state.handCount[currentPlayer] == numCardsToDraw);

// ----------------- TEST 2 ---------------------------------------------------
   printf("\n");
   printf(" TEST 2: Cards should have been drawn from player's deck.\n");
   printf("   deck count = %i, expected = %i\n", state.deckCount[currentPlayer], saveState.deckCount[currentPlayer] - numCardsToDraw);
   assert( state.deckCount[currentPlayer] == saveState.deckCount[currentPlayer] - numCardsToDraw ); 

// ----------------- TEST 3 ---------------------------------------------------
   printf("\n");
   printf(" TEST 3: No state changes should occur to other player.\n");
   printf("    deck count = %i, expected = %i\n", state.deckCount[!currentPlayer], saveState.deckCount[!currentPlayer]);
   assert( saveState.deckCount[!currentPlayer] == state.deckCount[!currentPlayer] );
   printf("\n<----------END unittest3-drawCard()---------->\n\n");

   return 0;
}
