/*
 * cardtest4.c
 * tests card adventurer
 
 */



#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>


void timer_handler (int signum)
{
    printf("********** ERROR: Adventurer timed out (infinite loop) **********\n");
	printf("\n >>>>> SUCCESS: Testing complete of Adventurer <<<<<\n\n\n");

	exit(0);
}



int testAdventurer() {
    char* UNITTEST = "Adventurer";
	int i;
	int provinceCount = 12;
	int kingdomCount = 10;
	int copperCount = 39;
	int silverCount = 40;
	int goldCount = 30;
    int seed = 1000;
    int numPlayers = 3;
	int numTreasure = 0;
	int deckTreasure = 1;
	int numRevealed = 0;
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
	G.hand[thisPlayer][0] = adventurer;
	G.hand[thisPlayer][1] = estate;
	G.hand[thisPlayer][2] = remodel;
	G.hand[thisPlayer][3] = estate;
	G.hand[thisPlayer][4] = village;
	
	printf("\n\n----------------- Testing of Card: %s ----------------\n", UNITTEST);

	
	/****************************************************
	Test 1: All the cards in the player's deck are copper cards
	****************************************************/
	printf("\nTEST 1: All the cards in the deck are copper cards \n");
	
	// Create a copy of the original hand
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// The next five cards in the current player's deck are all coppers
	for (i = 0; i<testG.deckCount[thisPlayer]; i++) {
		testG.deck[thisPlayer][i] = copper;
	}
	numTreasure = 2;
	numRevealed = 0;
	
	// Keep track of hand count and discard count for all players
	for (i = 0; i < numPlayers; i++){
		prevHandCount[i] = testG.handCount[i];
		prevDiscardCount[i] = testG.discardCount[i];
		prevDeckCount[i] = testG.deckCount[i];
	}
	prevPlayer = thisPlayer;
	
	// Play the adventurer card
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);
	
	// It should still be the current player's turn
	printf("current player = %d, expected = %d\n", thisPlayer, prevPlayer);
	if (thisPlayer != prevPlayer)
		printf("********** ERROR: current player mismatch**********\n");

	// The total number of cards added to the player's hand should be treasure added - adventurer card
	printf("current player's handCount = %d, expected = %d\n", testG.handCount[thisPlayer], prevHandCount[thisPlayer] + numTreasure - 1);
	if (testG.handCount[thisPlayer] != prevHandCount[thisPlayer] + numTreasure - 1)
		printf("********** ERROR: current player's hand mismatch**********\n");
	
	// If there is treasure in the deck, the discard pile should just contain any revealed cards
	if (deckTreasure) {
		printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], prevDiscardCount[thisPlayer] + numRevealed);
		if (testG.discardCount[thisPlayer] != prevDiscardCount[thisPlayer] + numRevealed)
			printf("********** ERROR: current player's discard pile mismatch**********\n");
	}
	
	// If not, then the discard pile should only be the number of revealed cards (b/c it's been shuffled into the deck)
	else {
		printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], numRevealed);
		if (testG.discardCount[thisPlayer] != numRevealed)
			printf("********** ERROR: current player's discard pile mismatch**********\n");
	}
		
	// The total number of played cards should be 1
	printf("played cards = %d, expected = %d\n", testG.playedCardCount, 1);
	if (testG.playedCardCount != 1)
		printf("********** ERROR: played card pile mismatch**********\n");
	
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
	
	// The first card should no longer be adventurer (it should be the last card - one of the drawn cards)
	printf("first card = %d, expected != %d\n", testG.hand[thisPlayer][0], adventurer);
	if (testG.hand[thisPlayer][0] == adventurer)
		printf("********** ERROR: first card mismatch**********\n");
	
	
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
	Test 2: All the cards in the player's deck are silver cards
	****************************************************/
	printf("\nTEST 2: All the cards in the deck are silver cards \n");
	
	// Create a copy of the original hand
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// The next five cards in the current player's deck are all silvers
	for (i = 0; i<testG.deckCount[thisPlayer]; i++) {
		testG.deck[thisPlayer][i] = silver;
	}
	numTreasure = 2;
	numRevealed = 0;
	
	// Keep track of hand count and discard count for all players
	for (i = 0; i < numPlayers; i++){
		prevHandCount[i] = testG.handCount[i];
		prevDiscardCount[i] = testG.discardCount[i];
		prevDeckCount[i] = testG.deckCount[i];
	}
	prevPlayer = thisPlayer;
	
	// Play the adventurer card
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);
	
	// It should still be the current player's turn
	printf("current player = %d, expected = %d\n", thisPlayer, prevPlayer);
	if (thisPlayer != prevPlayer)
		printf("********** ERROR: current player mismatch**********\n");

	// The total number of cards added to the player's hand should be treasure added - adventurer card
	printf("current player's handCount = %d, expected = %d\n", testG.handCount[thisPlayer], prevHandCount[thisPlayer] + numTreasure - 1);
	if (testG.handCount[thisPlayer] != prevHandCount[thisPlayer] + numTreasure - 1)
		printf("********** ERROR: current player's hand mismatch**********\n");
	
	// If there is treasure in the deck, the discard pile should just contain any revealed cards
	if (deckTreasure) {
		printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], prevDiscardCount[thisPlayer] + numRevealed);
		if (testG.discardCount[thisPlayer] != prevDiscardCount[thisPlayer] + numRevealed)
			printf("********** ERROR: current player's discard pile mismatch**********\n");
	}
	
	// If not, then the discard pile should only be the number of revealed cards (b/c it's been shuffled into the deck)
	else {
		printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], numRevealed);
		if (testG.discardCount[thisPlayer] != numRevealed)
			printf("********** ERROR: current player's discard pile mismatch**********\n");
	}
		
	// The total number of played cards should be 1
	printf("played cards = %d, expected = %d\n", testG.playedCardCount, 1);
	if (testG.playedCardCount != 1)
		printf("********** ERROR: played card pile mismatch**********\n");
	
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
	
	// The first card should no longer be adventurer (it should be the last card - one of the drawn cards)
	printf("first card = %d, expected != %d\n", testG.hand[thisPlayer][0], adventurer);
	if (testG.hand[thisPlayer][0] == adventurer)
		printf("********** ERROR: first card mismatch**********\n");
	
	
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
	Test 3: The first 2 cards in the deck are treasure cards
	****************************************************/
	printf("\nTEST 3: The first 2 cards in the deck are treasure cards \n");
	
	// Create a copy of the original hand
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// The next five cards in the current player's deck are all silvers
	for (i = 0; i<testG.deckCount[thisPlayer]; i++) {
		if (i < 2) testG.deck[thisPlayer][i] = village;
		else testG.deck[thisPlayer][i] = silver;
	}
	numTreasure = 2;
	numRevealed = 3;
	
	// Keep track of hand count and discard count for all players
	for (i = 0; i < numPlayers; i++){
		prevHandCount[i] = testG.handCount[i];
		prevDiscardCount[i] = testG.discardCount[i];
		prevDeckCount[i] = testG.deckCount[i];
	}
	prevPlayer = thisPlayer;
	
	// Play the adventurer card
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);
	
	// It should still be the current player's turn
	printf("current player = %d, expected = %d\n", thisPlayer, prevPlayer);
	if (thisPlayer != prevPlayer)
		printf("********** ERROR: current player mismatch**********\n");

	// The total number of cards added to the player's hand should be treasure added - adventurer card
	printf("current player's handCount = %d, expected = %d\n", testG.handCount[thisPlayer], prevHandCount[thisPlayer] + numTreasure - 1);
	if (testG.handCount[thisPlayer] != prevHandCount[thisPlayer] + numTreasure - 1)
		printf("********** ERROR: current player's hand mismatch**********\n");
	
	// If there is treasure in the deck, the discard pile should just contain any revealed cards
	if (deckTreasure) {
		printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], prevDiscardCount[thisPlayer] + numRevealed);
		if (testG.discardCount[thisPlayer] != prevDiscardCount[thisPlayer] + numRevealed)
			printf("********** ERROR: current player's discard pile mismatch**********\n");
	}
	
	// If not, then the discard pile should only be the number of revealed cards (b/c it's been shuffled into the deck)
	else {
		printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], numRevealed);
		if (testG.discardCount[thisPlayer] != numRevealed)
			printf("********** ERROR: current player's discard pile mismatch**********\n");
	}
		
	// The total number of played cards should be 1
	printf("played cards = %d, expected = %d\n", testG.playedCardCount, 1);
	if (testG.playedCardCount != 1)
		printf("********** ERROR: played card pile mismatch**********\n");
	
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
	
	// The first card should no longer be adventurer (it should be the last card - one of the drawn cards)
	printf("first card = %d, expected != %d\n", testG.hand[thisPlayer][0], adventurer);
	if (testG.hand[thisPlayer][0] == adventurer)
		printf("********** ERROR: first card mismatch**********\n");
	
	
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
	Test 4: Player 1's deck has no treasure cards - the discard pile has 2
	****************************************************/
	printf("\nTEST 4: Player 1's deck has no treasure cards - the discard pile has 2 \n");
	
	// Create a copy of the original hand
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// The next five cards in the current player's deck are all village
	for (i = 0; i<testG.deckCount[thisPlayer]; i++) {
		testG.deck[thisPlayer][i] = village;
	}
	
	// The discard pile has 2 coppers
	testG.discardCount[thisPlayer] = 2;
	for (i = 0; i<testG.discardCount[thisPlayer]; i++) {
		testG.discard[thisPlayer][i] = copper;
	}
	
	// Reset so that will need to continue testing
	deckTreasure = 0;
	numTreasure = 2;
	numRevealed = 5;
	
	// Keep track of hand count and discard count for all players
	for (i = 0; i < numPlayers; i++){
		prevHandCount[i] = testG.handCount[i];
		prevDiscardCount[i] = testG.discardCount[i];
		prevDeckCount[i] = testG.deckCount[i];
	}
	prevPlayer = thisPlayer;
	
	// Play the adventurer card
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);
	
	// It should still be the current player's turn
	printf("current player = %d, expected = %d\n", thisPlayer, prevPlayer);
	if (thisPlayer != prevPlayer)
		printf("********** ERROR: current player mismatch**********\n");

	// The total number of cards added to the player's hand should be treasure added - adventurer card
	printf("current player's handCount = %d, expected = %d\n", testG.handCount[thisPlayer], prevHandCount[thisPlayer] + numTreasure - 1);
	if (testG.handCount[thisPlayer] != prevHandCount[thisPlayer] + numTreasure - 1)
		printf("********** ERROR: current player's hand mismatch**********\n");
	
	// If there is treasure in the deck, the discard pile should also contain any revealed cards
	if (deckTreasure) {
		printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], prevDiscardCount[thisPlayer] + numRevealed);
		if (testG.discardCount[thisPlayer] != prevDiscardCount[thisPlayer] + numRevealed)
			printf("********** ERROR: current player's discard pile mismatch**********\n");
	}
	
	// If not, then the discard pile should only be the number of revealed cards (b/c it's been shuffled into the deck)
	else {
		printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], numRevealed);
		if (testG.discardCount[thisPlayer] != numRevealed)
			printf("********** ERROR: current player's discard pile mismatch**********\n");
	}
		
	// The total number of played cards should be 1
	printf("played cards = %d, expected = %d\n", testG.playedCardCount, 1);
	if (testG.playedCardCount != 1)
		printf("********** ERROR: played card pile mismatch**********\n");
	
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
	
	// The first card should no longer be adventurer (it should be the last card - one of the drawn cards)
	printf("first card = %d, expected != %d\n", testG.hand[thisPlayer][0], adventurer);
	if (testG.hand[thisPlayer][0] == adventurer)
		printf("********** ERROR: first card mismatch**********\n");
	
	
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
	Test 5: Player 2's deck has no treasure cards - the discard pile has 2
	****************************************************/
	printf("\nTEST 5: Player 1's deck has no treasure cards - the discard pile has 2 \n");
	
	// Create a copy of the original hand
	memcpy(&testG, &G, sizeof(struct gameState));
	endTurn(&testG);
	thisPlayer = (thisPlayer + 1)% numPlayers;
	
	
	// The next five cards in the current player's deck are all village
	for (i = 0; i<testG.deckCount[thisPlayer]; i++) {
		testG.deck[thisPlayer][i] = village;
	}
	
	// The discard pile has 2 coppers
	testG.discardCount[thisPlayer] = 2;
	for (i = 0; i<testG.discardCount[thisPlayer]; i++) {
		testG.discard[thisPlayer][i] = copper;
	}
	
	// Reset so that will need to continue drawing
	deckTreasure = 0;
	numTreasure = 2;
	numRevealed = 5;
	
	// Keep track of hand count and discard count for all players
	for (i = 0; i < numPlayers; i++){
		prevHandCount[i] = testG.handCount[i];
		prevDiscardCount[i] = testG.discardCount[i];
		prevDeckCount[i] = testG.deckCount[i];
	}
	prevPlayer = thisPlayer;
	
	// Play the adventurer card
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);
	
	// It should still be the current player's turn
	printf("current player = %d, expected = %d\n", thisPlayer, prevPlayer);
	if (thisPlayer != prevPlayer)
		printf("********** ERROR: current player mismatch**********\n");

	// The total number of cards added to the player's hand should be treasure added - adventurer card
	printf("current player's handCount = %d, expected = %d\n", testG.handCount[thisPlayer], prevHandCount[thisPlayer] + numTreasure - 1);
	if (testG.handCount[thisPlayer] != prevHandCount[thisPlayer] + numTreasure - 1)
		printf("********** ERROR: current player's hand mismatch**********\n");
	
	// If there is treasure in the deck, the discard pile should also contain any revealed cards
	if (deckTreasure) {
		printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], prevDiscardCount[thisPlayer] + numRevealed);
		if (testG.discardCount[thisPlayer] != prevDiscardCount[thisPlayer] + numRevealed)
			printf("********** ERROR: current player's discard pile mismatch**********\n");
	}
	
	// If not, then the discard pile should only be the number of revealed cards (b/c it's been shuffled into the deck)
	else {
		printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], numRevealed);
		if (testG.discardCount[thisPlayer] != numRevealed)
			printf("********** ERROR: current player's discard pile mismatch**********\n");
	}
		
	// The total number of played cards should be 1
	printf("played cards = %d, expected = %d\n", testG.playedCardCount, 1);
	if (testG.playedCardCount != 1)
		printf("********** ERROR: played card pile mismatch**********\n");
	
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
	
	// The first card should no longer be adventurer (it should be the last card - one of the drawn cards)
	printf("first card = %d, expected != %d\n", testG.hand[thisPlayer][0], adventurer);
	if (testG.hand[thisPlayer][0] == adventurer)
		printf("********** ERROR: first card mismatch**********\n");
	
	
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
	Test 6: Neither the deck nor the discard pile has any treasure cards
	****************************************************/
	printf("\nTEST 6: Neither the deck nor the discard pile has any treasure cards \n");
	
	// Create a copy of the original hand
	memcpy(&testG, &G, sizeof(struct gameState));
	thisPlayer = 0;
	
	// The next five cards in the current player's deck are all village
	for (i = 0; i<testG.deckCount[thisPlayer]; i++) {
		testG.deck[thisPlayer][i] = village;
	}
	
	// There are no cards in the discard pile
	testG.discardCount[thisPlayer] = 0;
	
	// Reset so that will need to continue testing
	deckTreasure = 0;
	numTreasure = 0;
	numRevealed = 5;
	
	// Keep track of hand count and discard count for all players
	for (i = 0; i < numPlayers; i++){
		prevHandCount[i] = testG.handCount[i];
		prevDiscardCount[i] = testG.discardCount[i];
		prevDeckCount[i] = testG.deckCount[i];
	}
	prevPlayer = thisPlayer;
	
	// Play the adventurer card (with timeout)
	signal (SIGALRM, timer_handler);
	alarm(1);
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);
	alarm(0);
	
	// It should still be the current player's turn
	printf("current player = %d, expected = %d\n", thisPlayer, prevPlayer);
	if (thisPlayer != prevPlayer)
		printf("********** ERROR: current player mismatch**********\n");

	// The total number of cards added to the player's hand should be treasure added - adventurer card
	printf("current player's handCount = %d, expected = %d\n", testG.handCount[thisPlayer], prevHandCount[thisPlayer] + numTreasure - 1);
	if (testG.handCount[thisPlayer] != prevHandCount[thisPlayer] + numTreasure - 1)
		printf("********** ERROR: current player's hand mismatch**********\n");
	
	// If there is treasure in the deck, the discard pile should also contain any revealed cards
	if (deckTreasure) {
		printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], prevDiscardCount[thisPlayer] + numRevealed);
		if (testG.discardCount[thisPlayer] != prevDiscardCount[thisPlayer] + numRevealed)
			printf("********** ERROR: current player's discard pile mismatch**********\n");
	}
	
	// If not, then the discard pile should only be the number of revealed cards (b/c it's been shuffled into the deck)
	else {
		printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], numRevealed);
		if (testG.discardCount[thisPlayer] != numRevealed)
			printf("********** ERROR: current player's discard pile mismatch**********\n");
	}
		
	// The total number of played cards should be 1
	printf("played cards = %d, expected = %d\n", testG.playedCardCount, 1);
	if (testG.playedCardCount != 1)
		printf("********** ERROR: played card pile mismatch**********\n");
	
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
	
	// The first card should no longer be adventurer (it should be the last card - one of the drawn cards)
	printf("first card = %d, expected != %d\n", testG.hand[thisPlayer][0], adventurer);
	if (testG.hand[thisPlayer][0] == adventurer)
		printf("********** ERROR: first card mismatch**********\n");
	
	
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


