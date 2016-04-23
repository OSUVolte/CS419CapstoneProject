#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int compareTest(int, int);

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 4;
	int players[numPlayer];   
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    int testResult=0;
	struct gameState G;
	
	//set game for up to 5 players
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	printf("-------------------UNITTEST4: GETWINNERS--------------------\n");
	//add provinces for each player position
	for( i=0; i<numPlayer; i++){
		G.hand[i][0] = province;
		G.handCount[i]++;
		//printf("new score is: %d\n", scoreFor(i-1, &G));
		getWinners(players, &G);
		printf("Expected Result: Player %d, Actual Result: player %d scored %d\n",i,i,players[i]);
		assert(players[i] ==1);
		testResult += compareTest(players[i] ,1);
	}
	
	printf("\nEvaluating Turn Affect on Winner\n\n");	
	//evaluate winner on turn position
	for( i=0; i<numPlayer; i++){
		printf("new score is: %d\n", scoreFor(i, &G));
		G.whoseTurn= i; 
		getWinners(players, &G);
		printf("Expected Result: Player %d, Actual Result: player %d scored %d\n",i,i,players[i]);
		if(i<numPlayer-1)
			testResult += compareTest(players[i] ,0);
			//assert(players[i] ==0);
		else	
			testResult += compareTest(players[i] ,1);
			//assert(players[i] ==1);
	}
	
		
	//print out results
	if(testResult ==0){
		printf("\nUnit 4 Test Results Passed!\n");		
	}
	else{
		printf("\nUnit 4 Test Failed\n");
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
