/*
	Rosa Tung
	CS362
	(20 points) Write unit tests for four functions (not card implementations or cardEffect) in dominion.c. 
	Check these tests in as unittest1.c,unittest2.c, unittest3.c, and unittest4.c. 
	(for example, you can create a test for updateCoins() method)
	
	Testing:
		int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state);
*/

#include "dominion.h" 

#include <stdio.h> //printf scanf

int main(){
	//create gameState object, hand, and flag for function state
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	int flag;
	int numPlayers;
	
	printf("---Testing initializeGame function START---\n\n");
	
	for(numPlayers = 2; numPlayers <= MAX_PLAYERS; numPlayers++){
		printf("Initialize Game...\n");
		printf("	Testing %d players...\n", numPlayers);
		flag = initializeGame(2, k, 4, &G);
		if (flag == 0){
			printf("		SUCCESS\n");
		}
		else{
			printf("		FAILURE\n");	
		}		
	}

	printf("\n---Testing initializeGame function COMPLETE---\n\n");
	
	return 0;
}