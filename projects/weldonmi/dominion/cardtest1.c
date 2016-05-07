/*
 * Miranda Weldon
 * April 24, 2016
 * CS 362 Spring 2016
 * Assignment 3
 * cardtest1.c
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
	int k[10] = {feast, gardens, embargo, remodel, adventurer, mine, cutpurse, ambassador, great_hall, smithy};

	//start up original game and create a copy
	initializeGame(numPlayers, k, 1000, &Game);
	memcpy(&testGame, &Game, sizeof(struct gameState));

	printf("Testing Adventurer Card\n\n");

	for(i = 0; i < numPlayers; i++){
		//reset game copy 
		memcpy(&testGame, &Game, sizeof(struct gameState));
	
		//play card
		cardEffect(adventurer, 0, 0, 0, &testGame, 0, 0);

		printf("Player %d:\n", i);

		//test that the player has 2 new cards
		printf("\tExpected HandCount: %d\n\tActual HandCount: %d\n", Game.handCount[i] + 2, testGame.handCount[i]);
		Game.handCount[i] + 2 == testGame.handCount[i] ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		//test that 2 of the cards in the new hand are treasure cards
		int j, treasureCardCount;
		for(j = 0; j < Game.handCount[i]; j++){
			if(testGame.hand[i][j] == copper || testGame.hand[i][j] == silver || testGame.hand[i][j] == gold)
				treasureCardCount++;
		}
		printf("\tExpected TreasureCardCount: at least 2\n\tActual TreasureCardCount: %d\n", testGame.handCount[i]);
		testGame.handCount[i] >= 2 ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		//test that the player's deck lost at least 2 cards
		printf("\tExpected DeckCount: at most %d\n\tActual DeckCount: %d\n", Game.deckCount[i] - 2, testGame.deckCount[i]);
		testGame.deckCount[i] <= Game.deckCount[i] - 2 ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		//test that at least 0 card is discarded, is this needed?
		printf("\tExpected DiscardCount: at least 0\n\tActual DiscardCount: %d\n", testGame.discardCount[i]);
		testGame.discardCount[i] >= 0 ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		//test which player's turn
		printf("\tExpected Player's Turn: %d\n\tActual Player's Turn: %d\n", Game.whoseTurn, testGame.whoseTurn);
		Game.whoseTurn == testGame.whoseTurn ? printf("\tTest Pass\n") : printf("\tTest Fail\n");

		Game.whoseTurn++;
	}

	//zero if no errors
	return 0;
}
