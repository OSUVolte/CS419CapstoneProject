// Joseph Cuellar 
// CS 362 - Assignment 4

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void OtherPlayersCards(struct gameState *);
void VillageTEST(int, struct gameState *, int);

int main() {
    int i, n, player1;
    int handPos = 0;
	struct gameState G;

	SelectStream(2);
    PutSeed(3);

    printf("TEST village Card. \n");
    for (n = 0; n < 1000; n++) {
        printf("\n TEST\n\n");
        // randomize struct - from lecture
        for (i = 0; i < sizeof(struct gameState); i++) {
          ((char*)&G)[i] = floor(Random() * 256);
        }

        OtherPlayersCards(&G);
        // pick random player
        G.numActions = 0;
        player1 = floor(Random() * 2);

        do{
            handPos = Random() * G.handCount[player1];
        } while (handPos == G.handCount[player1]);
        G.hand[player1][handPos] = village;
        VillageTEST(player1, &G, handPos);
    }
	printf("\n DONE \n\n");

	return 0;
}

void OtherPlayersCards(struct gameState *G){
    int i, j;
	for(i = 0; i < 2; i++){
	    int deckCards = floor(Random() * MAX_DECK);
        G->discardCount[i] = 0;
        G->playedCardCount = 0;
        int handCards = floor(Random() * MAX_HAND);

        if (handCards >  10 && deckCards > 10){
            if (rand()%2 == 1){
                deckCards /= 2;
                handCards /= 2;
            }
        }

		G->deckCount[i]  = deckCards;
		G->handCount[i] = deckCards;
		for(j = 0; j < deckCards; j++)
            G->deck[i][j] = floor(Random() * (treasure_map + 1));

		for(j = 0; j < handCards; j++)
            G->hand[i][j] = floor(Random() * (treasure_map + 1));
	}
}

void VillageTEST(int player1, struct gameState *G, int handPos) {
    int player2, result;
    int discardCount = 0;
    struct gameState testG;
    memcpy (&testG, G, sizeof(struct gameState));

    player2 = (player1 == 1) ? 0 : 1;
    result = callVillageCard( player1, &testG, handPos);

    drawCard(player1, G);
    G->numActions += 2;

    discardCard(handPos, player1, G, 0);
    discardCount++;

    // OUTPUT
    assert (result == 0); // village good
    printf("ACTIONS: actions %d, expected %d\n", testG.numActions, G->numActions);
    if (testG.numActions != G->numActions) 
        printf("FAILED: incorrect number of actions.\n");

    printf("DISCARD: Played card count %d, expected %d\n", testG.playedCardCount, G->playedCardCount);
    assert(testG.playedCardCount == G->playedCardCount);
    printf("Discarded card is village - played card value %d, expected %d\n", testG.playedCards[testG.playedCardCount - 1], village);
    assert(testG.playedCards[testG.playedCardCount - 1] == village);

    // player2 state
    printf("Second deck count - actual %d, expected %d\n", testG.deckCount[player2], G->deckCount[player2]);
    assert(testG.deckCount[player2] == G->deckCount[player2]);
    printf("Second hand count - actual %d, expected %d\n", testG.handCount[player2], G->handCount[player2]);
    assert(testG.handCount[player2] == G->handCount[player2]);
    printf("Second discard count - actual %d, expected %d\n", testG.discardCount[player2], G->discardCount[player2]);
    assert(testG.discardCount[player2] == G->discardCount[player2]);

    if (memcmp(G, &testG, sizeof(struct gameState)) == 0)
        printf("SUCCESS: Game states are the same.\n");
    else
        printf("FAIL: Game states are NOT the same.\n");
}