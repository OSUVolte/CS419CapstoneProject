//Ellard Gerritsen van der Hoop
//CS362 Card Test 1 - Smithy
//



#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int numPlayers = 2;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int seed = 1000;
	int k[10] = {adventurer, council_room,feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState state, testState;
	int totalBugs = 0; 
	int previousCountP1 = 0;
	int previousCountP2 = 0;



	initializeGame(numPlayers, k, seed, &state);
	int currentPlayer = whoseTurn(&state);
	state.hand[currentPlayer][0] = smithy;
	memcpy(&testState, &state, sizeof(struct gameState));

	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("Card Test 1 - Smithy Card\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n");

	
	 
	//Giving a guaranteed smithy 
	printf("5 Cards in Hand for player with at least 1 Smithy\n");
//	state.hand[currentPlayer][4] = smithy; // Gives a guaranteed smithy for testing in last slot of hand

	//Some quick information statements for later comparison
	printf("Cards Played so far : %d\n", state.playedCardCount);
	printf("Smithy Cards in Game: %d\n", state.supplyCount[smithy]);

	
	





	//Actually apply cardEffect of Smithy. 
	cardEffect(smithy, choice1, choice2, choice2, &state, 0, 0); 
	
	//Test to see how many cards were added to hand
	printf("Number of cards Drawn: %d    Expected: %d\n", state.handCount[currentPlayer], testState.handCount[currentPlayer] + 2); 


	//We expect 7 Cards. 3 should have been drawn and Smithy discard. 5+3-1= 7
	if (state.handCount[currentPlayer] !=  7)
	{
		totalBugs++;
		printf("ERROR: Hand Count is off for Player 1\n");
	}	


	//Test to see that 3 cards were removed from players pile
	printf("Number of cards in Pile: %d   Expected: %d \n", state.deckCount[currentPlayer], testState.deckCount[currentPlayer]- 3);


	//PreviousCountP1 tracks original count. So new count should be previousCountP1 -3 
	if (state.deckCount[currentPlayer] != testState.deckCount[currentPlayer] - 3)
	{
		totalBugs++;
		printf("ERROR: Deck count is off for Player\n");
	}

	
	printf("Number of cards discarded: %d       Expected: 0\n", state.discardCount[currentPlayer]);

	//This is different than the discard pile.  
	if (state.discardCount[currentPlayer] != 0)
	{
		totalBugs++;
		printf("ERROR: discardCount is off for Player\n");
	}

	//Check Player Card Count
	//
	
	printf("Number of cards played: %d    Expected: %d \n", state.playedCardCount, testState.playedCardCount+1);
	if (state.playedCardCount != 1)
	{
		totalBugs++;
		printf("ERROR: Played Card Count is incorrect\n");
	}

	//
	////
	//Test to see no state change occured for other player
	////
	//
	printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("Checking the state of other player\n");

	if (state.deckCount[1] != testState.deckCount[1])
	{
		totalBugs++;
		printf("ERROR: Deck count off. It should not be changed for P2 on P1's action\n"); 
	}

	if (state.handCount[1] != 0)
	{
		totalBugs++;
		printf("ERROR: Other player has cards in hand when they should have none\n");
	}

	//Remember this is different than the discard pile  and it is always rese to 0 at 
	//the beginning of a turn 
	if (state.discardCount[1] != 0)
	{
		totalBugs++;
		printf("ERROR: Other play has active discarded cards when it never had a turn\n");
	}



	//Test to see that no state change occurred for victory or kingdom cards	

	int i = 0;
	int victoryError = 0;
	printf("Checking Supply Count of Victory Cards\n");

	if (state.supplyCount[estate] != testState.supplyCount[estate]){
		totalBugs++;
		printf("ERROR: Estate Supply Count Off\n");
		victoryError++;
	}

	if (state.supplyCount[duchy] != testState.supplyCount[duchy]){
		totalBugs++;
		printf("ERROR: Duchy Supply Count off\n");
		victoryError++;
	}

	if (state.supplyCount[province] != testState.supplyCount[province]){
		totalBugs++;
		printf("ERROR: Province Supply Count off\n");
		victoryError++;
	}

	printf("Number of Incorrect SupplyCounts of Victory Cards: %d\n", victoryError++);




	printf("Checking Supply Count of Kingdom Cards\n");

	int kingdomError = 0;
	for (i = 0; i < 10; i++)
	{
		if (state.supplyCount[i] != testState.supplyCount[i]){
			totalBugs++;
			kingdomError++;
		}
	}
	printf("Number of Incorrect SupplyCounts of Kingdom Cards: %d\n", kingdomError);
	printf("Checking Supply Count of Smithy in Deck\n");

	printf("Number Left in Deck: %d     Expected:  %d\n", state.supplyCount[smithy], testState.supplyCount[smithy]);
	printf("Note: Since we assigned a smithy card at the beginning of the test, a Smithy Card was never bought.\n");
	printf("Thus 10 is acceptable in this case since it means noting happened to the supplyCount during action\n");
	if (state.supplyCount[smithy] != 10)
	{
		totalBugs++;
		printf("ERROR: Incorrect Count of Smithy Cards Left\n");

	}
	

	







	if (totalBugs != 0)
	{
		printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("Smithy Card test- FAIL \n");
		printf("Total Bugs: %d\n", totalBugs);
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}
	else
	{
		printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("Smithy Card test- PASS \n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}











	return 0;
}
