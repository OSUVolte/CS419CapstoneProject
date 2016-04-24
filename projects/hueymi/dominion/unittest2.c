/*
 * unittest2.c
 * tests fullDeckCount()
 
 */



#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int testFullDeckCount() {
	char * UNITTEST = "fullDeckCount()";
    int i;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, remodel, village, ambassador, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int coinCards[3][2] = {
		{copper, 1},
		{silver, 2},
		{gold, 3}
	};
	int fullDeckResult;

	// Initialize the game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	
	// Initialize the entire deck with coppers
	for (i = 0; i< G.deckCount[thisPlayer]; i++)
	{
		G.deck[thisPlayer][i] = copper;
	}
	
	// Initialize the hand with 2 coppers and 3 estates
	for (i = 0; i < G.handCount[thisPlayer]; i++){
		if (i < 2) G.hand[thisPlayer][i] = copper;
		else G.hand[thisPlayer][i] = estate;
	}
	
	printf("\n\n----------------- Testing of Function: %s ----------------\n", UNITTEST);

	
	/****************************************************
	Test 1: After initialization, there should be 7 coppers, 3 estates, and 0 smithys
	****************************************************/
	printf("\nTEST 1: Immediately after initialization \n");
	
	// Create a test copy
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Number of coppers should be 7
	fullDeckResult = fullDeckCount(thisPlayer, copper, &testG);
	printf("coppers = %d, expected = %d\n", fullDeckResult, 7);
	assert (fullDeckResult == 7);
	
	// Number of estates should be 3}
	fullDeckResult = fullDeckCount(thisPlayer, estate, &testG);
	printf("estates = %d, expected = %d\n", fullDeckResult, 3);
	assert (fullDeckResult == 3);
	
	// Number of smithys should be 0
	fullDeckResult = fullDeckCount(thisPlayer, smithy, &testG);
	printf("smithys = %d, expected = %d\n", fullDeckResult, 0);
	assert (fullDeckResult == 0);
	
	
	/****************************************************
	Test 2: Switch the hand with the deck
	****************************************************/
	printf("\nTEST 2: Switch the hand with the deck (should have no change) \n");
	
	// Create a test copy
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Switch the hand with the deck using temporary array
	int tempArray[5];
	for (i = 0; i< G.deckCount[thisPlayer]; i++)
	{
		tempArray[i] = testG.deck[thisPlayer][i];
		testG.deck[thisPlayer][i] = testG.hand[thisPlayer][i];
		testG.hand[thisPlayer][i] = tempArray[i];
	}
	
	// Number of coppers should be 7
	fullDeckResult = fullDeckCount(thisPlayer, copper, &testG);
	printf("coppers = %d, expected = %d\n", fullDeckResult, 7);
	assert (fullDeckResult == 7);
	
	// Number of estates should be 3}
	fullDeckResult = fullDeckCount(thisPlayer, estate, &testG);
	printf("estates = %d, expected = %d\n", fullDeckResult, 3);
	assert (fullDeckResult == 3);
	
	// Number of smithys should be 0
	fullDeckResult = fullDeckCount(thisPlayer, smithy, &testG);
	printf("smithys = %d, expected = %d\n", fullDeckResult, 0);
	assert (fullDeckResult == 0);
	
	
	
	/****************************************************
	Test 3: Replace all coppers with smithys
	****************************************************/
	printf("\nTEST 3: Replacing all coppers with smithys \n");
	
	// Create a test copy
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Replace all coppers in deck with smithys
	for (i = 0; i< testG.deckCount[thisPlayer]; i++)
	{
		if (testG.deck[thisPlayer][i] == copper)
			testG.deck[thisPlayer][i] = smithy;
	}
	
	// Replace all coppers in hand with smithys
	for (i = 0; i < testG.handCount[thisPlayer]; i++){
		if (testG.hand[thisPlayer][i] == copper)
			testG.hand[thisPlayer][i] = smithy;
	}

	// Number of coppers should be 7
	fullDeckResult = fullDeckCount(thisPlayer, copper, &testG);
	printf("coppers = %d, expected = %d\n", fullDeckResult, 0);
	assert (fullDeckResult == 0);
	
	// Number of estates should be 3}
	fullDeckResult = fullDeckCount(thisPlayer, estate, &testG);
	printf("estates = %d, expected = %d\n", fullDeckResult, 3);
	assert (fullDeckResult == 3);
	
	// Number of smithys should be 0
	fullDeckResult = fullDeckCount(thisPlayer, smithy, &testG);
	printf("smithys = %d, expected = %d\n", fullDeckResult, 7);
	assert (fullDeckResult == 7);
	
	
	/****************************************************
	Test 4: Add 2 smithys to the hand
	****************************************************/
	printf("\nTEST 4: Add 2 smithys to the hand \n");
	
	// Create a test copy
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Increase the handCount
	testG.handCount[thisPlayer] += 2;
	
	// Add 2 smithy cars to the hand
	testG.hand[thisPlayer][5] = smithy;
	testG.hand[thisPlayer][6] = smithy;

	// Number of coppers should be 7
	fullDeckResult = fullDeckCount(thisPlayer, copper, &testG);
	printf("coppers = %d, expected = %d\n", fullDeckResult, 7);
	assert (fullDeckResult == 7);
	
	// Number of estates should be 3}
	fullDeckResult = fullDeckCount(thisPlayer, estate, &testG);
	printf("estates = %d, expected = %d\n", fullDeckResult, 3);
	assert (fullDeckResult == 3);
	
	// Number of smithys should be 0
	fullDeckResult = fullDeckCount(thisPlayer, smithy, &testG);
	printf("smithys = %d, expected = %d\n", fullDeckResult, 2);
	assert (fullDeckResult == 2);
	
	
	/****************************************************
	Test 5: Add 2 smithys to the discard pile
	****************************************************/
	printf("\nTEST 5: Add 2 smithys to the discard pile \n");
	
	// Create a test copy
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Increase the handCount
	testG.discardCount[thisPlayer] += 2;
	
	// Add 2 smithy cars to the hand
	testG.discard[thisPlayer][0] = smithy;
	testG.discard[thisPlayer][1] = smithy;

	// Number of coppers should be 7
	fullDeckResult = fullDeckCount(thisPlayer, copper, &testG);
	printf("coppers = %d, expected = %d\n", fullDeckResult, 7);
	assert (fullDeckResult == 7);
	
	// Number of estates should be 3}
	fullDeckResult = fullDeckCount(thisPlayer, estate, &testG);
	printf("estates = %d, expected = %d\n", fullDeckResult, 3);
	assert (fullDeckResult == 3);
	
	// Number of smithys should be 0
	fullDeckResult = fullDeckCount(thisPlayer, smithy, &testG);
	printf("smithys = %d, expected = %d\n", fullDeckResult, 2);
	assert (fullDeckResult == 2);

	/****************************************************
	Test 6: Remove two estates from the hand
	****************************************************/
	printf("\nTEST 6: Remove 2 estates from the hand\n");
	
	// Create a test copy
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Increase the handCount
	testG.handCount[thisPlayer] -= 2;
	
	// Remove 2 estate cards from the hand
	testG.hand[thisPlayer][3] = -1;
	testG.hand[thisPlayer][4] = -1;

	// Number of coppers should be 7
	fullDeckResult = fullDeckCount(thisPlayer, copper, &testG);
	printf("coppers = %d, expected = %d\n", fullDeckResult, 7);
	assert (fullDeckResult == 7);
	
	// Number of estates should be 3}
	fullDeckResult = fullDeckCount(thisPlayer, estate, &testG);
	printf("estates = %d, expected = %d\n", fullDeckResult, 1);
	assert (fullDeckResult == 1);
	
	// Number of smithys should be 0
	fullDeckResult = fullDeckCount(thisPlayer, smithy, &testG);
	printf("smithys = %d, expected = %d\n", fullDeckResult, 0);
	assert (fullDeckResult == 0);
	
	/****************************************************
	Test 7: Add two smithys to another player's hand
	****************************************************/
	printf("\nTEST 7: Add 2 smithys to another player's hand\n");
	
	// Create a test copy
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Increase the handCount
	testG.handCount[thisPlayer+1] += 2;
	
	// Remove 2 estate cards from the hand
	testG.hand[thisPlayer +1][5] = smithy;
	testG.hand[thisPlayer+ 1][6] = smithy;

	// Number of coppers should be 7
	fullDeckResult = fullDeckCount(thisPlayer, copper, &testG);
	printf("coppers = %d, expected = %d\n", fullDeckResult, 7);
	assert (fullDeckResult == 7);
	
	// Number of estates should be 3}
	fullDeckResult = fullDeckCount(thisPlayer, estate, &testG);
	printf("estates = %d, expected = %d\n", fullDeckResult, 3);
	assert (fullDeckResult == 3);
	
	// Number of smithys should be 0
	fullDeckResult = fullDeckCount(thisPlayer, smithy, &testG);
	printf("smithys = %d, expected = %d\n", fullDeckResult, 0);
	assert (fullDeckResult == 0);	
	
	
	printf("\n >>>>> SUCCESS: Testing complete of %s <<<<<\n\n\n", UNITTEST);


	return 0;
}


