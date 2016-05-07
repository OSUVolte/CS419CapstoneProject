/*
 * unittest4.c
 *
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "interface.h"

#define TESTFUNCTION "drawCard()"

int main() {
    int hand;
    int deck;
    
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, feast, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    int i;
    int num;
    int GnewHandCount;
    int GnewDeckCount;
    int GnewDiscardCount;
    int errorCount = 0;
    int failedTests = 0;
    int passedTests = 0;
    
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    
    printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);
    
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    for(i = 0; i < testG.deckCount[thisPlayer]; i++) {
        testG.discard[thisPlayer][testG.discardCount[thisPlayer]] = testG.deck[thisPlayer][i];
        testG.discardCount[thisPlayer]++;
    }
    
    testG.deckCount[thisPlayer] = 0;
    
    hand = 1;
    deck = 1;
    GnewHandCount = G.handCount[thisPlayer] + hand;
    GnewDeckCount = G.deckCount[thisPlayer] - deck;
    GnewDiscardCount = 0;
    
    drawCard(thisPlayer, &testG);
    
    // ----------- Draw a card from an empty deck. --------------
    printf("Testing: Draw a card from an empty deck.\n");
    if(testG.handCount[thisPlayer] != GnewHandCount) {
        if(testG.handCount[thisPlayer] < GnewHandCount) {
            num = GnewHandCount - testG.handCount[thisPlayer];
            printf("\t**FAILED**: Hand count was not updated correctly.  There are %d too few cards.\n", num);
            failedTests++;
            errorCount++;
        } else { // hand count is too big
            num = testG.handCount[thisPlayer] - GnewHandCount;
            printf("\t**FAILED**: Hand count was not updated correctly.  There are %d too many cards.\n", num);
            failedTests++;
            errorCount++;
        }
    }
    if(testG.deckCount[thisPlayer] != GnewDeckCount) {
        if(testG.deckCount[thisPlayer] < GnewDeckCount) {
            num = GnewDeckCount - testG.deckCount[thisPlayer];
            printf("\t**FAILED**: Deck count was not updated correctly.  There are %d too few cards.\n", num);
            failedTests++;
            errorCount++;
        } else { // deck count is too big
            num = testG.deckCount[thisPlayer] - GnewDeckCount;
            printf("\t**FAILED**: Deck count was not updated correctly.  There are %d too many cards.\n", num);
            failedTests++;
            errorCount++;
        }
    }
    if(testG.discardCount[thisPlayer] != GnewDiscardCount) {
        if(testG.discardCount[thisPlayer] < GnewDiscardCount) {
            num = GnewDiscardCount - testG.discardCount[thisPlayer];
            printf("\t**FAILED**: Discard count was not updated correctly.  There are %d too few cards.\n", num);
            failedTests++;
            errorCount++;
        } else { // discard count is too big
            num = testG.discardCount[thisPlayer] - GnewDiscardCount;
            printf("\t**FAILED**: Discard count was not updated correctly.  There are %d too many cards.\n", num);
            failedTests++;
            errorCount++;
        }
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: Discard, deck, and hand counts are all correct.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    hand = 1;
    deck = 1;
    GnewHandCount = GnewHandCount + hand;
    GnewDeckCount = GnewDeckCount - deck;
    
    drawCard(thisPlayer, &testG);
    
    // ----------- Draw a card from a deck. --------------
    printf("Testing: Draw a card from a deck.\n");
    if(testG.handCount[thisPlayer] != GnewHandCount) {
        if(testG.handCount[thisPlayer] < GnewHandCount) {
            num = GnewHandCount - testG.handCount[thisPlayer];
            printf("\t**FAILED**: Hand count was not updated correctly.  There are %d too few cards.\n", num);
            failedTests++;
            errorCount++;
        } else { // hand count is too big
            num = testG.handCount[thisPlayer] - GnewHandCount;
            printf("\t**FAILED**: Hand count was not updated correctly.  There are %d too many cards.\n", num);
            failedTests++;
            errorCount++;
        }
    }
    if(testG.deckCount[thisPlayer] != GnewDeckCount) {
        if(testG.deckCount[thisPlayer] < GnewDeckCount) {
            num = GnewDeckCount - testG.deckCount[thisPlayer];
            printf("\t**FAILED**: Deck count was not updated correctly.  There are %d too few cards.\n", num);
            failedTests++;
            errorCount++;
        } else { // deck count is too big
            num = testG.deckCount[thisPlayer] - GnewDeckCount;
            printf("\t**FAILED**: Deck count was not updated correctly.  There are %d too many cards.\n", num);
            failedTests++;
            errorCount++;
        }
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: Discard, deck, and hand counts are all correct.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    
    
    
    
    
    //---------------------------------------------------------------------------
    
    printf(" >>>>> SUCCESS: Testing complete %s <<<<<\n", TESTFUNCTION);
    printf("\t%d tests **FAILED**.\n", failedTests);
    printf("\t%d tests PASSED.\n\n", passedTests);
    
    
    return 0;
}