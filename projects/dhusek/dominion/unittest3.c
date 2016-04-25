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

#define TESTFUNCTION "gainCard()"

int main() {
    int discarded, deck, hand;
    
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, feast, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    int num;
    int GnewHandCount;
    int GnewDiscardCount;
    int GnewDeckCount;
    int GnewSupplyCountSmithy;
    int supply;
    int testSupplyCount;
    int errorCount = 0;
    int failedTests = 0;
    int passedTests = 0;
    
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    
    printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);
    
    // set supply of feast to zero
    G.supplyCount[feast] = 0;
    // note that remodel is not used in game so supply will be -1
    
    // ----------- Gain a card with zero supply. --------------
    printf("Testing: Gain a card with zero supply.\n");
    if(gainCard(feast, &G, 2, thisPlayer) != -1) {
        printf("\t**FAILED**: Wrong value returned for adding a card with zero supply.\n\n");
        failedTests++;
    } else {
        printf("\tPASSED: Correct value returned for adding a card with zero supply.\n\n");
        passedTests++;
    }
    
    // ----------- Gain a card that is not in the game. --------------
    printf("Testing: Gain a card that is not in the game.\n");
    if(gainCard(remodel, &G, 2, thisPlayer) != -1) {
        printf("\t**FAILED**: Wrong value returned for adding a card that is not in the game.\n\n");
        failedTests++;
    } else {
        printf("\tPASSED: Correct value returned for adding a card that is not in the game.\n\n");
        passedTests++;
    }
    
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    // gain smithy to the discard pile
    gainCard(smithy, &testG, 0, thisPlayer);
    
    discarded = 1;
    hand = 0;
    deck = 0;
    
    GnewHandCount = G.handCount[thisPlayer] + hand;
    GnewDiscardCount = G.discardCount[thisPlayer] + discarded;
    GnewDeckCount = G.deckCount[thisPlayer] + deck;
    
    // ----------- Gain a card to the discard pile. --------------
    printf("Testing: Gain a card to the discard pile.\n");
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
    
    supply = 1;
    GnewSupplyCountSmithy = G.supplyCount[smithy] - supply;
    
    // ----------- Card that was gained is removed from supply pile. --------------
    printf("Testing: Card that was gained is removed from supply pile.\n");
    testSupplyCount = supplyCount(smithy, &testG);
    if(testSupplyCount != GnewSupplyCountSmithy) {
        if(testSupplyCount < GnewSupplyCountSmithy) {
            num = GnewSupplyCountSmithy - testSupplyCount;
            printf("\t**FAILED**: Supply count was not updated correctly.  There are %d too few cards.\n", num);
            failedTests++;
            errorCount++;
        } else { // supply count is too big
            num = testSupplyCount - GnewSupplyCountSmithy;
            printf("\t**FAILED**: Supply count was not updated correctly.  There are %d too many cards.\n", num);
            failedTests++;
            errorCount++;
        }
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: Supply count is correct.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // gain smithy to the deck
    gainCard(smithy, &testG, 1, thisPlayer);
    
    discarded = 0;
    hand = 0;
    deck = 1;
    
    GnewHandCount = GnewHandCount + hand;
    GnewDiscardCount = GnewDiscardCount + discarded;
    GnewDeckCount = GnewDeckCount + deck;
    
    // ----------- Gain a card to the deck. --------------
    printf("Testing: Gain a card to the deck.\n");
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
    } else if(testG.deckCount[thisPlayer] > 0 && testG.deck[thisPlayer][testG.deckCount[thisPlayer] - 1] != smithy) {
        printf("\t**FAILED**: Deck does not have the correct card on top.\n");
        failedTests++;
        errorCount++;
    } else {
        printf("\tPASSED: The correct card is on top of the deck.\n");
        passedTests++;
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: Discard, deck, and hand counts are all correct.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // gain smithy to the hand
    gainCard(smithy, &testG, 2, thisPlayer);
    
    discarded = 0;
    hand = 1;
    deck = 0;
    
    GnewHandCount = GnewHandCount + hand;
    GnewDiscardCount = GnewDiscardCount + discarded;
    GnewDeckCount = GnewDeckCount + deck;
    
    // ----------- Gain a card to the hand. --------------
    printf("Testing: Gain a card to the hand.\n");
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
    } else if(testG.handCount[thisPlayer] > 0 && testG.hand[thisPlayer][testG.handCount[thisPlayer] - 1] != smithy) {
        printf("\t**FAILED**: Hand does not have the correct card on top.\n");
        failedTests++;
        errorCount++;
    } else {
        printf("\tPASSED: The correct card is on top of the hand.\n");
        passedTests++;
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