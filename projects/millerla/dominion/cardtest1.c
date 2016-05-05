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

//testing Smithy
int main() {
	int seed = 1;//the seed for initializeGame
    int numPlayer;
	int returnVal, players, handCountBefore;
	int cardCount = 10;//the number of cards initially given to a player
	
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState game;
	
	printf ("Testing Smithy:\n\n");
	
	for(numPlayer = 2; numPlayer <= 4; numPlayer++) {//checking for all possible number of players (2-4) {
		
		initializeGame(numPlayer, cards, seed, &game);
		
		for (players = 0; players < numPlayer; players++)//testing each player
		{
			game.hand[players][game.handCount[players]] = smithy;
			game.handCount[players] = 1 + game.handCount[players];
			handCountBefore = game.handCount[players];
			game.whoseTurn = players;
			
			returnVal = playCard(game.handCount[players] - 1, -1, -1, -1, &game);//playing the smithy
			game.numActions++;//counteract playCard
			
			if(game.handCount[players] != handCountBefore + 2) {//confirming that there is a net gain of 2
				printf("ERROR IN CARDS RETURNED: player: %i, expected game.handCount: %i, actual game.handCount: %i\n\n", players, handCountBefore + 2, game.handCount[players]);
			}
			
			if(returnVal != 0) {
				printf("ERROR IN RETURN VALUE: expected return value: 0, actual return value: %i\n\n", returnVal);
			}
		}
	}
	
	
	
	
	return 0;
}

