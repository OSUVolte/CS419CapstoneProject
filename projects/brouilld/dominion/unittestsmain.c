#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestFramework.h"
#include "unittests.h"



int main(int argc, char *argv[])
{

	FILE *doc = fopen("unittestresults.out", "w");
	fclose(doc);

	TestSuite(testUpdateCoins, "Function 'updateCoins()'");

	TestSuite(testGetCost, "Function 'getCost()'");

	TestSuite(testPlayCard, "Function 'playCard()'");

	TestSuite(testBuyCard, "Function 'buyCard()'");

	TestSuite(testSmithyCard, "Card 'Smithy'");

	TestSuite(testAdventurerCard, "Card 'Adventurer'");

	TestSuite(testCouncilRoomCard, "Card 'Council Room'");

	TestSuite(testVillageCard, "Card 'Village'");

	return 0;
}