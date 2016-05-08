/*********************************************************************************************
 * Developer: Nick Martin (martinn6)
 * Date: 20160506
 * Project: Assignement 4
 * Description: Random testing - adventurer
 * *******************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main() {
    int newCards = 0;
	int discarded = 0;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
			
	srand(time(NULL));

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	//smithy = line 831
	printf("TEST: +2 treasure cards\n"); 
	//newCards = 2;
	discarded = 0;
	int before_HandTreasureCount = 0,
		after_HandTreasureCount = 0,
		before_deckTreasureCount = 0,
		after_deckTreasureCount = 0;
		
	for(int p = 1; p < 4; p++)
	{
		for (int j = 0; j < 3; j++)
		{
			G.deck[p][j] = copper;
			G.deckCount[p]++;	
		}
	}
	int before_handCount;
	int before_discardCount;
	int before_deckCount;
	int after_handCount;
	int after_discardCount;
	int after_deckCount;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	//Add adventurer to hand
	printf("Add Adventure Cards to user decks; ");
	for(int x = 0; x < 4; x++)
	{
		testG.hand[x][testG.handCount[x]] = adventurer;
		testG.handCount[x]++;
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
		testG.whoseTurn = thisPlayer;
		handpos = testG.handCount[thisPlayer]+1; 
		before_deckTreasureCount = 0;
		for(int x = 0; x<testG.deckCount[thisPlayer]; x++ )
		{
			
			//printf("deckcard=%d; ", testG.deck[thisPlayer][x]);
			if(testG.deck[thisPlayer][x] == 4 || testG.deck[thisPlayer][x] == 5 || testG.deck[thisPlayer][x] == 6)
				before_deckTreasureCount++;
		}
		
		if (before_deckTreasureCount > 2)
			newCards = 2;
		else
			newCards = before_deckTreasureCount;
		
		printf("\nStart: Player Turn: %d; ", thisPlayer);
		printf("handcount: %d; ", testG.handCount[thisPlayer]);
		printf("before_deckTreasureCount=%d; ", before_deckTreasureCount);

		
		printf("handpos: %d; ", handpos);
		printf("\nBefore:");
		before_HandTreasureCount = 0;
		for(int x = 0; x<testG.handCount[thisPlayer]; x++ )
		{
			printf("card=%d; ", testG.hand[thisPlayer][x]);
			if(testG.hand[thisPlayer][x] == 4 || testG.hand[thisPlayer][x] == 5 || testG.hand[thisPlayer][x] == 6)
				before_HandTreasureCount++;
		}
		
		before_handCount = testG.handCount[thisPlayer];
		before_discardCount = testG.discardCount[thisPlayer];
		before_deckCount = testG.deckCount[thisPlayer];
		
		//test
		cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
		
		after_handCount = testG.handCount[thisPlayer];
		after_discardCount = testG.discardCount[thisPlayer]; 
		after_deckCount = testG.deckCount[thisPlayer];
		printf("\nAfter:");
		after_HandTreasureCount = 0;
		for(int x = 0; x<testG.handCount[thisPlayer]; x++ )
		{
			printf("card=%d; ", testG.hand[thisPlayer][x]);
			if(testG.hand[thisPlayer][x] == 4 || testG.hand[thisPlayer][x] == 5 || testG.hand[thisPlayer][x] == 6)
				after_HandTreasureCount++;
		}
		printf("newCards=%d", newCards);
		printf("\nhand count before=%d; hand count after=%d; expected=%d ", before_handCount, after_handCount, before_handCount + newCards);
		if(after_handCount == (before_handCount + newCards))
			printf("PASSED\n");
		else
			printf("FAILED\n");
		
		printf("treaure card count before =%d; treaure card count after=%d; expected=%d ", before_HandTreasureCount, 
			after_HandTreasureCount, before_HandTreasureCount + newCards);
		if(after_HandTreasureCount == (before_HandTreasureCount + newCards))
			printf("PASSED\n");
		else
			printf("FAILED\n");
	}

	return 0;
}