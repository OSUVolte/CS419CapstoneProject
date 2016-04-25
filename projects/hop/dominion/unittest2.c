#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main(){

   struct gameState state, saveState;
   int numPlayers = 2, j = 0;
   int kingdom[10] = {adventurer, mine, gardens, feast, village, tribute, 
                     steward, baron, sea_hag, treasure_map};
   int seed = 88;

   initializeGame(numPlayers, kingdom, seed, &state);
   state.whoseTurn = 1;
   // Manually provide cards for player 2
   state.hand[1][0] = silver;
   state.hand[1][1] = silver;
   state.hand[1][2] = gold;
   state.hand[1][3] = adventurer;
   state.hand[1][4] = tribute;
   state.handCount[1] = 5;
   memcpy(&saveState, &state, sizeof(struct gameState));
   
   /* business requirements
      
      description: testing updateCoins(int player, struct gameState *state, 
      int bonus) which updates the state->coins to the value of the card held.
         
      1. Manual initialization of cards in hand. Function should convert 
         treasure cards to coins.
      2. No state changes should occur for the other player.  
      3. No state change should occur to victory and kingdom card piles.

      end requirements*/
   printf("<----------BEGIN unittest2-updateCoins()---------->\n\n");

// ----------------- TEST 1 ---------------------------------------------------
   printf(" TEST 1: Verify coin count is calculated correctly.\n");
   updateCoins(state.whoseTurn, &state, 0);
   printf("    coins: %i, expected: 7\n", state.coins);
   assert(state.coins == 7);

// ----------------- TEST 2 ---------------------------------------------------
   printf("\n");
   printf(" TEST 2: No state changes should occur for the other player.\n");
   printf("    deck count = %i, expected = %i\n", state.deckCount[!state.whoseTurn], saveState.deckCount[!state.whoseTurn]);
   printf("    discard pile count = %i, expected %i\n", state.discardCount[!state.whoseTurn], saveState.discardCount[!state.whoseTurn]);
   assert(saveState.deckCount[!state.whoseTurn] == state.deckCount[!state.whoseTurn]);

// ----------------- TEST 3 ---------------------------------------------------
   printf("\n");
   printf(" TEST 3: No state changes should occur to victory and kingdom card piles\n");
   printf("    estate count = %i, expected = %i\n", state.supplyCount[estate], saveState.supplyCount[estate]);
   printf("    duchy count = %i, expected = %i\n", state.supplyCount[duchy], saveState.supplyCount[duchy]);
   printf("    province count = %i, expected = %i\n", state.supplyCount[province], saveState.supplyCount[province]);
   
   for( j = adventurer; j <= treasure_map; ++j){
      printf("    kingdomCard '%i' count = %i, expected = %i\n", j, state.supplyCount[j], saveState.supplyCount[j]);
   }

   assert(saveState.supplyCount[estate] == state.supplyCount[estate]);
   assert(saveState.supplyCount[duchy] == state.supplyCount[duchy]);
   assert(saveState.supplyCount[province] == state.supplyCount[province]);
   for( j = adventurer; j <= treasure_map; ++j){
      assert(saveState.supplyCount[j] == state.supplyCount[j]);
   }
   printf("\n");
   printf("<----------END unittest2-updateCoins()---------->\n\n");

   return 0;
}
