/**
cardtest4.c: Tests the council_room card

// Basic requirements
1. Current player should receive exactly 4 cards.
2. 4 cards should come from his own pile.
3. Current player's number of buys should be incremented
4. Each other player should receive exactly 1 card
5. 1 card should come from each other player's own pile
6. No state change should occur to the curse, treasury, victory and kingdom card piles

Some possible errors:
(1) Opponents do not gain a card even though they should.
    //Each other player draws a card
    //for (i = 0; i < state->numPlayers; i++)
	//{
    //    if ( i != currentPlayer )
	//    {
    //        drawCard(i, state);
	//    }
	//}

Include the following lines in your makefile:
cardtest1: cardtest4.c dominion.o rngs.o
    gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o -lm

    was:
    gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

**/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "council_room"       //*******************>>>> change me

void cardtest4() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 7;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
	struct gameState G, testG;
	int k[10] = {smithy, adventurer, feast, council_room, gardens, village, remodel, mine, cutpurse, embargo};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	// apply the play to the testG game state
	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);        //*******************>>>> change me

    // variables that reflect expected outcome
	int newCards_thisPlayer = 4;
	int newCards_otherPlayer = 1;
	xtraCoins = 0;

    // ----------- TEST 1: +4 cards in player's hand --------------
	printf("TEST 1: +4 cards in player's hand\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards_thisPlayer - discarded);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards_thisPlayer - discarded);

    // ----------- TEST 2: -4 cards in player's deck --------------
	printf("TEST 2: -4 cards in player's deck\n");
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards_thisPlayer + shuffledCards);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards_thisPlayer + shuffledCards);

    // ----------- TEST 3: +1 buy for player -------------- ///
	printf("TEST 3: +1 buy for player\n");
	printf("number of buys = %d, expected = %d\n", testG.numBuys, G.numBuys + 1);
	assert(testG.numBuys == G.numBuys + 1);

    // ----------- TEST 4: +1 cards in player's hand --------------
	printf("TEST 4: +1 cards in player's hand\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer] + newCards_otherPlayer);
	assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer] + newCards_otherPlayer);

    // ----------- TEST 5: -1 cards in player's deck --------------
	printf("TEST 5: -1 cards in player's deck\n");
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer] - newCards_otherPlayer + shuffledCards);
	assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer] - newCards_otherPlayer + shuffledCards);

    // ----------- TEST 6: No state change should occur to the curse, treasury, victory and kingdom card piles. --------------
	printf("TEST 6: No state change should occur to the curse, treasury, victory and kingdom card piles.\n");
    for (i = curse; i <= treasure_map; i++) {    //loop over all possible cards in dominion universe (see enum def in dominion.h)
        assert(testG.supplyCount[i] == G.supplyCount[i]);
    }
    printf("Confirmed: no change to other supplies of curse, kingdom, victory or treasury cards.\n");


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}


