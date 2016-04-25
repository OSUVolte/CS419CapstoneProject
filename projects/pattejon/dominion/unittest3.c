/* ---------------------------------------------------------------------
* Jon Patterson
* Assignment 3
* unittest3.c
* discardCard() method
* This was adapted from the testupdateCoins.c code provided by the instructor
* but I have added additional code to test the game state when random hands
* were populated with different cards
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
// set ASSERTS_ON to 0 to disable asserts for investigating gcov
#define ASSERTS_ON 0

int main() {
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount, playedCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int error = 0;
    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);
    printf ("Testing discardCard():\n");
    for (p = 0; p < numPlayer; p++){
        handCount = G.handCount[p];
        playedCount = G.playedCardCount;
        while(handCount > 0){
            handCount--;
            playedCount++;
            discardCard(0, p, &G, 0);
            #if (NOISY_TEST == 1)
            printf("Test player %d with %d cards in hand and %d played.\n", p, handCount, playedCount);
            printf("Hand = %d, Expected = %d\n", G.handCount[p], handCount);
            printf("Played = %d, Expected = %d\n", G.playedCardCount, playedCount);
            #endif
            #if (ASSERTS_ON == 1)
            assert(G.playedCardCount == playedCount);
            assert(G.handCount[p] == handCount);
            #endif
            if(G.playedCardCount != playedCount) error = 1;
            if(G.handCount[p] != handCount) error = 1;
        }
        // hand should be empty now, try to discard a card again
        discardCard(0, p, &G, 0);
        #if (NOISY_TEST == 1)
        printf("Empty hand, played = %d, Expected = %d\n", G.playedCardCount, playedCount);
        #endif
        #if (ASSERTS_ON == 1)
        assert(G.playedCardCount == playedCount);
        #endif
        if(G.playedCardCount != playedCount) error = 1;
        if(error == 1){
            printf("Errors were encountered.\n");
            return 1;
        }

    }
    return 0;
}