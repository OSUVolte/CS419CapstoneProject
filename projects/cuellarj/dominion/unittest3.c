//Assignment #3 - Joseph Cuellar
//CS - 362
//Test to see if the game is over
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

const int SUPPLY_COUNT = 5;

int IsGameOverTEST(struct gameState *postGameState);

int main(){
	struct gameState postGameState;
	int provincesCount;
	
	SelectStream(2);
	PutSeed(3);
	printf ("START - Running isGameOver() unittest4.\n\n");
	
	int i;
	for(provincesCount = 0; provincesCount < 3; provincesCount++){
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&postGameState)[i] = floor(Random() * 256);
		}
		postGameState.supplyCount[province] = provincesCount;
		IsGameOverTEST(&postGameState);
	}
	
	int j;
	for(j = 0; j <= treasure_map; j++){
		postGameState.supplyCount[j] = SUPPLY_COUNT;
	}
	
	postGameState.supplyCount[copper] = 0;
	postGameState.supplyCount[silver] = 0;
	postGameState.supplyCount[gold] = 0;
	
	IsGameOverTEST(&postGameState);
	

	for(j = 0; j <= treasure_map; j++){
		postGameState.supplyCount[j] = SUPPLY_COUNT;
	}
	postGameState.supplyCount[silver] = 0;
	postGameState.supplyCount[gold] = 0;
	IsGameOverTEST(&postGameState);
	
	printf ("STOP - Running isGameOver() unittest4.\n\n");
	return 0;
}

int IsGameOverTEST(struct gameState *postGameState){
	int suppliesAvailable, card;
	int functionOutput = isGameOver(postGameState);
	
	if(postGameState->supplyCount[province] == 0){
		if(functionOutput != 1)	{
			printf("ERROR! supplyCount was 0 and isGameOver failed.\n\n");
		}
	}
	else{
		suppliesAvailable = 0;
		for(card = 0; card <= treasure_map; card++){
			if(postGameState->supplyCount[card] == 0){
				suppliesAvailable++;
			}
		}
		
		if(suppliesAvailable >= 3 && functionOutput !=1){
			printf("ERROR! 3 supply counts were empty and isGameOver failed.\n\n");
		}
	}
	return 0;
}