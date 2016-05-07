//Ashley Castiglione
//Assignment 4
//randomtestadventurer.c
//this tests the adventurer card
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
#define MAX_TESTS 10;

int main(int argc, char const *argv[])
{

srand(time(NULL));
    
    printf("starting randomtestadventurer.c\n");

    //struct for the state of the game
    struct gameState state;
    int numberOfPlayers, currentPlayer, randomNumber;
    int testFails = 0;
    int testPasses = 0;


    //k[10] for 10 cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

    //loop through random tests
    for (int i = 0; i < 5000; ++i)
    {  
        //randomly pick number of players with max_players
        numberOfPlayers = (rand() % 4) + 1;
        //numberOfPlayers = 2;
        //printf("number Of players: %i\n", numberOfPlayers);
        currentPlayer = (rand() % numberOfPlayers) + 1;

        randomNumber = rand();

        //initialize game
        initializeGame(numberOfPlayers, k, randomNumber, &state);

        //assign player one action
        state.numActions = 1;

        //set whose turn to current player
        state.whoseTurn = currentPlayer;

        //set discard pile to 0
        state.discardCount[currentPlayer] = 0;

        //set random deck number for checking correct discarding later in program
        state.deckCount[currentPlayer] = (rand() % MAX_DECK) + 1;

        //have 5 cards in hand **need [currentplayer] here! don't forget!
        state.handCount[currentPlayer]= 5;

        //test for deck count of 0
        if (randomNumber % 3 == 0)
        {
            state.deckCount[currentPlayer] = 0;
        }
        // int bonus = 0;
        // cardEffect(adventurer, 1, 1, 1, &state, 3, &bonus);
        //printf("DeckCount: %i\n", state.deckCount[currentPlayer]);

        //should fail due to introduced bugs into adventurer
        //want 6 cards in hand after playing one and picking up 2
        if (state.handCount[currentPlayer] != state.handCount[currentPlayer] + 1)
        {
           // printf("Test failed. Hand count incorrect\n");
                testFails++;
        }

        else
        {
            //printf("Test Passed. Hand count correct\n");
            testPasses++;
        }
        //should fail due to introduced bugs into adventurer
        if (state.discardCount[currentPlayer] != (state.handCount[currentPlayer] - state.deckCount[currentPlayer] - 2))
        {
            //printf("Test failed. Discard amount incorrect\n");
                testFails++;
        }

        else
        {
            //printf("Test passed. Discard amount correct\n");
                testPasses++;
        }
    }

    //print results
    printf("\nTest loops 5000 times testing number of cards in hand and number of discarded cards. \n");
    printf("10000 tests total.\n");
    printf("Total Passed tests: %i\n", testPasses);
    printf("Total Failed tests: %i\n", testFails);
	
	return 0;
}