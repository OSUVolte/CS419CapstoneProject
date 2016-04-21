//Joseph Cuellar
//CS - 362
//TEST - Smithy Card 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int SmithyTEST(struct gameState *post, int handPos);

int main(){
	int player = 0;
	struct gameState postGameState;
	int i, j, k, l, m, n, handPos;
	
	for (i = 0; i < sizeof(struct gameState); i++) { 
		((char*)&postGameState)[i] = floor(Random() * 256);
	}
	
	SelectStream(2);
	PutSeed(3);
	printf ("START - Running callSmithyCard().\n\n");
	
	postGameState.whoseTurn = player;
	for(k = 0; k < 500; k++){
		postGameState.handCount[player] = floor(Random() * MAX_HAND)+1;
		postGameState.deckCount[player] = floor(Random() * MAX_DECK);
		postGameState.discardCount[player] = floor(Random() * MAX_DECK);
		postGameState.playedCardCount = floor(Random() * MAX_DECK);
		
		for(l = 0; l < postGameState.handCount[player]; l++){
			postGameState.hand[player][l] = floor(Random() * treasure_map) + 1;
		}
		
		for(j = 0; j < postGameState.discardCount[player]; j++){
			postGameState.discard[player][j] = floor(Random() * treasure_map) + 1;
		}

		for(m = 0; m < postGameState.deckCount[player]; m++)	{
			postGameState.deck[player][m] = floor(Random() * treasure_map) + 1;
		}
		for(n = 0; n < postGameState.playedCardCount; n++){
			postGameState.playedCards[n] = floor(Random() * treasure_map) + 1;
		}
		
		handPos = floor(Random() * postGameState.handCount[player]);
		postGameState.hand[player][handPos] = smithy;
		
		SmithyTEST(&postGameState, handPos);
	}
	
	printf ("STOP - Running callSmithyCard().\n\n");
	return 0;
}

int SmithyTEST(struct gameState *post, int handPos){
	int player = post->whoseTurn;
	struct gameState preGameState;
	memcpy(&preGameState, post, sizeof(struct gameState));
	
	callSmithyCard(post, player, handPos);
	
	preGameState.handCount[player] = preGameState.handCount[player] + 2;
	preGameState.playedCardCount++;
	
	if(preGameState.deckCount[player] < 3){
		preGameState.deckCount[player] = preGameState.deckCount[player] + preGameState.discardCount[player] - 3;
	}
	else{
		preGameState.deckCount[player] = preGameState.deckCount[player] - 3;
	}
	
	if(post->handCount[player] != preGameState.handCount[player]){
		printf("ERROR! handCount is incorrect.\n");
	}
	if(post->deckCount[player] != preGameState.deckCount[player]){
		printf("ERROR! deckCount is incorrect.\n");
	}
	if(post->playedCardCount != preGameState.playedCardCount){
		printf("ERROR! playedCardCount is incorrect.\n");
	}
	
	return 0;
}