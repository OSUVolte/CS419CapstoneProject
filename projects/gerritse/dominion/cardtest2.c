//Ellard Gerritsen van der Hoop
//CS362 Card Test 2 - Adventurer
//
//
//
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
	int seed = 103;
	int k[10] = {adventurer, council_room,feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState state, testState;
	int totalBugs = 0; 
	

	initializeGame(numPlayers, k, seed, &state);
	int currentPlayer = whoseTurn(&state);
	memcpy(&testState, &state, sizeof(struct gameState));
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("Card Test 2 - Adventurer Card\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n");

	
	 
	//Giving a guaranteed smithy to both players


//	printf("5 Cards in Hand for player with at least 1 Adventurer\n");
//	state.hand[currentPlayer][4] = adventurer; // Gives a guaranteed adventurer for testing in last slot of hand
	printf("BEFORE CARD EFFECT\n");
	printf("Deck Count at Start: %d\n", state.deckCount[currentPlayer]);
	printf("Cards Played so far : %d\n", state.playedCardCount);
	printf("Adventurer Cards in Game: %d\n", state.supplyCount[adventurer]);
	printf("Cards in Hand: %d\n", state.handCount[currentPlayer]);
	



	cardEffect(adventurer, choice1, choice2, choice2, &state, 0, 0); 
	printf("AFTER CARD EFFECT- Adventurer\n");
	//Test to see how many cards were added to hand
	printf("Number of cards Drawn: %d   \n", state.handCount[currentPlayer]); 

	//Remember that the Adventurer is supposed to draw until 2 treasure cards are found\n");
	//Then discard the rest\n");
		
	int i = 0;

	printf("Cards in Hand: %d    Expected: %d", state.handCount[currentPlayer], testState.handCount[currentPlayer] +1);	
	//The count should be the amount only be 6.
	//5(hand count)  - 1(used adventurer card)  + 2(drawn treasures)
	if (state.handCount[currentPlayer] !=  testState.handCount[currentPlayer] + 1)
	{
		totalBugs++;
		printf("\nERROR: Hand Count is off for Player 1\n");
		
	}
	else
		printf("                     PASS\n");

	
	//Test to see that 3 cards were removed from players pile
	printf("Number of cards in Deck Pile after Card Effect: %d", state.deckCount[currentPlayer]); 


	if (state.deckCount[currentPlayer] == 0)
	{
		totalBugs++;
		printf("\nERROR: Deck count is off for Player. Should have been shuffled if 0\n");
	}
	else
		printf("                     PASS\n");

	

	//-----------------------------------TEST 2 ------------------------
	//Check to see if any treasure cards were discarded
	
	printf("Testing to see if Supply Counts are still the same\n");	
	printf("Supply Count Copper: %d\n", state.supplyCount[copper]);
	if (state.supplyCount[copper] == testState.supplyCount[copper])
		printf("PASS\n");
	printf("Supply Count Silver: %d\n", state.supplyCount[silver]);
	if (state.supplyCount[silver] == testState.supplyCount[silver])
		printf("PASS\n");
	printf("Supply Count Gold: %d\n", state.supplyCount[gold]);
	if (state.supplyCount[gold] == testState.supplyCount[gold])
		printf("PASS\n");

	if (state.supplyCount[copper] != testState.supplyCount[copper] || state.supplyCount[silver] != testState.supplyCount[silver] || state.supplyCount[gold] != testState.supplyCount[gold]){
		totalBugs++;
		printf("ERROR: Supply Count shouldnt have changed for copper,silver,gold\n");

	}
	else
		printf("PASS\n");

	printf("Since the treasures drawn are technically not cards being bought, the supply count shouldnt change for any\n");

	//Check Player Card Count
	//
	
	printf("Number of cards played: %d    Expected: %d ", state.playedCardCount,testState.playedCardCount+1);
	if (state.playedCardCount != testState.playedCardCount + 1)
	{
		totalBugs++;
		printf("\nERROR: Played Card Count is incorrect\n");
	}
	else
		printf("                          PASS\n");
	

	//
	//	
	//Test to see no state change occured for other player
	//
	//	
	printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("Checking the state of other player\n");

	printf("Initial DeckCount for P2: %d\n", testState.deckCount[1]);
	printf("Initial HandCount for P2: %d\n", testState.handCount[1]);
	printf("Initial DiscardCount for P2: %d\n", testState.discardCount[1]);

	printf("DeckCount of P2 After P1's Adventurer Card: %d", state.deckCount[1]);
	if (state.deckCount[1] != testState.deckCount[1])
	{
		totalBugs++;
		printf("\nERROR: Deck count off. It should not be changed for P2 on P1's action\n"); 
	}
	else
		printf("                       PASS\n");
	printf("HandCount of P2 After P1's Adventurer Card: %d", state.handCount[1]);
	if (state.handCount[1] != testState.handCount[1])
	{
		totalBugs++;
		printf("\nERROR: Other player's hand count cahnged when it shouldnt have\n");
	}
	else
		printf("                          PASS\n");

	printf("DiscardCount of P2 After P1's Adventurer Card: %d", state.discardCount[1]);
	if (state.discardCount[1] != testState.discardCount[1])
	{
		totalBugs++;
		printf("\nERROR: Other play has active discarded cards when it never had a turn\n");
	}
	else
		printf("                        PASS\n");

	

	printf("Checking Supply Count of Adventuer in Deck\n");
	
	printf("Number Left in Deck: %d     Expected:  10\n", state.supplyCount[smithy]);
	printf("Note: 10 is acceptable  since it means noting happened to the supplyCount during action");
	if (state.supplyCount[adventurer] != 10)
	{
		totalBugs++;
		printf("\nERROR: Incorrect Count of Adventurer Cards Left\n");

	}
	else
		printf("                   PASS\n");
	

	
	///TEst 2 - TEst to see if Shuffle Deck happens 






	if (totalBugs != 0)
	{
		printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("Adventurer Card test- FAIL \n");
		printf("Total Bugs: %d\n", totalBugs);
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}
	else
	{
		printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("Adventurer Card test - PASS \n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	
	}





















	return 0;
}
