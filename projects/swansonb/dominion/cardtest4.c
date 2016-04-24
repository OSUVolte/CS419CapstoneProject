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
    int i,j;
    int curPlayer = 0;
    int allPlayersDrew = 1;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
               sea_hag, tribute, smithy, council_room};


    initializeGame(numPlayers, k, seed, &G);

    //fill players decks with extra cards for drawing
    for (curPlayer = 0; curPlayer < numPlayers; ++curPlayer){
        for(i=0; i<50; ++i){
            G.deck[curPlayer][G.deckCount[curPlayer]++] = floor(Random() * treasure_map);
        }
    }

    for (i=0; i<NUM_TESTS; ++i){
        curPlayer = G.whoseTurn;
        G.hand[curPlayer][G.handCount[curPlayer]++] = village;
        copyGameState(&before,&G);
        printf("total cards for player %d: %d\n", curPlayer, G.handCount[curPlayer] + G.discardCount[curPlayer] + G.deckCount[curPlayer]);
        //after play players hand should have 4 extra card in hand and 1 extra Buy
        // all other players should have drawn a card

        playCouncil_Room(&G, G.handCount[curPlayer]-1);
        copyGameState(&after,&G);
        printf("TestNumber:%d  Playing Council\n",i);
        printf("Player has 1 more buy");
        if (G.numBuys - before.numBuys == 1){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        printf("Player has 4 more card in hand  <is:%d was:%d> ", G.handCount[curPlayer], before.handCount[curPlayer]);
        //check that there 3 cards more than before and played card is replaced by new card
        if (G.handCount[curPlayer] - before.handCount[curPlayer] == 3 &&
             G.hand[curPlayer][before.handCount[curPlayer]-1] != before.hand[curPlayer][before.handCount[curPlayer]-1]) {
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


        // need to check the played cards when checking if current player still has the same cards
        // but not when checking the other players
        G.playedCardCount = 0;

        allPlayersDrew = 1;
        for (j=0;j<numPlayers;++j){
            if (j!= curPlayer){
                allPlayersDrew &= (G.handCount[j] - before.handCount[j] == 1);
                allPlayersDrew &= playerHasSameCards(&before,&G,j);
            }
        }
        printf("All other players drew 1 card and that card came from their deck/discard ");
        if (allPlayersDrew){
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
