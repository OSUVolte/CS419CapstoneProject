/*********************************************************************************************
 * Developer: Nick Martin (martinn6)
 * Date: 20160506
 * Project: Assignement 4
 * Description: Random testing - smithy
 * *******************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
    int newCards = 0;
	int discarded = 0;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 4;
    int thisPlayer = 0;
	struct gameState G2, testG2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
			
	srand(time(NULL));

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G2);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	//smithy = line 831
	printf("TEST: +3 cards\n"); 
	discarded = 1;

		
	int before_handCount;
	int before_discardCount;
	int before_deckCount;
	int after_handCount;
	int after_discardCount;
	int after_deckCount;
	// copy the game state to a test case
	memcpy(&testG2, &G2, sizeof(struct gameState));
	//Add smithy to hand
	printf("Add smity Cards to user decks; ");
	for(int x = 0; x < 4; x++)
	{
		printf("handcount = %d", testG2.handCount[x]);
		testG2.hand[x][testG2.handCount[x]] = smithy;
		testG2.handCount[x]++;
	}
	
	//run for 25 tests
	for (int x = 0; x < 25; x++)
	{
		//random tests
		thisPlayer = rand() % 4; //random player
		choice1 = rand() % 4; //random choice1 - no effect
		choice2 = rand() % 4; //random choice2 - no effect
		choice3 = rand() % 4; //random choice3 - no effect
		bonus = rand() % 4; //random bonus - no effect
		testG2.whoseTurn = thisPlayer;
		handpos = testG2.handCount[thisPlayer]+1; 
		
		printf("\nStart: Player Turn: %d; ", thisPlayer);
		printf("handcount: %d; ", testG2.handCount[thisPlayer]);
		printf("handpos: %d; ", handpos);
		printf("\nBefore:");

		for(int x = 0; x<testG2.handCount[thisPlayer]; x++ )
		{
			printf("card=%d; ", testG2.hand[thisPlayer][x]);

		}
		
		before_handCount = testG2.handCount[thisPlayer];
		before_discardCount = testG2.discardCount[thisPlayer];
		before_deckCount = testG2.deckCount[thisPlayer];
		
		if (before_deckCount > 3)
			newCards = 3;
		else
			newCards = before_deckCount;
		
		//test smithy
		cardEffect(smithy, choice1, choice2, choice3, &testG2, handpos, &bonus);
		
		after_handCount = testG2.handCount[thisPlayer];
		after_discardCount = testG2.discardCount[thisPlayer]; 
		after_deckCount = testG2.deckCount[thisPlayer];
		printf("\nAfter:");

		for(int x = 0; x<testG2.handCount[thisPlayer]; x++ )
		{
			printf("card=%d; ", testG2.hand[thisPlayer][x]);
		}
		printf("\nnewCards=%d", newCards);
		printf("\nhand count before=%d; hand count after=%d; expected=%d ", before_handCount, after_handCount, before_handCount + newCards - discarded);
		if(after_handCount == (before_handCount + newCards - discarded))
			printf("PASSED\n");
		else
			printf("FAILED\n");

	}

	return 0;
}