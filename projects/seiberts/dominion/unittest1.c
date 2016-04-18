//Shawn Seibert
//Unit test 1
//updateCoins()


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
int player = 1;
struct gameState game, state;
int bonus;
int i;
int seed = 100;
int numPlayers = 2;
int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, 
			smithy, council_room};

			initializeGame(numPlayers, k, seed, &game);

printf("-----------------Unit Test 1 ----------------------");	
printf("--------------- updateCoins() ----------------------");
  //reset coin count
  state->coins = 0;
  //add coins for each Treasure card in player's hand
  for (i = 0; i < state->handCount[player]; i++)
    {
      if (state->hand[player][i] == copper)
	{
	  state->coins += 1;
	}
      else if (state->hand[player][i] == silver)
	{
	  state->coins += 2;
	}
      else if (state->hand[player][i] == gold)
	{
	  state->coins += 3;
	}	
    }	

  //add bonus
  state->coins += bonus;

  return 0;
}