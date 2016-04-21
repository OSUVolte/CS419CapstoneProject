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
    int startGame;
    int k[10] = {adventurer, embargo, great_hall, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    struct gameState g;
    
    printf("Whos turn test\n");
    for(counter = 2; counter<= 4; counter++)
    {
//create game and assert it is running, then check to find out whos turn it is
        startGame = initializeGame(counter, k, 2, &g);
        assert(startGame == 0);
        startGame = whoseTurn(&g);
        assert(startGame == g.whoseTurn);
        printf("whose turn - player number: %d \n", counter);
    }
    printf("Unit test 2 passed. \n");
return 0;
}
