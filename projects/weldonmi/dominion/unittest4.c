/*
 * Miranda Weldon
 * April 24, 2016
 * CS 362 Spring 2016
 * Assignment 3
 * unittest4.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//main function
int main (){
	//declare variables
	int i, numPlayers = 3, seed = 1000;
	struct gameState Game, testGame;
	int k[10] = {feast, gardens, salvager, remodel, sea_hag, mine, cutpurse, ambassador, great_hall, smithy};

	//start up original game and create a copy
	initializeGame(numPlayers, k, seed, &Game);
	memcpy(&testGame, &Game, sizeof(struct gameState));

	printf("Testing numHandCards()\n\n");

	//check card count for each player
	printf("Beginning of Game:\n");
	for(i = 0; i < numPlayers; i++){
		//printf("\tPlayer %d:\n\tExpected Card Count: 5\n\tActual Card Count: %d\n", i, numHandCards(&testGame));
		printf("\tPlayer %d:\n\tExpected Card Count: %d\n\tActual Card Count: %d\n", i, testGame.handCount[i], numHandCards(&testGame));
		if(numHandCards(&testGame) == 5)
			printf("\t\tTest Pass\n");
		else
			printf("\t\tTest Fail\n");
		testGame.whoseTurn++;
	}

	memcpy(&testGame, &Game, sizeof(struct gameState));

	//get rid of 1 card from two players hands (2 total) then retest
	printf("After Getting Rid of 1 Card from 2/3 Players' Hands:\n");
	testGame.hand[0][0] = -1;	//gets rid of first card for first player
	testGame.hand[1][0] = -1;	//gets rid of first card for second player
	for(i = 0; i < numPlayers; i++){
		//printf("\tPlayer %d:\n\tExpected Card Count: 5\n\tActual Card Count: %d\n", i, numHandCards(&testGame));
		printf("\tPlayer %d:\n\tExpected Card Count: %d\n\tActual Card Count: %d\n", i, testGame.handCount[i], numHandCards(&testGame));
		if(numHandCards(&testGame) == 5)
			printf("\t\tTest Pass\n");
		else
			printf("\t\tTest Fail\n");
		testGame.whoseTurn++;
	}

	//zero if no errors
	return 0;
}
