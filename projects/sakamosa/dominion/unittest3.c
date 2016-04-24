#include "dominion.h" 
#include "dominion_helpers.h"  
#include <stdio.h> 
#include <stdlib.h>

//testing of buyCard function

int main(){
    printf("*********************BEGIN UNIT TESTS OF BUYCARD()*********************\n\n");
    
    struct gameState T;
    T.whoseTurn = 0;
    T.supplyCount[adventurer] = 3;
    T.supplyCount[sea_hag] = 0;
    
    T.numBuys = 0;
    //test against 0 buys
    if(buyCard(adventurer, &T) != -1 ){
        printf("FAIL allowed purchase with no buys\n");
    }
    else{
         if(T.numBuys != 0){
        printf("FAIL altered number of buys with no purchase(0 buys)\n");
        }
        if(T.supplyCount[adventurer] != 3){
            printf("FAIL altered number of supply with no purchase(0 buys)\n");
        }
    }
    
    T.numBuys = 2;//reset
    //test against no cards
    if(buyCard(sea_hag, &T) != -1 ){
        printf("FAIL allowed purchase with no supply\n");
    }
    else{
        if(T.numBuys != 2){
        printf("FAIL altered number of buys with no purchase(0 supply)\n");
        }
        if(T.supplyCount[sea_hag] != 0){
            printf("FAIL altered number of supply with no purchase(0 supply)\n");
        }
    }
    

    T.numBuys = 1;
    T.supplyCount[adventurer] = 3;
    if(buyCard(adventurer, &T) != -1){
        if(T.numBuys != 0){
            printf("FAIL did not decrement buys\n");
        }
        if(T.supplyCount[adventurer] != 2){
            printf("FAIL did not decrement supplyCount\n");
        }
    }
    printf("**********************TESTS COMPLETE*************************\n\n")
    
    return 0;
}
    
    
