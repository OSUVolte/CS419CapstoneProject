/******************************************************************************
* ASSIGNMENT 3 - cardtest2.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 04/24/2016
* NOTES: unit testing of the refactored playAdventurer() function
* REQUIREMENTS for playAdventurer():
*  1. Draw cards from deck and discard pile until two treasure cards are drawn
*  2. Discard cards drawn that are not treasure cards
*  3. All cards must be drawn from the player's deck
*  4. Adventurer card is discarded
* TESTING tasks for discardCard():
*  1. Test that two treasure cards are drawn from the deck if available
*  2. Test that cards from the discard pile are also drawn if none are in
*     the player's deck
*  4. Test that all non-treasure cards are discarded
*  5. Test that adventurer card is discarded
*  6. Test that no other players are affected
******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

int main() 
{
    int i, j;
    int seed = 1000;
    int numPlayer = 2;
    int r, handCount;
	int maxHandCount = 10;
    int trashflag;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState NormalState;
	struct gameState TestState;
	int errorflag;

	printf("TESTING playAdventurer():\n");
	
	for (i = 0; i < numPlayer; i++)
	{
		memset(&NormalState, 23, sizeof(struct gameState));
		initializeGame(numPlayer, k, seed, &NormalState);

		int startingHand[2]	= {adventurer, copper};
		int startingDeck[3] = {copper, estate, estate};
		int startingDiscard[1] = {copper};
		
		for (j = 0; j < numPlayer; j++)
		{
			NormalState.handCount[j] = 2;
			NormalState.deckCount[j] = 3;
			NormalState.discardCount[j] = 1;
			
			memcpy(NormalState.hand[j], startingHand, sizeof(int) * 2);
			memcpy(NormalState.deck[j], startingDeck, sizeof(int) * 3);
			memcpy(NormalState.discard[j], startingDiscard, sizeof(int) * 1);
		}
		
		memcpy(&TestState, &NormalState, sizeof(struct gameState));
		int p;
		p = playAdventurer(&TestState, i, 0);
		
		for (j = 0; j < numPlayer; j++)
		{
#if (NOISY_TEST == 1)
				printf("Testing Player %d\n", j);
#endif	
			//test the current player
			if (i == j)
			{
				//test handcount
				if (TestState.handCount[i] != (NormalState.handCount[i] + 1))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
					printf("TestState.handCount[%d] = %d, expected = %d\n", i, TestState.handCount[i], NormalState.handCount[i] + 1);
#endif
				
				//test deckcount
				if (TestState.deckCount[i] != (NormalState.deckCount[i] - 3))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
					printf("TestState.deckCount[%d] = %d, expected = %d\n", i, TestState.deckCount[i], NormalState.deckCount[i] - 3);
#endif	
				
				//test discardcount
				if (TestState.discardCount[i] != (NormalState.discardCount[i] + 2))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("TestState.discardCount[%d] = %d, expected = %d\n", i, TestState.discardCount[i], NormalState.discardCount[i] + 2);
#endif	
			}
			
			//test the rest of the players
			else
			{
				//test handcount
				if (TestState.handCount[j] != (NormalState.handCount[j]))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("TestState.handCount[%d] = %d, expected = %d\n", j, TestState.handCount[j], NormalState.handCount[j]);
#endif

				//test deckcount
				if (TestState.deckCount[j] != (NormalState.deckCount[j]))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("TestState.deckCount[%d] = %d, expected = %d\n", j, TestState.deckCount[j], NormalState.deckCount[j]);
#endif	
				
				//test discardcount
				if (TestState.discardCount[j] != (NormalState.discardCount[j]))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("TestState.discardCount[%d] = %d, expected = %d\n", j, TestState.discardCount[j], NormalState.discardCount[j]);
#endif	
			}
		}
	}
	
	//give error even if not in NOISY_TEST mode
	if (errorflag)
	{
		printf("ERROR: Not all tests were successful.\n");
	}
	return 0;
}