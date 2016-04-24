//Assignment #3 - Joseph Cuellar
//CS - 362
//Test to see if the player is able to buy a card 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int BuyCardTEST(int currentPlayer, int currentCard, struct gameState *postGameState, int testState);

int main(){
	int currentPlayer = 0;
	int testState, currentCard;
	struct gameState postGameState;
	
	SelectStream(2);
	PutSeed(3);
	printf ("START - Running buyCard() unittest4.\n\n");
	
	int i;
	for (i = 0; i < sizeof(struct gameState); i++) { 
		((char*)&postGameState)[i] = floor(Random() * 256);
	}
	
	int j;
	for(j = 0; j <= treasure_map; j++){
		postGameState.supplyCount[j] = 5;
	}

	postGameState.numPlayers 					= 2;
	postGameState.whoseTurn 					= currentPlayer;
	postGameState.deck[currentPlayer][0] 		= gold; 
	postGameState.deckCount[currentPlayer] 		= 1;
	postGameState.hand[currentPlayer][0] 		= silver; 
	postGameState.handCount[currentPlayer] 		= 1;
	postGameState.discard[currentPlayer][0] 	= copper; 
	postGameState.discardCount[currentPlayer] 	= 1;
	postGameState.coins = 5000;
	postGameState.numBuys = 0;

	testState = 1;
	BuyCardTEST(currentPlayer, gold, &postGameState, testState);
	
	int k;
	for(k = 0; k < 100; k++){
		currentCard = floor(Random() * treasure_map) + 1;
		postGameState.numBuys = 1000;
		postGameState.supplyCount[currentCard] = 0;
		testState = 2;
		BuyCardTEST(currentPlayer, currentCard, &postGameState, testState);
	}
	
	for(j = 0; j <= treasure_map; j++){
		postGameState.supplyCount[j] = 100;
	}
	
	postGameState.coins = 0;
	testState = 3;
	BuyCardTEST(currentPlayer, province, &postGameState, testState);

	for(k = 0; k < 100; k++){
		currentCard = floor(Random() * sea_hag) + 1;
		postGameState.coins = 50;
		testState = 0;
		BuyCardTEST(currentPlayer, currentCard, &postGameState, testState);
	}
	printf ("STOP - Running buyCard() unittest4.\n\n");
	return 0;
}

int BuyCardTEST(int currentPlayer, int currentCard, struct gameState *postGameState, int testState){
	struct gameState preGameState;
	memcpy(&preGameState, postGameState, sizeof(struct gameState));
	
	int functionOutput = buyCard(currentCard, postGameState);
	
	preGameState.handCount[currentPlayer]++;
	preGameState.coins = preGameState.coins - getCost(currentCard);
	preGameState.numBuys--;
	preGameState.supplyCount[currentCard]--;
	
	if(testState == 1) {
		if(functionOutput != -1)	{
			printf("ERROR! numBuys should be 0.\n");
		}
	}
	else if(testState == 2){
		if(functionOutput != -1)	{
			printf("ERROR! supplyCount should be 0.\n");
		}
	}
	else if(testState == 3){
		if(functionOutput != -1){
			printf("ERROR! coins should be less than cost.\n");
		}
	}
	else if(functionOutput != 0 ){
		printf("ERROR! buyCard QUIT.\n");
	}
	else{
		if(postGameState->handCount[currentPlayer] != preGameState.handCount[currentPlayer]){
			printf("ERROR! The hand count did not increase with buy.\n");
		}
		if(postGameState->coins != preGameState.coins){
			printf("ERROR! Coins did not decrease with the cost of the card.\n");
		}
		if(postGameState->numBuys != preGameState.numBuys){
			printf("ERROR! numBuys did not decrease.\n");
		}
		if(postGameState->supplyCount[currentCard] != preGameState.supplyCount[currentCard]){
			printf("ERROR! supply count did not decrease.\n");
		}
	}
	return 0;
}