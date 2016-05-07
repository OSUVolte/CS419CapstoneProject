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

//testing buyCard()
int main() {
	int seed = 1;//the seed for initializeGame
    int numPlayer;
	int players, handCount, i, j, tempCount;
	int cardCount = 10;//the number of cards initially given to a player
	
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState game;

	printf ("Testing buyCard():\n\n");
	
	for(numPlayer = 2; numPlayer <= 4; numPlayer++) {//checking for all possible number of players (2-4) {
		initializeGame(numPlayer, cards, seed, &game); // initialize a new game
		for (players = 0; players < numPlayer; players++)//drawing all cards for each player
		{   
			for (i = 0; i < cardCount; i++){//drawing entire deck
				drawCard(players, &game);//drawing a card	
			}
			
			game.numBuys = 1;
			game.whoseTurn = players;
			updateCoins(players, &game, 0);
			buyCard(smithy, &game);//note:smithy cost 4, less than coppers originally given
			
			if(fullDeckCount(players, smithy, &game) != 1) {//checking that the user can buy an affordable card
				printf("ERROR BUYING AFFORDABLE CARD: player: %i, buy: %i, expected cards after buy: %i, actual cards = %i\n\n", players, 1, 1, fullDeckCount(players, smithy, &game));
				printf("user has in hand %i\n", game.handCount[players]);
			}
			
			game.numBuys = 1;
			game.whoseTurn = players;
			buyCard(smithy, &game);//note:smithy cost 4, more than money left
			
			if(fullDeckCount(players, smithy, &game) != 1) {//checking that the user can't buy an unaffordable card
				printf("ERROR BUYING UNAFFORDABLE CARD: player: %i, buy: %i, expected cards after buy: %i, actual cards = %i\n\n", players, 2, 1, fullDeckCount(players, smithy, &game));
			}
			
			game.numBuys = 1;
			game.whoseTurn = players;
			
			tempCount = game.supplyCount[smithy];
			game.supplyCount[smithy] = 0;//removing smithy cards
			buyCard(smithy, &game);
			if(fullDeckCount(players, smithy, &game) != 1) {//checking that the user can't buy an absent
				printf("ERROR BUYING ABSENT CARD: player: %i, buy: %i, expected cards after buy: %i, actual cards = %i\n\n", players, 3, 1, fullDeckCount(players, smithy, &game));
			}
			
			game.supplyCount[smithy] = tempCount;//returning smithy cards
			
		}
	}
	return 0;
}