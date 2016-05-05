/*
Name: Lauren Miller
Class: CS362
Assighnment: Assignment 3
Date: 4/23/2016
*/

#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>

//testing fullDeckCount()
int main() {
	int seed = 1;//the seed for initializeGame
    int numPlayer;
	int players, handCount, i, j;
	int cardCount = 10;//the number of cards initially given to a player
	int copperCount = 7;//the number of copper cards initially given to a player
	int decksCount;
	
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState game;

	printf ("Testing fullDeckCount():\n\n");
	
	for(numPlayer = 2; numPlayer <= 4; numPlayer++) {//checking for all possible number of players (2-4) {
		initializeGame(numPlayer, cards, seed, &game); // initialize a new game
		for (players = 0; players < numPlayer; players++)//drawing all cards for each player
		{   
			for (i = 0; i < cardCount; i++){//drawing entire deck
			
				drawCard(players, &game);//drawing a card
				
				decksCount = fullDeckCount(players, copper, &game);//counting the number of coppers total
				if(decksCount != copperCount) {//confirming that the total number of cards counted is copperCount
					printf("ERROR IN CARDS COUNTED: player: %i, expected copper count: %i, actual count: %i\n\n", players, copperCount, decksCount);
				}
				
				decksCount = fullDeckCount(players, adventurer, &game);//counting the number of adventurer cards - which are in game but not drawn - total
				if(decksCount != 0) {//confirming that the total number of cards counted is 0
					printf("ERROR IN CARDS COUNTED: player: %i, expected adventurer, (which is available in this game), count: 0, actual count: %i\n\n", players, decksCount);
				}
				
				decksCount = fullDeckCount(players, embargo, &game);//counting the number of adventurer cards - which are in game but not drawn - total
				if(decksCount != 0) {//confirming that the total number of cards counted is 0
					printf("ERROR IN CARDS COUNTED: player: %i, expected embargo, (which is not available in this game), count: 0, actual count: %i\n\n", players, decksCount);
				}
			}
		}
	}
	return 0;
}