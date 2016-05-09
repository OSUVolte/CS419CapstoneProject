/**
randomtestadventurer.c: Tests the ADVENTURER card.

Basic requirements for the card:
1. Current player should receive exactly 2 cards.
2. Current player should receive only treasury cards.
3. No treasury card should have been discarded.
4. The 2 treasury Cards should come from the player's own pile (deck+discard are decremented by 2)
5. No state change should occur for other players.
6. No state change should occur to the victory card piles and kingdom card piles.

Random Testing -- General Principle: A random tester generates random input from across the
    population of possible input. Sampling biases may be introduced to ensure that specific
    subpopulations are sufficiently tested.

Random input for the remodel card:
    - the size & composition of the player's hand, deck and discard are randomized + discard pile is stuffed with 2 treasury cards
    - the size & composition of the other player's hand, deck and discard are randomized
    - the number of buys, actions and coins are randomized
    - the sizes of the kingdom, treasury, curse and victory piles are randomized

**/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "adventurer"       //*******************>>>> change me

void randomtestadventurer() {
    time_t t;
    int newCards = 0;
    int discarded = 0;
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
	struct gameState G, testG;
	int k[10] = {smithy, adventurer, feast, council_room, gardens, village, remodel, mine, cutpurse, embargo};
	int failures = 0;
    int trialNumber;
    int seed = 0;

    for (trialNumber = 0; trialNumber < 100; trialNumber++) {

        // Set & save random seed
        printf("----------------- Generating random input: %s ----------------\n", TESTCARD);

        //Select a stream at random, the classic way. I am not using rngs.c because (1) I haven't seen an example of it
        //being used in the dominion code and (2) upon quick inspection, I do not understand the distinctions explained in
        //the rngs.c code and therefore I risk misusing rngs.c -- e.g. what var would I use in initializeGame?
//        int seed = 7;
//        srand((unsigned) seed);
        srand((unsigned) (time(&t) + seed));
        int seed = rand() % 100000000000;
        printf("\n The seed is: %d\n", seed);

        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        // randomize the supply of curse, treasury, victory and kingdom cards
        for (i = curse; i <= treasure_map; i++) {    //loop over all possible cards in dominion universe (see enum def in dominion.h)
            if (G.supplyCount[i] != -1) {
                G.supplyCount[i] = G.supplyCount[i] - rand() % (G.supplyCount[i] + 1);
            }
//            printf("Supply of card %i is set to: %d\n", i, G.supplyCount[i]);
        }

        // randomize the size & composition of the player's hand
        G.handCount[thisPlayer] = rand() % 11;//Set current player's hand count to a max of 10
//        printf("Player has %d cards in hand.\n", G.handCount[thisPlayer]);
        for (i = 0; i < G.handCount[thisPlayer]; i++){
            j = 1;
            while (j){
                G.hand[thisPlayer][i] = rand() % (treasure_map + 1);
                for (m = 0; m < 10; m++){
                    if ((G.hand[thisPlayer][i] == k[m]) || (G.hand[thisPlayer][i] < adventurer)){ //check that the card is one of the set in play
                        j=0;
                    }
                }
            }
//            printf("Player's hand contains: %d\n", G.hand[thisPlayer][i]);
        }

        // randomize the size & composition of the other player's hand
        G.handCount[otherPlayer] = rand() % 11;//Set current player's hand count to a max of 10
//        printf("Opponent has %d cards in hand.\n", G.handCount[otherPlayer]);
        for (i = 0; i < G.handCount[otherPlayer]; i++){
            j = 1;
            while (j){
                G.hand[otherPlayer][i] = rand() % (treasure_map + 1);
                for (m = 0; m < 10; m++){
                    if ((G.hand[otherPlayer][i] == k[m]) || (G.hand[otherPlayer][i] < adventurer)){
                        j=0;
                    }
                }
            }
//            printf("Opponent's hand contains: %d\n", G.hand[otherPlayer][i]);
        }

        // randomize the size & composition of the player's deck
        G.deckCount[thisPlayer] = rand() % 11;//Set to a max of 10
//        printf("Player has %d cards in the deck.\n", G.deckCount[thisPlayer]);
        for (i = 0; i < G.deckCount[thisPlayer]; i++){
            j = 1;
            while (j){
                G.deck[thisPlayer][i] = rand() % (treasure_map + 1);
                for (m = 0; m < 10; m++){
                    if ((G.deck[thisPlayer][i] == k[m]) || (G.deck[thisPlayer][i] < adventurer)){
                        j=0;
                    }
                }
            }
//            printf("Player's deck contains: %d\n", G.deck[thisPlayer][i]);
        }

        // randomize the size & composition of the other player's deck
        G.deckCount[otherPlayer] = rand() % 11;//Set to a max of 10
//        printf("Opponent has %d cards in the deck.\n", G.deckCount[otherPlayer]);
        for (i = 0; i < G.deckCount[otherPlayer]; i++){
            j = 1;
            while (j){
                G.deck[otherPlayer][i] = rand() % (treasure_map + 1);
                for (m = 0; m < 10; m++){
                    if ((G.deck[otherPlayer][i] == k[m]) || (G.deck[otherPlayer][i] < adventurer)){
                        j=0;
                    }
                }
            }
//            printf("Opponent's deck contains: %d\n", G.deck[otherPlayer][i]);
        }

        // randomize the size & composition of the player's discard pile
        G.discardCount[thisPlayer] = rand() % 11 + 2;//Set to a min of 2, max of 12
//        printf("Player has %d cards in the discard pile.\n", G.discardCount[thisPlayer]);
        for (i = 0; i < (G.discardCount[thisPlayer]-2); i++){
            j = 1;
            while (j){
                G.discard[thisPlayer][i] = rand() % (treasure_map + 1);
                for (m = 0; m < 10; m++){
                    if ((G.discard[thisPlayer][i] == k[m]) || (G.discard[thisPlayer][i] < adventurer)){
                        j=0;
                    }
                }
            }
//            printf("Player's discard pile contains: %d\n", G.discard[thisPlayer][i]);
        }
        G.discard[thisPlayer][G.discardCount[thisPlayer]-1] = copper; //guarantee against a deck+discard without sufficient treasure
//        printf("Player's discard pile contains: %d\n", G.discard[thisPlayer][G.discardCount[thisPlayer]-1]);
        G.discard[thisPlayer][G.discardCount[thisPlayer]-2] = copper; //sufficient treasure = 2 treasure cards
//        printf("Player's discard pile contains: %d\n", G.discard[thisPlayer][G.discardCount[thisPlayer]-2]);

        // randomize the size & composition of the other player's discard pile
        G.discardCount[otherPlayer] = rand() % 11 + 2;//Set to a min of 2, max of 12
//        printf("Opponent has %d cards in the discard pile.\n", G.discardCount[otherPlayer]);
        for (i = 0; i < (G.discardCount[otherPlayer]-2); i++){
            j = 1;
            while (j){
                G.discard[otherPlayer][i] = rand() % (treasure_map + 1);
                for (m = 0; m < 10; m++){
                    if ((G.discard[otherPlayer][i] == k[m]) || (G.discard[otherPlayer][i] < adventurer)){
                        j=0;
                    }
                }
            }
//            printf("Opponent's discard pile contains: %d\n", G.discard[otherPlayer][i]);
        }
        G.discard[otherPlayer][G.discardCount[otherPlayer]-1] = copper; //guarantee against a deck+discard without sufficient treasure
//        printf("Opponent's discard pile contains: %d\n", G.discard[otherPlayer][G.discardCount[otherPlayer]-1]);
        G.discard[otherPlayer][G.discardCount[otherPlayer]-2] = copper; //sufficient treasure = 2 treasure cards
//        printf("Opponent's discard pile contains: %d\n", G.discard[otherPlayer][G.discardCount[otherPlayer]-2]);

        // randomize the number of buys, actions and coins for the player
        G.coins = rand() % 21;
//        printf("Coins: %d\n", G.coins);
        G.numActions = rand() % 11;
//        printf("Number of actions: %d\n", G.numActions);
        G.numBuys = rand() % 11;
//        printf("Number of buys: %d\n", G.numBuys);

        // test adventureCard for all possible behaviors: here, there is no expected failure
        printf("\n----------------- Testing Card: %s ----------------\n", TESTCARD);

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));

        // apply the play to the testG game state
        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);        //*******************>>>> change me

        // variables that reflect expected outcome
        newCards = 2;

        // ----------- TEST 1: +2 cards in player's hand --------------
        printf("TEST 1: +2 cards in player's hand\n");
        printf(" hand count = %d, expected = %d, ", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
        //assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
        if (testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded){
            printf("test passed.\n");
        } else {
            printf("TEST FAILED.\n");
            failures++;
        }

        // ----------- TEST 2: Current player should receive only treasury cards. --------------
        printf("TEST 2: Current player should receive only treasury cards.\n");
        printf(" Last card added to hand = %d, expected = %d, %d or %d, ", testG.hand[thisPlayer][testG.handCount[thisPlayer]-1], copper, silver, gold);
        m = 0;
        for (i=(int)copper; i<=(int)gold; i++){
            if (testG.hand[thisPlayer][testG.handCount[thisPlayer]-1] == i) {
                m++;
            }
        }
        //assert(m > 0);
        if (m > 0){
            printf("test passed.\n");
        } else {
            printf("TEST FAILED.\n");
            failures++;
        }
        printf(" Second-to-last card added to hand = %d, expected = %d, %d or %d, ", testG.hand[thisPlayer][testG.handCount[thisPlayer]-2], copper, silver, gold);
        m = 0;
        for (i=(int)copper; i<=(int)gold; i++){
            if (testG.hand[thisPlayer][testG.handCount[thisPlayer]-2] == i) {
                m++;
            }
        }
        //assert(m > 0);
        if (m > 0){
            printf("test passed.\n");
        } else {
            printf("TEST FAILED.\n");
            failures++;
        }

        // ----------- TEST 3: No treasury card should have been discarded. --------------
        printf("TEST 3: No treasury card should have been discarded.\n");
        for (i=1; i<=testG.discardCount[thisPlayer]; i++) {
            printf(" discarded: %d, expected not to be in set {%d, %d, %d}, ", testG.discard[thisPlayer][ testG.discardCount[thisPlayer] -i ], copper, silver, gold);
            for (j=(int)copper; j<=(int)gold; j++){
                //assert(testG.discard[thisPlayer][ testG.discardCount[thisPlayer] -m ] != j);
                if (testG.discard[thisPlayer][ testG.discardCount[thisPlayer] -i ] == j){
                    printf("TEST FAILED.");
                    failures++;
                } else {
                    printf("test passed.");
                }
            }
            printf("\n");
        }
        if ( testG.discardCount[thisPlayer] ==0){
             printf(" no card was discarded: test passed.\n");
        }

        // ----------- TEST 4: The 2 treasury Cards should come from the player's own pile (deck+discard are decremented by 2) --------------
        printf("TEST 4: The 2 treasury Cards should come from the player's own pile\n");
        m = G.deckCount[thisPlayer] + G.discardCount[thisPlayer] - (testG.deckCount[thisPlayer] + testG.discardCount[thisPlayer]);
        printf(" deck+discard has decreased by %d cards, expected = 2, ", m);
        if (m == 2){
            printf("test passed.\n");
        } else {
            printf("TEST FAILED.\n");
            failures++;
        }

        // ----------- TEST 5: No change to other player's hand or deck --------------
        printf("TEST 5: No change to other player's hand or deck.\n");
        printf(" hand count = %d, expected = %d, ", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
        //assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);
        if (testG.handCount[otherPlayer] == G.handCount[otherPlayer]){
            printf("test passed.\n");
        } else {
            printf("TEST FAILED.\n");
            failures++;
        }
        printf(" deck count = %d, expected = %d, ", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
        //assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]);
        if (testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]){
            printf("test passed.\n");
        } else {
            printf("TEST FAILED.\n");
            failures++;
        }

        // ----------- TEST 6: No state change should occur to the curse, victory, treasury and kingdom card piles. --------------
        printf("TEST 6: No state change to the curse, victory, treasury and kingdom card piles: \n");
        for (i = curse; i <= treasure_map; i++) {    //loop over all possible cards in dominion universe (see enum def in dominion.h)
            //assert(testG.supplyCount[i] == G.supplyCount[i]);
            if (testG.supplyCount[i] == G.supplyCount[i]){
                printf("For card %d, test passed.\n", i);
            } else {
                printf("For card %d, TEST FAILED.\n", i);
                failures++;
            }
        }
        //printf(" Confirmed.");

        if (failures == 0){
            printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
        } else {
            printf("\n >>>>> NUMBER OF FAILURES: %d -- Testing complete %s <<<<<\n\n", failures, TESTCARD);
        }
    }
}
