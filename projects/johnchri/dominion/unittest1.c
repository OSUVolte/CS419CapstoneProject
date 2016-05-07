#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int checkInitializeGameState(struct gameState *G, int k[10]){

	int i;

	for (i = 0; i < 2; i++){
		printf("Checking game with %d players...\n", i);
		if (initializeGame(i, k, 9, G) == -1){
			printf("SUCCESS! %d players not allowed.\n", i);

		}else{
			printf("FAIL! %d players not allowed.\n", i);
		}
	}

	for (i = 5; i < 7; i++){
		printf("Checking game with %d players...\n", i);
		if (initializeGame(i, k, 9, G) == -1){
			printf("SUCCESS! %d players not allowed.\n", i);

		}else{
			printf("FAIL! %d players not allowed.\n", i);
		}
	}

	initializeGame(2, k, 9, G);
	if (G->supplyCount[curse] == 10){
		printf("SUCCESS! 10 curse cards for 2 players.\n");
	}else{
		printf("FAIL! 10 curse cards for 2 players.\n");
	}
	initializeGame(3, k, 9, G);
	if (G->supplyCount[curse] == 20){
		printf("SUCCESS! 20 curse cards for 3 players.\n");
	}else{
		printf("FAIL! 20 curse cards for 3 players.\n");
	}
	initializeGame(4, k, 9, G);
	if (G->supplyCount[curse] == 30){
		printf("SUCCESS! 30 curse cards for 4 players.\n");
	}else{
		printf("FAIL! 30 curse cards for 4 players.\n");
	}

	initializeGame(2, k, 9, G);
	if (G->supplyCount[estate] == 8 &&
		G->supplyCount[duchy] == 8 &&
		G->supplyCount[province] == 8){

		printf("SUCCESS! 8 of each victory card for 2 players.\n");
	}else{
		printf("FAIL! Incorrect number of victory cards for 2 players.\n");
	}
	initializeGame(4, k, 9, G);
	if (G->supplyCount[estate] == 12 &&
		G->supplyCount[duchy] == 12 &&
		G->supplyCount[province] == 12){

		printf("SUCCESS! 12 of each victory card for 4 players.\n");
	}else{
		printf("FAIL! Incorrect number of victory cards for 4 players.\n");
	}

	initializeGame(2, k, 9, G);
	if (G->supplyCount[copper] == 46){
		printf("SUCCESS! 46 copper cards for 2 players.\n");
	}else{
		printf("FAIL! Incorrect number of copper cards for 2 players.\n");
	}
	initializeGame(4, k, 9, G);
	if (G->supplyCount[copper] == 32){
		printf("SUCCESS! 25 copper cards for 4 players.\n");
	}else{
		printf("FAIL! Incorrect number of copper cards for 2 players.\n");
	}

	initializeGame(2, k, 9, G);
	if (G->supplyCount[adventurer] == 10){
		printf("SUCCESS! 10 adventurer cards for 2 players.\n");
	}else{
		printf("FAIL! Incorrect number of adventurer cards for 2 players.\n");
	}
	initializeGame(4, k, 9, G);
	if (G->supplyCount[great_hall] == 12){
		printf("SUCCESS! 12 great hall cards for 4 players.\n");
	}else{
		printf("FAIL! Incorrect number of great hall cards for 4 players.\n");
	}

	initializeGame(2, k, 9, G);
	if(G->deckCount[0] == 5){
		printf("SUCCESS! Correct starting deck size.\n");
	}else{
		printf("FAIL! Deck size error.\n");
	}
	if(G->deck[0][9] == copper){
		printf("SUCCESS! Last card in deck is copper.\n");
	}else{
		printf("FAIL! Last card in deck.\n");
	}

	return 0;

}

int main(int argc, char* argv[]) {

	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

	checkInitializeGameState(&G, k);

	return 0;
}