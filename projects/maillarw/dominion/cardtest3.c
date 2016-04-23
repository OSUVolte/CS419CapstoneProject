//cardtest3.c
//Unit test of playCouncilRoom()

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {

	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	struct gameState *G = newGame();
 
	initializeGame(2, k, 1, G);
	
	int allCards[27] = {curse,  estate, duchy, province, copper, silver, gold, adventurer, council_room, 
                      feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, 
                      steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
  	int numCards = 27;
	
	
	printf ("\n--------Test 1: Play CouncilRoom. 4 Cards should be added to player's hand and the CouncilRoom should be in Played Cards ------------\n\n");
	
	initializeGame(2, k, 1, G);
	G->whoseTurn = 1;
	G->handCount[1] = 5;							//Set player 1 to have 5 cards
	G->hand[1][0] = council_room;
	for(int i = 1; i < 5; i++){					//Fill hand with 1 council_room and 4 curses
		G->hand[1][i] = curse;
	}

	playCouncil_Room(G, 0);
	if(G->handCount[1] == 8 && G->playedCardCount == 1 && G->playedCards[0] == council_room){											 
		 printf("Passed\n");
	}
	else{
		printf("Failed\n");
	}


	
	printf ("\n--------Test 2: Play CouncilRoom with 2 players. 1 Card should be added to every other player's hand------------\n\n");
	
	initializeGame(2, k, 1, G);
	G->whoseTurn = 1;
	G->handCount[1] = 5;							//Set player 1 to have 5 cards
	G->hand[1][0] = council_room;
	for(int i = 1; i < 5; i++){					//Fill hand with 1 council_room and 4 curses
		G->hand[1][i] = curse;
	}

	playCouncil_Room(G, 0);

	if(G->handCount[0] == 6){											 
		 printf("Passed\n");
	}
	else{
		printf("Failed\n");
	}
	   
	printf ("\n--------Test 3: Play CouncilRoom with 4 players. 1 Card should be added to every other player's hand------------\n\n");
	
	initializeGame(4, k, 1, G);
	G->whoseTurn = 1;
	G->handCount[1] = 5;							//Set player 1 to have 5 cards
	G->hand[1][0] = council_room;
	for(int i = 1; i < 5; i++){					//Fill hand with 1 council_room and 4 curses
		G->hand[1][i] = curse;
	}

	playCouncil_Room(G, 0);

	if(G->handCount[0] == 6 && G->handCount[2] == 1 && G->handCount[3] == 1){											 
		 printf("Passed\n");
	}
	else{
		printf("Failed\n");
	}


	printf ("\n--------Test 4: Play CouncilRoom. Number of buys should be increased by 1 ------------\n\n");
	
	initializeGame(2, k, 1, G);
	G->whoseTurn = 1;
	G->handCount[1] = 5;							//Set player 1 to have 5 cards
	G->hand[1][0] = council_room;
	for(int i = 1; i < 5; i++){					//Fill hand with 1 council_room and 4 curses
		G->hand[1][i] = curse;
	}
	
	int buys = 2;
	G->numBuys = buys;
	playCouncil_Room(G, 0);
	buys++;

	if(G->numBuys == buys){											 
		 printf("Passed\n");
	}
	else{
		printf("Failed\n");
	}
}
