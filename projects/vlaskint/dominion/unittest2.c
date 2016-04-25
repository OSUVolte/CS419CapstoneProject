#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "dominion.h"
//makefile was taken from https://github.com/aburasali/cs362sp16/blob/master/projects/batese/dominion/Makefile
/*

int numHandCards(struct gameState *state) {
  return state->handCount[ whoseTurn(state) ];
}

*/
void testNumHandCards() {
    printf("\n\nNumHandCards() Function test\n");
    //srand(time(NULL));
    //int r = rand();
    struct gameState* g = malloc(sizeof(struct gameState));
    int k[10] = {smithy, adventurer, feast, council_room, embargo, village, minion, mine, cutpurse, sea_hag, tribute};
    initializeGame(2, k, 100, g);
    //assign some value to the handCount for each player
    int player1 = 5;
    //at the begining of the game- its the fist players turn
    g->handCount[0] = player1;
    assert(numHandCards(g) == player1);
    printf("numHandCards(g) for the first player should yield 5 if works correctly: %d \n", g->handCount[0] );
    //now we need to reassign the turn
    g->whoseTurn = 1;
    int player2 = 8;
    g->handCount[1] = player2;
    //check to make sure that the handCount works for the second player as well.
    assert(numHandCards(g) == player2);
    printf("numHandCards(g) for the second player should yield 8 if works correctly: %d \n", g->handCount[1] );
}

int main () {
    testNumHandCards();
    exit(0);
}

