#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
int fullDeckCount(int player, int card, struct gameState *state) {
	int i;
	int count = 0;

	for (i = 0; i < state->deckCount[player]; i++)
	{
		if (state->deck[player][i] == card) count++;
	}

	for (i = 0; i < state->handCount[player]; i++)
	{
		if (state->hand[player][i] == card) count++;
	}

	for (i = 0; i < state->discardCount[player]; i++)
	{
		if (state->discard[player][i] == card) count++;
	}

	return count;
}
*/

void testFullDeckCount()
{
	int numPlayers = 2;
	int currPlayer = 1;
	int seed = 1000;
	int count = 0;
	int cards[10] = {smithy, minion, duchy, feast, gardens, remodel, steward, ambassador, baron, mine};
	int tarCard = smithy;	//card to test.
	int fillCard = minion;	//card to act as filler
	struct gameState game;
	
	if(initializeGame(numPlayers, cards, seed, &game) == 0)
	{
		int plHand[MAX_HAND];
		int plDeck[MAX_DECK];
		int plDiscard[MAX_DECK];
		int maxHand = 10;	//player hand count
		int numTest = 5; //test cards to add
		int funcCount = 0;
		int i = 0;
		
		game.handCount[currPlayer] = maxHand;
		
		//Check if card is in deck when player has no cards in deck, hand, or discard. Count should = 0
		
		funcCount = fullDeckCount(currPlayer, tarCard, &game);
		if(count == funcCount)
			printf("Test with no cards in deck, hand, or discard succeeded. %d added == %d returned from function\n\n", count, funcCount);
		else
		{
			printf("Test with no cards in deck, hand, or discard failed. %d added != %d returned from function\n\n", count, funcCount);
			count = funcCount;	//if test fails, set count to returned value from function (so later tests don't fail from this test)
		}
		
		//Add cards that are not test card to player's deck, hand, and discard pile.
		
		
		//create player hand without any target test cards
		for(i = 0; i < MAX_HAND; ++i)
		{
			plHand[i] = fillCard;
		}
		
		memcpy(game.hand[currPlayer], plHand, sizeof(int) * MAX_HAND);
		
		//Check if card is in deck when player has no cards of same type in deck, hand, or discard. Count should = 0
		funcCount = fullDeckCount(currPlayer, tarCard, &game);
		if(count == funcCount)
			printf("Test with no target cards in deck, hand, or discard succeeded. %d added == %d returned from function\n\n", count, funcCount);
		else
		{
			printf("Test with no target cards in deck, hand, or discard failed. %d added != %d returned from function\n\n", count, funcCount);
			count = funcCount;	//if test fails, set count to returned value from function (so later tests don't fail from this test)
		}
		
		//Add cards to player's deck, count should equal number of cards in player's deck.
		//create player deck with one target test card
		for(i = 0; i < numTest; ++i)
		{
			plDeck[i] = tarCard;
			count++;
		}
		for(i; i < MAX_DECK; ++i)
		{
			plDeck[i] = fillCard;
		}
		
		memcpy(game.deck[currPlayer], plDeck, sizeof(int) * MAX_DECK);
		game.deckCount[currPlayer] = MAX_DECK;
		
		funcCount = fullDeckCount(currPlayer, tarCard, &game);
		if(count == funcCount)
			printf("Test with cards in deck and no cards in hand or discard succeeded. %d added == %d returned from function\n\n", count, funcCount);
		else
		{
			printf("Test with cards in deck and no cards in hand or discard failed. %d added != %d returned from function\n\n", count, funcCount);
			count = funcCount;	//if test fails, set count to returned value from function (so later tests don't fail from this test)
		}
		
		//Add cards to player's hand, count should equal number of cards in player's hand.
		//create player hand with one target test card
		for(i = 0; i < numTest; ++i)
		{
			plHand[i] = tarCard;
			count++;
		}
		for(i; i < MAX_HAND; ++i)
		{
			plHand[i] = fillCard;
		}
		memcpy(game.hand[currPlayer], plHand, sizeof(int) * MAX_HAND);
		
		funcCount = fullDeckCount(currPlayer, tarCard, &game);
		if(count == funcCount)
			printf("Test with cards in deck and hand and none in discard succeeded. %d added == %d returned from function\n\n", count, funcCount);
		else
		{
			printf("Test with cards in deck and hand and none in discard failed. %d added != %d returned from function\n\n", count, funcCount);
			count = funcCount;	//if test fails, set count to returned value from function (so later tests don't fail from this test)
		}
		
		//Add cards to player's discard, count should equal number of cards in player's discard.
		//create player discard with one target test card
		for(i = 0; i < numTest; ++i)
		{
			plDiscard[i] = tarCard;
			count++;
		}
		for(i; i < MAX_DECK; ++i)
		{
			plDiscard[i] = fillCard;
		}
		memcpy(game.discard[currPlayer], plDiscard, sizeof(int) * MAX_DECK);
		game.discardCount[currPlayer] = MAX_DECK;
/*		
		//check if discard pile contains correct cards
		for(i = 0; i < MAX_DECK; ++i)
		{
			printf("Discard Pile: %d (target = %d, fillCard = %d)\n", game.discard[currPlayer][i], card, fillCard);
		}
*/

		funcCount = fullDeckCount(currPlayer, tarCard, &game);
		if(count == funcCount)
			printf("Test with cards in deck, hand, and discard succeeded. %d added == %d returned from function\n", count, funcCount);
		else
			printf("Test with cards in deck, hand, and discard failed. %d added != %d returned from function\n", count, funcCount);
	}
	else
		printf("Failed to initialize game.\n");
}

int main()
{
	testFullDeckCount();
	return 0;
}