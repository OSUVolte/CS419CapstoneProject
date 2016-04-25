/*
 * unittest1.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 *
 *      Test shuffle function
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>




int main() {

		int seed = 12;
		int numPlayers = 2;
		struct gameState G, testG;
		int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
				tribute, smithy, council_room };
		int z[5] = {gold, baron, great_hall, steward, treasure_map};
		int i;
		int j;
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);
		int card;
		int s;

		printf("-------------------------------------------------\n");
		printf("Test to see if shuffle with 1 card..");
		memcpy(&testG, &G, sizeof(struct gameState));
		testG.deckCount[testG.whoseTurn] = 1;
		testG.deck[testG.whoseTurn][0] = curse;
		shuffle(testG.whoseTurn, &testG);
		assert(testG.deckCount[testG.whoseTurn] == 1);
		assert(testG.deck[testG.whoseTurn][0] == curse);
		printf("\nTest Passed. Card Shuffled and Unchanged.\n");


		printf("-------------------------------------------------\n");
		printf("Test to see shuffle with higher value cards: \n");
		memcpy(&testG, &G, sizeof(struct gameState));

		testG.deck[testG.whoseTurn][0] = steward;
		testG.deck[testG.whoseTurn][1] = baron;
		testG.deck[testG.whoseTurn][2] = great_hall;
		testG.deck[testG.whoseTurn][3] = steward;
		testG.deck[testG.whoseTurn][4] = treasure_map;
		testG.deckCount[testG.whoseTurn] = 5;
		shuffle(testG.whoseTurn, &testG);
		printf("Expected Result is combination of %d, %d, %d, %d, %d \n", steward, baron, great_hall, steward, treasure_map);
		printf("Actual result is: ");
		for(i = 0; i < testG.deckCount[testG.whoseTurn]; i++)
		{
			printf("%d ", testG.deck[testG.whoseTurn][i]);
		}
		printf("\nTest Complete\n");
		printf("-------------------------------------------------\n");

		printf("Test to see if shuffle with 0 cards..\n");
		testG.deckCount[testG.whoseTurn] = 0;
		card = shuffle(testG.whoseTurn, &testG);
		assert(card == -1);
		printf("Test Passed. Function Returns Error with 0 Cards\n");

		printf("-------------------------------------------------\n");
		//  qsort ((void*)(state->deck[player]), state->deckCount[player], sizeof(int), compare); appears
		// to be wrong based on (void*)(state->deck[player]
		printf("Test to see if OTHER deck effected.\n");
		testG.deck[1][0] = steward;
		testG.deck[1][1] = baron;
		testG.deck[1][2] = great_hall;
		testG.deck[1][3] = steward;
		testG.deck[1][4] = treasure_map;
		printf("Expected Result is exactly \n%d, %d, %d, %d, %d \n", steward, baron, great_hall, steward, treasure_map);
		printf("Actual Result is: \n");
		testG.deckCount[1] = 5;
		for(i = 0; i < testG.deckCount[1]; i++)
		{
			printf("%d ", testG.deck[1][i]);
		}
		printf("\n-------------------------------------------------\n");

return 0;

}
