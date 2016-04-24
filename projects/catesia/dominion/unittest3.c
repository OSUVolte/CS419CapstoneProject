#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>



int testBuy(struct gameState *state, int currentPlayer) {
    struct gameState testState;
    memcpy(&testState, state, sizeof(struct gameState));
    
    int didBuy = buyCard(currentPlayer, state);
    int checkBuy = 0;
    
    if (testState.supplyCount[currentPlayer] < 1) {
        checkBuy = -1;
    }
    
    
    if (testState.coins < getCost(currentPlayer)) {
        checkBuy = -1;
    }
        
    if (testState.numBuys < 0) {
        checkBuy = -1;
    }
    assert(didBuy == checkBuy);
    return 0;
    
    
    if (checkBuy == 0) {
        testState.discardCount[testState.whoseTurn]++;
        testState.supplyCount[currentPlayer]--;
    }
    
    assert(testState.discardCount[testState.whoseTurn] == state->discardCount[state->whoseTurn]);
    assert(testState.supplyCount[currentPlayer] == state->supplyCount[currentPlayer]);


}

int main() {
    printf("\n Now testing buyCard function\n");
    
    int i, k, playerCount, currentPlayer;
    struct gameState testState;
    
    for (i = 0; i < 2000; i++)
    {
        for (k = 0; k < sizeof(struct gameState); k++)
        {
            ((char*)&testState)[k] = floor(Random() * 256);
        }
        
        
        for (playerCount = 0; playerCount < MAX_PLAYERS; playerCount++) {
            testState.discardCount[playerCount] = floor(Random() * MAX_DECK);
            testState.deckCount[playerCount] = floor(Random() * MAX_DECK);
            testState.handCount[playerCount] = floor(Random() * MAX_HAND);
        }
        
        currentPlayer = floor(Random() * 10);
        testState.whoseTurn = floor(Random() * MAX_PLAYERS);
        testBuy(&testState, currentPlayer);
    }
    printf("buyCard() passed all tests\n");
}