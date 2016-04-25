/**
cardtest2.c: Tests the ADVENTURER card.

Basic requirements for the card:
1. Current player should receive exactly 2 cards.
2. Current player should receive only treasury cards.
3. No treasury card should have been discarded.
4. The 2 treasury Cards + discarded cards should come from the player's own pile (pile is decremented)
5. No state change should occur for other players.
6. No state change should occur to the victory card piles and kingdom card piles.

Some possible errors:
(1) One of the treasure cards is never tested, which leads it to be ignored when adding treasure to the player's hand
	//if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	if (cardDrawn == silver || cardDrawn == gold)

(2) [error in original file?] The Adventurer card appears not to be discarded after it is played.
    //discardCard(handPos, currentPlayer, state, 0);

Include the following lines in your makefile:
cardtest2: cardtest2.c dominion.o rngs.o
    gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o -lm

    was:
    gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)

**/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"       //*******************>>>> change me

void cardtest2() {
    int newCards = 0;
    int discarded = 0;
    int xtraCoins;
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
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
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);        //*******************>>>> change me

    // variables that reflect expected outcome
	newCards = 2;
	xtraCoins = 0;

    // ----------- TEST 1: +2 cards in player's hand --------------
	printf("TEST 1: +2 cards in player's hand\n");
	printf(" hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);

    // ----------- TEST 2: Current player should receive only treasury cards. --------------
	printf("TEST 2: Current player should receive only treasury cards.\n");
	printf(" Last card added to hand = %d, expected = %d, %d or %d\n", testG.hand[thisPlayer][testG.deckCount[thisPlayer]-1], copper, silver, gold);
    m = 0;
    for (i=(int)copper; i<=(int)gold; i++){
        if (testG.hand[thisPlayer][testG.deckCount[thisPlayer]-1] == i) {
            m++;
        }
    }
	assert(m > 0);
	printf(" Second-to-last card added to hand = %d, expected = %d, %d or %d\n", testG.hand[thisPlayer][testG.deckCount[thisPlayer]-2], copper, silver, gold);
    m = 0;
    for (i=(int)copper; i<=(int)gold; i++){
        if (testG.hand[thisPlayer][testG.deckCount[thisPlayer]-2] == i) {
            m++;
        }
    }
	assert(m > 0);

    // ----------- TEST 3: No treasury card should have been discarded. --------------
	printf("TEST 3: No treasury card should have been discarded.\n");
    m = testG.discardCount[thisPlayer] - G.discardCount[thisPlayer]; // number of cards discarded during play
    for (i=1; i<=m; i++) {
        printf(" discarded: %d, expected not to be in set {%d, %d, %d}\n", testG.discard[thisPlayer][ testG.discardCount[thisPlayer] -m ], copper, silver, gold);
        for (j=(int)copper; j<=(int)gold; j++){
            assert(testG.discard[thisPlayer][ testG.discardCount[thisPlayer] -m ] != j);
        }
    }
	printf(" Confirmed.\n");

    // ----------- TEST 4: The 2 treasury Cards + discarded cards should come from the player's own pile (pile is decremented) --------------
	printf("TEST 4: The 2 treasury Cards + discarded cards should come from the player's own pile (pile is decremented)\n");
    m = testG.discardCount[thisPlayer] - G.discardCount[thisPlayer] + 2; // number of cards discarded during play + 2 treasury cards in hand
	printf(" deck has decreased by %d cards, expected >= 2\n", m);
	assert(m >= 2);

    // ----------- TEST 5: No change to other player's hand or deck --------------
	printf("TEST 5: No change to other player's hand or deck.\n");
	printf(" hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
	printf(" deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
	assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);
	assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]);

    // ----------- TEST 6: No state change should occur to the curse, victory, treasury and kingdom card piles. --------------
    printf("TEST 6: No state change to the curse, victory, treasury and kingdom card piles\n");
    for (i = curse; i <= treasure_map; i++) {    //loop over all possible cards in dominion universe (see enum def in dominion.h)
        assert(testG.supplyCount[i] == G.supplyCount[i]);
    }
    printf(" Confirmed.");

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}
