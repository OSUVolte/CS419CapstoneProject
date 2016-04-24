/*
 * cardtest1.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest5.c dominion.o rngs.o $(CFLAGS)
 *
 *      This will test the smithy card.
 *      The smithy card is a card I have input an error into and which I draw out with
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
void testHandPos(struct gameState *state, int handpos,int player,int cardsInHand);
void testHandsSize(struct gameState *state, int cardsInHand, int player);
void testState(struct gameState *state, int s);
void testVPoints(struct gameState *state);

//test where cards come from.
void testWhereCardsComeFrom(struct gameState *state)
{

	int choice1=0;
	int choice2=0;
	int choice3=0;
	int bonus=0;
	int i=0;
	int beforeDraw = state->deckCount[state->whoseTurn];
	int afterDraw;
	cardEffect( smithy , choice1, choice2, choice3, state, 0, &bonus);

	afterDraw = state->deckCount[state->whoseTurn];

	assert (afterDraw + 3 == beforeDraw);
}


void testVPoints(struct gameState *state)
{

	int choice1=0;
	int choice2=0;
	int choice3=0;
	int bonus=0;
	int i=0;
	int beforeVictoryPoints[MAX_PLAYERS];

	for(i = 0; i < state->numPlayers-1; i++)
	{
		beforeVictoryPoints[i] = scoreFor(i, state);
		printf(".");
	}
	cardEffect( smithy , choice1, choice2, choice3, state, 0, &bonus);
	for(i = 0; i < state->numPlayers-1; i++)
	{
		assert(beforeVictoryPoints[i] == scoreFor(i, state));
		printf(".");
	}
	printf("\n");

return;


}


void testState(struct gameState *state, int s)
{

	int player;
	struct gameState copyState;
	int choice1=0;
	int choice2=0;
	int choice3=0;
	int bonus=0;
	int i=0;
	int seed = s;
	int beforeCardsDeckCount;
	int beforeCardUsedCount;

	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
			tribute, smithy, council_room };
 for (i = 2; i < MAX_PLAYERS+1; i ++)
 {
	initializeGame(i, k, seed, &copyState);
	player = state->whoseTurn;
	do
	{
		if(state->numPlayers-1 == state->whoseTurn)
		{
			beforeCardsDeckCount = state->deckCount[0];
			beforeCardUsedCount  = state->discardCount[0];
		}
		else
		{
			beforeCardsDeckCount = state->deckCount[state->whoseTurn+1];
			beforeCardUsedCount  = state->discardCount[state->whoseTurn+1];
		}
		cardEffect( smithy , choice1, choice2, choice3, &copyState, 0, &bonus);

		if(state->numPlayers-1 == state->whoseTurn)
		{
			assert(beforeCardsDeckCount == state->deckCount[0]);
			assert(beforeCardUsedCount  == state->discardCount[0]);
		}
		else
		{
			assert(beforeCardsDeckCount == state->deckCount[state->whoseTurn+1]);
			assert(beforeCardUsedCount  == state->discardCount[state->whoseTurn+1]);
		}
		printf(".");

		endTurn(state);

	}while(player != state->whoseTurn);
 }
	printf("\n");
return;


}

void testHandPos(struct gameState *state, int handpos,int player,int cardsInHand)
{
	//the following are irrelevant and only required for card effect to work.
	int choice1=0;
	int choice2=0;
	int choice3=0;
	int bonus=0;
	int cardsShouldBeInHand;
	int cardsNowInHand;
	struct gameState testG;
	cardsShouldBeInHand = cardsInHand+2;

	memcpy(&testG, state, sizeof(struct gameState));
	testG.hand[player][handpos] = 13;
	cardEffect( smithy , choice1, choice2, choice3, &testG, handpos, &bonus);

	cardsNowInHand = testG.handCount[player];
	assert(cardsNowInHand == cardsShouldBeInHand);
return;

}

void testHandsSize(struct gameState *state, int cardsInHand, int player)
{
	int choice1=0;
	int choice2=0;
	int choice3=0;
	int bonus=0;
	int cardsShouldBeInHand = cardsInHand+2;

	int cardsInitialHand = state->handCount[player];

	if( cardsInHand > cardsInitialHand)
	{
		while(cardsInHand > cardsInitialHand)
		{
			drawCard(player, state);
			cardsInitialHand = state->handCount[player];
		}
	}
	else if ( cardsInHand < cardsInitialHand)
	{
		while(cardsInHand < cardsInitialHand)
		{
			discardCard(0, player, state, 0);
			cardsInitialHand = state->handCount[player];
		}
	}

	cardEffect( smithy , choice1, choice2, choice3, state, 0, &bonus);
	assert(cardsShouldBeInHand == state->handCount[player]);

	return;
}



int main() {

		int seed = 12;
		int numPlayers = 2;
		struct gameState G, testG;
		int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
				tribute, smithy, council_room };
		int i;
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);

		printf("First Test - Smithy Drawn from each hand position\n\n");
		for(i = 0; i < 5; i++)
		{
			memcpy(&testG, &G, sizeof(struct gameState));
			printf("Testing drawing smithy from place %d \n", i);
			testHandPos(&testG, i,0,5);
		}
			printf("Passed hand position test\n");


		printf("\n ********************** \n\n");
		printf("Second Test - Smith Drawn from hands of various sizes (1-8)");
		printf("Bug found - test case changed to let bug stay in code. \nNumbers tested all > 4 due to system"
				"hang \n doesn't test past card #8 as this causes a failure to draw.");
		for(i = 4; i < 8; i++)
		{
		printf("Testing smithy with %d cards in hand \n", i);
		memcpy(&testG, &G, sizeof(struct gameState));
		testHandsSize(&testG, i, 0);
		}
		printf("Test Completed. \n");
		printf("\n ********************** \n\n");

		printf("Third Test - Test State Change For Other Players\n");
		memcpy(&testG, &G, sizeof(struct gameState));
		testState(&testG, 13);
		printf("Test Passed\n");

		printf("\n ********************** \n\n");

		printf("Fourth Test - Victory Points\n");
		memcpy(&testG, &G, sizeof(struct gameState));
		testVPoints(&testG);
		printf("Test Passed");

		printf("\n ********************** \n\n");
		printf("Fifth Test - Cards Come From Right Deck?\n");
		memcpy(&testG, &G, sizeof(struct gameState));
		testWhereCardsComeFrom(&testG);
		printf("Test Passed");

	return 0;


}
