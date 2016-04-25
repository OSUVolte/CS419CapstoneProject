#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "time.h"
#include "assert.h"

#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestLib.h"


/* Function to Be Tested
 *
 * Description: This card should reveal cards until 2 treasure cards have been revealed. After, all non 
 *    treasure cards should be discarded.
 *
 *    The way it works is:
 *	 WHILE less than 2 treasures have been drawn
 *	 IF deckCount for player is less than 1 shuffle discard into deck     //state affected - vars:deck[player]
 *	 - Draw a card for the player					      //state affected - vars:deck[player], deckCount[player], hand[player], handCount[player]
 *	 IF card drawn is copper, silver, or gold increment treasure count
 *	 ELSE set card aside to discard later, decrement the handcount by 1, and increase size of temporary hand. //state affected - vars:handCount[player]
 *	 END IF/ELSE
 *	 END IF
 *	 END WHILE
 *	 WHILE One minus the temporary count > 0
 *	 - Set the top of the discard pile equal to the card at the z-1 index in temporary hand
 *	 - Decrement z
 *
 * Eval: 
 *
 * The shuffle function doesn't shuffle the discard back into deck. It just shuffles the deck so if deckCount < 1,
 *    there may be an infinite loop.
 * The "top" card of the hand has been the last card in the players hand (ie. index = handCount-1), card for comparison
 *    won't be the right card
 */
/*
void adventurerCard(struct gameState *state, int currentPlayer, int* temphand){

  int drawntreasure=0;
  int cardDrawn;
  int z = 0;// this is the counter for the temp hand

   while(drawntreasure<2){
      if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
	 shuffle(currentPlayer, state);
      }
      drawCard(currentPlayer, state);
      cardDrawn = state->hand[currentPlayer][0];//top card of hand is most recently drawn card.
      if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
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
   return;
}
*/
int noTreasureInDeckOrDiscardTest(struct gameState* state){

   int* tempHand = malloc(MAX_HAND * sizeof(int));
   memset(tempHand, 0, MAX_HAND * sizeof(int));

   state->numPlayers = 2;
   state->deckCount[0] = 5;

   int i;
   for(i = 0;  i < state->deckCount[0]; i++){
      state->deck[0][i] = 10;
   }
   state->handCount[0] = 5;
   for(i = 0;  i < state->handCount[0]; i++){
      state->hand[0][i] = 5;
   }
   state->discardCount[0] = 5;
   for(i = 0;  i < state->discardCount[0]; i++){
      state->discard[0][i] = 10;
   }

   adventurerCard(state, 0, tempHand);
   //Game should enter infinite loop with no treasure in deck or discard
   free(tempHand);
   return 0;
}

int unitTest(){

   printf("\n+--------------------------------CARD TEST 1----------------------------+\n");
   //Create Zeroed Gamestate;
   struct gameState* testState = (struct gameState*)(malloc(sizeof(struct gameState)));
   memset(testState, 0, sizeof(struct gameState));
   int i, retVal = 0;

   
   printf("\n+------noTreasureInDeckOrDiscardTest------+\n\n");
   retVal = noTreasureInDeckOrDiscardTest(testState);
   if(retVal == 0){
      printf("noTresureInDeckOrDiscardTest -1: Test Failed, Card Found Non Existant Treaures\n");
   } else {
      printf("noTreasureInDeckOrDiscardTest: Successful\n");
   }
   free(testState);
   return retVal;
}

int main(){
   int testVal = unitTest();
   printf("Outcome: %i\n", testVal);
   return testVal;
}


