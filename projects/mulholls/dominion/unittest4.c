#include "stdlib.h"
#include "string.h"
#include "stdio.h"

#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestLib.h"

/* Function to Be Tested
 *
 * Description: 
 *
 *    The way it checks is by:
 *	 IF trashFlag is not set
 *	 -set playedCards tracks the card played from hand  //state affected - vars: playedCard[max]
 *	 -playedCardCount is incremented		    //state affected - vars: playedCardCount
 *	 ENDIF  
 *	 -playedCard from hand is set to -1		    //state affected - vars: hand[player][handpos]
 *	 IF card played was last position in hand	 
 *	 -remove from hand				    //state affected - vars: handCount[player]
 *	 ELSEIF card played was only card
 *	 -remove from hand				    //state affected - vars: handCount[player]
 *	 ELSE
 *	 -copy over card with last card in hand		    //state affected - vars: hand[player][pos]
 *	 -remove last card				    //state affected - vars: hand[player][highCardPos]
 *	 -decrement handCount				    //state affected - vars: handCount[player]
 *
 * Eval: 
 * 
 * DOESN'T ACTUALLY DISCARD TO DISCARD OR INCREMENT DISCARD COUNT
 * Game state variables playedCards, playedCardCount, hand[currentPlayer][handPos], and handCount[currentPlayer] altered
 * playedCards[playedCardCount] should be:	1) Unchanged OR
 *						2) Equal to hand[currentPlayer][handPos] before function ran
 * playedCardCount should be:	 1) Unchanged OR
 *				 2) Incremented
 * state->handCount[currentPlayer] should be decremented only once
 * state->hand[currentPlayer][handPos] should be:     1) Equal to -1 OR
 *						      2) Equal to the highest card in hand at beginning of turn
 * ALWAYS returns 0
 * It appears that the "else if" statement is redundant as if its the only card in your hand, it will also be
 *    the last card in your hand.
 */
/*
int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
{
	
  //if card is not trashed, added to Played pile 
  if (trashFlag < 1)
    {
      //add card to played pile
      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
      state->playedCardCount++;
    }
	
  //set played card to -1
  state->hand[currentPlayer][handPos] = -1;
	
  //remove card from player's hand
  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
    {
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
    {
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
  else 	
    {
      //replace discarded card with last card in hand
      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
      //set last card to -1
      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
	
  return 0;
}
*/
int basicReturnTest(struct gameState* state){

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   int i, retVal;
   for(i = 0; i < state->numPlayers; i++){
      retVal = discardCard(0, i, state, 0);
      int errorTens = i * 10;
      int errorCode;
      if(retVal){
    	 errorCode = -100-errorTens-retVal;
		 printf("basicReturnTest %i: discardCard Returning Non-zero Value\n", errorCode);
		 return errorCode;
      }
      memcpy(state, cpy, sizeof(struct gameState));

      retVal = discardCard(state->handCount[i]-1, i, state, 0);
      if(retVal){
     	 errorCode = -200-errorTens-retVal;
 		 printf("basicReturnTest %i: discardCard Returning Non-zero Value\n", errorCode);
		 return errorCode;
      }
      memcpy(state, cpy, sizeof(struct gameState));

      retVal = discardCard(1, i, state, 0);
      if(retVal){
     	 errorCode = -300-errorTens-retVal;
 		 printf("basicReturnTest %i: discardCard Returning Non-zero Value\n", errorCode);
		 return errorCode;
      }
      memcpy(state, cpy, sizeof(struct gameState));

      retVal = discardCard(0, i, state, 1);
      if(retVal){
     	 errorCode = -400-errorTens-retVal;
 		 printf("basicReturnTest %i: discardCard Returning Non-zero Value\n", errorCode);
		 return errorCode;
      }
      memcpy(state, cpy, sizeof(struct gameState));

      retVal = discardCard(state->handCount[i]-1, i, state, 1);
      if(retVal){
     	 errorCode = -500-errorTens-retVal;
 		 printf("basicReturnTest %i: discardCard Returning Non-zero Value\n", errorCode);
		 return errorCode;
      }
      memcpy(state, cpy, sizeof(struct gameState));

      retVal = discardCard(1, i, state, 1);
      if(retVal){
     	 errorCode = -600-errorTens-retVal;
 		 printf("basicReturnTest %i: discardCard Returning Non-zero Value\n", errorCode);
		 return errorCode;
      }

   }
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

      default:
	 if(retVal){
	    return retVal;
	 } else {
	    return 0;
	 }
   }
}

//Counts the number of states set to 1 in tracker
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

//Manages the workings of the individual tests
int _stateTestDiscreteTest(int handPos, int player, struct gameState* state, struct gameState* cpy, int trash, int totalChanges){

   //Discard requested card
   discardCard(handPos, player, state, trash);

   //Create a state change tracker
   int* stateTracker = (int*)(malloc(19*sizeof(int)));
   memset(stateTracker, 0, 19*sizeof(int));

   //Flag all the states that were changed by running discardCard()
   int retVal;
   do{
      retVal = _stateTestHelper(state, cpy, player);
      if(retVal){
    	  stateTracker[retVal] = 1;
      }
   } while (retVal);

   //discard[] expected change
   if(!stateTracker[13]){
	   return 1;
   }
   //discard count
   if(!stateTracker[14]){
	   return 2;
   }

   //Is card actually discarded?
   if(state->discard[player][state->discardCount[player]]-1 != cpy->hand[player][handPos]){
	   return 3;
   }

   //Count all the total number of states affected
   int sc = _stateTrackerChecker(stateTracker);

   //If count of changed states from discardCard doesn't match expected...
   if(sc != totalChanges){
      return sc-totalChanges;
   } else {
      return 0;
   }
}

//Total state test 
int stateTest(struct gameState* state){

   struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
   memcpy(cpy, state, sizeof(struct gameState));

   int i, retVal;
   //For Each Player
   for(i = 0; i < state->numPlayers; i++){
	  int errorTens = i * 10;
	  int errorCode;
      //Perform test on card in position 0, and non-trash card
      retVal = _stateTestDiscreteTest(0,i,state,cpy,0,6);
      if(retVal){
    	 errorCode = -100-errorTens-retVal;
		 printf("stateTest %i: Incorrect State Changes\n", errorCode);
		 return errorCode;
      }
      memcpy(state, cpy, sizeof(struct gameState));

      //Perform test on card in last position of hand, and non-trash card
      retVal = _stateTestDiscreteTest(state->handCount[i]-1,i,state,cpy,0, 6);
      if(retVal){
     	 errorCode = -200-errorTens-retVal;
 		 printf("stateTest %i: Incorrect State Changes\n", errorCode);
 		 return errorCode;
      }
      memcpy(state, cpy, sizeof(struct gameState));

      //Perform test on card in position 0, trash card
      retVal = _stateTestDiscreteTest(0,i,state,cpy,1,4);
      if(retVal){
     	 errorCode = -300-errorTens-retVal;
 		 printf("stateTest %i: Incorrect State Changes\n", errorCode);
 		 return errorCode;
      }
      memcpy(state, cpy, sizeof(struct gameState));

      //Perform test on card in last position of hand, trash card
      retVal = _stateTestDiscreteTest(state->handCount[i]-1,i,state,cpy,1,4);
      if(retVal){
     	 errorCode = -400-errorTens-retVal;
 		 printf("stateTest %i: Incorrect State Changes\n", errorCode);
 		 return errorCode;
      }
      memcpy(state, cpy, sizeof(struct gameState));

      //1 card in hand
      memset(state->hand[i], -1, state->handCount[i] * sizeof(int));
      state->handCount[i] = 1;

      //Perform test on last card in hand, non-trash
      retVal = _stateTestDiscreteTest(0,i,state,cpy,0,6);
      if(retVal){
     	 errorCode = -500-errorTens-retVal;
 		 printf("stateTest %i: Incorrect State Changes\n", errorCode);
 		 return errorCode;
      }
      memcpy(state, cpy, sizeof(struct gameState));
      memset(state->hand[i], -1, state->handCount[i] * sizeof(int));
      state->handCount[i] = 1;

      //Perform test on last card in hand, trash card
      retVal = _stateTestDiscreteTest(0,i,state,cpy,1,4);
      if(retVal){
     	 errorCode = -600-errorTens-retVal;
 		 printf("stateTest %i: Incorrect State Changes\n", errorCode);
 		 return errorCode;
      }

   }
   free(cpy);
   return 0;
}


int unitTest(){

   printf("\n+--------------------------------UNIT TEST 4----------------------------+\n");
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
      int j;
      //Ensures at least 3 cards in hand
      for(j = 0; j < i; j++){
	 testState->handCount[j] += 3;
	 testState->hand[j][testState->handCount[j]-2] = rand() % (treasure_map+1);
	 testState->hand[j][testState->handCount[j]-3] = rand() % (treasure_map+1);
	 testState->hand[j][testState->handCount[j]-4] = rand() % (treasure_map+1);
      }
      retVal = basicReturnTest(testState);
      if(retVal){   
	 printf("unitTest %i: Failed Basic Return Test\n", retVal);
	 //return -2;
      } else {
	 printf("basicReturnTest (%i players): Successful\n", i);
      }
   }


   printf("\n+--------stateTest----------+\n\n");
   //Checks to ensure no values in current state are changed after function
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

   return 0;
}

int main(){
   int retVal = unitTest();
   printf("Outcome: %i\n", retVal);
   return 0;
}
