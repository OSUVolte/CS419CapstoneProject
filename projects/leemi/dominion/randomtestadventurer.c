#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int testAdventurer(struct gameState actual, struct gameState previous, int curPlay);
int countCoins(struct gameState actual, int curPlay);

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
	
		//randomize how many coins in hand min of 3 coins
		int numCoins = rand() % game.handCount[curPlay] + 3;
		//printf("%d\n", numCoins);
		int j;
		for(j=0;j<numCoins;j++){
			int pos = rand() % game.handCount[curPlay];
			int randCoin = rand() % 3 + 4;
			game.hand[curPlay][pos] = randCoin;
		}	

		memcpy(&compareGame, &game, sizeof(struct gameState));
		int temphand[MAX_HAND];
		//call adventurer
		cardAdventurer(&game, 0, curPlay, temphand, 0, 0);
		errors = errors + testAdventurer(game, compareGame, curPlay);


	}
	printf("There were %d errors\n", errors);
	return 0;
}

int testAdventurer(struct gameState actual, struct gameState previous, int curPlay){
	int error = 0;
	if(actual.deckCount[curPlay] >= previous.deckCount[curPlay]){
	//	printf("new deck size: %d old deck size: %d\nnew deck should be smaller  than old deck\n", actual.deckCount[curPlay], previous.deckCount[curPlay]);
		error++;
	}

	if(actual.discardCount[curPlay] < previous.discardCount[curPlay]){
		printf("new discard count: %d old discard count: %d\ndiscard count is less than old deck\n", actual.discardCount[curPlay], previous.discardCount[curPlay]);
		error++;
	}

	if(countCoins(actual, curPlay) != 2 + countCoins(previous, curPlay)){
	//	printf("new coins: %d, oldCoins: %d\n", countCoins(actual, curPlay), countCoins(previous,curPlay));
	//	printf("didn't increase coin count\n");
		error++;
	}	

	if(actual.handCount[curPlay] != 2 + previous.handCount[curPlay]){
		//printf("player hand count was not increased\n");
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


int countCoins(struct gameState actual, int curPlay){
	int newHandCount = actual.handCount[curPlay];
	int i;
	int newCoins = 0; 
	for(i=0;i<newHandCount;i++){
		if(actual.hand[curPlay][i] == copper){
			newCoins++;
		}
		else if(actual.hand[curPlay][i] == silver){
			newCoins++;
		}
		else if(actual.hand[curPlay][i] == gold){
			newCoins++;
		}
	}
	return newCoins;
}
