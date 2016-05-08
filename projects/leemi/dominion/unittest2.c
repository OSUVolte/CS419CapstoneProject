#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>


void testDiscardCard(){
	int numPlayers = 2;
	int seed = 500;
	int k[10] = {adventurer, village, mine, smithy,
		remodel, feast, great_hall, gardens, embargo, minion}; 
	struct gameState game;
	printf("==================Testing playCard==================\n\n");

	//custom set
	int smithyPos = 0, g, p = 0, handCount = 5, d;
	int custHand[] = {smithy, silver, copper, salvager, village};

	//starting game 
	memset(&game, 23, sizeof(struct gameState));
	g = initializeGame(numPlayers, k, seed, &game);

	//update custom game state
	game.handCount[p] = handCount;
	memcpy(game.hand[p], custHand, sizeof(int) * handCount);
	int prevPlayCount = game.playedCardCount;

	printf("---Discarding One card from hand, 'smithy' from custom hand {smithy, salvager, silver, copper, village}---\n\n");
	d = discardCard(smithyPos, p, &game, 0);
	assert(d == 0);//assert that the function didnt fail
	printf("---Assert that handCount went down---\nexpected: 4 actual: %d\n", game.handCount[p]);
	assert(game.handCount[p] == handCount - 1);//assert that hand count went down
	printf("---Assert that smithy is gone---\n");
	assert(game.hand[p][smithyPos] != smithy);//assert that smithy is removed
	printf("---Done---\n");
	printf("---Assert that last card in hand is 'village' has been set to -1\n");
	assert(game.hand[p][handCount-1] == -1);	
	printf("---Done---\n");

	printf("---Assert cards except first and last are in same place\n");
	int i;
	for(i = 1; i < handCount-1; i++){
		assert(game.hand[p][i] == custHand[i]);
	}

	printf("---Done---\n");
	printf("---Assert that playedCardCount is increased---\nexpected: %d actual: %d\n", prevPlayCount + 1, game.playedCardCount);
	assert(game.playedCardCount == prevPlayCount + 1);
	printf("---Assert that smithy is in played card pile---\n");
	assert(game.playedCards[game.playedCardCount-1] == smithy);
	printf("---Done---\n\n");

	
	printf("---Discarding Salvager now to test for trashFlag---\n\n");
	//updating old information with updated gamestate	
	handCount = game.handCount[p];	
	//discard with trashflag
	d = discardCard(3, p, &game, 1);
	//assert the old things as they should be the same
	assert(game.hand[p][3] != salvager);
	assert(game.hand[p][handCount-1] == -1);
	//last card in hand is played and handcount should be subtracted
	printf("---last card in hand is played---\n");
	assert(game.handCount[p] == handCount - 1);
	printf("---Done---\n");

	//played cards should not change because they are trashed
	printf("---Assert that Played Cards have not changed at all---\n");
	assert(game.playedCardCount = prevPlayCount + 1);
	assert(game.playedCards[game.playedCardCount-1] == smithy);
	printf("---Done---\n");
	
	handCount = 1;
	game.handCount[p] = 1;
	int newCustHand[] = {copper};
	memcpy(game.hand[p], newCustHand, sizeof(int));	
	printf("---Assert that Last card decreses handCount---\n");
	//last card is played	
	discardCard(0, p , &game, 1);
	assert(game.hand[p][0] != copper);
	assert(game.hand[p][handCount-1] == -1);
	assert(game.handCount[p] == handCount - 1);
	printf("---Done---\n");

	//discarding card that doesnt exist?
	printf("---Discarding cards that don't exist---\n");
	discardCard(0, p, &game, 1);
	
	printf("HandCount is now: %d\n", game.handCount[p]);
		
	if(game.handCount[p] < 0){
		printf("===BUG: shouldn't be able to discard card that doesn't exist===");
	}
}


int main(){
	testDiscardCard();
	printf("\n\n");
	printf("=======================Sucess=====================");
	printf("\n\n");
	return 0;
}
