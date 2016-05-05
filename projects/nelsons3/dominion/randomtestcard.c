#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int testCouncilRoom(struct gameState *beforeCardPlayedStruct)
{
    printf(".");
    //break loop
    time_t endwait;
    int seconds = 5;

    int counter;
     //create test game
    struct gameState afterCardPlayedStruct;
    memcpy(&afterCardPlayedStruct,beforeCardPlayedStruct,sizeof(struct gameState));
    assert (memcmp(&afterCardPlayedStruct,beforeCardPlayedStruct, sizeof(struct gameState))==0);

    endwait = time (NULL) + seconds ;
    while (time (NULL) < endwait)
     {
       //play council room;
       playCouncil_Room(&afterCardPlayedStruct);
       int currentPlayer = beforeCardPlayedStruct->whoseTurn;
       //give 4 cards to before struct so we can compare
       drawCard(currentPlayer,beforeCardPlayedStruct);
       drawCard(currentPlayer,beforeCardPlayedStruct);
       drawCard(currentPlayer,beforeCardPlayedStruct);
       drawCard(currentPlayer,beforeCardPlayedStruct);
       //give before struct +1 buy
       beforeCardPlayedStruct->numBuys += 1;
       //other players draw card
       printf("%d- ", currentPlayer);
       for (counter = 0; counter < beforeCardPlayedStruct->numPlayers; counter++)
       {
         if ( counter != currentPlayer )
         {
              drawCard(counter, beforeCardPlayedStruct);
         }
         printf("player %d expected %d test  %d, \n", counter,  beforeCardPlayedStruct->handCount[counter], afterCardPlayedStruct.handCount[counter]);
       }
       if(memcmp(&afterCardPlayedStruct,beforeCardPlayedStruct, sizeof(struct gameState))==0)
       {      
         printf("Council Room Test PASS\n");
       }
       else
       {
         printf("Council room Test FAIL\n");
       }
    return 0;
    }
    printf("timeout");
    return 0;
}


int main()
{
    printf("PlayCouncil_Room test - randomtestcard\n");
    //array of cards
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState beforeCardPlayedState;
    int counter,innerCounter,innerInnerCounter;
    //create random seed
    SelectStream(2);
    PutSeed(3);
    //cycle through 5k tests
    for (counter = 0; counter < 5000; counter++)
    {
        printf("-");
        for (innerCounter = 0; innerCounter < sizeof(struct gameState); innerCounter++) {
          //fill game state with random bits
          ((char*)&beforeCardPlayedState)[innerCounter] = Random() * 256;
        }
        //fill in required preconditions
        //set players and current play
        beforeCardPlayedState.numPlayers = Random() * (MAX_PLAYERS-1)+1;   //Will select 0,1,2,3 being 4 players but with an offset of 1 it will pick 1,2,3,4 excluding 0 players
        //sets players turn
        beforeCardPlayedState.whoseTurn = Random() * beforeCardPlayedState.numPlayers;
        //keep track of players turn
        int currentPlayer = beforeCardPlayedState.whoseTurn;
        //setup number of buys field in pre play struct
        beforeCardPlayedState.numBuys = Random() * 10;
        
        //setup each players handCount, deckCount, discardCount, 
        for (innerCounter = 0; innerCounter < beforeCardPlayedState.numPlayers; innerCounter++)
        {
            beforeCardPlayedState.handCount[innerCounter] = Random() * (499); // non zero handcount
            beforeCardPlayedState.deckCount[innerCounter] = Random() * (10);
            beforeCardPlayedState.discardCount[innerCounter] = Random() * (10);

            for(innerInnerCounter=0;innerInnerCounter<beforeCardPlayedState.handCount[innerCounter];innerInnerCounter++)
            {
                beforeCardPlayedState.hand[innerCounter][innerInnerCounter] = Random() * 10;
            }
            for(innerInnerCounter=0;innerInnerCounter<beforeCardPlayedState.deckCount[innerCounter];innerInnerCounter++)
            {
                beforeCardPlayedState.hand[innerCounter][innerInnerCounter] = Random() * 10;
            }
            for(innerInnerCounter=0;innerInnerCounter<beforeCardPlayedState.discardCount[innerCounter];innerInnerCounter++)
            {
                beforeCardPlayedState.discard[innerCounter][innerInnerCounter] = Random() * 10;
            }
        }
        //run test
        testCouncilRoom(&beforeCardPlayedState);
    }

return 0;
}

