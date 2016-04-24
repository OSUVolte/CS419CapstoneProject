/*---------------------------------------
* Brett Irvin
* 4/20/16
* CS362_400 Software Engineering II
* Assignment 3--unittest4.c
* Unit test for the numHandCards function
*---------------------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main() 
{
    int i, j;
    int seed = 1000;
    int numPlayers = 2;
    int expectedCount;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};
	struct gameState G, testG;	

    initializeGame(numPlayers, k, seed, &G);
	
	/*---------------------------------------------------------*/
    printf("\n---Testing the numHandCards function:---\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("Test 1: Adding Cards\n");
    for (i = 0; i < numPlayers; i++) {
        printf("Player %d\n", i + 1);
        expectedCount = 5;
        for (j = 0; j < 5; j++){
            if (numHandCards(&G) == expectedCount + j) {
                printf("Cards in hand: %d, Expected: %d\n", numHandCards(&G), expectedCount + j);
				printf("Success: Card count matches what was expected.\n\n");
			}	
            else {
                printf("Cards in hand: %d, Expected: %d\n", numHandCards(&G), expectedCount + j);
				printf("Failure: Card count does not match expected count.\n");
			}	
            drawCard(whoseTurn(&G), &G);
        }
        endTurn(&G);
    }
	
	/*---------------------------------------------------------*/
    printf("Test 2: Discarding Cards\n");
	memcpy(&testG, &G, sizeof(struct gameState));
    for (i = 0; i < numPlayers; i++) {
        printf("Player %d\n", i + 1);
        expectedCount = 5;
        for (j = 0; j < 5; j++) {
            if (numHandCards(&G) == expectedCount - j) {
                printf("Cards in hand: %d, Expected: %d\n", numHandCards(&G), expectedCount - j);
				printf("\nSuccess: Card count matches what was expected.\n");	
			}	
            else {
                printf("Cards in hand: %d, Expected: %d\n", numHandCards(&G), expectedCount - j);
				printf("Failure: Card count does not match expected count.\n");
			}	
            discardCard(0, i, &G, 0);
        }
        endTurn(&G);
    }
    printf("\n---numHandCards test complete---\n\n");
    return 0;
}