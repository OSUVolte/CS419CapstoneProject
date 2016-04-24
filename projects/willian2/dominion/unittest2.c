/******************************************************************************
* ASSIGNMENT 3 - unittest2.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 04/24/2016
* NOTES: unit testing of the fullDeckCount() function
* REQUIREMENTS for fulLDeckCount():
*  1. Count number of cards in deck
*  2. Count number of cards in hand
*  3. Count number of cards in discard
*  4. Return total number of cards in game for this player
* TESTING tasks for discardCard():
*  1. Test that each card can be counted
*  2. Test that each card can be counted from each pile
*  3. Test that counts are correct
*  4. Test that counts for each player are correct
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
    int seed = 1000;
    int numPlayer = 2;
    int player, r, deckCount, handCount, discardCount, totalCount, result, failflag;
	int maxCardCount = 10;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("TESTING fullDeckCount():\n");
    for (player = 0; player < numPlayer; player++)
    {
		int cardType, cardPosition;
		for (cardType = 0; cardType <= 26; cardType++)
		{
			for (deckCount = 0; deckCount <= maxCardCount; deckCount++)
			{
				for (handCount = 0; handCount <= maxCardCount; handCount++)
				{
					for (discardCount = 0; discardCount <= maxCardCount; discardCount++)
					{
						totalCount = deckCount + handCount + discardCount;
						
						//create test decks for this *Count (deck,hand,discard)
						int testDeck[deckCount];
						for (cardPosition = 0; cardPosition < deckCount; cardPosition++)
						{
							testDeck[cardPosition] = cardType;
						}
						
						int testHand[handCount];
						for (cardPosition = 0; cardPosition < deckCount; cardPosition++)
						{
							testHand[cardPosition] = cardType;
						}
						
						int testDiscard[discardCount];
						for (cardPosition = 0; cardPosition < deckCount; cardPosition++)
						{
							testDiscard[cardPosition] = cardType;
						}

						memset(&G, 23, sizeof(struct gameState));   // clear the game state
						r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
						G.deckCount[player] = deckCount;            // set the number of cards on deck
						G.handCount[player] = handCount;            // set the number of cards on hand
						G.discardCount[player] = discardCount;      // set the number of cards on discard
											
						memcpy(G.deck[player], testDeck, sizeof(int) * deckCount); // set to testDeck
						memcpy(G.hand[player], testHand, sizeof(int) * handCount); // set to testHand
						memcpy(G.discard[player], testDiscard, sizeof(int) * discardCount); // set to testDiscard
						
						result = fullDeckCount(player, cardType, &G);
						if (result != totalCount)
						{
							failflag = 1;
						}
#if (NOISY_TEST == 1)
						printf("fullDeckCount = %d, expected %d\n", result, totalCount);
#endif
					}
				}
			}
		}
	}
	if (failflag != 1)
	{
		printf("All tests passed!\n");
	}
	else
	{
		printf("There were errors.\n");
	}
	return 0;
}