#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
	struct gameState G;
	int numPlayers = 1;
	int over;
	int seed = 1000;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
			tribute, smithy, council_room };
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	printf("Test for isGameOver\n");

	G.supplyCount[province] = 1;
	int i;
	for (i=0;i<25;i++) {
		G.supplyCount[i] = i;
	}
	over = isGameOver(&G);
	printf("1 province and all other supplies are greater than 0\n");
	if (over == 1) {
		printf("Test failed!!\n");
	} else {
		printf("Test passed!!!\n");
	}

	printf("Test with province equal to zero\n");
	G.supplyCount[province] = 0;
	over = isGameOver(&G);
	if (over == 0) {
		printf("Test failed!!\n");
	} else {
		printf("Test passed!!!\n");
	}

	G.supplyCount[province] = 1;
	G.supplyCount[3] = 0;
	G.supplyCount[8] = 0;
	printf("Test with a province card but three other cards are empty\n");
	over = isGameOver(&G);
	if (over == 0) {
		printf("Test failed!!\n");
	} else {
		printf("Test passed!!!\n");
	}

	printf("\n\n\n\n");
	return 0;
}

