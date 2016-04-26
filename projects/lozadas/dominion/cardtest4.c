/* -----------------------------------------------------------------------
*Name: Suyana Lozada 
*cardTest #4 
*cutpursecard 
*Reference:testUpdatecoins.c cardtest4.c 
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
    int xtracoins = 0;
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

	printf("Testing cutpurseCard()\n");
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;

	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 4;
	xtracoins = 0;

	printf("Test 1: player 0 update coins by 2\n");
	if (testG.coins==G.coins +2)
	{
		printf("PASS: test = %d, expected = %d\n",testG.coins,G.coins);
	}
	else
	{
		printf("PASS: test = %d, expected = %d\n",testG.coins,G.coins);
	}
	
	//Add copper treasure card to other player hand 	
	testG.hand[1][testG.handCount[1]-1]=copper;	
	printf("Test 2:Each other player in the game discards a copper card from hand\n");
	
	for (p = 1; p < numPlayers; p++)
	{
		
		if (scoreFor(p,&testG)==scoreFor(p,&G))
		{
			printf("PASS: test = %d, expected = %d\n",scoreFor(p,&testG),scoreFor(p,&G));
		}
		else
		{
			printf("FAIL: test = %d, expected = %d\n",scoreFor(p,&testG),scoreFor(p,&G));
		}	
	}	
	return 0;  
}


