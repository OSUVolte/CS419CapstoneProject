//Ellard Gerritsen van der Hoop
//CS362 Unit Test 3
//getCost function
//


#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"
#include <math.h>



#define NOISY_TEST 1

int main()
{

	int deck[27]= {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};

	int totalBugs = 0;
	

	//Checking the values of all cards in the deck 
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("Unit Test 3 - getCost()\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n");


	printf("This test is going to check that the Cost Values of all Cards is correct\n");
	

	if (getCost(deck[0] != 0))
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Curse cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");		
	if (getCost(deck[1]) != 2)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Estate cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[2]) != 5)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Duchy cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[3]) != 8)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Province cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[4]) != 0)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Copper cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[5]) != 3)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Silver cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[6]) != 6)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Gold cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[7]) != 6)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Adventurer cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[8]) != 5)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Council room cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[9]) != 4)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Feast cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[10]) != 4)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Gardens cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[11]) != 5)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Mine cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");if (getCost(deck[12]) != 4)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Remodel cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[13]) != 4)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Smithy cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[14]) != 3)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Village cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[15]) != 4)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Baron cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
 	if (getCost(deck[16]) != 3)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Great hall cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[17]) != 5)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Minion cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[18]) != 3)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Steward cost issue\n");

	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[19]) != 5)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Tribute cost issue\n");

	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[20]) != 3)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Ambassador cost issue\n");

	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[21]) != 4)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Cutpurse cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[22]) != 2)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Embargo cost issue\n");

	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[23]) != 5)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Outpost cost issue\n");

	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[24]) != 4)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Salvager cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[25]) != 4)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Sea hag cost issue\n");
	}
	else
		printf("Cost is good for this card\n)");
	if (getCost(deck[26]) != 4)
	{
		totalBugs++;
		
		if (NOISY_TEST == 1)
			printf("Treasure map cost issue\n");

	}
	else
		printf("Cost is good for this card\n)");


	if (totalBugs != 0)
	{
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("Number of Bugs: %d\n", totalBugs);
		printf("getCost() function - FAIL\n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		
	}
	else{
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("getCost() function - PASS\n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}





















	

	return 0;
}
