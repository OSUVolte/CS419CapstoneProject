/*William Maillard
CS 372
Assignment 4
5/5/2016*/

//randomtestadventurer: random testing of the adventurer card

//This programs defaults to 100,000 tests, printing one failed example, and 
//printing the percentage of passed tests.  To change this use
//the command line arguments randomtestadventurer <noisy> <numTests> where
//noisy is 1 to the results of all tests and 0 is to just print 1 failed test
//and numTests is the number of tests to run.

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

void addToDeck(int player, int card, struct gameState *state);
void addToHand(int player, int card, struct gameState *state);
void addToDiscard(int player, int card, struct gameState *state);


int main (int argc, char **argv) {
	int printOne = 0;
	int noisy = 0;
	int numTests = 100000;

	if(argc == 3){
		noisy = atoi(argv[1]);
		numTests = atoi(argv[2]);
	}
		
	printf("\n********************   Random Testing of Adventurer Card  ******************\n\n");

	int k[10] = {adventurer, council_room, feast, gardens, mine,
		   remodel, smithy, village, baron, great_hall};

//Create game with random # players?
//Create fill hand, discard, handCount, discardCount, deck with randoms; max 500 per
//Play adventurer 
	srand(time(NULL));
	
	int numPassed = 0;
	
	for(int i = 0; i < numTests; i++){
		struct gameState *state = newGame();

		initializeGame(2, k, 1, state);  

		int numSupplies = treasure_map + 1;
		int player = 0; //random player?

		state->whoseTurn = player;

		state->deckCount[player] = 0;  //Empty the player's hand, discard, and deck
		state->handCount[player] = 0;
		state->discardCount[player] = 0;
		int numTreasure = 0;			//Stores the number of treasure cards in the deck

		for(int i = 0; i < numSupplies; i++){
			if(state->supplyCount[i] > 0){
				int toAdd = rand() % state->supplyCount[i]; //Add a random valid number of each supply to deck
				for(int j = 0; j < toAdd; j++){
					addToDeck(player, i, state);
					if(i == gold || i == silver || i == copper){
						if(numTreasure < 2){
							numTreasure++;
						}
					}
				}
			}
		}
		for(int i = 0; i < numSupplies; i++){
			if(state->supplyCount[i] > 0){
				int toAdd = rand() % state->supplyCount[i]; //Add a random valid number of each supply to discard
				for(int j = 0; j < toAdd; j++){
					addToDiscard(player, i, state);
				}
			}
		}
		for(int i = 0; i < numSupplies; i++){
			if(state->supplyCount[i] > 0){
				int toAdd = rand() % state->supplyCount[i]; //Add a random valid number of each supply to hand
				for(int j = 0; j < toAdd; j++){
					addToHand(player, i, state);
				}
			}
		}

		shuffle(player, state);
		

		int expectedDeckCount = state->deckCount[player];
		int expectedDiscardCount = state->discardCount[player];
		int expectedHandCount = state->handCount[player];
		
		int testDeckCount = expectedDeckCount;
		int testDiscardCount = expectedDiscardCount;
		int testHandCount = expectedHandCount;
		
		int foundTreasure = 0;
		
		//Calculated expected values
		for(int i = 0; i < state->deckCount[player] && foundTreasure < numTreasure; i++){
			if(state->deck[player][i] == gold || state->deck[player][i] == silver || state->deck[player][i] == copper){
				foundTreasure++;
				expectedHandCount++; //Add every treasure card to hand
			}
			else{
				expectedDiscardCount++; //Add every other card to the discard pile
			}
			expectedDeckCount--;  		//Either way, remove card from deck
		}
		expectedHandCount--;
		expectedDiscardCount++; //discard adventurer
		
		//Play adventurer
		playAdventurer(state);



		if(expectedDeckCount == state->deckCount[player] && expectedDiscardCount == state->discardCount[player] && expectedDiscardCount == state->discardCount[player]){
			if(noisy == 1){
				printf("Test passed\n");
			}
			numPassed++;
		}
		else{
			if(noisy == 1 || printOne == 0){
				if(noisy == 0){
					printf("Here is an example of one failed test: \n");
					printOne = -1;
				}
				
				printf("Test failed:\n\nBefore Adventurer is Played:\n");
				printf("Starting Deck Count: %i\n", testDeckCount);
				printf("Starting Hand Count: %i\n", testHandCount);
				printf("Starting Discard Count: %i\n\n", testDiscardCount);
				printf("After Adventurer is Played:\n");
				printf("Expected Deck Count: %i, Actual Deck Count: %i\n", expectedDeckCount, state->deckCount[player]);
				printf("Expected Hand Count: %i, Actual Hand Count: %i\n", expectedHandCount, state->handCount[player]);
				printf("Expected Discard Count: %i, Actual Discard Count: %i\n", expectedDiscardCount, state->discardCount[player]);
			}
		}
		free(state);
	}
	printf("\nTotal number of tests: %i\n", numTests);
	printf("Number of tests passed: %i\n", numPassed);
	printf("Number of tests failed: %i\n", numTests - numPassed);
	printf("Percent passed: %f\n", 100 * (float)numPassed / (float)numTests);
		
		

  
  return 0;
}
	
void addToDeck(int player, int card, struct gameState *state){
	state->deck[player][state->deckCount[player]] = card;
	state->deckCount[player]++;
}
void addToHand(int player, int card, struct gameState *state){
	state->hand[player][state->handCount[player]] = card;
	state->handCount[player]++;
}
void addToDiscard(int player, int card, struct gameState *state){
	state->discard[player][state->discardCount[player]] = card;
	state->discardCount[player]++;
}