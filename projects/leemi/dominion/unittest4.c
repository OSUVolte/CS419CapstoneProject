#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>

void testIsGameOver(){
	int numPlayers = 2;
	int seed = 500;
	int k[10] = {adventurer, village, mine, smithy,
		remodel, feast, great_hall, gardens, embargo, minion}; 

	struct gameState game;
	struct gameState emptyGame;
	printf("==================Testing isGameOver==================\n\n");

	memset(&game, 23, sizeof(struct gameState));
	memset(&emptyGame, 23, sizeof(struct gameState));

	printf("---initializing game---\n");
	initializeGame(numPlayers, k, seed, &game);
	initializeGame(numPlayers, k, seed, &emptyGame);
	//start of game default test
	assert(isGameOver(&game) == 0);	
	printf("---Game is not over---\n\n");

	printf("---Setting supplyCount: province to 0---\n");
	game.supplyCount[province] = 0;
	assert(isGameOver(&game) == 1);
	printf("---Game is over---\n\n");
	
	printf("---Reset Game---\n");	
	memcpy(&game, &emptyGame, sizeof(struct gameState));
	printf("---Setting supplyCount: estate, adventurer to 0---\n");
	printf("---2 SUPPLY COUNTS AT 0 EXPECT NO GAME OVER---\n");
	game.supplyCount[estate] = 0;
	game.supplyCount[adventurer] = 0;
	assert(isGameOver(&game) == 0);
	printf("---Game is not over---\n\n");
		
	
	printf("---Reset Game---\n");	
	memcpy(&game, &emptyGame, sizeof(struct gameState));
	printf("---Setting supplyCount: estate, copper, adventurer to 0---\n");
	printf("---3 SUPPLY COUNTS AT 0 EXPECT GAME OVER---\n");
	game.supplyCount[estate] = 0;
	game.supplyCount[copper] = 0;
	game.supplyCount[adventurer] = 0;
	assert(isGameOver(&game) == 1);
	printf("---Game is over---\n\n");
		
	printf("---Reset Game---\n");	
	memcpy(&game, &emptyGame, sizeof(struct gameState));
	printf("---Setting supplyCount: estate, copper, silver, adventurer to 0---\n");
	printf("---4 SUPPLY COUNTS AT 0 EXPECT GAME OVER---\n");
	game.supplyCount[estate] = 0;
	game.supplyCount[copper] = 0;
	game.supplyCount[silver] = 0;
	game.supplyCount[adventurer] = 0;
	assert(isGameOver(&game) == 1);
	printf("---Game is over---\n\n");
		

	printf("---Reset Game---\n");	
	memcpy(&game, &emptyGame, sizeof(struct gameState));
	printf("---Setting supplyCount: estate, copper, silver to negative---\n");
	printf("---3 SUPPLY COUNTS AT -1 EXPECT GAME OVER---\n");
	game.supplyCount[estate] = -1;
	game.supplyCount[copper] = -1;
	game.supplyCount[silver] = -1;
	//assert(isGameOver(&game) == 1);
	printf("---Consider changing if supplycount <= 0 in any case supply goes lower than 0---\n");
	
	printf("---Game is not over---\n\n");
}

int main(){
	testIsGameOver();
	printf("=======================Sucess=====================");
	printf("\n\n");
	return 0;
}
