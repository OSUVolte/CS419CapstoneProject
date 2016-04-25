#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Dane Schoonover
// Assignment 3
// smithyCard() test

// This file tests the smithyCard() card effect.

// What to test:
    // Adds 3 cards to the player's hand
    // Other player's hand remains unchanged
    // Check that Smithy card has been replaced by next card in hand

int main (int argc, char** argv) {
    printf ("---------- Testing smithyCard() ----------\n");
    // Create a game
    int i, handCount, otherPlayerHandCount;
    int numPlayers = 2;
    int handPos = 0;
    struct gameState G;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '10'
    initializeGame(numPlayers, k, 10, &G);
    
    
    // Get hand count for hand count for test
    handCount = G.handCount[G.whoseTurn];
    
    // Get other player's hand count for test
    otherPlayerHandCount = G.handCount[1];
    
    // Default current player
    G.whoseTurn = 0;
    
    // Set Smith card to handPos
    G.hand[G.whoseTurn][handPos] = smithy;
    
    // Play the card
    smithyCard(i, G.whoseTurn, &G, handPos);
    
    // TEST 1
    // Adds 3 cards to the player's hand
    if (G.handCount[G.whoseTurn] < (handCount + 2) || G.handCount[G.whoseTurn] > (handCount + 2))
        printf ("smithyCard() test1: failed.\n");
    else
        printf ("smithyCard() test1: passed.\n");

    // TEST 2
    // Check remaining player's hand
    if(G.handCount[1] == otherPlayerHandCount)
        printf ("smithyCard() test2: passed.\n");
    else
        printf ("smithyCard() test2: failed.\n");
    
    // TEST 3
    // Check that Smithy card has been replaced by next card in hand
    if(G.hand[G.whoseTurn][handPos] > -1)
        printf ("smithyCard() test3: passed.\n");
    else
        printf ("smithyCard() test3: failed.\n");
    
    return 0;
    
}