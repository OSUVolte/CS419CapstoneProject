/* -----------------------------------------------------------------------
 * Diana O'Haver
 * File: unittest2.c
 *
 * Unit test of function in dominion.c:
 *      updateCoins
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct gameState gameOrig;          // original game state
    // to initialize the game, you need the number of players, kingdom cards, a random seed, and the game state
    struct gameState gameTest;          // game state for testing
    int kc[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int i;                              // we'll probably need a counter at some point
    int player1;                            // only testing coin update, so no need for player2
    int players = 2;
    int numTests = 1;                   // run each test once
    int startCoins = 0;

    /**************************************************
    * The following conditions occur by the end of the updateCoins function:
    * - for every copper, coins increased by 1
    * - for every silver, coins increased by 2
    * - for every gold, coins increased by 3
    * - for every bonus passed into function, coins increased by bonus amount
    **************************************************/

     printf("** Function being tested: updateCoins **\n\n");

    for (i = 0; i < numTests; i++) {

        // assign player number
        player1 = 0;

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing Gold ***/
        // assemble the player's hand manually
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = gold;          // +3
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = minion;
        gameTest.hand[player1][4] = feast;

        // after updateCoins is called, player should only have 3 coins
        updateCoins(player1, &gameTest, 0);
        printf("TEST 1:\n\n");
        printf("Expecting one gold card in hand to result in total of 3 coins for player1.\n\n");
        if (gameTest.coins == startCoins + 3) {
            printf("*** Passed test ***\n");
            printf("Player1 has %d coins\n\n", gameTest.coins);
        }
        else {
            printf("*** Failed test ***\n");
            printf("Player1 has %d coins\n\n", gameTest.coins);
        }


        // reinitialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing Silver ***/
        // assemble the player's hand manually
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = silver;          // +2
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = minion;
        gameTest.hand[player1][4] = feast;

        // after updateCoins is called, player should only have 2 coins
        updateCoins(player1, &gameTest, 0);
        printf("TEST 2:\n\n");
        printf("Expecting one silver card in hand to result in total of 2 coins for player1.\n\n");
        if (gameTest.coins == startCoins + 2) {
            printf("*** Passed test ***\n");
            printf("Player1 has %d coins\n\n", gameTest.coins);
        }
        else {
            printf("*** Failed test ***\n");
            printf("Player1 has %d coins\n\n", gameTest.coins);
        }

        // reinitialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing Copper ***/
        // assemble the player's hand manually
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = copper;          // +1
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = minion;
        gameTest.hand[player1][4] = feast;

        // after updateCoins is called, player should only have 1 coins
        updateCoins(player1, &gameTest, 0);
        printf("TEST 3:\n\n");
        printf("Expecting one copper card in hand to result in total of 1 coins for player1.\n\n");
        if (gameTest.coins == startCoins + 1) {
            printf("*** Passed test ***\n");
            printf("Player1 has %d coins\n\n", gameTest.coins);
        }
        else {
            printf("*** Failed test ***\n");
            printf("Player1 has %d coins\n\n", gameTest.coins);
        }

        // reinitialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

         /*** Testing Bonus ***/
        // assemble the player's hand manually
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = baron;
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = minion;
        gameTest.hand[player1][4] = feast;

        // after updateCoins is called, player should only have 4 coins
        updateCoins(player1, &gameTest, 4);
        printf("TEST 4:\n\n");
        printf("Expecting bonus of 4 coins to player1.\n\n");
        if (gameTest.coins == startCoins + 4) {
            printf("*** Passed test ***\n");
            printf("Player1 has %d coins\n\n", gameTest.coins);
        }
        else {
            printf("*** Failed test ***\n");
            printf("Player1 has %d coins\n\n", gameTest.coins);
        }
    }

    return 0;
}
