/*
 * Miranda Weldon
 * April 24, 2016
 * CS 362 Spring 2016
 * Assignment 3
 * unittest3.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//function to print results of updateCoins test
void updateCoinsTest(int expected, int actual){
	if(expected == actual)
		printf("\tTest Pass\n");
	else
		printf("\tTest Fail\n");
}

//main function
int main(){
	//declare variables
	int bonus = 0, numPlayers = 3, handSize = 5, seed = 1000;
	struct gameState Game, testGame;
	int k[10] = {feast, gardens, salvager, remodel, sea_hag, mine, cutpurse, ambassador, great_hall, smithy};
	int testHand[5] = {smithy, copper, copper, copper, copper};

	//start up original game and make a copy
	initializeGame(numPlayers, k, seed, &Game);
	memcpy(Game.hand[0], testHand, sizeof(int) * handSize);
	memcpy(&testGame, &Game, sizeof(struct gameState));

	printf("Testing updateCoins()\n\n");

	//test at beginning of game, should be no changes
	updateCoins(0, &testGame, bonus);
	printf("Beginning of Game:\n\tExpected: %d\n\tActual: %d\n", Game.coins, testGame.coins);
	updateCoinsTest(Game.coins, testGame.coins);

	memcpy(&testGame, &Game, sizeof(struct gameState));

	//test after 1 copper card added, should be +1
	//[0][0] is first player, first card in hadn; can be changed
	testGame.hand[0][0] = copper;
	updateCoins(0, &testGame, bonus);
	printf("Add 1 Copper to Hand:\n\tExpected: %d\n\tActual: %d\n", Game.coins + 1, testGame.coins);
	updateCoinsTest(Game.coins + 1, testGame.coins);

	memcpy(&testGame, &Game, sizeof(struct gameState));

	//test after 1 silver card added, should be +2
	testGame.hand[0][0] = silver;
	updateCoins(0, &testGame, bonus);
	printf("Add 1 Silver to Hand:\n\tExpected: %d\n\tActual: %d\n", Game.coins + 2, testGame.coins);
	updateCoinsTest(Game.coins + 2, testGame.coins);

	memcpy(&testGame, &Game, sizeof(struct gameState));

	//test after 1 gold card added, should be +3
	testGame.hand[0][0] = gold;
	updateCoins(0, &testGame, bonus);
	printf("Add 1 Gold to Hand:\n\tExpected: %d\n\tActual: %d\n", Game.coins + 3, testGame.coins);
	updateCoinsTest(Game.coins + 3, testGame.coins);

	memcpy(&testGame, &Game, sizeof(struct gameState));

	//test after 4 bonus added, should be +4
	bonus = 4;
	updateCoins(0, &testGame, bonus);
	printf("Add 4 Bonus:\n\tExpected: %d\n\tActual: %d\n", Game.coins + 4, testGame.coins);
	updateCoinsTest(Game.coins + 4, testGame.coins);

	memcpy(&testGame, &Game, sizeof(struct gameState));
	bonus = 0;

	//test after 1 kingdom card added to 2nd position, should be -1
	testGame.hand[0][1] = feast;
	updateCoins(0, &testGame, bonus);
	printf("Add 1 Kingdom Card to Hand:\n\tExpected: %d\n\tActual: %d\n", Game.coins - 1, testGame.coins);
	updateCoinsTest(Game.coins - 1, testGame.coins);

	memcpy(&testGame, &Game, sizeof(struct gameState));

	//zero if no errors
	return 0;
}

