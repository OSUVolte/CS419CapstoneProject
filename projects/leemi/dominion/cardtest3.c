#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>

void testCardCouncil(){
	int numPlayers = 4;
	int seed = 500;
	int k[10] = {council_room, village, mine, smithy,
		remodel, feast, great_hall, gardens, embargo, minion}; 

	struct gameState game;
	struct gameState emptyGame;
	int p = 0;


	memset(&game, 23, sizeof(struct gameState));
	memset(&emptyGame, 23, sizeof(struct gameState));
	
	initializeGame(numPlayers, k, seed, &game);
	initializeGame(numPlayers, k, seed, &emptyGame);

	printf("==================Testing=================\n\n");

	//previous hand count
	int handCount[4];
	handCount[0] = game.handCount[p];
	handCount[1] = game.handCount[p + 1];
	handCount[2] = game.handCount[p + 2];
	handCount[3] = game.handCount[p + 3];

	//previous deck count
	int deckCount[4];
	deckCount[0] = game.deckCount[p];
	deckCount[1] = game.deckCount[p + 1];
	deckCount[2] = game.deckCount[p + 2];
	deckCount[3] = game.deckCount[p + 3];

	int i;
	printf("---checking that hand count goes up for player who plays council by 4-1 (discards council card) and hand count goes up for every other player by 1---\n");
	printf("---Assert that deck count goes down by corresponding amount---\n");
	for(p=0;p<4; p++){
		cardCouncil(&game, p, 0); 
		for(i=0;i<4;i++){
			if(i == p){//current player
				
				assert(game.handCount[p] == handCount[p] + 4);
				assert(game.deckCount[p] == deckCount[p] - 4);
				//assert(game.handCount[p] == handCount[p] + 3);
			}
			else{//other players
				assert(game.handCount[i] == handCount[i] + 1);
				assert(game.deckCount[i] == deckCount[i] - 1);
			}
		}	
		memcpy(&game, &emptyGame, sizeof(struct gameState));
	}

	printf("---BUG cardcouncil is not discarded afterwards---\n");
}

int main(){
	printf("\n\n");
	testCardCouncil();
	printf("===========================finish======================");
	printf("\n\n");
	return 0;
}
