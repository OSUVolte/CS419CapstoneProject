/**
cardtest1.c: Tests the SMITHY card.

Basic requirements for the card:
1. Current player should receive exact 3 cards.
2. 3 cards should come from his own pile.
3. No state change should occur for other players.
4. No state change should occur to the victory card piles and kingdom card piles.

Some possible errors:
(1) Four cards are added instead of three. This is caused by the use of "<=" instead of "<"
    //for (i = 0; i < 3; i++)
    for (i = 0; i <= 3; i++)

(2) The card is not discarded after it is played.
    //discardCard(handPos, currentPlayer, state, 0);

Include the following lines in your makefile:
cardtest1: cardtest1.c dominion.o rngs.o
    gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o -lm

    was:
    gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)

**/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"       //*******************>>>> change me

void cardtest1() {
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
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);        //*******************>>>> change me

    // variables that reflect expected outcome
	newCards = 3;
	xtraCoins = 0;

    // ----------- TEST 1: +3 cards in player's hand --------------
	printf("TEST 1: +3 cards in player's hand\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);

    // ----------- TEST 2: -3 cards in player's deck --------------
	printf("TEST 2: -3 cards in player's deck\n");
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);

    // ----------- TEST 3: No change to other player's hand or deck --------------
	printf("TEST 3: No change to other player's hand or deck.\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
	assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);
	assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]);

    // ----------- TEST 4: No state change should occur to the curse, victory, treasury and kingdom card piles. --------------
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
    int flagIllegalCardInPlay = 0;
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

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}


