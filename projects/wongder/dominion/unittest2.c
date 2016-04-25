#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
	int player1 = 0;
	int player2 = 1;
	int gameOver;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, RESET;
	
	initializeGame(numPlayer, k, seed, &RESET);
	memcpy(&G, &RESET, sizeof(struct gameState));	
	
	//Test isGameOver function
	printf("~~~Testing isGameOver Function~~~\n");
	printf("Game over = 1 | Game continue = 0\n\n");
	
	printf("--------------------------------------------\n");
	printf("Test if stack of province card is empty\n\n");
	G.supplyCount[province] = 0;
	gameOver = isGameOver(&G);
	printf("Game over state = %d, expected = 1\n", gameOver);
	if (gameOver == 1){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if stack of estates card is empty\n\n");
	G.supplyCount[estate] = 0;
	gameOver = isGameOver(&G);
	printf("Game over state = %d, expected = 0\n", gameOver);
	if (gameOver == 0){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if stack of duchies card is empty\n\n");
	G.supplyCount[duchy] = 0;
	gameOver = isGameOver(&G);
	printf("Game over state = %d, expected = 0\n", gameOver);
	if (gameOver == 0){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if one supply pile are at 0\n\n");
	G.supplyCount[0] = 0;
    gameOver = isGameOver(&G);
    printf("Game over state = %d, expected = 0\n", gameOver);
    if (gameOver == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if two supply pile are at 0\n\n");
	G.supplyCount[0] = 0;
	G.supplyCount[1] = 0;
    gameOver = isGameOver(&G);
    printf("Game over state = %d, expected = 0\n", gameOver);
    if (gameOver == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }	
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if three supply pile are at 0\n\n");
	G.supplyCount[0] = 0;
	G.supplyCount[1] = 0;
	G.supplyCount[2] = 0;
    gameOver = isGameOver(&G);
    printf("Game over state = %d, expected = 1\n", gameOver);
    if (gameOver == 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state	

	printf("Test if player 1 discard pile is empty\n\n");
	G.discardCount[player1] = 0;
	gameOver = isGameOver(&G);
	printf("Game over state = %d, expected = 0\n", gameOver);
    if (gameOver == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state	
		
	printf("Test if player 1 hand is empty\n\n");
	G.handCount[player1] = 0;
	gameOver = isGameOver(&G);
	printf("Game over state = %d, expected = 0\n", gameOver);
    if (gameOver == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state	
		
	printf("Test if player 1 deck is empty\n\n");
	G.deckCount[player1] = 0;
	gameOver = isGameOver(&G);
	printf("Game over state = %d, expected = 0\n", gameOver);
    if (gameOver == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state	
		
	printf("Test if player 1 has cards\n\n");
	G.handCount[player1] = 5;
	gameOver = isGameOver(&G);
	printf("Game over state = %d, expected = 0\n", gameOver);
    if (gameOver == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }
	printf("--------------------------------------------\n");
	
	printf("Test if player 2 discard pile is empty\n\n");
	G.discardCount[player2] = 0;
	gameOver = isGameOver(&G);
	printf("Game over state = %d, expected = 0\n", gameOver);
    if (gameOver == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state	
		
	printf("Test if player 2 hand is empty\n\n");
	G.handCount[player2] = 0;
	gameOver = isGameOver(&G);
	printf("Game over state = %d, expected = 0\n", gameOver);
    if (gameOver == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state	
		
	printf("Test if player 2 deck is empty\n\n");
	G.deckCount[player2] = 0;
	gameOver = isGameOver(&G);
	printf("Game over state = %d, expected = 0\n", gameOver);
    if (gameOver == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state	
		
	printf("Test if player 2 has cards\n\n");
	G.handCount[player2] = 7;
	gameOver = isGameOver(&G);
	printf("Game over state = %d, expected = 0\n", gameOver);
    if (gameOver == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }
	printf("--------------------------------------------\n");
	
	
	return 0;
	
}
