/********************************
Author: Luke Brewbaker
Date: 4/18/16
Modified:4/22/16
File: unittest2.c

Overview: Testing buyCard() function.  


*******************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
int main()
{
	int errors, found = 0;
	
	struct gameState game;
	
	game.deckCount[0] = 5;
	game.deck[0][0] = copper;
	game.deck[0][1] = copper;
	game.deck[0][2] = copper;
	game.deck[0][3] = copper;
	game.deck[0][4] = copper;
	game.deck[0][5] = copper;
	game.deck[0][6] = copper;
	game.deck[0][7] = estate;
	game.deck[0][8] = estate;
	game.deck[0][9] = estate;
	buyCard(mine, &game);
	
	printf("\n\n ---Testing buyCard() Start--- \n\n");
	
	if (game.deckCount[0] > 11){
		printf("FAIL: Player has received too many cards.\n");
		errors++;
	}
	
	for (int i = 0; i < game.deckCount[0]; i++){
		if (game.deck[0][i] == mine){
			found = 1;
			printf("PASS: Player recieved the correct number of cards.");
			break;
		}
	}
	
	if (!found){
		printf("FAIL: Card was not added to deck.\n");
		errors++;
	}

	if (errors > 0)
		printf("There were %d errors.\n", errors);
	else
		printf("Test was successful.\n");
	
	printf("\n\n ---buyCard() Test End --- \n\n");
	return 0;
}