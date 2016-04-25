#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){
    int score = 0;
    int p, result;
    int k[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, baron, sea_hag, great_hall};
    int numPlayers = 2;
    struct gameState G;
    memset(&G, 0, sizeof(struct gameState));
    initializeGame(numPlayers, k, 1, &G); //initialize game

    printf ("------------------TESTING scoreFor():--------------------\n\n");
    printf ("Test score for hand.\n");
    for (p = 0; p < numPlayers; p++){
        G.handCount[p] = 1;
        G.deckCount[p] = 0;
        G.discardCount[p] = 0;

        //test for curse
        G.hand[p][0] = curse;
        result = scoreFor(p, &G);
        if(result == score-1){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score-1, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score-1, result);
        }

        //test for estate
        score = 0;
        G.hand[p][0] = estate;
        result = scoreFor(p, &G);
        if(result == score+1){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score+1, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score+1, result);
        }

        //test for duchy
        score = 0;
        G.hand[p][0] = duchy;
        result = scoreFor(p, &G);
        if(result == score+3){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score+3, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score+3, result);
        }

        //test for province
        score = 0;
        G.hand[p][0] = province;
        result = scoreFor(p, &G);
        if(result == score+6){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score+6, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score+6, result);
        }

        //test for great_hall
        score = 0;
        G.hand[p][0] = great_hall;
        result = scoreFor(p, &G);
        if(result == score+1){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score+1, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score+1, result);
        }

        //test for gardens
        score = 0;
        G.hand[p][0] = gardens;
        result = scoreFor(p, &G);
        if(result == score){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score, result);
        }
    }

    printf ("Test score for discard.\n");
    score = 0;
    for (p = 0; p < numPlayers; p++){
        G.handCount[p] = 0;
        G.deckCount[p] = 0;
        G.discardCount[p] = 1;

        //test for curse
        G.discard[p][0] = curse;
        result = scoreFor(p, &G);
        if(result == score-1){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score-1, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score-1, result);
        }

        //test for estate
        score = 0;
        G.discard[p][0] = estate;
        result = scoreFor(p, &G);
        if(result == score+1){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score+1, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score+1, result);
        }

        //test for duchy
        score = 0;
        G.discard[p][0] = duchy;
        result = scoreFor(p, &G);
        if(result == score+3){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score+3, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score+3, result);
        }

        //test for province
        score = 0;
        G.discard[p][0] = province;
        result = scoreFor(p, &G);
        if(result == score+6){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score+6, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score+6, result);
        }

        //test for great_hall
        score = 0;
        G.discard[p][0] = great_hall;
        result = scoreFor(p, &G);
        if(result == score+1){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score+1, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score+1, result);
        }

        //test for gardens
        score = 0;
        G.discard[p][0] = gardens;
        result = scoreFor(p, &G);
        if(result == score){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score, result);
        }
    }

    printf ("Test score for deck.\n");
    score = 0;
    for (p = 0; p < numPlayers; p++){
        G.handCount[p] = 0;
        G.deckCount[p] = 1;
        G.discardCount[p] = 0;

        //test for curse
        G.deck[p][0] = curse;
        result = scoreFor(p, &G);
        if(result == score-1){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score-1, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score-1, result);
        }

        //test for estate
        score = 0;
        G.deck[p][0] = estate;
        result = scoreFor(p, &G);
        if(result == score+1){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score+1, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score+1, result);
        }

        //test for duchy
        score = 0;
        G.deck[p][0] = duchy;
        result = scoreFor(p, &G);
        if(result == score+3){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score+3, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score+3, result);
        }

        //test for province
        score = 0;
        G.deck[p][0] = province;
        result = scoreFor(p, &G);
        if(result == score+6){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score+6, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score+6, result);
        }

        //test for great_hall
        score = 0;
        G.deck[p][0] = great_hall;
        result = scoreFor(p, &G);
        if(result == score+1){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score+1, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score+1, result);
        }

        //test for gardens
        score = 0;
        G.deck[p][0] = gardens;
        result = scoreFor(p, &G);
        if(result == score){
            printf ("PASS. EXPECTED: %d. ACTUAL: %d.\n", score, result);
        }
        else{
            printf ("FAIL. EXPECTED: %d. ACTUAL: %d.\n", score, result);
        }
    }

    printf("---------------------------------------------------------\n");

    return 0;
}
