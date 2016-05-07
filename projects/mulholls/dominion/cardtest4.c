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
 * Description: This card should add 2 cards, add 2 coins, or trash 2 cards from
 * 	the players hand
 *
 *    The way it should work is:
 *			-If choice1, the player should draw two cards
 *			-If choice2, the player should get 2 coins added
 *			-If choice3, the player should trash 2 cards
 *			-The steward card is discarded
 *
 * Eval:
 *
 *	There are extra choices not necessary in the function call.
 *	Everything else looks ok
 *
*/
void stewardCard(struct gameState*, int, int, int, int, int);
/*
void stewardCard(struct gameState* state, int currentPlayer, int handPos, int choice1, int choice2, int choice3){
   if (choice1 == 1)
   {
      //+2 cards
      drawCard(currentPlayer, state);
      drawCard(currentPlayer, state);
   }
   else if (choice1 == 2)
   {
      //+2 coins
      state->coins = state->coins + 2;
   }
   else
   {
      //trash 2 cards in hand
      discardCard(choice2, currentPlayer, state, 1);
      discardCard(choice3, currentPlayer, state, 1);
   }
	       
   //discard card from hand
   discardCard(handPos, currentPlayer, state, 0);
   return;
}
*/
int basicTest(struct gameState* state){

   state->numPlayers = 2;
   state->deckCount[0] = 27;

   int i;
   //Deck should include at one copper, one silver, and one gold to be found
   for(i = 0;  i < state->deckCount[0]; i++){
      state->deck[0][i] = gardens;
   }
   state->handCount[0] = 5;
   for(i = 5;  i < 5 + state->handCount[0]; i++){
      state->hand[0][i-5] = steward;
   }
   state->discardCount[0] = 10;
   for(i = 0;  i < state->discardCount[0]; i++){
      state->discard[0][i] = i;
   }

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));
   //Check all 3 choices
   for(int i = 1; i < 4; i++){
	   stewardCard(state, 0, 0, i, 0, 0);
	   //Add 2 cards
	   if(i == 1){
		   if(state->handCount[0] != cpy->handCount[0]+1){
			   free(cpy);
			   return -11;
		   }
		   if(state->hand[0][state->handCount[0]-1] != gardens){
			   free(cpy);
			   return -12;
		   }
		   if(state->discardCount[0] != cpy->discardCount[0]+1){
			   free(cpy);
			   return -13;
		   }
	   //Add two coins
	   } else if (i == 2){
		   if(state->coins != cpy->coins+2){
			   free(cpy);
			   return -21;
		   }
		   if(state->discardCount[0] != cpy->discardCount[0]+1){
			   free(cpy);
			   return -22;
		   }
	   //Trash two cards
	   } else {
		   if(state->handCount[0] != cpy->handCount[0] -3){
			   free(cpy);
			   return -31;
		   }
		   if(state->discardCount[0] != cpy->discardCount[0]+3){
			   free(cpy);
			   return -32;
		   }
	   }

	   if(state->discard[0][state->discardCount[0]-1] != steward){
		   free(cpy);
		   return -4;
	   }
	   //reset state to try next choice
	   memcpy(state, cpy, sizeof(struct gameState));
   }
   free(cpy);
   return 0;
}

int _stateTestHelper(struct gameState* state, struct gameState* cpy, int i){
   int j;
   int retVal = abs(checkState(cpy, state));

   switch (retVal){

     case 8:
    	 state->numActions = cpy->numActions;
    	 return 8;

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

int stateTest(struct gameState* state){

   int* stateTracker = (int*)(malloc(19*sizeof(int)));
   memset(stateTracker, 0, 19*sizeof(int));

   int i, retVal;
   state->numPlayers = 2;
   state->deckCount[0] = 27;

   for(i = 0;  i < state->deckCount[0]; i++){
      state->deck[0][i] = i;
   }
   state->handCount[0] = 5;
   for(i = 5;  i < 5 + state->handCount[0]; i++){
      state->hand[0][i-5] = steward;
   }
   state->discardCount[0] = 10;
   for(i = 0;  i < state->discardCount[0]; i++){
      state->discard[0][i] = i;
   }

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   for(int i = 1; i < 4; i++){
   	   stewardCard(state, 0, 0, i, 0, 0);

   	   do{

   	      retVal = _stateTestHelper(state, cpy, 0);
   	      if(retVal){
   	    	  stateTracker[retVal]++;
   	    	  if(stateTracker[retVal] > 1){
   	    		  printf("stateTest %i: Can't Clear State Error\n", retVal);
   	    		  return -1;
   	    	  }
   	      }
   	   } while (retVal);

   	   int errorCode = i * -10;

   	   if (i == 2){
   	   	   //coins should change
   	   	   if(!stateTracker[10]){
   	   		   return errorCode-9;
   	   	   }
   	   }

   	   //Hand Should change
	   if(!stateTracker[11]){
		   return errorCode-1;
	   }
	   //Hand Count Should CHange
	   if(!stateTracker[12]){
		   return errorCode-2;
	   }
	   //discard should change
	   if(!stateTracker[13]){
		   return errorCode-3;
	   }
	   //discard count
	   if(!stateTracker[14]){
		   return errorCode-4;
	   }
	   //playedCards
	   if(!stateTracker[15]){
		   return errorCode-5;
	   }
	   //PlayedCardCount
	   if(!stateTracker[16]){
		   return errorCode-6;
	   }
	   //deckCount
	   if(!stateTracker[17]){
		   return errorCode-7;
	   }
	   //deck should change
	   if(!stateTracker[18]){
		   return errorCode-8;
	   }

   	   int sc = _stateTrackerChecker(stateTracker);

   	   int expectedStateChanges = 0;
   	   if(i == 1){
   		   expectedStateChanges = 8;
   	   } else if (i == 2){
   		   expectedStateChanges = 9;
   	   } else {
   		   expectedStateChanges = 8;
   	   }
   	   if(sc != expectedStateChanges){
   		   printf("stateTest -4: State error, %i Extra Changes\n", sc-expectedStateChanges);
   		   return -4;
   	   }
   	   //reset state to try next choice
   	   memcpy(state, cpy, sizeof(struct gameState));
   }


   free(stateTracker);
   free(cpy);
   return 0;
}

int discardTest(struct gameState* state){

   state->numPlayers = 2;
   state->deckCount[0] = 27;

   int i;
   //Deck should include at one copper, one silver, and one gold to be found
   for(i = 0;  i < state->deckCount[0]; i++){
      state->deck[0][i] = i;
   }
   state->handCount[0] = 5;
   for(i = 5;  i < 5 + state->handCount[0]; i++){
      state->hand[0][i-5] = village;
   }
   state->discardCount[0] = 10;
   for(i = 0;  i < state->discardCount[0]; i++){
      state->discard[0][i] = i;
   }

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   for(i = 1; i < 4; i++){
	   stewardCard(state, 0, 0, i, 0, 0);
	   int errorCode = i * -10;
	   if(state->discardCount[0] != cpy->discardCount[0]+1){
		   free(cpy);
		   return errorCode-1;
	   }

	   if(state->discard[0][state->discardCount[0]-1] != village){
		   free(cpy);
		   return errorCode-2;
	   }

	   memcpy(state, cpy, sizeof(struct gameState));
   }

   //Card should exit normally as expected
   free(cpy);
   return 0;
}

int totalCardCountTest(struct gameState* state){

   state->numPlayers = 2;
   state->deckCount[0] = 27;

   int i;
   //Deck will contain one of each card
   for(i = 0;  i < state->deckCount[0]; i++){
      state->deck[0][i] = i;
   }
   //Fill hand with steward cards
   state->handCount[0] = 5;
   for(i = 5;  i < 5 + state->handCount[0]; i++){
      state->hand[0][i-5] = steward;
   }
   //Fill discard pile with arbitrary 10 cards
   state->discardCount[0] = 10;
   for(i = 0;  i < state->discardCount[0]; i++){
      state->discard[0][i] = i;
   }

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   for(i = 1; i < 4; i++){
	   stewardCard(state, 0, 0, i, 0, 0);
	   int errorCode = i * -10;
	   int cardCount = 0;
	   cardCount += state->deckCount[0] + state->handCount[0] + state->discardCount[0];
	   if(cardCount != cpy->deckCount[0] + cpy->handCount[0] + cpy->discardCount[0]){
		   return errorCode-1;
	   }
	   memcpy(state, cpy, sizeof(struct gameState));
   }

   //Card should exit normally as expected
   free(cpy);
   return 0;
}

int unitTest(){

   printf("\n+--------------------------------Steward CARD TEST----------------------------+\n");
   //Create Zeroed Gamestate;
   struct gameState* testState = (struct gameState*)(malloc(sizeof(struct gameState)));
   memset(testState, 0, sizeof(struct gameState));
   int retVal = 0;

   printf("\n+------basicTest------+\n\n");
   ///Checks if theres a net 2 card gain in hand
   retVal = basicTest(testState);
   if(retVal != 0){
      printf("basicTest %i: Test Failed, \n",retVal);
      //return -1
   } else {
      printf("basicTest: Successful\n");
   }
   memset(testState, 0, sizeof(struct gameState));

   printf("\n+--------stateTest----------+\n\n");
   //Checks to ensure expected values in current state are changed after function
   retVal = stateTest(testState);// Expected: numActions, hand, handCount, deck, deckCount, discard, discardCount, played, playedCount
   if(retVal){
	   printf("stateTest %i: Failed State Test\n", retVal);
	   //return -2;
   } else {
		   printf("stateTest: Successful\n");
   }

   printf("\n+--------discardTest----------+\n\n");
   //Checks to ensure Village Card is Discarded
   retVal = discardTest(testState);
   if(retVal){
	   printf("discardTest %i: Failed Discard Test\n", retVal);
	   //return -3;
   } else {
		   printf("discardTest: Successful\n");
   }

   printf("\n+--------totalCardCountTest----------+\n\n");
   //Checks to ensure the total cards in all the piles hasn't changed
   retVal = totalCardCountTest(testState);
   if(retVal){
	   printf("totalCardCountTest %i: Failed Total Card Count Test\n", retVal);
	   //return -3;
   } else {
		   printf("totalCardCountTest: Successful\n");
   }


   free(testState);
   return retVal;
}

int main(){
   int testVal = unitTest();
   printf("Outcome: %i\n", testVal);
   return 0;
}

