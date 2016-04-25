//cardtest2.c
//Unit test of playAdventurer()

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {

	printf ("\n************************    Card Test 2: Testing playAdventurer()     **********************\n\n");
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	struct gameState *G = newGame();
 
	initializeGame(2, k, 1, G);
	
	int allCards[27] = {curse,  estate, duchy, province, copper, silver, gold, adventurer, council_room, 
                      feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, 
                      steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
  	int numCards = 27;
	
	
	printf ("\n--------Test 1: Play Adventurer with a deck full of Gold and check that -----------------\n-------- two Gold Cards are added to the player's hand---------\n\n");
	
	initializeGame(2, k, 1, G);
	G->whoseTurn = 1;
	G->handCount[1] = 5;							//Set player 1 to have 5 cards
	G->hand[1][0] = adventurer;
	for(int i = 1; i < 5; i++){					//Fill hand with 1 adventurer and 4 curses
		G->hand[1][i] = curse;
	}
	for(int i = 1; i < 10; i++){				//Fill Deck with all Gold
		G->deck[1][i] = gold;
	}
	
	playAdventurer(G);

	if(G->handCount[1] == 7 && G->hand[1][5] == gold && G->hand[1][6] == gold){											 
		 printf("Passed\n");
	}
	else{
		printf("Failed\n");
	}


	printf ("\n--------Test 2: Play Adventurer with a deck full of Gold and check that -----------------\n-------- one card is discarded (Adventurer)---------\n\n");
	
	initializeGame(2, k, 1, G);
	G->whoseTurn = 1;
	G->handCount[1] = 5;							//Set player 1 to have 5 cards
	G->hand[1][0] = adventurer;
	for(int i = 1; i < 5; i++){					//Fill hand with 1 adventurer and 4 curses
		G->hand[1][i] = curse;
	}
	for(int i = 1; i < 10; i++){				//Fill Deck with all Gold
		G->deck[1][i] = gold;
	}
	
	playAdventurer(G);

	if(G->playedCardCount == 1 && G->playedCards[0] == adventurer){											 
		 printf("Passed\n");
	}
	else{
		printf("Failed\n");
	}


	printf ("\n--------Test 3: Play Adventurer with a deck of 10 with the last 2 being silver cards, check -----------------\n-------- that 9 cards are discarded (viewed cards + Adventurer)---------\n\n");
	
	initializeGame(2, k, 1, G);
	G->whoseTurn = 1;
	G->handCount[1] = 5;							//Set player 1 to have 5 cards
	G->hand[1][0] = adventurer;
	for(int i = 1; i < 5; i++){					//Fill hand with 1 adventurer and 4 curses
		G->hand[1][i] = curse;
	}
	for(int i = 0; i < 8; i++){
		G->deck[1][i] = curse;
	}

	for(int i = 8; i < 10; i++){				
		G->deck[1][i] = silver;
	}
	
	playAdventurer(G);

	if(G->discardCount[1] == 8 && G->playedCards[0] == adventurer){											 
		 printf("Passed\n");
	}
	else{
		printf("Failed\n");
	}


	printf ("\n--------Test 4: Play Adventurer with an empty deck and discard pile of all Copper-----------------\n-------- Check that two Copper Cards are added to the player's hand ---------\n\n");
	
	initializeGame(2, k, 1, G);
	G->whoseTurn = 1;
	G->handCount[1] = 5;							//Set player 1 to have 5 cards
	G->hand[1][0] = adventurer;
	for(int i = 1; i < 5; i++){					//Fill hand with 1 adventurer and 4 curses
		G->hand[1][i] = curse;
	}
	for(int i = 0; i < 10; i++){
		G->discard[1][i] = copper;
	}
	G->discardCount[1] = 10;
	G->deckCount[1] = 0;

	playAdventurer(G);

	if(G->handCount[1] == 7 && G->hand[1][5] == copper && G->hand[1][6] == copper){											 
		 printf("Passed\n");
	}
	else{
		printf("Failed\n");
	}
}
