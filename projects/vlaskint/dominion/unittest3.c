#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "dominion.h"
//makefile was taken from https://github.com/aburasali/cs362sp16/blob/master/projects/batese/dominion/Makefile

/*

int isGameOver(struct gameState *state) {
  int i;
  int j;

  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0)
    {
      return 1;
    }

  //if three supply pile are at 0, the game ends
  j = 0;
  for (i = 0; i < 25; i++)
    {
      if (state->supplyCount[i] == 0)
	{
	  j++;
	}
    }
  if ( j >= 3)
    {
      return 1;
    }

  return 0;
}
*/


void testisGameOver() {
	printf("\n\ntesting isGameOver\n");
	struct gameState *g = malloc(sizeof(struct gameState));
	int k[10] = {smithy, adventurer, feast, council_room, embargo, village, minion, mine, cutpurse, sea_hag, tribute};
	initializeGame(2, k, 100, g);
	//when the game is initialized, none of the conditions that are required for the game to be over is complete, so
	//the game should be running.
	if( isGameOver(g) == 1 ){
		printf("ERROR: there is at least 1 province left, so the game should not have ended\n");
	} else if ( isGameOver(g) == 0 ){
		printf("The game is still running because there is at least 1 province left.\n");
	}
    //now lets check to make sure that the game will be over when the conditions for the end of the game is met
    //when province count =0, game ends
	g->supplyCount[province] = 0 ;
	if( isGameOver(g) == 1 ){
		printf("Game has ended because all provinces are gone\n");
	} else if ( isGameOver(g) == 0 ){
		printf("ERROR: game has not ended eventhough all provinces are gone.\n");
	}
    //game also ends when 3 supply piles are consumed
    //3 supply counters will be assigned to 0
      g->supplyCount[1] = 0;
      g->supplyCount[2] = 0;
      g->supplyCount[3] = 0;
	if( isGameOver(g) == 1 ){
		printf("Game has ended because 3 supply piles are consumed \n");
	}
	else if (isGameOver(g) == 0){
		printf("ERROR: Game has NOT ended even though 3 supply piles are consumed\n");
	}

}

int main () {
    testisGameOver();
    exit(0);
}



