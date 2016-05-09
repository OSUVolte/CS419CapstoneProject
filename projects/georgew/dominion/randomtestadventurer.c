#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>
#include "rngs.h"
#include <stdlib.h>
#include "interface.h"

#define TESTCARD "adventurer"

int callFunction(struct gameState *G, int numPlayers);

int main() {
  	int seed = 1000;
	int testCounter = 0;
	int failedTests = 0;
	struct gameState G, testG;
	//start and end variables
	time_t start = time(NULL);
	time_t end;
	//5 minutes
	time_t seconds = 300; 
	//1 minute
	//time_t seconds = 60; 
	end = start + seconds;
	int numPlayers;
	int k[10] = {adventurer, great_hall, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	printf("\n\n\n\n----------------- Testing Card: %s ----------------\n", TESTCARD);
	//get random number of players
	while(start < end){
		testCounter++;
		//wait 1 second
		//sleep(1);
		//set numPlayers
		//printf("\nSetting Random Variables for CardEffect\n");
		//set num players between 1 and 4
		numPlayers = rand()%MAX_PLAYERS + 1;
		//printf("NumPlayers: %d ", numPlayers);
		assert(numPlayers != 0 && numPlayers < 5); 
		//initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);
		//save current state	
		memcpy(&testG, &G, sizeof(struct gameState));
		//set up CardEffect function
		failedTests += callFunction(&G, numPlayers);
		//reset state
		memcpy(&G, &testG, sizeof(struct gameState));
		//reset start	
		start = time(NULL);
	}
	printf("\n TOTAL TESTS RUN: %d\n", testCounter);
	printf("\n FAILED TESTS: %d\n", failedTests);
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n\n\n", TESTCARD);
return 0;
}

int callFunction(struct gameState *G, int numPlayers){
	int thisPlayer, choice1, choice2, choice3, handPos;
	int deckCount;
	int shuffle;
	int bonus = 0;
	int coinsStart, coins;
	//set current player
	thisPlayer = rand() % MAX_PLAYERS;
	//get valid player
	while(thisPlayer >= numPlayers){
		thisPlayer = rand() % MAX_PLAYERS;
	}
	//set current player to whose turn
	G->whoseTurn = thisPlayer;
	//set choices
	choice1 = rand() % 2 - 1;
	choice2 = rand() % 2 - 1;
	choice3 = rand() % 2 - 1;
	//printf("choice 1: %d choice 2:  %d choice 3: %d ", choice1, choice2, choice3);
	assert(choice1 > -2 && choice2 > -2 && choice3 > -2);
	assert(choice1 < 2 && choice2 < 2 && choice3 < 2);
	//set deckCount to random value
	deckCount = rand() % MAX_DECK;
	if(deckCount < 1){
		shuffle = 1;
	}
	G->deckCount[thisPlayer] = deckCount;
	//set hand pos
	handPos = rand() % MAX_HAND;
	//printf("HandPos: %d ", handPos);
	coinsStart = countHandCoins(thisPlayer, G);
	//printf("\nCoins Before: %d", coinsStart);
	//call cardEffect function
	//printf("\nCall Card Effect\n");
	cardEffect(adventurer, choice1, choice2, choice3, G, handPos, &bonus);
	coins = countHandCoins(thisPlayer, G);
	//printf("Coins After: %d\n", coins);
	if (coins - coinsStart != 2){
		//printf("ERROR ERROR!! TEST DID NOT PERFORM AS EXPECTED!!!\n");
		//printf("NumPlayers: %d, Current Player: %d, choice1: %d, choice2: %d, choice3: %d HandPos: %d\n", numPlayers, thisPlayer, choice1, choice2, choice3, handPos);
		//if(shuffle)
			//printf("Shuffle Run\n");
		return 1;
	}
	return 0;
}


