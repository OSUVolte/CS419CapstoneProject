/********************************************************************
 * Kara Franco
 * cardtest3: village() function
 * Due Date: April 24, 2016
 * ****************************************************************/

#include "dominion.h" 
#include <stdio.h>

int main(){

	printf("\n------------------------Card Test 3-----------------------------\n\n");
	printf("---Test village()---\n");
	
	// create a game to test 
	struct gameState G;

	int cards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	printf("Initialize Game...\n");
	initializeGame(2, cards, 10, &G);	
	// set up variables to track cards and players
	int flag;
	int thisPlayer; 
	int preHandCount;
	int preDeckCount;	
	int victoryCheck;
	int actionCheck;

	thisPlayer = G.whoseTurn;
	preHandCount = G.handCount[thisPlayer];
	preDeckCount = G.deckCount[thisPlayer];
	actionCheck = G.numActions + 2;
	victoryCheck = G.supplyCount[estate] + G.supplyCount[duchy] + G.supplyCount[province];
	
	// use cardEffect to check for function return value
	printf("Testing that village() cardEffect function return value is 0...\n");
	flag = cardEffect(village, 0, 0, 0, &G, 0, 0);
	if(flag == 0){
		printf("PASS\n");
	} else {
		printf("FAIL\n");
	}
	
	// village() action is take 1 card and get 2 actions

	printf("Testing if village() card gave player 1 new card...\n");
	
	if(G.handCount[thisPlayer] == preHandCount + 1){ 
		printf("PASS\n"); 	
	} 
	else {
		printf("FAIL\n");
		printf("current handCount: %d, previous handCount: %d\n", G.handCount[thisPlayer], preHandCount);
	}
	
	// village() action should result in 1 card missing from the deck 
	printf("Testing if village() card removed 1 card from the deck...\n");
	if(G.deckCount[thisPlayer] == preDeckCount - 1){  
		printf("PASS\n"); 		
	} 
	else {
		printf("FAIL\n");
		printf("current deckCount: %d, previous deckCount: %d\n", G.deckCount[thisPlayer], preDeckCount);
	}
	
	// village() action should not effect the victory card pile 
	printf("Testing if village() action did not alter victory points...\n");
	if((G.supplyCount[estate] + G.supplyCount[duchy] + G.supplyCount[province]) == victoryCheck){
		printf("PASS\n");
	} 
	else {
		printf("FAIL\n");
		printf("Victory points have been changed\n");
	}
	
	// village() action should give player 2 actions
	printf("Testing if village() gave 2 actions...\n");
	if(G.numActions == actionCheck){
		printf("PASS\n");
	} 
	else {
		printf("FAIL\n");
		printf("Player received %d actions\n", G.numActions);
	}


	printf("---village() Test Complete---\n\n");
return 0;
}
