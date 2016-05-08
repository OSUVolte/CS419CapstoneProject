//
//Michael Lee
//Smithy random testing
//
//
//


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int testSmithy(struct gameState actual, struct gameState previous, int curPlay);
void printCondition(struct gameState actual,struct gameState previous,  int curPlay);

int main() {
	srand(time(NULL));

	struct gameState game, compareGame;
	int numPlay, curPlay;
	
	int k[10] = {adventurer, embargo, village, mine, gardens, smithy, council_room, minion, tribute, feast};
	int seed = 500;
	int i; 
	int numRandTest = 10000;
	int errors = 0;
	//for 10000 random tests
	for(i=0; i<numRandTest; i++){
		//get random num of players
		numPlay = (rand() % 3) + 2;
		initializeGame(numPlay, k, seed, &game);
		
		//randomize the game settings
		curPlay = 0;
		
		game.deckCount[curPlay] = (rand() % MAX_DECK) + 4;
		game.discardCount[curPlay] = MAX_DECK - game.deckCount[curPlay];
		game.handCount[curPlay] = (rand() % MAX_HAND) + 1;
		//printf("%d\n", game.handCount[curPlay]);
		game.whoseTurn = curPlay;
	

		memcpy(&compareGame, &game, sizeof(struct gameState));
		//call Smithy
		cardSmithy(&game, curPlay, 0);
		errors = errors + testSmithy(game, compareGame, curPlay);
	}
	printf("There were %d errors\n", errors);
	return 0;
}

int testSmithy(struct gameState actual, struct gameState previous, int curPlay){
	int error = 0;
	if(actual.deckCount[curPlay] != previous.deckCount[curPlay]-3){
		//printf("the deck count should have decreased by three\n");
		//printCondition(actual, previous, curPlay);
		error++;
	}
	if(actual.discardCount[curPlay] != previous.discardCount[curPlay]  + 3){
		//printf("the discard count should have increased by three\n");
		//printCondition(actual, previous, curPlay);
		error++;
	}
	if(actual.handCount[curPlay] != previous.handCount[curPlay] + 3){
		//printf("the hand count should have increased by three\n");
		//printCondition(actual, previous, curPlay);
		error++;
	}
	int i;
	for(i=1; i<4; i++){
		//printf("other player was changed in some way\n");
		if(actual.deckCount[i] != previous.deckCount[i]){
			error++;
		}
		if(actual.discardCount[i] != previous.discardCount[i]){
			error++;
		}
		if(actual.handCount[i] != previous.handCount[i]){
			error++;
		}
	}

	return error;

}

void printCondition(struct gameState actual, struct gameState previous, int curPlay){
	printf("Previous DeckCount: %d New DeckCount: %d\n", previous.deckCount[curPlay], actual.deckCount[curPlay]);
	printf("Previous discardCount: %d New discardCount: %d\n", previous.discardCount[curPlay], actual.discardCount[curPlay]);
	printf("Previous handCount: %d New handCount: %d\n", previous.handCount[curPlay], actual.handCount[curPlay]);
}

