//unittest2.c
//shuffle function
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define FUNCTION "shuffle"

int main() {
	int i, j, l;
	int tempDeck[MAX_DECK];
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	int currDeckCount, startingDeckCount, endingDeckCount;
	int deckPos = 0;
	int sameCount = 0;
	struct gameState G, testG;

	int k[10] = {curse, estate, village, remodel, 
		council_room, adventurer, province, smithy, steward, tribute};
	//initialize game, state and player cards
	initializeGame(numPlayers, k, seed, &G);
	printf("----------------- Testing Function: %s ----------------\n", FUNCTION);
	printf("-------------Saving Current Game State----------------\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("--------------------Checking valid deckCount\n------------");
	//store deckCount
	currDeckCount = testG.deckCount[thisPlayer];
	//change deckCount
	testG.deckCount[thisPlayer] = 0;
	//shuffle to find error condition
	if (shuffle(thisPlayer, &testG) == -1)
		printf("No Cards to Count: SUCCESS\n");
	//restore deckCount
	testG.deckCount[thisPlayer] = currDeckCount;
	
	printf("----------------------------Checking Each Player----------------------\n");
	for (i=0; i < numPlayers; i++){
		//revert to starting game 
		memcpy(&G, &testG, sizeof(struct gameState));
		//set current player
		thisPlayer = i;
		printf("\nPlayer Number: %d\n", thisPlayer);
		if (testG.discardCount[i] == 0)
			printf("Player %d: Current Discard Count: %d\n", i, testG.discardCount[i]);
		else
			printf("Discard Pile should be empty");
		//output starting deck count
		printf("Player %d: Starting Deck Count: %d\n",i ,testG.deckCount[i]);
		//printf("----------Saving Current Deck--------\n");
		startingDeckCount = testG.deckCount[thisPlayer];
		j = testG.deckCount[thisPlayer];
		//iterate through deck and save to tempDeck
		//reset deckPos
		deckPos = 0;
		while (j > 0) {
			j--;
			tempDeck[j] = testG.deck[thisPlayer][j];
			deckPos++;
		}
		//shuffle deck
		shuffle(thisPlayer, &testG);
		//get final deck count
		endingDeckCount = testG.deckCount[thisPlayer];
		printf("Player %d: Ending Deck Count: %d\n", i, testG.deckCount[i]);
		//check if change in deckCount
		if (startingDeckCount == endingDeckCount){
			printf("Deck Count Start: %d Deck Count Finish: %d\n", startingDeckCount, endingDeckCount);
		}
		else
			printf("Deck Count should stay the same: FAIL\n");
		//output shuffled cards and check to see if shuffled
		for (l = 0; l < deckPos; l++){
			printf("\nBefore Shuffle Function Card at Position %d: %d", l, tempDeck[l]);
			printf("\nAfter Shuffle Function Card at Position %d: %d", l, (testG.deck[thisPlayer][l]));
			if (tempDeck[l] == testG.deck[thisPlayer][l]){
				sameCount++;
			}
		}
		if (sameCount == endingDeckCount){
			printf("\nCards were not suffled: FAIL\n");
		}
		else
			printf("\nCards Shuffled: SUCCESS\n");
		//check for game state changes
		//assert(testG.deckCount[thisPlayer] == testG.deckCount[thisPlayer]);
		//assert(testG.coins == testG.coins);
		//assert(testG.playedCardCount == testG.playedCardCount);
		//assert(testG.numPlayers == testG.numPlayers);
		//check discard
		if (testG.discardCount[i] == 0)
			printf("Player %d: Current Discard Count: %d\n",i ,testG.discardCount[i]);
		else
			printf("Discard Pile should be empty");
	}
		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", FUNCTION);
	return 0;
}
