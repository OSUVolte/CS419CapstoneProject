#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
/*
//play Steward card. Choose to gain 2 cards, gain 2 gold, or trash 2 cards in your hand.
int playSteward(int choice1, struct gameState *state)
{
	int currentPlayer = whoseTurn(state);
	
	if (choice1 == 1)
	{
		//+2 cards
		drawCard(currentPlayer, state);
		drawCard(currentPlayer, state);
	}
	else if (choice1 == 2)
	{
		state->coins = state->coins++;
	}

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}
*/
void testSteward()
{
	int numPlayers = 2;
	int currPlayer = 1;
	int seed = 1000;
	int count = 0;
	int cards[10] = {smithy, minion, duchy, feast, gardens, remodel, steward, ambassador, baron, mine};
	int tarCard = steward;	//card to test.
	int fillCard = smithy;
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
		
		//test removing 2 cards from hand
		cardEffect(tarCard, 0, 0, 1, &game, tarCard, 0); //discard 2 cards
		handC -= 3; //remove 2 from expected hand count (should discard 2 cards from playing Steward and 1 from playing card).
		
		if(handC == game.handCount[currPlayer])
			printf("Test if steward card removes 3 cards from player hand succeeded. Expected %d == Actual %d\n\n", handC, game.handCount[currPlayer]);
		else
			printf("Test if steward card removes 3 cards from player hand failed. Expected %d != Actual %d\n\n", handC, game.handCount[currPlayer]);
		
		//test drawing 2 cards from deck
		
		handC = game.handCount[currPlayer];
		
		cardEffect(tarCard, 1, 0, 1, &game, tarCard, 0); //draw 2 cards
		handC++; //add 1 to expected hand count (should draw 2 cards from playing Steward and discard 1 from playing card).
		
		if(handC == game.handCount[currPlayer])
			printf("Test if steward card adds 1 card to player hand succeeded. Expected %d == Actual %d\n\n", handC, game.handCount[currPlayer]);
		else
			printf("Test if steward card adds 1 card to player hand failed. Expected %d != Actual %d\n\n", handC, game.handCount[currPlayer]);
		
		//test gaining 2 gold
		
		int plGold = game.coins = 0;
		handC = game.handCount[currPlayer];
		
		cardEffect(tarCard, 2, 0, 1, &game, tarCard, 0); //gain 2 gold
		handC--; //remove 1 from expected hand count (should discard 1 from playing card).
		plGold += 2; //add 2 to gold count from playing card
		
		if(handC == game.handCount[currPlayer] && plGold == game.coins)
			printf("Test if steward card adds 2 gold and removes 1 card from player hand succeeded. Expected card count %d == Actual %d\n", handC, game.handCount[currPlayer]);
		else
			printf("Test if steward card adds 2 gold and removes 1 card from player hand failed.\nExpected card count %d != Actual %d\nExpected coins %d != Actual %d\n", handC, game.handCount[currPlayer], plGold, game.coins);
	}
	else
		printf("Failed to initialize game.\n");
}

int main()
{
	testSteward();
	return 0;
}