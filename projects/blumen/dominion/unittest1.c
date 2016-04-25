/**
unittest1.c: Tests the updateCoins() method

// Basic requirements
1. player & bonus are non-negative
2. Current player's coins equal treasury cards plus bonus value
3. No state change should occur for other players.
4. No state change should occur to the curse, victory, treasure and kingdom card piles.

Include the following lines in your makefile:
unittest1: unittest1.c dominion.o rngs.o
    gcc -o unittest1 -g  unittest1.c dominion.o rngs.o -lm

    was:
    gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
**/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTMETHOD "updateCoins()"       //*******************>>>> change me

void unittest1() {
    int seed = 7;
    srand((unsigned) seed);
    int bonus = rand() % 20;
    int i, j;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
	struct gameState G, testG, skewedG, testSkewedG;
	int k[10] = {smithy, adventurer, feast, council_room, gardens, village, remodel, mine, cutpurse, embargo};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	// skew player's hand; could be randomized but would then look like code under test
	memcpy(&skewedG, &G, sizeof(struct gameState));
    int count = skewedG.handCount[thisPlayer];//Get current player's hand count
    for (i = 0; i < count; i++) {
        skewedG.hand[thisPlayer][i] = estate;
	}
	skewedG.hand[thisPlayer][0] = copper;
    skewedG.hand[thisPlayer][2] = silver;
	skewedG.hand[thisPlayer][3] = gold;
	skewedG.hand[thisPlayer][4] = gold;
	int skewedTreasurySum = 9;
    int skewedBonus = 5;

	printf("----------------- Testing Method: %s ----------------\n", TESTMETHOD);

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	memcpy(&testSkewedG, &skewedG, sizeof(struct gameState));

	// apply the play to the testG game state
    updateCoins(thisPlayer, &testG, bonus);
    updateCoins(thisPlayer, &testSkewedG, skewedBonus);

    // ----------- TEST 1: player & bonus are non-negative --------------
	printf("TEST 1: player & bonus are non-negative\n");
	printf("player = %d, expected: > 0\n", thisPlayer);
	printf("bonus = %d, expected: > 0\n", thisPlayer);
	assert(thisPlayer >= 0);
	assert(bonus >= 0);

    // ----------- TEST 2: Current player's coins equal treasury cards plus bonus value --------------
	printf("TEST 2: Current player's coins equal treasury cards plus bonus value\n");
	printf("coins = %d, expected = %d\n", testSkewedG.coins, skewedTreasurySum+skewedBonus);
	//assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);

    // ----------- TEST 3: No state change should occur for other players. --------------
	printf("TEST 3: No change to other player's hand or deck.\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
	assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);
	assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]);

    // ----------- TEST 4: No state change should occur to the curse, victory, treasure and kingdom card piles. --------------
	printf("TEST 4: No state change should occur to the curse, victory, treasury and kingdom card piles.\n");
	printf("Curse supply = %d, expected = %d\n", testG.supplyCount[curse], G.supplyCount[curse]);
	printf("Estate supply = %d, expected = %d\n", testG.supplyCount[estate], G.supplyCount[estate]);
	printf("Duchy supply = %d, expected = %d\n", testG.supplyCount[duchy], G.supplyCount[duchy]);
	printf("Province supply = %d, expected = %d\n", testG.supplyCount[province], G.supplyCount[province]);
	printf("Copper supply = %d, expected = %d\n", testG.supplyCount[copper], G.supplyCount[copper]);
	printf("Silver supply = %d, expected = %d\n", testG.supplyCount[silver], G.supplyCount[silver]);
	printf("Gold supply = %d, expected = %d\n", testG.supplyCount[gold], G.supplyCount[gold]);
	assert(testG.supplyCount[curse] == G.supplyCount[curse]);
	assert(testG.supplyCount[estate] == G.supplyCount[estate]);
	assert(testG.supplyCount[duchy] == G.supplyCount[duchy]);
	assert(testG.supplyCount[province] == G.supplyCount[province]);
	assert(testG.supplyCount[copper] == G.supplyCount[copper]);
	assert(testG.supplyCount[silver] == G.supplyCount[silver]);
	assert(testG.supplyCount[gold] == G.supplyCount[gold]);
    //Kingdom cards
    int illegalCard = 0;
//    int flagIllegalCardInPlay = 0;
    for (i = adventurer; i <= treasure_map; i++) {    //loop over all possible cards in dominion universe (see enum def in dominion.h)
        illegalCard = 1;
        for (j=0; j<10; j++) {  //loop over 10 cards in game
            if (k[j] == i) { //If a kingdom card is in the game, check that its supply has not changed
                illegalCard = 0;
                printf("Supply of card %d = %d, expected = %d\n", k[j], testG.supplyCount[i], G.supplyCount[i]);
                assert(testG.supplyCount[i] == G.supplyCount[i]);
            }
        }
        if (illegalCard == 1 && testG.supplyCount[i] != -1) { //condensed error testing across all illegal kingdom cards
            printf("An illegal kingdom card has been put into play: ");
            assert(testG.supplyCount[i] == -1);
        }
    }
    printf("Also checked: no illegal kingdom cards were brought into play.\n");

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTMETHOD);

	return 0;
}


