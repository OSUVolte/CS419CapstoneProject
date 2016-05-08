//Random test for council_roomCard

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int oracleTest(struct gameState* G, struct gameState* testG);


int main()
{
	srand(time(NULL));
    int seed = 1000;
    int numPlayer = 2;
    int thisPlayer = 0;
    int i, j, l;
    int cardCount;
    int randomCard;
    int numTests = 20;
    int oracleResults;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	struct gameState G, testG;


    for(i = 0; i < numTests; i++)
    {
        initializeGame(numPlayer, k, seed, &G);
        cardCount = (rand() % 30);
        for(j = 0; j < cardCount; j++)
        {
            randomCard = rand() % 10;
            G.deck[thisPlayer][j] = k[randomCard];
        }
        
        G.numBuys = rand() % 5;

        memcpy(&testG, &G, sizeof(struct gameState));

        oracleResults = oracleTest(&testG, &G);

        printf("\n\nTest iteration: %d, Number of Failures: %d\n\n", i+1, oracleResults);

        printf("---------- council_roomCard testing completed. ----------\n\n");
    }
    
return 0;
}
    

int oracleTest(struct gameState* G, struct gameState* testG)
{
    int thisPlayer = 0;
    int handPos = 0;
    int cardsBeforeHand;
    int cardsBeforeDeck;
    int buysBeforePlay;
    int numFails = 0;
    int i = 0;

    printf("----------------- Testing Card: Council Room ----------------\n");	
	
    printf("----------- Test 1:  Player should have +4 cards ----------\n");

    
    cardsBeforeHand = testG->handCount[thisPlayer];
    cardsBeforeDeck = testG->deckCount[thisPlayer];
    buysBeforePlay = testG->numBuys;
    council_roomCard(testG, handPos, thisPlayer, i);

    if(testG->handCount[thisPlayer] == (cardsBeforeHand + 4))
        printf("TEST PASSED\n");
    else{
        printf("TEST FAILED\n");
        numFails++;
    }
    printf("----------- Test 2:  Deck should have -4 cards ----------\n");

    if(testG->deckCount[thisPlayer] == (cardsBeforeDeck - 4))
        printf("TEST PASSED\n");
    else{
        printf("TEST FAILED\n");
        numFails++;
    }

    printf("----------- Test 3:  Player should have increased number of buys ----------\n");

    if(testG->numBuys == buysBeforePlay + 1)
        printf("TEST PASSED\n");
    else{
        printf("TEST FAILED\n");
        numFails++;
    }
    printf("----------- Test 4:  Opponent should have drawn another card ----------\n");
    
    thisPlayer = 1;
    if(testG->handCount[thisPlayer] == G->handCount[thisPlayer] + 1)
        printf("TEST PASSED\n");
    else{
        printf("TEST FAILED\n");
        numFails++;
    }
    printf("----------- Test 5:  Player should have discarded played card ----------\n");
    thisPlayer = 0;
    if(testG->discardCount[thisPlayer] == G->discardCount[thisPlayer] + 1)
        printf("TEST PASSED\n");
    else{
        printf("TEST FAILED\n");
        numFails++;
    }    

 return numFails;

}