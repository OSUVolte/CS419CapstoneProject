/*
File: unittest1.c
Author: Elliot Bates
Description: Unit test for discard card function from dominion

getWinners
isGameover
buyCard
getcost
*/

/*
int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
{
	
  //if card is not trashed, added to Played pile 
  if (trashFlag < 1)
    {
      //add card to played pile
      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
      state->playedCardCount++;
    }
	
  //set played card to -1
  state->hand[currentPlayer][handPos] = -1;
	
  //remove card from player's hand
  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
    {
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
    {
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
  else 	
    {
      //replace discarded card with last card in hand
      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
      //set last card to -1
      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
	
  return 0;
}
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
	int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount, handPos;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
	int testHand1 = {copper, silver, gold, adventurer, smithy};
	int prePlayedCount, postPlayedCount;
	
	printf ("TESTING discardCard():\n");
    for (p = 0; p < numPlayer; p++) {
		for (handCount = 1; handCount <= maxHandCount; handCount++) {
			for (handPos = 0; handPos < handCount; handPos++) {
				// perform tests with no trash flag
				printf("Testing player %d with handCount %d, discarding card from handPos %d without trash flag.\n", p, handCount, handPos);
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
                memcpy(G.hand[p], testHand1, sizeof(int) * handCount); // copy across some random cards from the test hand
				prePlayedCount = G.playedCardCount;
				discardCard(handPos, p, &G, 0); //Call discard card without trash flag
				postPlayedCount = G.playedCardCount;
#if (NOISY_TEST == 1)
                printf("Top card in playedCards = %s, expected = %s.\n", G.playedCards[G.playedCardCount-1], testHand1[handPos]); // check correct card was added to played cards
				printf("Hand Count = %d, expected %d.\n", G.handCount[p], (handCount - 1)); // Check handcount has recreases
				if ((handPos != (handCount - 1)) && (handCount != 1)) { // ie is not the last card in the hand
					printf("Card switched with = %s, expected = %s\n", G.hand[p][handPos], testHand1[handCount - 1]); //Check that the card was switched with the expected card
				}
				printf("Played card count = %d, expected %d.\n", postPlayedCount, (prePlayedCount + 1)); //check played cards has increased by 1
#endif				
			}
		}
	}	
}



















