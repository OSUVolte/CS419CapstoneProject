/*
File: randomtesadventurer.c
Author: Elliot Bates
Description: Random test for the adventurer card function in dominion.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

# define noiseLevel 3
//Noise level 0 = no print statements
//Noise level 1 = only print failed tests
//Noise level 2 = print results of all tests
//Noise level 3 = print everything
# define defaultTests 1000

// Function prototypes
int testStatesAdventurer (struct gameState *preGameState, struct gameState *postGameState, int numPlayers, int p);
int hasTreasures (struct gameState *g, int player);


int main (int argc, char** argv) {

	int p, i; 								//player holder, test number
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
	struct gameState preGameSate;			// original gameState
	struct gameState postGameState;			// test gameState
	int k[10] = {feast, gardens, embargo, adventurer, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	int otherCards[7] = {curse, estate, duchy, province, copper, silver, gold};

	//Set up gamestate with random number of players
	//Get arguments for number of tests if there is one
	if (argc == 2) {
		char* testsArg = argv[1];
		numTests = atoi(testsArg);
	} else {
		numTests = defaultTests;
	}
	if (numTests == NULL) {
		printf("Bad agruments.\n");
		exit(1);
	}

	for (i = 0; i < numTests; i++) {
# if (noiseLevel > 3)
		printf("-----Beginning test %d of %d-----\n", i, numTests);
# endif	
		
		// Set a random number of players
		numPlayers = (Random() * 3) + 1;
		
		//Initialise gamestate
		memset(&preGameSate, 23, sizeof(struct gameState));   // clear the game state
		initializeGame(numPlayers, k, seed, &preGameSate); // initialize a new game	
		
		//Randomise hands and decks in some way
		for (p = 0; p < numPlayers; p++) {
			// Add random number of kingdom cards to deck
			kingdomCardsToAdd = (Random() * 10);
			for (x = 0; x < kingdomCardsToAdd; x++) {
				kingdomCardToAdd = k[(int) (Random() * 9)];
				preGameSate.deck[p][preGameSate.deckCount[p]] = kingdomCardToAdd;
				preGameSate.deckCount[p]++;
			}
			// Add random number of other cards to deck
			otherCardsToAdd = (Random() * 10);
			for (x = 0; x < otherCardsToAdd; x++) {
				otherCardToAdd = otherCards[(int) (Random() * 9)];
				preGameSate.deck[p][preGameSate.deckCount[p]] = otherCardToAdd;
				preGameSate.deckCount[p]++;
			}			
			// If first player then add hand back to deck
			if (p == 0) {
				while (preGameSate.handCount[p] > 0) {
					preGameSate.deck[p][preGameSate.deckCount[p]] = preGameSate.hand[p][preGameSate.handCount[p] - 1];
					preGameSate.handCount[p]--;
					preGameSate.hand[p][preGameSate.handCount[p]] = -1;
					preGameSate.deckCount[p]++;
				}
			}	
			// Shuffle deck
			shuffle(p, &preGameSate);
			// Draw random sized hand . this may need to be changed for a generic version
			handSize = (Random() * 5);
			for (x = 0; x < handsize; x++) {
				drawCard(p, preGameSate);
			}
		}

		//Choose a random player to test card on
		p = (Random() * 3);
		
		//Make it this player's turn
		preGameSate.whoseTurn = p;

		//Make sure player has card in hand, place in random position if not
		for (x = 0; x < preGameSate.handCount[p]; x++) {
			if (preGameSate.hand[p][x] == adventurer) {
				handPos = x;
				break;
			}
			if (x == preGameSate.handCount[p] - 1) { // Will only get inside this statement if there is no adventurer in hand
				handPos = Random() * (handCount[p] - 1);
				preGameSate.hand[p][handPos] = adventurer;
			}
		}
		
		// Randomise number of cards left in deck to trigger any lines that involve shuffling
		deckSize = Random() * preGameSate.deckCount[p];
		while (preGameSate.deckCount[p] > deckSize) {
			preGameSate.discard[p][preGameSate.dicardCount[p]] = preGameSate.deck[p][preGameSate.deckCount[p] - 1];
			preGameSate.dicardCount[p]++;
			preGameSate.deckCount[p]--;
		}		

		//Save copy of gamestate
		memcpy(&postGameState, &preGameState, sizeof(struct gameState));	

		//Check player has at least 2 treasures in their deck/discard pile
		if (hasTreasures(&preGameSate, p) > 2) {
# if (noiseLevel > 0)
			printf("ABANDONING TEST %d: Player %d does not have at least 2 treasure cards in deck/discard pile.\n", i, p);
# endif
		}

		//Call adventurer method
		cardEffect(adventurer, 0, 0, 0, &postGameState, 0, 0);

		//Test that only certain things have changed and that they have changed correctly
		failedTests = testStatesAdventurer(&preGameSate, &postGameState, numPlayers, p);
# if (noiseLevel > 2)
		printf("-----Test %d complete. %d state comparison tests were failed.-----\n", failedTests);
# endif	
	}

	return 0;
}




//Test states adventurer function
int testStatesAdventurer (struct gameState *preGameState, struct gameState *postGameState, int numPlayers, int p) {
	int x, y;				// counters
	int failedTest = 0;
	
	
# if (noiseLevel > 2)
	printf("Comparing game states before and after card played.\n");
# endif	
	for (x = 0; x < numPlayers; x++) {
		if (x == p) {
			//Check player's hand size has increased by 2
			if (postGameState->handCount[x] == preGameSate->handCount[x]) {
# if (noiseLevel > 1)
				prtinf("PASSED: Player %d hand count has increased by 2.\n", x);
# endif	
			} else {
# if (noiseLevel > 0)
				printf("FAILED: Player %d hand count has increased by %d.\n", x, (postGameState->handCount[x] - preGameSate->handCount[x]));
				failedTest++;
# endif	
			}
			//Check both of these new cards are treasures
			if ((postGameState->hand[p][postGameState->handCount[p]-1] == copper || postGameState->hand[p][postGameState->handCount[p]-1] == silver ||
					postGameState->hand[p][postGameState->handCount[p]-1] == gold) && (postGameState->hand[p][postGameState->handCount[p]-2] == copper ||
					postGameState->hand[p][postGameState->handCount[p]-2] == silver || postGameState->hand[p][postGameState->handCount[p]-2] == gold)) {
#if (noiseLevel > 1)
				printf("PASSED: Both new cards added to player %d hand are treasures.\n", x);
# endif	
			} else {
# if (noiseLevel > 0)
				printf("FAILED: One or both of the cards added to player %d hand are not treasures.\n", x);
				failedTest++;
# endif	
			}
			//Check buys are still the same
			if (postGameState->numBuys == preGameSate->numBuys) {
# if (noiseLevel > 1)
				printf("PASSED: numBuys has not changed.\n");
# endif	
			} else {
# if (noiseLevel > 0)
				printf("FAILED: numBuys has changed from %d to %d.\n", preGameSate->numBuys, postGameState->numBuys);
				failedTest++;
# endif	
			}
			//Check actions are still the same
			if (postGameState->numActions == preGameSate->numActions) {
# if (noiseLevel > 1)
				printf("PASSED: numActions has not changed.\n");
# endif	
			} else {
# if (noiseLevel > 0)
				printf("FAILED: numActions has changed from %d to %d.\n", preGameSate->numActions, postGameState->numActions);
				failedTest++;
# endif	
			}			
		} else { // For all other players
		
			// Compare hands
			if (postGameState->handCount[x] == preGameSate->handCount[x]) {
# if (noiseLevel > 1)
				printf("PASSED: Player %d handCount has not changed.\n", x);
# endif	
				for (y = 0; y < postGameState->handCount[x]; y++) {
					if (postGameState->hand[x][y] == preGameSate->hand[x][y]) {
# if (noiseLevel > 1)
						prtinf("PASSED: Player %d card in hand position %d has not changed.\n", x, y);
# endif	
					} else {
# if (noiseLevel > 0)
						printf("FAILED: Player %d card in hand position %d has changed from %d to %d.\n", x, y, preGameSate->hand[x][y], postGameState->hand[x][y]);
						failedTest++;
# endif	
					}
				}
			} else {
# if (noiseLevel > 0)
				printf("FAILED: Player %d handCount has changed from %d to %d.\n", x, preGameSate->handCount[x], postGameState->handCount[x]);
				failedTest++;
# endif		
			}
			
			// Compare decks
			if (postGameState->deckCount[x] == preGameSate->deckCount[x]) {
# if (noiseLevel > 1)
				printf("PASSED: Player %d deckCount has not changed.\n", x);
# endif	
				for (y = 0; y < postGameState->deckCount[x]; y++) {
					if (postGameState->deck[x][y] == preGameSate->deck[x][y]) {
# if (noiseLevel > 1)
						prtinf("PASSED: Player %d card in deck position %d has not changed.\n", x, y);
# endif	
					} else {
# if (noiseLevel > 0)
						printf("FAILED: Player %d card in deck position %d has changed from %d to %d.\n", x, y, preGameSate->deck[x][y], postGameState->deck[x][y]);
						failedTest++;
# endif	
					}
				}
			} else {
# if (noiseLevel > 0)
				printf("FAILED: Player %d deckCount has changed from %d to %d.\n", x, preGameSate->deckCount[x], postGameState->deckCount[x]);
				failedTest++;
# endif		
			}
			
			// Compare discard piles
			if (postGameState->discardCount[x] == preGameSate->discardCount[x]) {
# if (noiseLevel > 1)
				printf("PASSED: Player %d discardCount has not changed.\n", x);
# endif	
				for (y = 0; y < postGameState->discardCount[x]; y++) {
					if (postGameState->discard[x][y] == preGameSate->discard[x][y]) {
# if (noiseLevel > 1)
						prtinf("PASSED: Player %d card in discard position %d has not changed.\n", x, y);
# endif	
					} else {
# if (noiseLevel > 0)
						printf("FAILED: Player %d card in discard position %d has changed from %d to %d.\n", x, y, preGameSate->discard[x][y], postGameState->discard[x][y]);
						failedTest++;
# endif	
					}
				}
			} else {
# if (noiseLevel > 0)
				printf("FAILED: Player %d discardCount has changed from %d to %d.\n", x, preGameSate->discardCount[x], postGameState->discardCount[x]);
				failedTest++;
# endif		
			}
		}
	}
	
	// Returns the number of tests failed
	return failedTest;
}

//Has more treasures function
int hasTreasures (struct gameState *g, int player) {
	int numTreasures = 0;
	int x, y;
	
	// Find treasures in deck
	for (x = 0; x < g->deckCount[p]; x++)
		if (g->deck[p][x] == copper || g->deck[p][x] == silver || g->deck[p][x] == gold)
			numTreasures++;
	
	// Find treasures in discard pile
	for (x = 0; x < g->discardCount[p]; x++)
		if (g->discardard[p][x] == copper || g->discard[p][x] == silver || g->discard[p][x] == gold)
			numTreasures++;
	
	return numTreasures;
}