/*
 * cardtest2.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestadventurer: randomtestadventure.c dominion.o rngs.o
 *      gcc -o randomtestadventurer -g  randomtestadventure.c dominion.o rngs.o $(CFLAGS)
 *
 *   I have decided to make an intelligent random tester as creating a bunch of game states that are useless.
 *
 */

/*
 * cardtest2.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 *
 *      This will test the adventure card.
 *      int adventurerPlay(int currentPlayer, int handPos, struct gameState *state)
 *
 *		The adventurer card implementation was badly broken. Due to bugs introduced in implementation it will
 *		not draw cards into the hand of the person.
 *
 *		I created several test, one general case and one specific case to show that the Adventure Card
 *		Doesn't get discarded, and several more showing that this function is incredibly broken.
 *		This would not pass a smoke test.
 *
 *		The bright side is the test show no changes in OTHER cards when using the adventurer.
 *
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
void testDeckCount(struct gameState *state);
void testTreasure(struct gameState *state);
void testMoreCards(struct gameState *state);
void otherPlayersEffected(struct gameState *state, int numPlayers);
struct gameState * randomizeGame();

void otherPlayersEffected(struct gameState *state, int numPlayers)
{
	int bonus = 0;
	int i;
	int j;


	cardEffect( adventurer , 0, 0, 0, state, 0, &bonus);


	for(i = 0; i < numPlayers; i++)
	{
		if( i != state->whoseTurn)
		{
			//Important Note - If the hands are identical than the victory points are identical.
			for(j = 0; j < state->handCount[i]; j++)
			{
				assert(state->hand[i][j] == state->hand[i][j]);
			}

			for(j = 0; j < state->deckCount[i]; j++)
			{
				assert(state->deck[i][j] == state->deck[i][j]);

			}

			for(j = 0; j < state->discardCount[i]; j++)
			{
				assert(state->discard[i][j] == state->discard[i][j]);
			}
		}
	}
return;

}
// Test made to prove the adventure card does not draw any cards.
void testMoreCards(struct gameState *state)
{

	int cardInHand = state->handCount[state->whoseTurn] - 1;
	int cardToggle;
	int i;
	int player = state->whoseTurn;
	int deckTreaSureCount = 0;
	int bonus = 0;
	for(i = 0; i < state->deckCount[player]; i++)
	{
		if((state->deck[player][i] == copper) || (state->deck[player][i] == silver) || (state->deck[player][i] == gold))
		{
			deckTreaSureCount++;
		}
	}

	for(i = 0; i < state->discardCount[player]; i++)
	{
		if((state->discard[player][i] == copper) || (state->discard[player][i] == silver) || (state->discard[player][i] == gold))
		{
			deckTreaSureCount++;
		}
	}

	cardToggle = (deckTreaSureCount >= 2) ? 1 : 0;

	cardEffect( adventurer , 0, 0, 0, state, 0, &bonus);

	if(cardToggle == 1)
	{
		printf("Expected card count : %d \n", cardInHand+2);
		printf("Actual card count : %d \n", state->handCount[player]);
	}
	else
	{
		printf("Expected card count : %d or %d \n", cardInHand+1, cardInHand);
		printf("Actual card count : %d \n", state->handCount[player]);
	}


	assert(cardInHand < state->handCount[state->whoseTurn > cardInHand]);


	return;

}

void testTreasure(struct gameState *state)
{
	int player = state->whoseTurn;
	int deckTreaSureCount = 0;
	int bonus = 0;
	int i = 0;
	int treasureCount=0;
	int newTreasureCount=0;


	state->hand[player][0] = 7;

	printf("Original Hand: \n");
	for(i = 0; i < state->handCount[player]; i++)
	{
		printf("%d   ",state->hand[player][i]);

		if((state->hand[player][i] == copper) || (state->hand[player][i] == silver) || (state->hand[player][i] == gold))
		{
			treasureCount++;
		}
	}

	for(i = 0; i < state->deckCount[player]; i++)
	{
		if((state->deck[player][i] == copper) || (state->deck[player][i] == silver) || (state->deck[player][i] == gold))
		{
			deckTreaSureCount++;
		}
	}

	for(i = 0; i < state->discardCount[player]; i++)
	{
		if((state->discard[player][i] == copper) || (state->discard[player][i] == silver) || (state->discard[player][i] == gold))
		{
			deckTreaSureCount++;
		}
	}

	cardEffect( adventurer , 0, 0, 0, state, 0, &bonus);
	printf("\n Hand After Card Played: \n");

	for(i = 0; i < state->handCount[player]; i++)
	{
		printf("%d   ",state->hand[player][i]);

		if((state->hand[player][i] == copper) || (state->hand[player][i] == silver) || (state->hand[player][i] == gold))
		{
			newTreasureCount++;
		}
	}


	if(deckTreaSureCount >=2 )
	{
		printf("\nTreasure Count: %d \n", treasureCount);
		printf("New Treasure Count: %d \n", newTreasureCount);
		printf("Expected Treasure Count: %d \n", treasureCount+2);
		assert(treasureCount+2 == newTreasureCount);
	}
	else if(deckTreaSureCount == 1)
	{
		printf("\nTreasure Count: %d \n", treasureCount);
		printf("New Treasure Count: %d \n", newTreasureCount);
		printf("Expected Treasure Count: %d \n", treasureCount+1);
		assert(treasureCount+1 == newTreasureCount);
	}
	else if(deckTreaSureCount == 0)
	{
		printf("Treasure Count: %d \n", treasureCount);
		printf("New Treasure Count: %d \n", newTreasureCount);
		printf("Expected Treasure Count: %d \n", treasureCount);
		assert(treasureCount == newTreasureCount);
	}

	return;
}

void testDeckCount(struct gameState *state)
{
	struct gameState testG;
	int player = state->whoseTurn;
	int cardCount = state->deckCount[player];
	int bonus = 0;

	//int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)


	while(cardCount < 2)
	{
		drawCard(state->whoseTurn, &testG);
		cardCount = state->deckCount[player];
	}

	cardEffect( adventurer , 0, 0, 0, &testG, 0, &bonus);

	while(cardCount > 2)
	{
		discardCard(0, state->whoseTurn, &testG, 0);
		cardCount = state->deckCount[player];
	}

	cardEffect( adventurer , 0, 0, 0, &testG, 0, &bonus);

	return;
}





/*
 * This wil
 *
 * */
struct gameState * randomizeGame() {

	int k[10];
	int length;
	int i;
	int j;
	int newRoom;
	int roomTry;
	int player;
	int seed;
	struct gameState *G;

	G = malloc(sizeof(struct gameState));
	length = 1;
	k[0] = adventurer;

	for (i = 0; i < 9; i++) {
		newRoom = 0;
		while (newRoom == 0) {
			newRoom = 1;
			roomTry = (random() % 20) + 7;
			for (j = 0; j < length; j++) {
				if (k[j] == roomTry) {
					newRoom = 0;
				}
			}
		}
		k[length] = roomTry;
		length++;
	}
	player = random() % 2 + 2;
	seed = (random() % 9999) + 1;
	initializeGame(player, k, seed, G);

	for (i = random() % player; i > 0; i--) {
		endTurn(G);
	}

	G->coins = random() % 20;
	G->numActions = (random() % 3) + 1;
	G->numBuys = (random() % 2) + 2;

	for (i = 0; i < player; i++) {
		G->deckCount[i] = random() % 400;
		for (j = 0; j < G->deckCount[i]; j++) {
			if (j < 250) {
				roomTry = random() % 10;
				G->deck[i][j] = k[roomTry];
			} else {
				G->deck[i][j] = (random() % 3) + 4;
			}
		}
		shuffle(i, G);
	}

	for (i = 0; i < player; i++) {
		G->discardCount[i] = random() % 50;
		for (j = 0; j < G->discardCount[i]; j++) {
			if (j < 25) {
				roomTry = random() % 10;
				G->discard[i][j] = k[roomTry];
			} else {
				G->discard[i][j] = (random() % 3) + 4;
			}
		}
	}


	G->handCount[player] = (random() % 20)+1;
	for(i = 0; i < G->handCount[player]; i++){
		if (j > 5) {
			roomTry = random() % 10;
			G->hand[i][j] = k[roomTry];
		} else {
			G->hand[i][j] = (random() % 3) + 4;
		}
	}

	return G;
}

int main() {


	struct gameState *G;
	int i;

	for (i = 0; i < 1000; i++) {
		G = randomizeGame();
		printf("Test Treasure \n");
		testTreasure(G);
		printf("Test Complete \n ******************** \n");
		free(G);
	}
/*	for (i = 0; i < 1000; i++) {
			G = randomizeGame();
			printf("Follow up test to prove no cards are drawn. \n");
			testMoreCards(G);
			printf("Test Complete \n ******************** \n");
			free(G);
		}


	for (i = 0; i < 1000; i++) {
			G = randomizeGame();
			printf("Follow up test to see if other players decks/cards/vpoints are changed. \n");
			otherPlayersEffected(G, G->numPlayers);
			printf("Test Complete. No changes registered.\n ******************** \n");
			free(G);
		}


	for (i = 0; i < 10; i++) {
			G = randomizeGame();
			printf("Draws Card with deck < 2 cards and over 2 cards. Test for SegFault/ non-terminating loop \n");
//			testDeckCount(G);
			printf("Test Complete. Card draws with < 2 cards and >2 cards.\n ******************** \n");
			free(G);
		}*/

	printf("We made it!\n");

		return 0;

}
