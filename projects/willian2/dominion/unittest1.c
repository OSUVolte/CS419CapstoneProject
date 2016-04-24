/******************************************************************************
* ASSIGNMENT 3 - unittest1.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 04/24/2016
* NOTES: unit testing of the discardCard() function
* REQUIREMENTS for discardCard():
*  1. If card is not to be trashed, it must be placed in the played card pile
*  2. If card is to be trashed, it must count as removed from play (trash pile)
*  3. Only this card should be discarded
*  4. Only this player should have discarded
* TESTING tasks for discardCard():
*  1. Test if trashflag = 1, card is not placed in discard pile, 
*     playedCardCount is not incremented
*  2. Test if trashflag < 1, card is placed in discard pile and playedCardCount
*     is incremented
*  3. Test if last card is discarded, hand is empty
*  4. Test if only card is played, hand is empty
*  5. Test if hand is full (MAX_HAND cards in hand), and discardCard() is 
*     called MAX_HAND - 1 times, the last remaining card is the first card
*     in the hand
*  6. Test that no other players are affected by discardCard() 
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
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int player, r, handCount;
	int maxHandCount = 10;
    int trashflag;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	
	//create test hand where first card is copper, the rest is silver
	int testingHand[MAX_HAND];
	testingHand[1] = copper;
	for (i = 1; i < MAX_HAND; i++)
	{
		testingHand[i] = silver;
	}

    printf ("TESTING discardCard():\n");
    for (player = 0; player < numPlayer; player++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++) //start at one card
        {
            for (trashflag = 0; trashflag <= 1; trashflag++)
            {
#if (NOISY_TEST == 1)
                printf("Test player %d with %d card(s) and trashflag set to %d.\n", player, handCount, trashflag);
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[player] = handCount;            // set the number of cards on hand
                memcpy(G.hand[player], testingHand, sizeof(int) * handCount); // set to testingHand
                
				int j;
				int playedtrack = 0; //keeps track of how many cards should have been played
				
				for (j = (handCount - 1); j >= 0; j--)
				{
#if (NOISY_TEST == 1)
                printf("Discarding G.hand[%d][%d]\n", player, j);
#endif
					discardCard(j, player, &G, trashflag);
					if (trashflag == 0)
					{
						playedtrack++;
						assert(G.playedCardCount == playedtrack);
					}
					else if (trashflag == 1)
					{
						assert(G.playedCardCount == 0);
					}
					
					assert(G.hand[player][j] == -1);
					assert(G.handCount[player] == j);
					// if (j > 2) //there were three or more cards in the hand
					// {
						// assert(G.hand[player][j-1] == silver);
						// assert(G.hand[player][0] == copper);
					// }
					// else if (j == 1) //there were two cards in the hand
					// {
						// assert(G.hand[player][j-1] == copper);
					// }
				}
			}
        }
    }
	printf("All tests passed!\n");

	return 0;
}

