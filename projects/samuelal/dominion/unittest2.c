/*
Alex Samuel
Assignment 3
unittest2.c
Tests fullDeckCount() function
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {

    int numPlayers = 2;
    int PlayerID = 0;
    int seed = 2;
    int i;
	struct gameState G, testG;

	int manualCountResults[27] = { 0 };
	int fdcResults[27] = { 0 };
    int cardVal;
    int cardTotal;

    SelectStream(4);
    PutSeed(5);

	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

    printf ("TEST 1: Testing fullDeckCount() - Normal Card Distribution\n");

    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    for (i = 0; i < testG.handCount[PlayerID]; i++) {
        cardVal = testG.hand[PlayerID][i];
        manualCountResults[cardVal]++;
    }

    for (i = 0; i < testG.deckCount[PlayerID]; i++) {
        cardVal = testG.deck[PlayerID][i];
        manualCountResults[cardVal]++;
    }

    for (i = 0; i < testG.discardCount[PlayerID]; i++) {
        cardVal = testG.discard[PlayerID][i];
        manualCountResults[cardVal]++;
    }

    for (i = 0; i < 27; i++) {
        cardTotal = fullDeckCount(PlayerID, i, &G);
        fdcResults[i] = cardTotal;
    }

    printf("TOTALS\n\n");

    for (i = 0; i < 27; i++) {
        printf ("%d ", manualCountResults[i]);
    }

    printf("\n\n");

    for (i = 0; i < 27; i++) {
        printf ("%d ", fdcResults[i]);
    }

    if (memcmp(manualCountResults, fdcResults, sizeof(fdcResults)) == 0) {
            printf("\n\nTEST 1 COMPLETED SUCCESSFULLY");
    }

    printf ("\n\nTEST 2: Testing fullDeckCount() - Random Card Distribution\n");

    // array containing all 27 card possibilities
    int cards[] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens,
    mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost,
    salvager, sea_hag, treasure_map};

    memset(&G, 23, sizeof(struct gameState));
    memset(&testG, 23, sizeof(struct gameState));
    memset(manualCountResults, 0, sizeof manualCountResults);
    memset(fdcResults, 0, sizeof fdcResults);

    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    G.handCount[PlayerID] = MAX_HAND;
    G.deckCount[PlayerID] = MAX_DECK;
    G.discardCount[PlayerID] = MAX_DECK;
    int cardIndex;

    for (i = 0; i < G.handCount[PlayerID]; i++) {
        cardIndex = floor(Random() * 27); //generates a random value between 0 and 27
        G.hand[PlayerID][i] = cards[cardIndex]; //randomly assigns a card to the hand
    }

    for (i = 0; i < G.deckCount[PlayerID]; i++) {
        cardIndex = floor(Random() * 27);
        G.deck[PlayerID][i] = cards[cardIndex];
    }

    for (i = 0; i < G.discardCount[PlayerID]; i++) {
        cardIndex = floor(Random() * 27);
        G.discard[PlayerID][i] = cards[cardIndex];
    }


    for (i = 0; i < G.handCount[PlayerID]; i++) {
        cardVal = G.hand[PlayerID][i];
        manualCountResults[cardVal]++;
    }

    for (i = 0; i < G.deckCount[PlayerID]; i++) {
        cardVal = G.deck[PlayerID][i];
        manualCountResults[cardVal]++;
    }

    for (i = 0; i < G.discardCount[PlayerID]; i++) {
        cardVal = G.discard[PlayerID][i];
        manualCountResults[cardVal]++;
    }

    for (i = 0; i < 27; i++) {
        cardTotal = fullDeckCount(PlayerID, i, &G);
        fdcResults[i] = cardTotal;
    }

    printf("TOTALS\n\n");

    for (i = 0; i < 27; i++) {
        printf ("%d ", manualCountResults[i]);
    }

    printf("\n\n");

    for (i = 0; i < 27; i++) {
        printf ("%d ", fdcResults[i]);
    }

    if (memcmp(manualCountResults, fdcResults, sizeof(fdcResults)) == 0) {
            printf("\n\nTEST 2 COMPLETED SUCCESSFULLY");
    }

    return 0;
}
