#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "unitTestLib.h"

/* Function to Be Tested
 *
 * Description: This function counts the instances of the card int passed to it 
 *    in the hand, deck, and discard piles of the player int passed to it.
 *
 *    The way it searches is by:
 *
 *	 FOR LOOP - From 0 to deckCount
 *	 - If deck[player][i] == card, count++	//state accessed, card accessed, no variables affected
 *	 FOR LOOP - From 0 to handCount
 *	 - If hand[player][i] == card, count++	//state accessed, card accessed, no variables affected
 *	 FOR LOOP - From 0 to discardCount
 *	 - If discard[player][i] == card,count++//state accessed, card accessed, no variables affected
 *	 RETURN count
 *
 * Eval: 
 *
 * This function should only read data, and not write it.
 * Game state should remain unchanged.
 * Original player variable should remain unchanged
 * Original card variable shoudl remain unchanged.
 * The total number of card in deck, hand, and discard should be returned
 */
/*
int fullDeckCount(int player, int card, struct gameState *state) {
  int i;
  int count = 0;

  for (i = 0; i < state->deckCount[player]; i++)
    {
      if (state->deck[player][i] == card) count++;
    }

  for (i = 0; i < state->handCount[player]; i++)
    {
      if (state->hand[player][i] == card) count++;
    }

  for (i = 0; i < state->discardCount[player]; i++)
    {
      if (state->discard[player][i] == card) count++;
    }

  return count;
}
*/

int basicReturnTest(struct gameState* state){

   int i, j, retVal;

   for(i = 0; i < state->numPlayers; i++){

      int* myDeckCount = getDeckCount(i, state);

      //Count for each Card
      for(j = 0; j < treasure_map+1; j++){
		 retVal = fullDeckCount(i, j, state);
		 //Only non-zero return value
		 if(retVal != myDeckCount[j]){
			printf("basicReturnTest -1: Card Count Differs by %i\n", retVal - myDeckCount[j]);
			return -1;
		 }
      }

      free(myDeckCount);
   }
   return 0;
}

int allCardsTargetReturnTest(struct gameState* state){

   int i, j, k, retVal;

   for(i = 0; i < state->numPlayers; i++){
      //Count for each Card
      for(j = 0; j < treasure_map+1; j++){
		 for(k = 0; k < state->deckCount[i]; k++){
			state->deck[i][k] = j;
		 }
		 for(k = 0; k < state->handCount[i]; k++){
			state->hand[i][k] = j;
		 }
		 for(k = 0; k < state->discardCount[i]; k++){
			state->discard[i][k] = j;
		 }

		 int* myDeckCount = getDeckCount(i, state);
		 retVal = fullDeckCount(i, j, state);
		 //Only non-zero return value
		 if(retVal != myDeckCount[j]){
			printf("allCardsTargetReturnTest -1: Card Count Differs by %i\n", retVal - myDeckCount[j]);
			return -1;
		 }
		 free(myDeckCount);
      }

   }
   return 0;
}

int allCardsNotTargetReturnTest(struct gameState* state){

   int i, j, k, retVal;

   for(i = 0; i < state->numPlayers; i++){
      for(k = 0; k < state->deckCount[i]; k++){
	 state->deck[i][k] = treasure_map+1;
      }
      for(k = 0; k < state->handCount[i]; k++){
	 state->hand[i][k] = treasure_map+1;
      }
      for(k = 0; k < state->discardCount[i]; k++){
	 state->discard[i][k] = treasure_map+1;
      }
      int* myDeckCount = getDeckCount(i, state);
      //Count for each Card
      for(j = 0; j < treasure_map+1; j++){
		 retVal = fullDeckCount(i, j, state);
		 //Only non-zero return value
		 if(retVal != myDeckCount[j]){
			printf("allCardsNotTargetReturnTest -1: Card Count Differs by %i\n", retVal - myDeckCount[j]);
			return -1;
		 }
      }
      free(myDeckCount);
   }
   return 0;
}

int stateTest(struct gameState* state){

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   int i, j, retVal;

   for(i = 0; i < state->numPlayers; i++){

      //Count for each Card
      for(j = 0; j < treasure_map+1; j++){
	 fullDeckCount(i, j, state);
	 retVal = checkState(cpy, state);

	 if(retVal){ 
	    printf("stateTest %i: State error\n", retVal);
	    return -1;
	 }
      }
   }
   free(cpy);
   return 0;
}

int unitTest(){

   printf("\n+--------------------------------UNIT TEST 2----------------------------+\n");
   //Create Zeroed Gamestate;
   struct gameState* testState = (struct gameState*)(malloc(sizeof(struct gameState)));
   memset(testState, 0, sizeof(struct gameState));
   int i, retVal = 0;

   printf("+------zeroStateTest--------+\n\n");
   //Zero Test
   retVal = basicReturnTest(testState);
   if(retVal != 0){
      printf("unitTest %i: Failed Zero State Test\n", retVal);
      //return -1;
   } else {
      printf("zeroStateTest: Successful\n");
   }

   printf("\n+--------basicReturnTest----------+\n\n");
   //Checks to ensure cards count accross a variety of states for a variety of players
   for(i = 2; i <= 4; i++){
      setupRandomTestState(i, testState);
      retVal = basicReturnTest(testState);
      if(retVal){   
	 printf("unitTest %i: Failed Basic Return Test\n", retVal);
	 //return -2;
      } else {
	 printf("basicReturnTest (%i players): Successful\n", i);
      }
   }

   printf("\n+-------allCardsTargetReturnTest--------+\n\n");
   //Checks to ensure cards count accross a variety of states for a variety of players
   for(i = 2; i <= 4; i++){
      setupRandomTestState(i, testState);
      retVal = allCardsTargetReturnTest(testState);
      if(retVal){   
	 printf("unitTest %i: Failed All Cards Target Return Test\n", retVal);
	 //return -3;
      } else {
	 printf("allCardsTargetReturnTest (%i players): Successful\n", i);
      }
   }

   printf("\n+-------allCardsNotTargetReturnTest--------+\n\n");
   //Checks to ensure cards count accross a variety of states for a variety of players
   for(i = 2; i <= 4; i++){
      setupRandomTestState(i, testState);
      retVal = allCardsNotTargetReturnTest(testState);
      if(retVal){   
	 printf("unitTest %i: Failed All Cards Not Target Return Test\n", retVal);
	 //return -4;
      } else {
	 printf("allCards Not TargetReturnTest (%i players): Successful\n", i);
      }
   }

   printf("\n+--------stateTest----------+\n\n");
   //Checks to ensure no values in current state are changed after function
   for(i = 2; i <= 4; i++){
      setupRandomTestState(i, testState);
      retVal = stateTest(testState);
      if(retVal){   
	 printf("unitTest %i: Failed State Test\n", retVal);
	 //return -5;
      } else {
	 printf("stateTest (%i players): Successful\n", i);
      }
   }

   return 0;
}

int main(){
   int retVal = unitTest();
   printf("Outcome: %i\n", retVal);
   return 0;
}
