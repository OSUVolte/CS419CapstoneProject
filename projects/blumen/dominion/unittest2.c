/**
unittest2.c: Tests the discardCard() method

// Basic requirements
1.if flag is set, by end of method, card is added to discard pile
2.if flag is set, by end of method, discard pile counter is incremented by 1; otherwise it does not change
3.by end of method, card is removed from hand.
4.by end of method, decrement number of cards in hand
5.by end of method, other cards in hand are available (no card in hand has value -1)
6. no change to coins, buy or action counts
7. no change to other player's hand
8. No state change to the curse, victory, treasury and kingdom card piles.

Include the following lines in your makefile:
unittest2: unittest2.c dominion.o rngs.o
    gcc -o unittest2 -g  unittest2.c dominion.o rngs.o -lm

    was:
    gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
**/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTMETHOD "discardCard()"       //*******************>>>> change me

void unittest2() {
    int seed = 7;
    srand((unsigned) seed);
    int i, j, m;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
	struct gameState G, testG;
	int k[10] = {smithy, adventurer, feast, council_room, gardens, village, remodel, mine, cutpurse, embargo};
	int trashFlag = 0; // vary between 0 and 1
	int handPos = 0;
	int handType = 1; // toggle between 1 (single card) and 2 (full hand -- typically 5 cards -- and handPos = 0) and 3 (full hand + handPos = last)
    int returnValue = 0;

    printf("----------------- Testing Method: %s ----------------\n", TESTMETHOD);

    for (handType = 1; handType <= 6; handType++){

        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        // set trashFlag, hand size and position in hand of card to be discarded
        printf("\n\n%d\n", handType);
        if (handType == 1) {
            printf("TEST SERIES: Discarded (not trashed) card is only card in hand. \n");
            trashFlag = 0;
            for (i = 1; i < G.handCount[thisPlayer]; i++){
                G.hand[thisPlayer][i] = -1;
            }
            G.handCount[thisPlayer] = 1;
            handPos = 0;
        }
        if (handType == 2) {
            printf("TEST SERIES: Trashed card is only card in hand. \n");
            trashFlag = 1;
            for (i = 1; i < G.handCount[thisPlayer]; i++){
                G.hand[thisPlayer][i] = -1;
            }
            G.handCount[thisPlayer] = 1;
            handPos = 0;
        }
        if (handType == 3) {
            printf("TEST SERIES: Discarded (not trashed) card is last in a multi-card hand. \n");
            trashFlag = 0;
            handPos = G.handCount[thisPlayer]-1;
        }
        if (handType == 4) {
            printf("TEST SERIES: Trashed card is last in a multi-card hand. \n");
            trashFlag = 1;
            handPos = G.handCount[thisPlayer]-1;
        }
        if (handType == 5) {
            printf("TEST SERIES: Discarded (not trashed) card is first in a multi-card hand. \n");
            trashFlag = 0;
            handPos = 0;
        }
        if (handType == 6) {
            printf("TEST SERIES: Trashed card is first in a multi-card hand. \n");
            trashFlag = 1;
            handPos = 0;
        }

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));

        //Apply method
        returnValue = discardCard(handPos, thisPlayer, &testG, trashFlag);

        // ----------- TEST 1: if flag is set, by end of method, card is added to discard pile. --------------
        printf("TEST 1: If flag is NOT set, by end of method, card is added to discard pile; otherwise not\n");
        if (trashFlag == 0) {
//            i = testG.discard[thisPlayer][ testG.discardCount[thisPlayer] -1 ]; //testG holds card in discard pile
            i = testG.playedCards[ testG.playedCardCount -1 ]; //testG holds card in discard pile
            j = G.hand[thisPlayer][handPos]; //G holds card in old position in hand
            printf(" id of top card on discard pile = %d, expected = %d\n", i, j);
            assert(i == j);
        } else {
            printf(" does not apply\n");
        }

        // ----------- TEST 2: if flag is NOT set, by end of method, discard pile counter is incremented by 1; otherwise it does not change. --------------
        printf("TEST 2: if flag is set, by end of method, discard pile counter is incremented by 1; otherwise it does not change\n");
        if (trashFlag == 0) {
            printf(" discard count = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount+1);
            assert(testG.playedCardCount == G.playedCardCount+1);
        } else {
            printf(" discard count = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount);
            assert(testG.playedCardCount == G.playedCardCount);
        }

        // ----------- TEST 3: by end of method, card is removed from hand. --------------
        printf("TEST 3: by end of method, card is removed from hand.\n");
        if (handType == 1 || handType == 2) {  //discarded card was only card in hand
            printf(" hand count = %d, expected = 0\n", testG.handCount[thisPlayer]);
            assert(testG.handCount[thisPlayer] == 0);
        } else if (handType == 3 || handType == 4){ //last card in multihand card
            printf(" value at old hand position = %d, expected = -1\n", testG.hand[thisPlayer][handPos]);
            assert(testG.hand[thisPlayer][handPos] == -1);
        } else  {//some card other than the last, in a multicard hand
            printf(" value at old hand position = %d, expected = %d\n", testG.hand[thisPlayer][handPos], G.hand[thisPlayer][ G.handCount[thisPlayer] -1 ]);
            assert(testG.hand[thisPlayer][handPos] == G.hand[thisPlayer][ G.handCount[thisPlayer] -1 ]);
       }

        // ----------- TEST 4: by end of method, decrement number of cards in hand. --------------
        printf("TEST 4: by end of method, decrement number of cards in hand.\n");
        printf(" hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]-1);
        assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]-1);

        // ----------- TEST 5: by end of method, other cards in hand are available (no card in hand has value -1). --------------
        printf("TEST 5: by end of method, other cards in hand are available (no card in hand has value -1).\n");
        m = 0; //flag that is set if any card is found in hand that has <0 value
        for (i = 0; i < testG.handCount[thisPlayer]; i++) {
            if (i != handPos && testG.hand[thisPlayer][i] != G.hand[thisPlayer][i]) {
                m++;
            }
        }
        assert(m==0);
        printf(" Confirmed: Except for the discarded card, the hand contains the same cards as it did before.");

        // ----------- TEST 6: no change to coins, buy or action counts --------------
        printf("TEST 6: no change to coins, buy or action counts\n");
        printf(" coins = %d, expected = %d\n", testG.coins, G.coins);
        printf(" buys = %d, expected = %d\n", testG.numBuys, G.numBuys);
        printf(" actions = %d, expected = %d\n", testG.numActions, G.numActions);
        assert(testG.coins == G.coins);
        assert(testG.numBuys == G.numBuys);
        assert(testG.numActions == G.numActions);

        // ----------- TEST 7: no change to other player's hand --------------
        printf("TEST 7: no change to other player's hand\n");
        printf(" hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
        printf(" deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
        assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);
        assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]);

        // ----------- TEST 8: No state change to the curse, victory, treasury and kingdom card piles --------------
        printf("TEST 8: No state change to the curse, victory, treasury and kingdom card piles\n");
        for (i = curse; i <= treasure_map; i++) {    //loop over all possible cards in dominion universe (see enum def in dominion.h)
            assert(testG.supplyCount[i] == G.supplyCount[i]);
        }
        printf(" Confirmed.");

    }

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTMETHOD);

	return 0;
}


