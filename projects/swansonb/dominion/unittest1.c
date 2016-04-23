#include <stdio.h>
#include <stdlib.h>
#include "testUtilities.h"
#include <string.h>

int main(int argc, char **argv) {

    // Testing for Shuffle function
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");
    printf("Testing dominion.c int shuffle()\n");
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");


    const int NUM_NEW_GAMES = 4;
    const int NUM_SHUFFLES_PER_GAME = 8;
    int seed = 500;
    int testsRun = 0;
    int testsPassed = 0;
    int numPlayers = 4;
    struct gameState G, before, after;
    int i, j;
    int srted_deck_before_shuffle[MAX_DECK];
    int curPlayer = 1;
    int decks_contain_same_cards, deck_is_shuffled;
    int deckCount;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy, council_room};

    //Boundry and branch testing
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    G.deckCount[curPlayer] = 0;
    copyGameState(&before,&G);
    printf("requesting to shuffle empty deck, expected -1 return and game state unaffected \n");
    int result = shuffle(curPlayer, &G);

    if (result == -1){
        testsPassed += 1;
        printf("Shuffle returned -1 (PASSED)\n");
    } else {
        printf("shuffle did not return error (FAILED)\n");
    }
    testsRun++;

    if (equalGameStates(&G,&before)){
        testsPassed += 1;
        printf("Game state is unaffected after error return (PASSED)\n");
    } else {
        printf("Game state was affected (FAILED)\n");
    }
    testsRun++;

    // test under usual circumstances
    for (i=0; i< NUM_NEW_GAMES; ++i){
        initializeGame(numPlayers, k, seed, &G);

        for (j=0; j < NUM_SHUFFLES_PER_GAME; ++j){
            curPlayer = j%numPlayers;
            deckCount = G.deckCount[curPlayer];

            copyGameState(&before, &G);
            cpyDeck(srted_deck_before_shuffle, G.deck[curPlayer], deckCount);
            qsort ((void*)(srted_deck_before_shuffle), deckCount, sizeof(int), compare);


            shuffle(curPlayer, &G);

            //test that the players cards are the same set of cards as before shuffle
            copyGameState(&after, &G);
            qsort ((void*)(G.deck[curPlayer]), deckCount, sizeof(int), compare);
            decks_contain_same_cards = memcmp(G.deck[curPlayer], srted_deck_before_shuffle, deckCount);

            printf("Game %d, Player %d after shuffle \nPlayers deck contains the same cards",i,j%4);
            if (decks_contain_same_cards == 0){
                testsPassed++;
                printf("(PASSED) \n");
            } else {
                printf("(FAILED) \n");
            }
            testsRun += 1;

            //test that cards are in a different order
            deck_is_shuffled = memcmp(after.deck[curPlayer], before.deck[curPlayer], deckCount);
            printf("Deck is in a different order after shuffle ");
            if (deck_is_shuffled != 0){
                testsPassed++;
                printf("(PASSED) \n");
            } else {
                printf("(FAILED) \n");
            }
            testsRun += 1;

            //test that the rest of the game state was unaffected
            cpyDeck(G.deck[curPlayer],before.deck[curPlayer],deckCount);
            printf("The rest of the gameState was unaffected ");
            if (equalGameStates(&before, &G) != 0){
                testsPassed++;
                printf("(PASSED) \n");
            } else {
                printf("(FAILED) \n");
            }
            testsRun += 1;

            copyGameState(&G,&after);

        }
    }

    printf("%d of %d tests passed\n",testsPassed, testsRun);

    return 0;
}
