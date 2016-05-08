/*
Random test card: playSalvager()
Aleksandr Balab
CS 362 Spring 2016
Assignment 4
(Includes deliberate bug - Info can be found in refactor.c)
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h> //random 
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	time_t curSeed = time(NULL);

	srand((unsigned int)curSeed);

	int result = 1;

	int i;
	int seed = 1000;
	int numPlayer = 2;
	int p, r, handCount, correctBuys, correctCoins, toTrash;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;

	int salv[11];
	salv[0] = salvager;
	for (i = 1; i < 11; i++)
	{
		salv[i] = k[i - 1];
	}


	printf("\n Beginning testing for card Salvager() with the random seed number of: %d\n", (unsigned int)curSeed);

	//run the test with random seed number 1000 times finds bug 
	while (result < 1000) {
		//randomized number of players out of max players +2 incase of 0
		numPlayer = rand() % (MAX_PLAYERS - 2) + 2;
		//current player 
		p = rand() % numPlayer;
		//random hand count - number of cards in hand 
		handCount = rand() % 9 + 2;
		//random number of cards to trash 
		toTrash = rand() % (handCount - 1) + 1;

		printf("Test #%d: %d players, player %d playing Salvager card, hand size: %d, hand to trash: %d\n", result, numPlayer, p, handCount, toTrash);
		
		//reset the gamestate
		memset(&G, 23, sizeof(struct gameState));   
		//new game
		r = initializeGame(numPlayer, k, seed, &G);  
		//Get selected card amount
		G.whoseTurn = p;
		G.handCount[p] = handCount;
		correctBuys = G.numBuys + 1;
		correctCoins = G.coins + getCost(salv[toTrash]);

		memcpy(G.hand[p], salv, sizeof(int) * handCount);

		r = playCard(0, toTrash, 0, 0, &G);

		printf("G.numBuys = %d, expected = %d\n", G.numBuys, correctBuys);
		printf("G.coins = %d, expected = %d\n", G.coins, correctCoins);

		if (G.numBuys == correctBuys + 2 && G.coins == correctCoins) {
			printf("The Salvager card worked correctly\n");
			result++;
		}
		else {
			printf("The Salvager card did not work correctly\n");
			result++;
		}

	}

	return 0;
}