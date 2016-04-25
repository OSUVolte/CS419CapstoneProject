#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Dane Schoonover
// Assignment 3
// scoreFor()

// This file tests the scoreFor() function. The scoreFor() function calculates
// and returns a player's score using various critria such as hand cards, discarded
// cards, and deck cards.

// What to test:
    // Correct scores from cards in handCount
    // Correct scores from cards in discardCount
    // Correct scores from cards in deckcount


int main (int argc, char** argv) {
    printf ("---------- Testing scoreFor() ----------\n");
    // Create a game
    int numPlayers = 2;
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '10'
    initializeGame(numPlayers, k, 10, &G);
    
    // Cards for our tests
    int cards[6] = {curse, estate, duchy, province, great_hall, gardens};
    
    // Default Player
    G.whoseTurn = 0;
    
    // We need to populate the following sets: handCount, discardCount, and deckCount
    // To ensure the right numbers are being tested in each set within scoreFor(),
    // we need to use separate numbers for each set (this will catch the obvious bug
    // in the 3rd for loop). In order to do this, we will simply use sizes
    // 6, 12, and 18 for handCount, discardCount, and deckCount, respectively.
    // These pile sizes will then be filled with the cards array, restarting from cards[0]
    // at every 6th card.
    
    // Set the pile sizes:
    G.handCount[G.whoseTurn] = 6;
    G.discardCount[G.whoseTurn] = 12;
    G.deckCount[G.whoseTurn] = 18;
    
    // Check counts:
//    printf("handCount: %i\n", G.handCount[G.whoseTurn]);
//    printf("discardCount: %i\n", G.discardCount[G.whoseTurn]);
//    printf("deckCount: %i\n", G.deckCount[G.whoseTurn]);

    
    //*** Populate the piles ***//
    // --------------------------------------------------------
    // Hand
    for (int i = 0; i < G.handCount[G.whoseTurn]; i++){
        G.hand[G.whoseTurn][i] = cards[i];
    }
    // Check hand
//    printf("\nHand:\n");
//    for (int i = 0; i < G.handCount[G.whoseTurn]; i++){
//        printf("Card %i: %i\n",i, G.hand[G.whoseTurn][i]);
//    }
    // --------------------------------------------------------
    // Discard
    int count = 0;
    for (int j = 0; j < (G.discardCount[G.whoseTurn] * 2); j++) {
        
        G.discard[G.whoseTurn][j] = cards[count];
        
        count++;
        
        // End of cards array, start over
        if (count == 6)
            count = 0;
        
    }
    
    // Check discard
//    printf("\nDiscard:\n");
//    for (int i = 0; i < G.discardCount[G.whoseTurn]; i++){
//        printf("Card %i: %i\n",i, G.discard[G.whoseTurn][i]);
//    }
    // --------------------------------------------------------
    // Deck
    for (int k = 0; k < (G.deckCount[G.whoseTurn] * 3); k++) {
        
        G.deck[G.whoseTurn][k] = cards[count];
        
        count++;
        
        // End of cards array, start over
        if (count == 6)
            count = 0;
        
    }
    
    // Check deck
//    printf("\nDeck:\n");
//    for (int i = 0; i < G.deckCount[G.whoseTurn]; i++){
//        printf("Card %i: %i\n",i, G.deck[G.whoseTurn][i]);
//    }
    // --------------------------------------------------------


    // fullDeckCount = 36
    // fullDeckCount / 10 = 3.6 = 3 (C integer division)
    // hand:    13
    // discard: 26
    // deck:    39
    // Expected score: 13 + 26 + 39 = 78
    
    printf ("Expected score is 78.\n");
    int score = scoreFor(G.whoseTurn, &G);
    printf ("Actual score is %i.\n", score);
    
    if (score == 78)
        printf("scoreFor() test passed.\n");
    else
        printf("scoreFor() test failed.\n");

    return 0;
}












