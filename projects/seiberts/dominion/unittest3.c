//Shawn Seibert
//Unit test 3
//discardCard()
//gcc unittest3.c dominion.c rngs.c -o unittest3 -lm

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{

int handPos = 9;
int currentPlayer = 1;
struct gameState state, testState; 
int trashFlag;
int seed = 100;
int numPlayers = 2;
 testState.playedCardCount = 10;
int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, 
			smithy, council_room};

printf("-----------------Unit Test 3-1 ----------------------\n");	
printf("--------------- discardCard() ----------------------\n");
printf("Test 1: Set players hand count to 10 cards and remove one\n");
memcpy(&testState, &state, sizeof(struct gameState));
initializeGame(2, k, seed, &testState);
testState.handCount[currentPlayer] = 10;
	
  //if card is not trashed, added to Played pile 
  if (trashFlag < 1)
    {
      //add card to played pile
      testState.playedCards[testState.playedCardCount] = testState.hand[currentPlayer][handPos]; 
      testState.playedCardCount++;
    }
	printf("Current player hand count: %d\n", testState.handCount[currentPlayer]);
  //set played card to -1
  testState.hand[currentPlayer][handPos] = -1;

  //remove card from player's hand
  if ( handPos == (testState.handCount[currentPlayer] - 1) ) 	//last card in hand array is played
    {
      //reduce number of cards in hand
      printf("Remove 1 card.\n");
	  testState.handCount[currentPlayer]--;
    }
  else if ( testState.handCount[currentPlayer] == 1 ) //only one card in hand
    {
      //reduce number of cards in hand
	  printf("Remove last card.\n");
      testState.handCount[currentPlayer]--;
    }
  else 	
    {
      //replace discarded card with last card in hand
      testState.hand[currentPlayer][handPos] = testState.hand[currentPlayer][ (testState.handCount[currentPlayer] - 1)];
      //set last card to -1
      testState.hand[currentPlayer][testState.handCount[currentPlayer] - 1] = -1;
      //reduce number of cards in hand
      testState.handCount[currentPlayer]--;
    }
	printf("Current player hand count: %d\n", testState.handCount[currentPlayer]);
	
	if (testState.handCount[currentPlayer] == 9)
	{
		printf("Test 1: Passed.\n");
	}
	else
	{
		printf("Test 1: Failed.\n");
	}

printf("-----------------Unit Test 3-2 ----------------------\n");	
printf("--------------- discardCard() ----------------------\n");
printf("Test 2: Set players hand count to 1 cards and remove one\n");	
memcpy(&testState, &state, sizeof(struct gameState));
initializeGame(2, k, seed, &testState);
testState.handCount[currentPlayer] = 1;
	
  //if card is not trashed, added to Played pile 
  if (trashFlag < 1)
    {
      //add card to played pile
      testState.playedCards[testState.playedCardCount] = testState.hand[currentPlayer][handPos]; 
      testState.playedCardCount++;
    }
	printf("Current player hand count: %d\n", testState.handCount[currentPlayer]);
  //set played card to -1
  testState.hand[currentPlayer][handPos] = -1;

  //remove card from player's hand
  if ( handPos == (testState.handCount[currentPlayer] - 1) ) 	//last card in hand array is played
    {
      //reduce number of cards in hand
        printf("Remove 1 card.\n");
	  testState.handCount[currentPlayer]--;
    }
  else if ( testState.handCount[currentPlayer] == 1 ) //only one card in hand
    {
      //reduce number of cards in hand
       printf("Remove last card.\n");
	  testState.handCount[currentPlayer]--;
    }
  else 	
    {
      //replace discarded card with last card in hand
      testState.hand[currentPlayer][handPos] = testState.hand[currentPlayer][ (testState.handCount[currentPlayer] - 1)];
      //set last card to -1
      testState.hand[currentPlayer][testState.handCount[currentPlayer] - 1] = -1;
      //reduce number of cards in hand
      testState.handCount[currentPlayer]--;
    }
	printf("Current player hand count: %d\n", testState.handCount[currentPlayer]);
	
	if (testState.handCount[currentPlayer] == 0)
	{
		printf("Test 2: Passed.\n");
	}
	else
	{
		printf("Test 2: Failed.\n");
	}


  return 0;
}