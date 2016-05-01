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
	
	//Test discardCard function
	printf("~~~Testing discardCard Function~~~\n");
	
	printf("--------------------------------------------\n");
	printf("Test if player 1 hand count decrease by 1\n\n");
	printf("Before G.handCount = %d\n",G.handCount[player1]);
	discardCard(0, player1, &G, 0);
	printf("After G.handCount = %d, expected = 4\n", G.handCount[player1]);
	if (G.handCount[player1] == 4){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if played pile increase by 1 (trashFlag = 0)\n\n");
	printf("Before G.playedCardCount = %d\n",G.playedCardCount);
	discardCard(0, player1, &G, 0);
	printf("After G.playedCardCount = %d, expected = 1\n", G.playedCardCount);
	if (G.playedCardCount == 1){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if discarded Card is at the top of played pile (trashFlag = 0)\n\n");
	discardCard(0, player1, &G, 0);
	printf("discardCard = %d, expected = %d\n", G.playedCards[0], G.hand[player1][0]);
	if (G.playedCards[0] == G.hand[player1][0]){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 1 deck is still the same\n\n");
	blah = G.deckCount[player1];
	discardCard(0, player1, &G, 0);
	printf("G.deckCount = %d, expected = %d\n", G.deckCount[player1], blah);
	if (G.deckCount[player1] == blah){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 1 still has the card \n\n");
	printf("Hand before discard:\n");
	blah = G.handCount[player1];
	i = 0;
	while (G.hand[player1][i] != NULL){
		printf("%d, ", G.hand[player1][i]);
		i++;
	}
	i = 0;
	discardCard(0, player1, &G, 0);
	printf("\nHand after discard:\n");
	while (G.hand[player1][i] != NULL && G.hand[player1][i] != -1){
		printf("%d, ", G.hand[player1][i]);
		i++;
	}
	if (G.handCount[player1] != blah){
		printf("\nPASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 2 discard pile stayed the same\n\n");
	blah = G.discardCount[player2];
	discardCard(0, player1, &G, 0);
	printf("G.discardCount = %d, expected = %d\n", G.discardCount[player2], blah);
	if (G.discardCount[player2] == blah){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	printf("Test if player 1 deck is still the same\n\n");
	blah = G.deckCount[player1];
	discardCard(0, player1, &G, 0);
	printf("G.deckCount = %d, expected = %d\n", G.deckCount[player1], blah);
	if (G.deckCount[player1] == blah){
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
	
	return 0;
}