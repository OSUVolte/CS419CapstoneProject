#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int checkSupply(struct gameState A, struct gameState B) {
	assert(A.supplyCount[copper] == B.supplyCount[copper]); //check supply
	assert(A.supplyCount[silver] == B.supplyCount[silver]);
	assert(A.supplyCount[gold] == B.supplyCount[gold]);
	
	assert(A.supplyCount[estate] == B.supplyCount[estate]);
	assert(A.supplyCount[duchy] == B.supplyCount[duchy]);
	assert(A.supplyCount[province] == B.supplyCount[province]);

	return 0;
}

int checkDeck(int player, struct gameState A, struct gameState B) {
	int i;

	assert(A.deckCount[player] == B.deckCount[player]);

	for (i = 0; i < A.deckCount[player]; i++) {
		assert(A.deck[player][i] == B.deck[player][i]);
	}

	return 0;
}

int checkHand(int player, struct gameState A, struct gameState B) {
	int i;

	assert(A.handCount[player] == B.handCount[player]);

	for (i = 0; i < A.handCount[player]; i++) {
		assert(A.hand[player][i] == B.hand[player][i]);
	}

	return 0;	
}