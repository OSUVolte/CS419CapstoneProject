/* -----------------------------------------------------------------------
*Name: Suyana Lozada 
*Assignment #4
*CS 362
*Reference:testUpdateCoins.c cardtest4.c testDrawCard.c 
*Test Council Room card
* -----------------------------------------------------------------------
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
int main() {
    int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;
	int treasure=0, expected=0;
    int i, j, tcounter,p;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int failure=0,success=0; 
	int remove1, remove2;
    int seed = 0;
    int extraCoins=2;
	int numPlayers = 0;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int numTests=500;
	srand(time(NULL));
	
	printf("*****************Randon Testing Council Room Card******************\n\n");
	for (tcounter=0; tcounter< numTests; tcounter++)
	{	
		//struct gameState G, testG;
		treasure=0;
		expected=0;		
	
		//Randomly select game seed. 	
		seed=rand();
			
		//Randomly set the number of players.
		numPlayers=rand()%3+2;	
		
		//Clear memory previus game test
		memset(&G,23,sizeof(struct gameState)); 		
		memset(&testG,23,sizeof(struct gameState)); 		
	
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);

		//Randomly set player deck,hand, and discard piles
		for(p=0; p< numPlayers; p++)
		{
	    	G.deckCount[p] = floor(Random() * MAX_DECK);
    		G.discardCount[p] = floor(Random() * MAX_DECK);
    		G.handCount[p] = floor(Random() * MAX_HAND);
		}
		thisPlayer=0;
		G.whoseTurn= thisPlayer;	
			
		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		
		cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);
		
		newCards=4;

		printf("Test 1: player draws four cards from deck\n");
		//Determine the number of treasure cards in player hand for testG game  
		if (testG.handCount[thisPlayer]==G.handCount[thisPlayer]+ newCards -discarded)
		{
			printf("PASS: test = %d, expected = %d\n",testG.handCount[thisPlayer],G.handCount[thisPlayer]+ newCards -discarded);
			success++;
		}
		else
		{
			printf("FAIL: test = %d, expected = %d\n",testG.handCount[thisPlayer],G.handCount[thisPlayer]+ newCards -discarded);
			failure++;
		}		
		printf("Test 2: One buy is added to the game state\n");
		//Determine if the number of cards in deck is reduced by at least two cards. 
		if (testG.numBuys==G.numBuys + 1)
		{	
			printf("PASS: test = %d, expected = %d\n",testG.numBuys,G.numBuys + 1);
			success++;
		}
		else
		{	
			printf("FAIL: test = %d, expected = %d\n",testG.numBuys,G.numBuys + 1);
			failure++;
		}
		printf("Test 3:Each other player in game draws one card.\n");
		//Determine if the number of cards in deck is reduced by at least two cards. 
		for (p=0; p<numPlayers; p++)		
		{
			if (p!=thisPlayer)
			{
				if(testG.handCount[p]==G.handCount[p]+ 1)
				{
					printf("PASS: test = %d, expected = %d\n",testG.handCount[p],G.handCount[p]+ 1);	
					success++;
				}
				else
				{
					printf("FAIL: test = %d, expected = %d\n",testG.handCount[p],G.handCount[p]+ 1);	
					failure++;
				}		
			} 
		}
	}	
	printf("\nTesting complete \n\n");
	printf("\n*********************Final test results*************************\n");
	printf(" \n Failures:%d, Successes: %d \n",failure,success);
	printf("\n***************************************************************\n");
	return 0;
}


