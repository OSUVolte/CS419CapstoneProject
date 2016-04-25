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
	printf("Testing the discardCard function");
	int seed = 10;
	int numPlayer = 2;

	

	int k[10] = {adventurer, council_room, feast, gardens, mine,
		 remodel, smithy, village, baron, great_hall};
	struct gameState game;

	int i, j, p, r, handCount;

	memset(&game, 23, sizeof(struct gameState));

	p = 0;
	handCount = 2;

	//initialize a new game
	r = initializeGame(numPlayer, k, seed, &game);
		game.handCount[p] = handCount;


	if(r == -1)
	{
		exit(0);
	}

	//This will test the discard function
	int who;
	int cardTotalBefore, cardTotalAfter;

	who = game.whoseTurn;
	cardTotalBefore = game.handCount[who];
	i = discardCard(p, who, game, 1);
	cardTotalAfter = game.handCount[who];


	//Test number of cards in designated player's hand after gainCard called to hand
	if(cardTotalBefore == cardTotalAfter)
	{
		printf("Failure! Card was not discarded from player hand.");
	}

	if(cardTotalBefore > cardTotalAfter)
	{
		printf("Success! Card total decreased!");
	}


	//Tests when card discarded should be trashed as well.
	cardTotalBefore = game.deckCount[who];
	j = discardCard(p, who, game, 0);
	cardTotalAfter = game.deckCount[who];


	//Test number of cards in designated player's hand after discardCard called
	if(cardTotalBefore == cardTotalAfter)
	{
		printf("Failure! Discard did not function when trashFlag set.");
	}

	if(cardTotalBefore < cardTotalAfter)
	{
		printf("Success! Card discarded successfully.");
	}




}