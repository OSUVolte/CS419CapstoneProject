#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

/****************************************************************
** Function Name: randomSmithy()
** Input: player, number of total players, the upper boundary max
** 		for the deck count, and the game state
** Output: Displays test results
** Description: Play smithy card with random combinations
******************************************************************/
void randomSmithy(int p, int numPlayers, int maxDeck, struct gameState g){
	int p2 = 1;
	struct gameState testState;								// test game state

	// Display test conditions/randomness
	printf("\n\nTEST CONDITIONS: Random players, completely random deck, completely random hand, gamestate valid\n\n");
		
	memcpy(&testState, &g, sizeof(struct gameState));
	cardEffect(smithy, 0, 0, 0, &testState, 0, 0);
	

	
	// Test how many cards are gained by the player (goal is 3)
	printf("\nTest 1: Play Smithy and gain 3 cards:\n");
	if(testState.handCount[p] == g.handCount[p] + 2) 		// lose smithy (-1) and gain 3 more (+3) = 2
		printf("Passed. Expected hand count: %d   Actual count: %d\n", g.handCount[p] +2, testState.handCount[p]);
	else
		printf("FAILED. Expected size t: %d   Actual size : %d\n", g.handCount[p] +2, testState.handCount[p]);

	
	
	// Test that the smithy card does not affect Player 2's deck
		printf("\nTest 2: Player 2's deck size unchanged when smithy is drawn:\n");
	if(testState.deckCount[p2] == g.deckCount[p2])
		printf("Passed. Deck size Expected: %d   Deck size actual: %d\n", g.deckCount[p2], testState.deckCount[p2]);
	else
		printf("FAILED. Deck size expected: %d   Deck size actual: %d\n", g.deckCount[p2], testState.deckCount[p2]);
	
	

	// Test that the smithy card does not affect Player 2's hand
	printf("\nTest 2b: Other player's hand size unchanged when smithy is drawn:\n");
	if(testState.handCount[p2] == g.handCount[p2])
		printf("Passed. Deck size expected: %d   Deck size actual: %d\n", g.handCount[p2], testState.handCount[p2]);
	else
		printf("FAILED. Deck size expected: %d   Deck size actual: %d\n", g.handCount[p2], testState.handCount[p2]);
		
	
	
	// Test that the cards came from the Player's deck. 
	printf("\nTest 3: Player is drawing from own pile:\n");
	if(g.deckCount[p] - 3 == testState.deckCount[p])  		//  problematic when the deck count is 2 or less
		printf("Passed. Expected: %d   Deck size actual: %d\n", g.deckCount[p] - 3, testState.deckCount[p]);
	else
		printf("FAILED. Expected: %d   Deck size actual: %d\n", g.deckCount[p] - 3, testState.deckCount[p]);

	
	
	// Test that smithy card discards to played pile
	printf("\nTest 4: Smithy card added to played pile after use:\n");
	if(testState.playedCardCount == 1)
		printf("Passed. Expected increase in played pile: %d     To played pile: %d\n", 1, testState.playedCardCount);
	else
		printf("FAILED. Expected increase in played pile: %d   To played pile: %d\n", 1, testState.playedCardCount);

	
	
	// Test for any victory cards given out inappropriately
	printf("\nTest 5: : Test supply counts for points and curses that should not have been distributed: \n ");
	if(g.supplyCount[estate] != testState.supplyCount[estate])
		printf("FAILED. Estate Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[estate], testState.supplyCount[estate]);
	if(g.supplyCount[duchy] != testState.supplyCount[duchy])
		printf("FAILED. Duchy Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[duchy], testState.supplyCount[duchy]);
	if(g.supplyCount[province] != testState.supplyCount[province])
		printf("FAILED. Province Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[province], testState.supplyCount[province]);
	if(g.supplyCount[curse] != testState.supplyCount[curse])
		printf("FAILED. Province Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[curse], testState.supplyCount[curse]);
	else
		printf("Passed. Supply counts for curses and victory cards are the same\n");

	
	
	// Test for changes in money supply that shouldn't happen
	printf("\nTest 6: Test supply counts for treasure that should have been distributed: \n");
	if(g.supplyCount[copper] != testState.supplyCount[copper])
		printf("FAILED. copper Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[copper], testState.supplyCount[copper]);
	if(g.supplyCount[silver] != testState.supplyCount[silver])
		printf("FAILED. silver Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[silver], testState.supplyCount[silver]);
	if(g.supplyCount[gold] != testState.supplyCount[gold])
		printf("FAILED. gold Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[gold], testState.supplyCount[gold]);
	else
		printf("Passed. Supply counts for treasure cards are the same\n");
}

int main(){
	int i, j;												// counters
	int p = 0;												// player
	int numPlayers;											// number of players
	struct gameState g;										// game state
	int maxDeck;											// max deck amount, boundary upper
	int numTests = 20;									// loop random tests
	int k[10] = {duchy, gardens, province, estate, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	int deckSize = 27;										// will randomize, establishing max size

	srand(time(NULL));										// initialize rand
	
	printf("*******  TESTING CARD: Smithy  *******\n\n");	
	for(i = 0; i < numTests; i++){							// randomize variables before testing card
		numPlayers = (rand()%3)+2;							// random number of players within valid range
		initializeGame(numPlayers, k, 1000, &g);
		maxDeck = rand()%deckSize;							// random deck amount in valid range, allowing for empty
		g.deckCount[p] = maxDeck;							// set for player in question
		g.handCount[p] = rand()%6;							// random starting hand between typical start and empty to test shuffle;
		for(j = 0; j < maxDeck; j++){						// make sure deck is random
			g.deck[p][j] = (rand()%17)+1;
		}
		
		printf("\nInputs:\nDeck Size: %d\tHand Count: %d\t Players: %d\n", maxDeck, g.handCount[p], numPlayers);
		randomSmithy(p, numPlayers, maxDeck, g);			// play card with random variables
	}
	
	return 0;
}
