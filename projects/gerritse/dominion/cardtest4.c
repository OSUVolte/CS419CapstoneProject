//Ellard Gerritsen van der Hoop
//CS362 Card Test 4 - CutPurse


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{

	int numPlayers =2;
	int choice1 = 0;
	int choice2 = 0;
	int seed = 1000;
	int k[10] = {adventurer, cutpurse,feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState state, testState;
	int totalBugs = 0; 
	

	initializeGame(numPlayers, k, seed, &state);
	int currentPlayer = whoseTurn(&state);
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("Card Test 4 - CutpurseCard\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n");

	printf("BEFORE CARD EFFECT\n");	
	
	int j = 0;
	int i = 0;
	int P1copperAmount1 = 0;
	int P2copperAmount1 = 0;


	//Setting Hands for both players
	//

	state.hand[currentPlayer][0] = cutpurse;
	state.hand[currentPlayer][1] = copper;
	state.hand[currentPlayer][2] = copper;
	state.hand[currentPlayer][3] = copper;
	state.hand[currentPlayer][4] = copper;

	state.handCount[1] = 5;
	state.hand[1][0] = copper;
	state.hand[1][1] = copper;
	state.hand[1][2] = copper;
	state.hand[1][3] = copper;
	state.hand[1][4] = copper;





	updateCoins(currentPlayer, &state,0);
	
	memcpy(&testState, &state, sizeof(struct gameState));

	printf("Current Coin Amount: %d\n", state.coins);
	


	for (i = 0; i < state.handCount[currentPlayer]; i++)
	{
		if (state.hand[currentPlayer][i] == copper)
		{
			P1copperAmount1++;
		}

	}	

	for (i = 0; i < state.handCount[1]; i++)
	{
		if (state.hand[1][i] == copper)
		{
			P2copperAmount1++;
		}

	}	
	printf("Amount of Copper in P1's Hand: %d\n", P1copperAmount1);
	printf("Amount of Copper in P2's Hand: %d\n", P2copperAmount1);


	printf("\n\nAFTER Card Effect- Cutpurse Occurs\n");
	cardEffect(cutpurse, choice1, choice2, choice2, &state, 0, 0); 
	//--------------------------------Test 1 ------------------------------/
	// Check for the updateCoins action
	

	printf("Checking Amount of Coins for P1: %d  Expected: %d", state.coins, testState.coins + 2);
	


	if (state.coins == testState.coins + 2)
	{
		printf("               PASS\n");
	

	}
	else
	{
		printf("\nERROR: Incorrect Amount of Coins\n");
		totalBugs++;


	}


	//------------------------------------Test 2------------------------------/
	//Check for Copper Cards
	printf("Checking for Number of Copper Cards in P1 and  Removal of 1 Copper Card from P2's Hand\n");

	int P1copperAmount2 = 0;
	int P2copperAmount2 = 0;

	for (i = 0; i < state.handCount[currentPlayer]; i++)
	{
		if (state.hand[currentPlayer][i] == copper)
		{
			P1copperAmount2++;
		}

	}	

	for (i = 0; i < state.handCount[1]; i++)
	{
		if (state.hand[1][i] == copper)
		{
			P2copperAmount2++;
		}

	}	

	printf("Number of Copper Cards for P1: %d      Expected: %d", P1copperAmount2, P1copperAmount1);
	

	if (P1copperAmount2 == P1copperAmount1)
	{
		printf("                PASS\n");
		
	} 
	else
	{
		
		printf("\nERROR: Copper Cards in hand shouldnt have changed for P1\n");
		totalBugs++;

	}

	printf("Number of Copper Cards for P2: %d      Expected: %d", P2copperAmount2, P2copperAmount1-1);

	if (P2copperAmount2 == P2copperAmount1-1)
	{
		printf("                  PASS\n");
		
	} 
	else
	{
		printf("\nERROR: One copper card should have been removed from P2\n");
		totalBugs++;


	}
	
	//-------------------------------------Test 3 ---------------------------------//
	//Check Supply Counts of Copper


	printf("Checking Supply Count of Copper\n");
	printf("Current Supply Count of Copper:   %d        Expected: %d", state.supplyCount[copper], testState.supplyCount[copper]);


	if (state.supplyCount[copper] == testState.supplyCount[copper])
	{
		printf("                           PASS\n");


	}
	else
	{
		printf("\nERROR: Copper supply count should not have changed\n");
		totalBugs++;

	}

	//----------------------------------------------Test 4 --------------------------->
	//Checking playerCardCount and playedCards
	

	printf("Checking playedCardCount: Remember 2 cards were discarded\n");
	printf("Played Card Count: %d         Expected: %d", state.playedCardCount, testState.playedCardCount +2);


	if (state.playedCardCount == testState.playedCardCount+2)
	{
		printf("		PASS\n");
	

	}
	else
	{
		printf("\nERROR:  Improper playedCardCount\n");
		totalBugs++;
	}



	printf("Checking Played Cards: 4 = Copper,	 21 = Cutpurse\n");
	
	int card1 = 0;
	int card2 = 0;	
	for (i = 0; i < state.playedCardCount;i++)
	{
		if (state.playedCards[i] == 4)
			card1 = 1;

		if (state.playedCards[i] == 21)
			card2 = 1;	
		printf("Card here: %d \n", state.playedCards[i]);
	}

	printf("Card Check Results: ");
	if (card1 == 1 && card2 == 1)
	{
		printf("		PASS\n");
	}
	else
	{
		printf("\nERROR:  Incorrect Cards in played pile\n");
		totalBugs++;
	}

	if (totalBugs != 0)
	{
		printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("Cutpurse test- FAIL \n");
		printf("Total Bugs: %d\n", totalBugs);
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}
	else
	{
		printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("Cutpurse test - PASS \n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	
	}











	return 0;
}
