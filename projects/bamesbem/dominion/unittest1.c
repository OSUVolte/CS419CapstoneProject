/* -----------------------------------------------------------------------
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    int bonus;
    int trashFlag = 0;
    int currentPlayer = 0;
    int handPos = 4;
    
    // Initialize Game
    r = initializeGame(numPlayer, k, seed, &G);
    // Copy game to testG
    memcpy(&testG, &G, sizeof(struct gameState));
    
    printf ("TESTING discardCard():\n\n\n");
    
    printf("Beginning hand:\n");
    for (p = 0; p < G.handCount[currentPlayer]; p++){
        printf("%d\t", G.hand[0][p]);
    }
    printf("\nBeginning playedCard count = %d\n", G.playedCardCount);
    printf("Beginning discardCard count = %d\n", G.discardCount[0]);
    printf("Card at handPos 4 = %d \n", G.hand[0][4]);
    
    discardCard(handPos, currentPlayer, &G, trashFlag);

    printf("--------- Test 1---------------\n");
    printf("Played Card Count: actual %d, expected %d\n", G.playedCardCount, testG.playedCardCount + 1  );
    if (G.playedCardCount == testG.playedCardCount + 1 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("--------- Test 2 ---------------\n");
    printf("HandCount: actual %d, expected %d\n", G.handCount[0], testG.handCount[0] - 1 );
    
    if (G.handCount[0] == testG.handCount[0] - 1){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    

    printf("--------- Test 3 ---------------\n");
    printf("Final hand composition:\n");
    printf("Actual:  ");
    for (p = 0; p < G.handCount[currentPlayer]; p++){
        printf("%d\t", G.hand[0][p]);
    }
    printf("\nExpected: ");
    int tempCard;
    tempCard = testG.hand[currentPlayer][handPos];
    testG.hand[currentPlayer][handPos] = -1;
    testG.handCount[currentPlayer]-- ;
    
    for (p = 0; p < G.handCount[currentPlayer]; p++){
        printf("%d\t", testG.hand[0][p]);
    }
    printf("\n\n--------- Test 4 ---------------\n");
    
    printf("Played Card Count (when trashflag is 0): \n");
    printf("actual: %d, expected %d\n", G.playedCardCount, testG.playedCardCount + 1 );
    if (G.playedCardCount == testG.playedCardCount + 1 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("\n--------- Test 5 ---------------\n");
    
    // Initialize Game
    r = initializeGame(numPlayer, k, seed, &G);
    // Copy game to testG
    memcpy(&testG, &G, sizeof(struct gameState));
    
    discardCard(handPos, currentPlayer, &G, 1);
    
    printf("Played Card Count (when trashflag is 1): \n");
    printf("actual: %d, expected %d\n", G.playedCardCount, testG.playedCardCount );
    if (G.playedCardCount == testG.playedCardCount ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }


    printf("------------- TESTING COMPLETE -----------\n\n");
    return 0;

}