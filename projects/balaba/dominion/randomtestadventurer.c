
/*
Random test card: playAdventurer()
Aleksandr Balab
CS 362 Spring 2016
Description: random tester for : playAdventurer() - refactored version from assignment 2
(Includes deliberate bug - Info can be found in refactor.c)
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
	time_t curSeed = time(NULL);
	srand((unsigned int)curSeed);
	int result = 1;
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int p, r, handCount;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	
	// arrays of all adventurers
	int adven[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		adven[i] = adventurer;
	}

	printf("\n Beginning testing for card playAdventurer() with the random seed number of: %d\n", (unsigned int)curSeed);
	//randomly assigned number of tests to run 
	while (result < 1000) {
		//randomized number of players out of max players +2 incase of 0
		numPlayer = rand() % (MAX_PLAYERS - 2) + 2;
		p = rand() % numPlayer;
		//random hand count - number of cards in hand 
		handCount = rand() % 9 + 2;

		printf("Test #%d: %d players, player %d playing adventurer card, hand size: %d\n", result, numPlayer, p, handCount);

		memset(&G, 23, sizeof(struct gameState));   
		r = initializeGame(numPlayer, k, seed, &G); 
		G.whoseTurn = p;
		G.handCount[p] = handCount;
		memcpy(G.hand[p], adven, sizeof(int) * handCount);

		r = playCard(0, 0, 0, 0, &G);

		printf("G.handCount = %d, %d <= expected <= %d\n", G.handCount[p], handCount - 1, handCount + 1);

		if (G.handCount[p] >= handCount - 1 && G.handCount[p] <= handCount + 1) {
			printf("The adventure card worked correctly\n");
			result++;
		}
		else {
			printf("The adventure card did not work correctly\n");
			result++;
		}
	}

	return 0;
}