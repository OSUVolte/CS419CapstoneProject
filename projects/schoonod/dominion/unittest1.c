#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Dane Schoonover
// Assignment 3
// handCard() test

// This file tests the handCard() function. The purpose of the handCard() function is
// to return the card in the given player's (whoseTurn) hand based on the given
// hand position (handPos).

// What to test:
    // Card returned is not NULL
    // Card returned is the correct card

int handCardTest(int handPos, struct gameState *state){
    
    int correctCard = state->hand[state->whoseTurn][handPos];
    int playerCard = 0;
    playerCard = handCard(handPos, state);
    
    // TEST 1:
    // Card returned is not NULL
    if (!playerCard) {
        printf ("handCard() test1: failed.\n");
    }
    else {
        printf ("hardCard() test1: passed.\n");
    }

    // TEST 2:
    // Card returned is the correct card
    if (correctCard != playerCard){
        printf ("handCard() test2: failed.\n\n");
    }
    else {
        printf ("handCard() test2: passed.\n\n");
    }
    return 0;
}


int main (int argc, char** argv) {
    printf ("---------- UnitTest1: handCard() ----------\n");
    // Create a game
    int numPlayers = 2;
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '10'
    initializeGame(numPlayers, k, 10, &G);
    
    // Default Player
    G.whoseTurn = 0;
    
    // For each player
    for (int p = 0; p < numPlayers; p++){
        printf("Player %i:\n", p+1);
        // For each card in the player's hand
        for (int c = 0; c < G.handCount[p]; c++ ){
            printf("Card %i:\n", c+1);
            // Test handCard()
            handCardTest(c, &G);
        }
        endTurn(&G);
    }
    return 0;
}
