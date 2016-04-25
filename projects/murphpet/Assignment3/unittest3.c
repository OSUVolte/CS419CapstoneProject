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

    int errorCount = 0;


    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    printf("Testing gainCard function.\n\n");




        printf("Trying to buy kingdom card not included in the game\n");

        returnValue = gainCard(19, &testG, 1 , thisPlayer);

        if(returnValue != -1)
        {
            printf("Incorrect return value for trying to buy a card not in game. \n");
            errorCount++;
        }

        printf("player hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
        if(!(testG.handCount[thisPlayer] == G.handCount[thisPlayer]))
        {
            printf("ERROR, card player hand count not correct\n");
            errorCount++;
        }

        printf("player deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
        if(!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]))
        {
            printf("ERROR, card player deck count not correct\n");
            errorCount++;
        }

        printf("player discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
        if(!(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]))
        {
            printf("ERROR, discard Count not correct\n");
            errorCount++;
        }

        printf("checking current supply count of card = %d, expected = %d\n",  testG.supplyCount[8], G.supplyCount[8]);
        if(!( testG.supplyCount[19] == G.supplyCount[19]))//card not in the game = 19
        {
            printf("ERROR, Supply Count not correct\n");
            errorCount++;
        }


        int newCard = 1;

        printf("Trying to buy a valid kingdom card and put it in player's deck\n");

        returnValue = gainCard(8, &testG, 1 , thisPlayer); //8 = council room

        if(returnValue != 0)
        {
            printf("Incorrect return value for trying to buy a card that is legal to buy. \n");
            errorCount++;
        }

        printf("player hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
        if(!(testG.handCount[thisPlayer] == G.handCount[thisPlayer]))
        {
            printf("ERROR, card player hand count not correct\n");
            errorCount++;
        }

        printf("player deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] + newCard);
        if(!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] + newCard))
        {
            printf("ERROR, card player deck count not correct\n");
            errorCount++;
        }

        printf("player discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
        if(!(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]))
        {
            printf("ERROR, discard Count not correct\n");
            errorCount++;
        }

        printf("player deck[player][newest card spot] = %d, expected = 8\n", testG.deck[thisPlayer][testG.deckCount[thisPlayer] - 1]);
        if(!(testG.deck[thisPlayer][testG.deckCount[thisPlayer] - 1] == 8))
        {
            printf("Wrong type of card put into deck.\n");
            errorCount++;
        }

        printf("checking current supply count of card = %d, expected = %d\n",  testG.supplyCount[8], G.supplyCount[8] -newCard);
        if(!( testG.supplyCount[8] == G.supplyCount[8] - newCard))
        {
            printf("ERROR, Supply Count not correct\n");
            errorCount++;
        }

       memcpy(&testG, &G, sizeof(struct gameState)); // restore memory to pre buy state


       newCard = 1;

        printf("Trying to buy a valid kingdom card and put it in player's hand\n");

        returnValue = gainCard(8, &testG, 2 , thisPlayer); //8 = council room

        if(returnValue != 0)
        {
            printf("Incorrect return value for trying to buy a card that is legal to buy. \n");
            errorCount++;
        }

        printf("player hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCard);
        if(!(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCard))
        {
            printf("ERROR, player hand count not correct\n");
            errorCount++;
        }

        printf("player deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
        if(!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]))
        {
            printf("ERROR, card player deck count not correct\n");
            errorCount++;
        }

        printf("player discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
        if(!(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]))
        {
            printf("ERROR, discard Count not correct\n");
            errorCount++;
        }

        printf("player hand[player][newest card spot] = %d, expected = 8\n", testG.hand[thisPlayer][testG.handCount[thisPlayer] - 1]);
        if(!(testG.hand[thisPlayer][testG.handCount[thisPlayer] - 1] == 8))
        {
            printf("Wrong type of card put into hand.\n");
            errorCount++;
        }

        printf("checking current supply count of card = %d, expected = %d\n",  testG.supplyCount[8], G.supplyCount[8] -newCard);
        if(!( testG.supplyCount[8] == G.supplyCount[8] - newCard))
        {
            printf("ERROR, Supply Count not correct\n");
            errorCount++;
        }


        memcpy(&testG, &G, sizeof(struct gameState)); // restore memory to pre buy state



        newCard = 1;

        printf("Trying to buy a valid kingdom card and put it in player's discard pile\n");

        returnValue = gainCard(8, &testG, 0 , thisPlayer); //8 = council room

        if(returnValue != 0)
        {
            printf("Incorrect return value for trying to buy a card that is legal to buy. \n");
            errorCount++;
        }

        printf("player hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
        if(!(testG.handCount[thisPlayer] == G.handCount[thisPlayer]))
        {
            printf("ERROR, player hand count not correct\n");
            errorCount++;
        }

        printf("player deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
        if(!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]))
        {
            printf("ERROR, card player deck count not correct\n");
            errorCount++;
        }

        printf("player discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + newCard);
        if(!(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]+ newCard))
        {
            printf("ERROR, discard Count not correct\n");
            errorCount++;
        }

        printf("player discard[player][newest card spot]  = %d, expected = 8\n", testG.discard[thisPlayer][testG.discardCount[thisPlayer] - 1]);
        if(!(testG.discard[thisPlayer][testG.discardCount[thisPlayer] - 1] == 8))
        {
            printf("ERROR, Wrong type of card put into hand.\n");
            errorCount++;
        }

        printf("checking current supply count of card = %d, expected = %d\n",  testG.supplyCount[8], G.supplyCount[8] -newCard);
        if(!( testG.supplyCount[8] == G.supplyCount[8] - newCard))
        {
            printf("ERROR, Supply Count not correct\n");
            errorCount++;
        }

        memcpy(&testG, &G, sizeof(struct gameState));
        testG.supplyCount[8] = 0; // sets council room to bought out

        printf("Trying to buy kingdom card not included in the game\n");

        returnValue = gainCard(8, &testG, 1 , thisPlayer);

        if(returnValue != -1)
        {
            printf("Incorrect return value for trying to buy a card sold out. \n");
            errorCount++;
        }

        printf("player hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
        if(!(testG.handCount[thisPlayer] == G.handCount[thisPlayer]))
        {
            printf("ERROR, card player hand count not correct\n");
            errorCount++;
        }

        printf("player deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
        if(!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]))
        {
            printf("ERROR, card player deck count not correct\n");
            errorCount++;
        }

        printf("player discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
        if(!(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]))
        {
            printf("ERROR, discard Count not correct\n");
            errorCount++;
        }

        printf("checking current supply count of card = %d, expected = %d\n",  testG.supplyCount[8], G.supplyCount[8] - G.supplyCount[8]);
        if(!( testG.supplyCount[8] == G.supplyCount[8] - G.supplyCount[8]))
        {
            printf("ERROR, Supply Count not correct\n");
            errorCount++;
        }





    	printf("\n >>>>> Testing complete with %i errors <<<<<\n\n\n", errorCount);
    return 0;

}
