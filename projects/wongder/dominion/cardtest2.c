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
	int handPos = 0;
	int gameOver;
	int tempCard;
	int bonus;
	int c1, c2, c3 = 0;
	int blah;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, RESET;
	
	initializeGame(numPlayer, k, seed, &RESET);
	RESET.hand[player1][handPos] = smithy;
	memcpy(&G, &RESET, sizeof(struct gameState));	
	
	//Test council_room function
	printf("~~~Testing council_room Function~~~\n");
	
	printf("--------------------------------------------\n");
	printf("Test if player 1 deck count decrease by 4\n\n");
	printf("Before G.deckCount = %d\n",G.deckCount[player1]);
	cardEffect(council_room, c1, c2, c3, &G, handPos, &bonus);
	printf("After G.deckCount = %d, expected = 1\n", G.deckCount[player1]);
	if (G.deckCount[player1] == 1){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 1 hand count increase by 3 (+4 cards -1 played card)\n\n");
	printf("Before G.handCount = %d\n",G.handCount[player1]);
	cardEffect(council_room, c1, c2, c3, &G, handPos, &bonus);
	printf("After G.handCount = %d, expected = 8\n", G.handCount[player1]);
	if (G.handCount[player1] == 8){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 1 numBuy increase by 1\n\n");
	printf("Before G.numBuys = %d\n",G.numBuys);
	cardEffect(council_room, c1, c2, c3, &G, handPos, &bonus);
	printf("After G.numBuys = %d, expected = 2\n", G.numBuys);
	if (G.numBuys == 2){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 1 played pile increase by 1\n\n");
	printf("Before G.playedCardCount = %d\n",G.playedCardCount);
	cardEffect(council_room, c1, c2, c3, &G, handPos, &bonus);
	printf("After G.playedCardCount = %d, expected = 1\n", G.playedCardCount);
	if (G.playedCardCount == 1){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state

	printf("Test if player 1 discard pile stayed the same\n\n");
	printf("Before G.discardCount = %d\n",G.discardCount[player1]);
	cardEffect(council_room, c1, c2, c3, &G, handPos, &bonus);
	printf("After G.discardCount = %d, expected = 0\n", G.discardCount[player1]);
	if (G.discardCount[player1] == 0){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 2 discard pile stayed the same\n\n");
	printf("Before G.discardCount = %d\n",G.discardCount[player2]);
	cardEffect(council_room, c1, c2, c3, &G, handPos, &bonus);
	printf("After G.discardCount = %d, expected = 0\n", G.discardCount[player2]);
	if (G.discardCount[player2] == 0){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 2 hand count increase by 1\n\n");
	printf("Before G.handCount = %d\n",G.handCount[player2]);
	cardEffect(council_room, c1, c2, c3, &G, handPos, &bonus);
	printf("After G.handCount = %d, expected = 1\n", G.handCount[player2]);
	if (G.handCount[player2] == 1){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 2 deck count decrease by 1\n\n");
	printf("Before G.deckCount = %d\n",G.deckCount[player2]);
	cardEffect(council_room, c1, c2, c3, &G, handPos, &bonus);
	printf("After G.deckCount = %d, expected = 9\n", G.deckCount[player2]);
	if (G.deckCount[player2] == 9 ){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
		for (i = 0; i < sizeof(G.supplyCount)/sizeof(int); i++){
		memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
		
		printf("Test if supplyPile[%d] stayed the same\n\n", i);
		printf("Before G.supplyCount[%d] = %d\n", i, G.supplyCount[0]);
		cardEffect(smithy, c1, c2, c3, &G, handPos, &bonus);
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
	
	return 0;
}