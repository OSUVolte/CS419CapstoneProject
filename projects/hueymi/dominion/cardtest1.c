/*
 * cardtest1.c
 * tests card smithy
 
 */



#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int testSmithy() {
	char* UNITTEST = "Smithy";
    int i;
	int provinceCount = 12;
	int kingdomCount = 10;
	int copperCount = 39;
	int silverCount = 40;
	int goldCount = 30;
    int seed = 1000;
    int numPlayers = 3;
    int thisPlayer = 0;
	int prevPlayer = 0;
	int choice1 = 1, choice2 = 0, choice3 = 0, handPos = 0, bonus = 0;
	struct gameState G, testG, realG;
	int k[10] = {adventurer, remodel, village, ambassador, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int prevHandCount[3];
	int prevDiscardCount[3];
	int prevDeckCount[3];

	// Initialize the game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	G.hand[thisPlayer][0] = smithy;
	G.hand[thisPlayer][1] = estate;
	G.hand[thisPlayer][2] = remodel;
	G.hand[thisPlayer][3] = estate;
	G.hand[thisPlayer][4] = village;
	
	printf("\n\n----------------- Testing of Card: %s ----------------\n", UNITTEST);

	
	/****************************************************
	Test 1: First player draws all coppers from deck
	****************************************************/
	printf("\nTEST 1: Current player draws all coppers from deck \n");
	
	// Create a copy of the original hand
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// The next five cards in the current player's deck are all coppers
	for (i = 0; i<testG.deckCount[thisPlayer]; i++) {
		testG.deck[thisPlayer][i] = copper;
	}
	
	// Keep track of hand count and discard count for all players
	for (i = 0; i < numPlayers; i++){
		prevHandCount[i] = testG.handCount[i];
		prevDiscardCount[i] = testG.discardCount[i];
		prevDeckCount[i] = testG.deckCount[i];
	}
	prevPlayer = thisPlayer;
	
	// Play the smithy card
	cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);
	
	// It should still be the current player's turn
	printf("current player = %d, expected = %d\n", thisPlayer, prevPlayer);
	if (thisPlayer != prevPlayer)
		printf("********** ERROR: current player mismatch**********\n");
	
	// The total number of cards added to the player's hand should be 2
	printf("current player's handCount = %d, expected = %d\n", testG.handCount[thisPlayer], prevHandCount[thisPlayer] + 2);
	if (testG.handCount[thisPlayer] != prevHandCount[thisPlayer] + 2)
		printf("********** ERROR: current player's hand mismatch**********\n");
	
	// The total number of cards in the discard pile should be the same
	printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], prevDiscardCount[thisPlayer]);
	if (testG.discardCount[thisPlayer] != prevDiscardCount[thisPlayer])
		printf("********** ERROR: current player's discard pile mismatch**********\n");
	
	// The total number of played cards should be 1
	printf("played cards = %d, expected = %d\n", testG.playedCardCount, 1);
	if (testG.playedCardCount != 1)
		printf("********** ERROR: played card pile mismatch**********\n");
	
	// The 3 cards should come from player's own deck
	printf("current player's deckCount = %d, expected = %d\n", testG.deckCount[thisPlayer], prevDeckCount[thisPlayer] - 3);
	if (testG.deckCount[thisPlayer] != prevDeckCount[thisPlayer] - 3)
		printf("********** ERROR: current player's deck pile mismatch**********\n");
	
	// The total number of cards added to the other player's hands and deck should be 0
	for (i = 0; i< numPlayers; i++){
		if (i != thisPlayer) {
			printf("player %d's handCount = %d, expected = %d\n", i, testG.handCount[i], prevHandCount[i]);
			if (testG.handCount[i] != prevHandCount[i])
				printf("********** ERROR: player %d's handCount mismatch**********\n", i);
			printf("player %d's discardCount = %d, expected = %d\n", i, testG.discardCount[i], prevDiscardCount[i]);
			if (testG.discardCount[i] != prevDiscardCount[i])
				printf("********** ERROR: player %d's discardCount mismatch**********\n", i);
			printf("player %d's deckCount = %d, expected = %d\n", i, testG.deckCount[i], prevDeckCount[i]);
			if (testG.deckCount[i] != prevDeckCount[i])
				printf("********** ERROR: player %d's deckCount mismatch**********\n", i);
		}
	}
	
	// The first card should no longer be smithy (it should be the last card - one of the drawn cards)
	printf("first card = %d, expected = %d\n", testG.hand[thisPlayer][0], copper);
	if (testG.hand[thisPlayer][0] != copper)
		printf("********** ERROR: mismatch**********\n");
	
	
	// Theoretically, there should still be 12 province, estate, and duchy cards originally
	printf("province cards = %d\n", testG.supplyCount[province]);
	assert(testG.supplyCount[province] == 12);
	printf("estate cards = %d\n", testG.supplyCount[estate]);
	assert(testG.supplyCount[estate] == 12);
	printf("duchy cards = %d\n", testG.supplyCount[duchy]);
	assert(testG.supplyCount[duchy] == 12);
	
	// Theoretically, there should be 10 each of all the kindom cards
	for (i = 0; i < 10; i++) {
		printf("kingdom card (%d) = %d\n", k[i], testG.supplyCount[k[i]]);
	}
	
	// Theoretically, there should be 39 coppers, 40 silvers, and 30 gold
	printf("copper cards = %d\n", testG.supplyCount[copper]);
	assert(testG.supplyCount[copper] == 39);
	printf("silver cards = %d\n", testG.supplyCount[silver]);
	assert(testG.supplyCount[silver] == 40);
	printf("gold cards = %d\n", testG.supplyCount[gold]);
	assert(testG.supplyCount[gold] == 30);
	
	// Therefore, the game should not be over
	printf("game over = %d, expected = %d\n", isGameOver(&testG), 0);
	assert(isGameOver(&testG) == 0);
	
	
	/****************************************************
	Test 2: Second player draws all coppers from deck
	****************************************************/
	printf("\n\nTEST 2: Second player draws all coppers from deck \n");
	
	// Create a copy of the original hand
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// End the first player's turn
	endTurn(&testG);
	thisPlayer = (thisPlayer + 1)% numPlayers;
	
	// The next five cards in the current player's deck are all coppers
	for (i = 0; i<testG.deckCount[thisPlayer]; i++) {
		testG.deck[thisPlayer][i] = copper;
	}
	
	// Keep track of hand count and discard count for all players
	for (i = 0; i < numPlayers; i++){
		prevHandCount[i] = testG.handCount[i];
		prevDiscardCount[i] = testG.discardCount[i];
		prevDeckCount[i] = testG.deckCount[i];
	}
	prevPlayer = thisPlayer;
	
	// Play the smithy card
	cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);
	
	// It should still be the current player's turn
	printf("current player = %d, expected = %d\n", thisPlayer, prevPlayer);
	if (thisPlayer != prevPlayer)
		printf("********** ERROR: current player mismatch**********\n");
	
	// The total number of cards added to the player's hand should be 2
	printf("current player's handCount = %d, expected = %d\n", testG.handCount[thisPlayer], prevHandCount[thisPlayer] + 2);
	if (testG.handCount[thisPlayer] != prevHandCount[thisPlayer] + 2)
		printf("********** ERROR: current player's hand mismatch**********\n");
	
	// The total number of cards in the discard pile should be the same
	printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], prevDiscardCount[thisPlayer]);
	if (testG.discardCount[thisPlayer] != prevDiscardCount[thisPlayer])
		printf("********** ERROR: current player's discard pile mismatch**********\n");
	
	// The total number of played cards should be 1
	printf("played cards = %d, expected = %d\n", testG.playedCardCount, 1);
	if (testG.playedCardCount != 1)
		printf("********** ERROR: played card pile mismatch**********\n");
	
	// The 3 cards should come from player's own deck
	printf("current player's deckCount = %d, expected = %d\n", testG.deckCount[thisPlayer], prevDeckCount[thisPlayer] - 3);
	if (testG.deckCount[thisPlayer] != prevDeckCount[thisPlayer] - 3)
		printf("********** ERROR: current player's deck pile mismatch**********\n");
	
	// The total number of cards added to the other player's hands and deck should be 0
	for (i = 0; i< numPlayers; i++){
		if (i != thisPlayer) {
			printf("player %d's handCount = %d, expected = %d\n", i, testG.handCount[i], prevHandCount[i]);
			if (testG.handCount[i] != prevHandCount[i])
				printf("********** ERROR: player %d's handCount mismatch**********\n", i);
			printf("player %d's discardCount = %d, expected = %d\n", i, testG.discardCount[i], prevDiscardCount[i]);
			if (testG.discardCount[i] != prevDiscardCount[i])
				printf("********** ERROR: player %d's discardCount mismatch**********\n", i);
			printf("player %d's deckCount = %d, expected = %d\n", i, testG.deckCount[i], prevDeckCount[i]);
			if (testG.deckCount[i] != prevDeckCount[i])
				printf("********** ERROR: player %d's deckCount mismatch**********\n", i);
		}
	}
	
	// The first card should no longer be smithy (it should be the last card - one of the drawn cards)
	printf("first card = %d, expected = %d\n", testG.hand[thisPlayer][0], copper);
	if (testG.hand[thisPlayer][0] != copper)
		printf("********** ERROR: mismatch**********\n");
	
	// Theoretically, there should still be 12 province, estate, and duchy cards originally
	printf("province cards = %d\n", testG.supplyCount[province]);
	assert(testG.supplyCount[province] == 12);
	printf("estate cards = %d\n", testG.supplyCount[estate]);
	assert(testG.supplyCount[estate] == 12);
	printf("duchy cards = %d\n", testG.supplyCount[duchy]);
	assert(testG.supplyCount[duchy] == 12);
	
	// Theoretically, there should be 10 each of all the kindom cards
	for (i = 0; i < 10; i++) {
		printf("kingdom card (%d) = %d\n", k[i], testG.supplyCount[k[i]]);
	}
	
	// Theoretically, there should be 39 coppers, 40 silvers, and 30 gold
	printf("copper cards = %d\n", testG.supplyCount[copper]);
	assert(testG.supplyCount[copper] == 39);
	printf("silver cards = %d\n", testG.supplyCount[silver]);
	assert(testG.supplyCount[silver] == 40);
	printf("gold cards = %d\n", testG.supplyCount[gold]);
	assert(testG.supplyCount[gold] == 30);
	
	// Therefore, the game should not be over
	printf("game over = %d, expected = %d\n", isGameOver(&testG), 0);
	assert(isGameOver(&testG) == 0);
	
	/****************************************************
	Test 3: First player's only card left is smithy
	****************************************************/
	printf("\n\nTEST 3: First player's only card left is smithy \n");
	
	// Create a copy of the original hand
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Eliminate four cards from the player's hand
	for (i = 1; i<testG.handCount[thisPlayer]; i++) {
		testG.hand[thisPlayer][i] = -1;
	}
	testG.handCount[thisPlayer] = 1;
	
	// Keep track of hand count and discard count for all players
	for (i = 0; i < numPlayers; i++){
		prevHandCount[i] = testG.handCount[i];
		prevDiscardCount[i] = testG.discardCount[i];
		prevDeckCount[i] = testG.deckCount[i];
	}
	prevPlayer = thisPlayer;
	
	// Play the smithy card
	cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);
	
	// It should still be the current player's turn
	printf("current player = %d, expected = %d\n", thisPlayer, prevPlayer);
	if (thisPlayer != prevPlayer)
		printf("********** ERROR: current player mismatch**********\n");
	
	// The total number of cards added to the player's hand should be 2
	printf("current player's handCount = %d, expected = %d\n", testG.handCount[thisPlayer], prevHandCount[thisPlayer] + 2);
	if (testG.handCount[thisPlayer] != prevHandCount[thisPlayer] + 2)
		printf("********** ERROR: current player's hand mismatch**********\n");
	
	// The total number of cards in the discard pile should be the same
	printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], prevDiscardCount[thisPlayer]);
	if (testG.discardCount[thisPlayer] != prevDiscardCount[thisPlayer])
		printf("********** ERROR: current player's discard pile mismatch**********\n");
	
	// The total number of played cards should be 1
	printf("played cards = %d, expected = %d\n", testG.playedCardCount, 1);
	if (testG.playedCardCount != 1)
		printf("********** ERROR: played card pile mismatch**********\n");
	
	// The 3 cards should come from player's own deck
	printf("current player's deckCount = %d, expected = %d\n", testG.deckCount[thisPlayer], prevDeckCount[thisPlayer] - 3);
	if (testG.deckCount[thisPlayer] != prevDeckCount[thisPlayer] - 3)
		printf("********** ERROR: current player's deck pile mismatch**********\n");
	
	// The total number of cards added to the other player's hands and deck should be 0
	for (i = 0; i< numPlayers; i++){
		if (i != thisPlayer) {
			printf("player %d's handCount = %d, expected = %d\n", i, testG.handCount[i], prevHandCount[i]);
			if (testG.handCount[i] != prevHandCount[i])
				printf("********** ERROR: player %d's handCount mismatch**********\n", i);
			printf("player %d's discardCount = %d, expected = %d\n", i, testG.discardCount[i], prevDiscardCount[i]);
			if (testG.discardCount[i] != prevDiscardCount[i])
				printf("********** ERROR: player %d's discardCount mismatch********\n", i);
			printf("player %d's deckCount = %d, expected = %d\n", i, testG.deckCount[i], prevDeckCount[i]);
			if (testG.deckCount[i] != prevDeckCount[i])
				printf("********** ERROR: player %d's deckCount mismatch********\n", i);
		}
	}
	
	// The first card should no longer be smithy (it should be the last card - one of the drawn cards)
	printf("first card = %d, expected = %d\n", testG.hand[thisPlayer][0], copper);
	if (testG.hand[thisPlayer][0] != copper)
		printf("********** ERROR: mismatch********\n");
	
	// Theoretically, there should still be 12 province, estate, and duchy cards originally
	printf("province cards = %d\n", testG.supplyCount[province]);
	assert(testG.supplyCount[province] == 12);
	printf("estate cards = %d\n", testG.supplyCount[estate]);
	assert(testG.supplyCount[estate] == 12);
	printf("duchy cards = %d\n", testG.supplyCount[duchy]);
	assert(testG.supplyCount[duchy] == 12);
	
	// Theoretically, there should be 10 each of all the kindom cards
	for (i = 0; i < 10; i++) {
		printf("kingdom card (%d) = %d\n", k[i], testG.supplyCount[k[i]]);
	}
	
	// Theoretically, there should be 39 coppers, 40 silvers, and 30 gold
	printf("copper cards = %d\n", testG.supplyCount[copper]);
	assert(testG.supplyCount[copper] == 39);
	printf("silver cards = %d\n", testG.supplyCount[silver]);
	assert(testG.supplyCount[silver] == 40);
	printf("gold cards = %d\n", testG.supplyCount[gold]);
	assert(testG.supplyCount[gold] == 30);
	
	// Therefore, the game should not be over
	printf("game over = %d, expected = %d\n", isGameOver(&testG), 0);
	assert(isGameOver(&testG) == 0);

	
	
	/****************************************************
	Test 4: First player has all smithys in hand
	****************************************************/
	printf("\n\nTEST 4: First player has all smithys in hand \n");
	
	// Create a copy of the original hand
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Reset the player to first player
	thisPlayer = 0;
	
	// The five cards in the current player's hand are all smithys
	for (i = 0; i<testG.handCount[thisPlayer]; i++) {
		testG.hand[thisPlayer][i] = smithy;
	}
	
	// The next five cards in the current player's deck are all coppers
	for (i = 0; i<testG.deckCount[thisPlayer]; i++) {
		testG.deck[thisPlayer][i] = copper;
	}
	
	// Keep track of hand count and discard count for all players
	for (i = 0; i < numPlayers; i++){
		prevHandCount[i] = testG.handCount[i];
		prevDiscardCount[i] = testG.discardCount[i];
		prevDeckCount[i] = testG.deckCount[i];
	}
	prevPlayer = thisPlayer;
	
	// Play the smithy card
	cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);
	
	// It should still be the current player's turn
	printf("current player = %d, expected = %d\n", thisPlayer, prevPlayer);
	if (thisPlayer != prevPlayer)
		printf("********** ERROR: current player mismatch********\n");
	
	// The total number of cards added to the player's hand should be 2
	printf("current player's handCount = %d, expected = %d\n", testG.handCount[thisPlayer], prevHandCount[thisPlayer] + 2);
	if (testG.handCount[thisPlayer] != prevHandCount[thisPlayer] + 2)
		printf("********** ERROR: current player's hand mismatch********\n");
	
	// The total number of cards in the discard pile should be the same
	printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], prevDiscardCount[thisPlayer]);
	if (testG.discardCount[thisPlayer] != prevDiscardCount[thisPlayer])
		printf("********** ERROR: current player's discard pile mismatch**********\n");
	
	// The total number of played cards should be 1
	printf("played cards = %d, expected = %d\n", testG.playedCardCount, 1);
	if (testG.playedCardCount != 1)
		printf("********** ERROR: played card pile mismatch**********\n");
	
	// The 3 cards should come from player's own deck
	printf("current player's deckCount = %d, expected = %d\n", testG.deckCount[thisPlayer], prevDeckCount[thisPlayer] - 3);
	if (testG.deckCount[thisPlayer] != prevDeckCount[thisPlayer] - 3)
		printf("********** ERROR: current player's deck pile mismatch**********\n");
	
	// The total number of cards added to the other player's hands and deck should be 0
	for (i = 0; i< numPlayers; i++){
		if (i != thisPlayer) {
			printf("player %d's handCount = %d, expected = %d\n", i, testG.handCount[i], prevHandCount[i]);
			if (testG.handCount[i] != prevHandCount[i])
				printf("********** ERROR: player %d's handCount mismatch********\n", i);
			printf("player %d's discardCount = %d, expected = %d\n", i, testG.discardCount[i], prevDiscardCount[i]);
			if (testG.discardCount[i] != prevDiscardCount[i])
				printf("********** ERROR: player %d's discardCount mismatch********\n", i);
			printf("player %d's deckCount = %d, expected = %d\n", i, testG.deckCount[i], prevDeckCount[i]);
			if (testG.deckCount[i] != prevDeckCount[i])
				printf("********** ERROR: player %d's deckCount mismatch********\n", i);
		}
	}
	
	// The first card should no longer be smithy (it should be the last card - one of the drawn cards)
	printf("first card = %d, expected = %d\n", testG.hand[thisPlayer][0], smithy);
	if (testG.hand[thisPlayer][0] != smithy)
		printf("********** ERROR: mismatch********\n");
	
	// Theoretically, there should still be 12 province, estate, and duchy cards originally
	printf("province cards = %d\n", testG.supplyCount[province]);
	assert(testG.supplyCount[province] == 12);
	printf("estate cards = %d\n", testG.supplyCount[estate]);
	assert(testG.supplyCount[estate] == 12);
	printf("duchy cards = %d\n", testG.supplyCount[duchy]);
	assert(testG.supplyCount[duchy] == 12);
	
	// Theoretically, there should be 10 each of all the kindom cards
	for (i = 0; i < 10; i++) {
		printf("kingdom card (%d) = %d\n", k[i], testG.supplyCount[k[i]]);
	}
	
	// Theoretically, there should be 39 coppers, 40 silvers, and 30 gold
	printf("copper cards = %d\n", testG.supplyCount[copper]);
	assert(testG.supplyCount[copper] == 39);
	printf("silver cards = %d\n", testG.supplyCount[silver]);
	assert(testG.supplyCount[silver] == 40);
	printf("gold cards = %d\n", testG.supplyCount[gold]);
	assert(testG.supplyCount[gold] == 30);
	
	// Therefore, the game should not be over
	printf("game over = %d, expected = %d\n", isGameOver(&testG), 0);
	assert(isGameOver(&testG) == 0);
	
	/****************************************************
	Test 5: First player draws all smithys from deck
	****************************************************/
	printf("\n\nTEST 5: First player draws all smithys from deck \n");
	
	// Create a copy of the original hand
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Reset the player to first player
	thisPlayer = 0;
	
	// The next five cards in the current player's deck are all smithys
	for (i = 0; i<testG.deckCount[thisPlayer]; i++) {
		testG.deck[thisPlayer][i] = smithy;
	}
	
	// Keep track of hand count and discard count for all players
	for (i = 0; i < numPlayers; i++){
		prevHandCount[i] = testG.handCount[i];
		prevDiscardCount[i] = testG.discardCount[i];
		prevDeckCount[i] = testG.deckCount[i];
	}
	prevPlayer = thisPlayer;
	
	// Play the smithy card
	cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);
	
	// It should still be the current player's turn
	printf("current player = %d, expected = %d\n", thisPlayer, prevPlayer);
	if (thisPlayer != prevPlayer)
		printf("********** ERROR: current player mismatch********\n");
	
	// The total number of cards added to the player's hand should be 2
	printf("current player's handCount = %d, expected = %d\n", testG.handCount[thisPlayer], prevHandCount[thisPlayer] + 2);
	if (testG.handCount[thisPlayer] != prevHandCount[thisPlayer] + 2)
		printf("********** ERROR: current player's hand mismatch********\n");
	
	// The total number of cards in the discard pile should be the same
	printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], prevDiscardCount[thisPlayer]);
	if (testG.discardCount[thisPlayer] != prevDiscardCount[thisPlayer])
		printf("********** ERROR: current player's discard pile mismatch**********\n");
	
	// The total number of played cards should be 1
	printf("played cards = %d, expected = %d\n", testG.playedCardCount, 1);
	if (testG.playedCardCount != 1)
		printf("********** ERROR: played card pile mismatch**********\n");
	
	// The 3 cards should come from player's own deck
	printf("current player's deckCount = %d, expected = %d\n", testG.deckCount[thisPlayer], prevDeckCount[thisPlayer] - 3);
	if (testG.deckCount[thisPlayer] != prevDeckCount[thisPlayer] - 3)
		printf("********** ERROR: current player's deck pile mismatch**********\n");
	
	// The total number of cards added to the other player's hands and deck should be 0
	for (i = 0; i< numPlayers; i++){
		if (i != thisPlayer) {
			printf("player %d's handCount = %d, expected = %d\n", i, testG.handCount[i], prevHandCount[i]);
			if (testG.handCount[i] != prevHandCount[i])
				printf("********** ERROR: player %d's handCount mismatch********\n", i);
			printf("player %d's discardCount = %d, expected = %d\n", i, testG.discardCount[i], prevDiscardCount[i]);
			if (testG.discardCount[i] != prevDiscardCount[i])
				printf("********** ERROR: player %d's discardCount mismatch********\n", i);
			printf("player %d's deckCount = %d, expected = %d\n", i, testG.deckCount[i], prevDeckCount[i]);
			if (testG.deckCount[i] != prevDeckCount[i])
				printf("********** ERROR: player %d's deckCount mismatch********\n", i);
		}
	}
	
	// The first card should no longer be smithy (it should be the last card - one of the drawn cards)
	printf("first card = %d, expected = %d\n", testG.hand[thisPlayer][0], smithy);
	if (testG.hand[thisPlayer][0] != smithy)
		printf("********** ERROR: mismatch********\n");
	
	// Theoretically, there should still be 12 province, estate, and duchy cards originally
	printf("province cards = %d\n", testG.supplyCount[province]);
	assert(testG.supplyCount[province] == 12);
	printf("estate cards = %d\n", testG.supplyCount[estate]);
	assert(testG.supplyCount[estate] == 12);
	printf("duchy cards = %d\n", testG.supplyCount[duchy]);
	assert(testG.supplyCount[duchy] == 12);
	
	// Theoretically, there should be 10 each of all the kindom cards
	for (i = 0; i < 10; i++) {
		printf("kingdom card (%d) = %d\n", k[i], testG.supplyCount[k[i]]);
	}
	
	// Theoretically, there should be 39 coppers, 40 silvers, and 30 gold
	printf("copper cards = %d\n", testG.supplyCount[copper]);
	assert(testG.supplyCount[copper] == 39);
	printf("silver cards = %d\n", testG.supplyCount[silver]);
	assert(testG.supplyCount[silver] == 40);
	printf("gold cards = %d\n", testG.supplyCount[gold]);
	assert(testG.supplyCount[gold] == 30);
	
	// Therefore, the game should not be over
	printf("game over = %d, expected = %d\n", isGameOver(&testG), 0);
	assert(isGameOver(&testG) == 0);
	
	
	
	
	printf("\n >>>>> SUCCESS: Testing complete of %s <<<<<\n\n\n", UNITTEST);


	return 0;
}


