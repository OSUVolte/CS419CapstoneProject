#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
    int i;
    int numPlayer = 2;
	int player1 = 0;
	int player2 = 1;
    struct gameState G;

	//Test Shuffle function
	printf("~~~Testing Shuffle Function~~~\n\n");
	
	//set player1 and player2 hand/deck/discard pile
	for (i = 0; i < numPlayer; i++){
		G.hand[i][0] = feast;			// add 3 card to player1 hand
		G.hand[i][1] = gardens;
		G.hand[i][2] = smithy; 

		G.deck[i][0] = remodel;		// add 4 card to player1 deck
		G.deck[i][1] = gardens;
		G.deck[i][2] = baron;
		G.deck[i][3] = village;
		
		G.discard[i][0] = council_room;		// add 3 card to player1 discard
		G.discard[i][1] = village;
		G.discard[i][2] = feast;
	}
	
	printf("Shuffled Player 1 Deck.............\n");
	printf("The numbers are the enum Card\n\n");
	
	
	
	printf("--------------------------------------------\n");
	printf("Test if player 1 deck pile is in different order:\n\n");
	G.deckCount[player1] = 4;
	shuffle(player1, &G);
	
	printf("G.deck[player] = %d, %d, %d, %d | expected != %d, %d, %d, %d\n", G.deck[player1][0], G.deck[player1][1], G.deck[player1][2], 
		G.deck[player1][3], remodel, gardens, baron, village);

	if (G.deck[player1][0] == remodel && G.deck[player1][1] == gardens && G.deck[player1][2] == baron && G.deck[player1][3] == village){
		printf("FAILED.\n");
	}
	else{
		printf("PASSED.\n");
	}
	printf("--------------------------------------------\n");
	printf("Test if player 1 hand is still the same:\n\n");
	
	printf("G.hand[player1][0] = %d, expected = %d\n", G.hand[player1][0], feast);
	printf("G.hand[player1][1] = %d, expected = %d\n", G.hand[player1][1], gardens);
	printf("G.hand[player1][2] = %d, expected = %d\n", G.hand[player1][2], smithy);
	if (G.hand[player1][0] == feast && G.hand[player1][1] == gardens && G.hand[player1][2] == smithy){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	printf("Test if player 1 discard pile is still the same:\n\n");
	
	printf("G.discard[player1][0] = %d, expected = %d\n", G.discard[player1][0], council_room);
	printf("G.discard[player1][1] = %d, expected = %d\n", G.discard[player1][1], village);
	printf("G.discard[player1][2] = %d, expected = %d\n", G.discard[player1][2], feast);
	if (G.discard[player1][0] == council_room && G.discard[player1][1] == village && G.discard[player1][2] == feast){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	printf("Test if player 1 deckCount is still the same:\n\n");
	
	printf("G.deckcount[player1] = %d, expected = 4\n", G.deckCount[player1]);
	if (G.deckCount[player1] == 4){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("--------------------------------------------\n");
	printf("Test if player 2's deck got shuffled:\n\n");
	G.deckCount[player2] = 4;
	
	printf("G.deck[player] = %d, %d, %d, %d | expected = %d, %d, %d, %d\n", G.deck[player2][0], G.deck[player2][1], G.deck[player2][2], 
		G.deck[player2][3], remodel, gardens, baron, village);

	if (G.deck[player2][0] == remodel && G.deck[player2][1] == gardens && G.deck[player2][2] == baron && G.deck[player2][3] == village){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	printf("Test if player 2 hand is still the same:\n\n");
	
	printf("G.hand[player2][0] = %d, expected = %d\n", G.hand[player2][0], feast);
	printf("G.hand[player2][1] = %d, expected = %d\n", G.hand[player2][1], gardens);
	printf("G.hand[player2][2] = %d, expected = %d\n", G.hand[player2][2], smithy);
	if (G.hand[player2][0] == feast && G.hand[player2][1] == gardens && G.hand[player2][2] == smithy){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	printf("--------------------------------------------\n");
	printf("Test if player 2 discard pile is still the same:\n\n");
	
	printf("G.discard[player2][0] = %d, expected = %d\n", G.discard[player2][0], council_room);
	printf("G.discard[player2][1] = %d, expected = %d\n", G.discard[player2][1], village);
	printf("G.discard[player2][2] = %d, expected = %d\n", G.discard[player2][2], feast);
	if (G.discard[player2][0] == council_room && G.discard[player2][1] == village && G.discard[player2][2] == feast){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}
	
	printf("--------------------------------------------\n");
	printf("Test if player 2 deckCount is still the same:\n\n");
	
	printf("G.deckcount[player2] = %d, expected = 4\n", G.deckCount[player2]);
	if (G.deckCount[player2] == 4){
		printf("PASSED.\n");
	}
	else{
		printf("FAILED.\n");
	}


    return 0;
}
