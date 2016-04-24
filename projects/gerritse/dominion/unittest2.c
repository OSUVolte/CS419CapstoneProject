//Ellard Gerritsen van der Hoop
//CS362 Unit Test 2
//
//Testing updateCoins function from dominion_helper
//
//


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



#define NOISY_TEST 1


int main()
{
	int numPlayers = 2;
	struct gameState state, testState;
	int seed = 1000;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, feast};

	int goldCards = 0;
	int silverCards = 0;
	int copperCards = 0;
	int totalAmount = 0;
	int bonus = 4;
	int currentPlayer = 0;
	int i = 0;
	initializeGame(numPlayers, k , seed, &state);
	memcpy(&testState, &state, sizeof (struct gameState));
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("Unit Test 2- updateCoins Function\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n");


	printf("Testing updateCoins function to see if amount is updated properly\n");
	updateCoins(currentPlayer, &state, bonus);
	printf("updateCoins function called\n");
	printf("Loop checking math of updateCoins\n");

	//-----------------------------------Test 1------------------------------------/

	//Essentially we do our own loop and compare it to the functions amount
	for (i = 0; i < state.handCount[currentPlayer]; i++)
	{
		if (state.hand[currentPlayer][i] == gold)
		{
			
			goldCards += 1;
		}
	
		if (state.hand[currentPlayer][i] == silver)
		{
		
			silverCards += 1;
		}

		if (state.hand[currentPlayer][i] == copper)
		{
			copperCards += 1;
		}
		

	}
	printf("Total Amount is being calculated\n");
	totalAmount = (copperCards * 1) + (silverCards * 2) + (goldCards * 3) + bonus;
	
	if (NOISY_TEST == 1){
		printf("Amount of coins: %d     Expected: %d\n", state.coins, totalAmount);
	}

	if (totalAmount != state.coins)
	{
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("updateCoins Test 1  - FAIL\n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		
	}
	else{
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("updateCoins Test 1  - PASS\n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}

	///-------------------------------Test 2-------------------------------------------------/
	//In this test we put cards that we specify in the hand of P1

	printf("\n\n      Test 2: Lets add our own treasure cards in \n");
	testState.hand[currentPlayer][0] = copper; 
	testState.hand[currentPlayer][1] = silver;
	testState.hand[currentPlayer][2] = gold;
	testState.hand[currentPlayer][3] = silver; 
	testState.hand[currentPlayer][4] = gold;

	printf("Testing updateCoins function to see if amount is updated properly\n");
	updateCoins(currentPlayer, &testState, bonus);
	printf("updateCoins function called\n");
	printf("Loop checking math of updateCoins\n");
	
	goldCards =0;
	silverCards=0;
	copperCards = 0;

	//Essentially we do our own loop and compare it to the functions amount
	for (i = 0; i < testState.handCount[currentPlayer]; i++)
	{
		if (testState.hand[currentPlayer][i] == gold)
		{
			
			goldCards += 1;
		}
	
		if (testState.hand[currentPlayer][i] == silver)
		{
		
			silverCards += 1;
		}

		if (testState.hand[currentPlayer][i] == copper)
		{
			copperCards += 1;
		}
		

	}
	printf("Total Amount is being calculated\n");
	totalAmount = (copperCards * 1) + (silverCards * 2) + (goldCards * 3) + bonus;
	
	if (NOISY_TEST == 1){
		printf("Amount of coins: %d     Expected: %d\n", testState.coins, totalAmount);
	}

	if (totalAmount != testState.coins)
	{
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("updateCoins Test 2  - FAIL\n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		
	}
	else{
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("updateCoins Test 2  - PASS\n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}






	return 0;
}
