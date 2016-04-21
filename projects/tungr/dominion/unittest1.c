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
	
	//go through 2-4 players and attempt to initialize the game 
	for(numPlayers = 2; numPlayers <= MAX_PLAYERS; numPlayers++){
		printf("Initialize Game...\n");
		printf("	Testing gameState for %d players...\n", numPlayers);
		flag = initializeGame(numPlayers, k, 4, &G);
		if (flag == 0){
			printf("		Function succeeded including all below\n");
			printf("			1. correct number of players\n");
			printf("			2. selected kingdom cards are different\n");
			printf("			3. deck is shuffled\n");
		} else{
			printf("		Function failed for one or more below\n");	
			printf("			1. incorrect number of players\n");
			printf("			2. selected kingdom cards are not different\n");
			printf("			3. deck is not shuffled\n");
		}		
		if(G.numPlayers = numPlayers){
			printf("		Correct Number of Players\n");
		} else {
			printf("		Incorrect Number of Players\n");
		} //kingdom cards has -1 return value
		if(G.supplyCount[curse] == (numPlayers-1)*10){
			printf("		Correct # of Curse Cards\n");
		} else {
			printf("		Incorrect # of Curse Cards\n");
		}
		if(numPlayers == 2){
			if(G.supplyCount[estate] == 8){
				printf("		Correct # of Estate cards\n");
			} else {
				printf("		Incorrect # of Estate Cards\n");
			}
			if(G.supplyCount[duchy] == 8){
				printf("		Correct # of Duchy cards\n");
			} else {
				printf("		Incorrect # of Duchy Cards\n");	
			}
			if(G.supplyCount[province] = 8){
				printf("		Correct # of Province cards\n");
			} else {
				printf("		Incorrect # of Province Cards\n");
			}
		}
		if(numPlayers != 2){
			if(G.supplyCount[estate] == 12){
				printf("		Correct # of Estate cards\n");
			} else {
				printf("		Incorrect # of Estate Cards\n");
			}
			if(G.supplyCount[duchy] == 12){
				printf("		Correct # of Duchy cards\n");
			} else {
				printf("		Incorrect # of Duchy Cards\n");	
			}
			if(G.supplyCount[province] = 12){
				printf("		Correct # of Province cards\n");
			} else {
				printf("		Incorrect # of Province Cards\n");
			}			
		}
		if(G.supplyCount[copper] == 60 - (7 * numPlayers)){
			printf("		Correct # copper cards\n");
		} else {
			printf("		Incorrect # copper cards\n");
		}
		if(G.supplyCount[silver] == 40){
			printf("		Correct # silver cards\n");
		} else {
			printf("		Incorrect # silver cards\n");
		}
		if(G.supplyCount[gold] == 30){
			printf("		Correct # gold cards\n");
		} else {
			printf("		Incorrect # gold cards\n");
		}
		if(G.handCount[G.whoseTurn] == 5){
			printf("		Correct Cards in currentPlayers Hand\n");
		} else {
			printf("		Incorrect Cards in currentPlayers Hand\n");
		}
		if(G.deckCount[G.whoseTurn] == 5){
			printf("		Correct Cards in currentPlayers Deck\n\n");
		} else {
			printf("		Incorrect Cards in currentPlayers Deck\n\n");
		}
	}

	printf("\n---Testing initializeGame function COMPLETE---\n\n\n\n");
	
	return 0;
}

