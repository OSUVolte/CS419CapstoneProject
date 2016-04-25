#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){
    int result;
    int k[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, baron, sea_hag, province};
    int numPlayers = 2;
    struct gameState G;
    memset(&G, 0, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayers, k, 10, &G); //initialize game

    printf ("------------------TESTING fullDeckCount():--------------------\n\n");

    //test at the beginning of the game, no cards gained
    printf ("Test with no cards gained.\n");
    result = fullDeckCount(0, adventurer, &G);
    if(result == 0){
        printf ("PASS. EXPECTED: 0. ACTUAL: %d.\n\n", result);
    }
    else{
        printf ("FAIL. EXPECTED: 0. ACTUAL: %d.\n\n", result);
    }

    //test with cards in deck, no in hand, no in discard
    printf ("Test with a card in player's deck.\n");
    G.deckCount[0] = 1;
    G.deck[0][0] = adventurer;
    result = fullDeckCount(0, adventurer, &G);
    if(result == 1){
        printf ("PASS. EXPECTED: 1. ACTUAL: %d.\n\n", result);
    }
    else{
        printf ("FAIL. EXPECTED: 1. ACTUAL: %d.\n\n", result);
    }

    //test with cards in deck, in hand, no in discard
    printf ("Test with a card in player's deck and hand.\n");
    G.handCount[0] = 1;
    G.hand[0][0] = adventurer;
    result = fullDeckCount(0, adventurer, &G);
    if(result == 2){
        printf ("PASS. EXPECTED: 2. ACTUAL: %d.\n\n", result);
    }
    else{
        printf ("FAIL. EXPECTED: 2. ACTUAL: %d.\n\n", result);
    }

    //test with cards in deck, in hand, in discard
    printf ("Test with a card in player's deck and hand.\n");
    G.discardCount[0] = 1;
    G.discard[0][0] = adventurer;
    result = fullDeckCount(0, adventurer, &G);
    if(result == 3){
        printf ("PASS. EXPECTED: 3. ACTUAL: %d.\n\n", result);
    }
    else{
        printf ("FAIL. EXPECTED: 3. ACTUAL: %d.\n\n", result);
    }

    //test with cards no cards in deck, one in hand, one in discard
    printf ("Test with a card in player's discard and hand.\n");
    G.deckCount[0] = 0;
    result = fullDeckCount(0, adventurer, &G);
    if(result == 2){
        printf ("PASS. EXPECTED: 2. ACTUAL: %d.\n\n", result);
    }
    else{
        printf ("FAIL. EXPECTED: 2. ACTUAL: %d.\n\n", result);
    }

    //test with cards no cards in deck, no in hand, one in discard
    printf ("Test with a card in player's discard and hand.\n");
    G.handCount[0] = 0;
    result = fullDeckCount(0, adventurer, &G);
    if(result == 1){
        printf ("PASS. EXPECTED: 1. ACTUAL: %d.\n\n", result);
    }
    else{
        printf ("FAIL. EXPECTED: 1. ACTUAL: %d.\n\n", result);
    }

    //test with cards one card in deck, no in hand, one in discard
    printf ("Test with a card in player's discard and hand.\n");
    G.deckCount[0] = 1;
    G.deck[0][0] = adventurer;
    result = fullDeckCount(0, adventurer, &G);
    if(result == 2){
        printf ("PASS. EXPECTED: 2. ACTUAL: %d.\n\n", result);
    }
    else{
        printf ("FAIL. EXPECTED: 2. ACTUAL: %d.\n\n", result);
    }

    //test for adventurer count with other cards in deck, in hand, in discard
    printf ("Test with other card in player's discard, hand and deck.\n");
    G.handCount[0] = 2;
    G.deckCount[0] = 1;
    G.discardCount[0] = 2;
    G.hand[0][1] = smithy;
    G.deck[0][0] = smithy;
    G.discard[0][1] = smithy;
    result = fullDeckCount(0, adventurer, &G);
    if(result == 2){
        printf ("PASS. EXPECTED: 2. ACTUAL: %d.\n\n", result);
    }
    else{
        printf ("FAIL. EXPECTED: 2. ACTUAL: %d.\n\n", result);
    }

    printf("---------------------------------------------------------\n");

    return 0;
}
