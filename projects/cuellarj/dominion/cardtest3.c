//Joseph Cuellar
//CS - 362
//TEST - Village Card 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int VillageTEST(struct gameState *post, int handPos);

int main(){
	int player = 0;
	int numTests = 500;
	int i, j, k, m, n, q, handPos;
	struct gameState postGameState;

	
	SelectStream(2);
	PutSeed(3);
	printf ("START - Running callVillageCard().\n\n");
	
	for(k = 0; k < numTests; k++){
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&postGameState)[i] = floor(Random() * 256);
		}
		postGameState.whoseTurn = player;
		postGameState.numActions = 1;

		postGameState.handCount[player] = floor(Random() * MAX_HAND)+1;
		postGameState.deckCount[player] = floor(Random() * MAX_DECK);
		postGameState.discardCount[player] = floor(Random() * MAX_DECK);
		postGameState.playedCardCount = floor(Random() * MAX_DECK);
		
		for(m = 0; m < postGameState.handCount[player]; m++)	{
			postGameState.hand[player][m] = floor(Random() * treasure_map) + 1;
		}
		
		for(j = 0; j < postGameState.discardCount[player]; j++)	{
			postGameState.discard[player][j] = floor(Random() * treasure_map) + 1;
		}

		for(n = 0; n < postGameState.deckCount[player]; n++)	{
			postGameState.deck[player][n] = floor(Random() * treasure_map) + 1;
		}
		for(q = 0; q < postGameState.playedCardCount; q++){
			postGameState.playedCards[q] = floor(Random() * treasure_map) + 1;
		}
		
		handPos = floor(Random() * postGameState.handCount[player]);
		postGameState.hand[player][handPos] = village;
		
		VillageTEST(&postGameState, handPos);
		
	}
	
	printf ("STOP - Running callVillageCard().\n\n");
	return 0;
}

int VillageTEST(struct gameState *postGameState, int handPos){
	int player = postGameState->whoseTurn;
	struct gameState pre;
	memcpy(&pre, postGameState, sizeof(struct gameState));
	
	callVillageCard(player, postGameState, handPos);
	
	if(pre.handCount[player] != postGameState->handCount[player]){
		printf("ERROR! hand counts should match. \n");
	}

	pre.numActions = pre.numActions + 2;
	if(pre.numActions != postGameState->numActions){
		printf("ERROR! number of actions should match. \n");
	}
	
	return 0;
}