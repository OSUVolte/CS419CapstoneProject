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
	int played;								// number of cards played from deck
	int deckSize1;							// size of player 1's deck
	int deckSize2;							// size of player 2's deck
	int pileSize;							// pile of usable cards
	int numPlayers = 2;  					// players for valid gamestate
	int numTests = 1; 						// large testing spread
	struct gameState og;					// original gameState
	struct gameState testState;				// test gameState
	int k[10] = {council_room, gardens, embargo, remodel, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	char testCard[] = "Council Room";	 	// card being tested



	printf("*******  TESTING CARD: %s  *******\n\n", testCard);
	
	for(i = 0; i < numTests; i++){
		
		// Set hand basics for each game so the function can be called
		pos = -1;
		p1 = 0;
		p2 = 1;

		// Copy into a test state so I don't destroy the world
		initializeGame(numPlayers, k, 1000, &og);
		memcpy(&testState, &og, sizeof(struct gameState));


		// Beginning of Test
		deckSize1 = testState.handCount[p1];									// Cards in player 1's hand before play
		deckSize2 = testState.deckCount[p2];									// cards in player 2's hand before play
		played = testState.handCount[p1] - testState.discardCount[p1];			// Cards played
		pileSize = testState.deckCount[p1];										// Pile of non-trashed cards before play
		
		// Play Council Room card
		cardEffect(council_room, 0, 0, 0, &testState, 0, 0);
		
		// Test that player 1 draws 4 cards
		printf("\nTest 1a: Play Council Room and draw 4 cards:\n");
		if(testState.deckCount[p1] == og.deckCount[p1] - 4 && testState.handCount[p1] == og.handCount[p1] + 3)			// draw 4, discard Council Room = 3				
			printf("Passed. Deck size start: %d   		Deck size finish: %d\n", og.deckCount[p1], testState.deckCount[p1]);
		else
			printf("FAILED. Deck size start: %d   		Deck size finish: %d\n", og.deckCount[p1], testState.deckCount[p1]);
		
		
		
		// Test that player 1 increased numBuys by 1
		printf("\nTest 1b: Player 1 gains a buy:\n");
		if(testState.numBuys == og.numBuys + 1)
			printf("Passed. Number of Buys start: %d	Number of Buys finish: %d\n", og.numBuys, testState.numBuys);
		else
			printf("FAILED. Number of Buys start: %d	Number of Buys finish: %d\n", og.numBuys, testState.numBuys);
		
		

		// Test that player 2's deck didn't change
		printf("\nTest 2: Player 2's deck size decreased by 1 when Council Room is played:\n");
		if(testState.deckCount[p2] == og.deckCount[p2] - 1)						// Council Room requires player 2 to draw a card
			printf("Passed. Deck size start: %d   		Deck size finish: %d\n", og.deckCount[p2], testState.deckCount[p2]);
		else
			printf("FAILED. Deck size start: %d   		Deck size finish: %d\n", og.deckCount[p2], testState.deckCount[p2]);

		
		
		// Test that player 2's hand didn't change
		printf("\nTest 3: Player 2's hand size increased by 1 when Council Room is played:\n");
		if(testState.handCount[p2] == og.handCount[p2] + 1)						// Council Room requires player 2 to draw a card
			printf("Passed. Hand size start: %d   		Hand size finish: %d\n", og.handCount[p2], testState.handCount[p2]);
		else
			printf("FAILED. Hand size start: %d   		Hand size finish: %d\n", og.handCount[p2], testState.handCount[p2]);

		
		
		// Test that the cards come from own player's pile, and is not stealing from elsewhere
		printf("\nTest 4: Player is drawing from own pile:\n");
		if(og.deckCount[p1] - 4 == testState.deckCount[p1]) 						// Player draws 4 cards
			printf("Passed. Expected: %d   				Deck size finish: %d\n", og.deckCount[p1] - 4, testState.deckCount[p1]);
		else
			printf("FAILED. Expected: %d   				Deck size finish: %d\n", og.deckCount[p1] - 4, testState.deckCount[p1]);

		
		
		// Test that the card is going to the played pile after use. 
		printf("\nTest 5: Council Room card added to played pile after use:\n");
		if(testState.playedCardCount == 1)
			printf("Passed. Expected increase in played pile: %d    	Actual increase to played pile: %d\n", 1, testState.playedCardCount);
		else
			printf("FAILED. Expected increase in played pile: %d   		Actual increase to played pile: %d\n", 1, testState.playedCardCount);
		
		
		
		// Test for any victory cards given out inappropriately
		printf("\nTest 6: : Test supply counts for misplaced points and curses: \n");
		if(og.supplyCount[estate] != testState.supplyCount[estate])
			printf("FAILED. Estate Count Mismatch. Expected: %d  		Received: %d\n", og.supplyCount[estate], testState.supplyCount[estate]);
		if(og.supplyCount[duchy] != testState.supplyCount[duchy])
			printf("FAILED. Duchy Count Mismatch. Expected: %d  		Received: %d\n", og.supplyCount[duchy], testState.supplyCount[duchy]);
		if(og.supplyCount[province] != testState.supplyCount[province])
			printf("FAILED. Province Count Mismatch. Expected: %d  		Received: %d\n", og.supplyCount[province], testState.supplyCount[province]);
		if(og.supplyCount[curse] != testState.supplyCount[curse])
			printf("FAILED. Province Count Mismatch. Expected: %d  		Received: %d\n", og.supplyCount[curse], testState.supplyCount[curse]);
		else
			printf("Passed. Supply counts for curses and victory cards are correct\n");

		
		
		// Test for changes in money supply that shouldn't happen
		printf("\nTest 7: Test supply counts for misplaced treasure: \n");
		if(og.supplyCount[copper] != testState.supplyCount[copper])
			printf("FAILED. Copper Count Mismatch. Expected: %d  		Received: %d\n\n", og.supplyCount[copper], testState.supplyCount[copper]);
		if(og.supplyCount[silver] != testState.supplyCount[silver])
			printf("FAILED. Silver Count Mismatch. Expected: %d  		Received: %d\n\n", og.supplyCount[silver], testState.supplyCount[silver]);
		if(og.supplyCount[gold] != testState.supplyCount[gold])
			printf("FAILED. Gold Count Mismatch. Expected: %d  			Received: %d\n\n", og.supplyCount[gold], testState.supplyCount[gold]);
		else
			printf("Passed. Supply counts for treasure cards are correct\n\n");

	}

	return 0;
}