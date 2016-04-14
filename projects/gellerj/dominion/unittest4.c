#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"

#define VERBOSE 1

int main() {
    struct gameState G;
    int players = 2;
    int seed = 1;
    int gameOver = 0;
    int tempDeck[MAX_DECK];
    int tempDeckPos = 0;
    int i;
    int sameCardCount = 0;
    int kingdomCards[10] = {
            adventurer,
            gardens,
            embargo, village,
            minion, mine,
            cutpurse,
            sea_hag,
            tribute,
            smithy
    };

    initializeGame(players, kingdomCards, seed, &G);

    // make a copy of the deck so we can test that it is shuffled
    for (i = 0; i < G.deckCount[0]; i++) {
        tempDeck[i] = G.deck[0][i];
    }

    printf("Testing shuffle():\n\n");

    if (VERBOSE)
        printf("Test player 0's deck is shuffled...\n\n");

    if (VERBOSE)
        printf("Player 0's deck before shuffle:\n");
        printDeck(0, &G);

    shuffle(0, &G);

    if (VERBOSE)
        printf("Player 0's deck after shuffle:\n");
        printDeck(0, &G);

    for (i = 0; i < G.deckCount[0]; i++) {
        if (G.deck[0][i] == tempDeck[i]) {
            sameCardCount++;
        }
    }

    if (VERBOSE)
        printf("Number of cards in same position = %d, expected != %d:\n", sameCardCount, G.deckCount[0]);

    assert(sameCardCount != G.deckCount[0]);


    printf("\nAll tests passed.");
}