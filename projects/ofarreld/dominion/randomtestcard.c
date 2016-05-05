/*
 *	Name:						Daniel Ofarrell
 *	Date Created:					5 May 2016
 *	Last Modification Date:				5 May 2016
 *	Filename					randomtestcard.c
 *
 *	Objective:
 *		This will perform a random test on the SALVAGER card
 *
 *		Each test will haveb the following randomized:
 *		- the player deck
 *		- the player discardCount
 *		- the layer handCount
 *		- the number of players
 *		- the number of treasures
 *
 *		Reference for this test has been taken from betterTestDrawCard.c
 *  */ 


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#include "testHelperRand.h"

#define TESTCARD "salvager"

int main() {
	int iterations = 5000;
	int result = 0;

	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	int discard = 2;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0;

	int newBuys = 1;
	int a = 0, b = 0;

	struct gameState G, expG, resG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};

	// initialize game environment & begin testing
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&expG, &G, sizeof(struct gameState));
	printf("\t Testing Card: %s \n", TESTCARD);
	SelectStream(2);
	PutSeed(12);

	// +1 buy
	// + gain coins equal to cost of a card
	// Actions--

	for (a = 0; a < iterations; a++) {
		// initialize random values
		choice1 = 0;
		memcpy(&expG, &G, sizeof(struct gameState));
		do {
			expG.handCount[thisPlayer] = floor(Random() * MAX_HAND);
		} while (expG.handCount[thisPlayer] < 2);
		expG.deckCount[thisPlayer] = floor(Random() * MAX_DECK);
		expG.discardCount[thisPlayer] = floor(Random() * MAX_DECK);
		// randomize count of cards
		for (b = 0; b < (treasure_map); b++) {
			expG.supplyCount[b] = floor(Random() * 10);
			expG.embargoTokens[b] = floor(Random() * 10);
		}

		expG.numActions = floor(Random() * MAX_HAND);
		expG.coins += floor(Random() * 60) * 1;
		expG.coins += floor(Random() * 60) * 2;
		expG.coins += floor(Random() * 30) * 3;
		expG.numBuys = floor(Random() * MAX_HAND);

		// randomize the contents of player's hand, deck, and discard
		for (b = 0; b < expG.handCount[thisPlayer]; b++) {
			expG.hand[thisPlayer][b] = floor(Random() * (treasure_map));
		}
		for (b = 0; b < expG.deckCount[thisPlayer]; b++) {
			expG.deck[thisPlayer][b] = floor(Random() * (treasure_map));
		}
		for (b = 0; b < expG.discardCount[thisPlayer]; b++) {
			expG.discard[thisPlayer][b] = floor(Random() * treasure_map);
		}

		expG.hand[thisPlayer][0] = salvager;
		// pick a card to burn for coins

		while (choice1 <= 0) {
			choice1 = floor(Random() * expG.handCount[thisPlayer]);
		}

		memcpy(&resG, &expG, sizeof(struct gameState));
		result = cardEffect(salvager, choice1, choice2, choice3, &resG, handpos, 0);
	
		// test: discard size, handsize, coins, buys
		if (resG.handCount[thisPlayer] != (expG.handCount[thisPlayer] - discard)) {
			printf("ERROR: Hand Count Expected: %d\t Result: %d\n", 
				(expG.handCount[thisPlayer] - discard), resG.handCount[thisPlayer]);
		}
		if (resG.discardCount[thisPlayer] != (expG.discardCount[thisPlayer])) {
			printf("ERROR: Discard Count Expected: %d\t Result: %d\n",
				(expG.discardCount[thisPlayer]), resG.discardCount[thisPlayer]);
		}
		if (resG.coins != (expG.coins + getCost(handCard(choice1, &expG )))) {
			printf("ERROR: Coins Expected: %d\t Result: %d\n",
				(expG.coins + getCost(handCard(choice1, &expG))), resG.coins);
		}
		if (resG.numBuys != (expG.numBuys + newBuys)) {
			printf("ERROR: Buys Expected: %d\t Result: %d\n",
				(expG.numBuys + newBuys), resG.numBuys);
		}
	}

	printf("\n >>>>>>> %s TESTING STATUS: COMPLETE <<<<<<<\n\n", TESTCARD);  
	return 0;
}

