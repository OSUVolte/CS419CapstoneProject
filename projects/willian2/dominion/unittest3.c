/******************************************************************************
* ASSIGNMENT 3 - unittest3.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 04/24/2016
* NOTES: unit testing of the scoreFor() function
* REQUIREMENTS for scoreFor():
*  1. Count scoring cards in deck
*  2. Count scoring cards in hand
*  3. Count scoring cards in discard
*  4. Return total score for each area
* TESTING tasks for discardCard():
*  1. Test that scoring cards in each area are counted
*  2. Test that total score is caluclated correctly
*  3. Test that each player's score is calculated
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
    int player, r, deckCount, handCount, discardCount, result, failflag;
	int maxCardCount = 10;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	int scoringCards[] = {curse, estate, duchy, province, great_hall, gardens};
	int cardValues[] = {-1, 1, 3, 6, 1, 0};
	int totalCount, gardenCount, totalScore;

    printf ("TESTING fullDeckCount():\n");
    for (player = 0; player < numPlayer; player++)
    {
		int cardType, cardPosition;
		for (cardType = 0; cardType <= 5; cardType++)
		{
			for (deckCount = 0; deckCount <= maxCardCount; deckCount++)
			{
				for (handCount = 0; handCount <= maxCardCount; handCount++)
				{
					for (discardCount = 0; discardCount <= maxCardCount; discardCount++)
					{
						gardenCount = 0;
						totalCount = 0;
						totalScore = 0;
						//create test decks for this *Count (deck,hand,discard)
						int testDeck[deckCount];
						for (cardPosition = 0; cardPosition < deckCount; cardPosition++)
						{
							testDeck[cardPosition] = scoringCards[cardType];
							totalScore = totalScore + cardValues[cardType];
							if (cardType == 5)
							{
								gardenCount++;
							}
						}
						
						int testHand[handCount];
						for (cardPosition = 0; cardPosition < deckCount; cardPosition++)
						{
							testHand[cardPosition] = scoringCards[cardType];
							totalScore = totalScore + cardValues[cardType];
							if (cardType == 5)
							{
								gardenCount++;
							}
						}
						
						int testDiscard[discardCount];
						for (cardPosition = 0; cardPosition < deckCount; cardPosition++)
						{
							testDiscard[cardPosition] = scoringCards[cardType];
							totalScore = totalScore + cardValues[cardType];
							if (cardType == 5)
							{
								gardenCount++;
							}
						}
						
#if (NOISY_TEST == 1)
						printf("Total count = %d\n", totalCount);
#endif
						if (gardenCount != 0)
						{
							totalCount = deckCount + handCount + discardCount;
#if (NOISY_TEST == 1)
							printf("Garden count = %d\n", gardenCount);
#endif
							totalScore = totalScore + ((totalCount / 10) * gardenCount);
						}

						memset(&G, 23, sizeof(struct gameState));   // clear the game state
						r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
						G.deckCount[player] = deckCount;            // set the number of cards on deck
						G.handCount[player] = handCount;            // set the number of cards on hand
						G.discardCount[player] = discardCount;      // set the number of cards on discard
											
						memcpy(G.deck[player], testDeck, sizeof(int) * deckCount); // set to testDeck
						memcpy(G.hand[player], testHand, sizeof(int) * handCount); // set to testHand
						memcpy(G.discard[player], testDiscard, sizeof(int) * discardCount); // set to testDiscard
						
						result = scoreFor(player, &G);
						if (result != totalScore)
						{
							failflag = 1;
						}
#if (NOISY_TEST == 1)
						printf("scoreFor = %d, expected %d\n", result, totalScore);
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