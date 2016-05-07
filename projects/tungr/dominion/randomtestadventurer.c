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
	int randState;
	int test, player, card; 
	int cardEnum, treasuresBefore, treasuresAfter;
	int choice1, choice2, choice3;
	int treasurePass = 0, treasureFail = 0, returnPass = 0, returnFail = 0, returnValue; 
	int handPosition;

	//random seed
	srand(time(NULL));

	printf("---Random Testing Adventurer Card START---\n\n");
	
	/*loop through MAX_TEST times*/
	for(test = 0; test < MAX_TESTS; test++){
		randPlayers = (rand() % 3) + 2; //2-4 players
		randState = (rand() % 9) + 1; //1-9 state
		printf("initializing game with %d players and state of %d\n", randPlayers, randState);
		initializeGame(randPlayers, k, randState, G);
		
		/*loop through players times - set decks*/
		for(player = 0; player < randPlayers; player++){
			treasuresBefore = 0; //reset treasure counts
			treasuresAfter = 0;
			G->deckCount[player] = rand() % MAX_DECK; //each player gets random deck size
			printf("player %d gets deck size of %d\n", player+1, G->deckCount[player]);

			/*loop through players deck*/
			for(card = 0; card < G->deckCount[player]; card++){
				G->deck[player][card] = rand() % 27; //assign random card from enum CARD
				printf(" %s  | ", cardNames[G->deck[player][card]]);	
			} printf("\n");
			G->discardCount[player] = rand() % MAX_DECK; //each player gets random discard deck size
			printf("player %d gets discard size of %d\n", player+1, G->discardCount[player]);

			/*loop throuhg players discard pile*/
			for(card = 0; card < G->discardCount[player]; card++){
				G->discard[player][card] = rand() % 27; //random discard
				printf(" %s  | ", cardNames[G->discard[player][card]]);
			}printf("\n");

			G->handCount[player] = rand() % MAX_HAND; //each player gets a random hand size
			printf("player %d gets hand size of %d\n", player+1, G->handCount[player]);
			
			/*loop through players hand - count treasures*/
			for(card = 0; card < G->handCount[player]; card++){
				G->hand[player][card] = rand() % 27; //random hand
				cardEnum = G->hand[player][card];
				printf(" %s  | ", cardNames[G->hand[player][card]]);
				/*if it's a treasure card, tally it up*/
				if(cardEnum == copper || cardEnum == silver || cardEnum == gold){
					treasuresBefore++;
				}
			} printf("\n");
			printf("Treasures Before: %d\n", treasuresBefore);

			choice1 = rand() % 2; //0 or 1
			choice2 = rand() % 2; 
			choice3 = rand() % 2;	
			handPosition = rand() % 4; //no bonus
			printf("Card Effect with choice1 = %d choice2 = %d choice3 = %d handPosition = %d\n", choice1, choice2, choice3, handPosition);

			/*card effect - return value pass or fail*/
			returnValue = cardEffect(adventurer, choice1, choice2, choice3, G, handPosition, 0);
			if(returnValue == 0){
				returnPass++;
				printf("	RETURN VALUE PASS\n");
			} else {
				returnFail++;
				printf("	RETURN VALUE FAIL\n");
			}

			/*loop through players hand again - compare tresaures counts*/
			for(card = 0; card < G->handCount[player]; card++){
				cardEnum = G->hand[player][card]; //get card type
				if(cardEnum == copper || cardEnum == silver || cardEnum == gold){
					treasuresAfter++;
				}
			}
			printf("Treasures After: %d\n", treasuresAfter);

			/*treasure count fail or pass*/
			if(treasuresAfter == treasuresBefore + 2){
				treasurePass++;
				printf("	TREASURE COUNT PASS\n");
			} else {
				treasureFail++;
				printf("	TREASURE COUNT FAIL\n");
			}
		}

		/*print out results*/
		printf("Times Treasures Count Passes: %d\n", treasurePass);
		printf("Times Treasures Count Fails: %d\n", treasureFail);
		printf("Times Return Value Passes: %d\n", returnPass);
		printf("Times Return Value Passes: %d\n", returnFail);
	}

	printf("---Random Testing Adventurer Card COMPLETE---\n\n\n\n");
	return 0;
}