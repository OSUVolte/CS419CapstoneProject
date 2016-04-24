/* ---------------------------------------------------------------------
* Jon Patterson
* Assignment 3
* unittest2.c
* buyCard() method
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
#define ASSERTS_ON 1

int main() {
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount, deckCount, discardCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);

    for (p = 0; p < numPlayer; p++){
        handCount = G.handCount[p];
        deckCount = G.deckCount[p];
        discardCount = G.discardCount[p];
        while(deckCount > 0){
            handCount++; // increment hand count by one
            deckCount--; // decrement deck count by one
            drawCard(p, &G);
            #if (NOISY_TEST == 1)
            printf("Test player %d with %d cards in hand and %d in deck.\n", p, handCount, deckCount);
            printf("Hand = %d, Expected = %d\n", G.handCount[p], handCount);
            #endif
            #if (ASSERTS_ON == 1)
            assert(G.handCount[p] == handCount);
            #endif
            #if (NOISY_TEST == 1)
            printf("Deck = %d, Expected = %d\n", G.deckCount[p], deckCount);
            #endif
            #if (ASSERTS_ON == 1)
            assert(G.deckCount[p] == deckCount);
            #endif
        }
        // deck is empty, but discard pile is also empty, expect this to fail and leave counts unchanged
        drawCard(p, &G);
        #if (NOISY_TEST == 1)
        printf("Test player %d with %d cards in hand and %d in deck.\n", p, handCount, deckCount);
        printf("Hand = %d, Expected = %d\n", G.handCount[p], handCount);
        #endif
        #if (ASSERTS_ON == 1)
        assert(G.handCount[p] == handCount);
        #endif
        #if (NOISY_TEST == 1)
        printf("Deck = %d, Expected = %d\n", G.deckCount[p], deckCount);
        #endif
        #if (ASSERTS_ON == 1)
        assert(G.deckCount[p] == deckCount);
        #endif

        //discard all of the cards and try drawing again
        while(G.handCount > 0){
            discardCard(0, p, &G, 0);
        }
        deckCount = handCount; //we're going to assume all the cards were shuffled back into the deck
        handCount = G.handCount[p]; // this should be zero, not testing that here though, will test that function in another test
        handCount++; //increment hand count by one
        deckCount--;
        drawCard(p, &G); //code implements a shuffle here, which is probably bad but w/e
        #if (NOISY_TEST == 1)
        printf("Test player %d with %d cards in hand and %d in deck.\n", p, handCount, deckCount);
        printf("Hand = %d, Expected = %d\n", G.handCount[p], handCount);
        #endif
        #if (ASSERTS_ON == 1)
        assert(G.handCount[p] == handCount);
        #endif
        #if (NOISY_TEST == 1)
        printf("Deck = %d, Expected = %d\n", G.deckCount[p], deckCount);
        #endif
        #if (ASSERTS_ON == 1)
        assert(G.deckCount[p] == deckCount);
        #endif
        // now do it for the other players
    }

return 0;
}