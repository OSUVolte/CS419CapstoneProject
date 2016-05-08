#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "rngs.h"

#define VERBOSE_LOG 0

void testAdventurer()
{
	int numTests = 1000;
	int succ = 0;
	int fail = 0;
	int i = 0;
	for(i = 0; i < 1000; ++i)
	{
		int numPlayers = rand() % (MAX_PLAYERS - 1) + 2; //random number of players between 2 and MAXPLAYERS
		int currPlayer = rand() % numPlayers;
		int seed = rand();
		int cards[10] = {smithy, adventurer, duchy, feast, gardens, remodel, steward, ambassador, baron, mine};
		int coins[3] = {copper, silver, gold};
		int tarCard = adventurer;	//card to test.
		struct gameState game;
		
		if(initializeGame(numPlayers, cards, seed, &game) == 0)
		{
			game.whoseTurn = currPlayer;
			game.handCount[currPlayer] = rand() % (MAX_HAND - 2); //set hand of player between 0 and MAX_HAND - 2 and see if player draws 2 cards 
			game.deckCount[currPlayer] = rand() % MAX_DECK + 1; //set deckCount between 1 and MAX_DECK.
			game.discardCount[currPlayer] = MAX_DECK - game.deckCount[currPlayer]; //set discard count so there are MAX_DECK number of cards between the deck and discard
			
			
			//initialize deck and discard counts so player can draw cards
			int j = 0;
			for(j = 0; j < game.deckCount[currPlayer]; ++j)	//add cards to player's deck up to deckCount
			{
				if(rand() % 5 == 0)	//20% of cards will be a coin card
					game.deck[currPlayer][j] = coins[rand() % 3];
				else
					game.deck[currPlayer][j] = cards[rand() % 10 + 1];
				
			}
			
			for(j = 0; j < game.discardCount[currPlayer]; ++j)	//add cards to player's discard up to discardCount
			{
				if(rand() % 5 == 0)	//20% of cards will be a coin card
					game.discard[currPlayer][j] = coins[rand() % 3];
				else
					game.discard[currPlayer][j] = cards[rand() % 10 + 1];
				
			}
			
			int handC = game.handCount[currPlayer];
			cardEffect(tarCard, 0, 0, 0, &game, 0, 0);
			handC++; //increment expected hand count (should gain 2 cards and discard 1 from playing adventurer).
			
			
			if(handC == game.handCount[currPlayer])	//increment success or fail count
			{
				++succ;
				if(VERBOSE_LOG)	//if verbose logging flag set, print detailed info for each test
					printf("Test %d if adventurer card adds 2 cards to player hand succeeded.\nExpected hand count %d == Actual %d\n", i, handC, game.handCount[currPlayer]);
			}
			else
			{
				++fail;
				if(VERBOSE_LOG)	//if verbose logging flag set, print detailed info for each test
					printf("Test %d if adventurer card adds 2 cards to player hand failed.\nExpected hand count %d != Actual %d\n", i, handC, game.handCount[currPlayer]);
			}
		}
		else
			printf("Failed to initialize game.\n");
	}
	printf("After %d number of tests, %d succeeded, %d failed\n", numTests, succ, fail);
}

int main()
{
	srand(time(NULL));
	testAdventurer();
	return 0;
}