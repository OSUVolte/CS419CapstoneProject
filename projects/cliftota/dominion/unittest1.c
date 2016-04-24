#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){
    int testresult;
    int k[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, baron, sea_hag, great_hall};
    struct gameState G;
    memset(&G, 0, sizeof(struct gameState));   // clear the game state
    initializeGame(2, k, 10, &G); //initialize game

    printf ("-----------------TESTING isGameOver():-----------------\n\n");

    //test newly started game
    testresult = isGameOver(&G);
    printf ("Test when game just started.\n");
    if (testresult == 0){
        printf ("PASS. EXPECTED: Game is not over. ACTUAL: Game is not over.\n\n");
    }
    else{
        printf ("FAIL. EXPECTED: Game is not over. ACTUAL: Game is over.\n\n");
    }

    //test when no province cards left
    G.supplyCount[province] = 0; //set province cards to empty
    printf ("Test with no Province cards.\n");
    testresult = isGameOver(&G);
    if (testresult == 1){
        printf ("PASS. EXPECTED: Game is over. ACTUAL: Game is over.\n\n");
    }
    else{
        printf ("FAIL. EXPECTED: Game is over. ACTUAL: Game is not over.\n\n");
    }
    G.supplyCount[province] = 1; //recover the game returning one province card

    //test with one empty pile
    int i, j, m;
    printf ("Test with one pile empty.\n");
    for (i = 0; i < 10; i++){
        G.supplyCount[k[i]] = 0;
        testresult = isGameOver(&G);
        if (testresult != 0){
            printf ("FAIL. EXPECTED: Game is not over. ACTUAL: Game is over.\n");
        }
        else{
            printf ("PASS. EXPECTED: Game is not over. ACTUAL: Game is not over.\n");
        }
        G.supplyCount[k[i]] = 1;
    }

    //test with two empty piles
    printf ("\nTest with two piles empty.\n");
    G.supplyCount[k[0]] = 0;
    for(j = 1; j < 10; j++){
        G.supplyCount[k[j]] = 0;
        testresult = isGameOver(&G);
        if (testresult != 0){
            printf ("FAIL. EXPECTED: Game is not over. ACTUAL: Game is over.\n");
        }
        else{
            printf ("PASS. EXPECTED: Game is not over. ACTUAL: Game is not over.\n");
        }
        G.supplyCount[k[j]] = 1;
    }


    //test with three empty piles
    printf ("\nTest with three piles empty.\n");
    G.supplyCount[k[0]] = 0;
    G.supplyCount[k[1]] = 0;
    for(m = 2; m < 10; m++){
        G.supplyCount[k[m]] = 0;
        testresult = isGameOver(&G);
        if (testresult != 1){
            printf ("FAIL. EXPECTED: Game is over. ACTUAL: Game is not over.\n");
        }
        else{ printf ("PASS. EXPECTED: Game is over. ACTUAL: Game is over.\n");}
        G.supplyCount[k[m]] = 1;
    }

    printf("---------------------------------------------------------\n");

    return 0;
}
