/* -----------------------------------------------------------------------
 * Martha Gebremariam
 * CS362_SP2016
 * Assignment 3
 * Description: Unit test for adventurere card in dominion.c
 * 
 * The following lines were also included makefile:
 *
 * unittest4: cardtest1.c dominion.o rngs.o
 * gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    printf("\n\n*************************\n");
    printf ("TESTING adventurer card\n");
    printf("*************************\n\n");  
	int seed = 1000;
	int player = 0;
	int numPlayers = 2;
	int handPos = 0;
    int passedTest=0;
    int failedTest=0;
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, mine, remodel, smithy, village, salvager, sea_hag, treasure_map};
	initializeGame(numPlayers, k, seed, &G);
    int testHand1[]= {copper, silver, estate, feast, adventurer};
  	memcpy(G.hand[0], testHand1, sizeof(int)*5);
    int origCount=G.handCount[player];	

	cardEffect(adventurer, 0, 0, 0, &G, 4, 0);
	printf("Expected HandSize: %d - Result %d\n", origCount+2, G.handCount[player]);
    if (G.handCount[player] == origCount+2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
	//assert(G.handCount[player] == origCount+3-1); 
	printf("Passed %d and failed %d of the cardtest1 tests\n", passedTest, failedTest);		
	return 0;
}
