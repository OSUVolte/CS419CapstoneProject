/* -----------------------------------------------------------------------
 * Martha Gebremariam
 * CS362_SP2016
 * Assignment 3
 * Description: Unit test for council_room card in dominion.c
 * 
 * The following lines were also included makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 * gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main() {
    printf("\n\n*************************\n");
    printf ("TESTING council_room card\n");
    printf("*************************\n\n");  
        int seed = 1000;
        int player = 0;
        int numPlayers = 2;
        //int handPos = 0;
        int passedTest=0;
        int failedTest=0;
        struct gameState G;
        int k[10] = {adventurer, council_room, feast, mine, remodel, smithy, village, salvager, sea_hag, treasure_map};
        initializeGame(numPlayers, k, seed, &G);
        int testHand1[]= {copper, silver, estate, feast, council_room};
        int origCount=G.handCount[player];
	int origBuys=G.numBuys;
        //int s=villageRefactored(&G, player, handPos);

        memcpy(G.hand[0], testHand1, sizeof(int)*5);


        cardEffect(council_room, 0, 0, 0, &G, 4, 0);
        printf("Expected number of buys: %d - Result %d\n", origBuys+1, G.numBuys);
        if (G.handCount[player] == origCount){
            printf("Passed test\n\n");
            passedTest++;
        }
        else{
            printf("failed test\n\n");
            failedTest++;
        }
        //assert(G.handCount[player] == origCount);

        printf("Expected handSize: %d - Result %d\n", origCount+3, G.handCount[player]);
        if (G.handCount[player] == origCount+3){
            printf("Passed test\n\n");
            passedTest++;
        }
        else{
            printf("failed test\n\n");
            failedTest++;
        }
        //assert(G.handCount[player] == origCount+3);


        printf("Passed %d and failed %d of the cardtest4 tests\n", passedTest, failedTest);
        printf("*********************************************************************\n");
        printf("*********************************************************************\n\n");
        return 0;
}
