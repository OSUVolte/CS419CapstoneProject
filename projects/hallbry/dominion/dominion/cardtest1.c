#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

void printMetrics(struct gameState * G, struct gameState * testG,int, int *);
int compareTest(int, int);

int main() {
	
	//adventurer


	int p=0; 
    int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
	int testResult=0;
    int numPlayers = 2;
  	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	
	printf("-------------------CARDTEST1: %s--------------------\n", TESTCARD);
	
	
	printf("Test 0: Basic Test\n");
		memcpy(&testG, &G, sizeof(struct gameState)); 		
		cardEffect(adventurer, choice1, choice2, choice3, &testG, 0, &bonus);
		updateCoins(p, &testG, bonus);
		printMetrics(&G, &testG,p, &testResult);
		
		
	printf("Test 1: Every card is in discard, Need to shuffle cards back in Empty Deck\n");
	//test empty deck
		memcpy(&testG, &G, sizeof(struct gameState)); 

		//test shuffle function works
		//move deck over to discarded

		memcpy(testG.discard[p], testG.deck[p], sizeof(int) * testG.deckCount[p]);
		testG.deckCount[p] =0;
		cardEffect(adventurer, choice1, choice2, choice3, &testG, 0, &bonus);			
		printMetrics(&G, &testG,p, &testResult);	
	
	printf("Test 2: 2 coins on top of deck \n");
	//set deck to action cards, move 2 coins to discard 
		memcpy(&testG, &G, sizeof(struct gameState)); 
		testG.deck[p][testG.deckCount[p]] = copper;
		testG.deck[p][testG.deckCount[p]+1] = copper;
		testG.deckCount[p]++;
	
		printMetrics(&G, &testG,p, &testResult);	
		
	printf("Discard Count %d, expected discardCount: %d", testG.discardCount[p], G.discardCount[p]+1);
		
		
		// evaluate 2 coins added
		
		// check action is -1
		
		// check discard count 
	
	//test regular deck 
	printf("Test 2: coins spread throughout deck \n");
	
		//move deck over to discarded
		
		//test shuffle function works
		
		// evaluate 2 coins added
		
		// check action is -1
		
		// check discard count 
	
	
	
	
	
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



void printMetrics(struct gameState * G, struct gameState *testG, int p, int * testResult){
	//printf("testing123");
	
	printf("New Coin Count: %d,  Expected Coint Count: %d\n", testG->coins, G->coins+2);
	*testResult+= compareTest(testG->coins,G->coins+2 );
	//assert(testG->coins == G->coins+2);
	printf("New Hand Count: %d, Expected Hand Count: %d\n", testG->handCount[p], G->handCount[p]+2);
	*testResult+= compareTest(testG->handCount[p], G->handCount[p]+2 );
	//assert(testG->handCount[p] == G->handCount[p]+2);
	
	printf("Discard Count greater than original %d > %d\n", testG->discardCount[p], G->discardCount[p]);
	*testResult+= compareTest(testG->discardCount[p], G->discardCount[p]);
	//assert(testG->discardCount[p] > G->discardCount[p]);
	printf("Player %d's turn,  Expected Players turn: %d\n", testG->whoseTurn, G->whoseTurn);
	*testResult += compareTest(testG->whoseTurn, G->whoseTurn);
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
