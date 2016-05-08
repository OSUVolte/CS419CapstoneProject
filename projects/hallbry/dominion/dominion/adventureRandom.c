/****************************************************************
** Name: AdventureRandom.c
** Author: Bryant Hall
** Date: 5/8/2016
** Description:  A random testing function for the Adventure card. It randomizes a 
players hand, deck and discard pile and then plays the card effect function. It moves on to
evaluate the state of the game after the test. 
************************************************************************/

//Files to include

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Adventurer"

//function defintions
void randomizeGameState(int * numPlayers, int * seed );
void randomizeHand(int player, struct gameState * G, int * choice1); 
void compareTest(int, int, int *, char *);
int numberOfTreasureCards( struct gameState *g, int);


int main() {
	//set up random function
	time_t t; 
	
	srand((unsigned) time(&t));
	//Used to track test results, first number is pass, fail, total 
	int TestResults [3]= {0,0,0}; 
	int p=0,x; 
    int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int numPlayers = 2;
	int oldActions;
	int oldBuys;
	int oldHandcount;
	int oldNumberOfTreasureCards; 
	int numberOfCards; 
  	struct gameState G;
	int k[10] = {adventurer, salvager, village, minion, mine, cutpurse,	sea_hag, tribute, smithy, council_room};
	int trials=10000; 
	
	printf("-------------------RANDOM TEST 2: %s--------------------\n", TESTCARD);
	for(x=0;  x<trials; x++){
		initializeGame(2, k, 1000, &G);
		for(p=0; p<numPlayers; p++){
			randomizeHand(p, &G, &choice1);
			//go through cards in hand
			updateCoins(p, &G, bonus);
			oldNumberOfTreasureCards = numberOfTreasureCards(&G, p);
			oldActions= G.numActions;
			oldHandcount = G.handCount[p];			
			oldBuys = G.numBuys;
			numberOfCards = G.handCount[p] + G.playedCardCount + G.discardCount[p] + G.deckCount[p];
			cardEffect(adventurer, choice1, choice2, choice3, &G, 0, &bonus);
			compareTest(oldNumberOfTreasureCards+2, numberOfTreasureCards(&G, p) ,TestResults, "TreasureCards");
			compareTest(oldBuys, G.numBuys,TestResults,"Buys");
			compareTest(oldActions, G.numActions,TestResults,"Actions");			
			compareTest(oldHandcount+2, G.handCount[p], TestResults, "HandCount");
			compareTest(numberOfCards, (G.handCount[p] + G.playedCardCount + G.discardCount[p] + G.deckCount[p]), TestResults, "Number of Cards");
			endTurn(&G);
		}
	}
	
	//print out results
	printf("\nRandomtest 2 Test Results!\n");
	printf("Tests Passed: %d\n",TestResults[0]);
	printf("Tests Failed: %d\n",TestResults[1]);
	printf("Total Tests: %d\n",TestResults[2]);
	
	printf("--------------------------------------------------\n");	
	return 0;
}


//Randomize gamestate
void randomizeGameState(int * numPlayers, int * seed ){
	*seed = rand() % 5000; 	
	*numPlayers = rand() %2 +2;	
	return; 
}



//randomize number of cards and cards in hand
void randomizeHand(int player, struct gameState * G, int * choice1){
	int i;
	G->handCount[player] = rand() % 5+5;
	G->deckCount[player] = rand() % 15;  //allow deck to be empty 
	G->discardCount[player] = rand() %10 +5;
	
	*choice1 = rand() % (G->handCount[player]);
	for(i=0; i<G->handCount[player]; i++){
		G->hand[player][i] = (rand()%treasure_map);  
	}
	
	//randomize deck 
	for(i=0; i< G->deckCount[player]; i++){
		//printf("Loop Number %d\n",i);
		G->deck[player][i] = (rand()%treasure_map);  	
	}
		
	//randomize discardCount
	for(i=0; i< G->discardCount[player]; i++){
		G->discard[player][i] = (rand()%treasure_map);  //static_cast<CARD>
	}
	
	//make last 2 cards copper to prevent infinite loop
	G->discard[player][0] = copper;
	G->discard[player][1] = copper;		
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



//get number of treasure cards in a players hand
int numberOfTreasureCards( struct gameState *g, int p){
	int i=0;
	int cardDrawn;
	int numTreasureCards=0;
	for (i=0; i< g->handCount[p]; i++){
		cardDrawn = g->hand[p][i];
		if(cardDrawn == copper || cardDrawn == silver|| cardDrawn == gold)
			numTreasureCards++;		
	}
	return numTreasureCards;
}