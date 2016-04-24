//Ellard Gerritsen van der Hoop
//CS362 Card Test 3 - 




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
	int seed = 100;
	int k[10] = {adventurer, council_room,feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState state, testState;
	int totalBugs = 0; 
	

	initializeGame(numPlayers, k, seed, &state);
	int currentPlayer = whoseTurn(&state);
	memcpy(&testState, &state, sizeof(struct gameState));
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("Card Test 3 - Council Room Card\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n");

	printf("BEFORE CARD EFFECT\n");	
	printf("Number of Buys for P1: %d\n", state.numBuys);
	printf("Council Cards in Game: %d\n", state.supplyCount[council_room]);
	printf("Cards in Hand: %d\n", state.handCount[currentPlayer]);
	printf("Cards in Hand for P2: %d\n", state.handCount[1]);


	printf("\n\nAFTER Card Effect- Council Room Occurs\n");
	cardEffect(council_room, choice1, choice2, choice2, &state, 0, 0); 
	//--------------------------------Test 1 ------------------------------/
	//test to see if 4 cards are drawn
	printf("Number of Cards in Hand: %d    Expected: %d\n", state.handCount[currentPlayer], testState.handCount[currentPlayer] + 3);

	if (state.handCount[currentPlayer] != testState.handCount[currentPlayer] + 3)
	{
		printf("ERROR: Incorrect Number of Cards in hand");
		totalBugs++;
	}


	//test to see if number of Buys increased
	printf("Number of Buys: %d     Expected: %d\n", state.numBuys, testState.numBuys+1);

	if (state.numBuys != testState.numBuys+1)
	{
		printf("ERROR: Incorrect Number of Buys");
		totalBugs++;

	}	
	
	
	//Check to see if card was played
	printf("Number of Cards Played so Far: %d    Expected: %d\n", state.playedCardCount, testState.playedCardCount+1);

	if (state.playedCardCount != testState.playedCardCount + 1)
	{
		printf("ERROR: Incorrect Number of Played Cards");
		totalBugs++;
	}
	//Check Other Player 
	
	//Council Room also gives 1 card to every other player besides the currentPlayer
	printf("Number of Cards in Hand of P2: %d     Expected: %d\n", state.handCount[1], testState.handCount[1] +1);

	if (state.handCount[1] != testState.handCount[1] + 1)
	{
		printf("ERROR: Incorrect Number of Cards in Hand for P2");
		totalBugs++;

	}


	
	//----------------------------------------------Test 2 -------------------------------------------------//
	
	printf("\n\n Test 2: Adding a third player\n");
	numPlayers = 3;
	initializeGame(numPlayers, k, seed, &state);
	memcpy(&testState, &state, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice2, &state, 0, 0); 
	int i = 0;
	int playerError = 0;

	printf("Checking for Proper HandCounts after Card Effect\n");
	for (i = 0; i < state.numPlayers; i++)
	{
		if (i != currentPlayer)
		{
			if (state.handCount[i] != testState.handCount[i] + 1){
				printf("ERROR: Incorrect Number Of Cards in Hand for Player %d\n", i);
				totalBugs++;
				playerError = 0;
			}
		}
	

	}	

	if (playerError == 0)
	{
		printf("PASS\n");
	}

	if (totalBugs != 0)
	{
		printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("Council Card test- FAIL \n");
		printf("Total Bugs: %d\n", totalBugs);
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}
	else
	{
		printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("Council  Card test - PASS \n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	
	}








	return 0;
}
