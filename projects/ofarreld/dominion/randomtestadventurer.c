/*
 *	Name:					Daniel Ofarrell
 *	Date Created:				3 May 2016
 *	Last Modification Date:			3 May 2016
 *	Filename:				randomtestadventurer.c
 *
 *	Objective:
 *		This will test the adventurer card function through a series of
 *		of randomized tests. 
 *
 *		Each test will have the following randomized:
 *		- the player deck
 *		- the player discardCount
 *		- the player handCount
 *		- the number of players
 *		- the number of treasures
 *
 *		Reference for this test has been taken from betterTestDrawCard.c
 *
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#include "testHelperRand.h"

#define TESTCARD "Adventurer"

int main() {

	int iterations = 1000;
	int result = 0;

	int resCount = 0;
	int expCount = 0;

	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	int discard = 1;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0;
	int a, b, c, copperLoc;
	// expectedG, resultG
	struct gameState G, expG, resG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};

/*130 Basic Treasure Cards
 * 60 "Copper" [1]
 * 40 "Silver" [2]
 * 30 "Gold" [3]
 * 48 Basic Victory Cards
 * 24 "Estate"
 * 12 "Duchy"
 * 12 "Province"
 * 30 Curse Cards
 * 252 Kingdom Cards
 * 240 Action Cards [24 x 10]
 * 12 Victory Cards [1 x 12] */

	// initialize game environment & begin testing
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&expG, &G, sizeof(struct gameState));
	printf("\t Testing Card: %s \n", TESTCARD);
	SelectStream(2);
	PutSeed(12);

	// 27 cards = treasure_map+1
	for (a = 0; a < iterations; a++) {
	printf("building test %d\n", a);
		memcpy(&expG, &G, sizeof(struct gameState));

		// initialize hand, deck, and discard size
		expG.handCount[thisPlayer] = floor(Random() * MAX_HAND);
		expG.deckCount[thisPlayer] = floor(Random() * MAX_DECK) + 1;
		expG.discardCount[thisPlayer] = floor(Random() * MAX_DECK);
		for (b = 0; b < (treasure_map); b++) {
			expG.supplyCount[b] = floor(Random() * 10);
			expG.embargoTokens[b] = floor(Random() * 10);
		}

		expG.numActions = floor(Random() * MAX_HAND) + 1;
		expG.coins += floor(Random() * 60) * 1;
		expG.coins += floor(Random() * 40) * 2;
		expG.coins += floor(Random() * 30) * 3;
		expG.numBuys = floor(Random() * MAX_HAND);

		// randomize the contents of the players hand, deck, discard
		for (b = 0; b < expG.handCount[thisPlayer]; b++) {
			expG.hand[thisPlayer][b] = floor(Random() * (treasure_map));
		}		
	
		for (b = 0; b < expG.deckCount[thisPlayer]; b++) {
			expG.deck[thisPlayer][b] = floor(Random() * (treasure_map));
		}
	
		for (b = 0; b < expG.discardCount[thisPlayer]; b++) {
			expG.discard[thisPlayer][b] = floor(Random() * (treasure_map));
		}


		// set the card to position 0
		expG.hand[thisPlayer][0] = adventurer;

		c = 0;
		while (c < 2) {
			copperLoc = floor(Random() * expG.deckCount[thisPlayer]);
			expG.deck[thisPlayer][copperLoc] = copper;
			c++;
		}

		printf("starting test\n");
		memcpy(&resG, &expG, sizeof(struct gameState));
		result = cardEffect(adventurer, choice1, choice2, choice3, &resG, handpos, 0);

		resCount = (resG.deckCount[thisPlayer] + resG.handCount[thisPlayer] + resG.discardCount[thisPlayer]);
		expCount = (expG.deckCount[thisPlayer] + expG.handCount[thisPlayer] + expG.discardCount[thisPlayer] 
			+ discard );

		if (resCount != expCount) {
			printf("Error: Card Counts are incorrect where:\n");
			printf("EXECTED: %d, \tRESULT: %d\n", expCount, resCount);
			printf("Deck EXP %d, \tRES %d\n", expG.deckCount[thisPlayer], resG.deckCount[thisPlayer]);
			printf("Discard EXP %d, \tRES %d\n", expG.handCount[thisPlayer], resG.handCount[thisPlayer]);
			printf("HandDeck EXP %d, \tRES %d\n", expG.discardCount[thisPlayer], resG.discardCount[thisPlayer]);

		}
		if (result < 0) {
			printf("ERROR: %s TEST FAILED\n", TESTCARD);
		}
	}


	printf("\n >>>>>>> %s TESTING STATUS: COMPLETE <<<<<<<\n\n", TESTCARD);  
	return 0;
}

