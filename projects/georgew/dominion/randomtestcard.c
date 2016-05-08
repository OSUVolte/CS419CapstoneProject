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

#define TESTCARD "minion"

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
	int bonus = 0;
	int faults = 0;
	int coinsStart, coins, actions;
	//set current player
	thisPlayer = rand() % MAX_PLAYERS;
	//get valid player
	while(thisPlayer >= numPlayers){
		thisPlayer = rand() % MAX_PLAYERS;
	}
	//set current player to whose turn
	G->whoseTurn = thisPlayer;
	//set choices
	//choice1 = 1;
	choice1 = rand() % 2;
	choice2 = rand() % 2;
	choice3 = rand() % 2;
	//choice2 = 1;
	//printf("choice 1: %d choice 2:  %d choice 3: %d ", choice1, choice2, choice3);
	assert(choice1 > -2 && choice2 > -2 && choice3 > -2);
	assert(choice1 < 2 && choice2 < 2 && choice3 < 2);
	//set hand pos
	handPos = rand() % MAX_HAND;
	//printf("HandPos: %d ", handPos);
	coinsStart = G->coins;
	actions = G->numActions;
	//printf("\nCoins Before: %d", coinsStart);
	//call cardEffect function for minion
	//printf("\nCall Card Effect\n");
	cardEffect(minion, choice1, choice2, choice3, G, handPos, &bonus);
	coins = G->coins;
	//printf("Coins After: %d\n", coins);
	if (G->numActions != (actions + 1)){
		//printf("\nActions Before: %d Actions After: %d\n", actions, G->numActions);
		faults++;
	}
	//if choice1
	if (coins - coinsStart != 2 && (choice1 == 1 && choice2 == 0 && choice3 == 0)){
		//printf("\nCoins Before: %d Coins After: %d\n", coinsStart, coins);
		faults++;
	}
	//if choice2
	if (choice1 == 0 && choice2 == 1 && choice3 == 0){
		int i;
		for(i = 0; i < G->numPlayers; i++){
			if(i == thisPlayer){
				//printf("Current Player: %d Number of Cards: %d\n", i, G->handCount[i]);	
				if(G->handCount[i] != 4){
					//printf("\nExpected Hand Count: 4 Actual Hand Count: %d\n", G->handCount[i]);
					faults++;
				}
			}
			if(G->handCount[i] > 4 && i != thisPlayer){
				//printf("Player Number: %d Expected Hand Count: Less Than 4 Actual Hand Count: %d\n",i ,G->handCount[i]);
				//printf("Player: %d Number of Cards: %d\n", i, G->handCount[i]);
				faults++;
			}
		}
	}
	if(faults != 0){
		//printf("ERROR ERROR!! TEST DID NOT PERFORM AS EXPECTED!!!\n");
		//printf("There were %d Error(s)\n", faults);
		//printf("NumPlayers: %d, Current Player: %d, choice1: %d, choice2: %d, choice3: %d HandPos: %d\n\n", numPlayers, thisPlayer, choice1, choice2, choice3, handPos);
		return 1;	
	}
	return 0;	
}
