#include <stdio.h>
#include <stdlib.h>
#include "testUtilities.h"
#include "rngs.h"
#include <string.h>
#include <math.h>

int main(int argc, char **argv) {

    // Testing for playVillage function
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");
    printf("Testing dominion.c int playVillage()\n");
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");


    const int NUM_TESTS = 30;
    int seed = 1000;
    int testsRun = 0;
    int testsPassed = 0;
    int numPlayers = 4;
    struct gameState G, before, after;
    int i;
    int curPlayer = 0;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
               sea_hag, tribute, smithy, council_room};


    initializeGame(numPlayers, k, seed, &G);


    for (i=0; i<NUM_TESTS; ++i){
        curPlayer = G.whoseTurn;
        G.hand[curPlayer][G.handCount[curPlayer]++] = village;
        copyGameState(&before,&G);
        //after play players hand should have 1 extra card in hand and 2 extra actions

        playVillage(G, G.handCount[curPlayer]-1);
        copyGameState(&after,&G);
        printf("TestNumber:%d  Playing Village\n",i);
        printf("Player has 2 more actions ");
        if (G.numActions - before.numActions == 2){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        printf("Player has 1 more card in hand ");
        if (G.handCount[curPlayer] - before.handCount[curPlayer] == 1){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        printf("Players hand/deck/discard contain same cards ");
        if (playerHasSameCards(&G,&before,curPlayer)){
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
        cpyDeck(G.hand[curPlayer], before.hand[curPlayer], MAX_HAND);
        cpyDeck(G.discard[curPlayer], before.discard[curPlayer], MAX_DECK);
        cpyDeck(G.deck[curPlayer], before.deck[curPlayer], MAX_DECK);
        G.numActions = before.numActions;
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
