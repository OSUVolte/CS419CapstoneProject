/*
 * cardtest3.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest3: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
 *
 *      This will test the seahag card.
 *      Sea Hag is re-factored to use the function "discard Card"
I have it so it will do a for loop for all the players and an if statement that will discard the top card from the deck of the person.
It will then replace it with a curse card.
The error here is it does not take into account what to do if a person doesn't have a card in their hand.
 *
 *I did change my implementation a little bit because this had the same unintentional error that the adventurer card did
 *- the card was not being discarded.
 *
 *
 *
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void testFunctionality(struct gameState *state, int playerCount);
void testTopCardAndHand(struct gameState *state);


//it's player 0 turn. Player 1 is being tested and shows the bug.
void testTopCardAndHand(struct gameState *G)
{
	int i;
	struct gameState testG;
	int Before;
	int After;

	memcpy(&testG, G, sizeof(struct gameState));
	printf("Deck Before Draw: \n");
	for(i = 0; i < testG.deckCount[1]; i++)
	{
		printf("%d , ", testG.deck[1][testG.deckCount[i]]);
	}
	printf("\n");
	Before = testG.deck[1][testG.deckCount[0]];
	seahagPlay(testG.whoseTurn, &testG, 0);

	printf("Deck After Draw: \n");
	for(i = 0; i < testG.deckCount[1]; i++)
	{
		printf("%d , ", testG.deck[1][testG.deckCount[i]]);
	}
	After  = testG.deck[1][testG.deckCount[0]];
//	assert(Before != After);
	printf("\nValue before is %d, value after is %d \n **************** \n" , Before, After);


}

void testFunctionality(struct gameState *state, int playerCount)
{

	int i;
	int j;
	int curseCountBefore = 0;
	int curseCountAfter  = 0;
	int deckCountBefore;
	int deckCountAfter;
	int discardCountBefore;
	int discardCountAfter;
	struct gameState testG;
	int error = 0;



	for (i = 0; i < playerCount; i++)
	{
		memcpy(&testG, state, sizeof(struct gameState));
		if (i != testG.whoseTurn)
		{
			discardCountBefore = testG.discardCount[i];
			deckCountBefore = testG.deckCount[i];
			for (j = 0; j < testG.deckCount[i]; j++) {
				if (testG.deck[i][j] == curse) {
					curseCountBefore++;
				}
			}
			for (j = 0; j < testG.discardCount[i]; j++) {
				if (testG.discard[i][j] == curse) {
					curseCountBefore++;
				}
			}
			for (j = 0; j < testG.handCount[i]; j++) {
				if (testG.hand[i][j] == curse) {
					curseCountBefore++;
				}
			}

			seahagPlay(testG.whoseTurn, &testG, 0);

			discardCountAfter = testG.discardCount[i];
			deckCountAfter    = testG.deckCount[i];

			for (j = 0; j < testG.deckCount[i]; j++) {
				if (testG.deck[i][j] == curse) {
					curseCountAfter++;
				}
			}
			for (j = 0; j < testG.discardCount[i]; j++) {
				if (testG.discard[i][j] == curse) {
					curseCountAfter++;
				}
			}
			for (j = 0; j < testG.handCount[i]; j++) {
				if (testG.hand[i][j] == curse) {
					curseCountAfter++;
				}
			}
			if(curseCountAfter != curseCountBefore+1)
			{
				error = 1;
				printf("Curse Count Values are Before = %d , After = %d. Before should be one Less \n", curseCountBefore, curseCountAfter);

			}
			if(deckCountBefore != deckCountAfter)
			{
				error = 1;
				printf("Deck Count Values are Before = %d , After = %d. Before should be the same \n", deckCountBefore, deckCountAfter);
			}
			if(discardCountAfter != discardCountBefore+1)
			{
				error = 1;
				printf("Discard Count Values are Before = %d , After = %d. After pile should contain 1 more\n", discardCountBefore, discardCountAfter);

			}
		}
	}

if(error == 1)
{
	printf("Errors Found in Test. Cards are not getting discarded and/or added correctly.\n");
}
else
{
	printf("No errors found in Test\n");
}

return;
}

int main() {

		int seed = 27;
		int numPlayers = 2;
		struct gameState G, testG;
		int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
				tribute, smithy, council_room };
		int Before;
		int After;
		initializeGame(numPlayers, k, seed, &G);


		printf("Smoke Test To See If Function Crashes Program \n");
		memcpy(&testG, &G, sizeof(struct gameState));
		seahagPlay(testG.whoseTurn, &testG, 0);
		printf("Test Succeeded. \n **************** \n");

		printf("Test to see if Sea Hag correctly assigns a curse card to all opponents: \n");
		memcpy(&testG, &G, sizeof(struct gameState));
		testFunctionality(&testG, numPlayers);
		//bug found in discard card. it needs to come from the hand.
		printf("Test Complete \n **************** \n");

		printf("Test to see if SeaHag Correctly is Discarded From Player Hand. \n.......\n");
		memcpy(&testG, &G, sizeof(struct gameState));
		Before = testG.discardCount[testG.whoseTurn];
		seahagPlay(testG.whoseTurn, &testG, 0);
		After  = testG.discardCount[testG.whoseTurn];
		assert(Before+1 == After);
		//This is a bug I fixed on my own instead of leaving it in because it was driving me *nuts*.
		printf("Test Complete. Discard test over. \n **************** \n");

		printf("Check to see if top card is Curse for all players after card drawn\n\n");
		memcpy(&testG, &G, sizeof(struct gameState));
		testTopCardAndHand(&testG);
		printf("Test Complete. Top Card Test Over \n**************** \n");


return 0;
}
