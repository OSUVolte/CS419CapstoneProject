//Joseph Cuellar
//CS - 362
//TEST - Adventurer Card 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int AdventurerTEST(struct gameState *postGameState);

int main()
{
	int player = 0;
	int numTests = 500;
	int i, j, k, m, n;
	struct gameState postGameState;

	for (i = 0; i < sizeof(struct gameState); i++) { 
		((char*)&postGameState)[i] = floor(Random() * 256);
	}
	
	postGameState.whoseTurn = player;
	SelectStream(2);
	PutSeed(3);
	printf ("START - Running callAdventurerCard().\n\n");
	
	for(k = 0; k < numTests; k++){
		postGameState.handCount[player] = floor(Random() * MAX_HAND)+1;
		postGameState.deckCount[player] = floor(Random() * MAX_DECK);
		postGameState.discardCount[player] = floor(Random() * MAX_DECK);
		for(m = 0; m < postGameState.handCount[player]; m++)	{
			postGameState.hand[player][m] = floor(Random() * treasure_map) + 1;
		}
		
		for(j = 0; j < postGameState.discardCount[player]; j++){
			postGameState.discard[player][j] = floor(Random() * treasure_map) + 1;
		}

		for(n = 0; n < postGameState.deckCount[player]; n++)	{
			postGameState.deck[player][n] = floor(Random() * treasure_map) + 1;
		}
		AdventurerTEST(&postGameState);
	}
	printf ("STOP - Running callAdventurerCard().\n\n");
	return 0;
}

int AdventurerTEST(struct gameState *postGameState){
	int player = postGameState->whoseTurn;
	int preTreasure, postTreasure;
	int i, j;
	int card;
	struct gameState pre;
	memcpy(&pre, postGameState, sizeof(struct gameState));
	
	//callAdventurerCard(postGameState, player );
	int preTotal = pre.deckCount[player] + pre.discardCount[player] - 2;
	int postTotal = postGameState->deckCount[player] + postGameState->discardCount[player];
	if(postTotal != preTotal)
	{
		printf("ERROR! post total is not 2 treasure cards less than pre total. \n");
	}

	pre.handCount[player] =  pre.handCount[player]+2;
	if(postGameState->handCount[player] != pre.handCount[player]){
		printf("ERROR! pre hand count does not equal post hand count. \n");
	}
	
	for(i = 0; i < pre.handCount[player]; i++){
		card = pre.hand[player][i];
		if (card == copper || card == silver || card == gold)
			preTreasure++;
	}
	for(j = 0; j < postGameState->handCount[player]; j++){
		card = postGameState->hand[player][j];
		if (card == copper || card == silver || card == gold)
			postTreasure++;
	}
	
	if(!(postTreasure > preTreasure)){
		printf("ERROR! Not enough treasure cards added to hand. \n");
	}
	return 0;
}