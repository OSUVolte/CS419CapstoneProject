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
	
	//Test stewardCard function
	printf("~~~Testing stewardCard Function~~~\n");

	printf("--------------------------------------------\n");
	cardEffect(steward, 1, c2, c3, &G, handPos, &bonus);
	printf("Test if player 1 hand count increase by 1 (+2 cards -1 played card) (choice1 = 1)\n");
//	printf("Before G.handCount = %d\n",G.handCount[player1]);
//	cardEffect(steward, 1, c2, c3, &G, handPos, &bonus);
	printf("After G.handCount = %d, expected = 6\n", G.handCount[player1]);
	if (G.handCount[player1] == 6){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 deck count decrease by 2 (choice1 = 1)\n");
	printf("After G.deckCount = %d, expected = 3\n", G.deckCount[player1]);
	if (G.deckCount[player1] == 3){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 coins stay the same (choice1 = 1)\n");
	printf("After G.coins = %d, expected = 4\n", G.coins);
	if (G.coins == 4){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if played pile increase by 1 (choice1 = 1)\n");
	printf("After G.playedCardCount = %d, expected = 1\n", G.playedCardCount);
	if (G.playedCardCount == 1){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 discard pile stayed the same (choice1 = 1)\n");
	printf("After G.discardCount[player1] = %d, expected = 0\n", G.discardCount[player1]);
	if (G.discardCount[player1]	== 0){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 numActions stayed the same (choice1 = 1)\n");
	printf("After G.numActions = %d, expected = 1\n", G.numActions);
	if (G.numActions == 1){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 numBuys stayed the same (choice1 = 1)\n");
	printf("After G.numBuys = %d, expected = 1\n", G.numBuys);
	if (G.numBuys == 1){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state

	cardEffect(steward, 2, c2, c3, &G, handPos, &bonus);
	printf("Test if player 1 hand count stayed the same (choice1 = 2)\n");
	printf("After G.handCount = %d, expected = 5\n", G.handCount[player1]);
	if (G.handCount[player1] == 5){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 deck count stayed the same (choice1 = 2)\n");
	printf("After G.deckCount = %d, expected = 5\n", G.deckCount[player1]);
	if (G.deckCount[player1] == 5){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 coins increase by 2 (choice1 = 2)\n");
	printf("After G.coins = %d, expected = 6\n", G.coins);
	if (G.coins == 6){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if played pile increase by 1 (choice1 = 2)\n");
	printf("After G.playedCardCount = %d, expected = 1\n", G.playedCardCount);
	if (G.playedCardCount == 1){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 discard pile stayed the same (choice1 = 2)\n");
	printf("After G.discardCount[player1] = %d, expected = 0\n", G.discardCount[player1]);
	if (G.discardCount[player1]	== 0){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 numActions stayed the same (choice1 = 2)\n");
	printf("After G.numActions = %d, expected = 1\n", G.numActions);
	if (G.numActions == 1){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 numBuys stayed the same (choice1 = 2)\n");
	printf("After G.numBuys = %d, expected = 1\n", G.numBuys);
	if (G.numBuys == 1){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state
	
	cardEffect(steward, 3, 0, 1, &G, handPos, &bonus);
	printf("Test if player 1 hand count decrease by 3 (-2 cards -1 played card) (choice1 = 3 choice2 = 0 choice = 1)\n");
	printf("After G.handCount = %d, expected = 2\n", G.handCount[player1]);
	if (G.handCount[player1] == 2){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 deck count stayed the same (choice1 = 3 choice2 = 0 choice = 1)\n");
	printf("After G.deckCount = %d, expected = 5\n", G.deckCount[player1]);
	if (G.deckCount[player1] == 5){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 coins stayed the same (choice1 = 3 choice2 = 0 choice = 1)\n");
	printf("After G.coins = %d, expected = 4\n", G.coins);
	if (G.coins == 4){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if played pile increase by 1 (choice1 = 3 choice2 = 0 choice = 1)\n");
	printf("After G.playedCardCount = %d, expected = 1\n", G.playedCardCount);
	if (G.playedCardCount == 1){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 discard pile stayed the same (choice1 = 3 choice2 = 0 choice = 1)\n");
	printf("After G.discardCount[player1] = %d, expected = 0\n", G.discardCount[player1]);
	if (G.discardCount[player1]	== 0){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 numActions stayed the same (choice1 = 3 choice2 = 0 choice = 1)\n");
	printf("After G.numActions = %d, expected = 1\n", G.numActions);
	if (G.numActions == 1){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("\nTest if player 1 numBuys stayed the same (choice1 = 3 choice2 = 0 choice = 1)\n");
	printf("After G.numBuys = %d, expected = 1\n", G.numBuys);
	if (G.numBuys == 1){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("--------------------------------------------\n");
	
	memcpy(&G, &RESET, sizeof(struct gameState)); // reset game state

	return 0;
}