/*
 * Miranda Weldon
 * April 23, 2016
 * CS 362 Spring 2016
 * Assignment 3
 * cardtest3.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//main function
int main(){
	//declare variables
	int i, numPlayers = 3;
	struct gameState Game, testGame;
	int k[10] = {feast, gardens, salvager, remodel, tribute, mine, cutpurse, ambassador, great_hall, smithy};

	//start up original game and create a copy
	initializeGame(numPlayers, k, 1000, &Game);
	memcpy(&testGame, &Game, sizeof(struct gameState));

	printf("Testing Salvager Card\n\n");

	for(i = 0; i < numPlayers; i++){
		//reset game copy 
		memcpy(&testGame, &Game, sizeof(struct gameState));
	
		//play card
		cardEffect(salvager, 1, 0, 0, &testGame, 0, 0);

		printf("Player %d:\n", i);

		//test that the player lost 1 card (this card and an additional)
		printf("\tExpected HandCount: %d\n\tActual HandCount: %d\n", Game.handCount[i] - 2, testGame.handCount[i]);
		testGame.handCount[i] == Game.handCount[i] - 2 ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		//test that the player's deck has not changed
		printf("\tExpected DeckCount: %d\n\tActual DeckCount: %d\n", Game.deckCount[i], testGame.deckCount[i]);
		testGame.deckCount[i] == Game.deckCount[i] ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		//test that player has only gained 1 buy
		printf("\tExpected Number of Buys: %d\n\tActual Number of Buys: %d\n", Game.numBuys + 1, testGame.numBuys);
		testGame.numBuys == Game.numBuys + 1 ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		//test that player has gained at least the smallest
		//card's amount of coins (2 unless curse or copper, 0)
		printf("\tExpected CoinCount: at least %d\n\tActual CoinCount: %d\n", Game.coins + 2, testGame.coins);
		if(Game.coins + 2 == testGame.coins)
			printf("\tTest Pass\n");
		//if player chose copper or curse, no change
		else if(testGame.coins == Game.coins)
			printf("\tTest Pass\n");
		else
			printf("\tTest Fail\n");

		//test that only 2 cards is discarded
		printf("\tExpected DiscardCount: %d\n\tActual DiscardCount: %d\n", Game.discardCount[i] + 2, testGame.discardCount[i]);
		testGame.discardCount[i] == Game.discardCount[i] + 2 ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		//test which player's turn
		printf("\tExpected Player's Turn: %d\n\tActual Player's Turn: %d\n", Game.whoseTurn, testGame.whoseTurn);
		Game.whoseTurn == testGame.whoseTurn ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		Game.whoseTurn++;
	}

	//zero if no errors
	return 0;
}
