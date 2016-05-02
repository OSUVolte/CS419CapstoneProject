/*
	Bryan Serif
	CS 362
	04/24/2016

	This file randomly tests the Adventurer Card
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
	int preTreasureInHand;
	int preTreasureInDeck;
	int preTreasureInDiscard;
	int preTreasureTotal;
	int preHandGold;
	int preHandSilver;
	int preHandCopper;
	int preActions;
	int preBuys;
	int preCoins;
	int preHandCount;
	int preDeckAndDiscard;
	int postTreasureInHand;
	int postTreasureInDeck;
	int postTreasureInDiscard;
	int postTreasureTotal;
	int postHandGold;
	int postHandSilver;
	int postHandCopper;
	int postActions;
	int postBuys;
	int postCoins;
	int postHandCount;
	int postDeckAndDiscard;
};

struct Errors {
	int actionsErrors;
	int buysErrors;
	int coinsErrors;
	int handCountErrors;
	int handTreasureErrors;
	int deckTreasureErrors;
	int discardTreasureErrors;
	int totalTreasureErrors;
	int deckAndDiscardCountErrors;
	int deckAndDiscardTreasureErrors;
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
	int totalHandTreasureErrors;
	int totalDeckTreasureErrors;
	int totalDiscardTreasureErrors;
	int totalTotalTreasureErrors;
	int totalDeckAndDiscardCountErrors;
	int totalDeckAndDiscardTreasureErrors;
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
	int numErrors;
	srand(time(NULL));	
	int randomHandCount;
	int randomDeckCount;
	int randomDiscardCount;
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
	
	printf("\n-----STARTING TESTING FOR ADVENTURER-----	\n");
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
		numErrors = 0;
		
		//randomize game
		do{			
			// set the counters
			P.preTreasureInDeck = 0;
			P.preTreasureInDiscard = 0;
			P.preTreasureInHand = 0;
			P.preTreasureTotal = 0;
			P.preHandCopper = 0;
			P.preHandSilver = 0;
			P.preHandGold = 0;
			
			//randomize player hand
			G.handCount[0] = rand() % MAX_HAND;
			P.preHandCount = G.handCount[0];
			printf("Pre Hand Count: %d\n", P.preHandCount);
			//set the first card as adventurer
			G.hand[0][0] = adventurer;
			for (j = 1; j < P.preHandCount; j++)
			{
				randCard = rand() % 27;
				G.hand[0][j] = randCard;
				if (randCard == copper)
				{
					P.preTreasureInHand++;
					P.preTreasureTotal++;
					P.preHandCopper++;
				}
				else if (randCard == silver)
				{
					P.preTreasureInHand++;
					P.preTreasureTotal++;
					P.preHandSilver++;
				}
				else if(randCard == gold)
				{
					P.preTreasureInHand++;
					P.preTreasureTotal++;
					P.preHandGold++;
				}
			}
			printf("Pre Treasure in Hand: %d\n", P.preTreasureInHand);
			printf("Pre Copper in Hand: %d\n", P.preHandCopper);
			printf("Pre Silver in Hand: %d\n", P.preHandSilver);
			printf("Pre Gold in Hand: %d\n", P.preHandGold);
			
			//randomize player deck
			G.deckCount[0] = rand() % (MAX_DECK - P.preHandCount);
			randomDeckCount = G.deckCount[0];
			printf("Pre Deck Count: %d\n", randomDeckCount);
			for (j = 0; j < randomDeckCount; j++)
			{
				randCard = rand() % 27;
				G.hand[0][j] = randCard;
				if (randCard == copper)
				{
					P.preTreasureInDeck++;
					P.preTreasureTotal++;
				}
				else if (randCard == silver)
				{
					P.preTreasureInDeck++;
					P.preTreasureTotal++;
				}
				else if(randCard == gold)
				{
					P.preTreasureInDeck++;
					P.preTreasureTotal++;
				}
			}
			printf("Pre Treasure in Deck: %d\n", P.preTreasureInDeck);
			
			//randomize player discard
			G.discardCount[0] = rand() % (MAX_DECK - P.preHandCount - randomDeckCount + 1);
			randomDiscardCount = G.discardCount[0];
			printf("Pre Discard Count: %d\n", randomDiscardCount);
			for (j = 0; j < randomDiscardCount; j++)
			{
				randCard = rand() % 27;
				G.hand[0][j] = randCard;
				if (randCard == copper)
				{
					P.preTreasureInDiscard++;
					P.preTreasureTotal++;
				}
				else if (randCard == silver)
				{
					P.preTreasureInDiscard++;
					P.preTreasureTotal++;
				}
				else if(randCard == gold)
				{
					P.preTreasureInDiscard++;
					P.preTreasureTotal++;
				}
			}
			//get total of deck and discard
			P.preDeckAndDiscard = (randomDeckCount + randomDiscardCount);
			printf("Pre Treasure in Discard: %d\n", P.preTreasureInDiscard);
			printf("Pre Treasure Total: %d\n", P.preTreasureTotal);
			
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
			
			if ((P.preTreasureInDeck + P.preTreasureInDiscard) < 3)
				printf("---Did not randomize properly. Trying again---\n");
			
		}while ((P.preTreasureInDeck + P.preTreasureInDiscard) < 3);
		
		//set the error counts for the individual run
		ErrorSet(&E);
		
		//play the card
		G.whoseTurn = 0;
		cardEffect(adventurer, 0, 0, 0, &G, 0, 0);
		
		//check the player outcomes
		//check player actions
		P.postActions = G.numActions;
		if (P.postActions != P.preActions)
		{
			printf("Expected Actions: %d. Actual: %d. Failed!\n", (P.preActions - 1), P.postActions);
			E.actionsErrors++;
			E.runErrors++;
		}		
		//check player buys
		P.postBuys = G.numBuys;
		if (P.preBuys != P.postBuys)
		{
			printf("Expected Buys: %d. Actual: %d. Failed!\n", P.preBuys, P.postBuys);
			E.buysErrors++;
			E.runErrors++;
		}						
		//check player hand
		P.postHandCount = G.handCount[0];
		if (P.postHandCount != (P.preHandCount + 2))
		{
			printf("Expected Hand Count: %d. Actual: %d. Failed!\n", P.preHandCount + 1, P.postHandCount);
			E.handCountErrors++;
			E.runErrors++;
		}
		//zero out counters
		P.postTreasureInHand = 0;
		P.postTreasureInDeck = 0;
		P.postTreasureInDiscard = 0;
		P.postTreasureTotal = 0;
		P.postHandCopper = 0;
		P.postHandSilver = 0;
		P.postHandGold = 0;
		//count treasure in hand for the last two cards as they were the ones added
		for (j = 0; j < P.postHandCount; j++)
		{
			if (G.hand[0][j] == copper)
			{
				P.postTreasureInHand++;
				P.postTreasureTotal++;
				P.postHandCopper++;
			}
			else if (G.hand[0][j] == silver)
			{
				P.postTreasureInHand++;
				P.postTreasureTotal++;
				P.postHandSilver++;
			}
			else if(G.hand[0][j] == gold)
			{
				P.postTreasureInHand++;
				P.postTreasureTotal++;
				P.postHandGold++;
			}
		}
		//check player coins
		P.postCoins = G.coins;
		if (P.postCoins != P.preCoins)
			{
			printf("Expected Coins: %d. Actual: %d. Failed!\n", P.preCoins, P.postCoins);
			E.coinsErrors++;
			E.runErrors++;
		}
		// compare the pre and post hand treasure
		if (P.postTreasureInHand != (P.preTreasureInHand + 2))
		{
			printf("Expected Treasure in Hand: %d. Actual: %d. Failed!\n",(P.preTreasureInHand + 2),P.postTreasureInHand);
			E.handTreasureErrors++;
			E.runErrors++;
		}
		//check player deck and discard for treasure cards and count
		P.postDeckAndDiscard = (G.deckCount[0] + G.discardCount[0]);
		if (P.postDeckAndDiscard != (P.preDeckAndDiscard - 1))
		{
			printf("Expected total of Deck and Discard: %d. Actual: %d. Failed!\n",(P.preDeckAndDiscard - 1),P.postDeckAndDiscard);
			E.deckAndDiscardCountErrors++;
			E.runErrors++;
		}
		//sum the treasure cards in deck and discard
		for (j = 0; j < G.deckCount[0]; j++)
		{
			if (G.discard[0][j] == copper)
			{
				P.postTreasureInDeck++;
				P.postTreasureTotal++;
			}
			else if (G.discard[0][j] == silver)
			{
				P.postTreasureInDeck++;
				P.postTreasureTotal++;
			}
			else if(G.discard[0][j] == gold)
			{
				P.postTreasureInDeck++;
				P.postTreasureTotal++;
			}
		}
		for (j = 0; j < G.discardCount[0]; j++)
		{
			if (G.discard[0][j] == copper)
			{
				P.postTreasureInDiscard++;
				P.postTreasureTotal++;
			}
			else if (G.discard[0][j] == silver)
			{
				P.postTreasureInDiscard++;
				P.postTreasureTotal++;
			}
			else if(G.discard[0][j] == gold)
			{
				P.postTreasureInDiscard++;
				P.postTreasureTotal++;
			}
		}
		//compare the treasure card totals for deck and discard
		if (P.postTreasureTotal != P.preTreasureTotal)
		{
			printf("Expected Total Treasure: %d. Actual: %d. Failed!\n", 
					P.preTreasureTotal, P.postTreasureTotal);
			E.totalTreasureErrors++;
			E.runErrors++;
		}
		
		if ((P.postTreasureInDeck + P.postTreasureInDiscard) != (P.preTreasureInDeck + P.preTreasureInDiscard - 2))
		{
			printf("Expected Treasure in Deck and Discard: %d. Actual: %d. Failed!\n",
					(P.preTreasureInDeck + P.preTreasureInDiscard - 2), (P.postTreasureInDeck + P.postTreasureInDiscard));
					E.deckAndDiscardTreasureErrors++;
					E.runErrors++;
		}
		
		//check the opponent outcomes
		//check opponent hands, decks, and discards
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
		
		if (E.runErrors == 0)
		{
			printf("---All Tests Passed---\n");
			printf("---End of Test %d---\n", (i+1));
			successfulRuns++;
		}
		else
		{
			printf("---Results of Test %d---\n", (i+1));
			printf("Actions Error: %d\n", E.actionsErrors);
			printf("Buys Error: %d\n", E.buysErrors);
			printf("Coins Error: %d\n", E.coinsErrors);
			printf("Hand Count Error: %d\n", E.handCountErrors);
			printf("Hand Treasure Error: %d\n", E.handTreasureErrors);
			printf("Deck Treasure Error: %d\n", E.deckTreasureErrors);
			printf("Discard Treasure Error: %d\n", E.discardTreasureErrors);
			printf("Deck and Discard Count Error: %d\n", E.deckAndDiscardCountErrors);
			printf("Deck and Discard Treasure Error: %d\n", E.deckAndDiscardTreasureErrors);
			printf("Total Treasure Error: %d\n", E.totalTreasureErrors);
			printf("Opponent Hand Error: %d\n", E.opponentHandErrors);
			printf("Opponent Deck Error: %d\n", E.opponentDeckErrors);
			printf("Opponent Discard Error: %d\n", E.opponentDiscardErrors);
			printf("Total Run Errors: %d\n", E.runErrors);
			
			CombineErrors(&E, &TE);
		}
	}
	printf("\n-----FINISHED TESTING ADVENTURER-----\n");
	printf("---Total Test Results---\n");
	printf("Total Actions Error: %d\n", TE.totalActionsErrors);
	printf("Total Buys Error: %d\n", TE.totalBuysErrors);
	printf("Total Coins Error: %d\n", TE.totalCoinsErrors);
	printf("Total Hand Count Error: %d\n", TE.totalHandCountErrors);
	printf("Total Hand Treasure Error: %d\n", TE.totalHandTreasureErrors);
	printf("Total Deck Treasure Error: %d\n", TE.totalDeckTreasureErrors);
	printf("Total Discard Treasure Error: %d\n", TE.totalDiscardTreasureErrors);
	printf("Total Deck and Discard Count Error: %d\n", TE.totalDeckAndDiscardCountErrors);
	printf("Total Deck and Discard Treasure Error: %d\n", TE.totalDeckAndDiscardTreasureErrors);
	printf("Total Total Treasure Error: %d\n", TE.totalTotalTreasureErrors);
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
	E->handTreasureErrors = 0;
	E->deckTreasureErrors = 0;
	E->discardTreasureErrors = 0;
	E->totalTreasureErrors = 0;
	E->deckAndDiscardCountErrors = 0;
	E->totalTreasureErrors = 0;
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
	TE->totalHandTreasureErrors = 0;
	TE->totalDeckTreasureErrors = 0;
	TE->totalDeckAndDiscardCountErrors = 0;
	TE->totalDiscardTreasureErrors = 0;
	TE->totalTotalTreasureErrors = 0;
	TE->totalDeckAndDiscardTreasureErrors = 0;
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
	TE->totalHandTreasureErrors += E->handTreasureErrors;
	TE->totalDeckTreasureErrors += E->deckTreasureErrors;
	TE->totalDeckAndDiscardCountErrors += E->deckAndDiscardCountErrors;
	TE->totalDiscardTreasureErrors += E->discardTreasureErrors;
	TE->totalTotalTreasureErrors += E->totalTreasureErrors;
	TE->totalDeckAndDiscardTreasureErrors += E->deckAndDiscardCountErrors;
	TE->totalOpponentHandErrors += E->opponentHandErrors;
	TE->totalOpponentDeckErrors += E->opponentDeckErrors;
	TE->totalOpponentDiscardErrors += E->opponentDiscardErrors;
	TE->totalTestErrors += E->runErrors;
}