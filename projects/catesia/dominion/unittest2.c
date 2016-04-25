#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int testGameOver(struct gameState *state, int testCheck) {
    struct gameState testState;
    memcpy (&testState, state, sizeof(struct gameState));
    
    
    int checkOver;
    checkOver = isGameOver(state);
    
    if (testCheck) {
        assert(checkOver == 1);
        return 0;
    }
    
    if (testState.supplyCount[province] == 0) {
        assert(checkOver == 1);
        return 0;
    }
    
    assert(checkOver == 0);
    return 0;
}

int main() {
    printf("\n Now testing gameOver function\n");
    int totalPlayers = 2;
    int currentPlayer, currentDeckCount, currentDiscardCount, currentHandCount;
    
    struct gameState testState;
    
    int cards[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};
   
    
    for (currentPlayer = 0; currentPlayer < totalPlayers; currentPlayer++) {
        for (currentDeckCount = 0; currentDeckCount < 10; currentDeckCount++) {
            for (currentDiscardCount = 0; currentDiscardCount < 10 ; currentDiscardCount++) {
                for (currentHandCount = 1; currentHandCount < 5; currentHandCount++) {
                    
                    memset(&testState, 23, sizeof(struct gameState));
                    int seed = 1111;
                    initializeGame(totalPlayers, cards, seed, &testState);
                    
                    testState.deckCount[currentPlayer] = currentDeckCount;
                    testState.discardCount[currentPlayer] = currentDiscardCount;
                    testState.handCount[currentPlayer] = currentHandCount;
                    
                    //Test cases
                    testState.supplyCount[copper] = 0;
                    testState.supplyCount[silver] = 0;
                    testState.supplyCount[gold] = 0;
                    testState.supplyCount[province] = 9;
                    testGameOver(&testState, 1);
                    
                    
                    testState.supplyCount[copper] = 3;
                    testState.supplyCount[silver] = 0;
                    testState.supplyCount[gold] = 0;
                    testGameOver(&testState, 0);
                    
                    testState.supplyCount[copper] = 3;
                    testState.supplyCount[silver] = 2;
                    testState.supplyCount[gold] = 0;
                    testGameOver(&testState, 0);
                    
                    testState.supplyCount[province] = 0;
                    testGameOver(&testState, 0);
                    
                    
                }
                
                
            }
        }
    }
    printf("isGameOver() passed all tests\n");
}