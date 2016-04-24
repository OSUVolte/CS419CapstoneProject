#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>



//Function will check to make sure that the coins are valued correctly
void testCoin(struct gameState *game, int bonus, int coinMult, int currentPlayer, int currentHandCount) {
    
    struct gameState testState;
    memcpy (&testState, game, sizeof(struct gameState));
    updateCoins(currentPlayer, &testState, bonus);
    assert(testState.coins == currentHandCount*coinMult + bonus);

    
}

int main() {
    
    printf("\n Now testing updateCoin function\n");
    int totalPlayers = 2;
    int maxHand = 5;
    int maxBonus = 10;
    int currentPlayer, currentHandCount, currentBonus;
    int cards[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};
    
    struct gameState testState;
    
    
    for (currentPlayer = 0; currentPlayer < totalPlayers; currentPlayer++) {
        for (currentHandCount = 1; currentHandCount <= maxHand; currentHandCount++) {
            for (currentBonus = 0; currentBonus <= maxBonus; currentBonus++) {
                
                memset(&testState, 23, sizeof(struct gameState));
                int seed = 1111;
                initializeGame(totalPlayers, cards, seed, &testState);
                
                testState.handCount[currentPlayer] = currentHandCount;
                
                int copperArr[MAX_HAND];
                int i;
                for (i = 0; i < MAX_HAND; i++) {
                    copperArr[i] = copper;
                }
                memcpy(testState.hand[currentPlayer], copperArr, sizeof(int)*currentHandCount);
            
                testCoin(&testState, currentBonus, 1, currentPlayer, currentHandCount);
                
                int silverArr[MAX_HAND];
                for (i = 0; i < MAX_HAND; i++) {
                    silverArr[i] = silver;
                }
                memcpy(testState.hand[currentPlayer], silverArr, sizeof(int)*currentHandCount);
                testCoin(&testState, currentBonus, 2, currentPlayer, currentHandCount);
                
                int goldArr[MAX_HAND];
                for (i = 0; i < MAX_HAND; i++) {
                    goldArr[i] = gold;
                }
                memcpy(testState.hand[currentPlayer], goldArr, sizeof(int)*currentHandCount);
                testCoin(&testState, currentBonus, 3, currentPlayer, currentHandCount);
            }
        }
    }
    printf ("Update coin passed all tests.\n");
    
}