//Ashley Castiglione
//Assignment3
//cardtest2.c
//unit test testing adventurer

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assert.h"

int main(int argc, const char * argv[]) {

    printf("starting cardtest2.c\n");
    
	//struct for the state of the game
    struct gameState G;

     //temp variable for numhandcards()
    int nhcards = numHandCards(&G);

    //k[10] for 10 cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

    //initialize game
    initializeGame(2, k, 4, &G);

    //print statement for starting card test
    printf("Starting card test 2...\n");

   

    if (numHandCards(&G) == nhcards + 2)
    {
         printf("adventurer card test passed.\n");
    }
    else
    {
    //print fail statement
    printf("adventurer card test failed\n");
    }
    
    return 0;
}