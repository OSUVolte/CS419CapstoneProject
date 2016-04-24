#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    
    /* initializeGame() */
    
    struct gameState game;
    int i;
    int checkInitializer;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    
    checkInitializer = initializeGame(2, k, 2, &game);
    
    printf("Testing initializeGame() \n");
    

    if (game.numPlayers == 2){
        printf("initializeGame(): PASS - The number of players was initialized correctly \n");
    }
    else{
        printf("initializeGame(): FAIL - The number of players was not initialized correctly \n");
    }
    
    
    if(checkInitializer != -1){
        printf("initializeGame(): PASS - Kingdom cards were initialized correctly \n");
    }
    else{
        printf("initializeGame(): FAIL - Kingdom cards were not initialized correctly \n");
    }
    
    if(game.supplyCount[curse] == 10){
        printf("initializeGame(): PASS - The number of curse cards was initialized correctly \n");
    }
    else{
        printf("initializeGame(): FAIL - The number of curse cards was not initialized correctly \n");
    }
    
    if(game.supplyCount[estate] == 8 && game.supplyCount[duchy] == 8 && game.supplyCount[province] == 8){
        printf("initializeGame(): PASS - The number of victory cards was initialized correctly \n");
    }
    else{
        printf("initializeGame(): FAIL - The number of victory cards was not initialized correctly \n");
    }
    
    if(game.supplyCount[copper] == 46 && game.supplyCount[silver] == 40 && game.supplyCount[gold] == 30){
        printf("initializeGame(): PASS - The number of treasure cards was initialized correctly \n");
    }
    else{
        printf("initializeGame(): FAIL - The number of treasure cards was not initialized correctly \n");
    }
    
    if(game.embargoTokens[0] == 0){
        printf("initializeGame(): PASS - Embargo tokens initialized correctly \n");
    }
    else{
        printf("initializeGame(): FAIL - Embargo tokens not initialized correctly \n");
    }

    return 0;
    
    
}