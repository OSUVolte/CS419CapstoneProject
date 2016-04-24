#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"
int compareTest(int, int);

int main() {
  	int numPlayers=3; 
	int p,r; 
	int seed = 1000;
	struct gameState G, testG; 
	int bonus =0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	int choice1=0, choice2=0, choice3 =0;
	int testResult =0;
	//smithy
	printf("-------------------CARDTEST2: SMITHY--------------------\n");
	//evaluate 3 cards added to hand, deck has 3 fewer cards
	

	
	//check smity card is in discard
	
	r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
 
	memcpy(&testG, &G, sizeof(struct gameState));
	
	for(p=0; p<numPlayers; p++){
		//copy gamestate to copy
		memcpy(&testG, &G, sizeof(struct gameState));
		printf("\nPlayer %d\n", p);

		//set card to smithy
		testG.hand[p][0]= smithy; 
				
		r= cardEffect(smithy, choice1, choice2, choice3, &testG, 0, &bonus);		
		
		printf("New Deck Count: %d,  Expected Deck Count: %d\n", testG.deckCount[p], G.deckCount[p]-3);			
		testResult += compareTest(G.deckCount[p]-3 , testG.deckCount[p]);
		
		printf("new HandCount: %d,  Expected HandCount: %d\n", testG.handCount[p], G.handCount[p]+2);  //discard 1 card			
		testResult += compareTest(testG.handCount[p] , G.handCount[p]+2);
		
		printf("New Played Card Count:  %d,  Expected Played Card Count: %d\n", testG.playedCardCount, G.playedCardCount+1);		
		testResult += compareTest(testG.playedCardCount, G.playedCardCount+1);
		
		printf("Number of Buys: %d, Expected number of Buys:%d\n", G.numBuys, testG.numBuys);				
		testResult += compareTest( G.numBuys , testG.numBuys);
		
		printf("Expected Return Value from card effect: %d, Actual Value: %d\n", 0, r);	
		testResult += compareTest( r,0);
		
		//printf("Original Player Turn: %d, Current Player Turn: %d\n");
		printf("Expected Players Turn: %d, actual players turn:%d", G.whoseTurn, testG.whoseTurn);
		testResult += compareTest(G.whoseTurn, testG.whoseTurn);
		
		printf("Number of Actions: %d, Expected Actions:%d\n", testG.numActions, G.numActions);
		testResult += compareTest(testG.numActions, G.numActions);
		
		G.whoseTurn++;
	}
	
	//print out results
	if(testResult ==0){
		printf("\nCardtest 2 Test Passed!\n");		
	}
	else{
		printf("\nCardtest 2 Test Failed\n");
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
