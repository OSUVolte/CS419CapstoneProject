/*
 * cardtest2.c
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

#define TESTCARD "adventurer"

int main() {
    int newCards = 0;
    int discarded = 1;
    int extraCoins = 0;
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
    int GnewCoins;
    int GdeckCount;
    int GtempHandSize;
    int num;
    int GnumTreasureCards = 0;
    int expectedTreasureCards = 0;
    int testNumTreasureCards = 0;
    int card1, card2;
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
    
    // set card in position 0 to adventurer
    G.hand[thisPlayer][handpos] = adventurer;
    //printHand(thisPlayer, &G);
    // count treasure cards in G hand
    for(i = 0; i < G.handCount[thisPlayer]; i++) {
        if(G.hand[thisPlayer][i] == copper || G.hand[thisPlayer][i] == silver ||
           G.hand[thisPlayer][i] == gold) {
            GnumTreasureCards++;
        }
    }
    expectedTreasureCards = GnumTreasureCards + 2;
    
    GdeckCount = G.deckCount[thisPlayer];
    //printf("GdeckCount: %d\n", GdeckCount);
    
    // set first 4 cards in deck
    G.deck[thisPlayer][GdeckCount - 1] = feast;
    G.deck[thisPlayer][GdeckCount - 2] = gold;
    G.deck[thisPlayer][GdeckCount - 3] = village;
    G.deck[thisPlayer][GdeckCount - 4] = silver;
    //printDeck(thisPlayer, &G);
    GtempHandSize = 2;
    
    
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    // play adventurer card in testG game
    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
    //printHand(thisPlayer, &testG);
    
    newCards = 2;
    extraCoins = COPPER_VALUE + SILVER_VALUE;
    GnewHandCount = G.handCount[thisPlayer] + newCards - discarded;
    GnewDeckCount = GdeckCount - newCards - GtempHandSize + shuffledCards;
    GnewCoins = G.coins + extraCoins;
    
    // count treasure cards in testG hand
    for(i = 0; i < testG.handCount[thisPlayer]; i++) {
        if(testG.hand[thisPlayer][i] == copper || testG.hand[thisPlayer][i] == silver ||
           testG.hand[thisPlayer][i] == gold) {
            testNumTreasureCards++;
        }
    }
    
    printf("Current game state compared with expected state:\n");
    printf("\thand count = %d, expected = %d\n", testG.handCount[thisPlayer], GnewHandCount);
    printf("\tdeck count = %d, expected = %d\n", testG.deckCount[thisPlayer], GnewDeckCount);
    printf("\tcoins = %d, expected = %d\n", testG.coins, GnewCoins);
    printf("\n");
    
    // ----------- Current player should receive exactly 2 treasure cards --------------
    printf("Testing: Current player should receive exactly 2 treasure cards.\n");
    if(testNumTreasureCards != expectedTreasureCards) {
        if(testNumTreasureCards < expectedTreasureCards) {
            num = expectedTreasureCards - testNumTreasureCards;
            printf("\t**FAILED**: Current player drew %d too few treasure cards.\n\n", num);
            failedTests++;
        } else { // Current player drew too many treasure cards
            num = testNumTreasureCards - expectedTreasureCards;
            printf("\t**FAILED**: Current player drew %d too many treasure cards.\n\n", num);
            failedTests++;
        }
    } else {
        printf("\tPASSED: Current player received the correct number of treasure cards.\n\n");
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
    
    // ----------- Current player should receive exactly 2 coins --------------
    printf("Testing: Current player should receive exactly 2 coins.\n");
    if(testG.coins != GnewCoins) {
        if(testG.coins < GnewCoins) {
            num = GnewCoins - testG.coins;
            printf("\t**FAILED**: Current player has %d too few coins.\n\n", num);
            failedTests++;
        } else { // Current player hass too many coins
            num = testG.coins - GnewCoins;
            printf("\t**FAILED**: Current player has %d too many coins.\n\n", num);
            failedTests++;
        }
    } else {
        printf("\tPASSED: Current player has the correct number of coins.\n\n");
        passedTests++;
    }
    
    // ----------- Current player should draw treasure cards from his own deck --------------
    printf("Testing: Current player should draw treasure cards from his own deck.\n");
    errorCount = 0;
    card1 = testG.hand[thisPlayer][testG.handCount[thisPlayer] - 1];
    card2 = testG.hand[thisPlayer][handpos]; // since last card is swapped with Adventurer's position when it is discarded
    if(card1 != G.deck[thisPlayer][GdeckCount - 2]) {
        printf("\t**FAILED**: The first treasure card was not drawn from the current player's deck.\n");
        failedTests++;
        errorCount++;
    }
    if(card2 != G.deck[thisPlayer][GdeckCount - 4]) {
        printf("\t**FAILED**: The second treasure card was not drawn from the current player's deck.\n");
        failedTests++;
        errorCount++;
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: Treasure cards were drawn from the correct player's deck.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // ----------- No state change should occur for other players. --------------
    printf("Testing: No state change should occur for other players.\n");
    errorCount = 0;
    if(testG.handCount[otherPlayer] != G.handCount[otherPlayer]) {
        printf("\t**FAILED**: Other player's hand count has changed.\n");
        failedTests++;
        errorCount++;
    }
    if(testG.deckCount[otherPlayer] != G.deckCount[otherPlayer]) {
        printf("\t**FAILED**: Other player's deck count has changed.\n");
        failedTests++;
        errorCount++;
    }
    if(testG.discardCount[otherPlayer] != G.discardCount[otherPlayer]) {
        printf("\t**FAILED**: Other player's discard count has changed.\n");
        failedTests++;
        errorCount++;
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: No state change has occured for the other player.\n\n");
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
    
    // ----------- No state change should occur for the victory card piles. --------------
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
        printf("\tPASSED: No state change has occured for the victory card piles.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // ----------- Current player's discard pile should have Adventurer on top --------------
    printf("Testing: Current player's discard pile should have Adventurer on top.\n");
    if(testG.discardCount[thisPlayer] > 0) {
        if(testG.discard[thisPlayer][testG.discardCount[thisPlayer] - 1] != adventurer) {
            printf("\t**FAILED**: The last card in current player's discard pile is not Adventurer.\n\n");
            failedTests++;
        } else {
            printf("\tPASSED: The last card in current player's discard pile is Adventurer.\n\n");
            passedTests++;
        }
    } else {
        printf("\t**FAILED**: The current player's test discard pile is empty.\n\n");
        failedTests++;
    }
    
    // ----------- Current player's discard pile should have all non-treasure revealed cards below Adventurer in correct order --------------
    printf("Testing: Current player's discard pile should have all non-treasure revealed cards below Adventurer in correct order.\n");
    errorCount = 0;
    if(testG.discardCount[thisPlayer] > 0) {
        if(testG.discard[thisPlayer][testG.discardCount[thisPlayer] - 2] != feast) {
            printf("\t**FAILED**: The second card in current player's discard pile is not Feast.\n");
            failedTests++;
            errorCount++;
        }
        if(testG.discard[thisPlayer][testG.discardCount[thisPlayer] - 3] != village) {
            printf("\t**FAILED**: The third card in current player's discard pile is not Village.\n");
            failedTests++;
            errorCount++;
        }
        
        if(errorCount == 0) {
            printf("\tPASSED: The non-treasure revealed cards are in the correct spots in the discard pile.\n\n");
            passedTests++;
        } else {
            printf("\n");
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