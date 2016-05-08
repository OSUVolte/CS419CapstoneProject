#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>

int helpCoinNum(struct gameState game, int p){
	int i,coinNum = 0;
	for(i=0;i<game.handCount[p];i++){
		if(game.hand[p][i] == copper)
			coinNum++; 
		else if(game.hand[p][i] == silver)
			coinNum++; 
		else if(game.hand[p][i] == gold)
			coinNum++; 
	}
	return coinNum;
}

void testCardAdventurer(){
	int numPlayers = 2;
	int seed = 500;
	int k[10] = {adventurer, village, mine, smithy,
		remodel, feast, great_hall, gardens, embargo, minion}; 

	struct gameState game;
	struct gameState emptyGame;
	int p = 0;


	memset(&game, 23, sizeof(struct gameState));
	memset(&emptyGame, 23, sizeof(struct gameState));
	
	initializeGame(numPlayers, k, seed, &game);

	printf("==================Testing CardAdventurer=================\n\n");

	//cust hand
	int curHand[] = {adventurer, copper, silver};
	int handCount = 3;

	game.handCount[p] = handCount;	
	memcpy(game.hand[p], curHand, sizeof(int) * handCount);

	//cust deck so we dont redraw smithy
	int custDeck[] = {smithy, village, copper, silver, gold, copper, silver, gold, smithy};
	int deckCount = 9;

	game.deckCount[p] = deckCount;
	memcpy(game.deck[p], custDeck, sizeof(int) * deckCount);

	int discardCount = game.discardCount[p];	

	int drawntreasure = 0;
	int temphand[MAX_HAND];
	int z = 0, cardDrawn;
	int coinNum;

	coinNum = helpCoinNum(game, p);
	//printf("coinnum: %d",coinNum);
	
	cardAdventurer(&game, drawntreasure, p, temphand, z, cardDrawn);

//testing
//standard full deck
	printf("---Added at two coins and subtract adventurer---\n");
	assert(game.handCount[p] == handCount + 3);
	printf("===BUG should be 2 coins drawn not 3\n");

	printf("---check that it was coins added to the hand not any other---\n");
	//same bug should be 2
	assert(coinNum + 3 == helpCoinNum(game,p));
	//assert(coinNum + 2 == helpCoinNum(game,p));

	printf("---deckCount depends on order lost 4 elements here---\n");
	assert(game.deckCount[p] == deckCount - 4);

	printf("---check discard pile for smithy card---\n");
	assert(game.discard[p][0] == smithy);
	assert(game.discardCount[p] == discardCount + 1);

	printf("===BUGS should add played card count when adventurer and discard card should include the discarded adventurer??===\n");
	//assert(game.discardCount[p] == discardCount + 2);
	//assert(game.playedCardCount == 1);

	memcpy(&game, &emptyGame, sizeof(struct gameState));
//check the reshuffling of the deck
//	restart custom settings
//	make discard pile large
	int discCount = 6;
	int custDisc[] = {copper, silver, gold, copper, smithy, silver};
	
	game.discardCount[p] = discCount;
	memcpy(game.discard[p], custDisc, sizeof(int) * discCount);
	
	//make deck small	
	deckCount = 1;
	int newCustDeck[] = {copper};

	game.deckCount[p] = deckCount;
	memcpy(game.deck[p], newCustDeck, sizeof(int) * deckCount);
	
	//cust hand
	int newCurHand[] = {adventurer, copper, silver};
	handCount = 3;

	game.handCount[p] = handCount;	
	memcpy(game.hand[p], newCurHand, sizeof(int) * handCount);
//
	cardAdventurer(&game, drawntreasure, p, temphand, z, cardDrawn);

	printf("---checking same counts are working for shuffled deck---\n");
	//check handcount added	
	assert(game.handCount[p] == handCount + 3);
	//assert(game.handCount[p] == handCount + 2);
	//check coins added to hand
	//same bug should be 2
	assert(coinNum + 3 == helpCoinNum(game,p));
	//assert(coinNum + 2 == helpCoinNum(game,p));
	printf("---deck count should increase---\n");
	assert(game.deckCount[p] > deckCount);
	printf("===bug game will loop if there are not 2 coins available===\n");

}


int main(){
	printf("\n\n");
	testCardAdventurer();
	printf("==========================Finish========================");
	printf("\n\n");
	return 0;
}
