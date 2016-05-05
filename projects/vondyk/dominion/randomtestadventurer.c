#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

/****************************************************************
** Function Name: treasureRandom()
** Input: player, number of total players, the upper boundary max
** 		for the deck count, postion and the game state
** Output: Displays test results
** Description: Play smithy card with two random treasure cards 
** 		placed in the deck at a random position
******************************************************************/
void treasureRandom(int p, int numPlayers, int maxDeck, int position, struct gameState g){
	int j; 															// counter
	int p2 = 1;														// players
	int preCount;													// cards in hand
	int preamount;													// amount of coins before card effect
	int amount = 0;													// amount of coins after card effect
	struct gameState testState;										// gamestate under test
	
	// Display test conditions/randomness
	printf("TEST CONDITIONS ONE: Random players, all deck random but two treasure, all hand random but adventurer\n\n");

	// Randomly generate two treasure cards into the deck
	for(j = 0; j < 2; j++){									
		int oneTreasure = rand()%maxDeck;							// determine deck location
		int treasureType = rand()%2;								// determine which treasure cards
		if(treasureType == 0)								
			g.deck[p][oneTreasure] = copper;
		else if(treasureType == 1)
			g.deck[p][oneTreasure] = silver;
		else if(treasureType == 2)
			g.deck[p][oneTreasure] = gold;
	}
		
	// Test that the player draws until 2 treasures are found
	printf("\nTest 1: Play Adventurer and draw until two coins are drawn:\n");
	memcpy(&testState, &g, sizeof(struct gameState));
	preCount = testState.handCount[p];
	preamount = g.coins;
	amount = 0;
	printf("Coin cards in hand originally, if any: ");
	for(j = 0; j < testState.handCount[p]; j++){
		if(testState.hand[p][j] == copper){
			printf("copper, ");
			preamount += 1;
			preCount++;
		}
		if(testState.hand[p][j] == silver){
			printf("silver, ");
			preamount += 2;
			preCount++;
		}
		if(testState.hand[p][j] == gold){
			printf("gold, ");
			preamount += 3;
			preCount++;
		}
	}
	printf("\n");
	cardEffect(adventurer, 0, 0, 0, &testState, 0, 0);				// should have two coin cards when done
	
	printf("Coin cards Found: ");
	for(j = 0; j < testState.handCount[p]; j++){
		if(testState.hand[p][j] == copper){
			printf("copper, ");
			amount += 1;
		}
		if(testState.hand[p][j] == silver){
			printf("silver, ");
			amount += 2;
		}
		if(testState.hand[p][j] == gold){
			printf("gold, ");
			amount += 3;
		}
	}

	printf("\n");
	// Test that two coin cards were gained
	if(amount == testState.coins)
		printf("Passed. Coin card amount expected: %d   amount finish: %d\n", amount, testState.coins);
	else 
		printf("FAILED. Coin card amount expected: %d   amount finish: %d\n", amount, testState.coins);


	// Test that the value provided is right
	printf("\nTest 1b: Gained cards, coin ammount unchanged till use:\n");
	if(g.coins == testState.coins)
		printf("Passed. Coin amount the same\n");
	else
		printf("FAILED. Coin amount different\n");

	// Test that the player gained the correct amount of total cards
	printf("\nTest 2: Gained appropriate card amount:\n");
	if(testState.handCount[p] == g.handCount[p] + 2)				// - adventurer, + 2, = gain 1 
		printf("Passed. Hand count expected: %d   Hand count finish: %d\n", g.handCount[p] + 2, testState.handCount[p]);
	else 
		printf("FAILED. Hand count expected: %d   Hand count finish: %d\n", g.handCount[p] +2, testState.handCount[p]);

	

	// Test that Player 2's hand was not affected
	printf("\nTest 3: Other player's hand size unchanged when adventurer is drawn:\n");
	if(testState.handCount[p2] == g.handCount[p2])
		printf("Passed. Hand size start: %d   Hand size finish: %d\n", g.handCount[p2], testState.handCount[p2]);
	else
		printf("FAILED. Hand size start: %d   Hand size finish: %d\n", g.handCount[p2], testState.handCount[p2]);

	
	
	// Test that Player 2's deck was not affected
	printf("\nTest 3b: Other player's deck size unchanged when adventurer is drawn:\n");
	if(testState.deckCount[p2] == g.deckCount[p2])
		printf("Passed. Deck size start: %d   Deck size finish: %d\n", g.deckCount[p2], testState.deckCount[p2]);
	else
		printf("FAILED. Deck size start: %d   Deck size finish: %d\n", g.deckCount[p2], testState.deckCount[p2]);

	
	
	// Test that the cards are drawn from the player's deck
	printf("\nTest 4: No cards should be missing from the deck beyond what was discarded at end of turn:\n");
	if(g.deckCount[p] - testState.discardCount[p] -2 == testState.deckCount[p])   // 2 for drawn, 5 for hand count
		printf("Passed. Expected deck amount: %d   Deck finish: %d\n", g.deckCount[p] - 2 - testState.discardCount[p], testState.deckCount[p]);
	else
		printf("FAILED. Expected deck amount: %d  Deck finish: %d\n", g.deckCount[p] - 2 - testState.discardCount[p], testState.deckCount[p]);

	

	// Test that the adventurer card is discarded to the played pile
	printf("\nTest 5: Adventurer card added to played pile after use:\n");
	if(testState.playedCardCount == 1)
		printf("Passed. Expected increase in played pile: %d     To played pile: %d\n", 1, testState.playedCardCount);
	else
		printf("FAILED. Expected increase in played pile: %d   To played pile: %d\n", 1, testState.playedCardCount);

	
	
	// Test for any victory cards given out inappropriately
	printf("\nTest 6: : Test supply counts for points and curses that should not have been distributed: \n ");
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
	printf("\nTest 7: Test supply counts for treasure that should have been distributed: \n");
	if(g.supplyCount[copper] != testState.supplyCount[copper])
		printf("FAILED. copper Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[copper], testState.supplyCount[copper]);
	if(g.supplyCount[silver] != testState.supplyCount[silver])
		printf("FAILED. silver Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[silver], testState.supplyCount[silver]);
	if(g.supplyCount[gold] != testState.supplyCount[gold])
		printf("FAILED. gold Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[gold], testState.supplyCount[gold]);
	else
		printf("Passed. Supply counts for treasure cards are the same\n");
}

/****************************************************************
** Function Name: allRandom()
** Input: player, number of total players, the upper boundary max
** 		for the deck count, position and the game state
** Output: Displays test results
** Description: Playe adventurer with entirely random inputs 
** 		within a valid game state, deck may have any combination 
** 		of cards with no guarantees of amount of each type, in deck
******************************************************************/
void allRandom(int p, int numPlayers, int maxDeck, int position, struct gameState g){
	int j; 							 								// counter
	int p2 = 1;														// player
	int preCount, preamount;
	int amount = 0;
	struct gameState testState;										// test game state

	// Display test conditions/randomness
	printf("\n\nTEST CONDITIONS TWO: Random players, completely random deck, completely random hand, valid gameState\n\n");
		

	// Deck should shuffle if deckCount = 0
	printf("\nTest 1: If deckCount is zero, shuffle should be selected:\n");
	memcpy(&testState, &g, sizeof(struct gameState));
	preCount = testState.handCount[p];
	preamount = 0;
	if(testState.deckCount != 0){
		printf("Test parameters not met.\n");
	}
	else{
		cardEffect(adventurer, 0, 0, 0, &testState, 0, 0);			// should have two coin cards when done
		if(testState.deckCount == g.deckCount)
			printf("FAILED. Shuffle not called, no cards added\n");
		else
			printf("Passed. Deck was empty, shuffle called, state changed\n");
	}


	// Play Adventurer card and draw until two teasure cards are drawn 
	printf("\nTest 2: Play Adventurer and draw until two coins are drawn:\n");
	memcpy(&testState, &g, sizeof(struct gameState));
	preCount = testState.handCount[p];
	preamount = g.coins;
	amount = 0;
	printf("Coin cards in hand originally, if any: ");
	for(j = 0; j < testState.handCount[p]; j++){
		if(testState.hand[p][j] == copper){
			printf("copper, ");
			preamount += 1;
			preCount++;
		}
		if(testState.hand[p][j] == silver){
			printf("silver, ");
			preamount += 2;
			preCount++;
		}
		if(testState.hand[p][j] == gold){
			printf("gold, ");
			preamount += 3;
			preCount++;
		}
	}
	printf("\n");
	cardEffect(adventurer, 0, 0, 0, &testState, 0, 0);
	
	printf("Coin cards Found: ");
	for(j = 0; j < testState.handCount[p]; j++){
		if(testState.hand[p][j] == copper){
			printf("copper, ");
			amount += 1;
		}
		if(testState.hand[p][j] == silver){
			printf("silver, ");
			amount += 2;
		}
		if(testState.hand[p][j] == gold){
			printf("gold, ");
			amount += 3;
		}
	}

	printf("\n");
	// Test that the Player's coins increased
	if(amount == testState.coins)
		printf("Passed. Coin card amount expected: %d   amount finish: %d\n", amount, testState.coins);
	else 
		printf("FAILED. Coin card amount expected: %d   amount finish: %d\n", amount, testState.coins);


	// Test the game state of the coins
	printf("\nTest 3: Gained cards, coin amount unchanged till use:\n");
	if(g.coins == testState.coins)
		printf("Passed. Coin amount the same\n");
	else
		printf("FAILED. Coin amount different\n");

	// Test that the player's hand count changed appropriately
	printf("\nTest 2: Gained appropriate card amount:\n");
	if(testState.handCount[p] == g.handCount[p] + 2)				// - adventurer, + 2, = gain 1 
		printf("Passed. Hand count expected: %d   Hand count finish: %d\n", g.handCount[p] + 2, testState.handCount[p]);
	else 
		printf("FAILED. Hand count expected: %d   Hand count finish: %d\n", g.handCount[p] +2, testState.handCount[p]);


	// Tes that Player 2's hand was not affected
	printf("\nTest 4: Other player's hand size unchanged when adventurer is drawn:\n");
	if(testState.handCount[p2] == g.handCount[p2])
		printf("Passed. Hand size start: %d   Hand size finish: %d\n", g.handCount[p2], testState.handCount[p2]);
	else
		printf("FAILED. Hand size start: %d   Hand size finish: %d\n", g.handCount[p2], testState.handCount[p2]);


	// Test that the cards came from the player's deck
	printf("\nTest 4: No cards should be missing from the deck beyond what was discarded at end of turn:\n");
	if(g.deckCount[p] - testState.discardCount[p] -2 == testState.deckCount[p])   // 2 for drawn, 5 for hand count
		printf("Passed. Expected deck amount: %d   Deck finish: %d\n", g.deckCount[p] - testState.discardCount[p] -2, testState.deckCount[p]);
	else
		printf("FAILED. Expected deck amount: %d  Deck finish: %d\n", g.deckCount[p] - testState.discardCount[p] -2, testState.deckCount[p]);


	// Test that the discarded Adventurer went to the played pile
	printf("\nTest 5: Adventurer card added to played pile after use:\n");
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
		printf("FAILED. Copper Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[copper], testState.supplyCount[copper]);
	if(g.supplyCount[silver] != testState.supplyCount[silver])
		printf("FAILED. Silver Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[silver], testState.supplyCount[silver]);
	if(g.supplyCount[gold] != testState.supplyCount[gold])
		printf("FAILED. Gold Count Mismatch. Expected: %d  Received: %d\n", g.supplyCount[gold], testState.supplyCount[gold]);
	else
		printf("Passed. Supply counts for treasure cards are the same\n");
}


int main(){	
	int i, j;														// counter
	int numTests = 2000; 											// large testing spread
	int numPlayers;													// player amount
	int maxDeck;													// deck size
	int position;													// position of card
	int p = 0;														// player
	struct gameState g;												// gamestate
	int k[10] = {duchy, gardens, province, estate, tribute, mine, cutpurse, ambassador, great_hall, adventurer};
	int deckSize = 27;												// used as a boundary, decksize will be initialized random

	//set rand
	srand(time(NULL));
	
	// loop through, calling functions with random elements in gamestate
	printf("*******  TESTING CARD: Adventurer  *******\n\n");	
	for(i = 0; i < numTests; i++){
		numPlayers = (rand()%3)+2;									// random number of players within valid range
		initializeGame(numPlayers, k, 1000, &g);
		maxDeck = rand()%deckSize + 1;								// random deck amount in valid range
		g.deckCount[p] = maxDeck;									// set for player in question
		g.handCount[p] = rand()%6 + 1;								// random starting hand, lower boundary
		position = rand()%g.handCount[p] + 1;						// pick a hand location
		g.hand[p][position] = adventurer;							// make sure adventurer is present
		for(j = 0; j < maxDeck; j++){								// make sure deck is random
			if(j == position)
				continue;
			g.deck[p][j] = rand()%17+1;
		}

		// Pass random values to test functions
		printf("\nInputs:\nDeck Size: %d\tHand Count: %d\t, Players: %d\t Position: %d\n", maxDeck, g.handCount[p], numPlayers, position);
		treasureRandom(p, numPlayers, maxDeck, position, g);
		allRandom(p, numPlayers, maxDeck, position, g);
	}

	return 0;
}