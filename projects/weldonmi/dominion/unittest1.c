/*
 * Miranda Weldon
 * April 22, 2016
 * CS 362 Spring 2016
 * Assignment 3
 * unittest1.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//function to print results of isGameOver test
void isGameOverTest(int option, int tagGameOver){
	//case where game should not be over
	if(option == 0){
		if(tagGameOver == 0)
			printf("\tNo - Test Pass\n");
		else if(tagGameOver == 1)
			printf("\tYes - Test Fail\n");
		else
			printf("\tERROR - Test Fail\n");
	}
	//case where game should be over
	else if(option == 1){
		if(tagGameOver == 1)
			printf("\tYes - Test Pass\n");
		else if(tagGameOver == 0)
			printf("\tNo - Test Fail\n");
		else
			printf("\tERROR - Test Fail\n");
	}
	else
		printf("\tERROR in isGameOverTest\n");
}

//main function
int main(){
	//declare variables
	int tagGameOver = -1, numPlayers = 3, seed = 1000;
	struct gameState Game, testGame;
	int k[10] = {feast, gardens, salvager, remodel, sea_hag, mine, cutpurse, ambassador, great_hall, smithy};

	//start up original game and create a copy
	initializeGame(numPlayers, k, seed, &Game);
	memcpy(&testGame, &Game, sizeof(struct gameState));

	printf("Testing isGameOver()\n\n");

	//test if game over at beginning of game
	tagGameOver = isGameOver(&testGame);
	printf("Beginning of Game: Expected No\n");

	//game shouldn't be over
	isGameOverTest(0, tagGameOver);

	memcpy(&testGame, &Game, sizeof(struct gameState));

	//test if game is over when province pile is empty
	testGame.supplyCount[province] = 0;
	tagGameOver = isGameOver(&testGame);
	printf("Province Pile Empty: Expected Yes\n");

	//game should be over
	isGameOverTest(1, tagGameOver);

	memcpy(&testGame, &Game, sizeof(struct gameState));

	//test if game is over when 2 other estate piles are empty
	testGame.supplyCount[duchy] = 0;
	testGame.supplyCount[estate] = 0;
	tagGameOver = isGameOver(&testGame);
	printf("Two Estate Piles Empty: Expected No\n");

	//game shouldn't be over
	isGameOverTest(0, tagGameOver);

	memcpy(&testGame, &Game, sizeof(struct gameState));

	//test if game is over when 3 kingdom card piles are empty
	testGame.supplyCount[feast] = 0;
	testGame.supplyCount[salvager] = 0;
	testGame.supplyCount[smithy] = 0;
	tagGameOver = isGameOver(&testGame);
	printf("Three Kingdom Card Piles Empty: Expected Yes\n");

	//game should be over
	isGameOverTest(1, tagGameOver);

	memcpy(&testGame, &Game, sizeof(struct gameState));

	//test if game is over when 2 kingdom card piles are empty
	testGame.supplyCount[feast] = 0;
	testGame.supplyCount[salvager] = 0;
	tagGameOver = isGameOver(&testGame);
	printf("Two Kingdom Card Piles Empty: Expected No\n");

	//game shouldn't be over
	isGameOverTest(0, tagGameOver);

	memcpy(&testGame, &Game, sizeof(struct gameState));

	//test if game is over when 4 kingdom card piles are empty
	testGame.supplyCount[feast] = 0;
	testGame.supplyCount[salvager] = 0;
	testGame.supplyCount[smithy] = 0;
	testGame.supplyCount[remodel] = 0;
	tagGameOver = isGameOver(&testGame);
	printf("Four Kingdom Card Piles Empty: Expected Yes\n");

	//game should be over
	isGameOverTest(1, tagGameOver);

	memcpy(&testGame, &Game, sizeof(struct gameState));

	//test when 3 empty pile are from different supply types
	testGame.supplyCount[sea_hag] = 0;
	testGame.supplyCount[curse] = 0;
	testGame.supplyCount[province] = 0;
	tagGameOver = isGameOver(&testGame);
	printf("Sea Hag, Curse, Province Empty: Expected Yes\n");

	//game should be over
	isGameOverTest(1, tagGameOver);

	//zero if no errors
	return 0;
}

