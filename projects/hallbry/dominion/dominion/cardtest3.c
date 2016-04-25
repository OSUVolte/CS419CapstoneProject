
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

int compareTest(int, int);

int main() {
  
	//used to record original number of cards in hand, deck and discard 

	
	
	int numPlayers=3; 
	int p,r; 
	int seed = 1000;
	struct gameState G, testG; 
	int bonus =0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int testResult;
	int choice1=0, choice2=0, choice3 =0;
  
	
	printf("-------------------CARDTEST3: Village--------------------\n");	
	
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
 
	memcpy(&testG, &G, sizeof(struct gameState));
	
	//evaluate +1 card
	for(p=0; p<numPlayers; p++){
		//copy gamestate to copy
		memcpy(&testG, &G, sizeof(struct gameState));
		printf("\nPlayer %d\n", p);		
		
		r= cardEffect(village, choice1, choice2, choice3, &testG, 0, &bonus);
		
		printf("New Deck Count: %d,  Expected Deck Count: %d\n", testG.deckCount[p], G.deckCount[p]-1);		
		//assert (testG.deckCount[p] == G.deckCount[p]-1 ); //deck count 
		testResult += compareTest(testG.deckCount[p], G.deckCount[p]-1);
		
		printf("new HandCount: %d,  Expected HandCount: %d\n", testG.handCount[p], G.handCount[p]); 
		//assert ( testG.handCount[p] == G.handCount[p]); //hand count 
		testResult += compareTest(testG.handCount[p], G.handCount[p]);
		
		printf("New Played Card Count:  %d,  Expected Played Card Count: %d\n", testG.playedCardCount, G.playedCardCount+1);
		//assert (testG.playedCardCount == G.playedCardCount+1);  //played card 
		testResult += compareTest(testG.playedCardCount, G.playedCardCount+1);
		
		printf("Number of Actions: %d, Expected Actions:%d\n", testG.numActions, G.numActions+2);
		testResult += compareTest(testG.numActions, G.numActions+2);
		
		
		printf("Number of Buys: %d, Expected number of Buys:%d\n", G.numBuys, testG.numBuys);
		//assert ( G.numBuys == testG.numBuys);
		testResult += compareTest(G.numBuys , testG.numBuys);
		
		printf("Expected Players Turn: %d, actual players turn:%d", G.whoseTurn, testG.whoseTurn);
		testResult += compareTest(G.whoseTurn, testG.whoseTurn);
		
		
		printf("Expected Return Value from card effect: %d, Actual Value: %d\n", 0, r);	
		testResult += compareTest( r,0);		
		G.whoseTurn++;
	}
	
	
	//print out results
	if(testResult ==0){
		printf("\nCardtest 3 Test Passed!\n");		
	}
	else{
		printf("\nCardtest 3 Test Failed\n");
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

