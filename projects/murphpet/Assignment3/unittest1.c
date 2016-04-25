#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
    int i, j;
    int seed = 1000;
    int numPlayers = 4;
    int maxBonus = 10;
    int thisPlayer = 0;
    int  r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    int maxHandCount = 5;
    int deckCount;
    int returnValue;
    printf ("TESTING drawCard():\n");
    int errorCount = 0;


    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    printf("Testing drawing one player to 0 and keep trying to draw from deck once 0.\n");
    printf("Other players deck count should stay at initial value.\n");
    printf("Victory cards and Kingdom cards should stay at the same values.\n");
    printf("Actions, buys and coins should remain constant.\n");
    printf("Attempts to draw with no more cards in deck should return -1.\n\n");
    for (i = 1; i < 6; i++)
    {
        returnValue = drawCard(thisPlayer, &testG);

        if(returnValue == -1)
        {
            printf("ERROR, DrawCard failed with cards in deck \n", thisPlayer);
            errorCount++;
        }

        //testing drawing player's deck and hand counts

        if(!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - i))
        {
            printf("player %i deck count = %d, expected = %d\n",thisPlayer , testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - i);
            printf("ERROR, player %i deck count not correct\n", thisPlayer);
            errorCount++;
        }

        if(!(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + i))  //tests hand count stays the same for other players
        {
            printf("player %i hand count = %d, expected = %d\n", thisPlayer, testG.handCount[thisPlayer], G.handCount[thisPlayer] + i);
            printf("ERROR, player %i hand count not correct\n", thisPlayer);
            errorCount++;
        }

        //testing victory card levels

        if(!(testG.supplyCount[1] == G.supplyCount[1]))
        {
            printf("Error, estate card total count = %d, expected %d\n", testG.supplyCount[1], G.supplyCount[1]);
            errorCount++;
        }

        if(!(testG.supplyCount[2] == G.supplyCount[2]))
        {
            printf("Error, duchy card total count = %d, expected %d\n", testG.supplyCount[2], G.supplyCount[2]);
            errorCount++;
        }

        if(!(testG.supplyCount[3] == G.supplyCount[3]))
        {
            printf("Error, province card total count = %d, expected %d\n", testG.supplyCount[3], G.supplyCount[3]);
            errorCount++;
        }

        if(!(testG.coins == G.coins))
        {
            printf("player coins = %d, expected = %d\n", testG.coins, G.coins);
            errorCount++;
        }

        if(!(testG.numBuys == G.numBuys))
        {
           printf("buys = %d, expected = %d\n", testG.numBuys, G.numBuys);
           errorCount++;
        }

        if(!(testG.numActions == G.numActions))
        {
            printf("number of actions = %d, expected = %d\n", testG.numActions, G.numActions);
            errorCount++;
        }

        for(j = 0; j < numPlayers; j++)
        {
                if(j != thisPlayer) //tests other players decks and hands are constant while this player draws
                {
                        if(!(testG.deckCount[j] == G.deckCount[j]))
                        {
                            printf("player %i deck count = %d, expected = %d\n",j , testG.deckCount[j], G.deckCount[j]);
                            printf("ERROR, player %i deck count not correct\n", j);
                            errorCount++;
                        }

                        if(!(testG.handCount[j] == G.handCount[j]))  //tests hand count stays the same for other players
                        {
                            printf("player %i hand count = %d, expected = %d\n", j, testG.handCount[j], G.handCount[j]);
                            printf("ERROR, player %i hand count not correct\n", j);
                            errorCount++;
                        }
                }

            }

     }//end main forloop drawing this players cards
    i--;//used to restore i to proper level

        //attempting to draw from empty deck
        for(j = 0 ; j < 10; j++)
        {
            returnValue = drawCard(thisPlayer, &testG);
            if(!(returnValue == -1))
            {
                printf("ERROR, DrawCard didn't return error -1 with no cards in deck \n", thisPlayer);
                errorCount++;
            }
        }



                //testing drawing player's deck and hand counts
        if(!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - i))
        {
            printf("player %i deck count = %d, expected = %d\n",thisPlayer , testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - i);
            printf("ERROR, player %i deck count not correct\n", thisPlayer);
            errorCount++;
        }

        if(!(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + i))  //tests hand count stays the same for other players
        {
            printf("player %i hand count = %d, expected = %d\n", thisPlayer, testG.handCount[thisPlayer], G.handCount[thisPlayer] + i);
            printf("ERROR, player %i hand count not correct\n", thisPlayer);
            errorCount++;
        }

        //testing victory card levels

        if(!(testG.supplyCount[1] == G.supplyCount[1]))
        {
            printf("Error, estate card total count = %d, expected %d\n", testG.supplyCount[1], G.supplyCount[1]);
            errorCount++;
        }

        if(!(testG.supplyCount[2] == G.supplyCount[2]))
        {
            printf("Error, duchy card total count = %d, expected %d\n", testG.supplyCount[2], G.supplyCount[2]);
            errorCount++;
        }

        if(!(testG.supplyCount[3] == G.supplyCount[3]))
        {
            printf("Error, province card total count = %d, expected %d\n", testG.supplyCount[3], G.supplyCount[3]);
            errorCount++;
        }

        if(!(testG.coins == G.coins))
        {
            printf("player coins = %d, expected = %d\n", testG.coins, G.coins);
            errorCount++;
        }

        if(!(testG.numBuys == G.numBuys))
        {
           printf("buys = %d, expected = %d\n", testG.numBuys, G.numBuys);
           errorCount++;
        }

        if(!(testG.numActions == G.numActions))
        {
            printf("number of actions = %d, expected = %d\n", testG.numActions, G.numActions);
            errorCount++;
        }
 	printf("\n >>>>> Testing complete with %i errors <<<<<\n\n\n", errorCount);

    return 0;
}
