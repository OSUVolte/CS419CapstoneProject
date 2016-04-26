#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "time.h"

#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestLib.h"

/* Helper Function to Test Function
 *
 * Description: This is a simple compare function for qsort
 *
 * Eval: Should not impact outcome of test. Evaluates state->deck as ints
 *     and state->deck is already ints. Organizes the ints in the deck. 
 *     state will be evaluated in unit test, so function doesn't require
 *     direct unit testing.
 */
int compare(const void*, const void* );// Need for predeclaration
/*
  if (*(int*)a > *(int*)b)
    return 1;
  if (*(int*)a < *(int*)b)
    return -1;
  return 0;
}
*/

/* Function to Be Tested
 *
 * Description: This function accepts a player number and the gamestate and "shuffles" that players deck.
 *     The way it shuffles the deck is by:
 *     - organizing the current players deck //state affected - vars:deck[player], deckCount[player]
 *     WHILE LOOP - Runs for size of state->deckCount[]
 *     - A random index is selected and stored in card   //player/state unaffected
 *     - The selected card gets copied in a new deck     //player/state unaffected
 *     - The selected card gets removed from old deck    //state affected - vars:deck[]
 *     - The size of old deck gets decremented		 //state affected - vars:deckCount[]
 *     FOR LOOP - Runs for size of new deck
 *     - new deck at index i, is copied into old deck i	 //state affected - vars:deck[]
 *     - Old deck is incremented			 //state affected - vars:deckCount[] 
 *
 * Eval: 
 *
 * Game state variables that will be affected are deck[player][i], and deckCount[player]. 
 * The deckCount should be the same after the function runs, even though it is changed in the function
 * The deck[player] should contain the same cards after the function as it does before the function
 * Ensure that other variables in state are the same. 
 * Ensure that original player variable remains unchanged.
 * It appears that the function may, rarely, access outside its deck range when
 *    randomly picking the cards from the deck to put into newDeck.
 *    If Random() = 1, card = deckCount and the highest card position
 *    is deckCount - 1.
 */
/*
int shuffle(int player, struct gameState *state) {
 

  int newDeck[MAX_DECK];
  int newDeckPos = 0;
  int card;
  int i;

  if (state->deckCount[player] < 1)
    return -1;
  qsort ((void*)(state->deck[player]), state->deckCount[player], sizeof(int), compare); 
   SORT CARDS IN DECK TO ENSURE DETERMINISM! 

  while (state->deckCount[player] > 0) {
    card = floor(Random() * state->deckCount[player]);
    newDeck[newDeckPos] = state->deck[player][card];
    newDeckPos++;
    for (i = card; i < state->deckCount[player]-1; i++) {
      state->deck[player][i] = state->deck[player][i+1];
    }
    state->deckCount[player]--;
  }
  for (i = 0; i < newDeckPos; i++) {
    state->deck[player][i] = newDeck[i];
    state->deckCount[player]++;
  }

  return 0;
}
*/

int basicReturnTest(struct gameState* state){

   int i, retVal=0;

   for(i = 0; i < state->numPlayers; i++){
      //Run shuffle on each player in state
      retVal = shuffle(i, state);
      //Only non-zero return value
      if(state->deckCount[i] == 0 && retVal != -1){
		 printf("basicReturnTest: Player %i wrong shuffle return value\n", i+1);
		 return -1;
      }
   }
   return retVal;
}

int stateTest(struct gameState* state){

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   int i, retVal;

   for(i = 0; i < state->numPlayers; i++){
      retVal = shuffle(i, state);
      if(retVal == -1){
		 printf("stateTest -1: Player %i cards not shuffled\n", i+1);
		 free(cpy);
		 return -1;
      } else {
    	  retVal = checkState(cpy, state);
		 //Checks if deck is shuffled
		 if(retVal != -18){
			printf("stateTest %i: State error\n", retVal);
			free(cpy);
			return -2;
		 }
      }
   }
   return 0;
}

int cardTypeCountTest(struct gameState* state){
   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   int i, retVal;

   for(i = 0; i < state->numPlayers; i++){
      retVal = shuffle(i, state);
      if(retVal == -1){
		 printf("cardTypeCountTest -1: Player %i has no deck\n", i+1);
		 free(cpy);
		 return -1;
      } else {
		 retVal = checkDeckCount(cpy, state);
		 if(retVal){
			printf("cardTypeCountTest %i: Total card count doesn't match\n", retVal);
			free(cpy);
			return -2;
		 }
		 retVal = checkDeck(cpy, state);
		 if(retVal){
			printf("cardTypeCountTest %i: Decks don't have the same amount of each type of card\n", retVal);
			free(cpy);
			return -3;
		 }
      }
   }
   return 0;
}

int discardCardCountTest(struct gameState* state){
   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   int i, retVal;

   for(i = 0; i < state->numPlayers; i++){
      retVal = shuffle(i, state);
      if(retVal == -1){
		 printf("discardCardCountTest -1: Player %i has no deck\n", i+1);
		 free(cpy);
		 return -1;
      } else {
		 retVal = checkDiscardCount(cpy, state);
		 if(retVal){
			printf("discardCardCountTest %i: Total discard count doesn't match\n", retVal);
			free(cpy);
			return -2;
		 }
		 retVal = checkDiscard(cpy, state);
		 if(retVal){
			printf("discardCardCountTest %i: Discards don't have the same amount of each type of card\n", retVal);
			free(cpy);
			return -3;
		 }
      }
   }
   return 0;
}

int unitTest(){

   printf("\n+--------------------------------UNIT TEST 1----------------------------+\n");
   //Create Zeroed Gamestate;
   struct gameState* testState = (struct gameState*)(malloc(sizeof(struct gameState)));
   memset(testState, 0, sizeof(struct gameState));
   int i, retVal = 0;

   printf("+------zeroStateTest--------+\n\n");
   //Zero Test
   retVal = shuffle(0,testState);
   if(retVal != -1){
      printf("unitTest %i: Failed Zero State Test\n", retVal);
      //return -1;
   } else {
      printf("zeroStateTest: Successful\n");
   }

   printf("\n+------basicReturnTest------+\n\n");
   //Basic Return Value Test for game with players 2, 3, and 4
   for(i = 2; i <= 4; i++){
      setupRandomTestState(i, testState);
      retVal = basicReturnTest(testState);
      if(retVal){
	 printf("unitTest %i: Failed Basic Return Value test for Player %i\n", retVal, i);
	 //return -2;
      } else {
	 printf("basicReturnTest (%i players): Successful\n", i);
      }
   }

   printf("\n+--------StateTest----------+\n\n");
   //Checks to ensure only state change is deck is now shuffled
   for(i = 2; i <= 4; i++){
      setupRandomTestState(i, testState);
      retVal = stateTest(testState);
      if(retVal){
	 printf("unitTest %i: Failed State Test\n", retVal);
	 //return -3;
      } else {
	 printf("stateTest (%i players): Successful\n", i);
      }
   }

   printf("\n+-----cardTypeCountTest----+\n\n");
   //Checks to ensure the total count, and count of each type of card is the same
   for(i = 2; i <= 4; i++){
      setupRandomTestState(i, testState);
      retVal = cardTypeCountTest(testState);
      if(retVal){
	 printf("unitTest %i: Failed Card Type Count\n", retVal);
	 //return -4;
      } else {
	 printf("cardTypeCountTest (%i players): Successful\n", i);
      }
   }

   printf("\n+---discardCardCountTest---+\n\n");
   //Checks to see if discard is affected, comment from dominion.h states assumed empty
   for(i = 2; i <= 4; i++){
      setupRandomTestState(i, testState);
      retVal = discardCardCountTest(testState);
      if(retVal){
	 printf("unitTest %i: Failed Discard Card Type Count\n", retVal);
	 //return -5;
      } else {
	 printf("discardCardCountTest (%i players): Successful\n", i);
      }
   }


   free(testState);
   return retVal;
}

int main(){
   int testVal = unitTest();
   printf("Outcome: %i\n", testVal);
   return 0;
}



