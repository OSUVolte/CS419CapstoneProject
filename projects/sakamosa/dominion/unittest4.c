#include "dominion.h" 
#include "dominion_helpers.h"  
#include <stdio.h> 
#include <stdlib.h>

//testing of fullDeckCount function

int main(){
    printf("*********************BEGIN UNIT TESTS OF FULLDECKCOUNT()*********************\n\n");
    int i;
    struct gameState T;
    T.deckCount[0] = 3;
    T.discardCount[0] = 2;
    T.deckCount[1] = 0;
    T.discardCount[1] = 2;
    
    T.deck[0][0] = gardens;
    T.deck[0][1] = gardens;
    T.deck[0][2] = gardens;
    
    T.discard[0][0] = adventurer;
    T.discard[0][1] = gardens;
    
    T.discard[1][0] = sea_hag;
    T.discard[1][1] = gardens;
    
    //Test basic count
    if(fullDeckCount(0, gardens, &T) != 4){
        printf("FAIL incorrect count\n");
    }
    
    //Test that there are no unexpected changes to state
    if (T.deckCount[0] != 3 || T.discardCount[0] != 2){
            printf("FAIL change to deckCount\n");
    }
    for(i = 0; i < T.deckCount[0]; i++){
        if(T.deck[0][i] != gardens){
            printf("FAIL altered state of deck\n");    
        }
    }
    
    //Test basic count when deck is empty
    if(fullDeckCount(1, gardens, &T) != 1){
        printf("FAIL incorrect count when deck empty\n");
    }
    
    //Test that there are no unexpected changes to state
    if (T.deckCount[0] != 0 || T.discardCount[0] != 2){
            printf("FAIL change to deckCount when deck empty\n");
    }
    
    printf("**********************TESTS COMPLETE*************************\n\n");
    return 0;
}
    
    
