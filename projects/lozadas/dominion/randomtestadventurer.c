/* -----------------------------------------------------------------------
*Name: Suyana Lozada 
*Assignment #4
*CS 362
*Reference:testUpdateCoins.c cardtest4.c testDrawCard.c 
*Test description:
*1.Test player hand contains two treasure cards after drawing adventurer card.
*2.Test if deck was decreased by 2.
*3.Test other player hand remains unchanged.
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
	
	printf("*****************Randon Testing Adventurer Card******************\n\n");
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
		
		cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
		printf("Test 1: player draws two treasury cards from deck\n");
		//Determine the number of treasure cards in player hand for testG game  
		for(i=0;i<testG.handCount[thisPlayer];i++)
		{
			if (testG.hand[thisPlayer][i]==copper|| testG.hand[thisPlayer][i]== silver|| testG.hand[thisPlayer][i]==gold)
				treasure++;
		}
		//Determine number of treasure cards in	player hand for G game
		for(i=0;i<G.handCount[thisPlayer];i++)
		{
			if (G.hand[thisPlayer][i]==copper|| G.hand[thisPlayer][i]== silver|| G.hand[thisPlayer][i]==gold)
				expected++;
		}
		//Compare number of expected treasure cards in hand with actual number of treasure cards in players hand.
		if (treasure == expected+extraCoins)
		{
			printf("PASS: test = %d, expected = %d\n",treasure,expected + extraCoins);
			success++;
		}
		else
		{
			printf("FAIL: test = %d, expected = %d\n",treasure,expected + extraCoins);
			failure++;
		}
		printf("Test 2: determine if deck count is decreased by at least 2 cards\n");
		//Determine if the number of cards in deck is reduced by at least two cards. 
		if (testG.deckCount[thisPlayer]<=G.deckCount[thisPlayer]-2)
		{
			printf("PASS: test = %d <= expected = %d\n",testG.deckCount[thisPlayer],G.deckCount[thisPlayer]-2);
			success++;
		}		
		else
		{
			printf("FAIL: test = %d > expected = %d\n",testG.deckCount[thisPlayer],G.deckCount[thisPlayer]-2);
			failure++;
		}	
		printf("Test 3: determine if other players hands remain unchanged.\n");
		//Loop over players in game and determine if hand remains intact after adventurer card is drawn by thisPlayer
		for (p=0; p<numPlayers; p++)		
		{
			if (p!=thisPlayer)
			{
				if(testG.handCount[p]==G.handCount[p])
				{
					printf("PASS: test = %d , expected = %d\n",testG.handCount[p],G.handCount[p]);
					success++;
				}
				else
				{
					printf("PASS: test = %d , expected = %d\n",testG.handCount[p],G.handCount[p]);
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


