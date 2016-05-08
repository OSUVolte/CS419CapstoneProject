#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
int playSmithy(struct gameState *state, int handPos){

int i;
int currentPlayer = whoseTurn(state);

for (i = 0; i < 2; i++)
{
drawCard(currentPlayer, state);
}

//discard card from hand
discardCard(handPos, currentPlayer, state, 1);

return 0;
}
*/

int main() {
    int player;
    int testCount = 0;
    struct gameState Game;

    //game parameters

    int i;

    int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy };

    srand(time(NULL));

    int failed = 0;

    int random = rand() % 10;
    int numPlayers = rand() % (MAX_PLAYERS - 1) + 2;

    while (testCount < 1000){

        //printf("1.\n");
        //set it to a random person's turn
        initializeGame(numPlayers, k, random, &Game);
        int randomPlayer;

        //have to add this in... don't know why...

        if (numPlayers == 0)
            numPlayers += 2;

        player = rand() % numPlayers;

        Game.whoseTurn = player;

        int randomHand = rand() % MAX_HAND;
        //printf("random hand: %d\n", randomHand);
        Game.handCount[player] = randomHand;

        //fill this random hand to ensure no errors;
        for (i = 0; i < randomHand; i++)
        {
            int randomCard = rand() % 10;

            Game.hand[player][i] = randomCard;

        }

        cardEffect(smithy, 0, 0, 0, &Game, 0, 0);

        int finalHand = Game.handCount[player];
        //printf("final hand: %d\n", finalHand);
        if (randomHand != finalHand - 2)
            failed++;

        testCount++;
    }

    printf("Num Failed: %d\n", failed);
}