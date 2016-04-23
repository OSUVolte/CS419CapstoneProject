/*
 * unittest3.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 *
 *      Test DrawCard function. I did not draw out  any bugs here :(.
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
				tribute, smithy, council_room };\
		int i;
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);

		printf("Test DrawCard Function: \n");
		printf("-------------------------------------------------\n");
		printf("Test Drawing Card To Hand Test\n");
		memcpy(&testG, &G, sizeof(struct gameState));
		drawCard(testG.whoseTurn, &testG);
		assert(testG.handCount[testG.whoseTurn] == 6);
		printf("Test complete.\n");
		printf("-------------------------------------------------\n");

		printf("-------------------------------------------------\n");
		printf("Test to see running with empty deck: \n");
		memcpy(&testG, &G, sizeof(struct gameState));
		testG.discardCount[testG.whoseTurn] =3;
		testG.discard[testG.whoseTurn][0] = curse;
		testG.discard[testG.whoseTurn][1] = curse;
		testG.discard[testG.whoseTurn][2] = curse;
		testG.deckCount[testG.whoseTurn] = 0;
		testG.handCount[testG.whoseTurn] = 0;
		drawCard(testG.whoseTurn, &testG);
		assert(testG.hand[testG.whoseTurn][0] == curse);
		for(i = 0; i < testG.deckCount[testG.whoseTurn]; i++)
		{
			assert(testG.deck[testG.whoseTurn][i] == curse);
		}
		assert(testG.deckCount[testG.whoseTurn] == 2);
		assert(testG.discardCount[testG.whoseTurn] == 0);
		printf("Test Complete - empty deck shuffles correctly.\n");
		printf("-------------------------------------------------\n");


		printf("Test to see if card is drawn from top slot in deck: \n");
		memcpy(&testG, &G, sizeof(struct gameState));
		testG.deck[testG.whoseTurn][testG.handCount[testG.whoseTurn]-1] = 50;
		drawCard(testG.whoseTurn, &testG);
		assert(testG.hand[testG.whoseTurn][testG.handCount[testG.whoseTurn]-1] == 50);
		printf("Test Complete - Draw Card pulls from top of deck correctly.\n");
		printf("-------------------------------------------------\n");

		printf("-------------------------------------------------\n");
		printf("Test when all cards are in hand - no cards in discard / deck\n");
		memcpy(&testG, &G, sizeof(struct gameState));
		testG.discardCount[testG.whoseTurn] = 0;
		testG.deckCount[testG.whoseTurn] = 0;
		drawCard(testG.whoseTurn, &testG);
		assert(testG.discardCount[testG.whoseTurn] == 0);
		assert(testG.deckCount[testG.whoseTurn] == 0);
		assert(testG.handCount[testG.whoseTurn] == 5);
		printf("Test correctly returns no changes.\n");
		printf("-------------------------------------------------\n");
		return 0;
}
