// Joseph Cuellar 
// CS 362 - Assignment 4

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int cardsForPlayer(int, struct gameState *);
void checkAdventurer(int, struct gameState *, int);

int main() {
    int i, n, player1, handPos, p1treasure, p2treasure, treasureBefore;
	struct gameState G;
	
	SelectStream(2);
    PutSeed(3);
	
    printf("TEST Adventurer Card.\n");
    for (n = 0; n < 1000; n++) {
        printf("\n TEST %d \n\n", n + 1);
        for (i = 0; i < sizeof(struct gameState); i++) {
          ((char*)&G)[i] = floor(Random() * 256);
        }
        p1treasure = cardsForPlayer(0, &G);
        p2treasure = cardsForPlayer(1, &G);
        // Pick player randomly 
        player1 = floor(Random() * 2);
		treasureBefore = (player1 == 0) ? p1treasure : p2treasure;
        checkAdventurer(player1, &G, treasureBefore);

    }

	printf("\n DONE \n\n");
	return 0;
}

int cardsForPlayer(int player1, struct gameState *G){
	int j, numTreasure, thisCard;
    int deckCards = floor(Random() * MAX_DECK);
    G->discardCount[player1] = 0;
    int handCards = floor(Random() * MAX_HAND);

    G->deckCount[player1] = deckCards;
    G->handCount[player1] = handCards;

    for(j = 0; j < deckCards; j++)    {
        thisCard = floor(Random() * (treasure_map + 1));
        if ((thisCard == gold || thisCard == silver) || thisCard == copper)
            numTreasure++;

        G->deck[player1][j] = thisCard;

        if (j == deckCards - 1 && numTreasure < 2){
            j = 0;
            numTreasure = 0;
        }
    }

    numTreasure = 0; 
    for(j = 0; j < handCards; j++)    {
        thisCard = floor(Random() * (treasure_map + 1));
        G->hand[player1][j] = thisCard;
        if ((thisCard == gold || thisCard == silver) || thisCard == copper)
            numTreasure++;
    }

	return numTreasure;
}

void checkAdventurer(int player1, struct gameState *G, int treasureBefore){
    int treasureAfter = 0;
    int deckBefore;
    int numTreasure = 0;
    struct gameState testG;
    int i, z = 0;
    int temphand[MAX_HAND];
    int player2, result;
    int discardCount = 0;

    memcpy (&testG, G, sizeof(struct gameState));
    deckBefore = testG.deckCount[player1];
	player2 = (player1 == 1) ? 0 : 1;
    result = callAdventurerCard(&testG, player1);

    for (i = 0; i < testG.handCount[player1]; i++)  {
        if (testG.hand[player1][i] <= gold && testG.hand[player1][i] >= copper)
            treasureAfter++;
    }

    while(numTreasure < 2)
	{
		if(G->deckCount[player1] < 1){
			shuffle(player1, G);
		}

		drawCard(player1, G);
		int thisCard = G->hand[player1][G->handCount[player1]-1];
		if (thisCard >= copper && thisCard <= gold)
			numTreasure++;
		else{
		    discardCount++; 
			temphand[z] = thisCard;
			G->handCount[player1]--;
			z++;
		}
	}

	while(z-1>=0){
        G->discard[player1][G->discardCount[player1]++]=temphand[z-1]; 
        z--;
    }

    assert (result == 0);
    int treasureReceived = treasureAfter - treasureBefore;

    if (treasureReceived != numTreasure) 
        printf("FAIL: Treasure count bad.\n");

    if (testG.discardCount[player1] != discardCount)
        printf("FAIL: Discard not incremented.\n");

    if (memcmp(G, &testG, sizeof(struct gameState)) == 0)
        printf("SUCCESS: Game states are the same.\n");
    else
        printf("FAIL: Game states are NOT the same.\n");
}

