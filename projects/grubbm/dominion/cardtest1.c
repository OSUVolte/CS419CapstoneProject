#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"

int main (){

	
	printf("Testing council_room.\n");


	struct gameState G;
	int k[10] = {adventurer, great_hall, embargo, village, minion, duchy, feast,
	       steward, estate, smithy};


	
	initializeGame(2, k, 5, &G);

	int p1 = 0;
	int p2 = 1;
	int p1startHand, p1endHand, p2startHand, p2endHand, p1startDeck, p1endDeck, p2startDeck, p2endDeck, effect; 

	p1startHand = G.handCount[p1];
	p1startDeck = G.deckCount[p1];

	p2startHand = G.handCount[p2];
	p2startDeck = G.deckCount[p2];

	effect = cardEffect(council_room, 0, 0, 0, &G, 0, 0);

	p1endHand = G.handCount[p1];
	p1endDeck = G.deckCount[p1];
	printf("%i\n", effect);
	p2endHand = G.handCount[p2];
	p2endDeck = G.deckCount[p2];

	printf("Hand contains +3 cards: ");
	assert(p1startHand == p1endHand - 3);
	printf("PASSED\n");

	printf("4 cards drawn: ");
	assert(p1startDeck == p1endDeck + 4);
	printf("PASSED\n");

	printf("Player 2 hand +1: ");
	assert(p2startHand == p2endHand - 1);
	printf("PASSED\n");

	printf("1 card drawn: ");
	assert(p2startDeck == p2endDeck + 1);
	printf("PASSED\n");

	printf("Testing complete. All tests passed.\n");
	return 0;
}
