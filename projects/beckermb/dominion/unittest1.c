#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


//This is a test of the isGameOver method in dominion.c

int main () {
    printf("Testing isGameOver\n");

    struct gameState game;
    int i; //counter for initialization
      for (i = 0; i < 25; i++) {
      game->supplyCount[i] = 10;
    }
    //All piles full. Expect game to be not over.
    assert(isGameOver(game) == 0)

}
