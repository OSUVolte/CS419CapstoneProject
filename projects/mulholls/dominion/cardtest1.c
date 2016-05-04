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

void adventurerCard(struct gameState*, int, int*);
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
int basicTest(struct gameState* state){

   int* tempHand = malloc(MAX_HAND * sizeof(int));
   memset(tempHand, 0, MAX_HAND * sizeof(int));

   state->numPlayers = 2;
   state->deckCount[0] = 27;

   int i;
   //Deck should include at one copper, one silver, and one gold to be found
   for(i = 0;  i < state->deckCount[0]; i++){
      state->deck[0][i] = gardens;
      if(i > 4 && i < 8){
    	  state->deck[0][i] = copper;
      }
   }
   state->handCount[0] = 5;
   for(i = 0;  i < state->handCount[0]; i++){
      state->hand[0][i] = copper;
   }
   state->discardCount[0] = 10;
   for(i = 0;  i < state->discardCount[0]; i++){
      state->discard[0][i] = i;
   }

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   adventurerCard(state, 0, tempHand);

   //Only copper in Deck, so last two cards in hand must be copper
   if(state->hand[0][state->handCount[0]-1] != copper &&
	  state->hand[0][state->handCount[0]-2] != copper){
	   return -1;
   }

   //2 new copper cards added to hand, and adventurer discarded
   if(state->handCount[0] != cpy->handCount[0]+1){
	   return -2;
   }

   //Takes 5 draws to find the first copper
   if(state->discardCount[0] != cpy->discardCount[0]+5){
	   return -3;
   }
   //Wrong card discarded, only copper and gardens in deck
   if(state->discard[0][state->discardCount[0]-1] != gardens){
	   return -4;
   }

   //Card should exit normally as expected
   free(tempHand);
   return 0;
}

//Corrects a state difference in state by matching to cpy's state
//Returns the unitTestLib code for which state variable was affected.
int _stateTestHelper(struct gameState* state, struct gameState* cpy, int i){
   int j;
   int retVal = abs(checkState(cpy, state));
   switch (retVal){

     case 11:
		 for(j = 0; j < MAX_HAND; j++){
			state->hand[i][j] = cpy->hand[i][j];
		 }
		 return 11;

     case 12:
		 state->handCount[i] = cpy->handCount[i];
		 return 12;

     case 13:
		 for(j = 0; j < MAX_DECK; j++){
			state->discard[i][j] = cpy->discard[i][j];
		 }
		 return 13;

     case 14:
		 state->discardCount[i] = cpy->discardCount[i];
		 return 14;

     case 15:
    	  for(j = 0; j < MAX_DECK; j++){
    		  state->playedCards[j] = cpy->playedCards[j];
    	  }
		 return 15;

     case 16:
		 state->playedCardCount = cpy->playedCardCount;
		 return 16;

     case 17:
    	 state->deckCount[i] = cpy->deckCount[i];
    	 return 17;

     case 18:

		 for(j = 0; j < MAX_DECK; j++){
			 state->deck[i][j] = cpy->deck[i][j];
		 }
		 return 18;

      default:
	 if(retVal){
	    return retVal;
	 } else {
	    return 0;
	 }
   }
}

int _stateTrackerChecker(int* tracker){
   int i;
   int count = 0;
   for(i = 0; i < 19; i++){
      if(tracker[i] > 0){
	 count++;
      }
   }
   return count;
}

int stateTest(struct gameState* state, int expectedStateChanges){

   int* tempHand = malloc(MAX_HAND * sizeof(int));
   memset(tempHand, 0, MAX_HAND * sizeof(int));

   int* stateTracker = (int*)(malloc(19*sizeof(int)));
   memset(stateTracker, 0, 19*sizeof(int));

   int i, retVal;

   state->numPlayers = 2;
   state->deckCount[0] = 27;

   //Deck should include at one copper, one silver, and one gold to be found
   for(i = 0;  i < state->deckCount[0]; i++){
      state->deck[0][i] = i;
   }
   state->handCount[0] = 5;

   //Fill hand with copper
   for(i = 0;  i < state->handCount[0]; i++){
      state->hand[0][i] = copper;  //<-------CAUSES ENDLESS LOOP IF hand[0] != treasure
   }
   state->discardCount[0] = 10;
   for(i = 0;  i < state->discardCount[0]; i++){
      state->discard[0][i] = i;
   }

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   adventurerCard(state, 0, tempHand);
   do{

      retVal = _stateTestHelper(state, cpy, 0);
      if(retVal){
    	  stateTracker[retVal]++;
    	  if(stateTracker[retVal] > 1){
    		  printf("stateTest %i: Can't Clear State Error\n", retVal);
    		  return -retVal;
    	  }
      }
   } while (retVal);

   int sc = _stateTrackerChecker(stateTracker);

   if(sc != expectedStateChanges){
	   printf("stateTest -1: State error, %i Extra Changes\n", sc-expectedStateChanges);
	   return -1;
   }
   free(stateTracker);
   free(cpy);
   free(tempHand);
   return 0;
}

int discardTest(struct gameState* state){

   int* tempHand = malloc(MAX_HAND * sizeof(int));
   memset(tempHand, 0, MAX_HAND * sizeof(int));

   state->numPlayers = 2;
   state->deckCount[0] = 27;

   int i;
   //Deck should include at one copper, one silver, and one gold to be found
   for(i = 0;  i < state->deckCount[0]; i++){
      state->deck[0][i] = i;
   }
   state->handCount[0] = 5;
   for(i = 5;  i < 5 + state->handCount[0]; i++){
      state->hand[0][i-5] = i;
   }
   state->discardCount[0] = 10;
   for(i = 0;  i < state->discardCount[0]; i++){
      state->discard[0][i] = i;
   }

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   adventurerCard(state, 0, tempHand);
   if(state->discardCount[0] != cpy->discardCount[0]+1){
	   free(cpy);
	   free(tempHand);
	   return -1;
   }
   //Card should exit normally as expected
   free(cpy);
   free(tempHand);
   return 0;
}

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

int noCardsInDeckTest(struct gameState* state){

   int* tempHand = malloc(MAX_HAND * sizeof(int));
   memset(tempHand, 0, MAX_HAND * sizeof(int));

   state->numPlayers = 2;
   state->deckCount[0] = 0;
   state->handCount[0] = 5;
   state->discardCount[0] = 5;

   int i;
   for(i = 0;  i < state->deckCount[0]; i++){
      state->deck[0][i] = 10;
   }

   for(i = 0;  i < state->handCount[0]; i++){
      state->hand[0][i] = 5;
   }

   for(i = 0;  i < state->discardCount[0]; i++){
      state->discard[0][i] = 10;
   }

   adventurerCard(state, 0, tempHand);
   //Game should enter infinite loop with no treasure in deck or discard
   free(tempHand);
   return 0;
}

int unitTest(){

   printf("\n+--------------------------------ADVENTURER CARD TEST----------------------------+\n");
   //Create Zeroed Gamestate;
   struct gameState* testState = (struct gameState*)(malloc(sizeof(struct gameState)));
   memset(testState, 0, sizeof(struct gameState));
   int retVal = 0;

   printf("\n+------basicTest------+\n\n");
   retVal = basicTest(testState);
   if(retVal != 0){
      printf("basicTest -1: Test Failed, \n");
   } else {
      printf("basicTest: Successful\n");
   }
   memset(testState, 0, sizeof(struct gameState));

   printf("\n+--------stateTest----------+\n\n");
   //Checks to ensure no values in current state are changed after function
   retVal = stateTest(testState, 8);// Expected: hand, handCount, deck, deckCount, discard, discardCount, played, playedCount
   if(retVal){
	   printf("stateTest %i: Failed State Test\n", retVal);
	   //return -3;
   } else {
		   printf("stateTest: Successful\n");
   }
   
   printf("\n+--------discardTest----------+\n\n");
   //Checks to ensure Adventurer Card is Discarded
   retVal = discardTest(testState);
   if(retVal){
	   printf("discardTest %i: Failed Discard Test\n", retVal);
	   //return -3;
   } else {
		   printf("discardTest: Successful\n");
   }

   printf("\n+------noTreasureInDeckOrDiscardTest------+\n\n");
   retVal = noTreasureInDeckOrDiscardTest(testState);
   if(retVal == 0){
      printf("noTresureInDeckOrDiscardTest -1: Test Failed, Card Found Non Existent Treasures\n");
   } else {
      printf("noTreasureInDeckOrDiscardTest: Successful\n");
   }
   memset(testState, 0, sizeof(struct gameState));

   printf("\n+------noCardsInDeckTest------+\n\n");
    retVal = noCardsInDeckTest(testState);
    if(retVal == 0){
       printf("noCardsInDeckTest -1: Test Failed, Treasure Found When Deck Empty\n");
    } else {
       printf("noCardsInDeckTest: Successful\n");
    }

   free(testState);
   return retVal;
}

int main(){
   int testVal = unitTest();
   printf("Outcome: %i\n", testVal);
   return 0;
}


