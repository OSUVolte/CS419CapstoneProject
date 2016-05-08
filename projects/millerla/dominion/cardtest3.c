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

//testing Sea Hag
int main() {
	int seed = 1;//the seed for initializeGame
    int numPlayer;
	int returnVal, players, handCountBefore, otherPlayers;
	int cardCount = 10;//the number of cards initially given to a player
	int previousDiscardCount[4];//array to hold discount count before sea hag
	int previousDeckCount[4];//array to hold deck count before sea hag
	
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState game;
	
	printf ("Testing Sea Hag:\n\n");
	
	for(numPlayer = 2; numPlayer <= 4; numPlayer++) {//checking for all possible number of players (2-4)
		
		initializeGame(numPlayer, cards, seed, &game);
		
		for (players = 0; players < numPlayer; players++)//testing each player
		{
			game.hand[players][game.handCount[players]] = sea_hag;
			game.handCount[players] = 1 + game.handCount[players];
			handCountBefore = game.handCount[players];
			game.whoseTurn = players;
			
			for(otherPlayers = 0; otherPlayers < numPlayer; otherPlayers++) {//getting discard count, deck count before sea hag
				previousDiscardCount[otherPlayers] = game.discardCount[otherPlayers];
				previousDeckCount[otherPlayers] = game.deckCount[otherPlayers];
			}
			
			returnVal = playCard(game.handCount[players] - 1, -1, -1, -1, &game);//playing the sea hag
			game.numActions++;//counteract playCard
			
			for(otherPlayers = 0; otherPlayers < numPlayer; otherPlayers++) {//going through all other players
				if(otherPlayers!= players && previousDiscardCount[otherPlayers] != game.discardCount[otherPlayers] - 1) {//making sure there is one more discardCount for all other players
					printf("ERROR IN NUMBER OF CARDS DISCARDED: player: %i, expected game.discardCount: %i, actual game.discardCount: %i\n\n", players, previousDiscardCount[otherPlayers] + 1, game.discardCount[otherPlayers]);
				}
				
				if(otherPlayers!= players && previousDeckCount[otherPlayers] != game.deckCount[otherPlayers]) {//making sure there are the same number of deck cards total for other players
					printf("ERROR IN NUMBER OF CARDS ADDED TO OR REMOVED FROM OTHER PLAYER'S DECK: player: %i, expected game.deckCount: %i, actual game.deckCount: %i\n\n", players, previousDeckCount[otherPlayers], game.deckCount[otherPlayers]);
				}
				
				if(otherPlayers!= players && game.deck[otherPlayers][game.deckCount[otherPlayers] - 1] != curse) {//making sure that every other player has a curse card on top of their deck
					printf("ERROR IN ABSENCE OF CURSE CARD FOR OTHER PLAYER: player: %i, other player: %i\n\n", players, otherPlayers);
				}
			}

			if(returnVal != 0) {//confirming correct return value
				printf("ERROR IN RETURN VALUE: expected return value: 0, actual return value: %i\n\n", returnVal);
			}
		}
	}

	return 0;
}

