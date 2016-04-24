#include <stdio.h>
#include <stdlib.h>
#include "testUtilities.h"
#include "rngs.h"
#include <string.h>
#include <math.h>

int main(int argc, char **argv) {

    // Testing for playSmithy function
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");
    printf("Testing dominion.c int playSmithy()\n");
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");


    const int NUM_TESTS = 30;
    const int CARDS_IN_DECK_AT_START = 15;
    int seed = 1000;
    int testsRun = 0;
    int testsPassed = 0;
    int numPlayers = 4;
    struct gameState G, before, after;
    int i;
    int curPlayer = 0;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
               sea_hag, tribute, smithy, council_room};

    //testing empty deck and empty discard
    initializeGame(numPlayers, k, seed, &G);

    for (curPlayer = 0; curPlayer < numPlayers; ++curPlayer){
        while (G.deckCount[curPlayer] < CARDS_IN_DECK_AT_START){
            G.deck[curPlayer][G.deckCount[curPlayer]++] = floor(Random() * treasure_map);
        }
    }

    for (i=0; i< NUM_TESTS; ++i){

        curPlayer = G.whoseTurn;

        G.hand[curPlayer][0] = smithy;

        copyGameState(&before,&G);
        printf("Playing smithy card player: %d  testRound: %d\n",curPlayer, i);
        playSmithy(&G,0);
        copyGameState(&after,&G);

        printf("current player has drawn 3 new cards ");
        if (G.handCount[curPlayer] - before.handCount[curPlayer] == 3){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        printf("hands in players cards came from their deck or discard piles ");
        if (playerHasSameCards(&before, &G, curPlayer)){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        //rollback intentional changes to game state and check for any side-effects
        G.deckCount[curPlayer] = before.deckCount[curPlayer];
        G.handCount[curPlayer] = before.handCount[curPlayer];
        G.discardCount[curPlayer] = before.discardCount[curPlayer];
        G.playedCardCount = before.playedCardCount;
        cpyDeck(G.hand[curPlayer], before.hand[curPlayer], MAX_HAND);
        cpyDeck(G.discard[curPlayer], before.discard[curPlayer], MAX_DECK);
        cpyDeck(G.deck[curPlayer], before.deck[curPlayer], MAX_DECK);
        cpyDeck(G.playedCards, before.playedCards, MAX_DECK);
        printf("The rest of the gameState was unaffected ");
        if (equalGameStates(&before, &G)){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        copyGameState(&G,&after);


        endTurn(&G);
    }


    printf("%d of %d tests passed\n",testsPassed, testsRun);

    return 0;
}
