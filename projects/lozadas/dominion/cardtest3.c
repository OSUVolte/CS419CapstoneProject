/* -----------------------------------------------------------------------
*Name: Suyana Lozada 
*cardTest #3 
*councilRoomCard() 
*Reference:testUpdateCoins.c cardtest4.c 
*Test description:
*
* -----------------------------------------------------------------------
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
	int treasure=0;
    int p,i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("Testing council_room ()\n");
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;

	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 4;
	xtraCoins = 0;

	printf("Test 1: player 0 draws 4 cards from deck\n");
	//Determine the number of treasure cards in player hand for G game  
	if (testG.handCount[thisPlayer]==G.handCount[thisPlayer]+ newCards -discarded)
	{
		printf("PASS: test = %d, expected = %d\n",testG.handCount[thisPlayer],G.handCount[thisPlayer]+ newCards -discarded);
	}
	else
	{
		printf("FAIL: test = %d, expected = %d\n",testG.handCount[thisPlayer],G.handCount[thisPlayer]+ newCards -discarded);
	}
	printf("Test 2: 1 buy is added to the state of the game\n");
	if (testG.numBuys==G.numBuys + 1)
	{
		printf("PASS: test = %d, expected = %d\n",testG.numBuys,G.numBuys + 1);
	}
	else
	{	
		printf("FAIL: test = %d, expected = %d\n",testG.numBuys,G.numBuys + 1);
	}
	printf("Test 3:Each other player in the game draws one card\n");
	
	for (p = 1; p < numPlayers; p++)
	{
		if (testG.handCount[p]==G.handCount[p]+ 1)
		{
			printf("PASS: test = %d, expected = %d\n",testG.handCount[p],G.handCount[p]+ 1);
		}
		else
		{
			printf("FAIL: test = %d, expected = %d\n",testG.handCount[p],G.handCount[p]+ 1);
		}	
	}	
	
	return 0;  
}


