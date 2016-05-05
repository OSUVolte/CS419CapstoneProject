/*
Name: Lauren Miller
Class: CS362
Assighnment: Assignment 3
Date: 4/22/2016
*/

#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>

//testing drawCard()
int main() {
	int seed = 1;//the seed for initializeGame
    int numPlayer;
	int players, j, returnVal;
	int cardCount = 10;//the number of cards initially given to a player
	
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState game;

	printf ("Testing drawCard()\n\n");
	
	for(numPlayer = 2; numPlayer <= 4; numPlayer++) {//checking for all possible number of players (2-4)
		initializeGame(numPlayer, cards, seed, &game);
		for (players = 0; players < numPlayer; players++)//testing each player
		{  
			for (j = 0; j < cardCount; j++){//drawing all the cards from the deck
				returnVal = drawCard(players, &game);
				
				if(game.handCount[players] != j + 1|| game.deckCount[players] != cardCount - j -1) {//checking that handcount is increased
				printf("ERROR DRAWING FROM A NON-EMPTY DECK: total players: %i, player: %i, expected game.handCount: %i, expected game.deckCount: %i, actual game.handCount: %i, actual game.deckCount: %i\n\n", numPlayer, players, j + 1, cardCount - j -1, game.handCount[players], game.deckCount[players]);
				}
			}
			
			drawCard(players, &game);//drawing one more card than is in the deck 
			if(game.handCount[players] != cardCount) {//checking that no more cards than exist in the deck are added
				printf("ERROR DRAWING FROM AN EMPTY DECK: total players: %i player: %i, expected game.handCount: %i, expected game.deckCount = 0, actual game.handCount: %i, actual game.deckCount: %i\n", numPlayer, players, cardCount, game.handCount[players], game.deckCount[players]);
			}
		}
	}
	return 0;
}