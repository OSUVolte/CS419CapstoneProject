/*********************************************************************************************
 * Developer: Nick Martin (martinn6)
 * Date: 20160422
 * Project: Assignement 3
 * Description: unittest1.c Tests the updateCoins() function.
 * *******************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int runTest(int player, int handCount, int bonus, int *coins)
{
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
	struct gameState state;
	int numPlayer = 2;
	int seed = 1000;
	int handPos = 1;
	int card;
	printf("Test player %d with %d treasure card(s) and %d bonus.\n", player, handCount, bonus);
	memset(&state, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &state); // initialize a new game
	state.handCount[player] = handCount;                 // set the number of cards on hand
	memcpy(state.hand[player], coins, sizeof(int) * handCount); // set all the cards to copper
	updateCoins(player, &state, bonus);
	printf("state.coins = %d, expected = %d: ", state.coins, (handCount * (coins[0]-3)) + bonus); //copper = 4, silver = 5, gold = 6 in enum. -3 for value.
	if(state.coins == (handCount * (coins[0]-3)) + bonus)
		printf("PASSED\n");
	else
		printf("FAILURE\n");
	return(0);
}



int main() {
    int isFailure;
	int seed = 1000;
	int numPlayer = 2;
    int player = 0;
    int bonus = 0;
	int handCount = 1;
	int r;
    
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (int i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }
	
	//runtest1 = boundary tests utilizing all decks with only coins
	//int player, int handCount, int bonus, int *coins
	//coppers no bonus
	
	for(int p = 0; p<MAX_PLAYERS;p++ )
	{
		printf("coppers no bonus\n");
		runTest(p, 1, 0, coppers);
		runTest(p, MAX_HAND, 0, coppers);
		printf("coppers with bonus\n");
		runTest(p, 1, 10, coppers);
		runTest(p, MAX_HAND, 10, coppers);
		printf("silvers no bonus\n");
		runTest(p, 1, 0, silvers);
		runTest(p, MAX_HAND, 0, silvers);
		printf("silvers with bonus\n");
		runTest(p, 1, 10, silvers);
		runTest(p, MAX_HAND, 10, silvers);
		printf("gold no bonus\n");
		runTest(p, 1, 0, golds);
		runTest(p, MAX_HAND, 0, golds);
		printf("gold with bonus\n");
		runTest(p, 1, 10, golds);
		runTest(p, MAX_HAND, 10, golds);
		printf("no coins & no bonus\n");
		runTest(p, 0, 0, coppers);
		runTest(p, 0, 0, silvers);
		runTest(p, 0, 0, golds);
		printf("no coins with bonus\n");
		runTest(p, 0, 10, coppers);
		runTest(p, 0, 10, silvers);
		runTest(p, 0, 10, golds);
	}
	
    return 0;
}
