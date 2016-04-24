/* ---------------------------------------------------------------------
* Jon Patterson
* Assignment 3
* unittest1.c
* updatecoins() method
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
#include <time.h>
#include <stdlib.h>


// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    srand(time(NULL));
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    int testhand[MAX_HAND];

    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("Testing updateCoins():\n");
    for (p = 0; p < numPlayer; p++){
        for (handCount = 0; handCount <= maxHandCount; handCount++){
            for (bonus = 0; bonus <= maxBonus; bonus++){
                #if (NOISY_TEST == 1)
                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
                #endif
                // clear the game state
                memset(&G, 23, sizeof(struct gameState));
                // initialize a new game
                r = initializeGame(numPlayer, k, seed, &G);
                // set the number of cards in hand to 
                G.handCount[p] = handCount;
                memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
                updateCoins(p, &G, bonus);
                #if (NOISY_TEST == 1)
                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
                #endif
                assert(G.coins == handCount * 1 + bonus); //check coins number correct

                memcpy(G.hand[p], silvers, sizeof(int) * handCount); // set all the cards to silver
                updateCoins(p, &G, bonus);
                #if (NOISY_TEST == 1)
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
                #endif
                assert(G.coins == handCount * 2 + bonus); // check if the number of coins is correct

                memcpy(G.hand[p], golds, sizeof(int) * handCount); // set all the cards to gold
                updateCoins(p, &G, bonus);
                #if (NOISY_TEST == 1)
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
                #endif
                assert(G.coins == handCount * 3 + bonus); // check if the number of coins is correct

                // We would also like to check random hand compositions
                int t;
                for(t=0; t <= 100; t++){
                    int testHandSum = 0;
                    for(i=0; i < handCount; i++){
                        int t = rand() % 3;
                        if(t == 0){
                            testhand[i] = copper;
                            testHandSum += 1;
                            #if (NOISY_TEST == 1)
                            printf("hand position %d is copper\n", i);
                            #endif
                        }else if(t == 1){
                            testhand[i] = silver;
                            testHandSum += 2;
                            #if (NOISY_TEST == 1)
                            printf("hand position %d is silver\n", i);
                            #endif
                        }else if(t == 2){
                            testhand[i] = gold;
                            testHandSum += 3;
                            #if (NOISY_TEST == 1)
                            printf("hand position %d is gold\n", i);
                            #endif
                        }
                    }
                    memcpy(G.hand[p], testhand, sizeof(int) * handCount);
                    updateCoins(p, &G, bonus);
                    #if (NOISY_TEST == 1)
                    printf("Random iteration %d: G.coins = %d, expected = %d\n", t, G.coins, testHandSum + bonus);
                    #endif
                    assert(G.coins == testHandSum + bonus );

                }

            }
            
        }
    }
    return 0;
}