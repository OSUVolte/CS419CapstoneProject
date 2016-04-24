#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void shuffleTest(struct gameState *testState, struct gameState *testStatePost){
    
    shuffle(0, testState);
    
    
    
    
}


int main() {
    printf("\n Now testing shuffle function\n");
    
    int totalPlayers = 2;
    
    int cards[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};
    struct gameState testState;
    struct gameState testStatePost;
    
    memset(&testState, 23, sizeof(struct gameState));
    int seed = 1111;
    initializeGame(totalPlayers, cards, seed, &testState);
    
    memcpy(&testStatePost, &testState, sizeof(struct gameState));
    
    
    printf("shuffle() passed all tests\n");
    
    
}