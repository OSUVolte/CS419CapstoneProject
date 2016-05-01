/*
	Andriy Solovyov
	CS-362
	Assignment 3
        cardtest1.c


Description:
	(20 points) Write unit tests for four Dominion cards implemented in dominion.c.  
	These tests should be checked in as cardtest1.c, cardtest2.c,cardtest3.c, and cardtest4.c. 
	(For example, create a test for smithy card.). It is mandatory to test smithy and adventurer card. 

*/


#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h>  
#include <stdlib.h>
#include "rngs.h"

#define TESTCARD "smithy"


/*
	 Here for cardtest1.c we will create a test for smithy card as required
	 It will include 4 different tests:
		1) checks if players cards from the his/her pile
		2) checks if player receives 3 cards
                3) No change in state for other players
		4) No change in state to the victory and kindom card piles
*/


int main() {
   
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	int secPlayer = 1;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	int i;
        int equal;
	int newCards = 0;
    	int discarded = 1;
    	int cardTemp = 0;
        int successFlag = 0;
        int shuffledCards = 0;
        //int handpos = 0; 
        //int choice1 = 0; 
        //int choice2 = 0;
       // int choice3 = 0; 
    
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	gainCard(smithy, &G, 2, 0);
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\n Checking for current player's hand card \n");
	cardEffect(smithy, 0, 0, 0, &G, G.handCount[0]-1, 0);
	
	//players hand +3
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 3);
	if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + 3){
		printf("Test one Failed!\n");
	}
	
	// Take 3 cards from current player's pile
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] + 3);
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] + 3){
		printf("Failed Player 1 has more or less than 3 cards\n");
	}
	
	/*testing if player's 2 game was effected */
	
	printf ("Smithy card effect on player 2...\n");
	
	printf("hand count = %d, expected %d\n", testG.handCount[secPlayer], G.handCount[secPlayer]);
	if(testG.handCount[secPlayer] != G.handCount[secPlayer]){
		printf("Error, player 2 hand was effected\n");
	}
	
	printf("deck count = %d, expected %d\n", testG.deckCount[secPlayer], G.deckCount[secPlayer]);
	if(testG.deckCount[secPlayer] != G.deckCount[secPlayer]){
		printf("Error, player 2 deck was effected\n");
	}
	
	printf("discard count = %d, expected %d\n\n", testG.discardCount[secPlayer], G.discardCount[secPlayer]);
	if(testG.discardCount[secPlayer] != G.discardCount[secPlayer]){
		printf("Error, player 2 deck was effected\n");
	}
	/*testing if victory and Kindom cards were effected*/
	printf("Testing for if Victory and Kindom cards were effected\n");
	int arraySize = sizeof(G.supplyCount) / sizeof(int);
	int i = 0;
	for(i = 0; i < arraySize; i++){
		printf("supply count = %d, expected %d\n", testG.supplyCount[i], G.supplyCount[i]);
		if(testG.supplyCount[i] != G.supplyCount[i]){
			printf("Error,victory and Kindom cards were effected\n");
		}
	}	
	return 0;
}
