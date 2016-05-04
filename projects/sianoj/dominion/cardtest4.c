//Jessica Siano
//CS362 Software Development 2
//Testing the Great Hall Card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "rngs.h"

int main(){
	
	printf("\n\nTesting the Great Hall card.\n\n");
	int seed = 1000, players = 3, handPos = 2, r, result;
	int c[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	struct gameState gS;

	memset(&gS, 23, sizeof(struct gameState));
	r = initializeGame(players, c, seed, &gS);

	int beforeCards, beforeActions;
	int currPlayer = whoseTurn(&gS);

	beforeCards = gS.handCount[currPlayer];
	beforeActions = gS.numActions;
	result = cardEffect(great_hall, 0, 0, 0, &gS, handPos, 0);
	
	if(beforeCards == gS.handCount[currPlayer])
		printf("Great Hall card test passed.\n");
	else
		printf("Great Hall card test failed.\n");

	if(beforeActions == gS.numActions)
		printf("Great Hall action test passed.\n");
        else
                printf("Great Hall action test failed.\n");

	return 0;
}
