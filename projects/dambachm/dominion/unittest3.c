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
	int bonus = 4;
	printf("Test for updateCoins\n");
	G.handCount[player] = 20;
	G.hand[player][0] = silver;
	G.hand[player][1] = minion;
	G.hand[player][2] = gold;
	G.hand[player][3] = silver;
	G.hand[player][4] = minion;
	G.hand[player][5] = gold;
	G.hand[player][6] = silver;
	G.hand[player][7] = gold;
	G.hand[player][8] = silver;
	G.hand[player][9] = copper;
	G.hand[player][10] = silver;
	G.hand[player][11] = silver;
	G.hand[player][12] = copper;
	G.hand[player][13] = silver;
	G.hand[player][14] = minion;
	G.hand[player][15] = minion;
	G.hand[player][16] = copper;
	G.hand[player][17] = minion;
	G.hand[player][18] = silver;
	G.hand[player][19] = copper;

	updateCoins(player, &G, bonus);
	int coins = G.coins;
	if (coins == 33) {
		printf("Test passed!!!\n");
	} else {
		printf("Test failed!!\n");
	}
	printf("\n\n\n\n");
	return 0;
}



