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
	
	/*Test when all card stacks have the same number of cards.*/
	for(i = 0; i < treasure_map; i++)
	{
		state.supplyCount[i] = 1;
	}
	r = isGameOver(&state);
	if(r == 0)
		printf("isGameOver: PASS game is not over, each stack has one card.\n");
	else
		printf("isGameOver: FAIL game is not over, each stack has one card.\n");
	
	/*Test when card piles have different number of cards*/
	for(i = 0; i <= treasure_map; i++)
	{
		state.supplyCount[i] = i + 1;
	}
	r = isGameOver(&state);
	if(r == 0)
		printf("isGameOver: PASS game is not over, stacks have different number of cards.\n");
	else
		printf("isGameOver: FAIL game is not over, stacks have different number of cards.\n");
	
	/*Test when one stack has zero cards.*/
	state.supplyCount[village] = 0;
	r = isGameOver(&state);
	if(r == 0)
		printf("isGameOver: PASS game is not over, one stack has zero cards.\n");
	else
		printf("isGameOver: FAIL game is not over, one stack has zero cards.\n");
	
	/*Test when two stacks have zero cards*/
	state.supplyCount[village] = 0;
	state.supplyCount[smithy] = 0;
	r = isGameOver(&state);
	if(r == 0)
		printf("isGameOver: PASS game is not over, two stacks have zero cards.\n");
	else
		printf("isGameOver: FAIL game is not over, two stacks have zero cards.\n");
	
	/*Test when three stacks have zero cards*/
	state.supplyCount[village] = 0;
	state.supplyCount[smithy] = 0;
	state.supplyCount[feast] = 0;
	r = isGameOver(&state);
	if(r == 1)
		printf("isGameOver: PASS game is not over, three stacks have zero cards.\n");
	else
		printf("isGameOver: FAIL game is not over, three stacks have sero cards.\n");
	
	/*Test when three stacks have zero cards*/
	for(i = 0; i < treasure_map; i++)
	{
		state.supplyCount[i] = 1;
	}
	state.supplyCount[salvager] = 0;
	state.supplyCount[sea_hag] = 0;
	state.supplyCount[treasure_map] = 0;
	r = isGameOver(&state);
	if(r == 1)
		printf("isGameOver: PASS game is over, salvager, sea_hag, treasure_map have zero cards.\n");
	else
		printf("isGameOver: FAIL game is over, salvager, sea_hag, treasure_map have zero cards.\n");
	
	/*Test when all stacks are empty*/
	for(i = 0; i <= treasure_map; i++)
	{
		state.supplyCount[i] = 0;
	}
	r = isGameOver(&state);
	if(r == 1)
		printf("isGameOver: PASS game is over, all stacks are empty.\n");
	else
		printf("isGameOver: FAIL game is over, all stacks are empty.\n");
	
	/*Test when all stacks have a negative amount*/
	for(i = 0; i <= treasure_map; i++)
	{
		state.supplyCount[i] = -1;
	}
	r = isGameOver(&state);
	if(r == 1)
		printf("isGameOver: PASS game is over, all stacks have a negative value.\n");
	else
		printf("isGameOver: FAIL game is over, all stacks have a negative value.\n");
	
	/*Test when only province has zero cards*/
	for(i = 0; i <= treasure_map; i++)
	{
		state.supplyCount[i] = 3;
	}
	state.supplyCount[province] = 0;
	r = isGameOver(&state);
	if(r == 1)
		printf("isGameOver: PASS game is over, province has zero cards.\n");
	else
		printf("isGameOver: FAIL game is over, province has zero cards.\n");
}

int main(int argc, char *argv[])
{
    testIsGameOver();
    return 0;
}