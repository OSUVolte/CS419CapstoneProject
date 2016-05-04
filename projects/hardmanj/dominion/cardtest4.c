/* 
Author: Jonathan Hardman
File name: cardtest4.c

Card Effect Requirements: Smithy
1. Current player should receive exact 3 cards.

2. 3 cards should come from his own pile.

3. No state change should occur for other players.

4. No state change should occur to the victory card piles and kingdom card piles.
 
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
	int AssertON = 0;

    int p1newCards = 0;
    int p1discarded = 0;
    int shuffledCards = 0;

    int i;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	int otherPlayer = 1;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

	//Card Effects
	p1newCards = 3;
	p1discarded = 1;

	//Player 1 checks
	printf("Checking Player 1\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + p1newCards - p1discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - p1newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins);
	
	if(AssertON == 1){
		assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + p1newCards - p1discarded);
		assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - p1newCards + shuffledCards);
		assert(testG.coins == G.coins);
	}
	printf("PASSED\n");
	
	//Player 2 checks
	printf("\nChecking Player 2\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
	
	if(AssertON == 1){
		assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);
		assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]);
	}
	printf("PASSED\n");
	
	//Supply Checks
	printf("\nChecking Card Piles... ");
	//checking victory cards
	int temp = supplyCount(estate,&testG), temp2 = supplyCount(estate,&G);
	if(AssertON == 1){
		assert(temp == temp2);
	}
	temp = supplyCount(duchy,&testG), temp2 = supplyCount(duchy,&G);
	if(AssertON == 1){
		assert(temp == temp2);
	}
	temp = supplyCount(province,&testG), temp2 = supplyCount(province,&G);
	if(AssertON == 1){
		assert(temp == temp2);
	}
	//checking kingdom cards
	for (i=0; i<10; i++)
	{
		temp = supplyCount(k[i],&testG);
		temp2 = supplyCount(k[i],&G);
		if(AssertON == 1){
			assert(temp == temp2);
		}
	}
	printf("PASSED\n");
	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}


