//updateCoins function
//unittest3.c
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define FUNCTION "updateCoins"

int main() {
	int i,j;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	int bonus = 0;
	int copper = 0;
	int newCopper = 0; 
	int silver = 0;
	int newSilver = 0; 
	int gold = 0;
	int newGold = 0;
	//set up cards
	int k[10] = {curse, estate, village, remodel, 
		council_room, adventurer, province, smithy, steward, tribute};
	//set structs for game states
	struct gameState G, testG;

	//initialize game, state and player cards
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("\n\n\n\n----------------- Testing Function: %s ----------------\n", FUNCTION);	
	for (i=0; i < numPlayers; i++){
		//revert to starting game state
		memcpy(&G, &testG, sizeof(struct gameState));
		//set player to i
		thisPlayer = i;
		printf("\n---------------------Counting Coins---------------------\n");
		printf("Player %d\n Coins: %d",  testG.coins);
		for (j = 0; j < testG.handCount[thisPlayer]; j++){
			if (testG.hand[thisPlayer][i] == copper){
				copper++;
			}
			if (testG.hand[thisPlayer][i] == silver){
				silver++;
			}
			if (testG.hand[thisPlayer][i] == silver){
				gold++;
			}
		}
		printf("Copper: %d Silver: %d Gold: %d ", copper, silver, gold);
		printf("Bonus Added : %d\n", bonus);
		//run function
		updateCoins(thisPlayer, &testG, bonus);
		printf("\n-----------------Counting Coins After Update---------------------\n");
		printf("Player %d\n Coins: %d",  testG.coins);
		//count changes
		for (j = 0; j < testG.handCount[thisPlayer]; j++){
			if (testG.hand[thisPlayer][i] == copper){
				newCopper++;
			}
			if (testG.hand[thisPlayer][i] == silver){
				newSilver++;
			}
			if (testG.hand[thisPlayer][i] == silver){
				newGold++;
			}
		}
		printf("Copper: %d Silver: %d Gold: %d ", newCopper, newSilver, newGold);
		//assert(testG.deckCount[thisPlayer] == testG.deckCount[thisPlayer]);
		//assert(testG.coins == testG.coins);
		//assert(testG.playedCardCount == testG.playedCardCount);
		//assert(testG.numPlayers == testG.numPlayers);
	}
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n\n\n", FUNCTION);
	return 0;
}
