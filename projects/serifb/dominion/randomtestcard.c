/*
	Bryan Serif
	CS 362
	05/

	This file rnadomly tests the Smithy Card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

struct Player {
	int preTreasureCount;
	int preActions;
	int preBuys;
	int preCoins;
	int preHandCount;
	int preDeckCount;
	int preDiscardCount;
	int postTreasureCount;
	int postActions;
	int postBuys;
	int postCoins;
	int postHandCount;
	int postDeckCount;
	int postDiscardCount;
};

struct Errors {
	int actionsErrors;
	int buysErrors;
	int coinsErrors;
	int handCountErrors;
	int treasureCountErrors;
	int remainingCardCountErrors;
	int opponentHandErrors;
	int opponentDeckErrors;
	int opponentDiscardErrors;
	int runErrors;
};
void ErrorSet (struct Errors *E);

struct TotalErrors {
	int totalActionsErrors;
	int totalBuysErrors;
	int totalCoinsErrors;
	int totalHandCountErrors;
	int totalTreasureCountErrors;
	int totalremainingCardCountErrors;
	int totalOpponentHandErrors;
	int totalOpponentDeckErrors;
	int totalOpponentDiscardErrors;
	int totalTestErrors;
};
void TotalErrorSet (struct TotalErrors *TE);
void CombineErrors(struct Errors *E, struct TotalErrors *TE);

int main()
{
	struct gameState G;
	struct Player P;
	struct Errors E;
	struct TotalErrors TE;
	int i, j;	//loop controllers
	int r;	//for game initialization
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = { adventurer, embargo, village, great_hall, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	srand(time(NULL));	
	int randCard;
	int successfulRuns = 0;
	/* -----Opponent Grid-----
					 0			1			 2
	0 player 2   handCount	deckCount   discardCount
	1 player 3   handCount	deckCount   discardCount
	2 player 4   handCount	deckCount   discardCount
	*/
	int opponentPreGrid[MAX_PLAYERS - 1][3];
	
	//set total errors for run
	TotalErrorSet (&TE);
	
	printf("\n-----STARTING TESTING FOR SMITHY-----	\n");
	for (i = 0; i < 100; i++)
	{
		printf("\n---TEST %d---\n", (i+1));
		//initialize game
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayers, k, seed, &G);
		//check to make sure game initialized properly
		if (r < 0)
		{
			printf("Game Initialization Failed!\n");
			exit(-1);
		}
		
		//randomize game
		do{			
			// set the counters
			P.preTreasureCount = 0;
			
			//randomize player hand
			G.handCount[0] = rand() % MAX_HAND;
			P.preHandCount = G.handCount[0];
			printf("Pre Hand Count: %d\n", P.preHandCount);
			//set the first card as adventurer
			G.hand[0][0] = smithy;
			for (j = 1; j < P.preHandCount; j++)
			{
				randCard = rand() % 27;
				G.hand[0][j] = randCard;
				if (randCard == copper || randCard == silver || randCard == gold)
				{
					P.preTreasureCount++;
				}
			}
			
			//randomize player deck
			G.deckCount[0] = rand() % (MAX_DECK - P.preHandCount);
			P.preDeckCount = G.deckCount[0];
			printf("Pre Deck Count: %d\n", P.preDeckCount);
			for (j = 0; j < P.preDeckCount; j++)
			{
				randCard = rand() % 27;
				G.hand[0][j] = randCard;
				if (randCard == copper || randCard == silver || randCard == gold)
				{
					P.preTreasureCount++;
				}
			}
			
			//randomize player discard
			G.discardCount[0] = rand() % (MAX_DECK - P.preHandCount - P.preDeckCount + 1);
			P.preDiscardCount = G.discardCount[0];
			printf("Pre Discard Count: %d\n", P.preDiscardCount);
			for (j = 0; j < P.preDiscardCount; j++)
			{
				randCard = rand() % 27;
				G.hand[0][j] = randCard;
				if (randCard == copper || randCard == silver || randCard == gold)
				{
					P.preTreasureCount++;
				}
			}
			//treasure total
			printf("Pre Treasure Count: %d\n", P.preTreasureCount);
			
			//randomize actions, buys, and coins
			G.numActions = rand() % 100;
			P.preActions = G.numActions;
			printf("Pre Hand Count: %d\n", P.preActions);
			G.numBuys = rand() % 100;
			P.preBuys = G.numBuys;
			printf("Pre Hand Count: %d\n", P.preBuys);
			G.coins = rand() % 100;
			P.preCoins = G.coins;
			printf("Pre Hand Count: %d\n", P.preCoins);
			
			//get opponent pre-conditions
			for (j = 1; j < numPlayers; j++)
			{
				opponentPreGrid[j][0] = G.handCount[j];
				printf("Opponent %d Pre Hand Count: %d\n", (j + 1), opponentPreGrid[j][0]);
				opponentPreGrid[j][1] = G.deckCount[j];
				printf("Opponent %d Pre Hand Count: %d\n", (j + 1), opponentPreGrid[j][1]);
				opponentPreGrid[j][2] = G.discardCount[j];
				printf("Opponent %d Pre Hand Count: %d\n", (j + 1), opponentPreGrid[j][2]);
			}
			
			if ((P.preDeckCount + P.preDiscardCount) < 10)
				printf("---Did not randomize properly. Trying again---\n");
			
		}while ((P.preDeckCount + P.preDiscardCount) < 10);
		
		//set the errors struct for the run
		ErrorSet(&E);
		
		//play the card
		cardEffect(smithy, 0, 0, 0, &G, 0, 0);
		
		//check the conditions
		//check actions first
		P.postActions = G.numActions;
		if(P.postActions != P.preActions)
		{
			printf("Expected Action Count: %d. Actual: %d. Failed!\n", 
			P.preActions, P.postActions);
			E.actionsErrors++;
			E.runErrors++;
		}
		
		//check the number of buys
		P.postBuys = G.numBuys;
		if(P.postBuys != P.preBuys)
		{
			printf("Expected Buy Count: %d. Actual: %d. Failed!\n", 
			P.preBuys, P.postBuys);
			E.buysErrors++;
			E.runErrors++;
		}
		
		//check coins
		P.postCoins = G.coins;
		if(P.postCoins != P.preCoins)
		{
			printf("Expected Coin Count: %d. Actual: %d. Failed!\n", 
			P.preCoins, P.postCoins);
			E.coinsErrors++;
			E.runErrors++;
		}
		
		//set the counter for post treasure
		P.postTreasureCount = 0;
		//set the post conditions for hand, deck, and discard
		P.postHandCount = G.handCount[0];
		P.postDeckCount = G.deckCount[0];
		P.postDiscardCount = G.discardCount[0];
		
		//check the hand, deck, and discard conditions. Hand should increase by 1
		// and deck + discard should decrease by 1
		// hand count
		if (P.postHandCount != P.preHandCount + 1)
		{
			printf("Expected Hand Count: %d. Actual: %d. Failed!\n", 
			P.preHandCount  + 1, P.postHandCount);
			E.handCountErrors++;
			E.runErrors++;
		}
		
		//deck count + discard count
		if ((P.postDeckCount + P.postDiscardCount) != (P.preDeckCount + P.preDiscardCount - 1));
		{
			printf("Expected Deck and Discard Count: %d. Actual: %d. Failed!\n", 
			(P.preDeckCount + P.preDiscardCount - 1), (P.postDeckCount + P.postDiscardCount));
			E.remainingCardCountErrors++;
			E.runErrors++;
		}
		//count through hand, deck, and discard for treasure cards verify count
		// hand treasure
		for (j = 0; j < P.postHandCount; j++)
		{
			if (G.hand[0][j] == copper || G.hand[0][j] == silver || G.hand[0][j] == gold)
			{
				P.postTreasureCount++;
			}
		}
		//deck treasure count
		for (j = 0; j < P.postDeckCount; j++)
		{
			if (G.hand[0][j] == copper || G.hand[0][j] == silver || G.hand[0][j] == gold)
			{
				P.postTreasureCount++;
			}
		}
		//discard errors
		for (j = 0; j < P.postDiscardCount; j++)
		{
			if (G.hand[0][j] == copper || G.hand[0][j] == silver || G.hand[0][j] == gold)
			{
				P.postTreasureCount++;
			}
		}
		//check the total treasure count
		if(P.postTreasureCount != P.preTreasureCount)
		{
			printf("Expected Post Treasure Count: %d. Actual: %d. Failed!\n",
			P.preTreasureCount, P.postTreasureCount);
			E.treasureCountErrors++;
			E.runErrors++;
		}
		
		//check opponent conditions
		for (j = 1; j < numPlayers; j++)
		{
			if (opponentPreGrid[j][0] != G.handCount[j])
			{
				printf("Expected Opponent %d Post Hand Count: %d. Actual: %d. Failed!\n", 
					(j + 1), opponentPreGrid[j][0]);
					E.opponentHandErrors++;
					E.runErrors++;
			}
			if (opponentPreGrid[j][1] != G.deckCount[j])
			{
				printf("Expected Opponent %d Post Deck Count: %d. Actual: %d. Failed!\n", 
					(j + 1), opponentPreGrid[j][1]);
					E.opponentDeckErrors++;
					E.runErrors++;
			}
			if (opponentPreGrid[j][2] != G.discardCount[j])
			{
				printf("Expected Opponent %d Post Discard Count: %d. Actual: %d. Failed!\n", 
					(j + 1), opponentPreGrid[j][1]);
					E.opponentDiscardErrors++;
					E.runErrors++;
			}
		}
		
		//print tun results
		if (E.runErrors == 0)
		{
			printf("---All Tests Passed---\n");
			printf("---End of Test %d---\n", (i+1));
			successfulRuns++;
		}
		else{
			printf("---Results of Test %d---\n", (i+1));
			printf("Actions Error: %d\n", E.actionsErrors);
			printf("Buys Error: %d\n", E.buysErrors);
			printf("Coins Error: %d\n", E.coinsErrors);
			printf("Hand Count Error: %d\n", E.handCountErrors);
			printf("Treasure Count Error: %d\n", E.treasureCountErrors);
			printf("Deck and Discard Sum Error: %d\n", E.remainingCardCountErrors);
			printf("Opponent Hand Error: %d\n", E.opponentHandErrors);
			printf("Opponent Deck Error: %d\n", E.opponentDeckErrors);
			printf("Opponent Discard Error: %d\n", E.opponentDiscardErrors);
			printf("Total Run Errors: %d\n", E.runErrors);
			
			//sum run errors into total errors
			CombineErrors(&E, &TE);
		}
	}
	//print total results
	printf("\n-----FINISHED TESTING ADVENTURER-----\n");
	printf("---Total Test Results---\n");
	printf("Total Actions Error: %d\n", TE.totalActionsErrors);
	printf("Total Buys Error: %d\n", TE.totalBuysErrors);
	printf("Total Coins Error: %d\n", TE.totalCoinsErrors);
	printf("Total Hand Count Error: %d\n", TE.totalHandCountErrors);
	printf("Total Treasure Count Errors: %d\n", TE.totalTreasureCountErrors);
	printf("Total Deck and Discard Sum Errors: %d\n", TE.totalremainingCardCountErrors);
	printf("Total Opponent Hand Error: %d\n", TE.totalOpponentHandErrors);
	printf("Total Opponent Deck Error: %d\n", TE.totalOpponentDeckErrors);
	printf("Total Opponent Discard Error: %d\n", TE.totalOpponentDiscardErrors);
	printf("Total Testing Errors: %d\n", TE.totalTestErrors);
	printf("Total Successful Runs: %d\n\n\n", successfulRuns);
	return 0;
}
		
		
void ErrorSet(struct Errors *E)
{
	E->actionsErrors = 0;
	E->buysErrors = 0;
	E->coinsErrors = 0;
	E->handCountErrors = 0;
	E->treasureCountErrors = 0;
	E->remainingCardCountErrors = 0;
	E->opponentHandErrors = 0;
	E->opponentDeckErrors = 0;
	E->opponentDiscardErrors = 0;
	E->runErrors = 0;
}

void TotalErrorSet (struct TotalErrors *TE)
{
	TE->totalActionsErrors = 0;
	TE->totalBuysErrors = 0;
	TE->totalCoinsErrors = 0;
	TE->totalHandCountErrors = 0;
	TE->totalTreasureCountErrors = 0;
	TE->totalremainingCardCountErrors = 0;
	TE->totalOpponentHandErrors = 0;
	TE->totalOpponentDeckErrors = 0;
	TE->totalOpponentDiscardErrors = 0;
	TE->totalTestErrors = 0;
}

void CombineErrors(struct Errors *E, struct TotalErrors *TE)
{
	TE->totalActionsErrors += E->actionsErrors;
	TE->totalBuysErrors += E->buysErrors;
	TE->totalCoinsErrors += E->coinsErrors;
	TE->totalHandCountErrors += E->handCountErrors;
	TE->totalTreasureCountErrors += E->treasureCountErrors;
	TE->totalremainingCardCountErrors += E->remainingCardCountErrors;
	TE->totalOpponentHandErrors += E->opponentHandErrors;
	TE->totalOpponentDeckErrors += E->opponentDeckErrors;
	TE->totalOpponentDiscardErrors += E->opponentDiscardErrors;
	TE->totalTestErrors += E->runErrors;
}	
		