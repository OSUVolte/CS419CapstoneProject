#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
//makefile was taken from https://github.com/aburasali/cs362sp16/blob/master/projects/batese/dominion/Makefile
/*
int card_Smithy(struct gameState *state, int handPos)
{
  int i;
  int currentPlayer = whoseTurn(state);
  // + 3 cards
  for (i = 1; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  }

  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}

*/

int main(){
    struct gameState* g = malloc(sizeof(struct gameState));
	int expectedHandCountAfterSmithy;
	int k[10] = {smithy, adventurer, feast, council_room, embargo, village, minion, mine, cutpurse, sea_hag, tribute};
	printf("\n\n Unit Test for SMITHY\n");
    //initializing a game: 2 players, cards- see above, seed =100, and game
	initializeGame(2, k, 100, g);
/*
    Smithy is a terminal card, meaning it provides no +Action. This card lets the user to draw 3 additional cards.
    The implementation of the card is a simple for loop that calles the drawCard(currentPlayer, state) method 3 times.
    After 3 cards are drawn, the discardCard(handPos, currentPlayer, state, 0) method is called to discard the smithy
    card to the discarded pile.
    */
	//if 3 cards are drawn and then smithy card is discarded, we will expect that the handCount will be handCount + 2
	expectedHandCountAfterSmithy = g->handCount[0] + 2;
	printf("Hand Count before Smithy Card is Played: %d \n", g->handCount[0]);
    //( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
    //play smithy card
	cardEffect(smithy, 0, 0, 0, g, 0, 0);
	printf("\nHand Count after Smithy Card is Played: \n\n");
	if(g->handCount[0] != expectedHandCountAfterSmithy){
		printf("ERROR: Hand Count Should be: %d. Instead Hand Count is: %d \n", expectedHandCountAfterSmithy, g->handCount[0]);
	}
	else{
		printf("No Errors were detected in the Smithy card.\n", g->handCount[0]);
	}
	printf("\nunit Test: Smithy test successful \n");
return 0;
}

