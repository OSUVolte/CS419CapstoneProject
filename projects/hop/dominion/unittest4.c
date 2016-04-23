#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main(){

   struct gameState state, saveState;
   int numPlayers = 2, i;
   int kingdom[10] = {council_room, mine, gardens, feast, ambassador, tribute, 
                     steward, minion, sea_hag, treasure_map};
   int seed = 874;

   initializeGame(numPlayers, kingdom, seed, &state);
   int currentPlayer = state.whoseTurn;
   // Save the state as-is
   memcpy(&saveState, &state, sizeof(struct gameState));
   
   /* business requirements
      
      description: testing buyCard(int supplyPos, struct gameState *state), 
      which adds a card into the player's discard pile, which can eventually
      get into the player's deck.

      1. Bought cards should have been added to player's discard pile.
      2. Assuming no +buy cards were played, only 1 buys were allowed.
      3. Should not be able to buy cards without enough coins.
      4. Cannot buy more cards than available in supply.
      5. Supply card should have been reduced by amount bought.

      end requirements*/
   printf("<----------BEGIN unittest4-buyCard()---------->\n\n");

// ----------------- TEST 1 ---------------------------------------------------
   printf(" TEST 1: Bought cards should have been added to player's discard pile.\n");
   state.coins = 8;
   buyCard(province, &state);
   printf("    top card on discard pile is: %i, expected: %i\n", state.discard[currentPlayer][state.discardCount[currentPlayer]-1], province);
   assert(state.discard[currentPlayer][state.discardCount[currentPlayer]-1] == province);

// ----------------- TEST 2 ---------------------------------------------------
   printf("\n");
   printf(" TEST 2: Assuming no +buy cards were played, only 1 buys were allowed.\n");
   printf("    current player's buys left: %i, expected: 0\n", state.numBuys);
   assert(state.numBuys == 0);

// ----------------- TEST 3 ---------------------------------------------------
   printf("\n");
   printf(" TEST 3: Buying cards without enough coins.\n");
   // Restore state to original state
   memcpy(&state, &saveState, sizeof(struct gameState));
   state.coins = 0;
   state.numBuys = 1;
   int discardBeforeBuy = state.discardCount[currentPlayer];
   buyCard(estate, &state);
   printf("    discard count: %i, expected: %i\n", state.discardCount[currentPlayer], discardBeforeBuy);    
   assert(state.discardCount[currentPlayer] == discardBeforeBuy);

// ----------------- TEST 4 ---------------------------------------------------
   printf("\n");
   printf(" TEST 4: Buying cards that are out of supply.\n");
   // Restore state to original state
   memcpy(&state, &saveState, sizeof(struct gameState));
   state.coins = 10;
   state.numBuys = 1;
   // Find a card pile that is empty
   for (i = 0; i <= treasure_map; ++i) if (state.supplyCount[i] == 0) break;
   discardBeforeBuy = state.discardCount[currentPlayer];
   buyCard(i, &state);
   printf("    discard count: %i, expected: %i\n", state.discardCount[currentPlayer], discardBeforeBuy);
   assert(state.discardCount[currentPlayer] == discardBeforeBuy);

// ----------------- TEST 5 ---------------------------------------------------
   printf("\n");
   printf(" TEST 5: Purchased supply card should have their supply pile reduced by 1.\n");
   // Restore state to original state
   memcpy(&state, &saveState, sizeof(struct gameState));
   state.coins = 10;
   state.numBuys = 1;
   // Find a card pile that has available cards to buy
   for (i = 0; i <= treasure_map; ++i) if (state.supplyCount[i] > 0) break;
   int supplyBeforeBuy = state.supplyCount[i];
   buyCard(i, &state);
   printf("    supply count: %i, expected: %i\n", state.supplyCount[i], supplyBeforeBuy - 1); assert(state.supplyCount[i] == supplyBeforeBuy - 1);
   printf("\n<----------END unittest4-buyCard()---------->\n\n");   
}

