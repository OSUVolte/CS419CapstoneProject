/*
File: randomtestcard.c
Author: Elliot Bates
Description: Random test for the villiage card function in dominion.c
*/

/*
int villageCard(int currentPlayer, struct gameState *state, int handPos) {
	  //+1 Card
      drawCard(currentPlayer, state);
			
      //+2 Actions
      state->numActions = state->numActions + 1;
			
      //discard played card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
}
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

# define noiseLevel 1
//Noise level 0 = no print statements
//Noise level 1 = only print failed tests
//Noise level 2 = print results of all tests
//Noise level 3 = print everything
# define defaultTests 1000

// Function prototypes
int testStatesVillage (struct gameState *preGameState, struct gameState *postGameState, int numPlayers, int p);

int main (int argc, char** argv) {

	int p, i, r; 								//player holder, test number
	int x, y, z;							// counters
	int numTests;
	int kingdomCardsToAdd, otherCardsToAdd;
	int kingdomCardToAdd, otherCardToAdd;
	int maxExtraCards = 10;					// Maximum of each type of card to add extra to deck
	int handSize;							// Number of cards player will have in hand;
	int handPos;							// The position the card will go in the players hand
	int deckSize;							// The number of cards that the player will have in their deck when the test starts
	int failedTests;						// Will hold the number of failed tests returned by the state comparison function
	int seed = 1000;
	int numPlayers;  						// number of players in game
	struct gameState preGameState;			// original gameState
	struct gameState postGameState;			// test gameState
	int k[10] = {feast, gardens, embargo, adventurer, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	int otherCards[7] = {curse, estate, duchy, province, copper, silver, gold};

	//Set up gamestate with random number of players
	//Get arguments for number of tests if there is one
	/*if (argc == 2) {
		char* testsArg = argv[1];
		numTests = atoi(testsArg);
	} else {
		numTests = defaultTests;
	}
	if (numTests == NULL) {
		printf("Bad agruments.\n");
		exit(1);
	}*/
	numTests = 2000;
	PlantSeeds(7);

	for (i = 1; i <= numTests; i++) {
# if (noiseLevel > 0)
		printf("-----Beginning test %d of %d-----\n", i, numTests);
# endif	
		
		// Set a random number of players
		numPlayers = (Random() * 2) + 2;
		//printf("Seeds planted and numPlayers randomised to %d.\n", numPlayers);
		
		//Initialise gamestate
		memset(&preGameState, 23, sizeof(struct gameState));   // clear the game states
		memset(&postGameState, 23, sizeof(struct gameState));   // clear the game states
		r = initializeGame(numPlayers, k, seed, &preGameState); // initialize a new game	
		//printf("Gamestate initialised.\n");
		
		//Randomise hands and decks in some way
		for (p = 0; p < numPlayers; p++) {
			// Add random number of kingdom cards to deck
			kingdomCardsToAdd = (Random() * 10);
			for (x = 0; x < kingdomCardsToAdd; x++) {
				kingdomCardToAdd = k[(int) (Random() * 9)];
				preGameState.deck[p][preGameState.deckCount[p]] = kingdomCardToAdd;
				preGameState.deckCount[p]++;
			}
			//printf("Added kingdom cards to %d.\n", p);
			// Add random number of other cards to deck
			otherCardsToAdd = (Random() * 10);
			for (x = 0; x < otherCardsToAdd; x++) {
				otherCardToAdd = otherCards[(int) (Random() * 9)];
				preGameState.deck[p][preGameState.deckCount[p]] = otherCardToAdd;
				preGameState.deckCount[p]++;
			}	
			//printf("Added other cards to %d.\n", p);
			// If first player then add hand back to deck
			if (p == 0) {
				while (preGameState.handCount[p] > 0) {
					preGameState.deck[p][preGameState.deckCount[p]] = preGameState.hand[p][preGameState.handCount[p] - 1];
					preGameState.handCount[p]--;
					preGameState.hand[p][preGameState.handCount[p]] = -1;
					preGameState.deckCount[p]++;
				}
				printf("Removed card from hand of p0.\n");
			}
			// Shuffle deck
			shuffle(p, &preGameState);
			//printf("Player %d hand shuffled.\n", p);
			// Draw random sized hand . this may need to be changed for a generic version
			handSize = (Random() * 5);
			for (x = 0; x < handSize; x++) {
				drawCard(p, &preGameState);
			}
			//printf("Hand drawn of size %d for player %d.\n", handSize, p);
		}

		//Choose a random player to test card on
		p = (Random() * (numPlayers - 1));
		//printf("Random player chosen %d.\n", p);
		
		//Make it this player's turn
		preGameState.whoseTurn = p;
		
		//Make sure player has card in hand, place in random position if not
		for (x = 0; x < preGameState.handCount[p]; x++) {
			if (preGameState.hand[p][x] == village) {
				handPos = x;
				break;
			}
			if (x == preGameState.handCount[p] - 1) { // Will only get inside this statement if there is no village in hand
				handPos = Random() * (preGameState.handCount[p] - 1);
				preGameState.hand[p][handPos] = village;
			}
		}
		//printf("Card now in hand.\n");
		
		// Randomise number of cards left in deck to trigger any lines that involve shuffling
		deckSize = Random() * preGameState.deckCount[p];
		while (preGameState.deckCount[p] > deckSize) {
			preGameState.discard[p][preGameState.discardCount[p]] = preGameState.deck[p][preGameState.deckCount[p] - 1];
			preGameState.discardCount[p]++;
			preGameState.deckCount[p]--;
		}	
		//printf("Deck randomised.\n");		

		//Save copy of gamestate
		memcpy(&postGameState, &preGameState, sizeof(struct gameState));
		//printf("Gamestate copied.\n");

		//Check player has at least 2 treasures in their deck/discard pile
		if (hasTreasures(&preGameState, p) < 2) {
# if (noiseLevel > 0)
			printf("ABANDONING TEST %d: Player %d does not have at least 2 treasure cards in deck/discard pile.\n", i, p);
# endif
		} else {
			//Call village method
			cardEffect(village, 0, 0, 0, &postGameState, 0, 0);

			//Test that only certain things have changed and that they have changed correctly
			failedTests = testStatesAdventurer(&preGameState, &postGameState, numPlayers, p);
# if (noiseLevel > 0)
			printf("-----Test %d complete. %d state comparison tests were failed.-----\n", i, failedTests);
# endif	
		}
	}

	return 0;
}




//Test states village function
int testStatesVillage (struct gameState *preGameState, struct gameState *postGameState, int numPlayers, int p) {
	int x, y;				// counters
	int failedTest = 0;
	
	
# if (noiseLevel > 2)
	printf("Comparing game states before and after card played.\n");
# endif	
	for (x = 0; x < numPlayers; x++) {
		if (x == p) {
			//Check player's hand size has not increased
			if (postGameState->handCount[x] == preGameState->handCount[x]) {
# if (noiseLevel > 1)
				printf("PASSED: Player %d hand count has not increased.\n", x);
# endif	
			} else {
# if (noiseLevel > 0)
				printf("FAILED: Player %d hand count has increased by %d.\n", x, (postGameState->handCount[x] - preGameState->handCount[x]));
				failedTest++;
# endif	
			}
			//If deck did not need to be shuffled, check top card from deck is now in hand
			if (preGameState->deckCount[x] > 0) {
				for (y = 0; y < postGameState->handCount[x]; y++) {
					if (postGameState->hand[x][y] == preGameState->deck[x][preGameState->deckCount[x]-1]) {
# if (noiseLevel > 1)
						printf("PASSED: Hand now contains top card from deck.\n");
# endf	
						break;
					}
					if (y == postGameState->handCount[x] - 1) { // will only get inside here if top card from deck in not in hand
# if (noiseLevel > 0)
						printf("FAILED: Top card from deck is not in hand.\n");
# endif					
					}
				}
			}
			//Check buys are still the same
			if (postGameState->numBuys == preGameState->numBuys) {
# if (noiseLevel > 1)
				printf("PASSED: numBuys has not changed.\n");
# endif	
			} else {
# if (noiseLevel > 0)
				printf("FAILED: numBuys has changed from %d to %d.\n", preGameState->numBuys, postGameState->numBuys);
				failedTest++;
# endif	
			}
			//Check actions has increased by 2
			if (postGameState->numActions == preGameState->numActions + 2) {
# if (noiseLevel > 1)
				printf("PASSED: numActions has increased by 2.\n");
# endif	
			} else {
# if (noiseLevel > 0)
				printf("FAILED: numActions has changed from %d to %d.\n", preGameState->numActions, postGameState->numActions);
				failedTest++;
# endif	
			}			
		} else { // For all other players
		
			// Compare hands
			if (postGameState->handCount[x] == preGameState->handCount[x]) {
# if (noiseLevel > 1)
				printf("PASSED: Player %d handCount has not changed.\n", x);
# endif	
				for (y = 0; y < postGameState->handCount[x]; y++) {
					if (postGameState->hand[x][y] == preGameState->hand[x][y]) {
# if (noiseLevel > 1)
						printf("PASSED: Player %d card in hand position %d has not changed.\n", x, y);
# endif	
					} else {
# if (noiseLevel > 0)
						printf("FAILED: Player %d card in hand position %d has changed from %d to %d.\n", x, y, preGameState->hand[x][y], postGameState->hand[x][y]);
						failedTest++;
# endif	
					}
				}
			} else {
# if (noiseLevel > 0)
				printf("FAILED: Player %d handCount has changed from %d to %d.\n", x, preGameState->handCount[x], postGameState->handCount[x]);
				failedTest++;
# endif		
			}
			
			// Compare decks
			if (postGameState->deckCount[x] == preGameState->deckCount[x]) {
# if (noiseLevel > 1)
				printf("PASSED: Player %d deckCount has not changed.\n", x);
# endif	
				for (y = 0; y < postGameState->deckCount[x]; y++) {
					if (postGameState->deck[x][y] == preGameState->deck[x][y]) {
# if (noiseLevel > 1)
						printf("PASSED: Player %d card in deck position %d has not changed.\n", x, y);
# endif	
					} else {
# if (noiseLevel > 0)
						printf("FAILED: Player %d card in deck position %d has changed from %d to %d.\n", x, y, preGameState->deck[x][y], postGameState->deck[x][y]);
						failedTest++;
# endif	
					}
				}
			} else {
# if (noiseLevel > 0)
				printf("FAILED: Player %d deckCount has changed from %d to %d.\n", x, preGameState->deckCount[x], postGameState->deckCount[x]);
				failedTest++;
# endif		
			}
			
			// Compare discard piles
			if (postGameState->discardCount[x] == preGameState->discardCount[x]) {
# if (noiseLevel > 1)
				printf("PASSED: Player %d discardCount has not changed.\n", x);
# endif	
				for (y = 0; y < postGameState->discardCount[x]; y++) {
					if (postGameState->discard[x][y] == preGameState->discard[x][y]) {
# if (noiseLevel > 1)
						printf("PASSED: Player %d card in discard position %d has not changed.\n", x, y);
# endif	
					} else {
# if (noiseLevel > 0)
						printf("FAILED: Player %d card in discard position %d has changed from %d to %d.\n", x, y, preGameState->discard[x][y], postGameState->discard[x][y]);
						failedTest++;
# endif	
					}
				}
			} else {
# if (noiseLevel > 0)
				printf("FAILED: Player %d discardCount has changed from %d to %d.\n", x, preGameState->discardCount[x], postGameState->discardCount[x]);
				failedTest++;
# endif		
			}
		}
	}
	
	// Returns the number of tests failed
	return failedTest;
}