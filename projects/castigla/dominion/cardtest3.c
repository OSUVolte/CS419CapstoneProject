//Ashley Castiglione
//Assignment3
//cardtest3.c
//unit test testing village

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assert.h"

int main(int argc, const char * argv[]) {

    printf("starting cardtest3.c\n");

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
    printf("Starting card test 3...\n");

    //variable for number of actions
    int actions = G.numActions;

    //cardeffect from smithy modified here
    int ceffect = cardEffect(village, choice1, choice2, choice3, &G, 0, NULL);
   
    //check to make sure correct number of actions
    if (G.numActions == actions + 2)
    {
        printf("Village card action test passed.\n");
    }
    else
    {
        printf("Village card action test failed.\n");
    }

    if (ceffect == 0)
    {
        printf("Village card test passed.\n");
    }
    else
    {
        printf("Village card test failed.\n");
    }

    return 0;
}