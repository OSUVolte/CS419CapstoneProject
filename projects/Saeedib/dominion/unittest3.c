/*
Behnam Saeedi
Saeedib
93227697
Unit test
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define UNITTEST "kingdomCards"

int main(int argc, char ** argv)
{
	srand(time(NULL));
	//Generating player:
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
	// initialize a game state and player cards
	//Total should add up to 6
	// Starting test
	printf("\n\nTesting Unit %s\n\n", UNITTEST);


	printf("Test 1: cecking for match between two copies.\n");
	int * k2 = kingdomCards(k[0],k[1],k[2],k[3],k[4],k[5],k[6],k[7],k[8],k[9]);
	for(int i = 0; i < 10; i++)
	{
		printf("Member %d holds value of %d.\n",i, k[i]);
		assert(k2[i] == k[i]);
	}
	printf("Test 1 Passed\n");

	return 0;	//No bugs found
}
