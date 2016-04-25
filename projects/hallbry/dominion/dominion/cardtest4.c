#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "great_hall"
int compareTest(int, int);


int main() {
  	int testResult=0;
	int numPlayers=3; 
	int p,r; 
	int seed = 1000;
	struct gameState G, testG; 
	int bonus =0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, great_hall};
	
	int choice1=0, choice2=0, choice3 =0;
  
	printf("-------------------CARDTEST4: great_hall--------------------\n");
	
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
 
	memcpy(&testG, &G, sizeof(struct gameState));
	
	//evaluate +1 card +1 action
	for(p=0; p<numPlayers; p++){
		//copy gamestate to copy
		memcpy(&testG, &G, sizeof(struct gameState));
		printf("\nPlayer %d\n", p);		
		
		r= cardEffect(great_hall, choice1, choice2, choice3, &testG, 0, &bonus);		
		printf("New Deck Count: %d,  Expected Deck Count: %d\n", testG.deckCount[p], G.deckCount[p]-1);	
		//assert (testG.deckCount[p] == G.deckCount[p]-1 ); //deck count 
		testResult += compareTest( testG.deckCount[p], G.deckCount[p]-1);
		
		printf("new HandCount: %d,  Expected HandCount: %d\n", testG.handCount[p], G.handCount[p]); 		
		//assert ( testG.handCount[p] == G.handCount[p]); //hand count 
		testResult += compareTest( testG.handCount[p], G.handCount[p]);
		
		printf("New Played Card Count:  %d,  Expected Played Card Count: %d\n", testG.playedCardCount, G.playedCardCount+1);	
		//assert (testG.playedCardCount == G.playedCardCount+1);  //played card 
		testResult += compareTest(testG.playedCardCount, G.playedCardCount+1);
		
		printf("Number of Actions: %d, Expected Actions:%d\n", testG.numActions, G.numActions+1);		
		//assert (  testG.numActions == G.numActions+1);
		testResult += compareTest(testG.numActions, G.numActions+1);
		
		printf("Number of Buys: %d, Expected number of Buys:%d\n", G.numBuys, testG.numBuys);
		//assert ( G.numBuys == testG.numBuys);
		testResult += compareTest(G.numBuys, testG.numBuys);		
			
		printf("Expected Return Value from card effect: %d, Actual Value: %d\n", 0, r);	
		testResult += compareTest( r,0);	
		
		G.whoseTurn++;
	}
	
	
	//evaluate plus 2 actions 
		//print out results
	if(testResult ==0){
		printf("\nCardtest 4 Test Passed!\n");		
	}
	else{
		printf("\nCardtest 4 Test Failed\n");
	}	
	printf("--------------------------------------------------\n");	 
 
	return 0;
 
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

