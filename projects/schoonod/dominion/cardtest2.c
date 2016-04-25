#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Dane Schoonover
// Assignment 3
// adventurerCard() test

// This file tests the adventurerCard() card effect.

// What to test:
    // check that player has 2 more cards (handCount)
    // check that the 2 new cards are treasure cards;check against copper/silver...
    // check that the players draw pile has reduced by at least 2 cards (deckcount - 2)

int main (int argc, char** argv) {
    printf ("---------- Testing adventurerCard() ----------\n");
    int initialHandCount, initialDeckCount, z, cardDrawn;
    int drawnTreasure = 0;
    int temphand[MAX_HAND];
    int handPos = 0;
    
    // Create a game
    int numPlayers = 2;
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '10'
    initializeGame(numPlayers, k, 10, &G);

    // Get before metrics:
    initialHandCount = G.handCount[G.whoseTurn];
    initialDeckCount = G.deckCount[G.whoseTurn];
    
    // Default current player
    G.whoseTurn = 0;
    
    // Set Adventurer card to handPos
    G.hand[G.whoseTurn][handPos] = adventurer;
    
    // Play the card
    adventurerCard(drawnTreasure, &G, G.whoseTurn, z, temphand, cardDrawn);
    
    // TEST 1
    // Check that handCount has 2 additional cards
    if (G.handCount[G.whoseTurn] == initialHandCount + 2)
        printf ("adventurerCard() test1: passed.\n");
    else
        printf ("adventurerCard() test1: failed.\n");
    
    // TEST 2:
    // Check that all drawn cards are treasure cards
    for (int i = 0; i < 2; i++){
        if (G.hand[G.whoseTurn][G.handCount[G.whoseTurn] - 1 - i] == copper ||
            G.hand[G.whoseTurn][G.handCount[G.whoseTurn] - 1 - i] == silver ||
            G.hand[G.whoseTurn][G.handCount[G.whoseTurn] - 1 - i] == gold)
            printf ("adventurerCard() card%i test2: passed.\n", i+1);
        else
            printf ("adventurerCard() card%i test2: failed.\n", i+1);
    }
    
    // TEST 3
    // Check that the deckcount decreased by at least 2
    if (G.deckCount[G.whoseTurn] <= (initialDeckCount - 2))
        printf ("adventurerCard() test3: passed.\n");
    else
        printf ("adventurerCard() test3: failed.\n");
    
    return 0;
}