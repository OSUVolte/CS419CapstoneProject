/*
 * unittest1.c
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

#define TESTFUNCTION "discardCard"

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
    const char* cards[27] = {"curse", "estate", "duchy", "province", "copper", "silver",
        "gold", "adventurer", "council room", "feast", "gardens",
        "mine", "remodel", "smithy", "village", "baron", "great hall",
        "minion", "steward", "tribute", "ambassador", "cutpurse",
        "embargo", "outpost", "salvager", "sea hag", "treasure map"};
    
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    
    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    
    