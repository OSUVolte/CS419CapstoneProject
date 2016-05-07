/*
 * Miranda Weldon
 * April 23, 2016
 * CS 362 Spring 2016
 * Assignment 3
 * cardtest2.c
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
	int k[10] = {feast, gardens, embargo, remodel, tribute, mine, cutpurse, ambassador, great_hall, smithy};

	//start up original game and create a copy
	initializeGame(numPlayers, k, 1000, &Game);
	memcpy(&testGame, &Game, sizeof(struct gameState));

	printf("Testing Smithy Card\n");

	for(i = 0; i < numPlayers; i++){
		//reset game copy 
		memcpy(&testGame, &Game, sizeof(struct gameState));
	
		//play card
		cardEffect(smithy, 0, 0, 0, &testGame, 0, 0);

		printf("Player %d:\n", i);

		//test that the player has 3 new cards
		printf("\tExpected HandCount: %d\n\tActual HandCount: %d\n", Game.handCount[i] + 2, testGame.handCount[i]);
		Game.handCount[i] + 2 == testGame.handCount[i] ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		//test that the player's deck lost 3 cards
		printf("\tExpected DeckCount: %d\n\tActual DeckCount: %d\n", Game.deckCount[i] - 3, testGame.deckCount[i]);
		Game.deckCount[i] - 3 == testGame.deckCount[i] ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		//test that only 1 card is discarded
		printf("\tExpected DiscardCount: %d\n\tActual DiscardCount: %d\n", Game.discardCount[i] + 1, testGame.discardCount[i]);
		Game.discardCount[i] + 1 == testGame.discardCount[i] ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		//test which player's turn
		printf("\tExpected Player's Turn: %d\n\tActual Player's Turn: %d\n", Game.whoseTurn, testGame.whoseTurn);
		Game.whoseTurn == testGame.whoseTurn ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		Game.whoseTurn++;
	}

	//zero if no errors
	return 0;
}
