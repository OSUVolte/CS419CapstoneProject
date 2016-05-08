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

//testing Adventurer - reveal cards from deck until two treasure cards are found, then discard the other revealed cards
int main() {
	int randomRun = 1000000;//the number of times the random checker runs
	int seed = 1;//the seed for initializeGame
	int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};//used to initialize game - not cards for player playing adventurer
    struct gameState game;//the game used
	struct gameState preCardGame;//saved version of game	
    int numPlayer, i, j, k, currentPlayer, returnVal;
	int treasureCount = 0;//the number of gold, silver, or copper cards in play for the currentPlayer

	srand(time(NULL));//seeding rand
	
	printf ("Testing Adventurer:\n\n");
	
	for(i = 0; i < randomRun; i++) {
		treasureCount = 0;
		
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
		game.hand[currentPlayer][game.handCount[currentPlayer] - 1] = adventurer;//setting the last card in hand of the currentPlayer to adventurer
		game.whoseTurn = currentPlayer;	
		
		//counting the number of treasure cards in the deck and discard pile
		for (j = 0; j < game.deckCount[currentPlayer]; j++)
		{
		  if (game.deck[currentPlayer][j] == gold) treasureCount++;
		  if (game.deck[currentPlayer][j] == silver) treasureCount++;
		  if (game.deck[currentPlayer][j] == silver) treasureCount++;
		}
		for (j = 0; j < game.discardCount[currentPlayer]; j++)
		{
		  if (game.discard[currentPlayer][j] == gold) treasureCount++;
		  if (game.discard[currentPlayer][j] == silver) treasureCount++;
		  if (game.discard[currentPlayer][j] == copper) treasureCount++;
		}
	
		memcpy(&preCardGame, &game, sizeof(struct gameState));//saving game
		returnVal = playCard(game.handCount[currentPlayer] - 1, -1, -1, -1, &game);//playing the adventurer
			
		if(returnVal != 0 && game.numActions > 0) {//checking correct return value with valid game state
			printf("ERROR IN RETURN VALUE: test: %i, expected return value: 0, actual return value: %i\n\n", i, returnVal);
		}
		
		if(treasureCount == 0 && returnVal == 0 && preCardGame.handCount[currentPlayer] - 1 != game.handCount[currentPlayer]) {// confirming there is a net of 1 card taken from hand when 0 treasure cards available
			printf("ERROR IN NET NUMBER OF CARDS ADDED: test: %i, player: %i, treasure in game.deckCount and game.discardCount: %i, expected game.handCount: %i, actual game.handCount: %i\n\n", i, currentPlayer, treasureCount, preCardGame.handCount[currentPlayer] - 1, game.handCount[currentPlayer]);
		}
		else if(treasureCount == 1 && returnVal == 0 && preCardGame.handCount[currentPlayer] != game.handCount[currentPlayer]) {// confirming there is a net of 0 cards added to hand when 1 treasure card is available
			printf("ERROR IN NET NUMBER OF CARDS ADDED: test: %i, player: %i, treasure in game.deckCount and game.discardCount: %i, expected game.handCount: %i, actual game.handCount: %i\n\n", i, currentPlayer, treasureCount, preCardGame.handCount[currentPlayer], game.handCount[currentPlayer]);
		}
		else if(treasureCount >= 2 && returnVal == 0 && preCardGame.handCount[currentPlayer] + 1 != game.handCount[currentPlayer]) {// confirming there is a net of 1 card added to hand when 2 treasure cards available
			printf("ERROR IN NET NUMBER OF CARDS ADDED: test: %i, player: %i, treasure in game.deckCount and game.discardCount: %i, expected game.handCount: %i, actual game.handCount: %i\n\n", i, currentPlayer, treasureCount, preCardGame.handCount[currentPlayer] + 1, game.handCount[currentPlayer]); //LAUREN
		}
		
		if(game.handCount[currentPlayer] - preCardGame.handCount[currentPlayer] > - 1 && treasureCount >= 1 && game.hand[currentPlayer][game.handCount[currentPlayer]-1] != copper && game.hand[currentPlayer][game.handCount[currentPlayer]-1] != silver && game.hand[currentPlayer][game.handCount[currentPlayer]-1] != gold) {//confirming that there is treasure cards at the end of the hand if a card has been added and there are available treasure cards
			printf("ERROR IN MISSING TREASURE CARD AT END OF HAND: test: %i, player: %i, game.deckCount previously: %i, game.discardCount previously: %i, treasure in game.deckCount and game.discardCount: %i, CARD enum: %i, net game.handCount: %i\n\n", i,  currentPlayer, preCardGame.deckCount[currentPlayer], preCardGame.discardCount[currentPlayer], treasureCount, (int)game.hand[currentPlayer][game.handCount[currentPlayer]-1], game.handCount[currentPlayer] - preCardGame.handCount[currentPlayer]);
		}
		
		if(game.handCount[currentPlayer] - preCardGame.handCount[currentPlayer] > 0 && treasureCount >= 2 && game.hand[currentPlayer][game.handCount[currentPlayer]-2] != copper && game.hand[currentPlayer][game.handCount[currentPlayer]-2] != silver && game.hand[currentPlayer][game.handCount[currentPlayer]-2] != gold) {//confirming that there is treasure cards at the end of the hand
			printf("ERROR IN MISSING TREASURE CARD AT END OF HAND - 1: test: %i, player: %i, game.deckCount previously: %i, game.discardCount previously: %i, treasure in game.deckCount and game.discardCount: %i, CARD enum: %i, net game.handCount: %i\n\n", i,  currentPlayer, preCardGame.deckCount[currentPlayer], preCardGame.discardCount[currentPlayer], treasureCount, (int)game.hand[currentPlayer][game.handCount[currentPlayer]-2], game.handCount[currentPlayer] - preCardGame.handCount[currentPlayer]);
		}
		
	}
	return 0;
}