//Ashley Castiglione
//Assignment3
//unittest3.c
//unit test testing numHandCards() function

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assert.h"

int main(int argc, const char * argv[]) {

    printf("starting unittest3.c\n");
    

    //struct for the state of the game
    struct gameState G;

    //k[10] for 10 cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

    initializeGame(2, k, 2, &G);

    int i = numHandCards(&G);

    //check for initial 5 card hand
    if (i == 5)
    {
    	printf("5 cards in hand passed\n");
    }
    else
    {
    	printf("5 cards in hand failed\n");
    }

    //next turn
    drawCard(whoseTurn(&G), &G);
    i = numHandCards(&G);

    if (i == 6)
    {
    	printf("6 cards in hand passed\n");
    }
    else
    {
    	printf("6 cards in hand failed\n");
    }

    //next turn
     drawCard(whoseTurn(&G), &G);
    i = numHandCards(&G);

    if (i == 7)
    {
    	printf("7 cards in hand passed\n");
    }
    else
    {
    	printf("7 cards in hand failed\n");
    }

    return 0;
}