/*
 * randomtestadventurer.c
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
#include <time.h>

#define TESTCARD "adventurer"

int randomTestAdventurer() {
    int i;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
    struct gameState G, testG;
    int k[10] = {remodel, feast, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    int treasure[3] = {copper, silver, gold};
    int GdeckCount;
    int num;
    int GnumTreasureCards = 0;
    int GnewCoins;
    int expectedTreasureCards = 0;
    int testNumTreasureCards = 0;
    int deckNumCards;
    int discardNumCards;
    int numTreasureCards, numDeckTreasureCards = 0, numDiscardTreasureCards = 0;
    int randomNum;
    int errorCount = 0;
    int failedTests = 0;
    int passedTests = 0;
    const char* cards[27] = {"curse", "estate", "duchy", "province", "copper", "silver",
        "gold", "adventurer", "council room", "feast", "gardens",
        "mine", "remodel", "smithy", "village", "baron", "great hall",
        "minion", "steward", "tribute", "ambassador", "cutpurse",
        "embargo", "outpost", "salvager", "sea hag", "treasure map"};
    
    // get new random seed
    seed = rand();
    
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
    
    // get random number for the size of the deck
    deckNumCards = rand() % 5;
    //printf("Random deck number: %d\n", deckNumCards);
    
    G.deckCount[thisPlayer] = deckNumCards;
    
    // make random deck with no treasure cards
    for(i = 0; i < deckNumCards; i++) {
        num = rand() % 5;
        G.deck[thisPlayer][i] = k[num];
    }
    if(deckNumCards > 0) {
        numDeckTreasureCards = rand() % 4;
        
        // add 0-4 treasure cards in random spots
        for(i = 0; i < numDeckTreasureCards; i++) {
            num = rand() % deckNumCards;
            randomNum = rand() % 3;
            G.deck[thisPlayer][num] = treasure[randomNum];
        }
    }
    
    // count treasure cards in G deck since treasure cards could randomly get added
    // on top of each other in the same slot
    numDeckTreasureCards = 0;
    for(i = 0; i < G.deckCount[thisPlayer]; i++) {
        if(G.deck[thisPlayer][i] == copper || G.deck[thisPlayer][i] == silver ||
           G.deck[thisPlayer][i] == gold) {
            numDeckTreasureCards++;
        }
    }
    
    // get random  number for the size of the discard
    discardNumCards = rand() % 5;
    
    G.discardCount[thisPlayer] = discardNumCards;
    
    // make random discard with no treasure cards
    for(i = 0; i < discardNumCards; i++) {
        num = rand() % 5;
        G.discard[thisPlayer][i] = k[num];
    }
    
    if(discardNumCards > 0) {
        numDiscardTreasureCards = rand() % 4;
        
        // add 0-4 treasure cards in random spots
        for(i = 0; i < numDiscardTreasureCards; i++) {
            num = rand() % discardNumCards;
            randomNum = rand() % 3;
            G.discard[thisPlayer][num] = treasure[randomNum];
        }
    }
    // count treasure cards in G discard since treasure cards could randomly get added
    // on top of each other in the same slot
    numDiscardTreasureCards = 0;
    for(i = 0; i < G.discardCount[thisPlayer]; i++) {
        if(G.discard[thisPlayer][i] == copper || G.discard[thisPlayer][i] == silver ||
           G.discard[thisPlayer][i] == gold) {
            numDiscardTreasureCards++;
        }
    }
    
    numTreasureCards = numDeckTreasureCards + numDiscardTreasureCards;
    if (numTreasureCards > 2) {
        numTreasureCards = 2;
    }
    expectedTreasureCards = GnumTreasureCards + numTreasureCards;
    
    GdeckCount = G.deckCount[thisPlayer];
    //printf("GdeckCount: %d\n", GdeckCount);
    
    printDeck(thisPlayer, &G);
    printDiscard(thisPlayer, &G);
    
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    // play adventurer card
    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
    //printHand(thisPlayer, &testG);
    
    // count treasure cards in testG hand
    for(i = 0; i < testG.handCount[thisPlayer]; i++) {
        if(testG.hand[thisPlayer][i] == copper || testG.hand[thisPlayer][i] == silver ||
           testG.hand[thisPlayer][i] == gold) {
            testNumTreasureCards++;
        }
    }
    
    // minimum value of coins testG should have
    GnewCoins = G.coins + numTreasureCards;
    
    // ----------- Current player should receive exactly 2 treasure cards --------------
    
    if(testNumTreasureCards != expectedTreasureCards) {
        if(testNumTreasureCards < expectedTreasureCards) {
            num = expectedTreasureCards - testNumTreasureCards;
            printf("Testing: Current player should receive exactly %d treasure cards.\n", expectedTreasureCards);
            printf("\t**FAILED**: Current player drew %d too few treasure cards.\n\n", num);
            failedTests++;
        } else { // Current player drew too many treasure cards
            num = testNumTreasureCards - expectedTreasureCards;
            printf("Testing: Current player should receive exactly %d treasure cards.\n", expectedTreasureCards);
            printf("\t**FAILED**: Current player drew %d too many treasure cards.\n\n", num);
            failedTests++;
        }
    } else {
        //printf("Testing: Current player should receive exactly %d treasure cards.\n", expectedTreasureCards);
        //printf("\tPASSED: Current player received the correct number of treasure cards.\n\n");
        passedTests++;
    }
    
    // ----------- Current player should receive 2 coins --------------
    
    if(testG.coins < GnewCoins) {
        num = GnewCoins - testG.coins;
        printf("Testing: Current player should receive %d coins.\n", numTreasureCards);
        printf("\t**FAILED**: Current player has %d too few coins.\n\n", num);
        failedTests++;
    } else {
        //printf("Testing: Current player should receive exactly %d coins.\n", numTreasureCards);
        //printf("\tPASSED: Current player has the correct number of coins.\n\n");
        passedTests++;
    }
    
    // ----------- No state change should occur for other players. --------------
    errorCount = 0;
    if(testG.handCount[otherPlayer] != G.handCount[otherPlayer]) {
        printf("Testing: No state change should occur for other players.\n");
        printf("\t**FAILED**: Other player's hand count has changed.\n");
        failedTests++;
        errorCount++;
    }
    if(testG.deckCount[otherPlayer] != G.deckCount[otherPlayer]) {
        printf("Testing: No state change should occur for other players.\n");
        printf("\t**FAILED**: Other player's deck count has changed.\n");
        failedTests++;
        errorCount++;
    }
    if(testG.discardCount[otherPlayer] != G.discardCount[otherPlayer]) {
        printf("Testing: No state change should occur for other players.\n");
        printf("\t**FAILED**: Other player's discard count has changed.\n");
        failedTests++;
        errorCount++;
    }
    
    if(errorCount == 0) {
        //printf("Testing: No state change should occur for other players.\n");
        //printf("\tPASSED: No state change has occured for the other player.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // ----------- No state change should occur for the victory card piles. --------------
    
    errorCount = 0;
    if(supplyCount(estate, &testG) != supplyCount(estate, &G)) {
        printf("Testing: No state change should occur for the victory card piles.\n");
        printf("\t**FAILED**: Supply of %s cards has changed.\n", cards[estate]);
        failedTests++;
        errorCount++;
    }
    if(supplyCount(duchy, &testG) != supplyCount(duchy, &G)) {
        printf("Testing: No state change should occur for the victory card piles.\n");
        printf("\t**FAILED**: Supply of %s cards has changed.\n", cards[duchy]);
        failedTests++;
        errorCount++;
    }
    if(supplyCount(province, &testG) != supplyCount(province, &G)) {
        printf("Testing: No state change should occur for the victory card piles.\n");
        printf("\t**FAILED**: Supply of %s cards has changed.\n", cards[province]);
        failedTests++;
        errorCount++;
    }
    
    if(errorCount == 0) {
        //printf("Testing: No state change should occur for the victory card piles.\n");
        //printf("\tPASSED: No state change has occured for the victory card piles.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // ----------- No state change should occur for the treasure card piles. --------------

    errorCount = 0;
    if(supplyCount(copper, &testG) != supplyCount(copper, &G)) {
        printf("Testing: No state change should occur for the treasure card piles.\n");
        printf("\t**FAILED**: Supply of %s cards has changed.\n", cards[copper]);
        failedTests++;
        errorCount++;
    }
    if(supplyCount(silver, &testG) != supplyCount(silver, &G)) {
        printf("Testing: No state change should occur for the treasure card piles.\n");
        printf("\t**FAILED**: Supply of %s cards has changed.\n", cards[silver]);
        failedTests++;
        errorCount++;
    }
    if(supplyCount(gold, &testG) != supplyCount(gold, &G)) {
        printf("Testing: No state change should occur for the treasure card piles.\n");
        printf("\t**FAILED**: Supply of %s cards has changed.\n", cards[gold]);
        failedTests++;
        errorCount++;
    }
    
    if(errorCount == 0) {
        //printf("Testing: No state change should occur for the treasure card piles.\n");
        //printf("\tPASSED: No state change has occured for the treasure card piles.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // ----------- No state change should occur for the kingdom card piles. --------------
    
    errorCount = 0;
    for(i = 0; i < 10; i++) {
        if(supplyCount(k[i], &testG) != supplyCount(k[i], &G)) {
            printf("Testing: No state change should occur for the kingdom card piles.\n");
            printf("\t**FAILED**: Supply of %s cards has changed.\n", cards[k[i]]);
            failedTests++;
            errorCount++;
        }
    }
    
    if(errorCount == 0) {
        //printf("Testing: No state change should occur for the kingdom card piles.\n");
        //printf("\tPASSED: No state change has occured for the kingdom card piles.\n\n");
        passedTests++;
    } else {
        printf("\n");
    }
    
    // ----------- Current player's discard pile should have Adventurer on top --------------
    
    if(testG.discardCount[thisPlayer] > 0) {
        if(testG.discard[thisPlayer][testG.discardCount[thisPlayer] - 1] != adventurer) {
            printf("Testing: Current player's discard pile should have Adventurer on top.\n");
            printf("\t**FAILED**: The last card in current player's discard pile is not Adventurer.\n\n");
            failedTests++;
        } else {
            //printf("Testing: Current player's discard pile should have Adventurer on top.\n");
            //printf("\tPASSED: The last card in current player's discard pile is Adventurer.\n\n");
            passedTests++;
        }
    } else {
        printf("Testing: Current player's discard pile should have Adventurer on top.\n");
        printf("\t**FAILED**: The current player's test discard pile is empty.\n\n");
        failedTests++;
    }
    
    //---------------------------------------------------------------------------
    
    printf(" >>>>> SUCCESS: Testing complete %s <<<<<\n", TESTCARD);
    printf("\t%d tests **FAILED**.\n", failedTests);
    //printf("\t%d tests PASSED.\n\n", passedTests);
    
    
    return 0;
}

int main() {
    srand(time(NULL));
    int randomTests = 1000;
    int i;
    for(i = 0; i < randomTests; i++) {
        randomTestAdventurer();
    }
}