//Ashley Castiglione
//Assignment3
//cardtest4.c
//unit test testing council_room

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assert.h"

int main(int argc, const char * argv[]) {

    printf("starting cardtest4.c\n");
    
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
    printf("Starting card test 4...\n");

    //temp variable for numhandcards()
    int nhcards = numHandCards(&G);
    int buy = G.numBuys;

    //cardeffect from smithy modified here
    cardEffect(council_room, choice1, choice2, choice3, &G, 0, NULL);

    //check number of buys available
    if(buy == 2){
        printf("council_room card test buys passed.\n");
    }
    else {
        printf("council_room card test buys failed.\n");
    }
   
    //check to make sure correct number of cards
   
    if (numHandCards(&G)== nhcards + 3)
    {
       printf("council_room card test passed.\n");
    }
    else
    {
        printf("council_room number of cards test failed.\n");
    }

    return 0;
}