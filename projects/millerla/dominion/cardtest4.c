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

//testing Village
int main() {
	
	int seed = 1;//the seed for initializeGame
    int numPlayer;
	int returnVal, players, prevActionCount, handCountBefore;
	int cardCount = 10;//the number of cards initially given to a player
	
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState game;
	
	printf ("Testing Vilage:\n\n");
	
	for(numPlayer = 2; numPlayer <= 4; numPlayer++) {//checking for all possible number of players (2-4)
		
		initializeGame(numPlayer, cards, seed, &game);
		
		for (players = 0; players < numPlayer; players++)//testing each player
		{
			game.hand[players][game.handCount[players]] = village;
			game.handCount[players] = 1 + game.handCount[players];
			handCountBefore = game.handCount[players];
			prevActionCount = game.numActions;//getting the numActions before village played
			
			game.whoseTurn = players;
			
			returnVal = playCard(game.handCount[players] - 1, -1, -1, -1, &game);//playing the village
			
			if(game.numActions != prevActionCount + 1) {//checking that the net game.numActions is 1
				printf("ERROR IN NUMBER OF ACTIONS ADDED: player: %i, expected game.numActions: %i, actual game.numActions: %i\n\n", players, prevActionCount + 1, game.numActions);
			}
			
			if(game.handCount[players] != handCountBefore) {//checking that net cards added to hand is 0
				printf("ERROR IN NUMBER OF CARDS ADDED TO HAND: player: %i, expected game.numActions: %i, actual game.numActions: %i\n\n", players, handCountBefore, game.handCount[players]);

			}
			
			if(returnVal != 0) {//confirming correct return value
				printf("ERROR IN RETURN VALUE: expected return value: 0, actual return value: %i\n\n", returnVal);
			}
			
			game.numActions = 1;//resetting actions
		}
		
	}

	return 0;
}

