#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int i; 					 				// counter
	int p1, p2;								// players
	int pos;								// position
	int numActions;							// number of numActions for player
	int deckSize1;							// size of player 1's deck
	int deckSize2;							// size of player 2's deck
	int pileSize;							// pile of usable cards
	int numPlayers = 2;  					// players for valid gamestate
	int numTests = 1; 						// large testing spread
	struct gameState og;					// original gameState
	struct gameState testState;				// test gameState
	int k[10] = {feast, gardens, embargo, remodel, tribute, mine, cutpurse, ambassador, great_hall, village};
	char testCard[] = "Village";	 		// card being tested



	printf("*******  TESTING CARD: %s  *******\n\n", testCard);
	
	for(i = 0; i < numTests; i++){
		
		// Set hand basics for the game
		pos = -1;
		p1 = 0;
		p2 = 1;

		// Copy into a test state so I don't destroy the world
		initializeGame(numPlayers, k, 1000, &og);
		memcpy(&testState, &og, sizeof(struct gameState));


		// Beginning of Test
		deckSize1 = testState.handCount[p1];										// How many are originally in hand before play
		deckSize2 = testState.deckCount[p2];										// How many are originall in other's hand before play
		numActions = testState.numActions;
		pileSize = testState.deckCount[p1];											// Pile of non-trashed cards before play
		
		// Play the village card
		cardEffect(village, 0, 0, 0, &testState, 0, 0);
		
		
		// Test that player 1 gains one card. 
		printf("\nTest 1: Play Village and gain 1 card:\n");
		if(og.handCount[p1] == testState.handCount[p1]) 							// Draw card, discard Village = 0
			printf("Passed. Expected hand count: %d   		Hand count finish: %d\n", og.handCount[p1], testState.handCount[p1]);
		else
			printf("FAILED. Deck size start: %d   			Deck size finish: %d\n", og.handCount[p1], testState.handCount[p1]);

		
		
		// Test that player 1 gains 2 numActions
		printf("\nTest 2: Play Village and gain 2 numActions:\n");
		if(testState.numActions - og.numActions == 2) 								// Start: action = 1, play card (-1, action = 0), gain 2 (action = 2)
			printf("Passed. Expected Action count: %d   	Action finish: %d\n", 2, testState.numActions - og.numActions);
		else
			printf("FAILED. Expected Action count: %d   	Action finish: %d\n", 2, testState.numActions - og.numActions);		

		
		
		// Test that player 2's deck didn't change
		printf("\nTest 3: Player 2's deck size unchanged when village is played:\n");
		if(testState.deckCount[p2] == deckSize2)
			printf("Passed. Deck size start: %d   			Deck size finish: %d\n", deckSize2, testState.deckCount[p2]);
		else
			printf("FAILED. Deck size start: %d   			Deck size finish: %d\n", deckSize2, testState.deckCount[p2]);

		
		
		// Test that player 2's hand didn't change
		printf("\nTest 3b: Player 2's hand size unchanged when village is played:\n");
		if(testState.handCount[p2] == og.handCount[p2])
			printf("Passed. Hand size start: %d   			Hand size finish: %d\n", og.handCount[p2], testState.handCount[p2]);
		else
			printf("FAILED. Hand size start: %d   			Hand size finish: %d\n", og.handCount[p2], testState.handCount[p2]);

		
		
		// Test that the cards come from own player's pile, and is not stealing from elsewhere
		printf("\nTest 4: Player 1 is drawing from own pile:\n");
		if(og.deckCount[p1] -1 == testState.deckCount[p1]) 							//  5 in deck - 1 taken from it
			printf("Passed. Expected: %d   			Deck size finish: %d\n", og.deckCount[p1] - 1, testState.deckCount[p1]);
		else
			printf("FAILED. Expected: %d   			Deck size finish: %d\n", og.deckCount[p1] - 1, testState.deckCount[p1]);

		
		
		// Test that the card is going to the played pile after use. Already established other players deck is unchanged
		printf("\nTest 5: Village card added to played pile after use:\n");
		if(testState.playedCardCount == 1)
			printf("Passed. Expected increase in played pile: %d    Actual increase to played pile: %d\n", 1, testState.playedCardCount);
		else
			printf("FAILED. Expected increase in played pile: %d   	Actual increase to played pile: %d\n", 1, testState.playedCardCount);
		
		
		
		// Test for any victory cards given out inappropriately
		printf("\nTest 6: : Test supply counts for misplaced points and curses: \n");
		if(og.supplyCount[estate] != testState.supplyCount[estate])
			printf("FAILED. Estate Count Mismatch. Expected: %d  	Received: %d\n", og.supplyCount[estate], testState.supplyCount[estate]);
		if(og.supplyCount[duchy] != testState.supplyCount[duchy])
			printf("FAILED. Duchy Count Mismatch. Expected: %d  	Received: %d\n", og.supplyCount[duchy], testState.supplyCount[duchy]);
		if(og.supplyCount[province] != testState.supplyCount[province])
			printf("FAILED. Province Count Mismatch. Expected: %d  	Received: %d\n", og.supplyCount[province], testState.supplyCount[province]);
		if(og.supplyCount[curse] != testState.supplyCount[curse])
			printf("FAILED. Province Count Mismatch. Expected: %d  	Received: %d\n", og.supplyCount[curse], testState.supplyCount[curse]);
		else
			printf("Passed. Supply counts for curses and victory cards are correct\n");

		
		
		// Test for changes in money supply that shouldn't happen
		printf("\nTest 7: Test supply counts for misplaced treasure: \n");
		if(og.supplyCount[copper] != testState.supplyCount[copper])
			printf("FAILED. Copper Count Mismatch. Expected: %d  	Received: %d\n\n", og.supplyCount[copper], testState.supplyCount[copper]);
		if(og.supplyCount[silver] != testState.supplyCount[silver])
			printf("FAILED. Silver Count Mismatch. Expected: %d  	Received: %d\n\n", og.supplyCount[silver], testState.supplyCount[silver]);
		if(og.supplyCount[gold] != testState.supplyCount[gold])
			printf("FAILED. Gold Count Mismatch. Expected: %d  		Received: %d\n\n", og.supplyCount[gold], testState.supplyCount[gold]);
		else
			printf("Passed. Supply counts for treasure cards are correct\n\n");

	}

	return 0;
}