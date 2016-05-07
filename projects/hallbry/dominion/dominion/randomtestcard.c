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
	
  	struct gameState G, testG;
	int k[10] = {adventurer, salvager, village, minion, mine, cutpurse,	sea_hag, tribute, smithy, council_room};
	int trials=1; 
	//need to randomize seed, choice 0-4, numbuys, number of players 


	printf("-------------------RANDOM TEST1: %s--------------------\n", TESTCARD);
	for(x=0;  x<trials; x++){
		//randomizeGameState(&numPlayers, &seed);
		initializeGame(2, k, 1000, &G);
		memcpy(&testG, &G, sizeof(struct gameState)); 
		printf("Trial: %d\n", x);	
		for(p=0; p<numPlayers; p++){
			
			//printf("\nTest\n");
			randomizeHand(p, &testG, &choice1);
			//go through cards in hand
			//updateCoins(p, &testG, bonus);
			coinValue=  getCost(testG.hand[p][choice1]) + testG.coins ;
			cardEffect(salvager, choice1, choice2, choice3, &testG, 0, &bonus);
			
					//test coins					
			printf("Player %d Testing Coins:  Expected number of coins: %d, Actual Number of Coins:%d\n",p,  coinValue,testG.coins); 
			testResult += compareTest(coinValue,testG.coins);
		    
			printf("Testing Buys:  Expected number of Buys: %d, Actual Number of Buys: %d\n",G.numBuys+1, testG.numBuys); 
			testResult += compareTest(testG.numBuys, G.numBuys+1);
			endTurn(&testG);
			
			printf("Testing DiscardCount:  Expected number of DiscardCount: %d, Actual Number of DiscardCount: %d\n",G.discardCount[p]+1,testG.discardCount[p]); 
			testResult += compareTest(testG.discardCount[p], G.discardCount[p]);
			/*
			printf("Testing Actions:  Expected number of Actions: %d, Actual Number of ACtions: %d",G.numActions ,testG.numActions);
			testResult += compareTest(testG.numActions, G.numActions);		
			*/
			endTurn(&testG);
		}
		
	}
	
	
	

	
	
	
	
	
		
	//print out results
	if(testResult ==0){
		printf("\nCardtest 1 Test Passed!\n");		
	}
	else{
		printf("\nCardtest1 Test Failed\n");
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

void randomizeHand(int player, struct gameState * G, int * choice1){
	int i;
	G->handCount[player] = rand() % 10+1; 
	//printf("Player hand count: %d\n", G->handCount[player]);
	*choice1 = rand() % G->handCount[player];
	for(i=0; i<G->handCount[player]; i++){
		//printf("Random Card %d\n", i);
		G->hand[player][i] = (rand()%treasure_map);  //static_cast<CARD>
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
