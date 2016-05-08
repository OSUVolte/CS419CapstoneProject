/*
Alex Samuel
Assignment 4
randomtestcard.c
Random Tester for smithy card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int main() {
    srand (time(NULL));

    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int i, j, m;
    int newCards = 3;
    int discarded = 1;
    int minPlayers = 2;
    int numPlayers = 0;
    int PlayerID = 0;
    int errorFlag1 = 0;
    int errorFlag2 = 0;
    int errorFlag3 = 0;
    int counter = 0;

	struct gameState G, testG;

    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy, council_room};

	for (i = minPlayers; i < MAX_PLAYERS + 1; i++) {
            numPlayers = i;

        for (j = 0; j < 1000000; j++) {

            int seed = floor(Random() * 1000);
            int handpos = floor(Random() * MAX_HAND);
            int bonus = floor(Random() * 1000);

            int seed1C = floor(Random() * 1000);
            int seed2C = floor(Random() * 1000);
            int seed3C = floor(Random() * 1000);

            if (seed1C % 2 == 0) {
                choice1 = 1;
            }

            if (seed2C % 2 == 0) {
                choice2 = 1;
            }

            if (seed3C % 2 == 0) {
                choice3 = 1;
            }

            //Initializes game and copies game state to test case
            initializeGame(numPlayers, k, seed, &G);
            memcpy(&testG, &G, sizeof(struct gameState));

            PlayerID = whoseTurn(&testG);

            cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

            //Random Test 1 - Testing smithy - +3 Cards Added to Player's Hand
            //Test fails because of bug introduced in refactor.c where 4 cards are drawn instead of 3
            if (testG.handCount[PlayerID] != (G.handCount[PlayerID] + newCards - discarded)) {
                errorFlag1 = 1;
            }

            //Random Test 2 - Other Players Are Unaffected by Player 1 Playing Smithy
            for (m = 1; m < numPlayers; m++) {

                PlayerID = m;
                int GDeckResults[27] = { 0 };
                int testGDeckResults[27] = { 0 };
                int GHandResults[27] = { 0 };
                int testGHandResults[27] = { 0 };
                int Deckdifference[27] = { 0 };
                int Handdifference[27] = { 0 };
                int cardVal;
                int cardTotal;


                for (i = 0; i < G.deckCount[PlayerID]; i++) {
                    cardVal = G.deck[PlayerID][i];
                    GDeckResults[cardVal]++;
                }

                for (i = 0; i < testG.deckCount[PlayerID]; i++) {
                    cardVal = testG.deck[PlayerID][i];
                    testGDeckResults[cardVal]++;
                }

                /*
                for (i = 0; i < G.handCount[PlayerID]; i++) {
                    cardVal = G.hand[PlayerID][i];
                    GHandResults[cardVal]++;
                }


                for (i = 0; i < testG.handCount[PlayerID]; i++) {
                    cardVal = testG.hand[PlayerID][i];
                    testGHandResults[cardVal]++;
                }
                */


                //no difference in hand totals because hands are only drawn at start if turn,
                //see dominion.c, line 197

                //Compares whether any change to Player 2 hand or deck
                if (memcmp(GDeckResults, testGDeckResults, sizeof(GDeckResults)) == 0 &&
                    memcmp(GHandResults, testGHandResults, sizeof(GHandResults)) == 0 ) {
                        //printf("\n\nRANDOM TEST 3 HAS PASSED\n\n");
                }
                else {
                    errorFlag3 = 1;
                }

                memset(GDeckResults, 0, 27 * (sizeof GDeckResults[0]) );
                memset(testGDeckResults, 0, 27 * (sizeof testGDeckResults[0]) );
                memset(GHandResults, 0, 27 * (sizeof GHandResults[0]) );
                memset(testGHandResults, 0, 27 * (sizeof testGHandResults[0]) );
                memset(Deckdifference, 0, 27 * (sizeof Deckdifference[0]) );
                memset(Handdifference, 0, 27 * (sizeof Handdifference[0]) );

            }

            memset(&G, 23, sizeof(struct gameState));
            memset(&testG, 23, sizeof(struct gameState));

            if(counter == 0) {
                printf("RANDOM TESTING IN PROGRESS...");
            }
            else if(counter % 10000 == 0) {
                printf(".");
            }

            counter++;

        }

	}


    printf("\n\nRANDOM TEST 1: Testing smithy - +3 Cards Added to Player's Hand\n");
    if (errorFlag1 > 0) {
        printf("RANDOM TEST 1 HAS FAILED\n\n");
    }
    else {
        printf("RANDOM TEST 1 HAS PASSED\n\n");
    }

    printf("RANDOM TEST 2: Testing smithy - Other Players Are Unaffected by Player 1 Playing Smithy\n");
    if (errorFlag2 > 0) {
        printf("RANDOM TEST 2 HAS FAILED\n\n");
    }
    else {
        printf("RANDOM TEST 2 HAS PASSED\n\n");
    }



    return 0;
}
