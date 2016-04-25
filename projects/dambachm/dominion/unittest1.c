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
	printf("Test for scoreFor\n");

	printf("Testing with 1 curse, 2 estate, 1 duchy, 1 province and 1 steward card in hand.\n");
	G.handCount[1] = 7;
	G.hand[player][0] = curse;
	G.hand[player][1] = estate;
	G.hand[player][2] = duchy;
	G.hand[player][3] = province;
	G.hand[player][4] = steward;
	G.hand[player][5] = estate;
	G.hand[player][6] = minion;

	int score = scoreFor(player, &G);

	if (score == 10) {
		printf("Test passed!\n");
	} else {
		printf("Test failed!\n");
	}

	initializeGame(numPlayers, k, seed, &G);
	printf("Testing with 1 curse, 2 estate, 1 duchy, 1 province and 2 other cards in discard.\n");
	G.discardCount[1] = 8;
	G.discard[player][0] = curse;
	G.discard[player][1] = estate;
	G.discard[player][2] = duchy;
	G.discard[player][3] = province;
	G.discard[player][4] = steward;
	G.discard[player][5] = estate;
	G.discard[player][6] = minion;
	G.discard[player][7] = minion;

	score = scoreFor(player, &G);

	if (score == 20) {
		printf("Test passed!\n");
	} else {
		printf("Test failed!\n");
	}

	printf("Testing with 1 curse, 2 estate, 1 duchy, 1 province and 3 other cards in deck.\n");
	G.deckCount[1] = 9;
	G.deck[player][0] = curse;
	G.deck[player][1] = estate;
	G.deck[player][2] = duchy;
	G.deck[player][3] = province;
	G.deck[player][4] = steward;
	G.deck[player][5] = estate;
	G.deck[player][6] = minion;
	G.deck[player][7] = minion;
	G.deck[player][8] = minion;

	score = scoreFor(player, &G);

	if (score == 30) {
		printf("Test passed!\n");
	} else {
		printf("Test failed!\n");
	}
	printf("\n\n\n\n");
	return 0;
}

