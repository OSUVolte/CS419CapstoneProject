//Jessica Siano
//CS362 Software Development 2
//Testing the village card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "rngs.h"

int main(){
	printf("\n\nTesting the Village card.\n\n");
	
	int seed = 1000, numPlayer = 3, r, result, handPos = 2;
	int c[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

   	struct gameState gS;

   	memset(&gS, 23, sizeof(struct gameState));

	r = initializeGame(numPlayer, c, seed, &gS);

	int beforeCards, beforeActions;
	int currPlayer = whoseTurn(&gS);
	beforeCards = gS.handCount[currPlayer];
	beforeActions = gS.numActions;
	result = cardEffect(village, 0, 0, 0, &gS, handPos, 0);

	if(beforeCards == gS.handCount[currPlayer])
		printf("Village card test passed.\n");
	else
		printf("Village card test failed.\n");

	if((beforeActions + 1) == gS.numActions)
		printf("Village action test passed.\n");
        else
                printf("Village action test failed.\n");
 
	return 0;
}
