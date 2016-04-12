#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 1

int main() {
    struct gameState G;
    int players = 2;
    int seed = 1;
    int gameOver = 0;
    int result = 0;
    int kingdomCards[10] = {
            adventurer,
            gardens,
            embargo, village,
            minion, mine,
            cutpurse,
            sea_hag,
            tribute,
            smithy
    };

    initializeGame(players, kingdomCards, seed, &G);

    printf("Testing gainCard():\n");

    if (VERBOSE) printf("\tTest card is not gained if supply count equals zero...\n");
    G.supplyCount[smithy] = 0;                       // set the supply count for this card to 0
    result = gainCard(smithy, &G, 1, 1);
    if (VERBOSE) printf("\t\tReturn value = %d, expected -1\n", result);
    assert(result == -1);

    initializeGame(players, kingdomCards, seed, &G);

    if (VERBOSE) printf("\tTest card gained is added to deck...\n");
    result = gainCard(0, &G, 1, 1);
    int deck = G.deck[1][G.deckCount[1]];
    if (VERBOSE) printf("\t\tLast card in deck = %d, expected 0\n", result);
    assert(G.deck[1][G.deckCount[1]] == 0);
    if (VERBOSE) printf("\t\tP1 deck count = %d, expected 11\n", G.deckCount[1]);
    assert(G.deckCount[1] == 11);

    initializeGame(players, kingdomCards, seed, &G);

    if (VERBOSE) printf("\tTest card gained is added to hand...\n");
    result = gainCard(0, &G, 2, 1);
    int hand = G.hand[1][G.handCount[1]];
    if (VERBOSE) printf("\t\tLast card in hand = %d, expected 0\n", result);
    assert(G.hand[1][G.handCount[1]] == 0);
    if (VERBOSE) printf("\t\tP1 hand count = %d, expected 1\n", G.handCount[1]);
    assert(G.handCount[1] == 1);

    initializeGame(players, kingdomCards, seed, &G);

    if (VERBOSE) printf("\tTest card gained is added to discard...\n");
    int supplyCount = G.supplyCount[0];
    result = gainCard(0, &G, 0, 1);
    int discard = G.discard[1][G.discardCount[1]];
    if (VERBOSE) printf("\t\tLast card in hand = %d, expected 0\n", result);
    assert(G.discard[1][G.discardCount[1]] == 0);
    if (VERBOSE) printf("\t\tP1 discard count = %d, expected 1\n", G.discardCount[1]);
    assert(G.discardCount[1] == 1);

    if (VERBOSE) printf("\tTest supply pile count is decremented...\n");
    if (VERBOSE) printf("\t\tSupply count = %d, expected %d\n", G.supplyCount[0], supplyCount - 1);
    assert(G.supplyCount[0] == supplyCount - 1);

    printf("All tests passed.\n");
}