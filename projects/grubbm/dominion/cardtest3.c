#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"


int main () {

	printf("Testing Adventurer.\n");

	int effect;
	struct gameState G;
int k[10] = {adventurer, great_hall, embargo, village, minion, duchy, feast,
	       steward, estate, smithy};


	int p1, beginningHand, endingHand, testVal;

	//initialize to 2 players to show hand updates 		
	initializeGame(2, k, 5, &G);

	p1 = 0; //player 1, position 0; 
	beginningHand = G.handCount[p1];
	effect = cardEffect(adventurer, 0, 0, 0, &G, 0, 0);
	endingHand = G.handCount[p1];
	testVal = endingHand- beginningHand;
	printf("Function Success Test: "); 
	assert(effect == 0);
	printf("PASSED\n");
	
	printf("Card Draw Sub Test: 3 Drawn, 1 Discarded, Net +2 Cards to Hand: ");
	assert(testVal = 2);
	printf("PASSED\n");
	printf("Starting %i Ending %i\n", beginningHand, endingHand);

	printf("Testing complete. All tests passed.\n");
	return 0;
}
