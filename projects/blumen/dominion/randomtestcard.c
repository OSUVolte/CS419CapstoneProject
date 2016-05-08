/**
randomtestcard.c: Tests the REMODEL card.

Basic requirements for the REMODEL card:
0. if pile of card player wants to gain is empty, no change to game and return value = -1
1. Cost of card player trashes + 2 is at least as much as the cost of the card player wants to gain (else return -1)
2. Card that the player wants to gain (choice 2) ends up in player's discard pile
3. Pile of "gained" card is decremented by 1
4. Card that the player wants to trash (choice 1) ends up in trash (not discard pile)
5. Hand count for the player is decremented by 1
6. Except for #3 above, no state change should occur to the victory card piles and kingdom card piles.
7. No change to coin, numBuys or numActions.
8. No state change should occur for other players.

Likely errors in code:
-

Random Testing:
    A random tester generates random input from across the population of possible input.
    Sampling biases may be introduced to ensure that specific subpopulations are tested and
    that others are not over-tested.

    Random input for the remodel card:
    - the size & composition of the player's hand, deck and discard are randomized
    - the size & composition of the other player's hand, deck and discard are randomized
    - the number of buys, actions and coins are randomized
    - the sizes of the kingdom, treasury, curse and victory piles are randomized
    - the place in hand of choice1, the card to trash (include error positions)
    - the type of card to trash (incl. its cost, treasury vs. etc., cost relative to choice2) --> this is achieved indirectly through combo random hand + choice1= random place in hand
    - choice2 (incl. its cost, treasury vs. etc.)
    //ALT: I could have set specific choice1 and 2 and their cost dif, but would lost the benefit of the randomization scheme

**/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "remodel"       //*******************>>>> change me

void randomtestcard() {
    time_t t;
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

    for (trialNumber = 0; trialNumber < 3; trialNumber++) {

        // Set & save random seed
        printf("----------------- Generating random input: %s trial number %d ----------------\n", TESTCARD, trialNumber);

        //Select a stream at random, the classic way. I am not using rngs.c because (1) I haven't seen an example of it
        //being used in the dominion code and (2) upon quick inspection, I do not understand the distinctions explained in
        //the rngs.c code and therefore I risk misusing rngs.c -- e.g. what var would I use in initializeGame?
//        int seed = 7;
//        srand((unsigned) seed);
        srand((unsigned) (time(&t) + seed));
        seed = rand() % 100000000000;
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
                G.hand[thisPlayer][i] = 1 + (rand() % (treasure_map)); //avoid Curse card
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
                G.hand[otherPlayer][i] = 1 + (rand() % (treasure_map)); //avoid Curse card
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
        G.discardCount[thisPlayer] = rand() % 11;//Set to a max of 10
//        printf("Player has %d cards in the discard pile.\n", G.discardCount[thisPlayer]);
        for (i = 0; i < (G.discardCount[thisPlayer]); i++){
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

        // randomize the size & composition of the other player's discard pile
        G.discardCount[otherPlayer] = rand() % 11;//Set to a max of 10
//        printf("Opponent has %d cards in the discard pile.\n", G.discardCount[otherPlayer]);
        for (i = 0; i < (G.discardCount[otherPlayer]); i++){
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

        // randomize the number of buys, actions and coins for the player
        G.coins = rand() % 21;
//        printf("Coins: %d\n", G.coins);
        G.numActions = rand() % 11;
//        printf("Number of actions: %d\n", G.numActions);
        G.numBuys = rand() % 11;
//        printf("Number of buys: %d\n", G.numBuys);

        //randomize the place in hand of choice1, the card to trash (include error positions)
        choice1 = rand() % (G.handCount[thisPlayer]+1);
//        printf("choice1 (card selected for discard): %d\n", choice1);

        //randomize the pile from which choice2 is drawn. (incl. its cost, treasury vs. etc.)
        j = 1;
        while (j){
            choice2 = rand() % (treasure_map + 1);
            for (m = 0; m < 10; m++){
                if ((choice2 == k[m]) || (choice2 < adventurer)){
                    j=0;
                }
            }
        }
//        printf("choice2 (pile from which a better card is selected): %d\n", choice2);

        //Expected return value
        int expectedReturnValue = 0;

        //if the pile corresponding to choice 2 is empty then expected =  -1
        if(G.supplyCount[choice2] <= 0){
            expectedReturnValue = -1;
        }

        //if choice2 has value greater than 2+choice1, then expected = -1
        if(getCost(choice2) > (getCost(choice1)+2)){
            expectedReturnValue = -1;
        }

        // test adventureCard for all possible behaviors: here, there is no expected failure
        printf("\n----------------- Testing Card: %s ----------------\n", TESTCARD);

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));

        // apply the play to the testG game state
        int actualReturnValue = cardEffect(remodel, choice1, choice2, choice3, &testG, handpos, &bonus);        //*******************>>>> change me

        // ----------- TEST 0: If pile of card player wants to gain is empty, no change to game and return value = -1 --------------
        printf("TEST 0: If pile of card player wants to gain is empty, no change to game and return value = -1\n");
        printf(" return value = %d, expected = %d, ", actualReturnValue, expectedReturnValue);
        if (actualReturnValue == expectedReturnValue){
            printf(" test passed.\n");
        } else {
            printf(" TEST FAILED.\n");
            failures++;
        }

        // ----------- TEST 1: Cost of card player trashes + 2 is at least as much as the cost of the card player wants to gain --------------
        printf("TEST 1: Cost of card player trashes + 2 is at least as much as the cost of the card player wants to gain \n");
        printf(" return value = %d, expected: no more than %d, ", getCost(choice2), (getCost(choice1)+2));
        if (getCost(choice2) <= (getCost(choice1)+2)){
            printf(" test passed.\n");
        } else {
            printf(" TEST FAILED.\n");
            failures++;
        }

        // ----------- TEST 2: Card that the player wants to gain (choice 2) ends up in player's discard pile --------------
        printf("TEST 2: Card that the player wants to gain (choice 2) ends up in player's discard pile.\n");
        printf(" discarded: %d, expected: %d, ", testG.discard[thisPlayer][testG.discardCount[thisPlayer]-1], choice2);
        if (testG.discard[thisPlayer][testG.discardCount[thisPlayer]-1] == choice2){
            printf(" test passed.\n");
        } else {
            printf(" TEST FAILED.\n");
            failures++;
        }

        // ----------- TEST 3: Pile from which a card was gained is decremented by 1 --------------
        printf("TEST 3: Pile from which a card was gained is decremented by 1\n");
        printf(" actual: %d, expected: %d, ", testG.supplyCount[choice2], G.supplyCount[choice2]-1);
        if (testG.supplyCount[choice2] == G.supplyCount[choice2]-1){
            printf(" test passed.\n");
        } else {
            printf(" TEST FAILED.\n");
            failures++;
        }

        // ----------- TEST 4: Card that the player wants to trash (choice 1) ends up in trash (not discard pile) --------------
        printf("TEST 4: Card that the player wants to trash (choice 1) ends up in trash (not discard pile)\n");
        m = testG.discardCount[thisPlayer] - G.discardCount[thisPlayer]; // number of cards discarded during play
        for (i=1; i<=m; i++) {
            printf(" discarded: %d, expected not to be %d, ", testG.discard[thisPlayer][ testG.discardCount[thisPlayer] -i ], choice1);
            if (testG.discard[thisPlayer][ testG.discardCount[thisPlayer] -i ] != choice1){
                printf(" test passed.\n");
            } else {
                printf(" TEST FAILED.\n");
                failures++;
            }
        }

        // ----------- TEST 5: Hand count for the player is decremented by 1 --------------
        printf("TEST 5: Hand count for the player is decremented by 1\n");
        printf(" hand count = %d, expected = %d, ", testG.handCount[thisPlayer], G.handCount[thisPlayer] -1);
        if (testG.handCount[thisPlayer] == (G.handCount[thisPlayer] -1)){
            printf(" test passed.\n");
        } else {
            printf(" TEST FAILED.\n");
            failures++;
        }

        // ----------- TEST 6: Except for #3 above, no state change should occur to the victory card piles and kingdom card piles. --------------
        printf("TEST 6: Except for #3 above, no state change should occur to the victory card piles and kingdom card piles. \n");
        for (i = curse; i <= treasure_map; i++) {    //loop over all possible cards in dominion universe (see enum def in dominion.h)
            if (i != choice2) {
                if (testG.supplyCount[i] == G.supplyCount[i]){
                    printf(" For card %d, test passed.\n", i);
                } else {
                    printf(" For card %d, TEST FAILED.\n", i);
                    failures++;
                }
            }
        }

        // ----------- TEST 7: No change to coin, numBuys or numActions. --------------
        printf("TEST 7: No change to coin, numBuys or numActions. \n");
        if (G.coins == testG.coins){
            printf(" Coins test passed.\n");
        } else {
            printf(" COINS TEST FAILED.\n");
            failures++;
        }
        if (G.numBuys == testG.numBuys){
            printf(" numBuys test passed.\n");
        } else {
            printf(" NUMBUYS TEST FAILED.\n");
            failures++;
        }
        if (G.numActions == testG.numActions){
            printf(" numActions test passed.\n");
        } else {
            printf(" NUMACTIONS TEST FAILED.\n");
            failures++;
        }

        // ----------- TEST 8: No change to other player's hand or deck --------------
        printf("TEST 8: No change to other player's hand or deck.\n");
        printf(" hand count = %d, expected = %d, ", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
        //assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);
        if (testG.handCount[otherPlayer] == G.handCount[otherPlayer]){
            printf(" test passed.\n");
        } else {
            printf(" TEST FAILED.\n");
            failures++;
        }
        printf(" deck count = %d, expected = %d, ", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
        //assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]);
        if (testG.deckCount[otherPlayer] == G.deckCount[otherPlayer]){
            printf(" test passed.\n");
        } else {
            printf(" TEST FAILED.\n");
            failures++;
        }


        if (failures == 0){
            printf("\n >>>>> SUCCESS: Testing complete %s trial number %d <<<<<\n\n", TESTCARD, trialNumber);
        } else {
            printf("\n >>>>> NUMBER OF FAILURES: %d -- Testing complete %s trial number %d <<<<<\n\n", failures, TESTCARD, trialNumber);
        }

    }

}
