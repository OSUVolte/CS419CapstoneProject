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
    int trashed;
    int discarded;
    
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, feast, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    int i;
    int num;
    int GnewHandCount;
    int GnewDiscardCount;
    int GnewTrashCount;
    int errorCount = 0;
    int failedTests = 0;
    int passedTests = 0;
    
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    
    printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);
    
    for(i = 0; i < G.deckCount[thisPlayer]; i++) {
        G.discard[thisPlayer][G.discardCount[thisPlayer]] = G.deck[thisPlayer][i];
        G.discardCount[thisPlayer]++;
    }
    
    G.deckCount[thisPlayer] = 0;
    
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    
    
    
    
    
    
    
    
    
    //---------------------------------------------------------------------------
    
    printf(" >>>>> SUCCESS: Testing complete %s <<<<<\n", TESTFUNCTION);
    printf("\t%d tests **FAILED**.\n", failedTests);
    printf("\t%d tests PASSED.\n\n", passedTests);
    
    
    return 0;
}