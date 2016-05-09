#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>

void testSmithy();
void randomGameState(struct gameState *state);

int main(int argc, char *argv[])
{
	srand(time(NULL));
	testSmithy();
    return 0;
    
}

void testSmithy() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int bonus;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
    struct gameState G;
	int drawntreasure = 0;
	int cardDrawn = 0;
	int temphand[MAX_HAND];
	int z = 0;
	int originalDeckCount;
	int originalHandCount;
	int currentPlayer = 0;
	int count = 0;
	int handPosition = 0;

	while(1) {
		count++;
		initializeGame(numPlayer, k, seed, &G);
		randomGameState(&G);

		//Randomize Current Player
		currentPlayer = rand() % 2;

		//Randomize Hand Position
		handPosition = rand() % 5;

		smithyFunct(handPosition, currentPlayer, &G);
		printf("Iteration %i\n", count);
	}
}

void randomGameState(struct gameState *state) {
	int i;
	int j;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
	int l;
	int m;
	int n;
	
	//Supply Counts
	state->supplyCount[estate] = rand() % 8 + 1;
	state->supplyCount[duchy] = rand() % 8 + 1;
	state->supplyCount[province] = rand() % 8 + 1;
	state->supplyCount[copper] = rand() % (60 - (7 * 2) + 1);
	state->supplyCount[silver] = rand() % 41;
	state->supplyCount[gold] = rand() % 31;

	for (i = 0; i < 2; i++) {
		//Player Deck Count
		state->deckCount[i] = rand() % (MAX_DECK + 1);
		for (j = 0; j < state->deckCount[i]; j++) {
			l = rand() % 10;
			state->deck[i][j] = k[l];
		}
		n = rand() % (state->deckCount[i] + 1) + 3;
		for (j = 0; j < n; j++) {
			l = rand() % 4;
			if (l == 0) {
				state->deck[i][j] = copper;
			} else if (l == 1) {
				state->deck[i][j] = silver;
			} else {
				state->deck[i][j] = gold;
			}
		}
		
		//Draw 5 cards
		for (m = 0; m < 5; m++) {
			drawCard(i, state);
		}
	}
}

