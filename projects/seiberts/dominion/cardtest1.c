//Shawn Seibert
//Card Test 1
//adventureCard() 

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int player = 1;
	struct gameState state, testState;
	int bonus;
	int checkCardDraw;
	int seed = 100;
	int numPlayers = 2;
	int drawTotal = 3;
	int loopCount = 0;
	int drawntreasure = 0;
	int cardDrawn = 0;
	int currentPlayer = 1;
	int handPos = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, 
				smithy, council_room};
	int temphand[MAX_HAND];
	int z = 0;			

	printf("-------------------ADVENTURE CARD TEST ---------------------\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, &testState);


	
	while(drawntreasure < 2){
	if (testState.deckCount[currentPlayer] <1)
	{//if the deck is empty we need to shuffle discard and add to deck
	  shuffle(currentPlayer, &testState);
	}
	drawCard(currentPlayer, &testState);
	checkCardDraw = testState.hand[currentPlayer][testState.handCount[currentPlayer]]
	cardDrawn = testState.hand[currentPlayer][testState.handCount[currentPlayer]]-1;//top card of hand is most recently drawn card.
	
	
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	  drawntreasure++;
	else
	{
	  temphand[z]=cardDrawn;
	  testState.handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
	  z++;
	}
      }
      while(z-1>=0)
	  {
		testState.discard[currentPlayer][testState.discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
		z=z-1;
      }
      return 0;
}
