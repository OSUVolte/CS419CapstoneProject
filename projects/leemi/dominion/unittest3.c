#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>


void testGainCard(){
	int numPlayers = 2;
	int seed = 500;
	int k[10] = {adventurer, village, mine, smithy,
		remodel, feast, great_hall, gardens, embargo, minion}; 

	struct gameState game;
	struct gameState emptyGame;
	int flag, p = 0, ret;

	printf("==================Testing GainCard==================\n\n");

	memset(&game, 23, sizeof(struct gameState));
	memset(&emptyGame, 23, sizeof(struct gameState));
	
	initializeGame(numPlayers, k, seed, &game);
	initializeGame(numPlayers, k, seed, &emptyGame);
//add to discard
	flag = 0;	

	int discCount, handCount, deckCount, supCount;
	game.supplyCount[silver] = 0;
	//supply pile is empty cant gainCard from it
	ret = gainCard(silver, &game, flag, p);
	assert(ret == -1);
	
	printf("---Reset Game---\n");
	memcpy(&game, &emptyGame, sizeof(struct gameState));	

	//previous info
	discCount = game.discardCount[p];
	handCount = game.handCount[p];
	deckCount = game.deckCount[p];

	int i;
	for(flag = 0; flag<3; flag++){
		if(flag == 0)
			printf("---Testing all card types with gainCard for flag=0 (discard)---\n");
		else if(flag == 1)
			printf("---Testing all card types with gainCard for flag=1 (deck)---\n");
		else if(flag == 2)
			printf("---Testing all card types with gainCard for flag=2 (hand)---\n");
		for(i = 0; i < 27; i++){
			supCount = game.supplyCount[i];
			if(supCount != -1){
				gainCard(i, &game, flag, p);
				if(flag == 0){//ensure only disc count changes
					assert(game.discardCount[p] == discCount + 1);
					assert(game.deckCount[p] == deckCount);
					assert(game.handCount[p] == handCount);
				}
				else if (flag == 1){//ensure only deckcount changes
					assert(game.discardCount[p] == discCount);
					assert(game.deckCount[p] == deckCount + 1);
					assert(game.handCount[p] == handCount);
				}
				else if (flag == 2){//ensure only handcount changes
					assert(game.discardCount[p] == discCount);
					assert(game.deckCount[p] == deckCount);
					assert(game.handCount[p] == handCount + 1);
				}
				assert(game.supplyCount[i] == supCount - 1);//ensure supply count decreased for card type		
				memcpy(&game, &emptyGame, sizeof(struct gameState));//reset state of game for next card type	
			}
		} 
		printf("---success---\n");
	}

	printf("---Testing gainCard for single supply until hits zero---\n");
	printf("---Making sure supply doesn't go below 0---\n");
	flag = 0;
	int _supCount;
	supCount = game.supplyCount[silver];
	_supCount = game.supplyCount[silver];
	discCount = game.discardCount[p];
	for(i = 0; i< supCount + 5; i++){
		//printf("I: %d Flag: %d Game: %d Expected %d SupCount: %d Expected %d\n", i, flag, game.discardCount[p], discCount, game.supplyCount[silver], _supCount);

		if(_supCount != 0){
			gainCard(silver, &game, flag , p);	

			assert(game.discardCount[p] == discCount + 1 );
			assert(game.supplyCount[silver] == _supCount - 1);

			discCount = game.discardCount[p];
			_supCount = game.supplyCount[silver];
		}
		else{
			gainCard(silver, &game, flag, p);
			assert(game.supplyCount[silver] == _supCount);
			assert(game.supplyCount[silver] == 0);// hits zero and doesn't go below, supply cant go below 0
			_supCount = game.supplyCount[silver];
		}
	}
	printf("---success---\n");
}

int main(){
	testGainCard();
	printf("\n\n");
	printf("=======================Sucess=====================");
	printf("\n\n");
	return 0;
}
