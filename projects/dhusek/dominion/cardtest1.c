/*
 * cardtest1.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

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
    int num;
    int card1, card2, card3, card4;
    int deckCard1, deckCard2, deckCard3, deckCard4;
    int errorCount = 0;
    const char* cards[27] = {"curse", "estate", "duchy", "province", "copper", "silver",
                        "gold", "adventurer", "council room", "feast", "gardens",
                        "mine", "remodel", "smithy", "village", "baron", "great hall",
                        "minion", "steward", "tribute", "ambassador", "cutpurse",
                        "embargo", "outpost", "salvager", "sea hag", "treasure map"};
    
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    
    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    
    // set card in position 0 to Smithy
    G.hand[thisPlayer][handpos] = smithy;
    GdeckCount = G.deckCount[thisPlayer];
    
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    // play smithy card in testG game
    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
    
    newCards = 3;
    extraCoins = 0;
    GnewHandCount = G.handCount[thisPlayer] + newCards - discarded;
    GnewDeckCount = GdeckCount - newCards + shuffledCards;
    GnewCoins = G.coins + extraCoins;
    
    printf("Current game state compared with expected state:\n");
    printf("\thand count = %d, expected = %d\n", testG.handCount[thisPlayer], GnewHandCount);
    printf("\tdeck count = %d, expected = %d\n", testG.deckCount[thisPlayer], GnewDeckCount);
    printf("\tcoins = %d, expected = %d\n", testG.coins, GnewCoins);
    printf("\n");
    
    // ----------- Current player should receive exactly 3 cards --------------
    printf("Testing: Current player should receive exactly 3 cards.\n");
    if(testG.handCount[thisPlayer] != GnewHandCount) {
        if(testG.handCount[thisPlayer] < GnewHandCount) {
            num = GnewHandCount - testG.handCount[thisPlayer];
            printf("\tFAILED: Current player drew %d too few cards.\n\n", num);
        } else { // Current player drew too many cards
            num = testG.handCount[thisPlayer] - GnewHandCount;
            printf("\tFAILED: Current player drew %d too many cards.\n\n", num);
        }
    } else {
        printf("\tPASSED: Current player received the correct number of cards.\n\n");
    }
    
    // ----------- Current player's deck should be 3 cards smaller --------------
    printf("Testing: Current player's deck should be 3 cards smaller.\n");
    if(testG.deckCount[thisPlayer] != GnewDeckCount) {
        if(testG.deckCount[thisPlayer] < GnewDeckCount) {
            num = GnewDeckCount - testG.deckCount[thisPlayer];
            printf("\tFAILED: Current player drew %d too many cards.\n\n", num);
        } else { // Current player drew too few cards
            num = testG.deckCount[thisPlayer] - GnewDeckCount;
            printf("\tFAILED: Current player drew %d too few cards.\n\n", num);
        }
    } else {
        printf("\tPASSED: Current player's deck contains the correct number of cards.\n\n");
    }
    
    // ----------- Current player should receive exactly zero coins --------------
    printf("Testing: Current player should receive exactly zero coins.\n");
    if(testG.coins != GnewCoins) {
        if(testG.coins < GnewCoins) {
            num = GnewCoins - testG.coins;
            printf("\tFAILED: Current player has %d too few coins.\n\n", num);
        } else { // Current player hass too many coins
            num = testG.coins - GnewCoins;
            printf("\tFAILED: Current player has %d too many coins.\n\n", num);
        }
    } else {
        printf("\tPASSED: Current player has the correct number of coins.\n\n");
    }
    
    // ----------- Current player should draw 3 cards from his own deck --------------
    printf("Testing: Current player should draw 3 cards from his own deck.\n");
    errorCount = 0;
    card1 = testG.hand[thisPlayer][testG.handCount[thisPlayer] - 1];
    card2 = testG.hand[thisPlayer][testG.handCount[thisPlayer] - 2];
    card3 = testG.hand[thisPlayer][testG.handCount[thisPlayer] - 3];
    deckCard1 = G.deck[thisPlayer][G.deckCount[thisPlayer] - 1];
    deckCard2 = G.deck[thisPlayer][G.deckCount[thisPlayer] - 2];
    deckCard3 = G.deck[thisPlayer][G.deckCount[thisPlayer] - 3];
    if(card1 != deckCard1) {
        printf("\tFAILED: The first card was not drawn from the current player's deck.\n");
        errorCount++;
    }
    if(card2 != deckCard2) {
        printf("\tFAILED: The second card was not drawn from the current player's deck.\n");
        errorCount++;
    }
    if(card3 != deckCard3) {
        printf("\tFAILED: The second card was not drawn from the current player's deck.\n");
        errorCount++;
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: Cards were drawn from the correct player's deck.\n\n");
    } else {
        printf("\n");
    }
    
    // ----------- No state change should occur for other players. --------------
    printf("Testing: No state change should occur for other players.\n");
    errorCount = 0;
    if(testG.handCount[otherPlayer] != G.handCount[otherPlayer]) {
        printf("\tFAILED: Other player's hand count has changed.\n");
        errorCount++;
    }
    if(testG.deckCount[otherPlayer] != G.deckCount[otherPlayer]) {
        printf("\tFAILED: Other player's deck count has changed.\n");
        errorCount++;
    }
    if(testG.discardCount[otherPlayer] != G.discardCount[otherPlayer]) {
        printf("\tFAILED: Other player's discard count has changed.\n");
        errorCount++;
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: No state change has occured for the other player.\n\n");
    } else {
        printf("\n");
    }
    
    // ----------- No state change should occur for the victory card piles. --------------
    printf("Testing: No state change should occur for the victory card piles.\n");
    errorCount = 0;
    if(supplyCount(estate, &testG) != supplyCount(estate, &G)) {
        printf("\tFAILED: Supply of %s cards has changed.\n", cards[estate]);
        errorCount++;
    }
    if(supplyCount(duchy, &testG) != supplyCount(duchy, &G)) {
        printf("\tFAILED: Supply of %s cards has changed.\n", cards[duchy]);
        errorCount++;
    }
    if(supplyCount(province, &testG) != supplyCount(province, &G)) {
        printf("\tFAILED: Supply of %s cards has changed.\n", cards[province]);
        errorCount++;
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: No state change has occured for the victory card piles.\n\n");
    } else {
        printf("\n");
    }
    
    // ----------- No state change should occur for the treasure card piles. --------------
    printf("Testing: No state change should occur for the treasure card piles.\n");
    errorCount = 0;
    if(supplyCount(copper, &testG) != supplyCount(copper, &G)) {
        printf("\tFAILED: Supply of %s cards has changed.\n", cards[copper]);
        errorCount++;
    }
    if(supplyCount(silver, &testG) != supplyCount(silver, &G)) {
        printf("\tFAILED: Supply of %s cards has changed.\n", cards[silver]);
        errorCount++;
    }
    if(supplyCount(gold, &testG) != supplyCount(gold, &G)) {
        printf("\tFAILED: Supply of %s cards has changed.\n", cards[gold]);
        errorCount++;
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: No state change has occured for the treasure card piles.\n\n");
    } else {
        printf("\n");
    }
    
    // ----------- No state change should occur for the victory card piles. --------------
    printf("Testing: No state change should occur for the kingdom card piles.\n");
    errorCount = 0;
    for(i = 0; i < 10; i++) {
        if(supplyCount(k[i], &testG) != supplyCount(k[i], &G)) {
            printf("\tFAILED: Supply of %s cards has changed.\n", cards[k[i]]);
            errorCount++;
        }
    }
    
    if(errorCount == 0) {
        printf("\tPASSED: No state change has occured for the victory card piles.\n\n");
    } else {
        printf("\n");
    }
    
    // ----------- Current player's discard pile should have Smithy on top --------------
    printf("Testing: Current player's discard pile should have Smithy on top.\n");
    discardCard(handpos, thisPlayer, &G, 0);
    if(testG.discard[thisPlayer][testG.discardCount[thisPlayer] - 1] != smithy &&
       testG.discard[thisPlayer][testG.discardCount[thisPlayer] - 1] !=
       G.discard[thisPlayer][G.discardCount[thisPlayer] - 1]) {
        printf("\tFAILED: The last card in current player's discard pile is not correct.");
    } else {
        printf("\tPASSED: Current player's discard pile is correct and has Smithy on top.\n\n");
    }
    
    //---------------------------------------------------------------------------
    
    printf(" >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
    
    
    return 0;
}