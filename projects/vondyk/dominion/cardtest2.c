#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int i, j; 					 			// counter
	int p1, p2;								// players
	int pos;								// position
	int played;								// number of cards played from deck
	int deckSize1;							// size of player 1's deck
	int deckSize2;							// size of player 2's deck
	int pileSize;							// pile of usable cards
	int numPlayers = 2;  					// players for valid gamestate
	int numTests = 1; 						// large testing spread
	int amount;								// total value of accumulated coins
	int totalDrawn;							// cards drawn before +2 coins, should be discarded by end
	int drawnTreasure;						// treasure card counter
	struct gameState og;					// original gameState
	struct gameState testState;				// test gameState
	int k[10] = {duchy, gardens, province, estate, tribute, mine, cutpurse, ambassador, great_hall, adventurer};
	char testCard[] = "Adventurer";	 		// card being tested



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
		played = testState.handCount[p1] - testState.discardCount[p1];				// How many cards were played
		pileSize = testState.deckCount[p1];											// Pile of non-trashed cards before play
		totalDrawn = 0;																// Amount drawn to get to 2 coin cards
		drawnTreasure = 0;															// Number of coin cards drawn
		amount = 0;																	// Value of accumulated coin cards
		int preCount;
		
		// Test that cards are drawn until two coin cards
		printf("\nTest 1: Play Adventurer and draw until two coins are drawn:\n");
		initializeGame(numPlayers, k, 1000, &og);
		memcpy(&testState, &og, sizeof(struct gameState));
		testState.hand[p1][0] = adventurer;
		testState.hand[p1][1] = duchy;
		testState.hand[p1][2] = estate;
		testState.hand[p1][3] = province;
		testState.hand[p1][4] = gardens;
		testState.deck[p1][0] = copper;
		testState.deck[p1][1] = silver;
		testState.deck[p1][2] = gold;
		testState.deck[p1][3] = copper;
		testState.deck[p1][4] = silver;
		preCount = testState.handCount[p1];
		cardEffect(adventurer, 0, 0, 0, &testState, 0, 0);							// Should have two coin cards when done
		if(testState.handCount[p1] - preCount == 2) 
			printf("Passed. Coin card amount expected: %d   	Coin count finish: %d\n", 2, testState.handCount[p1] - preCount);
		else 
			printf("FAILED. Coin card amount expected: %d   	Coin count finish: %d\n", 2, testState.handCount[p1] - preCount);
		printf("Coin cards Found: ");
		for(j = 0; j < testState.handCount[p1]; j++){
			if(testState.hand[p1][j] == copper){
				printf("copper, ");
				amount += 1;
			}
			if(testState.hand[p1][j] == silver){
				printf("silver, ");
				amount += 2;
			}
			if(testState.hand[p1][j] == gold){
				printf("gold, ");
				amount += 3;
			}
		}

		// Test that the value provided is right
		printf("\n\nTest 2: Check that coin amount unchanged until use:\n");
		if(og.coins == testState.coins)
			printf("Passed. Coin amount the same\n");
		else
			printf("FAILED. Coin amount different\n");


		printf("\nTest 3: Check test one again, but force gold to be drawn:\n");
		initializeGame(numPlayers, k, 1000, &og);
		memcpy(&testState, &og, sizeof(struct gameState));
		testState.hand[p1][0] = adventurer;
		testState.hand[p1][1] = duchy;
		testState.hand[p1][2] = estate;
		testState.hand[p1][3] = province;
		testState.hand[p1][4] = gardens;
		testState.deck[p1][0] = gold;
		testState.deck[p1][1] = silver;
		testState.deck[p1][2] = gold;
		testState.deck[p1][3] = copper;
		testState.deck[p1][4] = gold;
		preCount = testState.handCount[p1];
		cardEffect(adventurer, 0, 0, 0, &testState, 0, 0);							// Should have two coin cards when done
		
		if(testState.handCount[p1] - preCount == 2) 
			printf("Passed. Coin card amount expected: %d   	Hand Size: %d\n", 2, testState.handCount[p1] - preCount);
		else 
			printf("FAILED. Coin card amount expected: %d   	Hand Size: %d\n", 2, testState.handCount[p1] - preCount);
		printf("Coin cards Found: ");
		for(j = 0; j < testState.handCount[p1]; j++){
			if(testState.hand[p1][j] == copper){
				printf("copper, ");
				amount += 1;
			}
			if(testState.hand[p1][j] == silver){
				printf("silver, ");
				amount += 2;
			}
			if(testState.hand[p1][j] == gold){
				printf("gold, ");
				amount += 3;
			}
		}

		// Check that drawnTreasure is matching amount of distributed coin cards
		initializeGame(numPlayers, k, 1000, &og);
		memcpy(&testState, &og, sizeof(struct gameState));
		testState.hand[p1][0] = adventurer;
		testState.hand[p1][1] = duchy;
		testState.hand[p1][2] = estate;
		testState.hand[p1][3] = province;
		testState.hand[p1][4] = gardens;
		testState.deck[p1][0] = gardens;
		testState.deck[p1][1] = silver;
		testState.deck[p1][2] = gold;
		testState.deck[p1][3] = copper;
		testState.deck[p1][4] = duchy;
		cardEffect(adventurer, 0, 0, 0, &testState, 0, 0);	

		printf("\n\nTest 4: Make sure all cards that were not coins were discarded properly:\n");
		if(1 == testState.discardCount[p1]) 										// Will gain one non-coincard prior to 2 with this deck
			printf("Passed. Expected discard amount: %d   		Discarded amount: %d\n", 1, testState.discardCount[p1]);
		else
			printf("FAILED. Expected discard amount: %d			Discarded amount: %d\n", 1, testState.discardCount[p1]);
		

		
		// Test that player 2's hand didn't change
		printf("\nTest 5: Player 2's deck size unchanged when adventurer is played:\n");
		if(testState.deckCount[p2] == deckSize2)
			printf("Passed. Deck size start: %d   		Deck size finish: %d\n", deckSize2, testState.deckCount[p2]);
		else
			printf("FAILED. Deck size start: %d   		Deck size finish: %d\n", deckSize2, testState.deckCount[p2]);


		
		// Test that player 2's hand didn't change
		printf("\nTest 6: Player 2's hand size unchanged when adventurer is played:\n");
		if(testState.handCount[p2] == og.handCount[p2])
			printf("Passed. Hand size start: %d   		Hand size finish: %d\n", og.handCount[p2], testState.handCount[p2]);
		else
			printf("FAILED. Hand size start: %d   		Hand size finish: %d\n", og.handCount[p2], testState.handCount[p2]);


		
		// Test that the cards come from own player's pile, and is not stealing from elsewhere
		printf("\nTest 7: Player is drawing and keeping only two cards from own pile:\n");
		if(og.deckCount[p1] - 3 == testState.deckCount[p1]) 						// -1 because of this hand, has one noncoin card pulled
			printf("Passed. Expected Deck size: %d   	Deck size finish: %d\n", og.deckCount[p1] - 3, testState.deckCount[p1]);
		else
			printf("FAILED. Expected Deck size: %d   	Deck size finish: %d\n", og.deckCount[p1] - 3, testState.deckCount[p1]);

		
		
		// Test that the card is going to the played pile after use. Player 2's deck is unchanged
		printf("\nTest 8: Adventurer card added to played pile after use:\n");
		if(testState.playedCardCount == 1)
			printf("Passed. Expected increase in played pile: %d     	Actual increase to played pile: %d\n", 1, testState.playedCardCount);
		else
			printf("FAILED. Expected increase in played pile: %d   	 	Actual increase to played pile: %d\n", 1, testState.playedCardCount);

		
		
		
		// Test for any victory cards given out inappropriately
		printf("\nTest 9: : Test supply counts for misplaced points and curses: \n");
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
		printf("\nTest 10: Test supply counts for misplaced treasure: \n");
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