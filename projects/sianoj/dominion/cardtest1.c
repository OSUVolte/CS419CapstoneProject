//Jessica Siano
//CS362 Software Development 2
//Testing the adventurer card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){

	printf("\n\nTesting the Adventurer card.\n\n");

	struct gameState gS;
	int seed = 1000, players = 3, r, result, handPos = 2;

	int c[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	memset(&gS, 23, sizeof(struct gameState));
	r = initializeGame(players, c, seed, &gS);

	int beforeCoins = 0, afterCoins = 0;
	int beforeCount, card, i;
	int currPlayer = whoseTurn(&gS);
	
	beforeCount = gS.handCount[currPlayer];
	for(i = 0; i < beforeCount; i++){
		card = gS.hand[currPlayer][i];
		if(card == copper || card == silver || card == gold)
			afterCoins++;
	}

	if((beforeCoins + 1 == gS.handCount[currPlayer]) && (beforeCoins + 2 == afterCoins))
		printf("Adventurer test passed.\n");
	else
		printf("Adventurer test failed.\n");

	return 0;
}	
