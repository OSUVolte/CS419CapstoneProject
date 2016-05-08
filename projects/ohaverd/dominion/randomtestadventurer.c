/* Diana O'Haver
   Assignment 4
   Random tester for card: adventurer
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
    int i, j;                              // we'll probably need a counter at some point
    int player1 = 0;
    int player2 = 1;
    int players = 2;
    int numTests = 1;                   // run each test once
    int card = adventurer;
    int position = 1;
    srand(time(NULL));

    /**************************************************
    * The following conditions occur by the end of the adventurer case:
    * - while drawntreasure is less than 2
    *       i. if deck is empty, discard is shuffled
    *       ii. player draws a card
    *       iii. card at the top of the hand is most recently drawn
    *       iv. if card drawn is a treasure card, drawn treasure increases by 1
    *       v. if not, player's hand count reduced by 1
    * - once drawntreasure is greater than 2
    *       i. all cards in play that have been drawn are discarded
    **************************************************/

     printf("** Card being tested: adventurer **\n\n");

    for (i = 0; i < numTests; i++) {

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        gameTest.whoseTurn = player1;

        // give the player a hand - randomly
        int numCards = rand() % 5;

        int drawing = 0;

        while (drawing < numCards) {
            drawCard(gameTest.whoseTurn, &gameTest);
            drawing++;
        }

        // give the player a deck to draw from
         // put some cards in the deck
        gameTest.deck[player1][0] = copper;     // drawntreasure +1
        gameTest.deck[player1][1] = copper;     // drawntreasure +1

        printf("TEST 1: testing that hand count was increased by 2\n\n");
        printf("Hand prior to adventurer card: %d\n", gameTest.handCount[player1]);

        int initHandCount = gameTest.handCount[player1];
        int initDeckCount = gameTest.deckCount[player1];

        cardEffect(card, 0, 0, 0, &gameTest, position, 0);

        if (gameTest.handCount[player1] == initHandCount+2) {
            printf("TEST PASSED\n");
            printf("Expected hand size of %d, actual hand size was %d\n", initHandCount+2, gameTest.handCount[player1]);
        }
        else {
            printf("TEST FAILED\n");
            printf("Expected hand size of %d, actual hand size was %d\n", initHandCount+2, gameTest.handCount[player1]);
        }

        printf("\nTEST 2: testing that deck size was reduced by 2\n\n");
        printf("Deck size prior to adventurer card: %d\n", initDeckCount);

        if (gameTest.deckCount[player1] == initDeckCount-2) {
            printf("TEST PASSED\n");
            printf("Expected deck size of %d, actual deck size was %d\n", initDeckCount-2, gameTest.deckCount[player1]);
        }
        else {
            printf("TEST FAILED\n");
            printf("Expected deck size of %d, actual deck size was %d\n", initDeckCount-2, gameTest.deckCount[player1]);
        }

        // discard hand to start over for next test

        while (numHandCards(&gameTest) > 0) {
            discardCard(0, gameTest.whoseTurn, &gameTest, 0);
        }

        // draw a new random hand for the player
        // give the player a hand - randomly
        numCards = rand() % 5;

        drawing = 0;

        while (drawing < numCards) {
            drawCard(gameTest.whoseTurn, &gameTest);
            drawing++;
        }

        gameTest.deckCount[player1] = 0;
        // give the player a deck
        for (j = 0; j < 3; j++) {
            gameTest.deck[player1][j] = estate;
            gameTest.deckCount[player1]++;
        }
        for (j = 3; j < 10; j++) {
            gameTest.deck[player1][j] = copper;
            gameTest.deckCount[player1]++;
        }

        // shuffle it a random number of times

        int numShuffles = rand() % 4;

        if (numShuffles == 0) {
            // don't shuffle
        }
        if (numShuffles == 1) {
            shuffle(player1, &gameTest);
        }
        if (numShuffles == 2) {
            shuffle(player1, &gameTest);
            shuffle(player1, &gameTest);
        }
        if (numShuffles == 3) {
            shuffle(player1, &gameTest);
            shuffle(player1, &gameTest);
            shuffle(player1, &gameTest);
        }

        int firstTreasure = -1;
        int secondTreasure;
        int flag = 0;

        // deck starts with 7 copper and 3 estate
        // loop through deck and figure out where the treasures are
        for (i = 0; i < gameTest.deckCount[player1]; i++) {
            if (gameTest.deck[player1][i] == copper || gameTest.deck[player1][i] == silver || gameTest.deck[player1][i] == gold) {
                //printf("Treasure found at position %d\n", i);

                if (firstTreasure == -1) {
                    firstTreasure = i;
                }

                if (firstTreasure != -1 && i > firstTreasure && flag == 0) {
                    secondTreasure = i;
                    flag = 1;
                }
            }
        }

        initDeckCount = gameTest.deckCount[player1];

        int initp2Deck = gameTest.deckCount[player2];
        int initp2Hand = gameTest.handCount[player2];

        // now we have the positions of the first two treasure
        cardEffect(card, 0, 0, 0, &gameTest, position, 0);

        // player draws a card. if it's not a treasure, player's hand count is reduced by 1
        // so expected that player's hand is reduced by the the number of positions

        printf("\nTEST 3: testing that drawn cards are equal to number of draws it takes to reach 2 treasure\n\n");

        int postDeckCount = gameTest.deckCount[player1];

        int diff = initDeckCount - postDeckCount;

        if (gameTest.deckCount[player1] == initDeckCount - secondTreasure) {
            printf("TEST PASSED\n");
            printf("Second treasure was drawn at position %d and deck has been reduced by %d cards\n", secondTreasure, diff);
        }
        else {
            printf("TEST FAILED\n");
            printf("Second treasure was drawn at position %d and deck has been reduced by %d cards\n", secondTreasure, diff);
        }

        printf("\nTEST 4: testing that prior player1 tests did not impact player 2 deck\n\n");

        int postp2Deck = gameTest.deckCount[player2];
        int postp2Hand = gameTest.handCount[player2];

        if (postp2Deck == initp2Deck) {
            printf("TEST PASSED\n");
            printf("Initial p2 deck count was %d, post p2 deck count was %d\n", initp2Deck, postp2Deck);
        }
        else {
            printf("TEST FAILED\n");
            printf("Initial p2 deck count was %d, post p2 deck count was %d\n", initp2Deck, postp2Deck);
        }

        printf("\nTEST 5: testing that prior player1 tests did not impact player 2 hand\n\n");

        if (postp2Hand == initp2Hand) {
            printf("TEST PASSED\n");
            printf("Initial p2 hand count was %d, post p2 hand count was %d\n", initp2Hand, postp2Hand);
        }
        else {
            printf("TEST FAILED\n");
            printf("Initial p2 hand count was %d, post p2 hand count was %d\n", initp2Hand, postp2Hand);
        }
    }
    return 0;
}
