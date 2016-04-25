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
	int tempCard;
	int blah;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, RESET;
	
	initializeGame(numPlayer, k, seed, &RESET);
	memcpy(&G, &RESET, sizeof(struct gameState));	
	
	//Test drawCard function
	printf("~~~Testing drawCard Function~~~\n");
	
	printf("--------------------------------------------\n");
	printf("Test if player 1 hand count increase by 1\n\n");
	printf("Before G.handCount = %d\n",G.handCount[player1]);
	drawCard(player1, &G);
	printf("After G.handCount = %d, expected = 6\n", G.handCount[player1]);
	if (G.handCount[player1] == 6){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");

	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 1 deck decrease by 1\n\n");
	printf("Before G.deckCount = %d\n", G.deckCount[player1]);
	drawCard(player1, &G);
	printf("After G.deckCount = %d, expected = 4\n", G.deckCount[player1]);
	if (G.deckCount[player1] == 4){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 1 discard pile stayed the same\n\n");
	printf("Before G.discardCount = %d\n", G.discardCount[player1]);
	drawCard(player1, &G);
	printf("After G.discardCount = %d, expected = 4\n", G.discardCount[player1]);
	if (G.discardCount[player1] == 0){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 2 hand count stayed the same\n\n");
	printf("Before G.handCount = %d\n", G.handCount[player2]);
	drawCard(player1, &G);
	printf("After G.handCount = %d, expected = 0\n", G.handCount[player2]);
	if (G.handCount[player2] == 0){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state

	printf("Test if player 2 deck stayed the same\n\n");
	printf("Before G.deckCount = %d\n", G.deckCount[player2]);
	drawCard(player1, &G);
	printf("After G.deckCount = %d, expected = 10\n", G.deckCount[player2]);
	if (G.deckCount[player2] == 10){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 2 discard pile stayed the same\n\n");
	printf("Before G.discardCount = %d\n", G.discardCount[player2]);
	drawCard(player1, &G);
	printf("After G.discardCount = %d, expected = 0\n", G.discardCount[player2]);
	if (G.discardCount[player2] == 0){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	for (i = 0; i < sizeof(G.supplyCount)/sizeof(int); i++){
		memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
		
		printf("Test if supplyPile[%d] stayed the same\n\n", i);
		printf("Before G.supplyCount[%d] = %d\n", i, G.supplyCount[0]);
		drawCard(player1, &G);
		printf("After G.supplyCount = %d, expected = 10\n", G.supplyCount[0]);
		if (G.supplyCount[0] == 10){
			printf("PASSED.\n");
		}
		else{
			printf("FAILED.\n");
		}
		printf("--------------------------------------------\n");
	}
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 1 drawn card is in hand\n\n");
	printf("Top Deck Card = %d\n", G.deck[player1][G.deckCount[player1] - 1]);
	drawCard(player1, &G);
	printf("Last Card Drawn = %d, expected = %d\n", G.hand[player1][G.handCount[player1] - 1], G.deck[player1][G.deckCount[player1] - 1]);
	if (G.deckCount[player2] == 10){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	
	return 0;
}