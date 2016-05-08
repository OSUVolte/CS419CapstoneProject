/* Diana O'Haver
   Assignment 4
   Random tester for card: smithy
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
#include <time.h>

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
    int card = smithy;
    int initHandCount;
    int position = 0;
    srand(time(NULL));                  // seed random number generator

    /**************************************************
    * The following conditions occur by the end of the smithy case:
    * - current player draws 3 cards
    * - current player discards a card from their hand
    **************************************************/

     printf("** Card being tested: smithy **\n\n");

    for (i = 0; i < numTests; i++) {

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        // give the player a hand - randomly
        int numCards = rand() % 5;

        int drawing = 0;

        gameTest.whoseTurn = player1;

        while (drawing < numCards) {
            drawCard(gameTest.whoseTurn, &gameTest);
            drawing++;
        }

        printf("TEST 1: random hand size\n\n");
        printf("Hand prior to smithy card: %d\n", gameTest.handCount[player1]);

        initHandCount = gameTest.handCount[player1];

        cardEffect(card, 0, 0, 0, &gameTest, position, 0);

        if (gameTest.handCount[player1] == numCards+2) {
            printf("TEST PASSED\n");
            printf("Expected hand size of %d, actual hand size of %d\n", initHandCount+2, gameTest.handCount[player1]);
        }
        else {
            printf("TEST FAILED\n");
            printf("Expected hand size of %d, actual hand size of %d\n", initHandCount+2, gameTest.handCount[player1]);
        }

        printf("\nTEST 2: random player selected, random number of cards drawn\n\n");

        int randPlayer = rand() % 2;

        gameTest.whoseTurn = randPlayer;

        initHandCount = gameTest.handCount[randPlayer];

        // make sure the player has a hand to start with
        if (initHandCount > 0) {
            for (i = 0; i < initHandCount; i++) {
                gameTest.hand[randPlayer][i] = 0;
            }
            gameTest.handCount[randPlayer] = 0;
        }

        numCards = rand() % 5;

        drawing = 0;
        // draw a new hand
        while (drawing < numCards) {
            drawCard(gameTest.whoseTurn, &gameTest);
            drawing++;
        }

        initHandCount = gameTest.handCount[randPlayer];

        printf("Player %d hand prior to smithy card: %d\n", randPlayer, gameTest.handCount[randPlayer]);

        cardEffect(card, 0, 0, 0, &gameTest, position, 0);

       if (gameTest.handCount[randPlayer] == initHandCount+2) {
            printf("TEST PASSED\n");
            printf("Expected hand size of %d, actual hand size of %d\n", initHandCount+2, gameTest.handCount[randPlayer]);
        }
        else {
            printf("TEST FAILED\n");
            printf("Expected hand size of %d, actual hand size of %d\n", initHandCount+2, gameTest.handCount[randPlayer]);
        }

        printf("\nTEST 3: smithy draw does not effect other player\n\n");

        printf("Hand prior to smithy card: %d\n", gameTest.handCount[player1]);

        // give the player a hand - randomly
        numCards = rand() % 5;

        drawing = 0;

        while (drawing < numCards) {
            drawCard(player2, &gameTest);
            drawing++;
        }

        initHandCount = gameTest.handCount[player1];

        gameTest.whoseTurn = player2;

        cardEffect(card, 0, 0, 0, &gameTest, position, 0);

        if (gameTest.handCount[player1] == initHandCount) {
            printf("TEST PASSED\n");
            printf("Expected hand size of %d, actual hand size of %d\n", initHandCount, gameTest.handCount[player1]);
        }
        else {
            printf("TEST FAILED\n");
            printf("Expected hand size of %d, actual hand size of %d\n", initHandCount, gameTest.handCount[player1]);
        }
    }
    return 0;
}
