//Shawn Seibert
//Card Test 1
//adventureCard() 
//gcc cardtest1.c dominion.c rngs.c -o cardtest1 -lm

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
	int i = 0;
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
	testState.handCount[currentPlayer] = 4;
	printf("TESTING TOP CARD OF HAND\n");
	drawCard(currentPlayer, &testState);
	checkCardDraw = testState.handCount[currentPlayer];
	sleep(3);
	printf("Current top card: %d\n", checkCardDraw);

	cardDrawn = testState.hand[currentPlayer][testState.handCount[currentPlayer]]-1;//top card of hand is most recently drawn card.
	printf("Current new top card: %d\n", cardDrawn);
	if ((checkCardDraw-1) == cardDrawn)
	{
		printf("Test Passed: Card Drawn is top card.\n", i);
	}
	else
	{
		printf("Test Failed: Card Drawn is not top card.\n", i);
		break;
	}
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	{	
		printf("Draw Treasure: \n");
		drawntreasure++;
	}
	else
	{
		printf("Temp Hand: \n");
	  temphand[z]=cardDrawn;
	  testState.handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
	  z++;
	}
   }
      while(z-1>=0)
	  {
		checkCardDraw = testState.discard[currentPlayer][testState.discardCount[currentPlayer]++];

		testState.discard[currentPlayer][testState.discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
		z=z-1;
      }
      return 0;
}
