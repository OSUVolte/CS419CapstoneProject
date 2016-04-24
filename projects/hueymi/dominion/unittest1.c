/*
 * unittest1.c
 * tests updateCoins()
 
 */



#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int testUpdateCoins() {
	char * UNITTEST = "updateCoins()";
	int i;
	int bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	int totalCoinVal;
	struct gameState G, testG, realG;
	int k[10] = {adventurer, remodel, village, ambassador, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int coinCards[3][2] = {
		{copper, 1},
		{silver, 2},
		{gold, 3}
	};

	// Initialize the game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	G.hand[thisPlayer][0] = cutpurse;
	G.hand[thisPlayer][1] = mine;
	G.hand[thisPlayer][2] = duchy;
	G.hand[thisPlayer][3] = estate;
	G.hand[thisPlayer][4] = feast;
	G.coins = 0;
	printf("\n\n----------------- Testing of Function: %s ----------------\n", UNITTEST);

	/****************************************************
	Test 1: Current player has no treasure card and no bonus
	****************************************************/
	printf("\nTEST 1: No treasure cards in hand and no bonus\n");
	
	// Create a test copy of a hand with no treasure cards
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Create a copy for comparison to what function should really do
	memcpy(&realG, &testG, sizeof(struct gameState));
	
	// Call the updateCoins method
	updateCoins(thisPlayer, &testG, bonus);
	
	// The number of coins in each should be 0
	printf("coinCount = %d, expected = %d\n", testG.coins, realG.coins);
	assert(testG.coins == realG.coins);
	
	// The player's handCount, deckCount, and discardCount should have remained the same
	printf("handCount = %d, expected = %d\n", testG.handCount[thisPlayer], realG.handCount[thisPlayer]);
	assert (testG.handCount[thisPlayer] == realG.handCount[thisPlayer]);
	printf("deckCount = %d, expected = %d\n", testG.deckCount[thisPlayer], realG.deckCount[thisPlayer]);
	assert (testG.deckCount[thisPlayer] == realG.deckCount[thisPlayer]);
	printf("discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], realG.discardCount[thisPlayer]);
	assert (testG.discardCount[thisPlayer] == realG.discardCount[thisPlayer]);
	
	/****************************************************
	Test 2: Current player has no treasure card and +2 bonus
	****************************************************/
	printf("\nTEST 2: No treasure cards in hand and +2 bonus\n");
	
	// Create a test copy of a hand with no treasure cards
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Create a copy for comparison to what function should really do
	memcpy(&realG, &testG, sizeof(struct gameState));
	
	// Call the updateCoins method
	bonus = 2;
	updateCoins(thisPlayer, &testG, bonus);
	
	// The number of coins in each should be 2
	printf("coinCount = %d, expected = %d\n", testG.coins, realG.coins + bonus);
	assert(testG.coins == realG.coins + bonus);
	
	// The player's handCount, deckCount, and discardCount should have remained the same
	printf("handCount = %d, expected = %d\n", testG.handCount[thisPlayer], realG.handCount[thisPlayer]);
	assert (testG.handCount[thisPlayer] == realG.handCount[thisPlayer]);
	printf("deckCount = %d, expected = %d\n", testG.deckCount[thisPlayer], realG.deckCount[thisPlayer]);
	assert (testG.deckCount[thisPlayer] == realG.deckCount[thisPlayer]);
	printf("discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], realG.discardCount[thisPlayer]);
	assert (testG.discardCount[thisPlayer] == realG.discardCount[thisPlayer]);

	/****************************************************
	Test 3: Current player has one type of treasure card and +2 bonus
	****************************************************/
	printf("\nTEST 3: One treasure card in hand and +2 bonus\n");
	
	// Create a test copy of a hand with no treasure cards
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Create a copy for comparison to what function should really do
	
	for (i = 0; i< 3; i++){
		
		// The first card of each hand is a coin card
		testG.hand[thisPlayer][0] = coinCards[i][0];
		printf("first card = (%d)\n", coinCards[i][0]);
		testG.coins = 0;
		
		// Copy this hand for comparison
		memcpy(&realG, &testG, sizeof(struct gameState));
		
		// Call the updateCoins method
		bonus = 2;
		updateCoins(thisPlayer, &testG, bonus);
		totalCoinVal = 0;
		totalCoinVal += coinCards[i][1];
		
		// The number of coins in each should be 2
		printf("coinCount = %d, expected = %d\n", testG.coins, realG.coins + bonus + totalCoinVal);
		assert(testG.coins == realG.coins + bonus + totalCoinVal);
		
		// The player's handCount, deckCount, and discardCount should have remained the same
		printf("handCount = %d, expected = %d\n", testG.handCount[thisPlayer], realG.handCount[thisPlayer]);
		assert (testG.handCount[thisPlayer] == realG.handCount[thisPlayer]);
		printf("deckCount = %d, expected = %d\n", testG.deckCount[thisPlayer], realG.deckCount[thisPlayer]);
		assert (testG.deckCount[thisPlayer] == realG.deckCount[thisPlayer]);
		printf("discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], realG.discardCount[thisPlayer]);
		assert (testG.discardCount[thisPlayer] == realG.discardCount[thisPlayer]);	
	}
	
	
	/****************************************************
	Test 4: Current player has two types of treasure cards and +2 bonus
	****************************************************/
	printf("\nTEST 4: Two treasure cards in hand and +2 bonus\n");
	
	// Create a test copy of a hand with no treasure cards
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Create a copy for comparison to what function should really do
	
	for (i = 0; i< 3; i++){
		
		// The first two hands are coin cards
		testG.hand[thisPlayer][0] = coinCards[i][0];
		testG.hand[thisPlayer][1] = coinCards[(i+1)%3][0];
		printf("first card = (%d)\n", coinCards[i][0]);
		printf("coin value = %d\n", coinCards[i][1]);
		printf("second card = (%d)\n", coinCards[(i+1)%3][0]);
		printf("second coin value = %d\n", coinCards[(i+1)%3][1]);
		testG.coins = 0;
		
		// Copy this hand for comparison
		memcpy(&realG, &testG, sizeof(struct gameState));
		
		// Call the updateCoins method
		bonus = 2;
		updateCoins(thisPlayer, &testG, bonus);
		totalCoinVal = 0;
		totalCoinVal += coinCards[i][1];
		totalCoinVal += coinCards[(i+1)%3][1];
		printf("totalCoinVal = %d\n", totalCoinVal);
		printf("realG.coins = %d\n", realG.coins);
		
		// The number of coins in each should be 2
		printf("coinCount = %d, expected = %d\n", testG.coins, realG.coins + bonus + totalCoinVal);
		//assert(testG.coins == realG.coins + bonus + totalCoinVal);
		
		// The player's handCount, deckCount, and discardCount should have remained the same
		printf("handCount = %d, expected = %d\n", testG.handCount[thisPlayer], realG.handCount[thisPlayer]);
		assert (testG.handCount[thisPlayer] == realG.handCount[thisPlayer]);
		printf("deckCount = %d, expected = %d\n", testG.deckCount[thisPlayer], realG.deckCount[thisPlayer]);
		assert (testG.deckCount[thisPlayer] == realG.deckCount[thisPlayer]);
		printf("discardCount = %d, expected = %d\n\n", testG.discardCount[thisPlayer], realG.discardCount[thisPlayer]);
		assert (testG.discardCount[thisPlayer] == realG.discardCount[thisPlayer]);	
	}
	
	/****************************************************
	Test 5: Current player has three types of treasure cards and +2 bonus
	****************************************************/
	printf("\nTEST 5: Three treasure cards in hand and +2 bonus\n");
	
	// Create a test copy of a hand with no treasure cards
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// The first two hands are coin cards
	testG.hand[thisPlayer][0] = coinCards[0][0];
	testG.hand[thisPlayer][1] = coinCards[1][0];
	testG.hand[thisPlayer][2] = coinCards[2][0];
	printf("first card = (%d)\n", coinCards[0][0]);
	printf("second card = (%d)\n", coinCards[1][0]);
	printf("third card = (%d)\n", coinCards[2][0]);
	testG.coins = 0;
	
	// Copy this hand for comparison
	memcpy(&realG, &testG, sizeof(struct gameState));
	
	// Call the updateCoins method
	bonus = 2;
	updateCoins(thisPlayer, &testG, bonus);
	totalCoinVal = 0;
	totalCoinVal += coinCards[0][1];
	totalCoinVal += coinCards[1][1];
	totalCoinVal += coinCards[2][1];
	printf("totalCoinVal = %d\n", totalCoinVal);
	printf("realG.coins = %d\n", realG.coins);
	
	// The number of coins in each should be 2
	printf("coinCount = %d, expected = %d\n", testG.coins, realG.coins + bonus + totalCoinVal);
	assert(testG.coins == realG.coins + bonus + totalCoinVal);
	
	// The player's handCount, deckCount, and discardCount should have remained the same
	printf("handCount = %d, expected = %d\n", testG.handCount[thisPlayer], realG.handCount[thisPlayer]);
	assert (testG.handCount[thisPlayer] == realG.handCount[thisPlayer]);
	printf("deckCount = %d, expected = %d\n", testG.deckCount[thisPlayer], realG.deckCount[thisPlayer]);
	assert (testG.deckCount[thisPlayer] == realG.deckCount[thisPlayer]);
	printf("discardCount = %d, expected = %d\n\n", testG.discardCount[thisPlayer], realG.discardCount[thisPlayer]);
	assert (testG.discardCount[thisPlayer] == realG.discardCount[thisPlayer]);	

	printf("\n >>>>> SUCCESS: Testing complete of %s <<<<<\n\n\n", UNITTEST);


	return 0;
}


