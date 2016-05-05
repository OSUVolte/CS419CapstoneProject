/*
Name: Lauren Miller
Class: CS362
Assighnment: Assignment 4
Date: 5/4/2016
*/

#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//testing Village - +1 Card, +2 Action
int main() {
	
	int randomRun = 1000000;//the number of times the random checker runs
	int seed = 1;//the seed for initializeGame
	int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};//used to initialize game - not cards for player playing village
    struct gameState game;//the game used
	struct gameState preCardGame;//saved version of game	
    int numPlayer, i, j, k, currentPlayer, returnVal;

	srand(time(NULL));//seeding rand
	
	printf ("Testing Vilage:\n\n");
	
	for(i = 0; i < randomRun; i++) {
		
		numPlayer = 2+ rand()%3;//setting a random number of players between 2-4
		currentPlayer = rand()%numPlayer;//getting the current player
		
		initializeGame(numPlayer, cards, seed, &game);//setting base game	
		
		game.handCount[currentPlayer] = rand()%MAX_HAND; //setting the hand count to random number between 0 and MAX_HAND
		for(k = 0; k < game.handCount[currentPlayer] - 1; k++) {
			game.hand[currentPlayer][k] = (enum CARD)(rand()%27);//adding one of the 27 random cards to the hand
		}
		
		game.deckCount[currentPlayer] = rand()%MAX_DECK; //setting the deck count to random number between 0 and MAX_DECK
		for(k = 0; k < game.deckCount[currentPlayer]; k++) {
			game.deck[currentPlayer][k] = (enum CARD)(rand()%27);//adding one of the 27 random cards to the hand
		}
		
		game.discardCount[currentPlayer] = rand()%MAX_DECK; //setting the discard count to random number between 0 and MAX_DECK
		for(k = 0; k < game.discardCount[currentPlayer]; k++) {
			game.discard[currentPlayer][k] = (enum CARD)(rand()%27);//adding one of the 27 random cards to the hand
		}
		
		game.numActions = rand()%MAX_HAND;//setting the number of actions
		game.hand[currentPlayer][game.handCount[currentPlayer] - 1] = village;//setting the last card in hand of the currentPlayer to village
		game.whoseTurn = currentPlayer;
		
		memcpy(&preCardGame, &game, sizeof(struct gameState));//saving game
		returnVal = playCard(game.handCount[currentPlayer] - 1, -1, -1, -1, &game);//playing the village
		
		if(returnVal != 0 && game.numActions > 0) {//checking correct return value with valid game state
			printf("ERROR IN RETURN VALUE: test: %i, expected return value: 0, actual return value: %i\n\n", i, returnVal);
		}
		
		if(returnVal == 0 && game.numActions != preCardGame.numActions + 1) {//checking that net number of actions added is 1 with valid game state
			printf("ERROR IN NUMBER OF ACTIONS ADDED: test: %i, player: %i, expected game.numActions: %i, actual game.numActions: %i\n\n", i+1, currentPlayer, preCardGame.numActions + 1, game.numActions);
		}
			
		if(returnVal == 0 && game.handCount[currentPlayer] != preCardGame.handCount[currentPlayer] && game.deckCount[currentPlayer] + game.discardCount[currentPlayer] > 0) {//checking that net cards added to hand is 0 with valid game state - if there are enough cards in discard or deck piles
			printf("ERROR IN NUMBER OF CARDS ADDED TO HAND: test: %i, player: %i, expected game.numActions: %i, actual game.numActions: %i\n\n", i+1, currentPlayer, preCardGame.handCount[currentPlayer], game.handCount[currentPlayer]);
		}	
	}

	return 0;
}