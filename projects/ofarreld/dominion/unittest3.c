#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

#include "testHelper.h"

#define TESTCARD "scoreFor()"

int main() {
	int discarded = 1;
	int a = 0, b = 0;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	int otherPlayer = 1;
	int newScore = 0;

	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};
	
	initializeGame(numPlayers, k, seed, &G);

	// set up 5 copper in each section:
	while (a < 5) {

		G.hand[thisPlayer][a] = copper;
		G.deck[thisPlayer][a] = copper;
		G.discard[thisPlayer][a] = copper;
		a++;
	}




	memcpy(&testG, &G, sizeof(struct gameState));
	printf("\t Testing Card: %s \n", TESTCARD);

	newScore = 5;
	//int scoreFor (int player, struct gameState *state) {
	// Test with each type: // curse, estate, duchy, province, great_hall, gardens

	// Test 01: Curse to Hand 	---------------------------------------------------
	linePrint();
	printf("Test 01: Curse in hand\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = -1;

	a = 0;
	b = 0;
	while ((a < MAX_HAND) && (b < 1)) {
		if (testG.hand[thisPlayer][a] == NULL) {
			testG.hand[thisPlayer][a] = curse;
			testG.handCount[thisPlayer]++;	
			b++;
		}
		a++;
	}

	printf("Testing Score for Curse in hand...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);

	// Test 02: Curse to Discard	---------------------------------------------------
	linePrint();
	printf("Test 02: Curse in discard\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = -1;

	testG.discard[thisPlayer][0] = curse;
	testG.discardCount[thisPlayer] += 1;	

	printf("Testing Score for curse in discard...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);

	// Test 03: Curse to Deck	---------------------------------------------------
	linePrint();
	printf("Test 03: Curse in deck\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = -1;

	testG.deck[thisPlayer][0] = curse;
	testG.deckCount[thisPlayer] += 1;	

	printf("Testing Score for Curse in deck...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);



	// Test 04: Estate to Hand 	---------------------------------------------------
	linePrint();
	printf("Test 04: estate in hand\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 1;

	a = 0;
	b = 0;
	while ((a < MAX_HAND) && (b < 1)) {
		if (testG.hand[thisPlayer][a] == NULL) {
			testG.hand[thisPlayer][a] = estate;
			testG.handCount[thisPlayer]++;	
			b++;
		}
		a++;
	}

	printf("Testing Score for Estate in hand...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);

	// Test 05: Estate to Discard	---------------------------------------------------
	linePrint();
	printf("Test 05: estate in discard\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 1;

	testG.discard[thisPlayer][0] = estate;
	testG.discardCount[thisPlayer] += 1;	

	printf("Testing Score for estate in discard...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);

	// Test 06: Estate to Deck	---------------------------------------------------
	linePrint();
	printf("Test 06: Estate in deck\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 1;

	testG.deck[thisPlayer][0] = estate;
	testG.deckCount[thisPlayer] += 1;	


	printf("Testing Score for estate in deck...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);

	// Test 07: Duchy to Hand 	---------------------------------------------------
	linePrint();
	printf("Test 07: duchy in hand\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 3;

	a = 0;
	b = 0;
	while ((a < MAX_HAND) && (b < 1)) {
		if (testG.hand[thisPlayer][a] == NULL) {
			testG.hand[thisPlayer][a] = duchy;
			testG.handCount[thisPlayer]++;	
			b++;
		}
		a++;
	}

	printf("Testing Score for duchy in hand...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);
	
	// Test 08: Duchy to Discard	---------------------------------------------------
	linePrint();
	printf("Test 08: Duchy in discard\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 3;

	testG.discard[thisPlayer][0] = duchy;
	testG.discardCount[thisPlayer] += 1;	

	printf("Testing Score for duchy in discard...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);

	// Test 09: Duchy to Deck	---------------------------------------------------
	linePrint();
	printf("Test 09: Duchy in deck\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 3;
	testG.deck[thisPlayer][0] = duchy;
	testG.deckCount[thisPlayer] += 1;	

	printf("Testing Score for duchy in deck...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);



	// Test 10: Province to Hand 	---------------------------------------------------
	linePrint();
	printf("Test 10: Province in hand\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 6;
	testG.hand[thisPlayer][0] = province;

	printf("Testing Score for province in hand...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);

	// Test 11: Province to Discard	---------------------------------------------------
	linePrint();
	printf("Test 11: province in discard\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 6;
	testG.discard[thisPlayer][0] = province;
	testG.discardCount[thisPlayer] += 1;	

	printf("Testing Score for province in discard...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);

	// Test 12: province to Deck	---------------------------------------------------
	linePrint();
	printf("Test 12: province in deck\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 6;
	testG.deck[thisPlayer][0] = province;
	testG.deckCount[thisPlayer] += 1;	

	printf("Testing Score for province in deck...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);



	// Test 13: Great_Hall to Hand 	---------------------------------------------------
	linePrint();
	printf("Test 12: great_hall in hand\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 1;
	testG.hand[thisPlayer][0] = great_hall;

	printf("Testing Score for great_hall in hand...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);

	// Test 14: greaT_hall to Discard	---------------------------------------------------
	linePrint();
	printf("Test 14: great_hall in discard\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 1;
	testG.discard[thisPlayer][0] = great_hall;
	testG.discardCount[thisPlayer] += 1;	

	printf("Testing Score for great_hall in discard...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);

	// Test 15: great_hall to Deck	---------------------------------------------------
	linePrint();
	printf("Test 15: great_hall in deck\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 1;
	testG.deck[thisPlayer][0] = great_hall;
	testG.deckCount[thisPlayer] += 1;	

	printf("Testing Score for great_hall in deck...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);




	// Test 16: gardens to Hand 	---------------------------------------------------
	linePrint();
	printf("Test 16: gardens in hand\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 5;

	a = 0;
	b = 0;
	while ((a < MAX_HAND) && (b < 4)) {
		if (testG.hand[thisPlayer][a] == NULL) {
			testG.hand[thisPlayer][a] = estate;
			b++;
		}
		a++;
	}
	testG.hand[thisPlayer][a] = gardens;
	testG.handCount[thisPlayer] += 5;

	printf("Testing Score for gardens in hand...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);

	// Test 17: gardens to Discard	---------------------------------------------------
	linePrint();
	printf("Test 17: gardens in discard\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 5;

	a = 0;
	b = 0;
	while ((a < MAX_HAND) && (b < 4)) {
		if (testG.discard[thisPlayer][a] == NULL) {
			testG.discard[thisPlayer][a] = estate;
			b++;
		}
		a++;
	}
	testG.discard[thisPlayer][a] = gardens;
	testG.discardCount[thisPlayer] += 5;


	printf("Fulldeck = %d\n", fullDeckCount(thisPlayer, 0, &testG));

	printf("Testing Score for gardens in discard...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);

	// Test 18: gardens to Deck	---------------------------------------------------
	linePrint();
	printf("Test 18: gardens in deck\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newScore = 5;

	a = 0;
	b = 0;
	while ((a < MAX_HAND) && (b < 4)) {
		if (testG.deck[thisPlayer][a] == NULL) {
			testG.deck[thisPlayer][a] = estate;
			b++;
		}
		a++;
	}
	testG.deck[thisPlayer][a] = gardens;
	testG.deckCount[thisPlayer] += 5;

	printf("Testing Score for gardens in deck...\t");
	if (scoreFor(thisPlayer, &testG) != (scoreFor(thisPlayer, &G)+ newScore)) {
		printf("ERROR\n");
		printf("Player score: %d, expected: %d\n",scoreFor(thisPlayer, &testG), 
			scoreFor(thisPlayer, &G) + newScore);
	} else {
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}




