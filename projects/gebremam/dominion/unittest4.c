/* -----------------------------------------------------------------------
 * Martha Gebremariam
 * CS362_SP2016
 * Assignment 3
 * Description: Unit test for fullDeckCount() function in dominion.c
 * card values were manually hardcoded.
 *
 * The following lines were also included makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 * gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>
//testing fullDeckCount(int player, int card, struct gameState *state)

int main() {

printf("\n\n*************************\n");
printf ("TESTING fullDeckCount()\n");
printf("*************************\n\n");    
int numPlayer = 2;
int seed = 1000;
int passedTest=0;
int failedTest=0;
struct gameState G;
int k[10] = {adventurer, council_room, feast, mine, remodel, smithy, village, salvager, sea_hag, treasure_map};

memset(&G, 0, sizeof(struct gameState));   // clear the game state
initializeGame(numPlayer, k, seed, &G); // initialize a new game
int i;
for (i=0; i<2; i++){
    G.deckCount[i] = 25;
    G.discardCount[i]=25;
    G.handCount[i]=5;
}
    int testDeck1[25]={curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, mine, remodel, smithy, village, salvager, sea_hag, treasure_map, copper, silver, gold, copper, silver, estate, feast, copper};
    memcpy(G.deck[0], testDeck1, sizeof(int)*25);

    int testDiscard1[25]= {feast, mine, remodel, smithy, village, salvager, sea_hag, treasure_map, copper, silver, gold, copper, silver, estate, feast, copper, curse, estate, duchy, province, copper, silver, gold, adventurer, council_room};
    memcpy(G.discard[0], testDiscard1, sizeof(int)*25);

    int testHand1[5]= {copper, silver, estate, feast, copper};
    memcpy(G.hand[0], testHand1, sizeof(int)*5);



    int testDeck2[25] = {province, copper, silver, gold, estate, smithy, village, remodel, copper, curse, treasure_map, smithy, silver, gold, estate, gold, estate, copper, copper, silver, estate, smithy, remodel, copper, gold};
    memcpy(G.deck[1], testDeck2, sizeof(int)*25);



    int testDiscard2[25] = {estate, gold, estate, copper, copper, silver, estate, smithy, remodel, copper, gold, adventurer, mine, treasure_map, copper, gold, duchy, remodel, silver, copper, estate, council_room, salvager, feast, mine};
    memcpy(G.discard[1], testDiscard2, sizeof(int)*25);

    int testHand2[5] = {copper, council_room, gold, gold, adventurer};
    memcpy(G.hand[1], testHand2, sizeof(int)*5);

   

    
    printf("testing for curse card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 0, &G), 2);
    if (fullDeckCount(0, 0, &G)== 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 0, &G)== 2);
    
    printf("testing for estate card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 1, &G), 5);
    if (fullDeckCount(0, 1, &G) == 5){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 1, &G) == 5);

    printf("testing for duchy card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 2, &G), 2);
    if (fullDeckCount(0, 2, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 2, &G) == 2);
    
    printf("testing for province card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 3, &G), 2);
    if (fullDeckCount(0, 3, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 3, &G) == 2);
    
    printf("testing for copper card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 4, &G), 10);
    if (fullDeckCount(0, 4, &G) == 10){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 4, &G) == 10);
    
    printf("testing for silver card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 5, &G), 7);
    if (fullDeckCount(0, 5, &G)== 7){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 5, &G)== 7);
    
    printf("testing for gold card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 6, &G), 4);
    if (fullDeckCount(0, 6, &G) == 4){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 6, &G) == 4);
    
    printf("testing for adventurer card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 7, &G), 2);
    if (fullDeckCount(0, 7, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 7, &G) == 2);

    printf("testing for council_room card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 8, &G), 2);
    if (fullDeckCount(0, 8, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 8, &G) == 2);
    
    printf("testing for feast in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 9, &G), 5);
    if (fullDeckCount(0, 9, &G) == 5){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 9, &G) == 5);
    
    printf("testing for gardens card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 10, &G), 0);
    if (fullDeckCount(0, 10, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 10, &G) == 0);
    
    printf("testing for mine card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 11, &G), 2);
    if (fullDeckCount(0, 11, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 11, &G) == 2);
 
        
    printf("testing for remodel card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 12, &G), 2);
    if (fullDeckCount(0, 12, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 12, &G) == 2);
    
    printf("testing for smithy card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 13, &G), 2);
    if (fullDeckCount(0, 13, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 13, &G) == 2);

    printf("testing for village card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 14, &G), 2);
    if (fullDeckCount(0, 14, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 14, &G) == 2);
    
    printf("testing for baron card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 15, &G), 0);
    if (fullDeckCount(0, 15, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 15, &G) == 0);
    
    printf("testing for greathall card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 16, &G), 0);
    if (fullDeckCount(0, 16, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 16, &G) == 0);
    
    printf("testing for minion card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 17, &G), 0);
    if (fullDeckCount(0, 17, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 17, &G) == 0);
    
    printf("testing for steward card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 18, &G), 0);
    if (fullDeckCount(0, 18, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 18, &G) == 0);
    
    printf("testing for tribute card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 19, &G), 0);
    if (fullDeckCount(0, 19, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 19, &G) == 0);

    printf("testing for ambassador card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 20, &G), 0);
    if (fullDeckCount(0, 20, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 20, &G) == 0);
    
    printf("testing for cutpurse in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 21, &G), 0);
    if (fullDeckCount(0, 21, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 21, &G) == 0);
    
    printf("testing for embargeo card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 22, &G), 0);
    if (fullDeckCount(0, 22, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 22, &G) == 0);
    
    printf("testing for outpost card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 23, &G), 0);
    if (fullDeckCount(0, 23, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 23, &G) == 0);
    
    printf("testing for salvager in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 24, &G), 2);
    if (fullDeckCount(0, 24, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 24, &G) == 2);
    
    printf("testing for sea_hag card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 25, &G), 2);
    if (fullDeckCount(0, 25, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 25, &G) == 2);
    
    printf("testing for treasure_map card in fullDeckCount of player1\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(0, 26, &G), 2);
    if (fullDeckCount(0, 26, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(0, 26, &G) == 2);
    
    
    
    printf("testing for curse card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 0, &G), 1);
    if (fullDeckCount(1, 0, &G)== 1){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 0, &G)== 1);
    
    printf("testing for estate card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 1, &G), 8);
    if (fullDeckCount(1, 1, &G) == 8){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 1, &G) == 8);

    printf("testing for duchy card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 2, &G), 1);
    if (fullDeckCount(1, 2, &G) == 1){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 2, &G) == 1);
    
    printf("testing for province card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 3, &G), 1);
    if (fullDeckCount(1, 3, &G) == 1){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 3, &G) == 1);
    
    printf("testing for copper card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 4, &G), 11);
    if (fullDeckCount(1, 4, &G) == 11){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 4, &G) == 11);
    
    printf("testing for silver card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 5, &G), 5);
    if (fullDeckCount(1, 5, &G) == 5){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 5, &G) == 5);
    
    printf("testing for gold card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 6, &G), 9);
    if (fullDeckCount(1, 6, &G) == 9){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 6, &G) == 9);
    
    printf("testing for adventurer card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 7, &G), 2);
    if (fullDeckCount(1, 7, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 7, &G) == 2);

    printf("testing for council_room card in fullDeckCount of player2\n"); 
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 8, &G), 2);
    if (fullDeckCount(1, 8, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 8, &G) == 2); 

    printf("testing for feast in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 9, &G), 1);
    if (fullDeckCount(1, 9, &G) == 1){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 9, &G) == 1);
    
    printf("testing for gardens card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 10, &G), 0);
    if (fullDeckCount(1, 10, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 10, &G) == 0);
    
    printf("testing for mine card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 11, &G), 2);
    if (fullDeckCount(1, 11, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 11, &G) == 2);
 
        
    printf("testing for remodel card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 12, &G), 4);
    if (fullDeckCount(1, 12, &G) == 4){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 12, &G) == 4);
    
    printf("testing for smithy card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 13, &G), 4);
    if (fullDeckCount(1, 13, &G) == 4){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 13, &G) == 4);

    printf("testing for village card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 14, &G), 1);
    if (fullDeckCount(1, 14, &G) == 1){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 14, &G) == 1);
    
    printf("testing for baron card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 15, &G), 0);
    if (fullDeckCount(1, 15, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 15, &G) == 0);
    
    printf("testing for greathall card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 16, &G), 0);
    if (fullDeckCount(1, 16, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 16, &G) == 0);
    
    printf("testing for minion card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 17, &G), 0);
    if (fullDeckCount(1, 17, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 17, &G) == 0);
    
    printf("testing for steward card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 18, &G), 0);
    if (fullDeckCount(1, 18, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 18, &G) == 0);
    
    printf("testing for tribute card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 19, &G), 0);
    if (fullDeckCount(1, 19, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 19, &G) == 0);

    printf("testing for ambassador card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 20, &G), 0);
    if (fullDeckCount(1, 20, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 20, &G) == 0);
    
    printf("testing for cutpurse in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 21, &G), 0);
    if (fullDeckCount(1, 21, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 21, &G) == 0);
    
    printf("testing for embargeo card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 22, &G), 0);
    if (fullDeckCount(1, 22, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 22, &G) == 0);
    
    printf("testing for outpost card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 23, &G), 0);
    if (fullDeckCount(1, 22, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    assert(fullDeckCount(1, 22, &G) == 0);
    
    printf("testing for salvager in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 24, &G), 1);
    if (fullDeckCount(1, 24, &G) == 1){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 24, &G) == 1);
    
    printf("testing for sea_hag card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 25, &G), 0);
    if (fullDeckCount(1, 25, &G) == 0){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 25, &G) == 0);
    
    printf("testing for treasure_map card in fullDeckCount of player2\n");
    printf("returned = %d, expected = %d\n\n", fullDeckCount(1, 26, &G), 2);
    if (fullDeckCount(1, 26, &G) == 2){
        printf("Passed test\n\n");
        passedTest++;
    }
    else{
        printf("failed test\n\n");
        failedTest++;
    }
    //assert(fullDeckCount(1, 26, &G) == 2);


    printf("Passed %d and failed %d of the unittest4 tests\n", passedTest, failedTest);
    return 0;
}
