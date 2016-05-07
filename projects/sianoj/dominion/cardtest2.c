//Jessica Siano
//CS362 Software Engineering 2
//Testing the smithy card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "rngs.h"

int main(){

	int seed = 1000, players = 3, r, result, handPos = 2, before;
	int c[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	printf("\n\nTesting the smithy card\n\n");

	struct gameState gS;
	
	memset(&gS, 23, sizeof(struct gameState));
	
	r = inializeGame(players, c, seed, &gS);

	int currPlayer = whoseTurn(&gS);
	before = gS.handCount[currPlayer];

	result = cardEffect(smithy, 0, 0, 0, &gS, handPos, 0);

	if(before + 2 == gS.handCount[currPlayer])
		printf("Smithy test passed.\n");
	else
		printf("Smithy test failed.\n");

	return 0; 
}
