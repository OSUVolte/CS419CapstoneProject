/*
 * cardtest4.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
    int errorCount = 0;
    int i;
    int usedActions = 0;
    int playedCards = 0;
    int xtraBuys = 0;
    int newCards = 3;
    int discarded = 0;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 912;
    int numPlayers = 4;
    int thisPlayer = 0;
    int nextPlayer = 1;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards

	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);


	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;



	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);


	newCards = 3;
	xtraCoins = 0;
	discarded = 0;
    xtraBuys = 0;
    playedCards = 1;

    printf("checking estate card total count = %d, expected %d\n", testG.supplyCount[1], G.supplyCount[1]);
    if(!(testG.supplyCount[1] == G.supplyCount[1]))
    {
        printf("ERROR, estate count not correct\n");
        errorCount++;
    }



    printf("checking duchy card total count = %d, expected %d\n", testG.supplyCount[2], G.supplyCount[2]);
    if(!(testG.supplyCount[2] == G.supplyCount[2]))
    {
        printf("ERROR, duchy count not correct\n");
        errorCount++;
    }


    printf("checking province card total count = %d, expected %d\n", testG.supplyCount[3], G.supplyCount[3]);
    if(!(testG.supplyCount[3] == G.supplyCount[3]))
    {
        printf("ERROR, province count not correct\n");
        errorCount++;
    }

    printf("checking province card total count = %d, expected %d\n", testG.supplyCount[3], G.supplyCount[3]);
    if(!(testG.supplyCount[3] == G.supplyCount[3]))
    {
        printf("ERROR, province count not correct\n");
        errorCount++;
    }

    printf("checking supplies of all treasure cards\n");

        for(i = 4; i < 7; i++)
        {

                if(!(testG.supplyCount[i] == G.supplyCount[i]))
                {
                printf("ERROR, treasure card type %i IE CARD ENUM count not correct\n", i);
                errorCount++;
                }
        }

    printf("checking all kingdom, treasure, curse and victory card supplies\n");

        for(i = 4; i < 7; i++)
        {

                if(!(testG.supplyCount[i] == G.supplyCount[i]))
                {
                printf("ERROR, card type %i IE CARD ENUM count not correct\n", i);
                errorCount++;
                }
        }



    printf("hand count = %d\n", testG.handCount[thisPlayer]);

	printf("card player hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards  - playedCards);
    if(!(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - playedCards))
    {
        printf("ERROR, card player hand count not correct\n");
        errorCount++;
    }

    printf("card player deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	if(!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards))
    {
        printf("ERROR, card player deck count not correct\n");
        errorCount++;
    }

    printf("card player coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	if(!(testG.coins == G.coins + xtraCoins))
    {
        printf("ERROR, card player coin count not correct\n");
        errorCount++;
    }


    printf("buys = %d, expected = %d\n", testG.numBuys, G.numBuys + xtraBuys);
	if(!(testG.numBuys == G.numBuys + xtraBuys))
    {
        printf("ERROR, numBuys not correct\n");
        errorCount++;
    }

    //actions are decremented after cardEffect() returns this checks that actions werent added
    printf("number of actions = %d, expected = %d\n", testG.numActions, G.numActions); //actions
	if(!(testG.numActions == G.numActions))
    {
        printf("ERROR, numBuys not correct\n");
        errorCount++;
    }


	//tests other players cards unchanged
        newCards = 0;
        xtraCoins = 0;
        discarded = 0;


    for(i = 0; i < numPlayers; i++)
    {
        if(i != thisPlayer)
        {
            printf("player %i hand count = %d, expected = %d\n", i, testG.handCount[i], G.handCount[i] + newCards - discarded);

            	if(!(testG.handCount[i] == G.handCount[i] + newCards - discarded))
                {
                printf("ERROR, player %i hand count not correct\n", i);
                errorCount++;
                }
        }
    }


    for(i = 0; i < numPlayers; i++)
    {
        if(i != thisPlayer)
        {
            printf("player %i deck count = %d, expected = %d\n",i , testG.deckCount[i], G.deckCount[i] - newCards + shuffledCards);

                if(!(testG.deckCount[i] == G.deckCount[i] - newCards + shuffledCards))
                {
                    printf("ERROR, player %i deck count not correct\n", i);
                    errorCount++;
                }
        }
    }



	printf("\n >>>>> Testing complete %s with %i errors <<<<<\n\n", TESTCARD, errorCount);


	return 0;
}

