/* * * * * * * * * * * * * * * * * * * * * *
* randomtestadventurer.c
* Lauren Crees
* Last Modified: 5/4/2016
* Description: Random tester for adventurer card.
* If adventurer fails a test, the test will print out. Otherwise it
* will continue until stopped.
* * * * * * * * * * * * * * * * * * * * * * */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int adventurerOracle(struct gameState*, struct gameState*);

int main()
{
	srand(time(0));
	int seed = 1000;
	int numPlayers;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState Game, testGame;

	int oracle = 0;
	int tests = 0;
	while (oracle >= 0 && tests < 10000000)
	{
		// Random number of players between 2 and 4
		numPlayers = rand() % 3 + 2;
		initializeGame(numPlayers, k, seed, &Game);
		// Random number of coin cards in player's deck
		int coinsInDeck = rand() % (Game.deckCount[0]+1);
		while (coinsInDeck > 0)
		{
			int whereInDeck = rand() % Game.deckCount[0];
			int whichCoin = rand() % 3;
			int coin;
			if (whichCoin == 0)
				coin = copper;
			else if (whichCoin == 1)
				coin = silver;
			else
				coin = gold;
			Game.deck[0][whereInDeck] = coin;
			coinsInDeck--;
		}
		// Copy to test state
		memcpy(&testGame, &Game, sizeof(struct gameState));
		// Check with oracle
		oracle = adventurerOracle(&testGame, &Game);
		tests++;
	}
	// Print parameters of failure
	if (oracle < 0)
	{
		printf("Number of players: %d\n", numPlayers);
		int i;
		for (i = 0; i < testGame.deckCount[0]; i++)
		{
			if (testGame.deck[0][i] == copper)
				printf("Location: %d, Coin: copper\n", i);
			else if (testGame.deck[0][i] == silver)
				printf("Location: %d, Coin: silver\n", i);
			else if (testGame.deck[0][i] == gold)
				printf("Location: %d, Coin: gold\n", i);
		}
	}
	else
		printf("Tests pass\n");

	return 0;
}

// Checks if adventurer card has functioned properly
int adventurerOracle(struct gameState* testG, struct gameState* G)
{
	int player = 0;
  int z = 0;
  int drawntreasure = 0;
  int cardDrawn = 0;
  int temphand[MAX_HAND];
  int failure = 0;

	int cardsHandBefore = testG->handCount[player];
	adventurerEffect(drawntreasure, testG, player, cardDrawn, z, temphand);
	if(testG->handCount[player] != (cardsHandBefore + 2))
  {
    printf("Player's hand should have two more cards: FAIL\n");
    failure++;
  }

	if(testG->deckCount[player] >= G->deckCount[player])
  {
    printf("Deck should have less cards: FAIL\n");
    failure++;
  }

	if(testG->discardCount[player] < G->discardCount[player])
  {
    printf("Discard should be same or have more cards: FAIL\n");
    failure++;
  }

	if(testG->deckCount[player] != (G->deckCount[player] - (testG->discardCount[player] + 2)))
  {
    printf("Discard + 2 = difference in deck amount: FAIL\n");
    failure++;
  }

	player = 1;
  if(testG->handCount[player] != G->handCount[player])
  {
    printf("Other players should be in same state as before\nHand Count is same: FAIL\n");
    failure++;
  }

	int j;
	for (j = 0; j < G->handCount[player]; j++)
  {
    if(testG->hand[player][j] != G->hand[player][j])
	  {
	    printf("Other players should be in same state as before\nHand is same: FAIL\n");
	    failure++;
	  }
  }

  if(testG->deckCount[player] != G->deckCount[player])
  {
    printf("Other players should be in same state as before\nDeck Count is same: FAIL\n");
    failure++;
  }
	
	for (j = 0; j < G->deckCount[player]; j++)
  {
    if(testG->deck[player][j] != G->deck[player][j])
	  {
	    printf("Other players should be in same state as before\nDeck is same: FAIL\n");
	    failure++;
	  }
  }
	
  if(testG->discardCount[player] != G->discardCount[player])
  {
    printf("Other players should be in same state as before\nDiscard Count is same: FAIL\n");
    failure++;
  }
	
	for (j = 0; j < G->discardCount[player]; j++)
	{
    if(testG->discard[player][j] != G->discard[player][j])
	  {
	    printf("Other players should be in same state as before\nDiscard is same: FAIL\n");
	    failure++;
	  }
  }

  if (failure > 0)
  	return -1;

	return 0;
}