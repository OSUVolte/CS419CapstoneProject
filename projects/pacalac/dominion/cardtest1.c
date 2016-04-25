#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
/*
//plays the adventurer card. Draws cards from the deck until 2 treasure cards revealed. Discards other drawn cards.
int playAdventurer(struct gameState *state)
{
	int cardDrawn;
	int drawntreasure=0;
	int z = 0;// this is the counter for the temp hand
	int temphand[MAX_HAND];
	int currentPlayer = whoseTurn(state);
	
	while(drawntreasure<2){
		if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
		  shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else{
			temphand[z]=cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while(z-1>0){
		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
		z=z-1;
	}
	return 0;
}
*/

void testAdventurer()
{
	int numPlayers = 2;
	int currPlayer = 1;
	int seed = 1000;
	int count = 0;
	int cards[10] = {smithy, adventurer, duchy, feast, gardens, remodel, steward, ambassador, baron, mine};
	int tarCard = adventurer;	//card to test.
	int fillCard = smithy;
	struct gameState game;
	
	if(initializeGame(numPlayers, cards, seed, &game) == 0)
	{
		game.whoseTurn = currPlayer;
		int i = 0;
		int plHand[MAX_HAND];
		for(i = 0; i < MAX_HAND; ++i)
		{
			plHand[i] = fillCard;
		}
		plHand[tarCard] = tarCard;
		memcpy(game.hand[currPlayer], plHand, sizeof(int) * MAX_HAND);
		
		int plDeck[MAX_DECK];
		for(i = 0; i < 10; ++i)
		{
			plDeck[i] = copper;
		}
		for(i; i < MAX_DECK; ++i)
		{
			plDeck[i] = fillCard;
		}
		memcpy(game.deck[currPlayer], plDeck, sizeof(int) * MAX_DECK);
	
		int handC = game.handCount[currPlayer] = tarCard + 1;
		
		cardEffect(tarCard, 0, 0, 0, &game, 0, 0);
		handC++; //increment expected hand count (should gain 2 cards and discard 1 from playing adventurer).
		
		if(handC == game.handCount[currPlayer])
			printf("Test if adventurer card adds 2 cards to player hand succeeded. Expected %d == Actual %d\n", handC, game.handCount[currPlayer]);
		else
			printf("Test if adventurer card adds 2 cards to player hand failed. Expected %d != Actual %d\n", handC, game.handCount[currPlayer]);	
	}
	else
		printf("Failed to initialize game.\n");
}

int main()
{
	testAdventurer();
	return 0;
}