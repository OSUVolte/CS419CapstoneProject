/********************************************************************
 * Kara Franco
 * unittest3: isGameOver() function
 * Due Date: April 24, 2016
 * ****************************************************************/

#include "dominion.h"
#include <stdio.h>
#include <stdlib.h> //malloc/free

int main(){

	printf("\n------------------------Unit Test 3-----------------------------\n\n");
	printf("---Test isGameOver()---\n");

	// create a game to test
  	struct gameState* state = malloc(sizeof(struct gameState));
  	int cards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	printf("Initialize Game...\n");
	initializeGame(2, cards, 10, state);
	
	// the game ends when there are no Province Cards in supply
	// first we will test if the game ends prematurely with any cards remaining
	printf("Testing if returns 0 (false) if there are cards remaining (including Province Cards)...\n");
  	int i;
  	for (i = 0; i <= state->supplyCount[treasure_map]; i++) {
    		state->supplyCount[i] = 1;
  	}

 	int r = isGameOver(state);
  	if (r == 0) {
    		printf("PASS\n");
  	}
  	else {
    		printf("FAIL\n");
  	}
	
	// next we test if the game stays in session when a non-Province card is empty
	printf("Testing if returns 0 (false) if a non-Province card supply count is empty...\n");
  
	state->supplyCount[province] = 1;
  	state->supplyCount[curse] = 0;

	r = isGameOver(state);
  	if (r == 0) {
    		printf("PASS\n");
  	}
  	else {
    		printf("FAIL\n");
  	}
	
	printf("Testing if returns 1 (true) if three non-Province cards are empty...\n"); 
	state->supplyCount[province] = 1;
  	state->supplyCount[curse] = 0;
  	state->supplyCount[treasure_map] = 0; 
 	state->supplyCount[smithy] = 0;

  	r = isGameOver(state);
  	if (r == 1) {
    		printf("PASS\n");
  	}
  	else {
    		printf("FAIL\n");
  	}
  	
	// lastly, we test if the game does end when there are no Province cards left
	printf("Testing if returns 1 (true) if there are no Province Cards...\n");
  	
  	state->supplyCount[province] = 0;

  	r = isGameOver(state);
  	if (r == 1) {
    		printf("PASS\n");
  	}
  	else {
    		printf("FAIL\n");
  	}

	printf("---isGameOver() Test Complete---\n\n");
	  
	// clean up
  	free(state);

  return 0;
}
