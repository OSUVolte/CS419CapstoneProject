/******************************************************************************
* ASSIGNMENT 3 - cardtest3.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 04/24/2016
* NOTES: unit testing of the playCouncilRoom() function
* REQUIREMENTS for playCouncilRoom():
*  1. Player gets to draw four additional cards
*  2. Player gets an additional buy
*  3. All other players get to draw an additional card
*  4. Council Room is discarded
*  5. Other players only draw an extra card, their other piles are unaffected
*  6. Other players do not get an extra buy
* TESTING tasks for discardCard():
*  1. Test that player draws four cards
*  2. Test that the player gets an additional buy
*  3. Test that Council Room is discarded
*  4. Test that this player's other piles are not affected
*  5. Test that other players get to draw a card
*  6. Test that other players' other piles are unaffected
*  7. Test that players do not get an extra buy
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

	printf("TESTING playCouncilRoom():\n");
	
	for (i = 0; i < numPlayer; i++)
	{
		memset(&NormalState, 23, sizeof(struct gameState));
		initializeGame(numPlayer, k, seed, &NormalState);

		int startingHand[1]	= {council_room};
		int startingDeck[4] = {copper, copper, copper, copper};
		int startingDiscard[0];
		
		for (j = 0; j < numPlayer; j++)
		{
			NormalState.handCount[j] = 1;
			NormalState.deckCount[j] = 4;
			NormalState.discardCount[j] = 0;
			
			memcpy(NormalState.hand[j], startingHand, sizeof(int) * 1);
			memcpy(NormalState.deck[j], startingDeck, sizeof(int) * 4);
			memcpy(NormalState.discard[j], startingDiscard, sizeof(int) * 0);
		}
		
		memcpy(&TestState, &NormalState, sizeof(struct gameState));
		int p;
		p = playCouncilRoom(&TestState, i, 0);
		
		for (j = 0; j < numPlayer; j++)
		{
#if (NOISY_TEST == 1)
				printf("Testing Player %d\n", j);
#endif	
			//test the current player
			if (i == j)
			{
				//test handcount
				if (TestState.handCount[i] != (NormalState.handCount[i] + 3))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
					printf("TestState.handCount[%d] = %d, expected = %d\n", i, TestState.handCount[i], NormalState.handCount[i] + 3);
#endif
				
				//test deckcount
				if (TestState.deckCount[i] != (NormalState.deckCount[i] - 4))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
					printf("TestState.deckCount[%d] = %d, expected = %d\n", i, TestState.deckCount[i], NormalState.deckCount[i] - 4);
#endif	
				
				//test discardcount
				if (TestState.discardCount[i] != (NormalState.discardCount[i] + 1))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("TestState.discardCount[%d] = %d, expected = %d\n", i, TestState.discardCount[i], NormalState.discardCount[i] + 1);
#endif	

				//test # of buys
				if (TestState.numBuys != (NormalState.numBuys + 1))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("TestState.numBuys = %d, expected = %d\n", TestState.numBuys, NormalState.numBuys + 1);
#endif	
			}
			
			//test the rest of the players
			else
			{
				//test handcount
				if (TestState.handCount[j] != (NormalState.handCount[j] + 1))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("TestState.handCount[%d] = %d, expected = %d\n", j, TestState.handCount[j], NormalState.handCount[j] + 1);
#endif

				//test deckcount
				if (TestState.deckCount[j] != (NormalState.deckCount[j] - 1))
				{
					errorflag = 1;
				}
#if (NOISY_TEST == 1)
				printf("TestState.deckCount[%d] = %d, expected = %d\n", j, TestState.deckCount[j], NormalState.deckCount[j] - 1);
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