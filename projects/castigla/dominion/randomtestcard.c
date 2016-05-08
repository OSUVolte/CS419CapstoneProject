//Ashley Castiglione
//Assignment 4
//randomtestcard.c
//this tests the smithy card
//max tests 50


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

//define MAX_TESTS
#define MAX_TESTS 5000;

int main(int argc, char const *argv[])
{
    //Randomly testing smithy card

    //random call
    srand(time(NULL));
	
	printf("starting randomtestcard.c\n");

    //struct for the state of the game
    struct gameState state;

    int numberOfPlayers, currentPlayer, randomNumber;
    int testFails = 0;
    int testPasses = 0;


    //k[10] for 10 cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

    //loop through random tests
    for (int i = 0; i < 5000; i++)
    {
    	//randomly pick number of players with max_players
    	numberOfPlayers = (rand() % MAX_PLAYERS) + 1;
    	//printf("number Of players: %i\n", numberOfPlayers);
        currentPlayer = (rand() % numberOfPlayers);

        randomNumber = rand();

    	//initialize game
        initializeGame(numberOfPlayers, k, randomNumber, &state);

        //assign player one action
        state.numActions = 1;

        //set whose turn to current player
        state.whoseTurn = currentPlayer;

        //have 5 cards in hand **need [currentplayer] here! don't forget!
        state.handCount[currentPlayer]= 5;

        if (randomNumber % 3 == 0)
        {
            state.deckCount[currentPlayer] = 0;
        }

        int success = cardEffect(smithy, 1, 1, 1, &state, 0, 0);
        
        //check if cardEffect passed. 
        if (success == 0)
         {
             //printf("successfully ran cardEffect\n");
             testPasses++;
         } 
         else 
         {
            //printf("cardEffect failed\n");
            testFails++;
         }

        //check to see if the hand count has correctly updated. It should not pass due to bugs added earlier in term.
    	if (state.handCount[currentPlayer] != state.handCount[currentPlayer] + 2)
        {
 
            //printf("Test failed. Hand count incorrect%i\n", state.handCount[currentPlayer]);
                testFails++;          
        }
        else
        {
            //printf("Test Passed. Hand count correct %i\n", state.handCount[currentPlayer]);
            testPasses++;
        }
    }
    printf("\nTest loops 5000 times testing number of cards in hand and if cardEffect was successful. \n");
    printf("10000 tests. 5000 cardEffect, 5000 handCount \n");
    printf("Total Passed tests: %i\n", testPasses);
    printf("Total Failed tests: %i\n", testFails);

	return 0;
}