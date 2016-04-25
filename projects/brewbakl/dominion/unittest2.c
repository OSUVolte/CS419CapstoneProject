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
	int found = 0;
	
	struct gameState game;
	int kingdomCards[10] = {adventurer, council_room, mine, remodel, village, smithy, ambassador, embargo, sea_hag, mine};
	initializeGame(2, kingdomCards, 2, &game);
	
	printf("\n\n ---Testing buyCard() Start--- \n\n");
	
	//set deck count and make sure there is copper
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
	
	//test buy MINE
	printf("\nAttempting to buy MINE card: \n");
	buyCard(mine, &game);

	//check if card is drawn
	if (game.deckCount[0] > 11){
		printf("FAIL: Player has received too many cards.\n");
	}
	else{
		printf("\nPASS: Player got right amount of cards.\n");
	}
	
	//make sure card is in the hand
	for (int i = 0; i < game.deckCount[0]; i++){
		if (game.deck[0][i] == mine){
			found = 1;
			printf("PASS: Player recieved the Mine card.");
			break;
		}
	}
	
	if (!found){
		printf("FAIL: Mine card not added to deck.\n");
	}
	
	//test buy VILLAGE
	printf("\nAttempting to buy VILLAGE card: \n");
	buyCard(village, &game);
	
	//testing if the card is drawn
	if (game.deckCount[0] > 11){
		printf("FAIL: Player has received too many cards.\n");
	}
	else{
		printf("\nPASS: Player got right amount of cards.\n");
	}
	
	//check if card is in hand.
	for (int i = 0; i < game.deckCount[0]; i++){
		if (game.deck[0][i] == village){
			found = 1;
			printf("PASS: Player recieved the Village card.");
			break;
		}
	}
	
	if (!found){
		printf("FAIL:Village card not added to deck.\n");
	}

	printf("\n\n ---buyCard() Test End --- \n\n");
	return 0;
}