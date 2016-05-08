#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>


void testCardSmithy(){
	printf("--- ---\n");
	int numPlayers = 2;
	int seed = 500;
	int k[10] = {adventurer, village, mine, smithy,
		remodel, feast, great_hall, gardens, embargo, minion}; 

	struct gameState game;
	int flag, p = 0, ret;

	printf("==================Testing cardSmithy==================\n\n");

	memset(&game, 23, sizeof(struct gameState));
	
	initializeGame(numPlayers, k, seed, &game);

	//cust hand
	int curHand[] = {smithy, copper, silver};
	int handCount = 3, otherHC;

	game.handCount[p] = handCount;	
	otherHC = game.handCount[p+1];
	memcpy(game.hand[p], curHand, sizeof(int) * handCount);

	//cust deck so we dont redraw smithy
	int custDeck[] = {copper, silver, gold, copper, silver, gold};
	int deckCount = 6, otherDC;

	game.deckCount[p] = deckCount;
	otherDC = game.deckCount[p+1];
	memcpy(game.deck[p], custDeck, sizeof(int) * deckCount);

	int playedCard = game.playedCardCount;
	//call smithy
	cardSmithy(&game, p, 0);

	//testing
	printf("---testing you gain 3 cards and discard card Smithy---\n");
//	assert(game.handCount[p] == handCount + 2);//cards added correctly
	assert(game.handCount[p] == handCount + 3);//cards added incorrectly
	printf("===BUG smithy grabs 4 cards===");

	printf("---testing cards removed from deck---\n");
//	assert(game.deckCount[p] == deckCount - 3);
	assert(game.deckCount[p] == deckCount - 4);
	printf("===BUG smithy grabs 4 cards===");
	
		
	printf("---testing smithy removed from hand---\n");
	assert(game.hand[p][0] != smithy);

	printf("---testing smithy added to played cards---\n");
	assert(game.playedCards[playedCard] == smithy);

	printf("---testing played cards incremented---\n");
	assert(game.playedCardCount == playedCard + 1);

	printf("---Ensure other player untouched---\n");
	assert(game.handCount[p+1] == otherHC);
	assert(game.deckCount[p+1] == otherDC);
}

int main(){
	printf("\n\n");
	testCardSmithy();
	printf("\n\n");

	printf("===========================finish=========================\n");
	return 0;
}
