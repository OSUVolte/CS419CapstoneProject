// Ellard Gerritsen van der Hoop
// Unit Test 1- Dominion
//
// use gcc -o unittest1 unittest1.c dominion.c rngs.c 
//
// This test will look at the endTurn() function within dominion
//
//
//
//


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>


//Set NOISY_TEST to 1 to show printfs from output
#define NOISY_TEST 1


int main()
{
	int numPlayers = 2;
	struct gameState state;
	int seed = 1000;
	int previousPlayer = 0;
	int currentPlayer = 0;
	
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, feast};

	int totalBugs = 0;






	initializeGame(numPlayers, k, seed, &state);

	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("Unit Test 1- endTurn()\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n");

	printf("Game is initialized. First turn begins\n");		

	if (NOISY_TEST == 1){
	printf("Current Player: %d   Expected Player: %d \n", whoseTurn(&state), currentPlayer);
	}

	if (whoseTurn(&state) != currentPlayer){
		totalBugs++;
	}
	
	//Current player should be 0
	endTurn(&state);
	currentPlayer = 1;
	
	printf("Turn ended. Next turn begins\n");
	if (NOISY_TEST == 1){
	printf("Curent Player: %d   Expected Player: %d\n", whoseTurn(&state), currentPlayer);
	}

	//Current player should be 1, with previousPlayer now 0

	if (whoseTurn(&state) != currentPlayer){
		totalBugs++;
		
	}
	
	printf("Checking HandCount\n");
	//Checks to see if handCount is 0 for player who just went
	if (state.handCount[previousPlayer] != 0){
		totalBugs++; 
	}	

	if (NOISY_TEST == 1){
	
		printf("Cards in Hand: %d   Expected: 0\n", state.handCount[previousPlayer]);
	}


	endTurn(&state);
	previousPlayer = 1;
	currentPlayer = 0;
	
	printf("Turn ended. Next turn begins\n");
	if (NOISY_TEST == 1){
		printf("Current Player: %d   Expected Player: %d\n", whoseTurn(&state), currentPlayer);
	}

	if (whoseTurn(&state) != currentPlayer){
		totalBugs++;
	}

	if (state.handCount[previousPlayer] != 0){
		totalBugs++; 
	
	}

	printf("Checking HandCount\n");
	if (NOISY_TEST == 1){
		printf("Cards in Hand: %d  Expected: 0\n", state.handCount[previousPlayer]);
	}

	if (totalBugs == 0){
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("endTurn() Function - PASS\n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}
	else{
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("endTurn() Function - FAIL\n");
		printf("Total Bugs: %d", totalBugs);
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}









}
