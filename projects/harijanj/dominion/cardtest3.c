/*
 * cardtest1.c
 *
 
 */

/*
 * Using cardtest4.c template.
 * -------------------------------------------
 * TESTCARD #3: Village.
 *--------------------------------------------
 * cardtest3: cardtest3.c dominion.o rngs.o
 *      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

int main() {
    int newCards = 0;
    int newActions = 0;
    int discarded = 1;
    int cardTemp = 0;
    int i;
    int equal;
    int successFlag = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int thatPlayer = 1;
	struct gameState originalG, testingG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

/*
What I'm going to test:

1. Current player should receive exactly 1 cards --> Check hand card

2. Current player should receive exactly 2 actions --> Check action

3. Other player should NOT receive 1 card --> Check other hand

4. No state change should occur to the victory card piles and kingdom card piles. --> Check victory & kingdom.
*/

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &originalG);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// -----------------------------------------------------------------------
	printf("\nTEST 1: Check current player's hand card.\n");

	memcpy(&testingG, &originalG, sizeof(struct gameState));
	cardEffect(village, choice1, choice2, choice3, &testingG, handpos, &bonus);
	
	newCards = 1;
	printf("Hand count = %d, expected = %d\n", testingG.handCount[thisPlayer], originalG.handCount[thisPlayer] + newCards - discarded);
	if (testingG.handCount[thisPlayer] == originalG.handCount[thisPlayer] + newCards - discarded) {
		printf ("Test 1 Passed: + 1 card.\n");
      	successFlag += 1;
    }
    else {
      printf ("Test 1 Failed: More / Less than 1 card.\n");
    }

	// -----------------------------------------------------------------------
	printf("\nTEST 2: Check current player's action.\n");

	memcpy(&testingG, &originalG, sizeof(struct gameState));
	cardEffect(village, choice1, choice2, choice3, &testingG, handpos, &bonus);
	
	newActions = 2;
	printf("Player's action = %d, expected = %d\n", testingG.numActions, originalG.numActions + newActions);
	if (testingG.numActions == originalG.numActions + 2) {
		printf ("Test 2 Passed: + 2 actions.\n");
      	successFlag += 1;
    }
    else {
      printf ("Test 2 Failed: More / Less than 2 actions.\n");
    }

	// -----------------------------------------------------------------------
	printf("\nTEST 3: Check OTHER player's hand card. \n");

	memcpy(&testingG, &originalG, sizeof(struct gameState));
	cardEffect(village, choice1, choice2, choice3, &testingG, handpos, &bonus);

	// "thatPlayer" still has 0 card in hand since it is not endTurn yet.
	// Thus, need to add +5 cards manually to "thatPlayer" hand & (-5) cards from deck.
	// so can be tested at that round whether "village" works or not.
	newCards = 5;
	printf("Other Hand count = %d, expected = %d\n", testingG.handCount[thatPlayer] + newCards, originalG.handCount[thisPlayer]);
	if (testingG.handCount[thatPlayer] + newCards == originalG.handCount[thisPlayer]) {
		printf ("Test 3 Passed: Other player's state doesn't change.\n");
      	successFlag += 1;
    }
    else {
      printf ("Test 3 Failed: Other player's state changes.\n");
    }

	// -----------------------------------------------------------------------
	printf("\nTEST 4: Check Victory piles.\n");
	
	memcpy(&testingG, &originalG, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testingG, handpos, &bonus);
	
	if (testingG.supplyCount[copper] == originalG.supplyCount[copper]) {
		equal++;
	}
	if (testingG.supplyCount[silver] == originalG.supplyCount[silver]) {
		equal++;
	}
	if (testingG.supplyCount[gold] == originalG.supplyCount[gold]) {
		equal++;
	}

	if (equal == 3) {
		printf ("Test 4 Passed: Victory piles NO CHANGE.\n");
      	successFlag += 1;
    }
    else {
      printf ("Test 4 Failed: Victory piles CHANGE.\n");
    }

    // -----------------------------------------------------------------------
	printf("\nTEST 5: Check Kingdom piles.\n");
	
	memcpy(&testingG, &originalG, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testingG, handpos, &bonus);
	
	equal = 0;
    for (i = 0; i < 10; i++) {
    	cardTemp = k[i];
        if (testingG.supplyCount[cardTemp] == originalG.supplyCount[cardTemp]) {
            equal++;
        }
    }

	if (equal == 10) {
		printf ("Test 5 Passed: Kingdom piles NO CHANGE.\n");
      	successFlag += 1;
    }
    else {
      printf ("Test 5 Failed: Kingdom piles CHANGE.\n");
    }

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}

