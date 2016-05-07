#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
//makefile was taken from https://github.com/aburasali/cs362sp16/blob/master/projects/batese/dominion/Makefile


//testing council_room card
/*
int card_Council_Room(struct gameState *state, int handPos){
  int i;
  int currentPlayer = whoseTurn(state);
      for (i = 0; i < 4; i++)
	{
	  drawCard(currentPlayer, state);
	}

      //+1 Buy
      //state->numBuys++;

      //Each other player draws a card
      for (i = 0; i < state->numPlayers; i++)
	{
	  if ( i != currentPlayer )
	    {
	      drawCard(i, state);
	      //drawCard(i, state);
	    }
	}

      //put played card in played card pile
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
  }


*/



int main(){
    struct gameState* g = malloc(sizeof(struct gameState));
	int expectedHandCountAfterCouncil_room, expectedHandCountAfterCouncil_room2;
	int k[10] = {smithy, adventurer, feast, council_room, embargo, village, minion, mine, cutpurse, sea_hag, tribute};
	printf("\n\n Unit Test for council_room\n");
    //initializing a game: 2 players, cards- see above, seed =100, and game
	initializeGame(2, k, 100, g);
	//Based on the original Council_room function [ the one wihout bug], after the Council_room card is played,
	//the handcount of the current player should go up + 4
	//and the count of all other players should be handout +1
	//current player
	expectedHandCountAfterCouncil_room = g->handCount[0] + 4;
	//all other players
	expectedHandCountAfterCouncil_room2 = g->handCount[1] + 1;
	//testing the current player
	printf("Hand Count of the CURRENT player before council_room Card is Played: %d \n", g->handCount[0]);
	printf("Hand Count of the OTHER player before council_room Card is Played: %d \n", g->handCount[1]);
    //( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
    //play smithy card
	cardEffect(council_room, 0, 0, 0, g, 0, 0);
	printf("\nHand Count Of the CURRENT Player after council_room Card is Played: \n\n");
	if(g->handCount[0] != expectedHandCountAfterCouncil_room){
		printf("ERROR: Hand Count Should be: %d. Instead Hand Count is: %d \n", expectedHandCountAfterCouncil_room, g->handCount[0]);
	}
	else{
		printf("No Errors were detected in the Council_room card. Hand Count is: %d\n", g->handCount[0]);
	}

    printf("\nHand Count Of the OTHER Player after council_room Card is Played: \n\n");
	if(g->handCount[1] != expectedHandCountAfterCouncil_room2){
		printf("ERROR: Hand Count Should be: %d. Instead Hand Count is: %d \n", expectedHandCountAfterCouncil_room2, g->handCount[1]);
	}
	else{
		printf("No Errors were detected in the Council_room card. Hand Count is: %d\n", g->handCount[1]);
	}
	printf("\nunit Test: Council_room test successful \n");
return 0;
}

