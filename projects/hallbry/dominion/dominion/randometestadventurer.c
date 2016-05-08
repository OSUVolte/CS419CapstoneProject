#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Salvager"

void randomizeGameState(int * numPlayers, int * seed );
void randomizeHand(int player, struct gameState * G, int * choice1); 
int compareTest(int, int);

int main() {
	
	
	
	time_t t; 
	
	srand((unsigned) time(&t));
	int coinValue=0;
	int p=0,x; 
    int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
	int testResult=0;
    int numPlayers = 2;
	int oldActions;
	int oldBuys;
	int expectedCoins;
	int oldHandcount;
	int oldPlayedCardCount; 
  	struct gameState G;
	int k[10] = {adventurer, salvager, village, minion, mine, cutpurse,	sea_hag, tribute, smithy, council_room};
	int trials=5; 
	//need to randomize seed, choice 0-4, numbuys, number of players 


	printf("-------------------RANDOM TEST1: %s--------------------\n", TESTCARD);
	for(x=0;  x<trials; x++){
		//randomizeGameState(&numPlayers, &seed);
		initializeGame(2, k, 1000, &G);
		//memcpy(&testG, &G, sizeof(struct gameState)); 
		printf("Trial: %d\n", x);	
		for(p=0; p<numPlayers; p++){
			
			//printf("\nTest\n");
			randomizeHand(p, &G, &choice1);
			//go through cards in hand
			updateCoins(p, &G, bonus);
			oldActions= G.numActions;
			oldHandcount = G.handCount[p];
			oldPlayedCardCount = G.playedCardCount;
			expectedCoins =  G.coins +  getCost( handCard(choice1, &G)) ;
			oldBuys = G.numBuys;
			cardEffect(adventurer, choice1, choice2, choice3, &G, 0, &bonus);
			
			printf("Player %d \n", p);
			//test coins					
			printf("Testing Coins:  Expected number of coins: %d, Actual Number of Coins:%d\n", expectedCoins, G.coins); 
			testResult += compareTest(expectedCoins,G.coins);
		    
			printf("Testing Buys:  Expected number of Buys: %d, Actual Number of Buys: %d\n", oldBuys+1, G.numBuys); 
			testResult += compareTest(oldBuys+1, G.numBuys);
			
			
			
			printf("Testing Played Card Count:  Expected number of PlayedCount: %d, Actual Number of Played Card Count: %d\n",oldPlayedCardCount+1, G.playedCardCount); 
			testResult += compareTest(oldPlayedCardCount+1, G.playedCardCount);
			
			printf("Testing HandCount:  Expected HandCount: %d, Actual HandCount: %d\n",oldHandcount-2, G.handCount[p]); 
			testResult += compareTest(oldHandcount-2, G.handCount[p]);
			
			
			printf("Testing Actions:  Expected number of Actions: %d, Actual Number of ACtions: %d",oldActions, G.numActions);
			testResult += compareTest(oldActions, G.numActions);		
			
			endTurn(&G);
		}
		
	}
	
	
	

	
	
	
	
	
		
	//print out results
	if(testResult ==0){
		printf("\nRandom 2 Test Passed!\n");		
	}
	else{
		printf("\nRandom 2 Test Failed\n");
	}
	
	printf("--------------------------------------------------\n");	
	
	
	
	return 0;
}



void randomizeGameState(int * numPlayers, int * seed ){
	*seed = rand() % 5000; 	
	*numPlayers = rand() %4 +1;	
	return; 
}



//randomize number of cards and cards in hand
// set deck to curse cards 
// add two money cards to deck in random spot 
//

void randomizeHand(int player, struct gameState * G){
	int i;
	int treasureIndex; 
	G->deckCount[player] = rand() % 15+5; 
	
	//randomize cards in hand 
	for(i=0; i<G->handCount[player]; i++){
		//printf("Random Card %d\n", i);
		G->deck[player][i] = (rand()%treasure_map);  //static_cast<CARD>
	}
	//add two treasure coins in random spot 
	treasureIndex = rand() %20; 
	if(treasureIndex<20 && treasureIndex > 0){
		G->deck[player][treasureIndex] = copper; 
		G->deck[player][treasureIndex+1] = copper; 
	}
	//0 scenario
	else if(treasureIndex<20){
		G->deck[player][treasureIndex] = copper; 
		G->deck[player][treasureIndex+1] = copper; 
	}
	//20 scenario 
	else{
		G->deck[player][treasureIndex] = copper; 
		G->deck[player][treasureIndex-1] = copper; 
	}
	
	
	return; 
}


int compareTest(int a, int b){
	if(a == b){
		printf("PASSED!\n");
		return 0; 	
	}
	else{
		printf("FAILED!\n");
		return 1;		
	}	
}
