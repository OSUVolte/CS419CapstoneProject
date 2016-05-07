#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkNumHandCards(int p, struct gameState *post) {
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));
    
    int whoseTurnBackup = pre.whoseTurn;
    
    pre.whoseTurn = 0;
    
    
    //int playerhandcountBackup = pre.handCount[p];
    int player1handcountBackup = pre.handCount[0];
    
    
    
    
    pre.handCount[0] = 1;
    
    //printf("XXX:%d\n", numHandCards(&pre));
    
    assert(numHandCards(&pre) == 1);
    
    pre.handCount[0] = player1handcountBackup;
    
    pre.whoseTurn = whoseTurnBackup;
    
    assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);
    
}

int main () {
    
    int i, n, r, p, deckCount, discardCount, handCount;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
    
    struct gameState G;
    
    printf ("Testing numHandCards.\n");
    
    printf ("RANDOM TESTS.\n");
    
    SelectStream(2);
    PutSeed(3);
    
    for (n = 0; n < 2000; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        p = floor(Random() * 2);
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        checkNumHandCards(p, &G);
    }
    
    printf ("ALL TESTS OK\n");
    
    exit(0);
    
    printf ("SIMPLE FIXED TESTS.\n");
    for (p = 0; p < 2; p++) {
        for (deckCount = 0; deckCount < 5; deckCount++) {
            for (discardCount = 0; discardCount < 5; discardCount++) {
                for (handCount = 0; handCount < 5; handCount++) {
                    memset(&G, 23, sizeof(struct gameState));
                    r = initializeGame(2, k, 1, &G);
                    G.deckCount[p] = deckCount;
                    memset(G.deck[p], 0, sizeof(int) * deckCount);
                    G.discardCount[p] = discardCount;
                    memset(G.discard[p], 0, sizeof(int) * discardCount);
                    G.handCount[p] = handCount;
                    memset(G.hand[p], 0, sizeof(int) * handCount);
                    checkNumHandCards(p, &G);
                }
            }
        }
    }
    
    return 0;
}
