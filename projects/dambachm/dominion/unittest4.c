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
	int seed = 1000;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
			tribute, smithy, council_room };
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	int player = 1;
	printf("Test for numHandCards\n");

	G.handCount[3] = 10;
	G.whoseTurn = 3;
	if (numHandCards(&G) == 10) {
		printf("Test passed!!!\n");
	} else {
		printf("Test failed!!!\n");
	}

	printf("\n\n\n\n");
	return 0;
}



