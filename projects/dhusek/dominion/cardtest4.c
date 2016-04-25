/*
 * cardtest4.c
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

#define TESTCARD "council room"

int main() {
    int newCards = 0;
    int discarded = 1;
    int extraActions = 0;
    int extraBuys = 0;
    int shuffledCards = 0;
    
    int i;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
    struct gameState G, testG;
    int k[10] = {adventurer, feast, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    int GnewHandCount;
    int GnewDeckCount;
    int GotherNewDeckCount;
    int GotherNewHandCount;
    int GnewActionCount;
    int GnewBuyCount;
    int GdeckCount;
    int num;
    int card1, card2, card3, card4;
    int deckCard1, deckCard2, deckCard3, deckCard4;
    int errorCount = 0;
    int failedTests = 0;
    int passedTests = 0;
    const char* cards[27] = {"curse", "estate", "duchy", "province", "copper", "silver",
                             "gold", "adventurer", "council room", "feast", "gardens",
                             "mine", "remodel", "smithy", "village", "baron", "great hall",
                             "minion", "steward", "tribute", "ambassador", "cutpurse",
                             "embargo", "outpost", "salvager", "sea hag", "treasure map"};
    
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    
    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    
    // set card in position 0 to Council Room
    G.hand[thisPlayer][handpos] = council_room;
    GdeckCount = G.deckCount[thisPlayer];
    
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    //printDeck(thisPlayer, &testG);
    //printHand(thisPlayer, &testG);
    
    // play council room card in testG game
    cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);
    
    //printHand(thisPlayer, &testG);
    
    newCards = 4;
    extraActions = 0;
    extraBuys = 1;
    GnewHandCount = G.handCount[thisPlayer] + newCards - discarded;
    GnewDeckCount = GdeckCount - newCards + shuffledCards;
    GnewActionCount = G.numActions + extraActions;
    GnewBuyCount = G.numBuys + extraBuys;
    // other player new cards
    newCards = 1;
    GotherNewHandCount = G.handCount[otherPlayer] + newCards;
    GotherNewDeckCount = G.deckCount[otherPlayer] - newCards + shuffledCards;
    
    
    printf("Current game state compared with expected state:\n");
    printf("\thand count = %d, expected = %d\n", testG.handCount[thisPlayer], GnewHandCount);
    printf("\tdeck count = %d, expected = %d\n", testG.deckCount[thisPlayer], GnewDeckCount);
    printf("\tactions = %d, expected = %d\n", testG.numActions, GnewActionCount);
    printf("\tbuys = %d, expected = %d\n", testG.numBuys, GnewBuyCount);
    printf("\n");
    
    // ----------- Current player should receive exactly 4 cards --------------
    printf("Testing: Current player should receive exactly 4 cards.\n");
    if(testG.handCount[thisPlayer] != GnewHandCount) {
        if(testG.handCount[thisPlayer] < GnewHandCount) {
            num = GnewHandCount - testG.handCount[thisPlayer];
            printf("\t**FAILED**: Current player drew %d too few cards.\n\n", num);
            failedTests++;
        } else { // Current player drew too many cards
            num = testG.handCount[thisPlayer] - GnewHandCount;
            printf("\t**FAILED**: Current player drew %d too many cards.\n\n", num);
            failedTests++;
        }
    } else {
        printf("\tPASSED: Current player received the correct number of cards.\n\n");
        passedTests++;
    }
    
    // ----------- Current player's deck should be 4 cards smaller --------------
    printf("Testing: Current player's deck should be 4 cards smaller.\n");
    if(testG.deckCount[thisPlayer] != GnewDeckCount) {
        if(testG.deckCount[thisPlayer] < GnewDeckCount) {
            num = GnewDeckCount - testG.deckCount[thisPlayer];
            printf("\t**FAILED**: Current player drew %d too many cards.\n\n", num);
            failedTests++;
        } else { // Current player drew too few cards
            num = testG.deckCount[thisPlayer] - GnewDeckCount;
            printf("\t**FAILED**: Current player drew %d too few cards.\n\n", num);
            failedTests++;
        }
    } else {
        printf("\tPASSED: Current player's deck contains the correct number of cards.\n\n");
        passedTests++;
    }
    
    // ----------- Current player should draw 4 cards from his own deck --------------
    printf("Testing: Current player should draw 4 cards from his own deck.\n");
    errorCount = 0;
    card1 = testG.hand[thisPlayer][testG.handCount[thisPlayer] - 1];
    card2 = testG.hand[thisPlayer][testG.handCount[thisPlayer] - 2];
    card3 = testG.hand[thisPlayer][testG.handCount[thisPlayer] - 3];
    card4 = testG.hand[thisPlayer][handpos]; // since last card is swapped with Council Room's position when it is discarded
    deckCard1 = G.deck[thisPlayer][G.deckCount[thisPlayer] - 1];
    deckCard2 = G.deck[thisPlayer][G.deckCount[thisPlayer] - 2];
    deckCard3 = G.deck[thisPlayer][G.deckCount[thisPlayer] - 3];
    deckCard4 = G.deck[thisPlayer][G.deckCount[thisPlayer] - 4];
    if(card1 != deckCard1) {
        printf("\t**FAILED**: The first card was not drawn from the current player's deck.\n");
        failedTests++;
        errorCount++;
    }
    if(card2 != deckCard2) {
        printf("\t**FAILED**: The second card was not drawn from the current player's deck.\n");
        failedTests++;
        errorCount++;
    }
    if(card3 != deckCard3) {
        printf("\t**FAILED**: The third card was not drawn from the current player's deck.\n");
        failedTests++;
        errorCount++;
    }
    if(card4 != deckCard4) {
        printf("\t**FAILED**: The fourth card was not drawn from the current player's deck.\n");
        failedTests++;
        errorCount++;
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: Cards were drawn from the correct player's deck.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // ----------- Current player should receive no additional actions --------------
    printf("Testing: Current player should receive no additional actions.\n");
    if(testG.numActions != GnewActionCount) {
        if(testG.numActions < GnewActionCount) {
            num = GnewActionCount - testG.numActions;
            printf("\t**FAILED**: Current player has %d too few actions.\n\n", num);
            failedTests++;
        } else { // Current player has too many actions
            num = testG.numActions - GnewActionCount;
            printf("\t**FAILED**: Current player has %d too many actions.\n\n", num);
            failedTests++;
        }
    } else {
        printf("\tPASSED: Current player has the correct number of actions.\n\n");
        passedTests++;
    }
    
    // ----------- Current player should receive 1 additional buy --------------
    printf("Testing: Current player should receive 1 additional buy.\n");
    if(testG.numBuys != GnewBuyCount) {
        if(testG.numBuys < GnewBuyCount) {
            num = GnewBuyCount - testG.numBuys;
            printf("\t**FAILED**: Current player has %d too few buys.\n\n", num);
            failedTests++;
        } else { // Current player has too many buys
            num = testG.numBuys - GnewBuyCount;
            printf("\t**FAILED**: Current player has %d too many buys.\n\n", num);
            failedTests++;
        }
    } else {
        printf("\tPASSED: Current player has the correct number of buys.\n\n");
        passedTests++;
    }
    
    // ----------- Other player should receive exactly 1 card --------------
    printf("Testing: Other player should receive exactly 1 card.\n");
    if(testG.handCount[otherPlayer] != GotherNewHandCount) {
        if(testG.handCount[otherPlayer] < GotherNewHandCount) {
            num = GotherNewHandCount - testG.handCount[otherPlayer];
            printf("\t**FAILED**: Other player drew %d too few cards.\n\n", num);
            failedTests++;
        } else { // Other player drew too many cards
            num = testG.handCount[otherPlayer] - GotherNewHandCount;
            printf("\t**FAILED**: Other player drew %d too many cards.\n\n", num);
            failedTests++;
        }
    } else {
        printf("\tPASSED: Other player received the correct number of cards.\n\n");
        passedTests++;
    }
    
    // ----------- Other player's deck should be 1 card smaller --------------
    printf("Testing: Other player's deck should be 1 card smaller.\n");
    if(testG.deckCount[otherPlayer] != GotherNewDeckCount) {
        if(testG.deckCount[otherPlayer] < GotherNewDeckCount) {
            num = GotherNewDeckCount - testG.deckCount[otherPlayer];
            printf("\t**FAILED**: Other player drew %d too many cards.\n\n", num);
            failedTests++;
        } else { // Current player drew too few cards
            num = testG.deckCount[otherPlayer] - GotherNewDeckCount;
            printf("\t**FAILED**: Other player drew %d too few cards.\n\n", num);
            failedTests++;
        }
    } else {
        printf("\tPASSED: Other player's deck contains the correct number of cards.\n\n");
        passedTests++;
    }
    
    // ----------- Other player should draw 1 card from his own deck --------------
    printf("Testing: Other player should draw 1 card from his own deck.\n");
    if(testG.hand[otherPlayer][testG.handCount[otherPlayer] - 1] != G.deck[otherPlayer][G.deckCount[otherPlayer] - 1]) {
        printf("\t**FAILED**: The first card was not drawn from the current player's deck.\n\n");
        failedTests++;
    } else {
        printf("\tPASSED: Cards were drawn from the correct player's deck.\n\n");
        passedTests++;
    }
    
    // ----------- No state change should occur for other players except for drawing a card. --------------
    printf("Testing: No state change should occur for other players except for drawing a card.\n");
    errorCount = 0;
    if(testG.handCount[otherPlayer] != GotherNewHandCount) {
        printf("\t**FAILED**: Other player's hand count is incorrect.\n");
        failedTests++;
        errorCount++;
    }
    if(testG.deckCount[otherPlayer] != GotherNewDeckCount) {
        printf("\t**FAILED**: Other player's deck count is incorrect.\n");
        failedTests++;
        errorCount++;
    }
    if(testG.discardCount[otherPlayer] != G.discardCount[otherPlayer]) {
        printf("\t**FAILED**: Other player's discard count has changed.\n");
        failedTests++;
        errorCount++;
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: No state change has occured for the other player except for drawing a card.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // ----------- No state change should occur for the victory card piles. --------------
    printf("Testing: No state change should occur for the victory card piles.\n");
    errorCount = 0;
    if(supplyCount(estate, &testG) != supplyCount(estate, &G)) {
        printf("\t**FAILED**: Supply of %s cards has changed.\n", cards[estate]);
        failedTests++;
        errorCount++;
    }
    if(supplyCount(duchy, &testG) != supplyCount(duchy, &G)) {
        printf("\t**FAILED**: Supply of %s cards has changed.\n", cards[duchy]);
        failedTests++;
        errorCount++;
    }
    if(supplyCount(province, &testG) != supplyCount(province, &G)) {
        printf("\t**FAILED**: Supply of %s cards has changed.\n", cards[province]);
        failedTests++;
        errorCount++;
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: No state change has occured for the victory card piles.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // ----------- No state change should occur for the treasure card piles. --------------
    printf("Testing: No state change should occur for the treasure card piles.\n");
    errorCount = 0;
    if(supplyCount(copper, &testG) != supplyCount(copper, &G)) {
        printf("\t**FAILED**: Supply of %s cards has changed.\n", cards[copper]);
        failedTests++;
        errorCount++;
    }
    if(supplyCount(silver, &testG) != supplyCount(silver, &G)) {
        printf("\t**FAILED**: Supply of %s cards has changed.\n", cards[silver]);
        failedTests++;
        errorCount++;
    }
    if(supplyCount(gold, &testG) != supplyCount(gold, &G)) {
        printf("\t**FAILED**: Supply of %s cards has changed.\n", cards[gold]);
        failedTests++;
        errorCount++;
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: No state change has occured for the treasure card piles.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // ----------- No state change should occur for the kingdom card piles. --------------
    printf("Testing: No state change should occur for the kingdom card piles.\n");
    errorCount = 0;
    for(i = 0; i < 10; i++) {
        if(supplyCount(k[i], &testG) != supplyCount(k[i], &G)) {
            printf("\t**FAILED**: Supply of %s cards has changed.\n", cards[k[i]]);
            failedTests++;
            errorCount++;
        }
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: No state change has occured for the kingdom card piles.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // ----------- Current player's discard pile should have Council Room on top --------------
    printf("Testing: Current player's discard pile should have Council Room on top.\n");
    if(testG.discardCount[thisPlayer] > 0) {
        if(testG.discard[thisPlayer][testG.discardCount[thisPlayer] - 1] != council_room) {
            printf("\t**FAILED**: The last card in current player's discard pile is not Council Room.\n\n");
            failedTests++;
        } else {
            printf("\tPASSED: The last card in current player's discard pile is Council Room.\n\n");
            passedTests++;
        }
    } else {
        printf("\t**FAILED**: The current player's test discard pile is empty.\n\n");
        failedTests++;
    }
    
    //---------------------------------------------------------------------------
    
    printf(" >>>>> SUCCESS: Testing complete %s <<<<<\n", TESTCARD);
    printf("\t%d tests **FAILED**.\n", failedTests);
    printf("\t%d tests PASSED.\n\n", passedTests);
    
    
    return 0;
}