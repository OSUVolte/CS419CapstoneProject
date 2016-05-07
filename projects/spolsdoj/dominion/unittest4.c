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

	int trashFlag = 0;
	int tester, handPos;

	printf("Testing discardCard.\n");
		r = initializeGame(numPlayer, k, seed, &G);

		tester = G.playedCardCount;
		handPos = 0;
		discardCard(handPos, 1, &G, trashFlag);

		if(tester < G.playedCardCount){
			printf("  discardCard(): PASS with trashFlag < 1\n");
		}
	
		handPos = -2;
		tester = G.handCount[1];
		trashFlag = 2;
		discardCard(handPos, 1, &G, trashFlag);

		if(tester > G.handCount[1]){
			printf("  discardCard(): PASS with removing card from player hand\n");
		}
		
		G.handCount[1] = 1;
		tester = G.handCount[1];  
		discardCard(handPos, 1, &G, trashFlag);
		
		if(tester > G.handCount[1]){
			printf("  discardCard(): PASS with only one card in hand\n"); 
		}	
		
		G.handCount[1] = 4;
		tester = G.handCount[1];
		discardCard(handPos, 1, &G, trashFlag);

		if(tester > G.handCount[1]){
			printf("  discardCard(): PASS replace discarded card with last card in hand\n");
		}

	printf("Test complete.\n"); 

	return 0;
}
