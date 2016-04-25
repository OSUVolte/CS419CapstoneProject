#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
//makefile was taken from https://github.com/aburasali/cs362sp16/blob/master/projects/batese/dominion/Makefile

//testing adventure card
/*
int card_Adventurer(struct gameState *state)
{
  //current player
  int currentPlayer = whoseTurn(state);
  //this should just remove the top card (the most recently drawn one).
  //this variable is needed in case a funciton that was drawn is not the treasure function
  int temphand[MAX_HAND];
  //count the treasures that were drawn
  int drawntreasure = 0;
  //counts the cards that were drawn
  int cardDrawn = 0;
  //used for the indexing of the temphand array
  int z = 0;


   while(drawntreasure<2){
	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
	  shuffle(currentPlayer, state);
	}
	drawCard(currentPlayer, state);
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn != gold)
	  drawntreasure++;
	else{
	  temphand[z]=cardDrawn;
	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
	  z++;
	}
      }
      while(z-1>=0){
	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
	z=z-1;
      }
     return 0;
}


*/


int main(){
    struct gameState* g = malloc(sizeof(struct gameState));
	int expectedHandCountAfterAdventure;
	int k[10] = {smithy, adventurer, feast, council_room, embargo, village, minion, mine, cutpurse, sea_hag, tribute};
	printf("\n\n Unit Test for ADVENTURE\n");
    //initializing a game: 2 players, cards- see above, seed =100, and game
	initializeGame(2, k, 100, g);
/*
    Adventure is an action card with the terminal action that digs for treasure cards in the deck. The palayer
    draws cards from their deck until they get 2 treasure cards. The treasure cards are added to the deck of the
    player and the rest of the cards that were revealed are placed in the discard pile. In case the deck is empty
    before the player find 2 treasure cards, the discarded cards are shuffled and placed on the deck.
    */
	//Based on the description above, after the adventure card is played, the handcount should go up +2
	expectedHandCountAfterAdventure = g->handCount[0] + 2;
	printf("Hand Count before Adventure Card is Played: %d \n", g->handCount[0]);
    //( cardEffect(card, choice1, choice2, choice3, state, handPos, &coin_bonus) < 0 )
    //play smithy card
	cardEffect(adventurer, 0, 0, 0, g, 0, 0);
	printf("\nHand Count after Adventure Card is Played: \n\n");
	if(g->handCount[0] != expectedHandCountAfterAdventure){
		printf("ERROR: Hand Count Should be: %d. Instead Hand Count is: %d \n", expectedHandCountAfterAdventure, g->handCount[0]);
	}
	else{
		printf("No Errors were detected in the Adventure card. Hand Count is: %d\n", g->handCount[0]);
	}
	printf("\nunit Test: Adventure test successful \n");
return 0;
}
