/**********************************************************************
CS362-400
Assignment 4
File: randomtestcard.c
Author: Tatsiana Clifton
Date: 5/3/2016
Description: Random testing of the village card
***********************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TESTCARD "village"
#define MAX_TEST 5000

int main() {
    srand(time(NULL));

    //declare variables to hold count of failed tests
    int failHand = 0;
    int failAction = 0;
    int failDeck = 0;
    int failPlay = 0;
    int failDiscard = 0;
    int failHandOthers = 0;
    int failDeckOthers = 0;
    int failVictory = 0;
    int failKingdom = 0;

    //game cards
    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

    struct gameState G;    //hold everything about the initial game
    memset(&G, 0, sizeof(struct gameState));   // clear the initial game state
    struct gameState testG;    //hold everything about the game after village was played
    memset(&testG, 0, sizeof(struct gameState));   // clear the test game state

    printf("-------------- Running Random Testing of %s Card -------------\n", TESTCARD);
    //run tests MAX_TEST times
    int i, p;
    for(i = 0; i < MAX_TEST; i++){
        int numPlayers, player, seed;
        //set randomly number of players between 2 and 4
        numPlayers = rand()%3 + 2;
        //set randomly seed
        seed = rand();
        //initialize game
        initializeGame(numPlayers, k, seed, &G);
        //pick a current player
        player = 0;
        G.whoseTurn = player;
        //randomly set deck count, hand count, discard count
        for (p = 0; p < numPlayers; p++){
            G.deckCount[p] = floor(Random() * MAX_DECK);
            G.discardCount[p] = floor(Random() * MAX_DECK);
            G.handCount[p] = floor(Random() * MAX_HAND);
        }

        //copy initial game state to be used for testing
        memcpy(&testG, &G, sizeof(struct gameState));

        //play card
        cardEffect(village, 0, 0, 0, &testG, 0, 0);

        //check that number of cards in hand was increased by 1
        //since village was played the hand count after village
        //will be the same as before village was played
        if (testG.handCount[player] != G.handCount[player]){
           failHand++;
        }

        //check that number of actions was increased by 2
        if (testG.numActions != (G.numActions + 2)){
           failAction++;
        }

        //check that number of cards in deck was decreased by 1
        //testing only if the deck was not empty, because it if was
        //deck was filled with discard piles
        if(G.deckCount[player] > 0){
            if (testG.deckCount[player] != (G.deckCount[player] - 1)){
                failDeck++;
            }
        }
        //testing if discard pile was moved to the deck
        else{
            if (testG.deckCount[player] != (G.discardCount[player] - 1)){
                failDeck++;
            }
        }

        //check deck count
        //if discard was not added to the deck, it should be increased by one
        if(G.deckCount[player] > 0){
            if (testG.deckCount[player] != (G.deckCount[player] - 1)){
                failDeck++;
            }
        }
        //testing if discard pile was moved to the deck
        else{
            if (testG.deckCount[player] != (G.discardCount[player] - 1)){
                failDeck++;
            }
        }

        //check that discard count was not changed if it was not added to the deck;
        //otherwise, it should be 0
         if(G.deckCount[player] > 0){
            if (testG.discardCount[player] != G.discardCount[player]){
                failDiscard++;
            }
        }
        //testing if discard pile was moved to the deck
        else{
            if (testG.discardCount[player] != 0){
                failDiscard++;
            }
        }

        //check that play count was increased by 1
        if (testG.playedCardCount != G.playedCardCount+1){
           failPlay++;
        }

        //check others players hands; should be unchanged
        int h;
        for (h = 1; h < numPlayers; h++){
            if(testG.handCount[h] != G.handCount[h]){
                failHandOthers++;
            }
        }

        //check others players deck; should be unchanged
        int d;
        for (d = 1; d < numPlayers; d++){
            if(testG.deckCount[d] != G.deckCount[d]){
                failDeckOthers++;
            }
        }

        //check that victory pile was unchanged
        if (testG.supplyCount[estate] != G.supplyCount[estate]){
           failVictory++;
        }
        if (testG.supplyCount[duchy] != G.supplyCount[duchy]){
           failVictory++;
        }
        if (testG.supplyCount[province] != G.supplyCount[province]){
           failVictory++;
        }

        //check that kingdom pile was unchanged
        if (testG.supplyCount[adventurer] != G.supplyCount[adventurer]){
           failKingdom++;
        }
        if (testG.supplyCount[council_room] != G.supplyCount[council_room]){
           failKingdom++;
        }
        if (testG.supplyCount[feast] != G.supplyCount[feast]){
           failKingdom++;
        }
        if (testG.supplyCount[gardens] != G.supplyCount[gardens]){
           failKingdom++;
        }
        if (testG.supplyCount[mine] != G.supplyCount[mine]){
           failKingdom++;
        }
        if (testG.supplyCount[remodel] != G.supplyCount[remodel]){
           failKingdom++;
        }
        if (testG.supplyCount[smithy] != G.supplyCount[smithy]){
           failKingdom++;
        }
        if (testG.supplyCount[village] != G.supplyCount[village]){
           failKingdom++;
        }
        if (testG.supplyCount[baron] != G.supplyCount[baron]){
           failKingdom++;
        }
        if (testG.supplyCount[great_hall] != G.supplyCount[great_hall]){
           failKingdom++;
        }

    }
    printf("Number of performed tests: %d.\n\n", MAX_TEST);

    printf("Test that number of cards in hand is increased by 1\n");
    printf("Number of FAILED tests: %d.\n\n", failHand);

    printf("Test that number of actions is increased by 2\n");
    printf("Number of FAILED tests: %d.\n\n", failAction);

    printf("Test that number of cards in deck is decreased by 1\n");
    printf("Number of FAILED tests: %d.\n\n", failDeck);

    printf("Test that number of cards in discard is correct \n");
    printf("Number of FAILED tests: %d.\n\n", failDiscard);

    printf("Test if other player's deck count was unchanged \n");
    printf("Number of FAILED tests: %d.\n\n", failDeckOthers);

    printf("Test if other player's hand count was unchanged \n");
    printf("Number of FAILED tests: %d.\n\n", failHandOthers);

    printf("Test if played count was increased by 1 \n");
    printf("Number of FAILED tests: %d.\n\n", failPlay);

    printf("Test that victory card pile was not changed \n");
    printf("Number of FAILED tests: %d.\n\n", failVictory);

    printf("Test that kingdom card pile was not changed \n");
    printf("Number of FAILED tests: %d.\n\n", failKingdom);

	return 0;
}
