#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Dane Schoonover
// Assignment 3
// councilRoomCard() test

// This file tests the councilRoomCard() card effect.

// What to test:
    // Player's handcount increased by 3 more cards (+4 - 1 = 3)
    // Player's number of buys increased by 1
    // Remaining players' handcounts increased by 1 more card
    // Check that council_room card has been replaced by next card in hand
    // Player's draw pile reduced by 4 cards (deckcount - 4)
    // Remaining players' draw piles reduced by 1 card each


int main (int argc, char** argv) {
    printf ("---------- Testing councilRoomCard() ----------\n");
    int i, j, k;
    int handPos = 0;
    
    // Create a game
    int numPlayers = 2;
    struct gameState G;     // initial state
    struct gameState G2;    // post council_room card state
    int z[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '10'
    initializeGame(numPlayers, z, 10, &G);
    initializeGame(numPlayers, z, 10, &G2);
    
    // Default whoseTurn
    G.whoseTurn = 0;
    
    // Set Council Room card to handPos
    G.hand[G.whoseTurn][handPos] = council_room;
    
    // Play the card
    councilRoomCard(i, G.whoseTurn, &G2, handPos);
    
    // TEST 1
    // Player's handcount increased by 3 more cards
    if (G2.handCount[G.whoseTurn] == G.handCount[G.whoseTurn] + 3)
        printf ("councilRoomCard() test1: passed.\n");
    else
        printf ("councilRoomCard() test1: failed.\n");
    

    // TEST 2
    // Player's number of buys increased by 1
    if (G2.numBuys == G.numBuys + 1)
        printf ("councilRoomCard() test2: passed.\n");
    else
        printf ("councilRoomCard() test2: failed.\n");
    
    // TEST 3
    // Remaining players' handcounts increased by 1 more card
    for (j = 1; j < numPlayers; j++)
        if (G2.handCount[j] == (G.handCount[j] + 1))
            printf ("councilRoomCard() test3: passed for player %i.\n", j);
        else
            printf ("councilRoomCard() test3: failed for player %i.\n", j);

    
    // TEST 4
    // Check that council_room card has been replaced by next card in hand
    if (G2.hand[G.whoseTurn][handPos] > -1)
        printf ("councilRoomCard() test4: passed.\n");
    else
        printf ("councilRoomCard() test4: failed.\n");
    
    
    // TEST 5
    // Player's draw pile reduced by 4 cards (deckcount - 4)
    if (G2.deckCount[G.whoseTurn] == (G.deckCount[G.whoseTurn] - 4))
            printf ("councilRoomCard() test5: passed.\n");
        else
            printf ("councilRoomCard() test5: failed.\n");
    
    // TEST 6
    // Remaining players' draw piles reduced by 1 card each
    for (k = 1; k < numPlayers; k++)
        if (G2.deckCount[k] == (G.deckCount[k] - 1))
            printf ("councilRoomCard() test6: passed for player %i.\n", k);
        else
            printf ("councilRoomCard() test6: failed for player %i.\n", k);
    
    return 0;
}
