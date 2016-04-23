//cardtest1.c
//Unit test of playSmithy()

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {

	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	struct gameState *G = newGame();
 
	initializeGame(2, k, 1, G);
	
	
	
	printf ("\n--------Test 1: Play Smithy and Check that 3 Cards are Drawn and 1 (Smithy) is Discarded---------\n\n");
	
	initializeGame(2, k, 1, G);
	G->whoseTurn = 1;
	G->handCount[1] = 5;							//Set player 1 to have 5 cards
	G->hand[1][0] = smithy;
	for(int i = 1; i < 5; i++){					//Fill hand with 1 smithy and 4 curses
		G->hand[1][i] = curse;
	}
	
	playSmithy(G, 0);
	
	if(G->handCount[1] == 7){											 
		 printf("Passed\n");
	}
	else{
		printf("Failed\n");
	}
	
	printf ("\n--------Test 2:	Play Smithy with an empty player deck and empty discard pile---------\n\n");
	
	initializeGame(2, k, 1, G);
	G->whoseTurn = 1;
	G->handCount[1] = 5;							//Set player 1 to have 5 cards
	G->hand[1][0] = smithy;
	for(int i = 1; i < 5; i++){					//Fill hand with 1 smithy and 4 curses
		G->hand[1][i] = curse;
	}
	G->deckCount[1] = 0;
	
	playSmithy(G, 0);

	if(G->handCount[1] == 4){											 
		 printf("Passed\n");
	}
	else printf("Failed\n");


	printf("\n--------Test 3:	Play Smithy with an empty player deck and full discard pile---------\n\n");
	
	initializeGame(2, k, 1, G);
	G->whoseTurn = 1;
	G->handCount[1] = 5;							//Set player 1 to have 5 cards
	G->hand[1][0] = smithy;
	for(int i = 1; i < 5; i++){					//Fill hand with 1 smithy and 4 curses
		G->hand[1][i] = curse;
	}
	G->deckCount[1] = 0;
	for(int i = 0; i < 10; i++){							//Move deck to discard
		G->discard[1][i] = G->deck[1][i];
	}
	G->discardCount[1] = 10;

	playSmithy(G, 0);

	if(G->handCount[1] == 7){											 
		 printf("Passed\n");
	}
	else printf("Failed\n");
}