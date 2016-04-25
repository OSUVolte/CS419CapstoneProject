/******************************************************************************
* ASSIGNMENT 3 - cardtest4.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 04/24/2016
* NOTES: unit testing of the refactored playSalvager() function
* REQUIREMENTS for playSalvager():
*  1. Player gets an additional buy
*  2. Player must trash a card
*  3. Player gets a number of coins equal to trashed card's value
*  4. This card should be discarded to the played pile
*  5. Trashed card should not appear in discard pile
*  6. No other players should be affected
* TESTING tasks for playSalvager():
*  1. Test that number of buys increases
*  2. Test that chosen card is trashed
*  3. Test that chosen card does not appear in discard pile
*  4. Test that number of coins increases corresponding to discarded value
*  5. Test that no other players are affected
*  6. Test that this card is discarded
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

	printf("TESTING playSalvager():\n");
	
	for (i = 0; i < numPlayer; i++)
	{
		memset(&NormalState, 23, sizeof(struct gameState));
		initializeGame(numPlayer, k, seed, &NormalState);

		int startingHand[2]	= {salvager, adventurer};
		int startingDeck[0];
		int startingDiscard[0];
		
		for (j = 0; j < numPlayer; j++)
		{
			NormalState.handCount[j] = 2;
			NormalState.deckCount[j] = 0;
			NormalState.discardCount[j] = 0;
			
			memcpy(NormalState.hand[j], startingHand, sizeof(int) * 2);
			memcpy(NormalState.deck[j], startingDeck, sizeof(int) * 0);
			memcpy(NormalState.discard[j], startingDiscard, sizeof(int) * 0);
		}
		
		memcpy(&TestState, &NormalState, sizeof(struct gameState));
		int p;
		p = playSalvager(&TestState, i, 0, 1);
		
		for (j = 0; j < numPlayer; j++)
		{
#if (NOISY_TEST == 1)
				printf("Testing Player %d\n", j);
#endif	
			//test the current player
			if (i == j)
			{
				//test handcount
				if (TestState.handCount[i] != (NormalState.handCount[i] - 2))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
					printf("TestState.handCount[%d] = %d, expected = %d\n", i, TestState.handCount[i], NormalState.handCount[i] - 2);
#endif
				
				//test deckcount
				if (TestState.deckCount[i] != (NormalState.deckCount[i]))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
					printf("TestState.deckCount[%d] = %d, expected = %d\n", i, TestState.deckCount[i], NormalState.deckCount[i]);
#endif	
				
				//test discardcount
				if (TestState.discardCount[i] != (NormalState.discardCount[i]))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("TestState.discardCount[%d] = %d, expected = %d\n", i, TestState.discardCount[i], NormalState.discardCount[i]);
#endif	

				//test # of coins
				if (TestState.coins != (NormalState.coins + 6))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("TestState.coins = %d, expected = %d\n", TestState.coins, NormalState.coins + 6);
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