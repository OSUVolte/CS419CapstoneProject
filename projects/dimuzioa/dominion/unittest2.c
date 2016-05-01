#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int numPlayer = 2; 
	int seed = 1000;
	int playerNum = 1;
	
	
	//Kingdom cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
			   
    struct gameState* G = malloc(sizeof(struct gameState));
	initializeGame(numPlayer, k, seed, G);
	
	printf("Unit Tests for updateCoins");
	
	//Update coins with no cards
	G->handCount[playerNum] = 0;

	updateCoins(playerNum, G, 0);
		if (G->coins == 0) { 
			printf("Pass - Coins should be 0"); 
		} 
		else { 
			printf("Fail"); 
		}
		
		
	//Update coins with no cards, but a bonus
	G->handCount[playerNum] = 0;

	updateCoins(playerNum, G, 2);
		if (G->coins == 2) { 
			printf("Pass - Coins should be 2"); 
		} 
		else { 
			printf("Fail"); 
		}
		
	//Update coins with copper cards in hand
	G->handCount[playerNum] = 0;
	int x;
	for (x = 0; x <= 2; x++) {
		G->hand[playerNum][x] = 4;
		updateCoins(playerNum, G, 0);
		if (G->coins == (x * 1)) { 
			printf("Pass - Copper calculated correctly"); 
		} 
		else { 
			printf("Fail - Copper calculated incorrectly"); 
		}
 
	}
	
	
	return 0;
}