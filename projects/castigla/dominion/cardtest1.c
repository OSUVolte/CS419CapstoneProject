//Ashley Castiglione
//Assignment3
//cardtest1.c
//unit test testing smithy

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assert.h"

int main(int argc, const char * argv[]) {

    printf("starting cardtest1.c\n");

    //struct for the state of the game
    struct gameState G;

    //3 var for the 3 choices
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;

    //k[10] for 10 cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

    //initialize game
    initializeGame(2, k, 2, &G);

    //print statement for starting card test
    printf("Starting card test 1...\n");

    //temp variable for numhandcards()
    int nhcards = numHandCards(&G);

    cardEffect(smithy, choice1, choice2, choice3, &G, 0, NULL);

    //check to see if 3 cards were drawn
    //assert(numHandCards(&G) == nhcards + 2);
    if (numHandCards(&G) == nhcards + 2)
    {
         printf("Smithy card test passed.\n");
    }
    else
    {
    //print fail statement
    printf("Smithy card test failed\n");
    }
    
    return 0;

}