/*
	Rosa Tung
	CS362
	(20 points) Write unit tests for four Dominion cards implemented in dominion.c.  
	These tests should be checked in as cardtest1.c, cardtest2.c,cardtest3.c, and cardtest4.c. 
	(For example, create a test for smithy card.). It is mandatory to test smithy and adventurer card.

	Testing:
		adventurer card
		int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);
			playAdventurer(state);
*/

#include "dominion.h" 
#include "dominion_helpers.h" 

#include <string.h> 
#include <stdio.h> //printf scanf
#include <assert.h> 
#include <stdlib.h> //free malloc

int main(){
	//make new game 
	struct gameState G;

	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	int flag;
	int currentPlayer; 
	int baseHandCount;
	int baseDeckCount;	
	
	printf("---Testing Adventurer Card START---\n\n");
	
	printf("Initialize Game...\n");
	initializeGame(2, k, 4, &G);	
	
	currentPlayer = G.whoseTurn;
	baseHandCount = G.handCount[currentPlayer];
	baseDeckCount = G.deckCount[currentPlayer];
	
	printf("currentPlayer: %d\n", currentPlayer);
	printf("baseHandCount: %d\n", baseHandCount);
	printf("baseDeckCount: %d\n", baseDeckCount);

	//check for function execution
	printf("Testing adventurer cardEffect function return value...\n");
	flag = cardEffect(adventurer, 0, 0, 0, &G, 0, 0);
	if(flag == -1){
		printf("	PASS\n");
	} else {
		printf("	FAIL\n");
	}	
	
	printf("currentPlayer: %d\n", currentPlayer);
	printf("baseHandCount: %d\n", G.handCount[currentPlayer]);
	printf("baseDeckCount: %d\n", G.deckCount[currentPlayer]);
	
	printf("---Testing Adventurer Card COMPLETE---\n\n\n\n");
	return 0;
}