#include <stdio.h>
#include <stdlib.h>
#include "testUtilities.h"
#include <string.h>

int main(int argc, char **argv) {

    // Testing for Shuffle function
    printf("Testing dominion.c int gainCard()\n");

    char* toFlags[3] = {"discard","deck", "hand"};
    int seed = 500;
    int res;
    int testsRun = 0;
    int testsPassed = 0;
    int numPlayers = 4;
    struct gameState G, before;
    int i, toFlag, card, ammountChange, newCard;
    int curPlayer = 0;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
         sea_hag, tribute, smithy, council_room};

    initializeGame(numPlayers, k, seed, &G);

    // test gaining cards not in use in game
    printf("Attempting to gain card not in use in current game\n");
    copyGameState(&before, &G);
    res = gainCard(outpost, &G, 1, curPlayer);
    if (res == -1){
        testsPassed += 1;
        printf("gainCard returned -1 (PASSED)\n");
    } else {
        printf("gainCard did not return error (FAILED)\n");
    }
    testsRun++;

    if (equalGameStates(&G,&before)){
        testsPassed += 1;
        printf("Game state is unaffected after error return (PASSED)\n");
    } else {
        printf("Game state was affected (FAILED)\n");
    }
    testsRun++;

    //test gaining card that is depleted
    G.supplyCount[adventurer] = 0;
    copyGameState(&before, &G);
    printf("Attempting to gain card with depleted supply\n");
    res = gainCard(adventurer, &G, 1, curPlayer);
    if (res == -1){
        testsPassed += 1;
        printf("gainCard returned -1 (PASSED)\n");
    } else {
        printf("gainCard did not return error (FAILED)\n");
    }
    testsRun++;

    if (equalGameStates(&G,&before)){
        testsPassed += 1;
        printf("Game state is unaffected after error return (PASSED)\n");
    } else {
        printf("Game state was affected (FAILED)\n");
    }
    testsRun++;
    G.supplyCount[adventurer] = 3;


    //attempt drawing each available kingdomCard, to each different place
    for(i=0; i<10;++i){
        toFlag = i%3;
        card = k[i];

        if(G.supplyCount[card] == 0) G.supplyCount[card] = 1;
        copyGameState(&before,&G);
        gainCard(card, &G, toFlag, curPlayer);
        printf("gaining card to players %s\n", toFlags[toFlag]);

        printf("Card has been removed from supply ");
        if (before.supplyCount[card] - G.supplyCount[card] == 1){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        if (toFlag == 0){
            ammountChange = G.discardCount[curPlayer] - before.discardCount[curPlayer];
            newCard = G.discard[curPlayer][before.discardCount[curPlayer]];
        } else if (toFlag == 1){
            ammountChange = G.deckCount[curPlayer] - before.deckCount[curPlayer];
            newCard = G.deck[curPlayer][before.deckCount[curPlayer]];
        } else {
            ammountChange = G.handCount[curPlayer] - before.handCount[curPlayer];
            newCard = G.hand[curPlayer][before.handCount[curPlayer]];
        }

        printf("Card has been moved to player's %s ", toFlags[toFlag]);
        if (ammountChange == 1 && newCard == card){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        if (toFlag == 0){
            G.discardCount[curPlayer]-=1;
            G.discard[curPlayer][G.discardCount[curPlayer]] = before.discard[curPlayer][G.discardCount[curPlayer]];
        } else if (toFlag == 1){
            G.deckCount[curPlayer]-=1;
            G.deck[curPlayer][G.deckCount[curPlayer]] = before.discard[curPlayer][G.deckCount[curPlayer]];
        } else {
            G.handCount[curPlayer]-=1;
            G.hand[curPlayer][G.handCount[curPlayer]] = before.hand[curPlayer][G.handCount[curPlayer]];
        }
        G.supplyCount[card]+=1;

        printf("The rest of the gameState was unaffected ");
        if (equalGameStates(&before, &G) != 0){
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
