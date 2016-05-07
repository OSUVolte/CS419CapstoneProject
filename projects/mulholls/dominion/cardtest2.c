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
 * Description: This card should discard the smithy card from the players hand
 * 		and add 3 additional cards to their hand.
 *
 *    The way it should work is:
 *			-A temporary hand is created to hold drawn cards
 *			-drawCard is run on player 3 times, and the new card is copied into
 *				temporary hand
 *			-And then the smithy card is discarded
 *
 * Eval:
 *
 *	The temporary hand doesn't seem necessary, and seems like it will break the base functionality
 *	3 cards are discarded
 *	The discardCard function call is wrong, its setting the cardDrawn variable in the trash flag
 *	The discardCard function call is discarding from the players HAND not the temp hand
 */
void smithyCard(struct gameState*, int, int);
/*void smithyCard(struct gameState* state, int currentPlayer, int handPos){
   int cardDrawn;
   int temphand[MAX_HAND];

   int i;
   //+3 Cards
   for (i = 0; i < 3; i++)
   {
      drawCard(currentPlayer, state);
      cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
      temphand[i] = cardDrawn;
   }
   
   for(i = 0; i < 3; i++){
      cardDrawn = temphand[i];		  
      //discard card from hand
      discardCard(handPos, currentPlayer, state, cardDrawn);
   }
   return;
}
*/
int basicTest(struct gameState* state){

   state->numPlayers = 2;
   state->deckCount[0] = 27;

   int i;

   for(i = 0;  i < state->deckCount[0]; i++){
      state->deck[0][i] = i;
   }
   state->handCount[0] = 5;
   for(i = 5;  i < 5 + state->handCount[0]; i++){
      state->hand[0][i-5] = smithy;
   }
   state->discardCount[0] = 10;
   for(i = 0;  i < state->discardCount[0]; i++){
      state->discard[0][i] = i;
   }

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   smithyCard(state, 0, 0);

   //Draw 3 cards, discard smithy
   if(state->handCount[0] != cpy->handCount[0]+2){
	   free(cpy);
	   return -1;
   }
   //Discard Count + smithy
   if(state->discardCount[0] != cpy->discardCount[0] +1){
	   free(cpy);
	   return -2;
   }

   if(state->discard[0][state->discardCount[0]-1] != smithy){
	   return -3;
   }
   //Net card change is plus 2
   free(cpy);
   return 0;
}

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

   int* stateTracker = (int*)(malloc(19*sizeof(int)));
   memset(stateTracker, 0, 19*sizeof(int));

   int i, retVal;
   state->numPlayers = 2;
   state->deckCount[0] = 27;

   //Deck doesn't matter
   for(i = 0;  i < state->deckCount[0]; i++){
      state->deck[0][i] = i;
   }
   //Put Smithy into hand
   state->handCount[0] = 5;
   for(i = 5;  i < 5 + state->handCount[0]; i++){
      state->hand[0][i-5] = smithy;
   }
   state->discardCount[0] = 10;
   for(i = 0;  i < state->discardCount[0]; i++){
      state->discard[0][i] = i;
   }

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   smithyCard(state, 0, 0);
   do{

      retVal = _stateTestHelper(state, cpy, 0);
      if(retVal){
    	  stateTracker[retVal]++;
    	  //Unpredictable state change
    	  if(stateTracker[retVal] > 1){
    		  printf("stateTest %i: Can't Clear State Error\n", retVal);
    		  return -retVal;
    	  }
      }
   } while (retVal);

   int sc = _stateTrackerChecker(stateTracker);
   //Hand Should change
   if(!stateTracker[11]){
	   return -1;
   }
   //Hand Count Should CHange
   if(!stateTracker[12]){
	   return -2;
   }
   //discard should change
   if(!stateTracker[13]){
	   return -3;
   }
   //discard count
   if(!stateTracker[14]){
	   return -4;
   }
   //playedCards
   if(!stateTracker[15]){
	   return -5;
   }
   //PlayedCardCount
   if(!stateTracker[16]){
	   return -6;
   }
   //deckCount
   if(!stateTracker[17]){
	   return -7;
   }
   //deck should change
   if(!stateTracker[18]){
	   return -8;
   }
   //If there isn't an expected number of state changes...
   if(sc != expectedStateChanges){
	   printf("stateTest -1: State error, %i Wrong Changes\n", sc-expectedStateChanges);
	   return -9;
   }


   free(stateTracker);
   free(cpy);
   return 0;
}

int discardTest(struct gameState* state){

   state->numPlayers = 2;
   state->deckCount[0] = 27;

   int i;

   for(i = 0;  i < state->deckCount[0]; i++){
      state->deck[0][i] = i;
   }
   state->handCount[0] = 5;
   for(i = 5;  i < 5 + state->handCount[0]; i++){
      state->hand[0][i-5] = smithy;
   }
   state->discardCount[0] = 10;
   for(i = 0;  i < state->discardCount[0]; i++){
      state->discard[0][i] = i;
   }

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   smithyCard(state, 0, 0);

   if(state->discardCount[0] != cpy->discardCount[0]+1){
	   free(cpy);
	   return -1;
   }

   if(state->discard[0][state->discardCount[0]-1] != smithy){
	   free(cpy);
	   return -2;
   }

   //Card should exit normally as expected
   free(cpy);
   return 0;
}

int totalCardCountTest(struct gameState* state){

   state->numPlayers = 2;
   state->deckCount[0] = 27;

   int i;

   for(i = 0;  i < state->deckCount[0]; i++){
      state->deck[0][i] = i;
   }
   state->handCount[0] = 5;
   for(i = 5;  i < 5 + state->handCount[0]; i++){
      state->hand[0][i-5] = smithy;
   }
   state->discardCount[0] = 10;
   for(i = 0;  i < state->discardCount[0]; i++){
      state->discard[0][i] = i;
   }

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   smithyCard(state, 0, 0);

   int cardCount = 0;
   cardCount += state->deckCount[0] + state->handCount[0] + state->discardCount[0];
   if(cardCount != cpy->deckCount[0] + cpy->handCount[0] + cpy->discardCount[0]){
	   return -1;
   }
   //Card should exit normally as expected
   free(cpy);
   return 0;
}

int unitTest(){

   printf("\n+--------------------------------SMITHY CARD TEST----------------------------+\n");
   //Create Zeroed Gamestate;
   struct gameState* testState = (struct gameState*)(malloc(sizeof(struct gameState)));
   memset(testState, 0, sizeof(struct gameState));
   int retVal = 0;

   printf("\n+------basicTest------+\n\n");
   ///Checks if theres a net 2 card gain in hand
   retVal = basicTest(testState);
   if(retVal != 0){
      printf("basicTest -1: Test Failed, \n");
      //return -1
   } else {
      printf("basicTest: Successful\n");
   }
   memset(testState, 0, sizeof(struct gameState));

   printf("\n+--------stateTest----------+\n\n");
   //Checks to ensure expected values in current state are changed after function
   retVal = stateTest(testState, 8);// Expected: hand, handCount, deck, deckCount, discard, discardCount, played, playedCount
   if(retVal){
	   printf("stateTest %i: Failed State Test\n", retVal);
	   //return -2;
   } else {
		   printf("stateTest: Successful\n");
   }

   printf("\n+--------discardTest----------+\n\n");
   //Checks to ensure Smithy Card is Discarded
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

