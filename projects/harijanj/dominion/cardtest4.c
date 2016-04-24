/*
 * cardtest1.c
 *
 
 */

/*
 * Using cardtest4.c template.
 * -------------------------------------------
 * TESTCARD #4: Council Room.
 *--------------------------------------------
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "council_room"

int main() {
    int newCards = 0;
    int newBuy = 0;
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

1. Current player should receive exactly 4 cards & deck --> Check hand card

2. Current player should receive exactly 1 buy --> Check action

3. Other player should receive 1 card --> Check other's hand and deck

4. No state change should occur to the victory card piles and kingdom card piles. --> Check victory & kingdom.
*/

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &originalG);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// -----------------------------------------------------------------------
	printf("\nTEST 1: Check current player's hand card.\n");

	memcpy(&testingG, &originalG, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testingG, handpos, &bonus);
	
	newCards = 4;
	printf("Hand count = %d, expected = %d\n", testingG.handCount[thisPlayer], originalG.handCount[thisPlayer] + newCards - discarded);
	if (testingG.handCount[thisPlayer] == originalG.handCount[thisPlayer] + newCards - discarded) {
		printf ("Test 1 Passed: +4 cards.\n");
      	successFlag += 1;
    }
    else {
      printf ("Test 1 Failed: More / Less than 4 cards.\n");
    }

	// -----------------------------------------------------------------------
	printf("\nTEST 2: Check current player's buy.\n");

	memcpy(&testingG, &originalG, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testingG, handpos, &bonus);
	
	newBuy = 1;
	printf("Player's buy = %d, expected = %d\n", testingG.numBuys, originalG.numBuys + newBuy);
	if (testingG.numBuys == originalG.numBuys + newBuy) {
		printf ("Test 2 Passed: + 1 buy.\n");
      	successFlag += 1;
    }
    else {
      printf ("Test 2 Failed: More / Less than 1 buy.\n");
    }

	// -----------------------------------------------------------------------
	printf("\nTEST 3: Check OTHER player's hand card & deck. \n");

	memcpy(&testingG, &originalG, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testingG, handpos, &bonus);
	
	// "thatPlayer" still has 0 card in hand since it is not endTurn yet.
	// Thus, need to add +5 cards manually to "thatPlayer" hand & (-5) cards from deck.
	// so can be tested at that round whether "village" works or not.
	newCards = 5;
	printf("Other Hand count = %d, expected = %d\n", testingG.handCount[thatPlayer] + newCards, originalG.handCount[thisPlayer] + 1);
	printf("Other Deck count = %d, expected = %d\n", testingG.deckCount[thatPlayer] - newCards, originalG.deckCount[thisPlayer] - 1);
	if (((testingG.handCount[thatPlayer] + newCards) == originalG.handCount[thisPlayer] + 1) && ((testingG.deckCount[thatPlayer] - newCards) == (originalG.deckCount[thisPlayer] - 1))) {
		printf ("Test 3 Passed: Other player's state changes +1 card TO hand.\n");
      	successFlag += 1;
    }
    else {
      printf ("Test 3 Failed: Other player's state doesn't change +1 card TO hand.\n");
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

