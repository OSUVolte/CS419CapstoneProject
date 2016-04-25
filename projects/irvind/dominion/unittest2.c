/*---------------------------------------
* Brett Irvin
* 4/20/16
* CS362_400 Software Engineering II
* Assignment 3--unittest2.c
* Unit test for the shuffle function
*---------------------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


int main() {
    int i, j;
    int seed = 1000;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};
    int numPlayers = 2;
    struct gameState G, testG;
    
	// Initialize a new game 
    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    shuffle(0, &G);
    shuffle(0, &testG);
    printf("\n---Testing the shuffle function:---\n");
	
	for (j = 0; j < numPlayers; j++) {
        printf("\nPlayer %d\n", j + 1);
        printf("Unshuffled Deck: \n");
        for (i = 0; i < testG.deckCount[0]; i++){
            printf("%d ", testG.deck[0][i]);	
        }
        printf("\nShuffled Deck:\n");
        for (i = 0; i < G.deckCount[0]; i++) {
            printf("%d ", G.deck[0][i]);
        }
	}
	
	printf("\n---Shuffle test complete---\n\n");
	return 0;
}


