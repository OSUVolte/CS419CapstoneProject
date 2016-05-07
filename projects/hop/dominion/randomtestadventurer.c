#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <time.h>

void oracle1(struct gameState *, struct gameState *, int);
void oracle2(struct gameState *, struct gameState *, int);
void oracle3(struct gameState *, struct gameState *, int);
void oracle4(struct gameState *, struct gameState *, int);

int main(){

	srand(time(NULL));
   struct gameState state, savedState;
   int numPlayers = 2, i, j;
   int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0;
   int *bonus = NULL;

   int kingdom[10] = {council_room, adventurer, gardens, mine, ambassador,  
                     remodel, great_hall, minion, sea_hag, outpost};
   int seed = 1000;

   initializeGame(numPlayers, kingdom, seed, &state);
   int currentPlayer = state.whoseTurn;
   // Save the state as-is
   memcpy(&savedState, &state, sizeof(struct gameState));
	/*
	Random Test plan.

		1. Draw cards at random to initiate game at different states of the
			deck. Also, try to get a state where the deck becomes empty.
		2. Randomize the number of treasure cards in a player's deck from 0 to 
			maximum number of treasure cards.
		3. Randomize the number of kingdom cards in the supply pile from 0 to 
			10.
		4. Randomize number of players from 0 to maximum number of players.

	End of Random Test Plan
   
	Test oracles - Used on EACH Random Test
      
      1. If available in the deck, current player should receive exactly 2 
         treasure cards. If not available, hand should only contain the number
         of tresasure cards available [0 to 2].
      2. Up to 2 treasure cards should come from own pile.
      3. No state change should occur for other players.
      4. No state change should occur to the victory and kingdom card piles.

	end oracles
	*/

   printf("########----BEGIN random test on adventurer card----########\n\n");
	printf("########--------Test 1--------########\n");
	printf("    Randomly draw cards from deck before starting game.\n");
	printf("    Starting at different deck count.\n");

	for ( j = 0 ; j < 100 ; ++j){

		// draw random number of cards from 0 to 5 cards from deck
		int numDraw = rand() % 6;
		for ( i = 0 ; i < numDraw ; ++i ){
			drawCard(currentPlayer, &state);	
		}

		printf("########-------Random Sample %i--------########\n\n", j);
		printf("        Sample: Drew %i cards from deck\n", numDraw );
		printf("        deck count: %i\n", state.deckCount[currentPlayer]);
		// play card
		cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, bonus);
		// assert oracles
		oracle1(&state, &savedState, currentPlayer);
		oracle2(&state, &savedState, currentPlayer);
		oracle3(&state, &savedState, currentPlayer);
		oracle4(&state, &savedState, currentPlayer);
		// restore initial state for next random test
		memcpy(&state, &savedState, sizeof(struct gameState));

	}

	printf("########--------Test 2--------########\n");
	printf("    Randomize number of treasure cards in player's deck\n"); 

	for ( j = 0 ; j < 100 ; ++j){

		// randomly determine number of treasure cards,x, to place in 
		// player's deck. Add x number of copper cards in deck and replace
		// all other cards as estate cards. Shuffle deck and start game.
		int numTreasures = rand() % 11;

		printf("########--------Random Sample %i--------########\n\n",j);
		printf("        Sample: Leave %i treasure cards in deck\n", numTreasures);
		for( i = 0 ; i < numTreasures ; ++i){
			state.deck[currentPlayer][i] = copper;	
		}
		for( i = numTreasures ; i < state.deckCount[currentPlayer] ; ++i){
			state.deck[currentPlayer][i] = estate;
		}
		// play card
		cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, bonus);
		// assert oracles
		oracle1(&state, &savedState, currentPlayer);
		oracle2(&state, &savedState, currentPlayer);
		oracle3(&state, &savedState, currentPlayer);
		oracle4(&state, &savedState, currentPlayer);
		// restore initial state for next random test
		memcpy(&state, &savedState, sizeof(struct gameState));

	}

	printf("########--------Test 3--------########\n");
	printf("    Randomize each number of kingdom cards in supply pile from 0 to "
			 "10.\n");
	printf("    This simulates states that are later on in the game.\n");

	for ( j = 0 ; j < 100 ; ++j){

		// Set random number of kingdom cards to begin game state
		// use array 'randomKingdomCount' to store the count number and 
		// record sample
		int randomKingdomCount[20] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
												-1,-1,-1,-1,-1,-1};
		for (i = adventurer; i <= treasure_map; i++){      	//loop all cards
				if (state.supplyCount[i] != -1){
					int numKingdom = rand() % 11;
					//check if card is a 'Victory' Kingdom card
					if (state.supplyCount[i] == great_hall || 
							state.supplyCount[i] == gardens){
						if (numPlayers == 2){ 
							// limit random number up to eight cards
							numKingdom = rand() % 9;
							randomKingdomCount[i - adventurer] = numKingdom;
							state.supplyCount[i] = numKingdom;//8; 
						} else { 
							// limit random number up to 12 cards
							numKingdom = rand() % 13;
							randomKingdomCount[i - adventurer] = numKingdom;
							state.supplyCount[i] = numKingdom;//12; 
						}
					} else {
						randomKingdomCount[i - adventurer] = numKingdom;
						state.supplyCount[i] = numKingdom;
					}
				}
			}

		struct gameState randKingState;
		memcpy(&randKingState, &state, sizeof(struct gameState));
		printf("########-------Random Sample %i--------########\n\n", j);
		printf("        kingdom card ");

		for (i = adventurer ; i <= treasure_map ; ++i){
			printf(",");
			printf("[%i]=%i",i - adventurer,randomKingdomCount[i - adventurer]);
		}

		printf("\n");
		// play card
		cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, bonus);
		// assert oracles
		oracle1(&state, &randKingState, currentPlayer);
		oracle2(&state, &randKingState, currentPlayer);
		oracle3(&state, &randKingState, currentPlayer);
		oracle4(&state, &randKingState, currentPlayer);
		// restore initial state for next random test
		memcpy(&state, &savedState, sizeof(struct gameState));

	}

	printf("########--------Test 4--------########\n");
	printf("    Randomize number of players from 2 to maximum number of "
			 "players."); 

	for ( j = 0 ; j < 20 ; ++j){

		// get random number of players from 2 to 4 players
		int numRandPlayers = 2 + (rand() % (MAX_PLAYERS - 1));

		printf("########-------Random Sample %i--------########\n\n", j);
		printf("        Sample: %i number of players\n", numRandPlayers );
		initializeGame(numRandPlayers, kingdom, seed, &state);
		memcpy(&savedState, &state, sizeof(struct gameState));
		// play card
		cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, bonus);
		// assert oracles
		oracle1(&state, &savedState, currentPlayer);
		oracle2(&state, &savedState, currentPlayer);
		oracle3(&state, &savedState, currentPlayer);
		oracle4(&state, &savedState, currentPlayer);
		// restore initial state for next random test
		memcpy(&state, &savedState, sizeof(struct gameState));

	}

   printf("\n");
   printf("<----------END random test on adventurer card---------->\n\n");
   return 0;

}

void oracle1(struct gameState *state, struct gameState *savedState, 
				int currentPlayer){

   int newCards = 2, discard = 1;
   printf("        Oracle 1: Current player should receive 2 treasure cards, "
										"if available.\n");
   printf("\n");
   printf("        hand count = %i, %i <= expected <= %i\n", 
			state->handCount[currentPlayer], savedState->handCount[currentPlayer], 
			savedState->handCount[currentPlayer] + newCards - discard);  
   if (state->handCount[currentPlayer] >= savedState->handCount[currentPlayer] 
			&& state->handCount[currentPlayer] <= 
			savedState->handCount[currentPlayer] + newCards - discard){
		printf("        passes (+)\n");
	} else {
		printf("        fails (-)\n");
	}

}

void oracle2(struct gameState *state, struct gameState *savedState, 
		int currentPlayer){
	int newCards = 2;
   printf("\n");
   printf("        Oracle 2: Up to 2 Cards should come from own pile.\n");
   printf("        deck count = %i, %i <= expected <= %i\n", 
			state->deckCount[currentPlayer], savedState->deckCount[currentPlayer] 
			- newCards, savedState->deckCount[currentPlayer]);
   if (state->deckCount[currentPlayer] <= savedState->deckCount[currentPlayer] 
			&& state->deckCount[currentPlayer] >= 
			savedState->deckCount[currentPlayer] - newCards){
		printf("        +test passes(+)\n");
	} else {
		printf("        test fails(-)\n");
	}
}

void oracle3(struct gameState *state, struct gameState *savedState, 
		int currentPlayer){
   printf("\n");
   printf("        Oracle 3: No state change should occur for other players.");
	printf("\n"); 
   printf("        deck count = %i, expected = %i\n", state->deckCount[!currentPlayer], savedState->deckCount[!currentPlayer]);
   printf("        discard pile count = %i, expected %i\n", 
			state->discardCount[!currentPlayer], 
			savedState->discardCount[!currentPlayer]);
	if (savedState->deckCount[!currentPlayer]==state->deckCount[!currentPlayer]){
		printf("        test passes (+)\n");
	} else {
		printf("        test fails (-)\n");
	}
}

void oracle4(struct gameState *state, struct gameState *savedState, 
		int currentPlayer){
	int i;
   printf("\n");
   printf("        Oracle 4: No state change should occur to victory and kingdom cards piles.\n");
   printf("        estate count = %i, expected = %i\n",state->supplyCount[estate], savedState->supplyCount[estate]);

	printf("        estate count ");
	if (savedState->supplyCount[estate] == state->supplyCount[estate]){
		printf("passes (+)\n");
	} else {
		printf("fails (-)\n");
	}

   printf("        duchy count = %i, expected = %i\n", state->supplyCount[duchy], savedState->supplyCount[duchy]);
	printf("        duchy count ");
	if (savedState->supplyCount[duchy] == state->supplyCount[duchy]){
		printf("passes (+)\n");
	} else {
		printf("fails (-)\n");
	}

   printf("        province count = %i, expected = %i\n",state->supplyCount[province], savedState->supplyCount[province]);
	printf("        province count ");
	if (savedState->supplyCount[province] == state->supplyCount[province]){
		printf("passes (+)\n");
	} else {
		printf("fails (-)\n");
	}

   for( i = adventurer; i <= treasure_map; ++i){
      printf("        kingdomCard '%i' count = %i, expected = %i\n", i, state->supplyCount[i], savedState->supplyCount[i]);
   }
   for( i = adventurer; i <= treasure_map; ++i){
		printf("        supply card %i - count is ",i);
      if (savedState->supplyCount[i] == state->supplyCount[i]){
			printf("correct: passes (+)\n");
		} else {
			printf("incorrect: fails (-)\n");
		}
   }
}

