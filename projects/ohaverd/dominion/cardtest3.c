/* -----------------------------------------------------------------------
 * Diana O'Haver
 * File: cardtest3.c
 *
 * Unit test of card in dominion.c:
 *      council_room
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
    int player1 = 0;
    int player2 = 1;
    int players = 2;
    int numTests = 1;                   // run each test once
    int initHandSize, initNumBuys, initp2Hand;
    int card = council_room;
    int position = 0;
    int effect;

    /**************************************************
    * The following conditions occur by the end of the council_room case:
    * - current player draws 4 cards
    * - game's numBuys increases by 1
    * - all players other than current player draw a card
    * - played card (handPos) is discarded
    **************************************************/

     printf("** Card being tested: council_room **\n\n");

    for (i = 0; i < numTests; i++) {

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        // give the player a hand
        gameTest.hand[player1][0] = council_room;           // handPos = 0
        gameTest.hand[player1][1] = estate;
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = great_hall;
        gameTest.hand[player1][4] = feast;

        gameTest.handCount[player1] = 5;

        initHandSize = gameTest.handCount[player1];
        initNumBuys = gameTest.numBuys;
        initp2Hand = gameTest.handCount[player2];

        effect = cardEffect(card, 0, 0, 0, &gameTest, position, 0);

        /*** Testing if the current player drew 4 cards ***/

        printf("TEST 1\n\n");

        if (gameTest.handCount[player1] == initHandSize + 3) {
            printf("*** Test passed ***\n");
            printf("Expecting a hand size of %d, actual hand size was %d\n\n", initHandSize+3, gameTest.handCount[player1]);
        }
        else {
            printf("*** Test failed ***\n");
            printf("Expecting a hand size of %d, actual hand size was %d\n\n", initHandSize+3, gameTest.handCount[player1]);
        }

        printf("TEST 2\n\n");
        /*** Testing if numBuys incremented by 1 ***/
        if (gameTest.numBuys == initNumBuys + 1) {
            printf("*** Test passed ***\n");
            printf("Expecting numBuys of %d, actual numBuys was %d\n\n", initNumBuys+1, gameTest.numBuys);
        }
        else {
            printf("*** Test failed ***\n");
            printf("Expecting numBuys of %d, actual numBuys was %d\n\n", initNumBuys+1, gameTest.numBuys);
        }

        /*** Testing if player 2 drew a card ***/

        printf("TEST 3\n\n");

        if (gameTest.handCount[player2] == initp2Hand + 1) {
            printf("*** Test passed ***\n");
            printf("Expecting a player2 hand size of %d, actual player2 hand size was %d\n\n", initp2Hand+1, gameTest.handCount[player2]);
        }
        else {
            printf("*** Test failed ***\n");
            printf("Expecting a player2 hand size of %d, actual player2 hand size was %d\n\n", initp2Hand+1, gameTest.handCount[player2]);
        }
    }
    return 0;
}
