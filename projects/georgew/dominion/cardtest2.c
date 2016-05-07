//cardtest2.c
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "interface.h"

#define TESTCARD "adventurer"

int main() {
  	int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int currCard;
	int handPos = 0;
	int currDeckCount, currHandCount, currDiscardCount;
	int deckChange, handChange, discardChange;
	int tempHand[MAX_HAND];
	int treasureBefore, treasureAfter;
	int z;
	//int choice1 = 0;
	//int choice2 = 0;
	//int choice3 = 0;	
	int k[10] = {adventurer, great_hall, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	printf("Testing for: ");
	printf("1. 2 Cards Added To Hand");
	printf("2. 2 Cards Added Are Treasure Cards");
	printf("3. All Cards that are either added to Hand or Taken from deck are Accounted For");
	printf("4. If At End of Pile Add Discarded Back and Shuffle");
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("\n\n\n\n----------------- Testing Card: %s ----------------\n", TESTCARD);
	
	printf("-------TEST 1: CHECKING IF TWO CARDS WERE ADDED TO HAND--------\n");
	//copy starting game state
	memcpy(&G, &testG, sizeof(struct gameState));
	//check hand count at start
	currHandCount = testG.handCount[thisPlayer];
	printf("Current Hand Before: %d\n", testG.handCount[thisPlayer]);
	//run function
	adventurerCard(thisPlayer, &testG, tempHand);	
	//check hand count
	printf("Current Hand After: %d\n", testG.handCount[thisPlayer]);
	if ((currHandCount + 2) == testG.handCount[thisPlayer]){
		printf("HAND COUNT INCREASED BY 1: SUCCESS\n");
	}
	else if (currHandCount == testG.handCount[thisPlayer])
	{
		printf("HAND COUNT DIDN'T CHANGE: FAILURE\n");
	}
	else
		printf("HAND COUNT CHANGE INCORRECT: FAILURE\n");
	printf("--------TEST 2: CHECK IF ADDED CARDS ARE TREASURE CARDS---------\n");
	//revert to starting game state
	memcpy(&G, &testG, sizeof(struct gameState));
	currHandCount = testG.handCount[thisPlayer];
	//print hand
	//printHand(thisPlayer, &testG);
	//count treasure cards
	while(z < currHandCount){
		currCard = testG.hand[thisPlayer][z];
		if (currCard == copper || currCard == silver || currCard == gold)
	       		treasureBefore++;    
		z++;
	}
	printf("Treasure Before Function: %d\n", treasureBefore);
	//run function
	adventurerCard(thisPlayer, &testG, tempHand);
	//printHand
	//printHand(thisPlayer, &testG);
	z = 0;
	if (testG.handCount[thisPlayer] == (currHandCount + 2)) {
		while(z != testG.handCount[thisPlayer]) {
			currCard = testG.hand[thisPlayer][z];
			if (currCard == copper || currCard == silver || currCard == gold)
		       treasureAfter++;   
			z++;
		}
	}
	printf("Treasure After Function: %d\n", treasureAfter);
	if ((treasureBefore + 2) == treasureAfter)
		printf("ADDED TWO TREASURE CARDS: SUCCESS\n");
	else
		printf("ADDED INCORRECT TREASURE CARDS: FAILURE\n");
	printf("--------TEST 3: CHECK IF ALL CARDS ACCOUNTED FOR---------\n");
	//revert to starting game state
	memcpy(&G, &testG, sizeof(struct gameState));
	//count cards in each deck
	currHandCount = testG.handCount[thisPlayer];
	currDiscardCount = testG.discardCount[thisPlayer];
	currDeckCount = testG.deckCount[thisPlayer];
	printf("Deck Count Before: %d\n", testG.deckCount[thisPlayer]);
	printf("Current Hand Before: %d\n", testG.handCount[thisPlayer]);
	printf("Discard Count Before: %d\n", testG.discardCount[thisPlayer]);
	//run fxn
	adventurerCard(thisPlayer, &testG, tempHand);
	//get count after run
	printf("Deck Count After: %d\n", testG.deckCount[thisPlayer]);
	printf("Current Hand After: %d\n", testG.handCount[thisPlayer]);
	printf("Discard Count After: %d\n", testG.discardCount[thisPlayer]);
	handChange = (testG.handCount[thisPlayer]) - currHandCount;
	deckChange =  currDeckCount - (testG.deckCount[thisPlayer]);
	discardChange = (testG.discardCount[thisPlayer]) - currDiscardCount;
	//check if all cards are accounted for
	if(deckChange == (handChange + discardChange))
		printf("All Cards Accounted For: SUCCESS\n");
	else
		printf("All Cards not Accounted For: FAILURE\n");
	printf("--------------TEST 4: CHECK IF SHUFFLE OCCURS-----------------\n");
	//revert to starting game state
	memcpy(&G, &testG, sizeof(struct gameState));
	//empty deck out
	while(testG.handCount[thisPlayer] > 1)
	{
		discardCard(handPos, thisPlayer, &testG, 1);
	}
	printf("Deck Count: %d\n", testG.deckCount[thisPlayer]);
	//run function
	adventurerCard(thisPlayer, &testG, tempHand);
	printf("Deck Count: %d\n", testG.deckCount[thisPlayer]);
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n\n\n", TESTCARD);
return 0;
}
