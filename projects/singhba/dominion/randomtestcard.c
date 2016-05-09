/*
 * randomtestcard.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestcard: randomtestcard.c dominion.o rngs.o
 *      gcc -o randomtestcard -g  randomtestcard.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "great_hall"

#define NUMTESTS 1000
#define MIN_PLAYERS 2

int CountTreasureCards(struct gameState G, int p)
{
    int i, tresureCards = 0;
     for (i = 0; i < G.handCount[p]; i++)
     {
        if (G.hand[p][i] == copper || G.hand[p][i] == silver || G.hand[p][i] == gold)
        {
           tresureCards++;
        }
     }
    return tresureCards;   
}

/*Make Sure Nothing Changed for other players*/
void CheckOtherPlayers(struct gameState G, struct gameState testG, int p, int numPlayers)
{
    int i;
    for (i = 0; i < numPlayers; i++)
    {
        if(i != p)
        {
            assert(testG.handCount[i] == G.handCount[i]);
            assert(testG.deckCount[i] == G.deckCount[i]);
            assert(CountTreasureCards(testG, i) == CountTreasureCards(G, i));
        }
    }
}

int main() {
    srand(time(NULL));
   
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed;
    int numPlayers, whichPlayer;
    int counter;
    int newCard = 1, discardCard = 1;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    for (counter = 0; counter < NUMTESTS; counter++)
    {
        seed = rand() % 6000 + 5; //Giving random seeds for each play
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        memset(&testG, 23, sizeof(struct gameState));   // clear the game state
        numPlayers = rand() % (MAX_PLAYERS - MIN_PLAYERS + 1) + MIN_PLAYERS; //Randomly choose number of players
        
        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);
        whichPlayer = G.whoseTurn = rand()%numPlayers; //Randomly choose players turn
       
        // copy the game state to a test case
	    memcpy(&testG, &G, sizeof(struct gameState));
        
	    cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
        
        assert(testG.numActions == G.numActions + 1);  //Make Sure number of action increased
        
        assert(testG.handCount[whichPlayer] == G.handCount[whichPlayer] + newCard - discardCard);
        
        assert(testG.playedCardCount == G.playedCardCount + 1);
        
        assert(testG.deckCount[whichPlayer] == G.deckCount[whichPlayer] - newCard);
        
        CheckOtherPlayers(G, testG, whichPlayer, numPlayers);
    }
	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}