/*
Author: Ryan Peters
Date: 04/21/16
Description: Unit test for village card effect.  The village card allows the
player to draw one card and gain 2 actions.  There are test to see if the player
handCount stays the same, the drawn card replacing the village card.  Test that 
the player gains 2 actions.  Tests that the exit code is 0.  Shows that the new
card in the hand is different.
*/

#include<stdio.h>
#include<string.h>
#include "dominion.h"

void testVillage()
{
	int seed = 100;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
                remodel, smithy, village, baron, great_hall};
	struct gameState state;
	int r;
	int i;
	int bonus = 0; //Bonus is not used by village
	int numPlayer = 2;
	int player = 1;
	int handPos;
	
	/*Test card is drawn by player and exit code is 0*/
	memset(&state, 0, sizeof(struct gameState));  
    initializeGame(numPlayer, k, seed, &state);
	handPos = 1;
	state.whoseTurn = player;
	state.numActions = 0;
	state.handCount[player] = 3;
	r = cardEffect(village, 0, 0, 0, &state, handPos, &bonus);
	if(state.handCount[player] == 3)
		printf("villageEffect: PASS net gain 0 cards.\n");
	else
		printf("villageEffect: FAIL net gain 0 cards.\n");
	if(r == 0)
		printf("villageEffect: PASS exit code 0.\n");
	else
		printf("villageEffect: FAIL exit code 0.\n");
	
	/*Test player gains 2 actions*/
	memset(&state, 0, sizeof(struct gameState));  
    initializeGame(numPlayer, k, seed, &state);
	handPos = 1;
	state.whoseTurn = player;
	state.numActions = 0;
	state.handCount[player] = 3;
	r = cardEffect(village, 0, 0, 0, &state, handPos, &bonus);
	if(state.numActions == 2)
		printf("villageEffect: PASS gain 2 actions.\n");
	else
		printf("villageEffect: FAIL gain 2 actions.\n");
	
	/*Test other players did nto draw cards*/
	memset(&state, 0, sizeof(struct gameState));  
    initializeGame(numPlayer, k, seed, &state);
	handPos = 1;
	state.whoseTurn = player;
	state.numActions = 0;
	state.handCount[0] = 3;
	state.deckCount[0] = 10;
	r = cardEffect(village, 0, 0, 0, &state, handPos, &bonus);
	if(state.handCount[0] == 3)
		printf("villageEffect: PASS other player did not draw a card.\n");
	else
		printf("villageEffect: FAIL other player did not draw a card.\n");
	if(state.deckCount[0] == 10)
		printf("villageEffect: PASS other player deck did not change.\n");
	else
		printf("villageEffect: FAIL other player deck did not change.\n");
	
	/*Test village card is replaced with new card*/
	memset(&state, 0, sizeof(struct gameState));  
    initializeGame(numPlayer, k, seed, &state);
	handPos = 1;
	state.whoseTurn = player;
	state.numActions = 0;
	state.handCount[player] = 3;
	state.hand[player][0] = gold;
	state.hand[player][1] = village;
	state.hand[player][2] = silver;
	printf("villageEffect: Hand before play - ");
	for(i = 0; i < 3; i++)
	{
		printf("%d ", state.hand[player][i]);
	}
	printf("\n");
	r = cardEffect(village, 0, 0, 0, &state, handPos, &bonus);
	printf("villageEffect: Hand after play - ");
	for(i = 0; i < 3; i++)
	{
		printf("%d ", state.hand[player][i]);
	}
	printf("\n");
	
	/*Test supply stacks do not change*/
	for(i = 0; i <= treasure_map; i++)
	{
		state.supplyCount[i] = 10;
	}
	player = 1;
	handPos = 0;	
	state.handCount[player] = 3;
	state.deckCount[player] = 10;
	state.handCount[0] = 3;
	state.deckCount[0] = 10;
	state.playedCardCount = 0;
	r = cardEffect(village, 0, 0, 0, &state, handPos, &bonus);
	for(i = 0; i <= treasure_map; i++)
	{
		if(state.supplyCount[i] == 10)
			printf("villageEffect: PASS card to drawn from supply posistion %d.\n", i);
		else
			printf("villageEffect: FAIL  card to drawn from supply posistion %d.\n", i);
	}
}

int main(int argc, char *argv[])
{
    testVillage();
    return 0;
}