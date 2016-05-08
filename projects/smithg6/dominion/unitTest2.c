#include "dominion.h" 
#include "dominion_helpers.h"
#include <string.h> 
#include <stdio.h> 
#include <assert.h> 
#include "rngs.h" 
#include <stdlib.h>
#include <math.h>


int main()
{
	printf("Testing the gainCard function");
	int seed = 10;
	int numPlayer = 2;

	

	int k[10] = {adventurer, council_room, feast, gardens, mine,
		 remodel, smithy, village, baron, great_hall};
	struct gameState game;

	int i, j, p, r, handCount;

	memset(&game, 23, sizeof(struct gameState));

	p = 1;
	int cardNum;
	handCount = 2;

	//initialize a new game
	r = initializeGame(numPlayer, k, seed, &game);
		game.handCount[p] = handCount;


	if(r == -1)
	{
		exit(0);
	}

	int who;
	int cardTotalBefore, cardTotalAfter;

	who = game.whoseTurn;
	cardTotalBefore = game.handCount[who];
	i = gainCard(p, game, 2, who);
	cardTotalAfter = game.handCount[who];


	//Test number of cards in designated player's hand after gainCard called to hand
	if(cardTotalBefore == cardTotalAfter)
	{
		printf("Failure! gainCard failed to draw a card for given player.");
	}

	if(cardTotalBefore < cardTotalAfter)
	{
		printf("Success! Card total increased!");
	}


	cardTotalBefore = game.deckCount[who];
	j = gainCard(p, game, 1, who);
	cardTotalAfter = game.deckCount[who];


	//Test number of cards in designated player's hand after gainCard called to deck
	if(cardTotalBefore == cardTotalAfter)
	{
		printf("Failure! gainCard failed to add a card to the deck.");
	}

	if(cardTotalBefore < cardTotalAfter)
	{
		printf("Success! Deck total increased!");
	}


}





