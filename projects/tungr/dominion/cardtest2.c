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
	
	int currentPlayer = whoseTurn(&G);
	int baseHandCount = G.handCount[currentPlayer];
	
	printf("---Testing Adventurer Card START---\n\n");
	
	printf("Initialize Game...\n");
	flag = initializeGame(2, k, 2, &G);
	
	printf("Testing Adventurer cardEffect function return value...\n");
	flag = cardEffect(adventurer, copper, silver, gold, &G, 1, 0);
	if(flag == -1){
		printf("	PASS\n");
	} else {
		printf("	FAIL\n");
	}
	
	printf("Testing playAdventurer function return value...\n");
	flag = playAdventurer(&G);
	if(flag == 0){
		printf("	PASS\n");
	} else {
		printf("	FAIL\n");
	}
	printf("Testing adventurer action...\n");
	if(G.handCount[currentPlayer] = baseHandCount + 2){
		printf("	PASS\n\n"); 
	} else {
		printf("	FAIL\n\n");
		printf("		Wrong Number of Cards being added.\n\n");
	}
	
	printf("---Testing Adventurer Card COMPLETE---\n\n\n\n");
	return 0;
}