#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



/* Test of the isGameOver() function */
int main(){
    
    struct gameState game;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    
    initializeGame(2, k, 2, &game);
    
    printf("\n Testing isGameOver() \n");
    
    game.supplyCount[province] = 0;
    
    if(isGameOver(&game) == 1){
        printf("isGameOver(): PASS when province count is 0 \n");
    }
    
    else{
        printf("isGameOver(): FAIL when province count is 0 \n");
    }
    
    game.supplyCount[province] = 10;
    
    if(isGameOver(&game) == 1){
        printf("isGameOver(): PASS when province count is 10 \n");
    }
    
    else{
        printf("isGameOver(): FAIL when province count is 10 \n");
    }
    
    return 0;
    
}


/*int main(){
    testIsGameOver();
    return 0;
}*/
