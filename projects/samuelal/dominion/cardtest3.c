/*
Alex Samuel
Assignment 3
cardtest3.c
Tests for village card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

int main() {

    int newCards = 1;
    int discarded = 1;
    int numPlayers = 2;
    int PlayerID = 0;
    int seed = 45;
    int i;
    int errorFlag = 0;
	struct gameState G, testG;

    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy, council_room};

	printf("TEST 1: Testing Village - +1 Card Added to Player's Hand, 1 Discarded\n");

	//Initializes game and copies game state to test case
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("Player hand count = %d, expected hand count= %d\n", testG.handCount[PlayerID], G.handCount[PlayerID] + newCards - discarded);

    if (testG.handCount[PlayerID] != (G.handCount[PlayerID] + newCards - discarded)) {
        printf("TEST 1 HAS FAILED\n\n");
        errorFlag = 1;
     }
     else {
        printf("TEST 1 HAS PASSED\n\n");
     }

    printf("TEST 2: Testing Village - +2 Actions Added to Player 1\n");

    int newActions = 2;

	printf("Player 1 Action Count = %d, Expected Action Count= %d\n", testG.numActions, G.numActions + newActions);

    if (testG.numActions != (G.numActions + newActions)) {
        printf("TEST 2 HAS FAILED\n\n");
        errorFlag = 1;
     }
     else {
        printf("TEST 2 HAS PASSED\n\n");
     }

    printf("TEST 3: Testing Village - 1 Card Is Drawn From Player 1's Deck\n");
        int g0DeckResults[27] = { 0 };
        int testg0DeckResults[27] = { 0 };
        int cardVal;

        for (i = 0; i < G.deckCount[PlayerID]; i++) {
            cardVal = G.deck[PlayerID][i];
            g0DeckResults[cardVal]++;
        }

        for (i = 0; i < testG.deckCount[PlayerID]; i++) {
            cardVal = testG.deck[PlayerID][i];
            testg0DeckResults[cardVal]++;
        }

        printf("Player 1 Deck Totals Before Village Was Played By Player 1\n");
        for (i = 0; i < 27; i++) {
            printf ("%d ", g0DeckResults[i]);
        }

        printf("\n\n");

        printf("Player 1 Deck Totals After Village Was Played By Player 1\n");
        for (i = 0; i < 27; i++) {
            printf ("%d ", testg0DeckResults[i]);
        }

        int totalCardsDeckG = 0;
        int totalCardsDecktestG = 0;

        for (i = 0; i < 27; i++) {
            totalCardsDeckG = totalCardsDeckG + g0DeckResults[i];
            totalCardsDecktestG = totalCardsDecktestG + testg0DeckResults[i];
        }

        if (totalCardsDecktestG == (totalCardsDeckG - 1)) {
            printf("\n\nTEST 3 HAS PASSED\n\n");
        }
        else {
            printf("\n\nTEST 3 HAS FAILED\n\n");
            errorFlag = 1;
        }



    printf("TEST 4: Testing Village - Player 2 Cards Are Unaffected by Player 1\n");
    PlayerID = 1;
	int G1DeckResults[27] = { 0 };
	int testG1DeckResults[27] = { 0 };
    int G1HandResults[27] = { 0 };
	int testG1HandResults[27] = { 0 };

    for (i = 0; i < G.deckCount[PlayerID]; i++) {
        cardVal = G.deck[PlayerID][i];
        G1DeckResults[cardVal]++;
    }

    for (i = 0; i < G.handCount[PlayerID]; i++) {
        cardVal = G.hand[PlayerID][i];
        G1HandResults[cardVal]++;
    }

    for (i = 0; i < testG.deckCount[PlayerID]; i++) {
        cardVal = testG.deck[PlayerID][i];
        testG1DeckResults[cardVal]++;
    }

    for (i = 0; i < testG.handCount[PlayerID]; i++) {
        cardVal = testG.hand[PlayerID][i];
        testG1HandResults[cardVal]++;
    }

    printf("Player 2 Deck Totals Before Village Was Played By Player 1\n");
    for (i = 0; i < 27; i++) {
        printf ("%d ", G1DeckResults[i]);
    }

    printf("\n\n");

    printf("Player 2 Deck Totals After Village Was Played By Player 1\n");
    for (i = 0; i < 27; i++) {
        printf ("%d ", testG1DeckResults[i]);
    }

    printf("\n\n");

    printf("Player 2 Hand Totals Before Village Was Played By Player 1\n");
    for (i = 0; i < 27; i++) {
        printf ("%d ", G1HandResults[i]);
    }

    printf("\n\n");

    printf("Player 2 Hand Totals After Village Was Played By Player 1\n");
    for (i = 0; i < 27; i++) {
        printf ("%d ", testG1HandResults[i]);
    }

    //no difference in hand totals because hands are only drawn at start if turn,
    //see dominion.c, line 197

    //Compares whether any change to Player 2 hand or deck
    if (memcmp(G1DeckResults, testG1DeckResults, sizeof(G1DeckResults)) == 0 &&
        memcmp(G1HandResults, testG1HandResults, sizeof(G1HandResults)) == 0 ) {
            printf("\n\nTEST 4 HAS PASSED\n\n");
    }
    else {
        printf("\n\nTEST 4 HAS FAILED\n\n");
        errorFlag = 1;
    }

    if (errorFlag == 0) {
        printf("ALL TESTS PASSED");
    }

    return 0;
}
