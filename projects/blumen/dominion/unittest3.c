/**
unittest3.c: Tests the buyCard() method

// Basic requirements
1. return -1 if insufficient numBuys; no change anywhere in game
2. return -1 if insufficient supply in target pile; no change anywhere in game
3. return -1 if insufficient coins for target card; no change anywhere in game
4. purchase is added to player's discard pile (incremented & last card = target)
5. supply of target card is decremented
6. coins are decremented by cost of purchase
7. numBuys is decremented
8. no change to numActions
9. no change to thisPlayer's hand
10. no change to other player's hand
11. No state change to the supplies other than for the target pile.

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

#define TESTMETHOD "buyCard()"       //*******************>>>> change me

void unittest3() {
    //time_t t;
    //srand((unsigned) time(&t));
    int seed = 7;
    srand((unsigned) seed);
    int i, m;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
	struct gameState G, testG;
	int k[10] = {smithy, adventurer, feast, council_room, gardens, village, remodel, mine, cutpurse, embargo};
	int handType = 1; // toggle between 1 (single card) and 2 (full hand -- typically 5 cards -- and handPos = 0) and 3 (full hand + handPos = last)
    int returnValue = 0;
    int targetCard = 0;

    printf("----------------- Testing Method: %s ----------------\n", TESTMETHOD);

    for (handType = 1; handType <= 4; handType++){

        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        // pick a random card to buy
        targetCard = rand() % (treasure_map+1);

        // set trashFlag, hand size and position in hand of card to be discarded
        printf("\n\n%d\n", handType);
        if (handType == 1) {
            printf("TEST SERIES: insufficient numBuys. \n");
            G.numBuys = 0;
        }
        if (handType == 2) {
            printf("TEST SERIES: insufficient supply of target cards \n");
            G.supplyCount[targetCard] = 0;
        }
        if (handType == 3) {
            printf("TEST SERIES: Insufficient coins for target card. \n");
            G.coins = getCost(targetCard) - rand() % (getCost(targetCard) + 1);
        }
        if (handType == 4) {
            printf("TEST SERIES: Purchase authorized. \n");
            G.numBuys = G.numBuys+1;
            G.supplyCount[targetCard] = G.supplyCount[targetCard] + 1;
            G.coins = getCost(targetCard) + rand() % (getCost(targetCard) + 1);
        }

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));

        //Apply method
        returnValue = buyCard(targetCard, &testG);

        // ----------- TEST 1: return -1 if insufficient numBuys; no change anywhere in game --------------
        printf("TEST 1: return -1 if insufficient numBuys; no change anywhere in game\n");
        if (handType == 1) {
            printf("return value = %d, expected = -1\n", returnValue);
            assert(returnValue == -1);
            assert(memcmp(&testG, &G, sizeof(struct gameState)) == 0);
            printf("game state remained the same through function call\n");
        } else {
            printf("does not apply\n");
        }

        // ----------- TEST 2: return -1 if insufficient supply in target pile; no change anywhere in game --------------
        printf("TEST 2: return -1 if insufficient supply in target pile; no change anywhere in game\n");
        if (handType == 2) {
            printf(" return value = %d, expected = -1\n", returnValue);
            assert(returnValue == -1);
            assert(memcmp(&testG, &G, sizeof(struct gameState)) == 0);
            printf(" game state remained the same through function call");
        } else {
            printf(" does not apply\n");
        }

        // ----------- TEST 3: return -1 if insufficient coins for target card; no change anywhere in game --------------
        printf("TEST 3: return -1 if insufficient coins for target card; no change anywhere in game\n");
        if (handType == 3) {
            printf(" return value = %d, expected = -1\n", returnValue);
            assert(returnValue == -1);
            assert(memcmp(&testG, &G, sizeof(struct gameState)) == 0);
            printf(" game state remained the same through function call");
        } else {
            printf(" does not apply\n");
        }

        // ----------- TEST 4: purchase is added to player's discard pile (incremented; last card = target) --------------
        printf("TEST 4: purchase is added to player's discard pile (incremented; last card = target)\n");
        if (handType == 4) {
            printf(" id of top card on discard pile = %d, expected = %d\n", testG.discard[thisPlayer][ testG.discardCount[thisPlayer] -1 ], targetCard);
            printf(" discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]+1);
            assert(testG.discard[thisPlayer][ testG.discardCount[thisPlayer] -1 ] == targetCard);
            assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]+1);
        } else {
            printf(" does not apply\n");
        }

        // ----------- TEST 5: supply of target card is decremented --------------
        printf("TEST 5: supply of target card is decremented\n");
        if (handType == 4) {
            printf(" supply of target card = %d, expected = %d\n", testG.supplyCount[targetCard], G.supplyCount[targetCard]-1);
            assert(testG.supplyCount[targetCard] == G.supplyCount[targetCard]-1);
        } else {
            printf(" does not apply\n");
        }

        // ----------- TEST 6: coins are decremented by cost of purchase --------------
        printf("TEST 6: coins are decremented by cost of purchase\n");
        if (handType == 4) {
            printf(" coins = %d, expected = %d\n", testG.coins, G.coins-getCost(targetCard));
            assert(testG.coins == G.coins-getCost(targetCard));
        } else {
            printf(" does not apply\n");
        }

        // ----------- TEST 7: numBuys is decremented --------------
        printf("TEST 7: numBuys is decremented\n");
        if (handType == 4) {
            printf(" numBuys = %d, expected = %d\n", testG.numBuys, G.numBuys-1);
            assert(testG.numBuys == G.numBuys-1);
        } else {
            printf(" does not apply\n");
        }

        // ----------- TEST 8: no change to numActions --------------
        printf("TEST 8: no change to numActions\n");
        printf(" numActions = %d, expected = %d\n", testG.numActions, G.numActions);
        assert(testG.numActions == G.numActions);

        // ----------- TEST 9: no change to thisPlayer's hand --------------
        printf("TEST 9: no change to thisPlayer's hand\n");
        printf(" hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
        assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);
        printf(" same cards remain in thisPlayer's hand: ");
        m = 0; //flag that is set if any card is found in hand that has <0 value
        for (i = 0; i < testG.handCount[thisPlayer]; i++) {
            if (testG.hand[thisPlayer][i] != G.hand[thisPlayer][i]) {
                m++;
            }
        }
        assert(m==0);
        printf(" Confirmed.\n");

        // ----------- TEST 10: no change to other player's hand --------------
        printf("TEST 10: no change to other player's hand\n");
        printf(" hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
        assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);
        printf(" same cards remain in otherPlayer's hand: ");
        m = 0; //flag that is set if any card is found in hand that has <0 value
        for (i = 0; i < testG.handCount[otherPlayer]; i++) {
            if (testG.hand[otherPlayer][i] != G.hand[otherPlayer][i]) {
                m++;
            }
        }
        assert(m==0);
        printf(" Confirmed.\n");

        // ----------- TEST 11: no change to the supplies of curse, treasury, victory and kingdom cards -- other than for the target pile --------------
        printf("TEST 11: no change to the supplies of curse, treasury, victory and kingdom cards -- other than for the target pile\n");
        for (i = curse; i <= treasure_map; i++) {    //loop over all possible cards in dominion universe (see enum def in dominion.h)
            if (i != targetCard) {
            assert(testG.supplyCount[i] == G.supplyCount[i]);
            }
        }
        printf("Confirmed.");

    }

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTMETHOD);

	return 0;
}


