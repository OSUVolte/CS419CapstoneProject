/******************************************************************************
* ASSIGNMENT 3 - cardtest1.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 04/24/2016
* NOTES: unit testing of the refactored playSmithy() function
* REQUIREMENTS for playSmithy():
*  1. Player draws exactly three cards
*  2. Cards are drawn only from the player's deck
*  3. Smithy card is discarded
* TESTING tasks for discardCard():
*  1. Test that exactly three cards are drawn
*  2. Test that these three cards are drawn from player's deck
*  3. Test that smithy card was discarded
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

	printf("TESTING playSmithy():\n");
	
	for (i = 0; i < numPlayer; i++)
	{
		memset(&NormalState, 23, sizeof(struct gameState));
		initializeGame(numPlayer, k, seed, &NormalState);

		int startingHand[1]	= {smithy};
		int startingDeck[5] = {copper, silver, gold, estate, duchy};
		int startingDiscard[0];
		
		for (j = 0; j < numPlayer; j++)
		{
			NormalState.handCount[j] = 1;
			NormalState.deckCount[j] = 5;
			NormalState.discardCount[j] = 0;
			
			memcpy(NormalState.hand[j], startingHand, sizeof(int) * 1);
			memcpy(NormalState.deck[j], startingDeck, sizeof(int) * 5);
			memcpy(NormalState.discard[j], startingDiscard, sizeof(int) * 0);
		}
		
		memcpy(&TestState, &NormalState, sizeof(struct gameState));
		int p;
		p = playSmithy(&TestState, i, 0);
		
		for (j = 0; j < numPlayer; j++)
		{
#if (NOISY_TEST == 1)
				printf("Testing Player %d\n", j);
#endif	
			//test the current player
			if (i == j)
			{
				//test handcount
				if (TestState.handCount[i] != (NormalState.handCount[i] + 2))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
					printf("TestState.handCount[%d] = %d, expected = %d\n", i, TestState.handCount[i], NormalState.handCount[i] + 2);
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
				if (TestState.discardCount[i] != (NormalState.discardCount[i] + 1))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("TestState.discardCount[%d] = %d, expected = %d\n", i, TestState.discardCount[i], NormalState.discardCount[i] + 1);
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
		
	