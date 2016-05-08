#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>

void testCardOutpost(){
	int numPlayers = 2;
	int seed = 500;
	int k[10] = {adventurer, village, mine, smithy,
		remodel, feast, great_hall, gardens, embargo, minion}; 

	struct gameState game;
	int p = 0;


	memset(&game, 23, sizeof(struct gameState));
	
	initializeGame(numPlayers, k, seed, &game);

	printf("==================Testing=================\n\n");

	int prevOutState = game.outpostPlayed;	
	int prevHandCount = game.handCount[p];
	int otherPlayerCount = game.handCount[p + 1];
	int prevPlayedCount = game.playedCardCount;
	
	int bonus;
	cardEffect(outpost,-1,-1,-1, &game, 0, &bonus);
	
	//testing
	printf("---Testing outpost state is changed---\n");
	assert(prevOutState + 1 == game.outpostPlayed);

	printf("---testing hand count lowered---\n");
	assert(prevHandCount - 1 == game.handCount[p]);

	printf("---testing discard pile increased ---\n");
	assert(game.playedCardCount == prevPlayedCount + 1 );

	printf("---testing other player unchanged---\n");
	assert(game.handCount[p+1] == otherPlayerCount);

}

int main(){
	testCardOutpost();
	printf("\n\n");
	printf("=======================finish====================\n\n");
	return 0;
}
