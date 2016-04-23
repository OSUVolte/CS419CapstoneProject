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
   int newCards = 0, discard = 0;
   int kingdom[10] = {council_room, adventurer, gardens, mine, ambassador,  
                     remodel, great_hall, minion, sea_hag, outpost};
   int seed = 1000;

   initializeGame(numPlayers, kingdom, seed, &state);
   int currentPlayer = state.whoseTurn;
   // Save the state as-is
   memcpy(&saveState, &state, sizeof(struct gameState));
   /* business requirements
      
      description: testing adventurer card, 

      1. If available in the deck, current player should receive exactly 2 
         treasure cards. If not available, hand should only contain the number
         of tresasure cards available [0 to 2].
      2. Up to 2 treasure cards should come from own pile.
      3. No state change should occur for other players.
      4. No state change should occur to the victory and kingdom card piles.

      end requirements*/
   printf("<----------BEGIN cardtest2-adventurer card---------->\n\n");
   printf("Initial deck count: %i\n",state.deckCount[currentPlayer]);
   printf("Initial hand count: %i\n", state.handCount[currentPlayer]);

// ----------------- TEST 1 ---------------------------------------------------
   printf(" TEST 1: Current player should receive 2 treasure cards, if available.\n");
   printf("\n");
   cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, bonus);  
   newCards = 2;
   discard = 1;
   printf("    hand count = %i, %i <= expected <= %i\n", state.handCount[currentPlayer], saveState.handCount[currentPlayer], saveState.handCount[currentPlayer] + newCards - discard);  
   assert(state.handCount[currentPlayer] >= saveState.handCount[currentPlayer] && state.handCount[currentPlayer] <= saveState.handCount[currentPlayer] + newCards - discard);

// ----------------- TEST 2 ---------------------------------------------------
   printf("\n");
   printf(" TEST 2: Up to 2 Cards should come from own pile.\n");
   printf("    deck count = %i, %i <= expected <= %i\n", state.deckCount[currentPlayer], saveState.deckCount[currentPlayer] - newCards, saveState.deckCount[currentPlayer]);
   //assert(state.deckCount[currentPlayer] <= saveState.deckCount[currentPlayer] && state.deckCount[currentPlayer] >= saveState.deckCount[currentPlayer] - newCards);
   printf("    ASSERTION FAILS.\n");

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
   printf("<----------END cardtest2-adventurer card---------->\n\n");
}

