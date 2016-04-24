/*
 * unittest3.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
 *
 *      Test updateCoins function.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>




int main() {

		int seed = 12;
		int numPlayers = 2;
		struct gameState G, testG;
		int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
				tribute, smithy, council_room };\
		int bonus;
		int before;
		int after;
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);

		printf("-------------------------------------------------\n");
		printf("-------------------------------------------------\n");
		printf("Test updateCoins Function: \n");
		printf("run test assuming hand has bonus 0, 3 silver(6), 1 gold(3), 1 copper(1) no bonus \n");
		memcpy(&testG, &G, sizeof(struct gameState));
		testG.coins = 0;
		testG.hand[testG.whoseTurn][0] = silver;
		testG.hand[testG.whoseTurn][1] = silver;
		testG.hand[testG.whoseTurn][2] = silver;
		testG.hand[testG.whoseTurn][3] = gold;
		testG.hand[testG.whoseTurn][4] = copper;
		updateCoins(testG.whoseTurn, &testG, 0);
		after = testG.coins;
		assert(after == 10);
		assert(before < after);
		printf("Test Completed with no errors.\n");
		printf("-------------------------------------------------\n");



		printf("-------------------------------------------------\n");
		printf("Test Update Coins Function With Bonus: \n");
		memcpy(&testG, &G, sizeof(struct gameState));
		testG.coins = 0;
		bonus = 5;
		testG.hand[testG.whoseTurn][0] = silver;
		testG.hand[testG.whoseTurn][1] = silver;
		testG.hand[testG.whoseTurn][2] = silver;
		testG.hand[testG.whoseTurn][3] = gold;
		testG.hand[testG.whoseTurn][4] = copper;
		updateCoins(testG.whoseTurn, &testG, bonus);
		after = testG.coins;
		assert(after == 15);
		assert(before < after);
		printf("Test Completed with no errors.\n");
		printf("-------------------------------------------------\n");

		printf("-------------------------------------------------\n");
		printf("Test Buying Card Value 4 and Updating Coins: \n");
		memcpy(&testG, &G, sizeof(struct gameState));
		testG.numBuys   = 1;
		testG.coins 	= 0;
		bonus 			= 0;
		testG.hand[testG.whoseTurn][0] = silver;
		testG.hand[testG.whoseTurn][1] = silver;
		testG.hand[testG.whoseTurn][2] = silver;
		testG.hand[testG.whoseTurn][3] = gold;
		testG.hand[testG.whoseTurn][4] = copper;
		testG.handCount[testG.whoseTurn] = 5;
		updateCoins(testG.whoseTurn, &testG, bonus);
		buyCard(treasure_map, &testG);
		updateCoins(testG.whoseTurn, &testG, bonus);
		if(testG.coins == 6)
		{
			printf("Test Passed. Card bought successfully.\n");
		}
		else
		{
			printf("Bug: Coin count expected is 6. Actual is %d\n", testG.coins);
		}

		printf("-------------------------------------------------\n");


		printf("-------------------------------------------------\n");

return 0;

}
