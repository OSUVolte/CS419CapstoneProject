#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
/*
//plays smithy card. Adds 3 cards to player's hand.
int playSmithy(struct gameState *state, int handPos)
{
	int currentPlayer = whoseTurn(state);
	int i = 0;
	
	//+3 Cards
	for (i = 0; i < 3; i++)
	{
		drawCard(currentPlayer, state);
	}
	
	return 0;
}
*/
void testSmithy()
{
	int numPlayers = 2;
	int currPlayer = 1;
	int seed = 1000;
	int count = 0;
	int cards[10] = {smithy, minion, duchy, feast, gardens, remodel, steward, ambassador, baron, mine};
	int tarCard = smithy;	//card to test.
	int fillCard = minion;
	struct gameState game;
	
	if(initializeGame(numPlayers, cards, seed, &game) == 0)
	{
		game.whoseTurn = currPlayer;
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
		
		cardEffect(tarCard, 0, 0, 0, &game, tarCard, 0);
		handC += 2; //add 2 to expected hand count (should gain 3 cards and discard 1 from playing smithy).
		
		if(handC == game.handCount[currPlayer])
			printf("Test if smithy card adds 3 cards to player hand succeeded. Expected %d == Actual %d\n", handC, game.handCount[currPlayer]);
		else
			printf("Test if smithy card adds 3 cards to player hand failed. Expected %d != Actual %d\n", handC, game.handCount[currPlayer]);	
	}
	else
		printf("Failed to initialize game.\n");
}

int main()
{
	testSmithy();
	return 0;
}