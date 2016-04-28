#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkIsGameOver(int p, struct gameState *post) {
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));
    
    int supplyCountBackup = pre.supplyCount[province];
    
    pre.supplyCount[province] = 1;

    assert(isGameOver(&pre) == 0);
    
    pre.supplyCount[province] = 0;

    assert(isGameOver(&pre) == 1);
    
    
    
    pre.supplyCount[province] = supplyCountBackup;
    
    int supplyCount1Backup = pre.supplyCount[0];
    int supplyCount2Backup = pre.supplyCount[1];
    int supplyCount3Backup = pre.supplyCount[2];
    
    //if three supply pile are at 0, the game ends
    pre.supplyCount[0] = 0;
    pre.supplyCount[1] = 0;
    pre.supplyCount[2] = 0;
    int j = 0;
    for (int i = 0; i < 25; i++)
    {
        if (pre.supplyCount[i] == 0)
        {
            j++;
        }
    }
    
    assert( j >= 3);
    /* if ( j >= 3)
    {
        return 1;
    }
    */
    
    pre.supplyCount[0] = supplyCount1Backup;
    pre.supplyCount[1] = supplyCount2Backup;
    pre.supplyCount[2] = supplyCount3Backup;
    
    
    
    assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);
}

int main () {
    
    int i, n, r, p, deckCount, discardCount, handCount;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
    
    struct gameState G;
    
    printf ("Testing isGameOver.\n");
    
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
        checkIsGameOver(p, &G);
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
                    checkIsGameOver(p, &G);
                }
            }
        }
    }
    
    return 0;
}
