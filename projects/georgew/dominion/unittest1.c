//gainCard function
//unittest1.c
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "interface.h"

#define FUNCTION "gainCard"

int main() {
	int numPlayers = 2;
	int thisPlayer = 0;
	int seed = 1000;
	int supplyPos;
	int toFlag = 0;
	struct gameState G, testG;
	int currDeckCount, currHandCount, currDiscardCount, currSupplyCount;
	int k[10] = {curse, estate, village, remodel, 
		council_room, adventurer, province, smithy, steward, tribute};
	//initialize game, state and player cards
	initializeGame(numPlayers, k, seed, &G);
	printf("\n\n\n\n----------------- Testing Function: %s ----------------\n", FUNCTION);
	printf("\n-------------Saving Starting Game State----------------\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	//output supply
	printSupply(&testG);
	printf("\n------------TEST 1: Testing if Card isn't in game-------------\n");
	supplyPos = -1;
	if(gainCard(supplyPos, &testG, toFlag, thisPlayer) == -1)
		printf("RETURNED ERROR FOR CARD NOT IN GAME: SUCCESS\n");
	printf("\n-------------TEST 2: Testing when toFlag == 1...................\n");
	//revert to starting game state
	memcpy(&G, &testG, sizeof(struct gameState));
	//set to flag
	toFlag = 1;
	//set supply pos
	supplyPos = 1;
	//get starting counts
	currDeckCount = testG.deckCount[thisPlayer];
	currHandCount = testG.handCount[thisPlayer];
	currDiscardCount = testG.discardCount[thisPlayer];
	currSupplyCount = testG.supplyCount[supplyPos];
	printf("Current deck count: %d\n", testG.deckCount[thisPlayer]);
	printf("Current hand count: %d\n", testG.handCount[thisPlayer]);
	printf("Current discard count: %d\n", testG.discardCount[thisPlayer]);
	printf("Current Supply Count: %d\n", testG.supplyCount[supplyPos]);
	//run function
	gainCard(supplyPos, &testG, toFlag, thisPlayer);
	//output counts
	printf("Final deck count: %d\n", testG.deckCount[thisPlayer]);
	printf("Final hand count: %d\n", testG.handCount[thisPlayer]);
	printf("Final discard count: %d\n", testG.discardCount[thisPlayer]);	
	printf("Final Supply Count: %d\n", testG.supplyCount[supplyPos]);
	//output failure/success statements
	printf("DECK\n");
	if ((currDeckCount + 1) == testG.deckCount[thisPlayer])
		printf("Card Added to Deck: SUCCESS\n");
	else if (currDeckCount == testG.deckCount[thisPlayer])
		printf("Card Not Added to Deck: FAILURE\n");
	else
		printf("Too Many or Too Few Cards Added: FAILURE\n");
	
	printf("HAND\n");
	if ((currHandCount) == testG.handCount[thisPlayer])
		printf("No Cards Added to Hand: SUCCESS\n");
	else
		printf("Too Many or Too Few Cards Added: FAILURE\n");
	
	printf("DISCARD\n");
	if ((currDiscardCount + 1) == testG.discardCount[thisPlayer])
		printf("No Cards Added to Discard: SUCCESS\n");
	else
		printf("Too Many or Too Few Cards Added: FAILURE\n");
	
	printf("SUPPLY\n");
	if ((currSupplyCount - 1) == testG.supplyCount[supplyPos])
		printf("Card Taken From Supply: SUCCESS\n");
	else if (currSupplyCount == testG.supplyCount[supplyPos])
		printf("Card Not taken from Supply: FAILURE\n");
	else
		printf("Too Many or Too Few Cards Added: FAILURE\n");
	
	printf("\n-------------Testing when toFlag == 2...................\n");
	//revert to starting game state
	memcpy(&G, &testG, sizeof(struct gameState));
	//set flag to 2
	toFlag = 2;
	supplyPos = 1;
	//set starting counts
	currDeckCount = testG.deckCount[thisPlayer];
	currHandCount = testG.handCount[thisPlayer];
	currDiscardCount = testG.discardCount[thisPlayer];
	currSupplyCount = testG.supplyCount[supplyPos];
	//output starting counts
	printf("Current deck count: %d\n", testG.deckCount[thisPlayer]);
	printf("Current hand count: %d\n", testG.handCount[thisPlayer]);
	printf("Current discard count: %d\n", testG.discardCount[thisPlayer]);
	printf("Current Supply Count: %d\n", testG.supplyCount[supplyPos]);
	//run function
	gainCard(supplyPos, &testG, toFlag, thisPlayer);
	//get counts post function 
	printf("Final deck count: %d\n", testG.deckCount[thisPlayer]);
	printf("Final hand count: %d\n", testG.handCount[thisPlayer]);
	printf("Final discard count: %d\n", testG.discardCount[thisPlayer]);
	printf("Final Supply Count: %d\n", testG.supplyCount[supplyPos]);
	//output the statements 
	printf("DECK\n");
	if ((currDeckCount) == testG.deckCount[thisPlayer])
		printf("Card Not Added to Deck: SUCCESS\n");
	else
		printf("Too Many or Too Few Cards Added: FAILURE\n");
	
	printf("HAND\n");
	if ((currHandCount + 1) == testG.handCount[thisPlayer])
		printf("Card Added to Hand: SUCCESS\n");
	else if (currHandCount == testG.handCount[thisPlayer])
		printf("Card Not Added to Deck: FAILURE\n");
	else
		printf("Too Many or Too Few Cards Added: FAILURE\n");
	
	printf("DISCARD\n");
	if ((currDiscardCount) == testG.discardCount[thisPlayer])
		printf("Card Not Added to Discard: SUCCESS\n");
	else
		printf("Too Many or Too Few Cards Added: FAILURE\n");
	
	printf("SUPPLY\n");
	if ((currSupplyCount - 1) == testG.supplyCount[supplyPos])
		printf("Card Taken From Supply: SUCCESS\n");
	else if (currSupplyCount == testG.supplyCount[supplyPos])
		printf("Card Not taken from Supply: FAILURE\n");
	else
		printf("Too Many or Too Few Cards Added: FAILURE\n");

	printf("\n-------------Testing when toFlag == 0...................\n");
	//revert to starting game state
	memcpy(&G, &testG, sizeof(struct gameState));
	//set flag to zero
	toFlag = 0;
	supplyPos = 1;
	//get starting counts
	currDeckCount = testG.deckCount[thisPlayer];
	currHandCount = testG.handCount[thisPlayer];
	currDiscardCount = testG.discardCount[thisPlayer];
	currSupplyCount = testG.supplyCount[supplyPos];
	//output starting counts
	printf("Current deck count: %d\n", testG.deckCount[thisPlayer]);
	printf("Current hand count: %d\n", testG.handCount[thisPlayer]);
	printf("Current discard count: %d\n", testG.discardCount[thisPlayer]);
	printf("Current Supply Count: %d\n", testG.supplyCount[supplyPos]);
	//run function
	gainCard(supplyPos, &testG, toFlag, thisPlayer);
	//output results
	printf("Final deck count: %d\n", testG.deckCount[thisPlayer]);
	printf("Final hand count: %d\n", testG.handCount[thisPlayer]);
	printf("Final discard count: %d\n", testG.discardCount[thisPlayer]);
	printf("Final Supply Count: %d\n", testG.supplyCount[supplyPos]);
	//output success/failure
	printf("DECK\n");
	if ((currDeckCount) == testG.deckCount[thisPlayer])
		printf("Card Not Added to Deck: SUCCESS\n");
	else
		printf("Too Many or Too Few Cards Added: FAILURE\n");

	printf("HAND\n");
	if ((currHandCount) == testG.handCount[thisPlayer])
		printf("No Cards Added to Hand: SUCCESS\n");
	else
		printf("Too Many or Too Few Cards Added: FAILURE\n");
	
	printf("DISCARD\n");
	if ((currDiscardCount + 1) == testG.discardCount[thisPlayer])
		printf("Card Added to Discard: SUCCESS\n");
	else if (currDiscardCount == testG.discardCount[thisPlayer])
		printf("Card Not Added to Discard: FAILURE\n");
	else
		printf("Too Many or Too Few Cards Added: FAILURE\n");
	
	printf("SUPPLY\n");
	if ((currSupplyCount - 1) == testG.supplyCount[supplyPos])
		printf("Card Taken From Supply: SUCCESS\n");
	else if (currSupplyCount == testG.supplyCount[supplyPos])
		printf("Card Not taken from Supply: FAILURE\n");
	else
		printf("Too Many or Too Few Cards Added: FAILURE\n");
	//revert to starting game state
	memcpy(&G, &testG, sizeof(struct gameState));
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n\n\n", FUNCTION);
	return 0;
}
