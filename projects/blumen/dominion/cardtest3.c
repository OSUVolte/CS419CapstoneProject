/**
cardtest3.c: Tests the FEAST card.

Basic requirements for the card:
1. Feast card should be trashed (no longer in discard, hand or player's pile)     //NOT DONE INSIDE FEAST'S CARD CODE / not tested here
2. The card the player selects should have a value of at most 5
3. The pile the player selects should have been non-empty before play
4. Kingdom/Victory/Curse/Treasury card pile of selected card should be decremented
5. The card the player selected should be added to the player's discard pile.
6. Player's discard pile should be incremented.
7. The number of cards assigned to the player should be 1 more than it was before play.
8. No state change should occur for other players.
9. No state change should occur to the other victory card piles and kingdom card piles.

Some possible errors:
(1) Only 2 coins (and not 5) are added to the player's purse.
    //updateCoins(currentPlayer, state, 5);
    updateCoins(currentPlayer, state, 2);

(2) The comparitor is incorrect, <= rather than <. This compounds error 1 without erasing it.
    //else if (state->coins < getCost(choice1)){
    else if (state->coins <= getCost(choice1)){

(3) The player does not gain the card that was purchased. This may only show up by looking at the deck post-play.
    //gainCard(choice1, state, 0, currentPlayer);//Gain the card

Include the following lines in your makefile:
cardtest3: cardtest3.c dominion.o rngs.o
    gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o -lm

    was:
    gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)

**/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "feast"       //*******************>>>> change me

void cardtest3() {
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
	choice1 = 2; //consider randomizing this value instead
	cardEffect(feast, choice1, choice2, choice3, &testG, handpos, &bonus);        //*******************>>>> change me

    // variables that reflect expected outcome
	newCards = 3;
	xtraCoins = 0;

    // ----------- TEST 1: Feast card should be trashed (no longer in discard, hand or player's pile) --------------
    //NOT DONE INSIDE FEAST'S CARD CODE

    // ----------- TEST 2: The card the player selects should have a value of at most 5 --------------
	printf("TEST 2: The card the player selects should have a value of at most 5\n");
	printf("Card value = %d\n", getCost(choice1));
	assert(getCost(choice1) <= 5);

    // ----------- TEST 3: The pile the player selects should have been non-empty before play --------------
	printf("TEST 3: The pile the player selects should have been non-empty before play\n");
	printf("pre-play supply count = %d\n", G.supplyCount[choice1]); //G is game state before play
	assert(G.supplyCount[choice1] > 0);

    // ----------- TEST 4: Kingdom/Victory/Curse/Treasury card pile of selected card should be decremented --------------
	printf("TEST 4: Kingdom/Victory/Curse/Treasury card pile of selected card should be decremented\n");
	printf("supply count = %d, expected = %d\n", testG.supplyCount[choice1], G.supplyCount[choice1]-1);
	assert(testG.supplyCount[choice1] == G.supplyCount[choice1]-1);

    // ----------- TEST 5: The card the player selected should be added to the player's discard pile. --------------
	printf("TEST 5: The card the player selected should be added to the player's discard pile\n");
	printf("id of top card on discard pile = %d, expected = %d\n", testG.discard[thisPlayer][ testG.discardCount[thisPlayer] -1 ], choice1);
    assert(testG.discard[thisPlayer][ testG.discardCount[thisPlayer] -1 ] == choice1);

    // ----------- TEST 6: Player's discard pile should be incremented. --------------
	printf("TEST 6: Player's discard pile should be incremented\n");
	printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]+1);
    assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]+1);

    // ----------- TEST 7: The number of cards assigned to the player should be the same as it was before play. --------------
	printf("TEST 7: The number of cards assigned to the player should be 1 more than it was before play\n");
	i = testG.handCount[thisPlayer] + testG.deckCount[thisPlayer] + testG.discardCount[thisPlayer];
	j = G.handCount[thisPlayer] + G.deckCount[thisPlayer] + G.discardCount[thisPlayer] + 1;
	printf("number of cards = %d, expected = %d\n", i, j);
    assert(i == j);

    // ----------- TEST 8: No state change should occur for other players. --------------
	printf("TEST 8: No change to other player's hand or deck.\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
	assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);
	assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]);

    // ----------- TEST 9: No state change should occur to the other victory card piles and kingdom card piles. --------------
    //except where chosen!
	printf("TEST 4: No state change should occur to the curse, victory, treasury and kingdom card piles.\n");
    for (i = curse; i <= treasure_map; i++) {    //loop over all possible cards in dominion universe (see enum def in dominion.h)
        if (i != choice1) {
            assert(testG.supplyCount[i] == G.supplyCount[i]);
        }
    }
    printf("Confirmed: no change to other supplies of curse, kingdom, victory or treasury cards.\n");

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}


