#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Tests isGameOver()
int main() {
	int numPlayer = 2; 
	int seed = 1000;
	
	
	//Kingdom cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
			   
    struct gameState* G = malloc(sizeof(struct gameState));
	initializeGame(numPlayer, k, seed, G);
	
	printf("Unit Tests for isGameOver");
	
	//Sets province cards to 0, function should return 1(True) and game should be over
	G->supplyCount[province] = 0;
	int x = isGameOver(G);
	
	if (x == 1) {
		printf("Pass - Province cards empty, game over");
	}
	else {
		printf("Fail - game still playing");
	}
  
  //Sets one non-province to 0, should return 0(False) and game SHOULD NOT be over
   G->supplyCount[province] = 1;
   G->supplyCount[smithy] = 0; 
   x = isGameOver(G);
   
   if(x == 0) {
		printf("Pass - Game should not be over");
	}
	else {
		printf("Fail - Game over");
	}
  
  //Sets two non-province cards to 0, should still return 0(False) and game SHOULD NOT be over
   G->supplyCount[province] = 1;
   G->supplyCount[gardens] = 0; 
   G->supplyCount[mine] = 0;
   x = isGameOver(G);
   
   if(x == 0) {
		printf("Pass - Game should not be over");
	}
	else {
		printf("Fail - Game over");
	}
	
	//Sets three non-province cards to 0, should return 1(True) and game should be over.
	x = isGameOver(G);
   
   if(x == 1) {
		printf("Pass - Game should be over");
	}
	else {
		printf("Fail - Game still going");
	}
	
	
	return 0;
}