#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
//makefile was taken from https://github.com/aburasali/cs362sp16/blob/master/projects/batese/dominion/Makefile


//testing village card
/*
int card_Village(struct gameState *state, int handPos){
      int currentPlayer = whoseTurn(state);
      //+1 Card
      drawCard(currentPlayer, state);

      //+2 Actions
      state->numActions = state->numActions + 3;

      //discard played card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;


}

*/



int main(){
    struct gameState* g = malloc(sizeof(struct gameState));
	int expectedHandCountAfterVillage, expectednumActionsAfterVillage;
	int k[10] = {smithy, adventurer, feast, council_room, embargo, village, minion, mine, cutpurse, sea_hag, tribute};
	printf("\n\n Unit Test for Village\n");
    //initializing a game: 2 players, cards- see above, seed =100, and game
	initializeGame(2, k, 100, g);
    //for the village card, the user draws 1 card, so the hand count should go +1
	expectedHandCountAfterVillage = g->handCount[0];
	//expected number of action will be +2
	expectednumActionsAfterVillage =  g->numActions +2;
	//testing the current player
	printf("Hand Count before Village Card is Played: %d \n", g->handCount[0]);
	printf("Num Action before Village Card is Played: %d \n", g->numActions);

    //( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
    //play smithy card
	cardEffect(village, 0, 0, 0, g, 0, 0);
	printf("\nHand Count Of the Player after village Card is Played: \n\n");
	if(g->handCount[0] != expectedHandCountAfterVillage){
		printf("ERROR: Hand Count Should be: %d. Instead Hand Count is: %d \n", expectedHandCountAfterVillage, g->handCount[0]);
	}
	else{
		printf("No Errors were detected in the Village card. Hand Count is: %d\n", g->handCount[0]);
	}

	printf("\nNum Action Of the Player after village Card is Played: \n\n");
	if(g->numActions != expectednumActionsAfterVillage){
		printf("ERROR: Num Action Should be: %d. Instead Hand Count is: %d \n", expectednumActionsAfterVillage, g->numActions);
	}
	else{
		printf("No Errors were detected in the Village card. Num Action is: %d\n", g->numActions);
	}


	printf("\nunit Test: Council_room test successful \n");
return 0;
}

