#include <stdio.h>
#include <stdlib.h>
#include "testUtilities.h"
#include "rngs.h"
#include <string.h>
#include <math.h>

struct adventurerTestCase {
    int* deck;
    int deckSize;
    int deckSizeAfter;
    int discardAfter[MAX_DECK];
    int discardAfterSize;
};

int isCoin(int card){
    return card == copper || card == silver || card == gold;
}

int numTreasureCards(int* arr, int n){
    int num = 0;
    int i=0;
    for(;i<n;++i){
        if (isCoin(arr[i])) num++;
    }
    return num;
}

struct adventurerTestCase initTestCase(int j, int* testDecks){
    struct adventurerTestCase out;
    out.deck = testDecks + (j*8);
    out.deckSize = 8;
    out.deckSizeAfter = 0;
    out.discardAfterSize = 0;

    int i;
    int numCoinsFound = 0;
    for(i=out.deckSize-1; i>=0; --i){
        if(isCoin(out.deck[i])){
            numCoinsFound++;
        } else {
            out.discardAfter[out.discardAfterSize++] = out.deck[i];
        }
        if (numCoinsFound == 2){
            out.deckSizeAfter = i;
            break;
        }
    }


    return out;
}

int main(int argc, char **argv) {

    // Testing for playAdventurer function
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");
    printf("Testing dominion.c int playAdventurer()\n");
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");


    const int NUM_TESTS = 5;

    int testDecks[40] =
    {copper,silver,smithy, sea_hag, village, mine, village, minion,
     copper, mine, village, minion, smithy, sea_hag, village, silver,
     mine, village, minion, smithy, sea_hag, village, silver, gold,
     mine, village, minion, silver, smithy, sea_hag, village, gold,
     mine, copper, minion, copper, smithy, sea_hag, village, gold,
     };

    int seed = 1000;
    int testsRun = 0;
    int testsPassed = 0;
    int numPlayers = 2;
    struct gameState G, before;
    int i,j;
    int deckIsSame;
    int curPlayer = 0;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
               sea_hag, tribute, smithy, council_room};

    for (i=0; i<NUM_TESTS; ++i){

        struct adventurerTestCase testCase = initTestCase(i, testDecks);


        initializeGame(numPlayers, k, seed, &G);
        curPlayer = G.whoseTurn;

        G.discardCount[curPlayer]=0;
        for(G.deckCount[curPlayer] = 0; G.deckCount[curPlayer]<testCase.deckSize; G.deckCount[curPlayer]++){
            G.deck[curPlayer][G.deckCount[curPlayer]] = testCase.deck[G.deckCount[curPlayer]];
        }

        G.hand[curPlayer][G.handCount[curPlayer]++] = adventurer;
        copyGameState(&before,&G);
        playAdventurer(&G, G.handCount[curPlayer]-1);
        printf("Test #:%d playing adventurer card\n",i);
        printf("Player's hand has 2 new coin cards ");
        if (G.handCount[curPlayer] == before.handCount[curPlayer]+1 &&
                isCoin(G.hand[curPlayer][G.handCount[curPlayer]-1]) &&
                isCoin(G.hand[curPlayer][G.handCount[curPlayer]-2])){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        printf("Drawn cards from deck other than 2 coins have been put in discard ");
        if (cardArraysAreEqual(testCase.discardAfter, testCase.discardAfterSize,
                G.discard[curPlayer],G.discardCount[curPlayer])){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        printf("Only the necessary amount of cards were drawn from deck ");
        deckIsSame = testCase.deckSizeAfter == G.deckCount[curPlayer];
        for(j=0;j<testCase.deckSizeAfter && deckIsSame; ++j){
            deckIsSame &= testCase.deck[j] == G.deck[curPlayer][j];
        }
        if (deckIsSame){
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

    }




    printf("%d of %d tests passed\n",testsPassed, testsRun);

    return 0;
}
