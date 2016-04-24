#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
    
    struct gameState game;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    
    initializeGame(2, k, 2, &game);
    int curPlayer = 0;
    int prevPlayer = 0;
    
    printf("\n Testing endTurn() \n");
    
    if (whoseTurn(&game) != curPlayer) {
        
        printf("whoseTurn() FAIL - turn was not assigned properly \n");
        return 0;
    }
    
    endTurn(&game);
    curPlayer = 1;
    
    
    if (whoseTurn(&game) != curPlayer) {
        
        printf("endTurn(): FAIL - it did not end the turn properly \n");
        return 0;
    }
    
    printf("endTurn(): PASS - the turn was ended correctly \n");

    return 0;
    
    
    
}