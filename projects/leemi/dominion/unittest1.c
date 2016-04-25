#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>


void testUpdateCoins(){
	int numPlayers = 2;
	int seed = 500;
	int k[10] = {adventurer, village, mine, smithy,
		remodel, feast, great_hall, gardens, embargo, minion}; 
	struct gameState game;
	int coppers[MAX_HAND], silvers[MAX_HAND], golds[MAX_HAND];
	int maxHand = 5, maxBonus=10;	

	int i, p, h, b, g;
	for (i=0; i<MAX_HAND; i++){
		coppers[i] = copper;
		silvers[i] = silver;
		golds[i] = gold;
	}

	printf("=========Testing updateCoins=========\n");

	for (p = 0; p< numPlayers; p++){
		for (h = 0; h < maxHand; h++){
			for(b = 0; b < maxBonus; b++){
			//	printf("Testing player %d with %d treasure cards and %d bonus. \n", p,h,b);				
				
				memset(&game, 23, sizeof(struct gameState));//clear gamestate
				g = initializeGame(numPlayers, k, seed, &game);//initialize
				game.handCount[p] = h;//set handcount
				
				memcpy(game.hand[p], coppers, sizeof(int) * h);//set all to copper
				updateCoins(p, &game, b);//call function updateCoins		
			//	printf("game.coins = %d, expected %d\n", game.coins, h * 1 + b);
				assert(game.coins == h* 1 + b);//test

				memcpy(game.hand[p], silvers, sizeof(int) * h);//set all to silver
				updateCoins(p, &game, b);//call function updateCoins		
			//	printf("game.coins = %d, expected %d\n", game.coins, h * 1 + b);
				assert(game.coins == h* 2 + b);//test

				memcpy(game.hand[p], golds, sizeof(int) * h);//set all to gold
				updateCoins(p, &game, b);//call function updateCoins		
			//	printf("game.coins = %d, expected %d\n", game.coins, h * 1 + b);
				assert(game.coins == h* 3 + b);//test

			}
		}
	}
}
int main(){
	testUpdateCoins();
	return 0;
}


