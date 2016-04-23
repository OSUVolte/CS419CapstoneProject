/*
Author: Ryan Peters
Date: 04/20/16
Description: Unit test for gainCard().  Tests using five players.  Test
conditions for the function to fail.  Test the adding cards to the player
deck, hand, and discard pile.  Test removing card from the supply stack.
*/
#include<stdio.h>
#include "dominion.h"

void testGainCard()
{
	int i;
	int r;
	struct gameState state;
	
	/*Add cards to the stack*/
	for(i = 0; i <= treasure_map; i++)
	{
		state.supplyCount[i] = 5;
	}
	
	/*run tests for five players, one more than max*/
	for(i = 0; i < 5; i++)
	{
		/*Test trying to get card from an empty stack*/
		state.supplyCount[1] = 0;
		r = gainCard(1, &state, 1, i);
		if(r == -1)
			printf("gainCard: PASS empty stack, player %d.\n", i);
		else
			printf("gainCard: FAIL empty stack, player %d.\n", i);
		
		/*Test trying to get card from stack*/
		state.supplyCount[1] = 5;
		r = gainCard(1, &state, 1, i);
		if(r == 0)
			printf("gainCard: PASS gain card, player %d.\n", i);
		else
			printf("gainCard: FAIL gain card, player %d.\n", i);
		
		/*Test adding card to player deck*/
		state.supplyCount[1] = 5;
		state.deckCount[i] = 0;
		gainCard(1, &state, 1, i);
		if(state.deckCount[i] == 1)
			printf("gainCard: PASS add card to player %d deck.\n", i);
		else
			printf("gainCard: FAIL add card to player %d deck.\n", i);
		
		/*Test adding card to player hand*/
		state.supplyCount[1] = 5;
		state.handCount[i] = 0;
		gainCard(1, &state, 2, i);
		if(state.handCount[i] == 1)
			printf("gainCard: PASS add card to player %d hand.\n", i);
		else
			printf("gainCard: FAIL add card to player %d hand.\n", i);
		
		/*Test adding card to player discard, positive flag*/
		state.supplyCount[1] = 5;
		state.discardCount[i] = 0;
		gainCard(1, &state, 3, i);
		if(state.discardCount[i] == 1)
			printf("gainCard: PASS add card to player %d discard, positive flag.\n", i);
		else
			printf("gainCard: FAIL add card to player %d discard, positive flag.\n", i);
		
		/*Test adding card to player discard, negative flag*/
		state.supplyCount[1] = 5;
		state.discardCount[i] = 0;
		gainCard(1, &state, -1, i);
		if(state.discardCount[i] == 1)
			printf("gainCard: PASS add card to player %d discard, negative flag.\n", i);
		else
			printf("gainCard: FAIL add card to player %d discard, negative flag.\n", i);
	}
	
	/*Test card is removed from supply stack*/
	state.supplyCount[1] = 5;
	gainCard(1, &state, 1, 1);
	if(state.supplyCount[1] == 4)
		printf("gainCard: PASS remove from supply stack.\n");
	else
		printf("gainCard: FAIL remove from supply stack.\n");
	
	/*Test using invalid card*/
	state.supplyCount[27] = 5;
	gainCard(27, &state, 1, 1);
	if(state.supplyCount[27] == 4)
		printf("gainCard: PASS using invalid card.\n");
	else
		printf("gainCard: FAIL using invalid card.\n");
}

int main(int argc, char *argv[])
{
    testGainCard();
    return 0;
}