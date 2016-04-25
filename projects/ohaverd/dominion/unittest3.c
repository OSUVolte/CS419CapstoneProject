/* -----------------------------------------------------------------------
 * Diana O'Haver
 * File: unittest3.c
 *
 * Unit test of function in dominion.c:
 *      scoreFor
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
    int player1;                            // only testing score update, so no need for player2
    int players = 2;
    int numTests = 1;                   // run each test once
    int score = 0;

    /**************************************************
    * The following conditions occur by the end of the scoreFor function:
    * - score from hand, discard, and deck updates as follows:
    *       i. curse = -1
    *       i. estate = +1
    *       i. duchy = +3
    *       i. province = +6
    *       i. great_hall = +1
    *       i. gardens = fullDeckCount / 10
    * - score is returned
    **************************************************/

     printf("** Function being tested: scoreFor **\n\n");

    for (i = 0; i < numTests; i++) {

        // assign player number
        player1 = 0;

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing if score is only coming from hand ***/
        // give the player a hand
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = province;      // +6
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = minion;
        gameTest.hand[player1][4] = feast;

        score = scoreFor(player1, &gameTest);

        printf("TEST 1:\n\n");
        printf("Expecting player to have score of 6 from 1 province card.\n\n");
        if (score == 6) {
            printf("*** Passed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }
        else {
            printf("*** Failed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing if score is only coming from discard ***/
        // give the player a hand
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = estate;            // +1
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = minion;
        gameTest.hand[player1][4] = feast;

        score = scoreFor(player1, &gameTest);

        printf("TEST 2:\n\n");
        printf("Expecting player to have score of 1 from 1 estate card.\n\n");
        if (score == 1) {
            printf("*** Passed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }
        else {
            printf("*** Failed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }
        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing if score is only coming from deck ***/
        // give the player a hand
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = duchy;              // +3
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = minion;
        gameTest.hand[player1][4] = feast;

        score = scoreFor(player1, &gameTest);

        printf("TEST 3:\n\n");
        printf("Expecting player to have score of 3 from 1 duchy card.\n\n");
        if (score == 3) {
            printf("*** Passed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }
        else {
            printf("*** Failed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing if no score at all from any initialized hand, discard, deck ***/
        // give the player a hand
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = gold;
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = minion;
        gameTest.hand[player1][4] = feast;

        // give the discard values
        gameTest.discard[player1][0] = council_room;
        gameTest.discard[player1][1] = gold;
        gameTest.discard[player1][2] = minion;
        gameTest.discard[player1][3] = minion;
        gameTest.discard[player1][4] = feast;

        // give the deck values
        gameTest.deck[player1][0] = council_room;
        gameTest.deck[player1][1] = gold;
        gameTest.deck[player1][2] = minion;
        gameTest.deck[player1][3] = minion;
        gameTest.deck[player1][4] = feast;

        score = scoreFor(player1, &gameTest);

        printf("TEST 4:\n\n");
        printf("Expecting player to have score of 0 from no cards of value in any portion tested.\n\n");
        if (score == 0) {
            printf("*** Passed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }
        else {
            printf("*** Failed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing if score is tallied from hand and discard ***/
        // give the player a hand
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = estate;             // +1
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = great_hall;         // +1
        gameTest.hand[player1][4] = feast;

        // give the discard values
        gameTest.discard[player1][0] = council_room;
        gameTest.discard[player1][1] = gold;
        gameTest.discard[player1][2] = duchy;           // +3
        gameTest.discard[player1][3] = minion;
        gameTest.discard[player1][4] = feast;

        // give the deck values
        gameTest.deck[player1][0] = council_room;
        gameTest.deck[player1][1] = gold;
        gameTest.deck[player1][2] = minion;
        gameTest.deck[player1][3] = minion;
        gameTest.deck[player1][4] = feast;

        gameTest.handCount[player1] = 5;
        gameTest.discardCount[player1] = 5;
        gameTest.deckCount[player1] = 5;

        score = scoreFor(player1, &gameTest);


        printf("TEST 5:\n\n");
        printf("Expecting player to have score of 5 from 1 estate and 1 great hall in hand, and 1 duchy in discard.\n\n");
        if (score == 5) {
            printf("*** Passed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }
        else {
            printf("*** Failed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing if score is tallied from hand and deck ***/
        // give the player a hand
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = estate;             // +1
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = great_hall;         // +1
        gameTest.hand[player1][4] = feast;

        // give the discard values
        gameTest.discard[player1][0] = council_room;
        gameTest.discard[player1][1] = gold;
        gameTest.discard[player1][2] = gold;
        gameTest.discard[player1][3] = minion;
        gameTest.discard[player1][4] = feast;

        // give the deck values
        gameTest.deck[player1][0] = council_room;
        gameTest.deck[player1][1] = gold;
        gameTest.deck[player1][2] = province;           // +6
        gameTest.deck[player1][3] = minion;
        gameTest.deck[player1][4] = feast;

        gameTest.handCount[player1] = 5;
        gameTest.discardCount[player1] = 5;
        gameTest.deckCount[player1] = 5;

        score = scoreFor(player1, &gameTest);

        printf("TEST 6:\n\n");
        printf("Expecting player to have score of 8 from 1 estate and 1 great hall in hand, and 1 province in deck.\n\n");
        if (score == 8) {
            printf("*** Passed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }
        else {
            printf("*** Failed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing if score is tallied from discard and deck ***/
        // give the player a hand
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = silver;
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = silver;
        gameTest.hand[player1][4] = feast;

        // give the discard values
        gameTest.discard[player1][0] = council_room;
        gameTest.discard[player1][1] = gold;
        gameTest.discard[player1][2] = curse;           // -1
        gameTest.discard[player1][3] = minion;
        gameTest.discard[player1][4] = feast;

        // give the deck values
        gameTest.deck[player1][0] = council_room;
        gameTest.deck[player1][1] = gold;
        gameTest.deck[player1][2] = province;           // +6
        gameTest.deck[player1][3] = minion;
        gameTest.deck[player1][4] = feast;

        gameTest.handCount[player1] = 5;
        gameTest.discardCount[player1] = 5;
        gameTest.deckCount[player1] = 5;

        score = scoreFor(player1, &gameTest);

        printf("TEST 7:\n\n");
        printf("Expecting player to have score of 5 from 1 province in deck and 1 curse in discard.\n\n");
        if (score == 5) {
            printf("*** Passed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }
        else {
            printf("*** Failed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing gardens - not working yet ***/
        // give the player a hand of 10 cards
        gameTest.hand[player1][0] = estate;
        gameTest.hand[player1][1] = estate;
        gameTest.hand[player1][2] = estate;
        gameTest.hand[player1][3] = estate;
        gameTest.hand[player1][4] = estate;
        gameTest.hand[player1][5] = estate;
        gameTest.hand[player1][6] = estate;
        gameTest.hand[player1][7] = estate;
        gameTest.hand[player1][8] = estate;
        gameTest.hand[player1][9] = gardens;

        gameTest.handCount[player1] = 10;

        gameTest.deckCount[player1] = 0;
        gameTest.discardCount[player1] = 0;

        score = scoreFor(player1, &gameTest);

        printf("TEST 8:\n\n");
        printf("Expecting player to have score of 10 from use of garden card.\n\n");
        if (score == 10) {
            printf("*** Passed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }
        else {
            printf("*** Failed test ***\n");
            printf("Player1 has a score of %d\n\n", score);
        }
    }
    return 0;
}


