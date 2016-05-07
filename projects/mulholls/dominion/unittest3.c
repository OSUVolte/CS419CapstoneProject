#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestLib.h"

/* Function to Be Tested
*
* Description This function checks the game state to see if the game should
*    be over. If the province count is 0, the game ends. If three supply
*    piles are at 0, the game ends.
*
*    The way it checks is by
*	 - IF supplyCount of provinces is 0, RETURN 1 //state accessed
*	 FOR LOOP - for each of the supply piles 0-25
*	 - If supplyCount of supply is 0, count++     //state accessed
*	 - If count >= 3 (3 supply piles counted), RETURN 1
*	 RETURN 0 if function hasn't returned 1
*
* Eval
*
* Game state is only read, and should remain unchanged.
* Only a 1 or a 0 is returned.
* If there are 0 cards in the province pile, a 1 was returned
* If there are 3 or more piles with 0 supply, a 1 is returned
* If the 2 end game conditions aren't met, a 0 is returned
* It appears that the check for 3 empty supplies only checks the first 24
*    supplies and not up to the 27 supplies.
*/
/*
int isGameOver(struct gameState *state) {
 int i;
 int j;

 //if stack of Province cards is empty, the game ends
 if (state->supplyCount[province] == 0)
   {
	 return 1;
   }

 //if three supply pile are at 0, the game ends
 j = 0;
 for (i = 0; i < 25; i++)
   {
	 if (state->supplyCount[i] == 0)
{
  j++;
}
   }
 if ( j >= 3)
   {
	 return 1;
   }

 return 0;
}
*/


int basicReturnTest(struct gameState* state){

  int retVal = isGameOver(state);
  int gameOver = checkGameOver(state);

  //Only non-zero return value
  if(retVal != gameOver){
	 printf("basicReturnTest - Game Over Conditions Don't Match\n");
	 return -1;
  }
  return 0;
}


int allNonProvinceEmptyReturnTest(struct gameState* state){

	int i;
	for(i = 0; i < treasure_map+1; i++){
		state->supplyCount[i] = 0;
	}
	state->supplyCount[province] = 1;
	int retVal = isGameOver(state);
	if(retVal != checkGameOver(state)){
		printf("allNonProvinceEmptyReturnTest - Game Over Evaluation Differs\n");
		return -1;
	}

	return 0;
}


int noEmptySuppliesReturnTest(struct gameState* state){

	int i;
	for(i = 0; i < treasure_map+1; i++){
		state->supplyCount[i] = 1;
	}

	int retVal = isGameOver(state);

	if(retVal != checkGameOver(state)){
		printf("noEmptySuppliesReturnTest - Game Over Evaluation Differs\n");
		return -1;
	}

	return 0;
}



int stateTest(struct gameState* state){

	struct gameState* cpy = (struct gameState*)(malloc(sizeof(struct gameState)));
	memcpy(cpy, state, sizeof(struct gameState));

	isGameOver(state);

	int retVal = checkState(cpy, state);

	if(retVal){
		printf("stateTest %i State error\n", retVal);
		return -1;
	}

	free(cpy);
	return 0;
}


int unitTest(){

	printf("\n+--------------------------------UNIT TEST 3----------------------------+\n");

	//Create Zeroed Gamestate;
	struct gameState* testState = (struct gameState*)(malloc(sizeof(struct gameState)));
	memset(testState, 0, sizeof(struct gameState));
	int i, retVal = 0;

	printf("+------zeroStateTest--------+\n\n");

	//Zero Test
	retVal = basicReturnTest(testState);

	if(retVal != 0){
		printf("unitTest %i Failed Zero State Test\n", retVal);
		//return -1;
	} else {
		printf("zeroStateTest Successful\n");
	}

	printf("\n+--------basicReturnTest----------+\n\n");
	//Checks to ensure cards count accross a variety of states for a variety of players
	for(i = 2; i <= 4; i++){
		setupRandomTestState(i, testState);
		retVal = basicReturnTest(testState);
		if(retVal){
			printf("unitTest %i Failed Basic Return Test\n", retVal);
			//return -2;
		} else {
			printf("basicReturnTest (%i players) Successful\n", i);
		}
	}

	printf("\n+--------allNonProvinceEmptyReturnTest----------+\n\n");
	//Checks to ensure cards count accross a variety of states for a variety of players
	for(i = 2; i <= 4; i++){

		setupRandomTestState(i, testState);
		retVal = allNonProvinceEmptyReturnTest(testState);
		if(retVal){
			printf("unitTest %i Failed All Non Province Empty Return Test\n", retVal);
			//return -3;
		} else {
			printf("allNonProvinceEmptyReturnTest (%i players) Successful\n", i);
		}
	}

	printf("\n+--------noEmptySuppliesReturnTest----------+\n\n");
	//Checks to ensure cards count accross a variety of states for a variety of players
	for(i = 2; i <= 4; i++){
			setupRandomTestState(i, testState);
			retVal = noEmptySuppliesReturnTest(testState);
		if(retVal){
			printf("unitTest %i Failed No Empty Supplies Return Test\n", retVal);
			//return -4;
		} else {
			printf("noSuppliesEmptyReturnTest (%i players) Successful\n", i);
		}
	}


	printf("\n+--------provinceEmptyReturnTest----------+\n\n");
	//Checks to ensure cards count accross a variety of states for a variety of players
	for(i = 2; i <= 4; i++){
		setupRandomTestState(i, testState);
		noEmptySuppliesReturnTest(testState); //Sets all supplies to 1
		testState->supplyCount[province] = 0;

		if(checkGameOver(testState) != isGameOver(testState)){
			printf("unitTest - Failed No Empty Supplies Return Test\n");
			//return -5;
		} else {
			printf("provinceEmptyReturnTest (%i players) Successful\n", i);
		}
	}

	printf("\n+--------SpecificStateTest----------+\n\n");
	//Checks to ensure cards count accross a variety of states for a variety of players
	for(i = 2; i <= 4; i++){
		setupRandomTestState(i, testState);
		noEmptySuppliesReturnTest(testState); //Sets all supplies to 1
		int j;
		for(j = 24; j < treasure_map+1; j++){ //Sets top 3 supplies to 0
			testState->supplyCount[j] = 0;
		}
		if(checkGameOver(testState) != isGameOver(testState)){
			printf("specificStateTest - Failed Specific State Test\n");
			//return -6;
		} else {
			printf("provinceEmptyReturnTest (%i players) Successful\n", i);
		}
	}

	printf("\n+--------stateTest----------+\n\n");
	//Checks to ensure no values in current state are changed after function
	for(i = 2; i <= 4; i++){
		setupRandomTestState(i, testState);
		retVal = stateTest(testState);
		if(retVal){
			printf("unitTest %i Failed State Test\n", retVal);
			//return -7;
		} else {
			printf("stateTest (%i players) Successful\n", i);
		}
	}

		return 0;
	}

int main(){
	int retVal = unitTest();
	printf("Outcome %i\n", retVal);
	return 0;
}

