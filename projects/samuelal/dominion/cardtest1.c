/*
Alex Samuel
Assignment 3
cardtest1.c
Tests for smithy card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

int main() {
    int newCards = 3;
    int discarded = 1;
    int numPlayers = 2;
    int PlayerID = 0;
    int seed = 638;
    int i;
    int errorFlag = 0;
	struct gameState G, testG;

    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy, council_room};

	printf("TEST 1: Testing smithy - +3 Cards Added to Player's Hand\n");

	//Initializes game and copies game state to test case
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("Player hand count = %d, expected hand count= %d\n", testG.handCount[PlayerID], G.handCount[PlayerID] + newCards - discarded);

    //printf("\n%d,%d, %d, %d\n", testG.handCount[PlayerID], testG.deckCount[PlayerID], testG.discardCount[PlayerID], testG.playedCardCount);

	if (testG.handCount[PlayerID] != (G.handCount[PlayerID] + newCards - discarded)) {
        printf("TEST 1 HAS FAILED\n\n");
        errorFlag = 1;
     }

    //Test will fail due to bug introduced in earlier assignment, see refactor.c

    printf("TEST 2: Player 2 Is Unaffected by Player 1 Playing Smithy\n");
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

    printf("Player 2 Deck Totals Before Smithy Was Played By Player 1\n");
    for (i = 0; i < 27; i++) {
        printf ("%d ", GDeckResults[i]);
    }

    printf("\n\n");

    printf("Player 2 Deck Totals After Smithy Was Played By Player 1\n");
    for (i = 0; i < 27; i++) {
        printf ("%d ", testGDeckResults[i]);
    }

    printf("\n\n");

    printf("Player 2 Hand Totals Before Smithy Was Played By Player 1\n");
    for (i = 0; i < 27; i++) {
        printf ("%d ", GHandResults[i]);
    }

    printf("\n\n");

    printf("Player 2 Hand Totals After Smithy Was Played By Player 1\n");
    for (i = 0; i < 27; i++) {
        printf ("%d ", testGHandResults[i]);
    }

    //no difference in hand totals because hands are only drawn at start if turn,
    //see dominion.c, line 197

    //Compares whether any change to Player 2 hand or deck
    if (memcmp(GDeckResults, testGDeckResults, sizeof(GDeckResults)) == 0 &&
        memcmp(GHandResults, testGHandResults, sizeof(GHandResults)) == 0 ) {
            printf("\n\nTEST 2 HAS PASSED");
    }


    if (errorFlag == 0) {
        printf("ALL TESTS PASSED");
    }

    return 0;
}
