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
	int t, r;
	int bonus;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	struct gameState G;
	int maxHandCount = 5;

	int supplyPos = 0;

	printf("Testing buyCard.\n");
		 r = initializeGame(numPlayer, k, seed, &G);

		 // test when numBuy is 0
		 G.numBuys = 0;
		 t = buyCard(supplyPos, &G);
		 if(t == -1){
		 	printf("  buyCard(): PASS with numBuys = 0\n"); 	
		 }
		 else
		 	printf("  buyCard(): FAILED\n");

		 G.numBuys = 2;
		 G.supplyCount[0] = 0;
		 t = buyCard(supplyPos, &G);
		 if(t == -1){
		 	printf("  buyCard(): PASS with supplyCount = 0\n"); 	
		 }
		 else
		 	printf("  buyCard(): FAILED\n");

		 G.numBuys = 1;
		 G.supplyCount[0] = 1;
		 G.coins = 0;
		 supplyPos = 1;		 
		 t = buyCard(supplyPos, &G);
		 if(t == -1){
		 	printf("  buyCard(): PASS with G.coins = 0\n"); 	
		 }
		 else
		 	printf("  buyCard(): FAILED\n");

		 supplyPos = 0;
		 G.numBuys = 2;
		 G.supplyCount[0] = 10;
		 G.coins = 100;	 
		 t = buyCard(supplyPos, &G);
		 if(t == 0){
		 	printf("  buyCard(): PASS with G.coins = 0\n"); 	
		 }
		 else
		 	printf("  buyCard(): FAILED\n");
			
	printf("Test complete.\n"); 

	return 0;
}
