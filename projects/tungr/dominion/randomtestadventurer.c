/*
	Rosa Tung
	CS 362 Assignment 4
	randomtestadventurer.c
		Write a random tester for two Dominion cards, one of which has to be the adventurer card.
*/

#include <stdio.h>
#include <stdlib.h> //rand()
#include <time.h> //time

#include "dominion.h"

//global variables
#define MAX_TESTS 10
/* dominion.h

#define MAX_HAND 500
#define MAX_DECK 500
#define MAX_PLAYERS 4	

*/

int main(){

	//make new game object
	struct gameState* G = newGame();
  	const char *cardNames[] = {"curse", "estate", "duchy", "province", "copper", "silver", "gold", "adventurer", "council_room", "feast", 
  								"gardens", "mine", "remodel", "smithy", "village", "baron", "great_hall", "minion", "steward", "tribute", 
  								"ambassador", "cutpurse", "embargo", "outpost", "salvager", "sea_hag", "treasure_map"};
	
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	int randPlayers;
	int test, player, card; 
	int choice1, choice2, choice3;

	//random seed
	srand(time(NULL));

	printf("---Random Testing Adventurer Card START---\n\n");
	
	/*loop through MAX_TEST times*/
	for(test = 0; test < MAX_TESTS; test++){
		randPlayers = (rand() % 3) + 2; //2-4 players
		printf("initializing game with %d players\n", randPlayers);
		initializeGame(randPlayers, k, 0, G);
		
		/*loop through players times*/
		for(player = 0; player < randPlayers; player++){
			G->deckCount[player] = rand() % MAX_DECK; //each player gets random deck size
			printf("player %d gets deck size of %d\n", player+1, G->deckCount[player]);

			/*loop through players deck*/
			for(card = 0; card < G->deckCount[player]; card++){
				G->deck[player][card] = rand() % 27; //assign random card from enum CARD
				printf("	%s\n", cardNames[G->deck[player][card]]);	
			}
			G->handCount[player] = rand() % MAX_HAND; //each player gets a random hand size
			printf("player %d gets hand size of %d\n", player+1, G->handCount[player]);
			
			/*loop through players hand*/
			for(card = 0; card < G->handCount[player]; card++){
				G->hand[player][card] = rand() % 27; //random hand
				printf("	%s\n", cardNames[G->hand[player][card]]);
			}
			/*loop throuhg players discard pile*/
			for(card = 0; card < G->discardCount[player]; card++){
				G->discard[player][card] = rand() % 27; //random discard
				printf("	%s\n", cardNames[G->discard[player][card]]);
			}
		}

		/*Count Treasures*/
	}

	printf("---Random Testing Adventurer Card COMPLETE---\n\n\n\n");
	return 0;
}