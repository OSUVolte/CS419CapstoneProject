/*
Sam Jones
Date: 04/25/16
Description: isGameOver() unit test 
- Tests to see if game is over by emptying each stack type.
- Tests what happens is a stack has a negative count.
*/

#include<stdio.h>
#include "dominion.h"

void testIsGameOver()
{
	int r;
	int i;
	struct gameState state;
	
	/*Test when all card stacks have the same number of cards.*/
	for(i = 0; i < 25; i++)
	{
		state.supplyCount[i] = 1;
	}
	r = isGameOver(&state);
	if(r == 0)
		printf("isGameOver: PASS game is not over.\n");
	else
		printf("isGameOver: FAIL game is not over.\n");
	
	/*Test when card piles have different number of cards*/
	for(i = 0; i < 25; i++)
	{
		state.supplyCount[i] = i + 1;
	}
	r = isGameOver(&state);
	if(r == 0)
		printf("isGameOver: PASS game is not over.\n");
	else
		printf("isGameOver: FAIL game is not over.\n");
	
	/*Test when one stack has zero cards.*/
	state.supplyCount[1] = 0;
	r = isGameOver(&state);
	if(r == 0)
		printf("isGameOver: PASS game is not over.\n");
	else
		printf("isGameOver: FAIL game is not over.\n");
	
	/*Test when two stacks have zero cards*/
	state.supplyCount[1] = 0;
	state.supplyCount[20] = 0;
	r = isGameOver(&state);
	if(r == 0)
		printf("isGameOver: PASS game is not over.\n");
	else
		printf("isGameOver: FAIL game is not over.\n");
	
	/*Test when three stacks have zero cards*/
	state.supplyCount[1] = 0;
	state.supplyCount[20] = 0;
	state.supplyCount[12] = 0;
	r = isGameOver(&state);
	if(r == 1)
		printf("isGameOver: PASS game is over.\n");
	else
		printf("isGameOver: FAIL game is over.\n");
	
	/*Test when all stacks are empty*/
	for(i = 0; i < 25; i++)
	{
		state.supplyCount[i] = 0;
	}
	r = isGameOver(&state);
	if(r == 1)
		printf("isGameOver: PASS game is over.\n");
	else
		printf("isGameOver: FAIL game is over.\n");
	
	/*Test when all stacks have a negative amount*/
	for(i = 0; i < 25; i++)
	{
		state.supplyCount[i] = -1;
	}
	r = isGameOver(&state);
	if(r == 1)
		printf("isGameOver: PASS game is over.\n");
	else
		printf("isGameOver: FAIL game is over.\n");
	
	/*Test when only province has zero cards*/
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