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
    printf("Testing shuffle functions, one hand will be shuffled and the exact same hand will not be.\n");
    printf("A visual inspection for randomness is required.\n");
    printf("Deck size and hand size should remain constant.\n\n");


    shuffle(0, &testG);

    printf("Player 0's shuffled deck\n");
    for(i = 0; i < testG.deckCount[0]; i++)
    {
        printf("%i, ", testG.deck[0][i]);
    }
    printf("\n");

    printf("Player 0's unshuffled deck\n");
    for(i = 0; i < G.deckCount[0]; i++)
    {
        printf("%i, ", G.deck[0][i]);
    }
    printf("\n\n");

    printf("Player 1's shuffled deck\n");
    for(i = 0; i < testG.deckCount[1]; i++)
    {
        printf("%i, ", testG.deck[1][i]);
    }
    printf("\n");

    printf("Player 1's unshuffled deck\n");
    for(i = 0; i < G.deckCount[1]; i++)
    {
        printf("%i, ", G.deck[1][i]);
    }
    printf("\n\n");



    if(numPlayers > 2)
    {
    printf("Player 2's shuffled deck\n");
    for(i = 0; i < testG.deckCount[2]; i++)
    {
        printf("%i, ", testG.deck[2][i]);
    }
    printf("\n");

    printf("Player 2's unshuffled deck\n");
    for(i = 0; i < G.deckCount[2]; i++)
    {
        printf("%i, ", G.deck[2][i]);
    }
    printf("\n\n");
    }

    if(numPlayers > 3)
    {
    printf("Player 3's shuffled deck\n");
    for(i = 0; i < testG.deckCount[3]; i++)
    {
        printf("%i, ", testG.deck[3][i]);
    }
    printf("\n");

    printf("Player 3's unshuffled deck\n");
    for(i = 0; i < G.deckCount[3]; i++)
    {
        printf("%i, ", G.deck[3][i]);
    }
    printf("\n\n");
    }

    for(i = 0; i < numPlayers; i++)
    {
            if(!(testG.deckCount[i] == G.deckCount[i]))
            {
                printf("player %i deck count = %d, expected = %d\n",j , testG.deckCount[j], G.deckCount[j]);
                printf("ERROR, player %i deck count not correct\n", j);
                errorCount++;
            }

            if(!(testG.handCount[i] == G.handCount[i]))  //tests hand count stays the same for other players
            {
                printf("player %i hand count = %d, expected = %d\n", j, testG.handCount[j], G.handCount[j]);
                printf("ERROR, player %i hand count not correct\n", j);
                errorCount++;
            }
    }
    	printf("\n >>>>> Testing complete with %i errors <<<<<\n\n\n", errorCount);
    return 0;

}
