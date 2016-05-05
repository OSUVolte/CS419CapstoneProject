/*William Maillard
CS 372
Assignment 4
5/5/2016*/

//randomtestcard: random testing of the smithycard

//This programs defaults to 10 tests, printing one failed example, and 
//printing the percentage of passed tests.  To change this use
//the command line arguments randomtestcard <noisy> <numTests> where
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
	int numTests = 10;  //Set this to default so low because the current bugs cause this test to take take forever,
						//if the bug is found several times. 10 gets the bug once in a while (~every 3 times)

	if(argc == 3){
		noisy = atoi(argv[1]);
		numTests = atoi(argv[2]);
	}
		
	printf("\n********************   Random Testing of Smithy Card  ******************\n\n");

	int k[10] = {adventurer, council_room, feast, gardens, mine,
		   remodel, smithy, village, baron, great_hall};




	srand(time(NULL));
	
	int numPassed = 0;
	
	for(int i = 0; i < numTests; i++){
		struct gameState *state = newGame();

		initializeGame(2, k, 1, state);  

		int numSupplies = treasure_map + 1;
		int player = 0;

		state->whoseTurn = player;

		state->deckCount[player] = 0;  //Empty the player's hand, discard, and deck
		state->handCount[player] = 0;
		state->discardCount[player] = 0;
	
										//Create fill hand, discard, handCount, discardCount, deck with randoms

		for(int i = 0; i < numSupplies; i++){ 
			if(state->supplyCount[i] > 0){
				int toAdd = rand() % state->supplyCount[i]; //Add a random valid number of each supply to deck
				for(int j = 0; j < toAdd; j++){
					if(i != smithy || state->supplyCount[smithy] > 1){ //Save one smithy so we can add to hand and play later
						addToDeck(player, i, state);
					}
				}
			}
		}
		for(int i = 0; i < numSupplies; i++){
			if(state->supplyCount[i] > 0){
				int toAdd = rand() % state->supplyCount[i]; //Add a random valid number of each supply to discard
				for(int j = 0; j < toAdd; j++){				//Save one smithy so we can add to hand and play later
					if(i != smithy || state->supplyCount[smithy] > 1){
						addToDiscard(player, i, state);
					}
				}
			}
		}
		for(int i = 0; i < numSupplies; i++){
			if(state->supplyCount[i] > 0){
				int toAdd = rand() % state->supplyCount[i]; //Add a random valid number of each supply to hand
				for(int j = 0; j < toAdd; j++){				//Save one smithy so we can add to hand and play later
					if(i != smithy || state->supplyCount[smithy] > 1){
						addToHand(player, i, state);
					}
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
		
		int spotForSmithy;
		if(state->handCount[player] > 0){
			int spotForSmithy = rand() % state->handCount[player];  //Add smithy to hand somewhere, replacing a card
			state->supplyCount[state->hand[player][spotForSmithy]]++;
		}
		else{
			state->supplyCount[smithy]--;
			spotForSmithy = 0;
		}
		state->hand[player][spotForSmithy] = smithy;
		

		playSmithy(state, spotForSmithy);
		
		//Calculate expected values
		expectedDeckCount -= 3;
		expectedHandCount += 2;  //Lose the smithy, gain 3 cards
		expectedDiscardCount++; //Lose smithy
		



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