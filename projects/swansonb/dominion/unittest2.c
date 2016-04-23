#include <stdio.h>
#include <stdlib.h>
#include "testUtilities.h"
#include <string.h>

int main(int argc, char **argv) {

    // Testing for drawCard function
    printf("Testing dominion.c int drawCard()\n");

    const int TESTS_TO_RUN = 20;

    int seed = 1000;
    int cardToBeDrawn;
    int *placeForNewCard;
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
    G.deckCount[curPlayer] = 0;
    G.discardCount[curPlayer] = 0;
    copyGameState(&before, &G);

    printf("drawing from empty deck and empty discard\n");
    int res = drawCard(curPlayer, &G);
    printf("function returns error ");
    if (res == -1){
       testsPassed++;
       printf("(PASSED) \n");
    } else {
       printf("(FAILED) \n");
    }
    testsRun += 1;

    printf("Game State Unaffected ");
    if (equalGameStates(&before, &G)){
       testsPassed++;
       printf("(PASSED) \n");
    } else {
       printf("(FAILED) \n");
    }
    testsRun += 1;

    //testing empty deck branch
    initializeGame(numPlayers, k, seed, &G);

    for (curPlayer=0; curPlayer < numPlayers; ++curPlayer){
        //empty player deck to discard
        while(G.deckCount[curPlayer]){
            G.discard[curPlayer][G.discardCount[curPlayer]] = G.deck[curPlayer][G.deckCount[curPlayer]-1];
            G.discardCount[curPlayer]++;
            G.deckCount[curPlayer]--;
        }
    }

    copyGameState(&before,&G);

    for (curPlayer=0; curPlayer < numPlayers; ++curPlayer){
        //draw from empty deck
        printf("drawing from empty deck, expecting entire discard pile to be moved to deck and card drawn from it\n");
        printf("cur discard count: %d  deck count: %d\n",G.discardCount[curPlayer], G.deckCount[curPlayer]);

        drawCard(curPlayer, &G);

        printf("Discard deck is shuffled and moved to player deck ");
        if (G.deckCount[curPlayer] == before.discardCount[curPlayer] - 1
                && G.discardCount[curPlayer] == 0){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        printf("Player has one new card in hand ");
        if (G.handCount[curPlayer] == before.handCount[curPlayer] + 1 ){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        printf("deck and new card in had are composed of the same cards that were in discard pile before reshuffle ");
        G.deck[curPlayer][G.deckCount[curPlayer]] = G.hand[curPlayer][G.handCount[curPlayer]-1];
        G.deckCount[curPlayer]++;
        if (cardArraysAreEqual(before.discard[curPlayer], before.discardCount[curPlayer],
                G.deck[curPlayer], G.deckCount[curPlayer])){
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
        printf("The rest of the gameState was unaffected ");
        if (equalGameStates(&before, &G)){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

    }

    //test under draw from deck branch
    initializeGame(numPlayers,k,seed,&G);

    for (i=0; i<TESTS_TO_RUN; ++i){
        curPlayer = i%numPlayers;

        copyGameState(&before,&G);
        cardToBeDrawn = G.deck[curPlayer][G.deckCount[curPlayer]-1];
        placeForNewCard = G.hand[curPlayer] + G.handCount[curPlayer];

        drawCard(curPlayer,&G);
        copyGameState(&after,&G);

        printf("Card from top of players deck was placed in players hand ");
        if (*placeForNewCard == cardToBeDrawn){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        printf("player hand count increased and deck count decreased ");
        if (G.handCount[curPlayer] == before.handCount[curPlayer] + 1
            && G.deckCount[curPlayer] == before.deckCount[curPlayer] - 1){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;


        //rollback intentional changes to game state and check for any side-effects
        G.deckCount[curPlayer] = before.deckCount[curPlayer];
        G.handCount[curPlayer] = before.handCount[curPlayer];
        cpyDeck(G.hand[curPlayer], before.hand[curPlayer], MAX_HAND);
        cpyDeck(G.deck[curPlayer], before.deck[curPlayer], MAX_DECK);
        printf("The rest of the gameState was unaffected ");
        if (equalGameStates(&before, &G)){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        copyGameState(&G,&after);
    }


    printf("%d of %d tests passed\n",testsPassed, testsRun);

    return 0;
}
