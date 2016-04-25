/*
 * unittest3.c
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

#define TESTFUNCTION "discardCard()"

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
    
    // set cards in hand
    G.hand[thisPlayer][0] = smithy;
    G.hand[thisPlayer][1] = feast;
    G.hand[thisPlayer][2] = adventurer;
    G.hand[thisPlayer][3] = village;
    G.hand[thisPlayer][4] = council_room;
    
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    // trash feast card
    discardCard(1, thisPlayer, &testG, 1);
    discarded = 0;
    trashed = 1;
    
    GnewHandCount = G.handCount[thisPlayer] - discarded - trashed;
    GnewDiscardCount = G.discardCount[thisPlayer] + discarded;
    GnewTrashCount = G.trashCount + trashed;
    
    // ----------- If trash flag is 1, card is added to trash pile. --------------
    printf("Testing: If trash flag is 1, card is added to trash pile.\n");
    errorCount = 0;
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
    if(testG.trashCount != GnewTrashCount) {
        if(testG.trashCount < GnewTrashCount) {
            num = GnewTrashCount - testG.trashCount;
            printf("\t**FAILED**: Trash count was not updated correctly.  There are %d too few cards.\n", num);
            failedTests++;
            errorCount++;
        } else { // trash count is too big
            num = testG.trashCount - GnewTrashCount;
            printf("\t**FAILED**: Trash count was not updated correctly.  There are %d too many cards.\n", num);
            failedTests++;
            errorCount++;
        }
    } else if(testG.trash[testG.trashCount - 1] != feast) {
        printf("\t**FAILED**: Trash does not have the correct card on top.\n");
        failedTests++;
        errorCount++;
    } else {
        printf("\tPASSED: The correct card is on top of the trash.\n");
        passedTests++;
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: Discard, trash, and hand counts are all correct.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // ----------- Card is not the last card in the hand so it is replaced by last card in hand. --------------
    printf("Testing: Card is not the last card in the hand so it is replaced by last card in hand.\n");
    if(testG.hand[thisPlayer][1] != council_room) {
        printf("\t**FAILED**: Card was not replaced by last card in hand.\n\n");
        failedTests++;
        errorCount++;
    } else {
        printf("\tPASSED: Card locations in hand were updated correctly.\n\n");
        passedTests++;
    }
    
    // --------------------------------------------------------------------------------------
    
    // trash village card
    discardCard(3, thisPlayer, &testG, 1);
    discarded = 0;
    trashed = 1;
    
    GnewHandCount = GnewHandCount - discarded - trashed;
    GnewDiscardCount = GnewDiscardCount + discarded;
    GnewTrashCount = GnewTrashCount + trashed;
    
    // ----------- If played card is the last card in hand, hand count is decremented. --------------
    printf("Testing: If played card is the last card in hand, hand count is decremented.\n");
    errorCount = 0;
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
    } else {
        if(testG.hand[thisPlayer][0] == smithy && testG.hand[thisPlayer][1] == council_room && testG.hand[thisPlayer][2] == adventurer && testG.hand[thisPlayer][3] == -1) {
            printf("\tPASSED: The hand is in the correct order.\n");
            passedTests++;
        } else {
            printf("\t**FAILED**: The hand is not in the correct order.\n");
            failedTests++;
            errorCount++;
        }
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: Hand count was decremented correctly.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // --------------------------------------------------------------------------------------
    
    // trash council_room card
    discardCard(1, thisPlayer, &testG, 1);
    discarded = 0;
    trashed = 1;
    
    GnewHandCount = GnewHandCount - discarded - trashed;
    GnewDiscardCount = GnewDiscardCount + discarded;
    GnewTrashCount = GnewTrashCount + trashed;
    
    // ----------- Played card is removed from hand. --------------
    printf("Testing: Played card is removed from hand.\n");
    errorCount = 0;
    for(i = 0; i < testG.handCount[thisPlayer]; i++) {
        if(testG.hand[thisPlayer][i] == council_room) {
            printf("\t**FAILED**: Played card was not removed from hand.\n");
            failedTests++;
            errorCount++;
        }
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: Played card was removed from hand.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // --------------------------------------------------------------------------------------
    
    // trash adventurer card
    discardCard(1, thisPlayer, &testG, 1);
    discarded = 0;
    trashed = 1;
    
    GnewHandCount = GnewHandCount - discarded - trashed;
    GnewDiscardCount = GnewDiscardCount + discarded;
    GnewTrashCount = GnewTrashCount + trashed;
    
    // --------------------------------------------------------------------------------------
    
    // discard smithy card
    discardCard(0, thisPlayer, &testG, 0);
    discarded = 1;
    trashed = 0;
    
    GnewHandCount = GnewHandCount - discarded - trashed;
    GnewDiscardCount = GnewDiscardCount + discarded;
    GnewTrashCount = GnewTrashCount + trashed;
    
    // ----------- If trash flag is less than 1, card is added to discard pile. --------------
    printf("Testing: If trash flag is less than 1, card is added to discard pile.\n");
    errorCount = 0;
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
    } else if(testG.discardCount[thisPlayer] > 0 && testG.discard[thisPlayer][testG.discardCount[thisPlayer] - 1] != smithy) {
        printf("\t**FAILED**: Discard pile does not have the correct card on top.\n");
        failedTests++;
        errorCount++;
    } else {
        printf("\tPASSED: The correct card is on top of the discard pile.\n");
        passedTests++;
    }
    if(testG.trashCount != GnewTrashCount) {
        if(testG.trashCount < GnewTrashCount) {
            num = GnewTrashCount - testG.trashCount;
            printf("\t**FAILED**: Trash count was not updated correctly.  There are %d too few cards.\n", num);
            failedTests++;
            errorCount++;
        } else { // trash count is too big
            num = testG.trashCount - GnewTrashCount;
            printf("\t**FAILED**: Trash count was not updated correctly.  There are %d too many cards.\n", num);
            failedTests++;
            errorCount++;
        }
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: Discard, trash, and hand counts are all correct.\n\n");
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