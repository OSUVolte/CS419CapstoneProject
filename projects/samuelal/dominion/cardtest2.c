/*
Alex Samuel
Assignment 3
cardtest2.c
Tests for adventurer card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

int main() {
    int newCards = 2;
    int discarded = 1;
    int numPlayers = 2;
    int PlayerID = 0;
    int seed = 326;
    int i;
    int errorFlag = 0;
	struct gameState G, testG;

    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy, council_room};

	printf("TEST 1: Testing adventurer - +2 Treasure Cards Added to Player's Hand, 1 Discarded\n");

	//Initializes game and copies game state to test case
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("Player hand count = %d, expected hand count= %d\n", testG.handCount[PlayerID], G.handCount[PlayerID] + newCards - discarded);

    //Test fails because of bug introduced in refactor.c where 3 treasure cards are added instead of 2
    //Also, as a result of a different bug, adventurer card is not discarded
    if (testG.handCount[PlayerID] != (G.handCount[PlayerID] + newCards - discarded)) {
        printf("TEST 1 HAS FAILED\n\n");
        errorFlag = 1;
     }

    printf("TEST 2: Testing adventurer - Only Treasure Cards Are Added to Player's Hand\n");

    int treasureBefore = 0;
    int treasureAfter = 0;

    for (i = 0; i < G.handCount[PlayerID]; i++) {
        if (G.hand[PlayerID][i] == copper || G.hand[PlayerID][i] == silver || G.hand[PlayerID][i] == gold) {
            treasureBefore++;
        }
    }

    for (i = 0; i < testG.handCount[PlayerID]; i++) {
        if (testG.hand[PlayerID][i] == copper || testG.hand[PlayerID][i] == silver || testG.hand[PlayerID][i] == gold) {
            treasureAfter++;
        }
    }

    printf("Treasure in hand count = %d, expected treasure in hand count= %d\n", treasureAfter, treasureBefore + newCards);

    //Test 2 fails because of bug introduced in refactor.c where 3 treasure cards are added instead of 2
    if (treasureAfter != (treasureBefore + newCards)) {
        printf("TEST 2 HAS FAILED\n\n");
        errorFlag = 1;
     }

    printf("TEST 3: Player 2 Is Unaffected by Player 1 Playing Adventurer\n");
    PlayerID = 1;
	int GDeckResults[27] = { 0 };
	int testGDeckResults[27] = { 0 };
    int GHandResults[27] = { 0 };
	int testGHandResults[27] = { 0 };
	int Deckdifference[27] = { 0 };
	int Handdifference[27] = { 0 };
    int cardVal;
    int cardTotal;

    for (i = 0; i < G.deckCount[PlayerID]; i++) {
        cardVal = G.deck[PlayerID][i];
        GDeckResults[cardVal]++;
    }

    for (i = 0; i < G.handCount[PlayerID]; i++) {
        cardVal = G.hand[PlayerID][i];
        GHandResults[cardVal]++;
    }

    for (i = 0; i < testG.deckCount[PlayerID]; i++) {
        cardVal = testG.deck[PlayerID][i];
        testGDeckResults[cardVal]++;
    }

    for (i = 0; i < testG.handCount[PlayerID]; i++) {
        cardVal = testG.hand[PlayerID][i];
        testGHandResults[cardVal]++;
    }

    printf("Player 2 Deck Totals Before Adventurer Was Played By Player 1\n");
    for (i = 0; i < 27; i++) {
        printf ("%d ", GDeckResults[i]);
    }

    printf("\n\n");

    printf("Player 2 Deck Totals After Adventurer Was Played By Player 1\n");
    for (i = 0; i < 27; i++) {
        printf ("%d ", testGDeckResults[i]);
    }

    printf("\n\n");

    printf("Player 2 Hand Totals Before Adventurer Was Played By Player 1\n");
    for (i = 0; i < 27; i++) {
        printf ("%d ", GHandResults[i]);
    }

    printf("\n\n");

    printf("Player 2 Hand Totals After Adventurer Was Played By Player 1\n");
    for (i = 0; i < 27; i++) {
        printf ("%d ", testGHandResults[i]);
    }

    //no difference in hand totals because hands are only drawn at start if turn,
    //see dominion.c, line 197

    //Compares whether any change to Player 2 hand or deck
    if (memcmp(GDeckResults, testGDeckResults, sizeof(GDeckResults)) == 0 &&
        memcmp(GHandResults, testGHandResults, sizeof(GHandResults)) == 0 ) {
            printf("\n\nTEST 3 HAS PASSED\n\n");
    }
    else {
        printf("\n\nTEST 3 HAS FAILED\n\n");
    }

    return 0;
}
