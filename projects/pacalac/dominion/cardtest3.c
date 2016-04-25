#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
/*
//plays Council Room card. Draws 4 cards for player and adds +1 Buy to player. Draws 1 card for every other player.
int playCouncil(struct gameState *state, int handPos)
{
	int currentPlayer = whoseTurn(state);
	int i = 0;
	
	//+4 Cards
	for (i = 0; i < 4; i++)
	{
		drawCard(currentPlayer, state);
	}

	//Each other player draws a card
	for (i = 0; i < state->numPlayers; i++)
	{
		drawCard(i, state);
	}

	//put played card in played card pile
	discardCard(handPos, currentPlayer, state, 0);

	return 0;
}
*/
void testCouncil()
{
	int numPlayers = 2;
	int currPlayer = 1;
	int otherPl = 0;
	int seed = 1000;
	int cards[10] = {smithy, council_room, duchy, feast, gardens, remodel, steward, ambassador, baron, mine};
	int tarCard = council_room;	//card to test.
	int fillCard = smithy;
	struct gameState game;
	
	if(initializeGame(numPlayers, cards, seed, &game) == 0)
	{
		game.whoseTurn = currPlayer;
		int numBuy = game.numBuys = 5;
		int i = 0;
		int plHand[MAX_HAND];
		int plDeck[MAX_DECK];
		
		for(i = 0; i < MAX_HAND; ++i)
		{
			plHand[i] = fillCard;
		}
		plHand[tarCard] = tarCard;
		memcpy(game.hand[currPlayer], plHand, sizeof(int) * MAX_HAND);

		for(i = 0; i < MAX_DECK; ++i)
		{
			plDeck[i] = fillCard;
		}
		memcpy(game.deck[currPlayer], plDeck, sizeof(int) * MAX_DECK);
	
		int handC = game.handCount[currPlayer] = tarCard + 1;
		int otherPlC = game.handCount[otherPl] = 5;
		
		cardEffect(tarCard, 0, 0, 0, &game, tarCard, 0);
		handC += 3; //add 3 to expected hand count (should gain 4 cards and discard 1 from playing Council).
		otherPlC++;
		numBuy++;
		
		if(handC == game.handCount[currPlayer] && otherPlC == game.handCount[otherPl] && numBuy == game.numBuys)
			printf("Test if council card adds 4 cards to player hand %d == %d, 1 buy to player %d == %d, and 1 card to other players succeeded %d == %d.\n", handC, game.handCount[currPlayer], numBuy, game.numBuys, otherPlC, game.handCount[otherPl]);
		else
			printf("Test if council card adds 4 cards to player hand %d != %d, 1 buy to player %d != %d, and 1 card to other players failed %d != %d.\n", handC, game.handCount[currPlayer], numBuy, game.numBuys, otherPlC, game.handCount[otherPl]);
	}
	else
		printf("Failed to initialize game.\n");
}

int main()
{
	testCouncil();
	return 0;
}