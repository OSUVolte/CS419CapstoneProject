/*
File: cardtest4.c
Author: Elliot Bates
Description: Unit test for the council_room card function in dominion.c (8)
*/

/*
int council_roomCard(int currentPlayer, struct gameState *state, int handPos) {
  //+4 Cards
  int i;
      for (i = 0; i < 4; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //+1 Buy
      state->numBuys++;
			
      //Each other player draws a card
      for (i = 1; i < state->numPlayers; i++)
	{
	  if ( i != currentPlayer )
	    {
	      drawCard(i, state);
	    }
	}
			
      //put played card in played card pile
      discardCard(handPos, currentPlayer, state, 0);
			
      return 0;
}
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int i, r, p, otherPlayer; 					 				
	int c1, c2;								// cards
	int pos;
	int seed = 1000;
	int numPlayers = 2;  					// players for valid gamestate
	struct gameState O;						// original gameState
	struct gameState G;						// test gameState
	int k[10] = {village, council_room, embargo, adventurer, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	int handPos;
	int maxHandPos = 4;

	printf("Testing COUNCIL_ROOM card.\n");
	for (p = 0; p < numPlayers; p++) {
		for (handPos = 0; handPos < maxHandPos; handPos++) {
			printf("Testing for player %d and handPos %d.\n", p, handPos);
			//Create game state
			memset(&O, 23, sizeof(struct gameState));   // clear the game state
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			r = initializeGame(numPlayers, k, seed, &O); // initialize a new game
			O.whoseTurn = p; //set players turn
			if (p != 0) { //If not first player need to draw first hand
				  for (i = 0; i < 5; i++){
					drawCard(O.whoseTurn, &O);
				  }
			}
			O.hand[p][handPos] = 8; //int for coincil_room card
			memcpy(&G, &O, sizeof(struct gameState)); // Copy game state
			//play card
			cardEffect(council_room, 0, 0, 0, &G, handPos, 0);
			
			//Check player has gained 4 cards
			if (G.handCount[p] == O.handCount[p] + 3)
				printf("PASSED: New hand count = %d, expected = %d.\n", G.handCount[p], O.handCount[p] + 3);
			else
				printf("FAILED: New hand count = %d, expected = %d.\n", G.handCount[p], O.handCount[p] + 3);
			
			//check player has gained 1 buy
			if (G.numBuys == O.numBuys + 1)
				printf("PASSED: New num buys = %d, expected = %d.\n", G.numBuys, O.numBuys + 1);
			else
				printf("FAILED: New num buys = %d, expected = %d.\n", G.numBuys, O.numBuys + 1);
			
			//check all other players have gained 1 card
			for (otherPlayer = 0; otherPlayer < numPlayers; otherPlayer++) {
				if (otherPlayer != p) { //i.e. is another player
					if (G.handCount[otherPlayer] == O.handCount[otherPlayer] + 1)
						printf("PASSED: Player %d new hand count = %d, expected = %d.\n", otherPlayer, G.handCount[otherPlayer], O.handCount[otherPlayer] + 1);
					else
						printf("FAILED: Player %d new hand count = %d, expected = %d.\n", otherPlayer, G.handCount[otherPlayer], O.handCount[otherPlayer] + 1);
				}
			}
		}
	}
	return 0;
}