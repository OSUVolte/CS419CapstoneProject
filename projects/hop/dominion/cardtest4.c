#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main(){

   struct gameState state, saveState;
   int numPlayers = 2, i;
   int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0;
   int *bonus = NULL;
   int newCards = 0, discard = 0, addActions = 0;
   int kingdom[10] = {council_room, adventurer, gardens, mine, ambassador,  
                     remodel, great_hall, embargo, sea_hag, outpost};
   int seed = 1020;

   initializeGame(numPlayers, kingdom, seed, &state);
   int currentPlayer = state.whoseTurn;
   // Save the state as-is
   memcpy(&saveState, &state, sizeof(struct gameState));
   /* business requirements
      
      description: testing village card, 

      1. Hand should have 1 extra card minus this one that's played. There
         should also be two additional actions allowed.
      2. Number of buys or coins should not change.
      3. No state change should occur for other players.
      4. No state change should occur to the victory and kingdom card piles.

      end requirements*/
   printf("<----------BEGIN cardtest4-village card---------->\n\n");
   printf("Initial deck count: %i\n",state.deckCount[currentPlayer]);
   printf("Initial hand count: %i\n", state.handCount[currentPlayer]);

// ----------------- TEST 1 ---------------------------------------------------
   printf("\n");
   printf(" TEST 1: Hand should have +1 card minus this card. Current\n");
   printf("         player should also have +2 actions.\n");
   newCards = 1;
   discard = 1;
   addActions = 2;
   cardEffect(village, choice1, choice2, choice3, &state, handPos, bonus);  
   printf("    hand count = %i, expected = %i\n", state.handCount[currentPlayer], saveState.handCount[currentPlayer] + newCards - discard);  
   printf("    deck count = %i, expected = %i\n", state.deckCount[currentPlayer], saveState.deckCount[currentPlayer] - newCards);
   printf("    action count = %i, expected = %i\n", state.numActions, saveState.numActions + addActions);
   assert(state.handCount[currentPlayer] == saveState.handCount[currentPlayer] + newCards - discard);
   assert(state.deckCount[currentPlayer] == saveState.deckCount[currentPlayer] - newCards);
   assert(state.numActions == saveState.numActions + addActions);

// ----------------- TEST 2 ---------------------------------------------------
   printf("\n");
   printf(" TEST 2: Number of buys or coins should not change\n");
   printf("    buy count = %i, expected = %i\n", state.numBuys, saveState.numBuys);
   printf("    coin count = %i, expected = %i\n", state.coins, saveState.coins);
   assert(state.numBuys == saveState.numBuys);
   assert(state.coins == saveState.coins);

// ----------------- TEST 3 ---------------------------------------------------
   printf("\n");
   printf(" TEST 3: No state change should occur for other players.\n");
   printf("    deck count = %i, expected = %i\n", state.deckCount[!currentPlayer], saveState.deckCount[!currentPlayer]);
   printf("    discard pile count = %i, expected %i\n", state.discardCount[!currentPlayer], saveState.discardCount[!currentPlayer]);
   assert(saveState.deckCount[!currentPlayer] == state.deckCount[!currentPlayer]);

// ----------------- TEST 4 ---------------------------------------------------
   printf("\n");
   printf(" TEST 4: No state change should occur to victory and kingdom cards piles.\n");
   printf("    estate count = %i, expected = %i\n", state.supplyCount[estate], saveState.supplyCount[estate]);
   printf("    duchy count = %i, expected = %i\n", state.supplyCount[duchy], saveState.supplyCount[duchy]);
   printf("    province count = %i, expected = %i\n", state.supplyCount[province], saveState.supplyCount[province]);
   
   for( i = adventurer; i <= treasure_map; ++i){
      printf("    kingdomCard '%i' count = %i, expected = %i\n", i, state.supplyCount[i], saveState.supplyCount[i]);
   }

   assert(saveState.supplyCount[estate] == state.supplyCount[estate]);
   assert(saveState.supplyCount[duchy] == state.supplyCount[duchy]);
   assert(saveState.supplyCount[province] == state.supplyCount[province]);
   for( i = adventurer; i <= treasure_map; ++i){
      assert(saveState.supplyCount[i] == state.supplyCount[i]);
   }
   printf("\n");
   printf("<----------END cardtest4-village card---------->\n\n");
}

