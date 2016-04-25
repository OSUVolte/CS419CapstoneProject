#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
    
    
    struct gameState state;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    
    initializeGame(2, k, 2, &state);
    
    int currentPlayer = whoseTurn(&state);
    int coinBonus = 0;
    int i;
    
    updateCoins(currentPlayer, &state, coinBonus);
    
    printf(" Test for updateCoins() \n");
    
    for (i = 0; i < state.handCount[currentPlayer]; i++){
        
        if((state.hand[currentPlayer][i] == copper || state.hand[currentPlayer][i] == silver || state.hand[currentPlayer][i] == gold) && state.coins == 0){
            
            printf("updateCoins: FAIL - The function kept the coins number at 0 even though the player had coins \n");
        }
        
        else{
            printf("updateCoins: PASS - The function did not keep the coin count at 0 when the player had coins \n");
        }
        
        
    }
    
    
    return 0;
    
    
    
}