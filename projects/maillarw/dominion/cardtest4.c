//cardtest3.c
//Unit test of playVillage()

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {
	
	printf ("\n************************    Card Test 4: Testing playVillage()    **********************\n\n");
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	struct gameState *G = newGame();
 
	initializeGame(2, k, 1, G);
	
	int allCards[27] = {curse,  estate, duchy, province, copper, silver, gold, adventurer, council_room, 
                      feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, 
                      steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
  	int numCards = 27;
	
	
	printf ("\n--------Test 1: Play Village. Player should add one card to hand and remove one card from hand ------------\n\n");
	
	initializeGame(2, k, 1, G);
	G->whoseTurn = 1;
	for(int i = 0; i < 10; i++){  				//Fill deck with gold so we know what's in it
		G->deck[1][i] = gold;
	}
	G->handCount[1] = 5;							//Set player 1 to have 5 cards
	G->hand[1][0] = village;
	for(int i = 1; i < 5; i++){					//Fill hand with 1 village and 4 curses
		G->hand[1][i] = curse;
	}

	playVillage(G, 0);
	if(G->handCount[1] == 5 && G->hand[1][0] != village){											 
		 printf("Passed\n");
	}
	else{
		printf("Failed\n");
	}

	printf ("\n--------Test 2: Play Village. One card (Village) should be sent to playedCards ------------\n\n");
	
	initializeGame(2, k, 1, G);
	G->whoseTurn = 1;
	G->handCount[1] = 5;							//Set player 1 to have 5 cards
	G->hand[1][0] = village;
	for(int i = 1; i < 5; i++){					//Fill hand with 1 village and 4 curses
		G->hand[1][i] = curse;
	}

	playVillage(G, 0);
	
	if(G->playedCardCount == 1 && G->playedCards[0] == village){											 
		 printf("Passed\n");
	}
	else{
		printf("Failed\n");
	}
	
	printf ("\n--------Test 3: Play Village. Actions should be increased by 2 ------------\n\n");
	
	initializeGame(2, k, 1, G);
	G->whoseTurn = 1;
	G->handCount[1] = 5;							//Set player 1 to have 5 cards
	G->hand[1][0] = village;
	for(int i = 1; i < 5; i++){					//Fill hand with 1 village and 4 curses
		G->hand[1][i] = curse;
	}
	int actions = 2;
	G->numActions = actions;
	actions += 2;
	playVillage(G, 0);
	
	if(G->numActions == actions){											 
		 printf("Passed\n");
	}
	else{
		printf("Failed\n");
	}
}
