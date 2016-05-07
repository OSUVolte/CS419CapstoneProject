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

//testing Adventurer
int main() {
	int seed = 1;//the seed for initializeGame
    int numPlayer;
	int returnVal, players, handCountBefore;
	int cardCount = 10;//the number of cards initially given to a player
	
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState game;
	
	printf ("Testing Adventurer:\n\n");
	
	for(numPlayer = 2; numPlayer <= 4; numPlayer++) {//checking for all possible number of players (2-4) {
		
		initializeGame(numPlayer, cards, seed, &game);
		
		for (players = 0; players < numPlayer; players++)//testing each player
		{
			game.hand[players][game.handCount[players]] = adventurer;
			game.handCount[players] = 1 + game.handCount[players];
			handCountBefore = game.handCount[players];
			game.whoseTurn = players;
			
			returnVal = playCard(game.handCount[players] - 1, -1, -1, -1, &game);//playing the smithy
			game.numActions++;//counteract playCard
			
			if(handCountBefore + 1 != game.handCount[players]) {// confirming there is a net sum of 1 added to hand
				printf("ERROR IN NUMBER OF CARDS ADDED: player: %i, expected game.handCount: %i, actual game.handCount: %i\n\n", players, handCountBefore + 1, game.handCount[players]);
			}

			if(game.hand[players][game.handCount[players]-1] != copper && game.hand[players][game.handCount[players]-1] != silver && game.hand[players][game.handCount[players]-1] != gold) {//confirming that there is treasure cards at the end of the hand
				printf("ERROR IN MISSING TREASURE CARD AT END OF HAND: player: %i\n\n", players);
			}
			
			
			if(game.hand[players][game.handCount[players]-2] != copper && game.hand[players][game.handCount[players]-2] != silver && game.hand[players][game.handCount[players]-2] != gold) {//confirming that there is treasure cards at the end of the hand - 1
				printf("ERROR IN MISSING TREASURE CARD AT END OF HAND - 1: player: %i\n\n", players);
			}
			
			if(returnVal != 0) {//confirming correct return value
				printf("ERROR IN RETURN VALUE: expected return value: 0, actual return value: %i\n\n", returnVal);
			}
		}
	}

	return 0;
}

