/********************************************************************
 * Kara Franco
 * cardtest4: council_room() function
 * Due Date: April 24, 2016
 * ****************************************************************/

#include "dominion.h" 
#include <stdio.h>

int main(){

	printf("\n------------------------Card Test 4-----------------------------\n\n");
	printf("---Test council_room()---\n");
	
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
	int buyCheck;

	thisPlayer = G.whoseTurn;
	preHandCount = G.handCount[thisPlayer];
	preDeckCount = G.deckCount[thisPlayer];
	victoryCheck = G.supplyCount[estate] + G.supplyCount[duchy] + G.supplyCount[province];
	buyCheck = G.numBuys + 1;

	// use cardEffect to check for function return value
	printf("Testing that council_room() cardEffect function return value is 0...\n");
	flag = cardEffect(council_room, 0, 0, 0, &G, 0, 0);
	if(flag == 0){
		printf("PASS\n");
	} else {
		printf("FAIL\n");
	}
	
	// council_room() action is take 4 cards and one additional buy

	printf("Testing if council_room() card gave player 4 new cards...\n");
	
	if(G.handCount[thisPlayer] == preHandCount + 4){ 
		printf("PASS\n"); 	
	} 
	else {
		printf("FAIL\n");
		printf("current handCount: %d, previous handCount: %d\n", G.handCount[thisPlayer], preHandCount);
	}
	
	// council_room() action should result in 4 cards missing from the deck 
	printf("Testing if council_room() card removed 4 cards from the deck...\n");
	if(G.deckCount[thisPlayer] == preDeckCount - 4){  
		printf("PASS\n"); 		
	} 
	else {
		printf("FAIL\n");
		printf("current deckCount: %d, previous deckCount: %d\n", G.deckCount[thisPlayer], preDeckCount);
	}
	
	// council_room() action should not effect the victory card pile 
	printf("Testing if council_room() action did not alter victory points...\n");
	if((G.supplyCount[estate] + G.supplyCount[duchy] + G.supplyCount[province]) == victoryCheck){
		printf("PASS\n");
	} 
	else {
		printf("FAIL\n");
		printf("Victory points have been changed\n");
	}
	
	// council_room action should give player 1 extra buy
	printf("Testing if council_room() action gave an extra buy...\n");
	if(G.numBuys == buyCheck){
		printf("PASS\n");
	} 
	else {
		printf("FAIL\n");
		printf("Number of buys is %d\n", G.numBuys);
	}
	


	printf("---council_room() Test Complete---\n\n");
return 0;
}
