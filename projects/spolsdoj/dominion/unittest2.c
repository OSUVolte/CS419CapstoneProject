#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(int argc, char* argv[]){
	int i;
	int seed = 100;
	int numPlayer = 2;
	int maxBonus = 10;
	int p, r, handCount;
	int bonus;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	struct gameState G;
	int maxHandCount = 5;

	int coppers[MAX_HAND];
	int silvers[MAX_HAND];
	int golds[MAX_HAND];

	for(i=0; i<MAX_HAND; i++){
		coppers[i] = copper;
		silvers[i] = silver;
		golds[i] = gold;
	}

	printf("Testing updateCoins.\n");
	
	for(p=0; p < numPlayer; p++){
		for(handCount = 1; handCount <= maxHandCount; handCount++){
			for(bonus = 0; bonus <= maxBonus; bonus++){
				memset(&G, 23, sizeof(struct gameState));
				r = initializeGame(numPlayer, k, seed, &G);
				G.handCount[p] = handCount;
				memcpy(G.hand[p], coppers, sizeof(int) * handCount);
				updateCoins(p, &G, bonus);
		
				if(G.coins == handCount * 1 + bonus){
					printf("  updateCoins(): PASS with G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
				}
				else
					printf("  updateCoins(): FAILED\n");

				memcpy(G.hand[p], silvers, sizeof(int) * handCount);
				updateCoins(p, &G, bonus);

				if(G.coins == handCount * 2 + bonus){
					printf("  updateCoins(): PASS with G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus); 
				}
				else
					printf("  updateCoins(): FAILED\n");

				memcpy(G.hand[p], golds, sizeof(int) * handCount);
				updateCoins(p, &G, bonus);

				if(G.coins == handCount * 3 + bonus){
					printf("  updateCoins(): PASS with G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus); 
				}
				else
					printf("  updateCoins(): FAILED\n");
			}
		} 
	}	
	
	printf("Test complete.\n"); 

	return 0;
}
