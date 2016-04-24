/********************************************************************
 * Kara Franco
 * cardtest2: smithy() function
 * Due Date: April 24, 2016
 * ****************************************************************/

#include "dominion.h" 
#include <stdio.h>

int main(){

	printf("\n------------------------Card Test 2-----------------------------\n\n");
	printf("---Test smithy()---\n");
	
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

	thisPlayer = G.whoseTurn;
	preHandCount = G.handCount[thisPlayer];
	preDeckCount = G.deckCount[thisPlayer];
	victoryCheck = G.supplyCount[estate] + G.supplyCount[duchy] + G.supplyCount[province];
	
	// use cardEffect to check for function return value
	printf("Testing that smithy() cardEffect function return value is 0...\n");
	flag = cardEffect(smithy, 0, 0, 0, &G, 0, 0);
	if(flag == 0){
		printf("PASS\n");
	} else {
		printf("FAIL\n");
	}
	
	// smithy() action is take 3 cards

	printf("Testing if smithy() card gave player 3 new cards...\n");
	
	if(G.handCount[thisPlayer] == preHandCount + 3){ 
		printf("PASS\n"); 	
	} 
	else {
		printf("FAIL\n");
		printf("current handCount: %d, previous handCount: %d\n", G.handCount[thisPlayer], preHandCount);
	}
	
	// smithy() action should result in 3 cards missing from the deck 
	printf("Testing if smithy() card removed 3 cards from the deck...\n");
	if(G.deckCount[thisPlayer] == preDeckCount - 3){  
		printf("PASS\n"); 		
	} 
	else {
		printf("FAIL\n");
		printf("current deckCount: %d, previous deckCount: %d\n", G.deckCount[thisPlayer], preDeckCount);
	}
	
	// smithy() action should not effect the victory card pile 
	printf("Testing if smithy() action did not alter victory points...\n");
	if((G.supplyCount[estate] + G.supplyCount[duchy] + G.supplyCount[province]) == victoryCheck){
		printf("PASS\n");
	} 
	else {
		printf("FAIL\n");
		printf("victory points have been changed\n");
	}
	
	printf("---smithy() Test Complete---\n\n");
return 0;
}
