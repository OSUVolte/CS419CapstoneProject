/* -----------------------------------------------------------------------
 * Martha Gebremariam
 * CS362_SP2016
 * Assignment 3
 * Description: Unit test for village card in dominion.c
 * 
 * The following lines were also included makefile:
 *
 * cardtest3: cardtest3.c dominion.o rngs.o
 * gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
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
    printf ("TESTING village card\n");
    printf("*************************\n\n");  
    int seed = 1000;
    int player = 0;
    int numPlayers = 2;
    int passedTest=0;
    int failedTest=0;
        struct gameState G;
        int k[10] = {adventurer, council_room, feast, mine, remodel, smithy, village, salvager, sea_hag, treasure_map};
        initializeGame(numPlayers, k, seed, &G);
        int testHand1[]= {copper, silver, estate, feast, village};
        memcpy(G.hand[0], testHand1, sizeof(int)*5);
        int origCount=G.handCount[player];
 	    printf("orig numActions: %d\n", G.numActions);
        cardEffect(village, 0, 0, 0, &G, 4, 0);
        printf("Expected handSize: %d - Result %d\n", origCount, G.handCount[player]);
        if (G.handCount[player] == origCount){
            printf("Passed test\n\n");
            passedTest++;
        }
        else{
            printf("failed test\n\n");
            failedTest++;
        }
        //assert(G.handCount[player] == origCount);

        printf("Expected number of actions: %d - Result %d\n", 3, G.numActions);
        if (G.numActions == 3){
            printf("Passed test\n\n");
            passedTest++;
        }
        else{
            printf("failed test\n\n");
            failedTest++;
        }
        //assert(G.numActions == 3);

	   printf("Passed %d and failed %d of the cardtest3 tests\n", passedTest, failedTest);		
        return 0;
}
