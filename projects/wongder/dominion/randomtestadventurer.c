#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <time.h> 
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define MAX_TESTS 10


// Random Testing for Adventurer Card
// Reveal cards from your deck until you reveal 2 Treasure cards.
// Put those Treasure cards into your hand and discard the other revealed cards.

int main() {
    int i;
	int player, card, handPosition, returnValue;
	struct gameState G, RESET;
	int randPlayer, randSeed, handBefore, handAfter, deckBefore, deckAfter, discardBefore, discardAfter;
	int handPass = 0, handFail = 0, deckPass = 0, deckFail = 0, discardPass = 0, discardFail = 0, returnPass = 0, returnFail = 0, treasurePass = 0, treasureFail = 0;
	int treasureCountBefore, treasureCountAfter;
	int choice1, choice2, choice3;
	const char *cardNames[] = {"adventurer", "council_room", "feast", "gardens", "mine"
               , "remodel", "smithy", "village", "baron", "great_hall", "copper", "silver", "gold"};
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
			   
	srand(time(NULL));
	
	printf("~~~Random Testing Adventurer Card~~~\n\n");
			   
 //   struct gameState G, RESET;
	
//	initializeGame(numPlayer, k, seed, &RESET);
	memcpy(&G, &RESET, sizeof(struct gameState));
	
	for (i = 0; i < MAX_TESTS; i++){
		printf("Test #%d\n\n", i+1);
		memcpy(&G, &RESET, sizeof(struct gameState));
		randPlayer = (rand() % 3) + 2;
		randSeed = (rand() % 1000) + 1;
		printf("Number of Players = %d, Seed Number = %d\n", randPlayer, randSeed);
		initializeGame(randPlayer, k, randSeed, &G);
		
		for (player = 0; player < randPlayer; player++){
			handBefore, handAfter, deckBefore, deckAfter, discardBefore, discardAfter;
			treasureCountBefore = 0;
			treasureCountAfter = 0;
				
			// set deck 
			G.deckCount[player] = rand () % MAX_DECK;
			printf("Player %d deck size = %d\n", player+1, G.deckCount[player]);
			for (card = 0; card < G.deckCount[player]; card++){
				G.deck[player][card] = rand() % 13;
				printf(" %s , ", cardNames[G.deck[player][card]]);
			}printf("\n");
			
			// set discard pile 
			G.discardCount[player] = rand() % MAX_DECK;
			printf("Player %d discard size = %d\n", player+1, G.discardCount[player]);
			for (card = 0; card < G.discardCount[player]; card++){
				G.discard[player][card] = rand() % 13;
				printf(" %s , ", cardNames[G.discard[player][card]]);
			}printf("\n");
			
			// set hand
			G.handCount[player] = rand() % MAX_HAND;
			printf("Player %d hand size = %d\n", player+1, G.handCount[player]);
			for (card = 0; card < G.handCount[player]; card++){
				G.hand[player][card] = rand() % 13;
				if (G.hand[player][card] == gold || G.hand[player][card] == silver || G.hand[player][card] == copper){
					treasureCountBefore++;
				}
				printf(" %s ,", cardNames[G.hand[player][card]]);
			}printf("\n");
			
			handBefore = G.handCount[player];
			deckBefore = G.deckCount[player];
			discardBefore = G.discardCount[player];
			printf("Hand Count Before = %d\n", handBefore);
			printf("Deck Count Before = %d\n", deckBefore);
			printf("Discard Count Before = %d\n", discardBefore);
			printf("Treasure Count Before = %d\n", treasureCountBefore);
			
			choice1 = rand() % 2;
			choice2 = rand() % 2;
			choice3 = rand() % 2;
			handPosition = rand() % G.handCount[player];
			G.hand[player][handPosition] = adventurer;
			printf("Choice1 = %d, Choice2 = %d, Choice3 = %d, handPosition = %d\n", choice1, choice2, choice3, handPosition);
			
			G.whoseTurn = player;
			returnValue = cardEffect(adventurer, choice1, choice2, choice3, &G, handPosition, 0);
			
			for (card = 0; card < G.handCount[player]; card++){
				if (G.hand[player][card] == gold || G.hand[player][card] == silver || G.hand[player][card] == copper){
					treasureCountAfter++;
				}
			}
			
			handAfter = G.handCount[player]; //should increase by 1 (+2 card -1 card)
			deckAfter = G.deckCount[player]; //should be less than before
			discardAfter = G.discardCount[player]; //should increase 
			printf("Hand Count After = %d\n", handAfter);
			printf("Deck Count After = %d\n", deckAfter);
			printf("Discard Count After = %d\n", discardAfter);
			printf("Treasure Count After = %d\n", treasureCountAfter); // should increase by 2
			
			if (handAfter == handBefore + 2){
				handPass++;
				printf("Hand Count Passed\n");
			}
			else{
				handFail++;
				printf("Hand Count Failed\n");
			}
			
			if (deckAfter < deckBefore){
				deckPass++;
				printf("Deck Count Passed\n");
			}
			else{
				deckFail++;
				printf("Deck Count Failed\n");
			}
			
			if (discardAfter > discardBefore){
				discardPass++;
				printf("Played Card Count Passed\n");
			}
			else{
				discardFail++;
				printf("Played Card Count Failed\n");
			}
			
			if (treasureCountAfter == treasureCountBefore + 2){
				treasurePass++;
				printf("Treasure Count Passed\n");
			}
			else{
				treasureFail++;
				printf("Treasure Count Failed\n");
			}
			
			if (returnValue == 0){
				returnPass++;
				printf("Return Value Passed\n");
			}
			else{
				returnFail++;
				printf("Return Value Failed\n");
			}
		}
		
	}

	printf("\n\n");
	printf("Hand Card Count Pass: %d\n", handPass);
	printf("Hand Card Count Fail: %d\n", handFail);
	printf("Deck Card Count Pass: %d\n", deckPass);
	printf("Deck Card Count Fail: %d\n", deckFail);
	printf("Discard Card Count Pass: %d\n", discardPass);
	printf("Discard Card Count Fail: %d\n", discardFail);
	printf("Treasure Count Passed: %d\n", treasurePass);
	printf("Treasure Count Failed: %d\n", treasureFail);
	printf("Return Value Pass: %d\n", returnPass);
	printf("Return Value Fail: %d\n", returnFail);
	
	return 0;
	
}