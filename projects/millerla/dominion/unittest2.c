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

//testing discardCard()
int main() {
	int seed = 1;//the seed for initializeGame
    int numPlayer;
	int players, handCount, i, j;
	int cardCount = 10;//the number of cards initially given to a player
	int trashFlag;
	int returnVal;
	
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState game;
	
	
	printf ("Testing discardCard():\n\n");
	
	for(numPlayer = 2; numPlayer <= 4; numPlayer++) {//checking for all possible number of players (2-4) {
		for(trashFlag = 0; trashFlag <= 1; trashFlag++){//checking for both values of trashFlag
			
			initializeGame(numPlayer, cards, seed, &game); // initialize a new game
			for (players = 0; players < numPlayer; players++)//drawing all cards for each player
			{  
				for (i = 0; i < cardCount; i++){
					drawCard(players, &game);
				}
			}
			
			for (players = 0; players < numPlayer; players++) {//checking discards for all players
				for (handCount = cardCount - 1; handCount >= 0; handCount--) {//checking for entire hand of cards

					returnVal = discardCard(handCount, players, &game, trashFlag);//discarding for the current player to their discard pile if 0, trashPile if 1
					if(trashFlag == 0) {//if discarding card
						if(game.handCount[players] != handCount || cardCount - handCount != game.discardCount[players]) {//checking that card is moved from hand to discard pile
							printf("ERROR IN CARDS DISCARDED: player: %i, expected game.handCount: %i, expected game.discardCount: %i, actual game.handCount: %i, actual game.discardCount: %i\n\n", players, handCount, cardCount - handCount, game.handCount[players], game.discardCount[players]);
						}
					}
					else {//if trashing card
						if(game.handCount[players] != handCount || game.discardCount[players] != 0) {//checking that card is removed from hand and not added to discard pile
							printf("ERROR IN CARDS TRASHED: player: %i, expected game.handCount: %i, expected game.discardCount: 0, actual game.handCount: %i, actual game.discardCount: %i\n\n", players, handCount, game.handCount[players], game.discardCount[players]);
						}
					}
					
					if(returnVal != 0) {
						printf("ERROR IN RETURN VALUE: expected return value: 0, actual return value: %i\n\n", returnVal);
					}
				}
			}
		}
	}
	return 0;
}