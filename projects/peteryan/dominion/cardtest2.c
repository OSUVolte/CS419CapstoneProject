/*
Author: Ryan Peters
Date: 04/21/16
Description: Unit test for playAdventurer().  Test the adventure card effect.
Test for eit code 0.  Test that two cards are added to player's hand.  Tests 
if treasure cards are added to hand.
*/

#include<stdio.h>
#include<string.h>
#include "dominion.h"

void testPlayAdventurer()
{
	int seed = 100;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
                remodel, smithy, village, baron, great_hall};
	struct gameState state;
	int r;
	int i;
	int numPlayer = 2;
	int player;
	
	/*Tests that two cards are in the players hand*/
	memset(&state, 0, sizeof(struct gameState));  
    initializeGame(numPlayer, k, seed, &state);
	player = 1;	
	state.handCount[player] = 3;
	r = playAdventurer(player, &state);
	if(state.handCount[player] == 5)
		printf("playAdventurer: PASS two cards added to player hand.\n");
	else
		printf("playAdventurer: FAIL two cards added to player hand.\n");
	if(r == 0)
		printf("playAdventurer: PASS exit code 0.\n");
	else
		printf("playAdventurer: FAIL exit code 0.\n");
	
	/*Check is treasure is added to hand*/
	memset(&state, 0, sizeof(struct gameState));   
    initializeGame(numPlayer, k, seed, &state);
	int treasureAdded = 0;
	player = 1;	
	state.handCount[player] = 3;  //add cards that are not treasure cards.
	for(i = 0; i < 3; i++)
	{
		state.hand[player][i] = adventurer;
	}
	r = playAdventurer(player, &state);
	for(i = 0; i < state.handCount[player]; i++)
	{
		if(state.hand[player][i] == copper || state.hand[player][i] == silver || state.hand[player][i] == gold)
		{
			treasureAdded++;
		}
	}
	if(treasureAdded == 2)
		printf("playAdventurer: PASS draw two treasure cards.\n");
	else
		printf("playAdventurer: FAIL draw two treasure cards.\n");
	
	/*Test other players do not draw cards*/
	player = 1;	
	state.handCount[player] = 3;
	state.deckCount[player] = 10;
	state.handCount[0] = 3;
	state.deckCount[0] = 10;
	state.playedCardCount = 0;
	r = playAdventurer(player, &state);
	if(state.handCount[0] == 3)
		printf("playAdventurer: PASS other player did not draw card.\n");
	else
		printf("playAdventurer: FAIL other player did not draw card.\n");
	if(state.deckCount[0] == 10)
		printf("playAdventurer: PASS other player did not draw card.\n");
	else
		printf("playAdventurer: FAIL other player did not draw card.\n");
	
	/*Test palyers discards cards*/
	player = 1;	
	state.handCount[player] = 3;
	state.deckCount[player] = 10;
	state.handCount[0] = 3;
	state.deckCount[0] = 10;
	state.playedCardCount = 0;
	state.discardCount[player] = 0;
	r = playAdventurer(player, &state);
	if(state.discardCount[player] > 0)
		printf("playAdventurer: PASS player discarded cards.\n");
	else
		printf("playAdventurer: FAIL player discarded cards.\n");
	for(i = 0; i < state.discardCount[player]; i++)
	{
		if(state.discard[player][i] == copper || state.discard[player][i] == silver || state.discard[player][i] == gold)
			printf("playAdventurer: FAIL treasure discarded.\n");
		else
			printf("playAdventurer: PASS treasure not discarded.\n");
	}
}	

int main(int argc, char *argv[])
{
    testPlayAdventurer();
    return 0;
}