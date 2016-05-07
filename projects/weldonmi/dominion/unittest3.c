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

//main function
int main (){
	//declare variables
	int i, j, fullCardTally, numPlayers = 3, numCardTypes = 27, numCards = 299, seed = 1000;
	//numCards reflects how many cards are in use for a 3 player game, can be change if needed if numPlayers changed
	//numCardTypes, there are 27 types of cards in this implementation of dominion, don't change
	struct gameState Game, testGame;
	int k[10] = {feast, gardens, salvager, remodel, sea_hag, mine, cutpurse, ambassador, great_hall, smithy};
	int fullCardTallyList[numCardTypes];

	//start up original game and create a copy
	initializeGame(numPlayers, k, seed, &Game);
	memcpy(&testGame, &Game, sizeof(struct gameState));

	printf("Testing fullDeckCount()\n\n");

	//tally up all of each card from all players
	printf("Counting Cards from all Players...\n");
	for(i = 0; i < numPlayers; i++)
		for(j = 0; j < numCardTypes; j++){
			fullCardTallyList[j] = fullDeckCount(i, j, &testGame);
			printf("\tCard %d Count: %d\n", j, fullCardTallyList[j]);
		}

	//combine cards in deck, hand, or discard
	printf("Combining Final Tally (-1 cards not counted)\n");
	for(i = 0; i < numCardTypes; i++)
		fullCardTally += fullCardTallyList[i];
	//add cards in supply
	for(i = 0; i < numCardTypes; i++){
		printf("\tCard %d Count (Supply): %d\n", i, supplyCount(i, &testGame));
		if(supplyCount(i, &testGame) != -1)
			fullCardTally += supplyCount(i, &testGame);
	}

	//check that no cards are missing or extra
	printf("Expected Card Count: %d\nActual Card Count: %d\n", numCards, fullCardTally);
	if(fullCardTally == numCards)		//20+36+70+39+24+80=206 cards
		printf("\tTest Pass - No Missing or Extra Cards\n");
	else if(fullCardTally > numCards)
		printf("\tTest Fail - Too Many Cards\n");
	else if(fullCardTally < numCards)
		printf("\tTest Fail - Too Few Cards\n");

	//zero if no errors
	return 0;
}
