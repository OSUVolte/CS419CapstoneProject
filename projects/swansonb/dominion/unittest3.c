#include <stdio.h>
#include <stdlib.h>
#include "testUtilities.h"
#include "rngs.h"
#include <string.h>
#include <math.h>


int main(int argc, char **argv) {
    //testing endTurn method

    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");
    printf("Testing dominion.c int shuffle()\n");
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");

    const int NUM_TESTS_TO_RUN = 20;
    int seed = 500;
    int testsRun = 0;
    int testsPassed = 0;
    int numPlayers = 4;
    struct gameState G, before;
    int i;
    int curPlayer, expectedNextPlayer, prevPlayer;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy, council_room};

    initializeGame(numPlayers, k, seed, &G);

    //fill players decks with extra cards for drawing at beginning of turn
    //behavior of drawcard when deck is empty is tested in drawcard unit test
    for (curPlayer = 0; curPlayer < numPlayers; ++curPlayer){
        for(i=0; i<40; ++i){
            G.deck[curPlayer][G.deckCount[curPlayer]++] = floor(Random() * treasure_map);
        }
    }

    for (i=0; i<NUM_TESTS_TO_RUN; ++i){
        curPlayer = G.whoseTurn;
        expectedNextPlayer = (curPlayer + 1)%numPlayers;

        printf("calling end turn for player %d:\n",curPlayer);
        copyGameState(&before,&G);
        endTurn(&G);


        // check that game has advanced to next players turn
        printf("Game has advanced to next player (%d)  ", expectedNextPlayer);
        if (G.whoseTurn == expectedNextPlayer){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        prevPlayer = curPlayer;
        curPlayer = G.whoseTurn;

        // check that current player has 5 cards in their hand that came from their deck
        printf("current player has 5 cards in hand from their deck ");
        if (G.handCount[curPlayer] == 5 && before.deckCount[curPlayer] - G.deckCount[curPlayer] == 5 &&
                cardArraysAreEqual(G.hand[curPlayer], 5, before.deck[curPlayer] + before.deckCount[curPlayer] - 5, 5)){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        // check that previous players hand has properly moved to their discard pile
        printf("Previous players cards in hand have been placed in their discard pile ");
        if (G.handCount[prevPlayer] == 0 &&
                G.discardCount[prevPlayer] - before.discardCount[prevPlayer] == before.handCount[prevPlayer] &&
                cardArraysAreEqual(G.discard[prevPlayer] + before.discardCount[prevPlayer], before.handCount[prevPlayer],
                        before.hand[prevPlayer], before.handCount[prevPlayer]) ){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;
    }

    printf("%d of %d tests passed\n",testsPassed, testsRun);

    return 0;

}
