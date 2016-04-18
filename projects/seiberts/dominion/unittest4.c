//Shawn Seibert
//Unit test 4
//playCard()

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{
int handPos;
int choice1;
int choice2;
int choice3;
struct gameState *state; 
int card;
int coin_bonus = 0; 		//tracks coins gain from actions
int seed = 100;
int numPlayers = 2;
int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, 
			smithy, council_room};

			initializeGame(numPlayers, k, seed, &game);

printf("-----------------Unit Test 4-1 ----------------------");	
printf("----------------- playCard() ----------------------");

  //check if it is the right phase
  if (state->phase != 0)
    {
      return -1;
    }
	
  //check if player has enough actions
  if ( state->numActions < 1 )
    {
      return -1;
    }
	
  //get card played
  card = handCard(handPos, state);
	
  //check if selected card is an action
  if ( card < adventurer || card > treasure_map )
    {
      return -1;
    }
	
  //play card
  if ( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
    {
      return -1;
    }
	
  //reduce number of actions
  state->numActions--;

  //update coins (Treasure cards may be added with card draws)
  updateCoins(state->whoseTurn, state, coin_bonus);
	
  return 0;
}