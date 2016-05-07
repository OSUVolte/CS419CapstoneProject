#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#define TESTCARD "smithy"

int checkSuplies(struct gameState G, struct gameState testG, int errorCount);
void setupRandomCards(struct gameState G, int thisPlayer, int numPlayers);
int checkCardPlayersValues(struct gameState G, struct gameState testG, int errorCount, int thisPlayer);
int checkOtherPlayersValues(struct gameState G, struct gameState testG, int errorCount, int thisPlayer, int numPlayers);


int main(){



    int errorCount;
    int i;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 912;
    int numPlayers;
    int thisPlayer = 0;
    struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

    srand(time(NULL)); // seed srand

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);


   // int random_number = rand() % range + min;

    for(i = 0; i < 20; i++)//to increase number of tests raise i < to desired amount
    {
        errorCount = 0;
        numPlayers = rand() % 3 + 2;        //random num of players
        seed = rand() % 10000 + 1;          //random seed 1 - 10000
        initializeGame(numPlayers, k, seed, &G);         //random game started
        setupRandomCards(G, thisPlayer, numPlayers);     //assigns random cards to every players hand and deck
        memcpy(&testG, &G, sizeof(struct gameState));    //copies gamestate struct to compare to other struct with card played
        cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
        errorCount = checkCardPlayersValues(G, testG,  errorCount, thisPlayer);
        errorCount = checkSuplies(G, testG, errorCount);    //checks all supplies of cards not in hands
        errorCount = checkOtherPlayersValues(G, testG, errorCount, thisPlayer, numPlayers);
        if(errorCount > 0)
        {
            printf("TO REPLICATE ABOVE ERRORS, seed = %i, number of players = %i\n\n", seed, numPlayers);
        }
    }
return 0;
}


int checkSuplies(struct gameState G, struct gameState testG, int errorCount)
{
    int i;

      if(!(testG.supplyCount[1] == G.supplyCount[1]))
    {
        printf("ERROR, estate card total count = %d, expected %d\n", testG.supplyCount[1], G.supplyCount[1]);
        errorCount++;
    }


    if(!(testG.supplyCount[2] == G.supplyCount[2]))
    {
        printf("ERROR, duchy card total count = %d, expected %d\n", testG.supplyCount[2], G.supplyCount[2]);
        errorCount++;
    }



    if(!(testG.supplyCount[3] == G.supplyCount[3]))
    {
        printf("ERROR, province card total count = %d, expected %d\n", testG.supplyCount[3], G.supplyCount[3]);
        errorCount++;
    }


    if(!(testG.supplyCount[3] == G.supplyCount[3]))
    {
        printf("ERROR, province card total count = %d, expected %d\n", testG.supplyCount[3], G.supplyCount[3]);
        errorCount++;
    }


        //checks all supplies of cards, even the cards not chosen for the game
        for(i = 0; i < 27; i++)
        {

                if(!(testG.supplyCount[i] == G.supplyCount[i]))
                {
                printf("ERROR, type %i IE CARD ENUM count not correct\n", i);
                errorCount++;
                }
        }

return errorCount;
}


void setupRandomCards(struct gameState G, int thisPlayer, int numPlayers)
{
    int i;
    int j;
    for(i = 0; i < numPlayers; i++)
    {
        G.deckCount[i] = rand() % (MAX_DECK - 1) + 1; //random deckcount
        for(j = 0; j < G.deckCount[i]; j++)
        {
            G.deck[i][j] = rand() % 27;   //random cards drawn out of 27 total cards
        }


        G.handCount[i] = rand() % (MAX_HAND -1) + 1;
        for(j = 0; j < G.handCount[i]; j++)
        {
            G.hand[i][j] = rand() % 27;    //random cards drawn out of 27 total cards
        }

     G.hand[0][0] = smithy; //gives player an adventurer to play

    }
return;
}

int checkCardPlayersValues(struct gameState G, struct gameState testG, int errorCount, int thisPlayer)
{
    int newCards = 3;// 2 new treasure cards
    int playedCards = 1; //played an adventurer card
    int i;

    if(!(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - playedCards))
    {
        printf("ERROR, card player hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards  - playedCards);
        errorCount++;
    }


	if(!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards - G.discardCount[thisPlayer] ))
    {
       printf("ERROR, card player deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards - G.playedCardCount);
       errorCount++;
    }


	if(!(testG.coins == G.coins))
    {
        printf("ERROR, card player coins = %d, expected = %d\n", testG.coins, G.coins );
        errorCount++;
    }

	if(!(testG.numBuys == G.numBuys))
    {
        printf("ERROR, buys = %d, expected = %d\n", testG.numBuys, G.numBuys);
        errorCount++;
    }

    //actions are decremented after cardEffect() returns this checks that actions werent added
	if(!(testG.numActions == G.numActions))
    {
        printf("ERROR, number of actions = %d, expected = %d\n", testG.numActions, G.numActions); //actions
        errorCount++;
    }
    return errorCount;
}


int checkOtherPlayersValues(struct gameState G, struct gameState testG, int errorCount, int thisPlayer, int numPlayers)
{
    int i;
    for(i = 0; i < numPlayers; i++)
    {
        if(i != thisPlayer)
        {

            	if(!(testG.handCount[i] == G.handCount[i]))
                {
                printf("ERROR, player %i hand count = %d, expected = %d\n", i, testG.handCount[i], G.handCount[i]);
                errorCount++;
                }
        }
    }


    for(i = 0; i < numPlayers; i++)
    {
        if(i != thisPlayer)
        {


                if(!(testG.deckCount[i] == G.deckCount[i]))
                {
                    printf("player %i deck count = %d, expected = %d\n",i , testG.deckCount[i], G.deckCount[i]);
                    errorCount++;
                }
        }
    }


    return errorCount;
}



