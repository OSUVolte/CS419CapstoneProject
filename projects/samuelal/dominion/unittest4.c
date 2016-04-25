/*
Alex Samuel
Assignment 3
unittest4.c
Tests scoreFor() Function
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {

    int numPlayers = 2;
    int PlayerID = 0;
    int seed = 2;
    int i;
    int errorFlag = 0;
	struct gameState G, testG;

	int manualScoreResult = 0;
	int ScoreForResult = 0;
    int cardScore;
    int ScoreTotal;

    SelectStream(8);
    PutSeed(9);

    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy, council_room};

    printf("TEST 1: Testing scoreFor() - Normal Card Distribution\n");

    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    int totalCards = testG.handCount[PlayerID] + testG.deckCount[PlayerID] + testG.discardCount[PlayerID];

    //Calculates the total number of victory points in players hand
    for (i = 0; i < testG.handCount[PlayerID]; i++) {
        if (testG.hand[PlayerID][i] == curse) {
                --manualScoreResult;
        }
        else if (testG.hand[PlayerID][i] == estate) {
                ++manualScoreResult;
        }
        else if (testG.hand[PlayerID][i] == duchy) {
                manualScoreResult = manualScoreResult + 3;
        }
        else if (testG.hand[PlayerID][i] == province) {
                manualScoreResult = manualScoreResult + 6;
        }
        else if (testG.hand[PlayerID][i] == great_hall) {
                ++manualScoreResult;
        }
        else if (testG.hand[PlayerID][i] == gardens) {
                manualScoreResult = manualScoreResult + (( totalCards ) / 10 );
        }
    }

    //Calculates the total number of victory points in players deck pile
    for (i = 0; i < testG.deckCount[PlayerID]; i++) {
        if (testG.deck[PlayerID][i] == curse) {
                --manualScoreResult;
        }
        else if (testG.deck[PlayerID][i] == estate) {
                ++manualScoreResult;
        }
        else if (testG.deck[PlayerID][i] == duchy) {
                manualScoreResult = manualScoreResult + 3;
        }
        else if (testG.deck[PlayerID][i] == province) {
                manualScoreResult = manualScoreResult + 6;
        }
        else if (testG.deck[PlayerID][i] == great_hall) {
                ++manualScoreResult;
        }
        else if (testG.deck[PlayerID][i] == gardens) {
                manualScoreResult = manualScoreResult + (( totalCards ) / 10 );
        }
    }

//Calculates the total number of victory points in players discard
    for (i = 0; i < testG.discardCount[PlayerID]; i++) {
        if (testG.discard[PlayerID][i] == curse) {
                --manualScoreResult;
        }
        else if (testG.discard[PlayerID][i] == estate) {
                ++manualScoreResult;
        }
        else if (testG.discard[PlayerID][i] == duchy) {
                manualScoreResult = manualScoreResult + 3;
        }
        else if (testG.discard[PlayerID][i] == province) {
                manualScoreResult = manualScoreResult + 6;
        }
        else if (testG.discard[PlayerID][i] == great_hall) {
                ++manualScoreResult;
        }
        else if (testG.discard[PlayerID][i] == gardens) {
                manualScoreResult = manualScoreResult + (( totalCards ) / 10 );
        }
    }

    ScoreForResult = scoreFor(PlayerID, &testG);

    printf("Total Score from scoreFor()= %d, Expected Total Score = %d\n", ScoreForResult, manualScoreResult);

    if(ScoreForResult != manualScoreResult) {
        printf("TEST 1 HAS FAILED\n\n");
        errorFlag = 1;
    }

    printf("TEST 2: Testing scoreFor() - Random Card Distribution\n");

    int cards[] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens,
    mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost,
    salvager, sea_hag, treasure_map};

    memset(&G, 23, sizeof(struct gameState));
    memset(&testG, 23, sizeof(struct gameState));
    manualScoreResult = 0;
    ScoreForResult = 0;
    totalCards = 0;

    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    G.handCount[PlayerID] = MAX_HAND;
    G.deckCount[PlayerID] = MAX_DECK;
    G.discardCount[PlayerID] = MAX_DECK;
    int cardIndex;

//These for loops randomly assign cards to player's hand, deck, and discard pile
    for (i = 0; i < G.handCount[PlayerID]; i++) {
        cardIndex = floor(Random() * 27); //generates a random value between 0 and 27
        G.hand[PlayerID][i] = cards[cardIndex]; //randomly assigns a card to the hand
    }

    for (i = 0; i < G.deckCount[PlayerID]; i++) {
        cardIndex = floor(Random() * 27);
        G.deck[PlayerID][i] = cards[cardIndex];
    }

    for (i = 0; i < G.discardCount[PlayerID]; i++) {
        cardIndex = floor(Random() * 27);
        G.discard[PlayerID][i] = cards[cardIndex];
    }

    totalCards = G.handCount[PlayerID] + G.deckCount[PlayerID] + G.discardCount[PlayerID];

    for (i = 0; i < G.handCount[PlayerID]; i++) {
        if (G.hand[PlayerID][i] == curse) {
                --manualScoreResult;
        }
        else if (G.hand[PlayerID][i] == estate) {
                ++manualScoreResult;
        }
        else if (G.hand[PlayerID][i] == duchy) {
                manualScoreResult = manualScoreResult + 3;
        }
        else if (G.hand[PlayerID][i] == province) {
                manualScoreResult = manualScoreResult + 6;
        }
        else if (G.hand[PlayerID][i] == great_hall) {
                ++manualScoreResult;
        }
        else if (G.hand[PlayerID][i] == gardens) {
                manualScoreResult = manualScoreResult + (( totalCards ) / 10 );
        }
    }

    for (i = 0; i < G.deckCount[PlayerID]; i++) {
        if (G.deck[PlayerID][i] == curse) {
                --manualScoreResult;
        }
        else if (G.deck[PlayerID][i] == estate) {
                ++manualScoreResult;
        }
        else if (G.deck[PlayerID][i] == duchy) {
                manualScoreResult = manualScoreResult + 3;
        }
        else if (G.deck[PlayerID][i] == province) {
                manualScoreResult = manualScoreResult + 6;
        }
        else if (G.deck[PlayerID][i] == great_hall) {
                ++manualScoreResult;
        }
        else if (G.deck[PlayerID][i] == gardens) {
                manualScoreResult = manualScoreResult + (( totalCards ) / 10 );
        }
    }

    for (i = 0; i < G.discardCount[PlayerID]; i++) {
        if (G.discard[PlayerID][i] == curse) {
                --manualScoreResult;
        }
        else if (G.discard[PlayerID][i] == estate) {
                ++manualScoreResult;
        }
        else if (G.discard[PlayerID][i] == duchy) {
                manualScoreResult = manualScoreResult + 3;
        }
        else if (G.discard[PlayerID][i] == province) {
                manualScoreResult = manualScoreResult + 6;
        }
        else if (G.discard[PlayerID][i] == great_hall) {
                ++manualScoreResult;
        }
        else if (G.discard[PlayerID][i] == gardens) {
                manualScoreResult = manualScoreResult + (( totalCards ) / 10 );
        }
    }

    ScoreForResult = scoreFor(PlayerID, &G);

    printf("Total Score from scoreFor()= %d, Expected Total Score = %d\n", ScoreForResult, manualScoreResult);

    if(ScoreForResult != manualScoreResult) {
        printf("TEST 2 HAS FAILED\n\n");
        errorFlag = 1;
    }

    if (errorFlag == 0) {
        printf("ALL TESTS PASSED\n\n");
    }

    return 0;

}
