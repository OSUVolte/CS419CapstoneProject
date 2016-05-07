/* * * * * * * * * * * * * * * * * * * * * *
* randomtestcard.c
* Lauren Crees
* Last Modified: 5/4/2016
* Description: Random tester for treasure_map card.
* If treasure_map fails a test, the test will print out. Otherwise it
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

int treasuremapOracle(struct gameState*, struct gameState*, int, int);

int main()
{
	srand(time(0));
	int seed = 1000;
	int numPlayers;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState Game, testGame;

	int mapNum;
	int goldNum;
	int pos;
	int oracle = 0;
	int tests = 0;
	while (oracle >= 0 && tests < 10000000)
	{
		// Random number of players between 2 and 4
		numPlayers = rand() % 3 + 2;
		initializeGame(numPlayers, k, seed, &Game);
		// Random number of treasure maps in hand - 1, or 2
		mapNum = rand() % 2 + 1;
		// Random position of treasure map in hand, if any
		int i;
		for (i = 0; i < mapNum; i++)
		{
			pos = rand() % Game.handCount[0];
			if (Game.hand[0][pos] != treasure_map)
				Game.hand[0][pos] = treasure_map;
			else
			{
				if (pos+1 < Game.handCount[0])
					Game.hand[0][pos+1] = treasure_map;
				else
					Game.hand[0][pos-1] = treasure_map;
			}
		}
		// Random number of supply for gold cards
		goldNum = rand() % 31;

		// Copy to test state
		memcpy(&testGame, &Game, sizeof(struct gameState));
		// Check with oracle
		oracle = treasuremapOracle(&testGame, &Game, pos, mapNum);
		tests++;
	}
	if (oracle < 0)
	{
		// Print parameters for failure
		printf("Number of players: %d\n", numPlayers);
		printf("Number of treasure maps in hand: %d\n", mapNum);
		printf("Position: %d\n", pos);
		printf("Gold Supply: %d\n", goldNum);
	}
	else
		printf("Tests pass\n");

	return 0;
}

// Oracle for treasure_map
int treasuremapOracle(struct gameState* testG, struct gameState* G, int p, int numMapsHand)
{
	int index = 0;
  int i = 0;
  int player = 0;
  int r;
  int failure = 0;

  // Tests for one tresure map
  if (numMapsHand == 1)
  {
	  testG->hand[player][0] = treasure_map;
	  r = treasuremapEffect(index, testG, player, i, p);
	  if(testG->deckCount[player] != G->deckCount[player])
	  {
	    printf("1 Treasure Map, no gold gained: FAIL\n");
	    failure++;
	  }

	  if(testG->playedCards[testG->playedCardCount-1] == treasure_map)
	  {
	    printf("Treasure Map trashed: FAIL\n");
	    failure++;
	  }

	  if(r != -1)
	  {
	    printf("1 Treasure Map, should return -1: FAIL\n");
	    failure++;
	  }
	}

	// Tests for two treasure maps
	if( numMapsHand == 2)
	{
	  memcpy(testG, G, sizeof(struct gameState));
	  r = treasuremapEffect(index, testG, player, i, p);
	  int j;
	  for (j = testG->deckCount[player]-1; j >= testG->deckCount[player]-4; j--)
	  {
	    if(testG->deck[player][j] != gold)
	    {
		    printf("2 Treasure Maps, gain 4 golds on top of deck: FAIL\n");
		    failure++;
		  }
	  }

	  if(testG->playedCards[testG->playedCardCount-1] == treasure_map)
	  {
	    printf("Treasure Maps trashed: FAIL\n");
	    failure++;
	  }

	  if(testG->playedCards[testG->playedCardCount-2] == treasure_map)
	  {
	    printf("Treasure Maps trashed: FAIL\n");
	    failure++;
	  }

	  if(r != 1)
	  {
	    printf("2 Treasure Maps, should return 1: FAIL\n");
	    failure++;
	  }
	}

	// Tests for rest of players
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