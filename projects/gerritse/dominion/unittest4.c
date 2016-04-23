//Ellard Gerritsen van der Hoop
//CS362 Unit Test 4
//
//supplyCount test
//
//
//



#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main()
{
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("Unit Test 4: supplyCount Function\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n");

	struct gameState state;
	int numPlayers = 2;
	int currentPlayer = 0;
	int seed = 1000;
	int k[10] = {adventurer, smithy, gardens, feast, village, baron, great_hall, council_room, remodel, mine};
	int totalBugs = 0;
	int expected = 0;
	
	initializeGame(numPlayers, k , seed, &state);
	
	expected = 10;
	printf("Test 1 -  Smithy Card\n");
	printf("Checking amount of Smithys in Supply\n");
	printf("Amount: %d    Expected: %d\n", supplyCount(smithy, &state), expected);	

	printf("Gaining card - smithy\n");
	expected--;
	gainCard(smithy, &state, 2, currentPlayer);
	printf("Amount of Smithy's in Supply: %d     Expected: %d\n", supplyCount(smithy, &state), expected);
	
	if (supplyCount(smithy, &state) != expected)
	{
		totalBugs++;
	}

	expected = 10;
	printf("Test 2 -  Feast Card\n");
	printf("Checking amount of Feast in Supply\n");
	printf("Amount: %d    Expected: %d\n", supplyCount(feast, &state), expected);	

	printf("Gaining card - feast\n");
	expected--;
	gainCard(feast, &state, 2, currentPlayer);
	printf("Amount of feasts in Supply: %d     Expected: %d\n", supplyCount(feast, &state), expected);
	
	if (supplyCount(feast, &state) != expected)
	{
		totalBugs++;
	}

	expected = 8;
	printf("Test 3 -  Garden Card\n");
	printf("Checking amount of Gardens in Supply\n");
	printf("Amount: %d    Expected: %d\n", supplyCount(gardens, &state), expected);	

	printf("Gaining card - garden\n");
	expected--;
	gainCard(gardens, &state, 2, currentPlayer);
	printf("Amount of gardens in Supply: %d     Expected: %d\n", supplyCount(gardens, &state), expected);
	
	if (supplyCount(gardens, &state) != expected)
	{
		totalBugs++;
	}

	
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("Number of Players is now increased to 3\n\n");
	numPlayers = 3;

	initializeGame(numPlayers, k , seed, &state);
	
	expected = 10;
	printf("Test 1 -  Smithy Card\n");
	printf("Checking amount of Smithys in Supply\n");
	printf("Amount: %d    Expected: %d\n", supplyCount(smithy, &state), expected);	

	printf("Gaining card - smithy\n");
	expected--;
	gainCard(smithy, &state, 2, currentPlayer);
	printf("Amount of Smithy's in Supply: %d     Expected: %d\n", supplyCount(smithy, &state), expected);
	
	if (supplyCount(smithy, &state) != expected)
	{
		totalBugs++;
	}

	expected = 10;
	printf("Test 2 -  Feast Card\n");
	printf("Checking amount of Feast in Supply\n");
	printf("Amount: %d    Expected: %d\n", supplyCount(feast, &state), expected);	

	printf("Gaining card - feast\n");
	expected--;
	gainCard(feast, &state, 2, currentPlayer);
	printf("Amount of feasts in Supply: %d     Expected: %d\n", supplyCount(feast, &state), expected);
	
	if (supplyCount(feast, &state) != expected)
	{
		totalBugs++;
	}

	expected = 12;
	printf("Test 3 -  Garden Card\n");
	printf("Checking amount of Gardens in Supply\n");
	printf("Amount: %d    Expected: %d\n", supplyCount(gardens, &state), expected);	

	printf("Gaining card - garden\n");
	expected--;
	gainCard(gardens, &state, 2, currentPlayer);
	printf("Amount of gardens in Supply: %d     Expected: %d\n", supplyCount(gardens, &state), expected);
	
	if (supplyCount(gardens, &state) != expected)
	{
		totalBugs++;
	}
	










	if (totalBugs != 0){
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("supplyCount function - FAIL\n");
		printf("Total Bugs: %d\n", totalBugs);
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}
	else{
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("supplyCount function - PASS\n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	}



	return 0; 
}
