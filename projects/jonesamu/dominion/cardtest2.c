/*
Sam Jones
Date: 04/25/16
Description: playAdventurer() Unit test.  
- Test the adventure card effect.
- test that it returns 0
- Test that two cards are added to player's hand.  

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
	
	/*Tests two cards in the players hand*/
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
	
	/*Check if treasure is added to hand*/
	memset(&state, 0, sizeof(struct gameState));   
    initializeGame(numPlayer, k, seed, &state);
	int treasureAdded = 0;
	player = 1;	
	state.handCount[player] = 3;  
	for(i = 0; i < 3; i++)
	{
		state.hand[player][i] = 1;
	}
	r = playAdventurer(player, &state);
	for(i = 0; i < 3; i++)
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
}

int main(int argc, char *argv[])
{
    testPlayAdventurer();
    return 0;
}