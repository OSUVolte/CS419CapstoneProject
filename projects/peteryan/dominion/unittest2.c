/*
Author: Ryan Peters
Date: 04/20/16
Description: Unit test for isGameOver().  Tests check to see if game is
over when there is one of each supply card, when there are different amounts
of supply cards, when there is no supply cards, when only one supply card stack
is empty, when two stacks are empty, when three stack are empty, and when there
is negative amounts in the stacks.
*/

#include<stdio.h>
#include "dominion.h"

void testIsGameOver()
{
	int r;
	int i;
	struct gameState state;
	
	for(i = 0; i < 25; i++)
	{
		state.supplyCount[i] = 1;
	}
	r = isGameOver(&state);
	if(r == 0)
		printf("isGameOver: PASS game is not over.\n");
	else
		printf("isGameOver: FAIL game is not over.\n");
	
	for(i = 0; i < 25; i++)
	{
		state.supplyCount[i] = i + 1;
	}
	r = isGameOver(&state);
	if(r == 0)
		printf("isGameOver: PASS game is not over.\n");
	else
		printf("isGameOver: FAIL game is not over.\n");
	
	state.supplyCount[1] = 0;
	r = isGameOver(&state);
	if(r == 0)
		printf("isGameOver: PASS game is not over.\n");
	else
		printf("isGameOver: FAIL game is not over.\n");
	
	state.supplyCount[20] = 0;
	r = isGameOver(&state);
	if(r == 0)
		printf("isGameOver: PASS game is not over.\n");
	else
		printf("isGameOver: FAIL game is not over.\n");
	
	state.supplyCount[1] = 0;
	state.supplyCount[20] = 0;
	state.supplyCount[12] = 0;
	r = isGameOver(&state);
	if(r == 1)
		printf("isGameOver: PASS game is over.\n");
	else
		printf("isGameOver: FAIL game is over.\n");
	
	for(i = 0; i < 25; i++)
	{
		state.supplyCount[i] = 0;
	}
	r = isGameOver(&state);
	if(r == 1)
		printf("isGameOver: PASS game is over.\n");
	else
		printf("isGameOver: FAIL game is over.\n");
	
	for(i = 0; i < 25; i++)
	{
		state.supplyCount[i] = -1;
	}
	r = isGameOver(&state);
	if(r == 1)
		printf("isGameOver: PASS game is over.\n");
	else
		printf("isGameOver: FAIL game is over.\n");
	
	for(i = 0; i < 25; i++)
	{
		state.supplyCount[i] = 3;
	}
	state.supplyCount[province] = 0;
	r = isGameOver(&state);
	if(r == 1)
		printf("isGameOver: PASS game is over.\n");
	else
		printf("isGameOver: FAIL game is over.\n");
}

int main(int argc, char *argv[])
{
    testIsGameOver();
    return 0;
}