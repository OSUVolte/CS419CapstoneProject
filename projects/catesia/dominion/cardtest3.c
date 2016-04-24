#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main () {
    printf("\n Now testing great_hall card\n");
    struct gameState testState;
    struct gameState testStatePost;
    
    int cards[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};
    int seed = 1111;
    int totalPlayers = 2;
    int currentPlayer = 0;
    int otherPlayer = 1;
    int bonus = 0;
    int totalErrors = 0;
    
    initializeGame(totalPlayers, cards, seed, &testState);
    memcpy(&testStatePost, &testState, sizeof(struct gameState));
    cardEffect(great_hall, 0, 0, 0, &testStatePost, 0, &bonus);
    
    //Tests
    if (testState.deckCount[currentPlayer] != testStatePost.deckCount[currentPlayer]+1) {
        printf("Error in deck count.\n");
        totalErrors++;
    }
    
    if (testState.discardCount[currentPlayer] != testStatePost.discardCount[currentPlayer]-1) {
        printf("Error in discard count.\n");
        totalErrors++;
    }
    
    if (testState.handCount[currentPlayer] != testStatePost.handCount[currentPlayer]) {
        printf("Error in hand count.\n");
        totalErrors++;
    }
    
    if (testState.numActions != testStatePost.numActions) {
        printf("Error in action count.\n");
        totalErrors++;
    }
    
    
    
    if (testState.deckCount[otherPlayer] != testStatePost.deckCount[otherPlayer]) {
        printf("Error in deck count for other player.\n");
        totalErrors++;
    }
    
    if (testState.discardCount[otherPlayer] != testStatePost.discardCount[otherPlayer]) {
        printf("Error in discard count for other player.\n");
        totalErrors++;
    }
    
    if (testState.handCount[otherPlayer] != testStatePost.handCount[otherPlayer]) {
        printf("Error in hand count for other player.\n");
        totalErrors++;
    }
    
    if (testState.numActions != testStatePost.numActions) {
        printf("Error in action count for other player.\n");
        totalErrors++;
    }
    
    printf("The total number of errors found is: %d\n", totalErrors);
    
}