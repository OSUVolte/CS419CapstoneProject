#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main(int argc, char* argv[])
{
    int counter;
    int startOfGame;
    int k[10] = {adventurer, embargo, great_hall, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    struct gameState game;
    
    printf("\n\nWhos turn test\n");
    for(counter = 2; counter<= 4; counter++)
    {
//create game and assert it is running, then check to find out whos turn it is
        startOfGame = initializeGame(counter, k, 10, &game);
        assert(startOfGame == 0);
        startOfGame = whoseTurn(&game);
        assert(startOfGame == game.whoseTurn);
        printf("whose turn - player number: %d \n", counter);
    }
    printf("\nUnit test 2 passed. \n");
return 0;
}
