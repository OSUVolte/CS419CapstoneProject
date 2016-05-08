/*********************************************************************************************
** Name: randomtestcard.c
** Author: Bryant Hall
** Date: 5/8/2016
** Description:  A random testing function for the Salvager card. It randomizes a 
players hand, deck and discard pile and then plays the card effect function. It moves on to
evaluate the state of the game after the test. 
*********************************************************************************************/

//Files to include
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Salvager"

//function definitions
void randomizeGameState(int * numPlayers, int * seed );
void randomizeHand(int player, struct gameState * G, int * choice1); 
void compareTest(int, int, int *, char *);

int main() {	
	time_t t;	
	srand((unsigned) time(&t));
	//Used to track test results, first number is pass, fail, total 
	int TestResults [3]= {0,0,0};  
	int p=0,x; 
    int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int numPlayers = 2;
	int oldActions;
	int oldBuys;
	int expectedCoins;
	int oldHandcount;
	int oldPlayedCardCount; 
  	struct gameState G;
	int k[10] = {adventurer, salvager, village, minion, mine, cutpurse,	sea_hag, tribute, smithy, council_room};
	int trials=10000; 
	
	printf("-------------------RANDOM TEST1: %s--------------------\n", TESTCARD);
	//main loop for number of trials
	for(x=0;  x<trials; x++){
		initializeGame(2, k, 1000, &G);
		//iterate through each player 
		for(p=0; p<numPlayers; p++){
			//set hand 
			randomizeHand(p, &G, &choice1);
			
			//go through cards in hand
			updateCoins(p, &G, bonus);
			
			//record old values before card effect 
			oldActions= G.numActions;
			oldHandcount = G.handCount[p];
			oldPlayedCardCount = G.playedCardCount;
			expectedCoins =  G.coins +  getCost( handCard(choice1, &G)) ;
			oldBuys = G.numBuys;
			cardEffect(salvager, choice1, choice2, choice3, &G, 0, &bonus);
			
			//run tests on new cards 
			compareTest(expectedCoins,G.coins,TestResults, "Coins");
			compareTest(oldBuys+1, G.numBuys,TestResults,"Buys");
			compareTest(oldPlayedCardCount+1, G.playedCardCount,TestResults, "Played Cards");
			compareTest(oldHandcount-2, G.handCount[p],TestResults, "HandCount");
			compareTest(oldActions, G.numActions,TestResults,"Actions");			
			endTurn(&G);
		}
	}
	
	//print out results
	printf("\nCardtest 1 Test Results!\n");
	printf("Tests Passed: %d\n",TestResults[0]);
	printf("Tests Failed: %d\n",TestResults[1]);
	printf("Total Tests: %d\n",TestResults[2]);
	printf("--------------------------------------------------\n");	
	return 0;
}



//randomize gamestate 
void randomizeGameState(int * numPlayers, int * seed ){
	*seed = rand() % 5000; 	
	*numPlayers = rand() %4 +1;	
	return; 
}



//randomize number of cards and cards in hand
void randomizeHand(int player, struct gameState * G, int * choice1){
	int i;
	G->handCount[player] = rand() % 5+5; 
	*choice1 = rand() % (G->handCount[player]);
	for(i=0; i<G->handCount[player]; i++){
		G->hand[player][i] = (rand()%treasure_map);  //static_cast<CARD>
	}
	return; 
}

//function to compare results of tests. Uses if statements to evaluate if test past, failed and incrments result
//in array.Finally increments the number of tests taken  
void compareTest(int a, int b, int * testResult,char * variableName){
	if(a == b){
		testResult[0]++;
	}
	else{
		testResult[1]++;
		printf("FAILED!\n");
		printf("Testing %s:  Expected number of %s: %d, Actual Number of %s: %d\n",variableName,variableName,a,variableName,b);
	}	
	testResult[2]++;
}
