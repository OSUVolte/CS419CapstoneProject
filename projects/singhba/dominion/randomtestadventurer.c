/*
 * randomtestadventurer.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
 *      gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h> 

#define TESTCARD "adventurer"
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
    int counter, tresureBefore, tresureAfter;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    for (counter = 0; counter < NUMTESTS; counter++)
    {
        seed = rand() % 6000; //Giving random seeds for each play
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        memset(&testG, 23, sizeof(struct gameState));   // clear the game state
        numPlayers = rand() % (MAX_PLAYERS - MIN_PLAYERS + 1) + MIN_PLAYERS; //Randomly choose number of players
        
        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);
        whichPlayer = G.whoseTurn = rand()%numPlayers; //Randomly choose players turn
       
        // copy the game state to a test case
	    memcpy(&testG, &G, sizeof(struct gameState));
        
	    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
        
        tresureAfter = CountTreasureCards(testG, whichPlayer);
        tresureBefore = CountTreasureCards(G, whichPlayer);
        
        
        assert(tresureBefore + 2 == tresureAfter);
        assert(testG.handCount[whichPlayer] == G.handCount[whichPlayer] + 2);
        if(testG.playedCardCount != G.playedCardCount+1)
        {
            printf("\nFAILED: Played Card Count.\n");
            printf("EXPECTED: %d , ACTUAL %d\n", G.playedCardCount + 1, testG.playedCardCount);
        }
        if(testG.deckCount[whichPlayer] + testG.discardCount[whichPlayer] != G.deckCount[whichPlayer] + G.discardCount[whichPlayer] - 2)
        {
            printf("\nFAILED: Discard pile and Deck count.\n");
            printf("Discard Pile before: %d and after %d\n", G.discardCount[whichPlayer], testG.discardCount[whichPlayer]);
            printf("Deck Count before: %d and after %d\n", G.deckCount[whichPlayer], testG.deckCount[whichPlayer]);
        }
        CheckOtherPlayers(G, testG, whichPlayer, numPlayers);
    }

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}