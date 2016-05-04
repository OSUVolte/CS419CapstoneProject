//Test for council_roomCard

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{
	int seed = 1000;
    int numPlayer = 2;
    int thisPlayer = 0;
    int handPos = 0;
    int i = 0;
    int cardsBeforeHand;
    int cardsBeforeDeck;
    int buysBeforePlay;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	struct gameState G, testG;
    printf("----------------- Testing Card: Council Room ----------------\n");

	initializeGame(numPlayer, k, seed, &G);
	
    printf("----------- Test 1:  Player should have 4+ cards ----------\n");

    memcpy(&testG, &G, sizeof(struct gameState));
    cardsBeforeHand = testG.handCount[thisPlayer];
    cardsBeforeDeck = testG.deckCount[thisPlayer];
    buysBeforePlay = testG.numBuys + 1;
    council_roomCard(&testG, handPos, thisPlayer, i);

    if(testG.handCount[thisPlayer] == (cardsBeforeHand + 4))
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED\n");

    printf("----------- Test 2:  Deck should have -4 cards ----------\n");

    if(testG.deckCount[thisPlayer] == (cardsBeforeDeck - 4))
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED\n");


    printf("----------- Test 3:  Player should have increased number of buys ----------\n");

    if(testG.numBuys == buysBeforePlay)
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED\n");

    printf("----------- Test 4:  Opponent should have drawn another card ----------\n");
    thisPlayer = 1;
    if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 1)
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED\n");

    printf("----------- Test 5:  Player should have discarded played card ----------\n");
    thisPlayer = 0;
    if(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer] + 1)
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED\n");


    printf("---------- council_roomCard testing completed. ----------\n\n");

 return 0;

}