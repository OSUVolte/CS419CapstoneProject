/*
 * unittest3.c
 * tests endTurn()
 
 */



#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int testEndTurn() {
	char* UNITTEST = "endTurn()";
    int i;
    int seed = 1000;
    int numPlayers = 3;
    int thisPlayer = 0;
	struct gameState G, testG, realG;
	int k[10] = {adventurer, remodel, village, ambassador, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int prevHandCount;
	int prevDiscardCount;

	// Initialize the game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	
	printf("\n\n----------------- Testing of Function: %s ----------------\n", UNITTEST);

	/****************************************************
	Test 1: First player has 5 cards in hand when turn ends
	****************************************************/
	printf("\nTEST 1: First player has 5 cards in hand when turn ends \n");
	
	// Store previous hand count and previous discard count
	prevHandCount = G.handCount[thisPlayer];
	printf("prevHandCount of previous player = %d\n", prevHandCount);
	prevDiscardCount = G.discardCount[thisPlayer];
	printf("prevDiscard of previous player = %d\n", prevDiscardCount);
	
	// End the first player's turn
	endTurn(&G);
	thisPlayer = (thisPlayer + 1)%3;
	
	// At the end of the turn, it should be the next player's hand
	printf("whoseTurn = %d, expected = %d\n", whoseTurn(&G), 1);
	assert(whoseTurn(&G) == 1);
	
	// The hand count of the previous player should be 0
	printf("handCount of previous player = %d, expected = %d\n", G.handCount[(thisPlayer-1)%numPlayers], 0);
	assert (G.handCount[(thisPlayer-1)%numPlayers] ==  0);
	
	// The discard count of the previous player should increase by the previous hand count
	printf("discardCount of previous player= %d, expected = %d\n", G.discardCount[(thisPlayer-1)%numPlayers], prevHandCount + prevDiscardCount);
	assert (G.discardCount[(thisPlayer-1)%numPlayers] ==  prevHandCount + prevDiscardCount);
	
	// The hand count of the current player should be 5
	printf("handCount of current player = %d, expected = %d\n", G.handCount[thisPlayer], 5);
	assert (G.handCount[thisPlayer] ==  5);
	
	

	/****************************************************
	Test 2: Second player has 3 cards in hand when turn ends
	****************************************************/	
	printf("\nTEST 2: Second player has 3 cards in hand when turn ends \n");

	// Make sure that the second player has only 3 cards in hand
	G.handCount[thisPlayer] -=2;
	G.hand[thisPlayer][4] = -1;
	G.hand[thisPlayer][3] = -1;
	
	// Store previous hand count and previous discard count
	prevHandCount = G.handCount[thisPlayer];
	printf("prevHandCount of previous player = %d\n", prevHandCount);
	prevDiscardCount = G.discardCount[thisPlayer];
	printf("prevDiscard of previous player = %d\n", prevDiscardCount);
	
	// End the second player's turn
	endTurn(&G);
	thisPlayer = (thisPlayer + 1)%3;
	
	// At the end of the turn, it should be the next player's hand
	printf("whoseTurn = %d, expected = %d\n", whoseTurn(&G), thisPlayer);
	assert(whoseTurn(&G) == thisPlayer);
	
	// The hand count of the previous player should be 0
	printf("handCount of previous player = %d, expected = %d\n", G.handCount[(thisPlayer-1)%numPlayers], 0);
	assert (G.handCount[(thisPlayer-1)%numPlayers] ==  0);
	
	// The discard count of the previous player should increase by the previous hand count
	printf("discardCount of previous player= %d, expected = %d\n", G.discardCount[(thisPlayer-1)%numPlayers], prevHandCount + prevDiscardCount);
	assert (G.discardCount[(thisPlayer-1)%numPlayers] ==  prevHandCount + prevDiscardCount);
	
	// The hand count of the current player should be 5
	printf("handCount of current player = %d, expected = %d\n", G.handCount[thisPlayer], 5);
	assert (G.handCount[thisPlayer] ==  5);
	

	/****************************************************
	Test 3: Third player has no cards in hand when turn ends
	****************************************************/	
	printf("\nTEST 3: Third player has no cards in hand when turn ends \n");

	// Make sure that the second player has only 3 cards in hand
	G.handCount[thisPlayer] -=5;
	for (i = 0; i < G.handCount[thisPlayer]; i++){
		G.hand[thisPlayer][i] = -1;
	}

	// Store previous hand count and previous discard count
	prevHandCount = G.handCount[thisPlayer];
	printf("prevHandCount of previous player = %d\n", prevHandCount);
	prevDiscardCount = G.discardCount[thisPlayer];
	printf("prevDiscard of previous player = %d\n", prevDiscardCount);
	
	// End the third player's turnf
	endTurn(&G);
	thisPlayer = (thisPlayer + 1)%3;
	
	// At the end of the turn, it should be the next player's hand
	printf("whoseTurn = %d, expected = %d\n", whoseTurn(&G), thisPlayer);
	assert(whoseTurn(&G) == thisPlayer);
	
	// The hand count of the previous player should be 0
	printf("handCount of previous player = %d, expected = %d\n", G.handCount[(thisPlayer-1)%numPlayers], 0);
	assert (G.handCount[(thisPlayer-1)%numPlayers] ==  0);
	
	// The discard count of the previous player should increase by the previous hand count
	printf("discardCount of previous player= %d, expected = %d\n", G.discardCount[(thisPlayer-1)%numPlayers], prevHandCount + prevDiscardCount);
	assert (G.discardCount[(thisPlayer-1)%numPlayers] ==  prevHandCount + prevDiscardCount);
	
	// The hand count of the current player should be 5
	printf("handCount of current player = %d, expected = %d\n", G.handCount[thisPlayer], 5);
	assert (G.handCount[thisPlayer] ==  5);
	
	
	printf("\n >>>>> SUCCESS: Testing complete of %s <<<<<\n\n\n", UNITTEST);


	return 0;
}


