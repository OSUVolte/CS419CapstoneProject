#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestFramework.h"
#include "unittests.h"

void testGetCost(){

	int returnedValue = -50;

	/*
	* TEST: 'curse' returns 0
	*/

		// Test
		returnedValue = getCost(curse);
		assertTest(returnedValue, 0, "'curse' returns 0");

		// After Test Cleanup
		returnedValue = -50;


	/*
	* TEST: 'estate' returns 2
	*/
		
		

		// Test
		returnedValue = getCost(estate);
		assertTest(returnedValue, 2, "'estate' returns 2");

		// After Test Cleanup
		returnedValue = -50;


	/*
	* TEST: 'duchy' returns 5
	*/
		
		

		// Test
		returnedValue = getCost(duchy);
		assertTest(returnedValue, 5, "'duchy' returns 5");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'province' returns 8
	*/
		
		// Test
		returnedValue = getCost(province);
		assertTest(returnedValue, 8, "'province' returns 8");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'copper' returns 0
	*/
		
		// Test
		returnedValue = getCost(copper);
		assertTest(returnedValue, 0, "'copper' returns 0");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'silver' returns 3
	*/
		
		// Test
		returnedValue = getCost(silver);
		assertTest(returnedValue, 3, "'silver' returns 3");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'gold' returns 6
	*/
		// Test
		returnedValue = getCost(gold);
		assertTest(returnedValue, 6, "'gold' returns 6");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'adventurer' returns 6
	*/
		// Test
		returnedValue = getCost(adventurer);
		assertTest(returnedValue, 6, "'adventurer' returns 6");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'council_room' returns 5
	*/
		// Test
		returnedValue = getCost(council_room);
		assertTest(returnedValue, 5, "'council_room' returns 5");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'feast' returns 4
	*/
		// Test
		returnedValue = getCost(feast);
		assertTest(returnedValue, 4, "'feast' returns 4");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'gardens' returns 4
	*/
		// Test
		returnedValue = getCost(gardens);
		assertTest(returnedValue, 4, "'gardens' returns 4");

		// After Test Cleanup
		returnedValue = -50;


	/*
	* TEST: 'mine' returns 5
	*/
		// Test
		returnedValue = getCost(mine);
		assertTest(returnedValue, 5, "'mine' returns 5");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'remodel' returns 4
	*/
		// Test
		returnedValue = getCost(remodel);
		assertTest(returnedValue, 4, "'remodel' returns 4");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'smithy' returns 4
	*/
		// Test
		returnedValue = getCost(smithy);
		assertTest(returnedValue, 4, "'smithy' returns 4");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'village' returns 3
	*/
		// Test
		returnedValue = getCost(village);
		assertTest(returnedValue, 3, "'village' returns 3");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'baron' returns 4
	*/
		// Test
		returnedValue = getCost(baron);
		assertTest(returnedValue, 4, "'baron' returns 4");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'great_hall' returns 3
	*/
		// Test
		returnedValue = getCost(great_hall);
		assertTest(returnedValue, 3, "'great_hall' returns 3");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'minion' returns 5
	*/
		// Test
		returnedValue = getCost(minion);
		assertTest(returnedValue, 5, "'minion' returns 5");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'steward' returns 3
	*/
		// Test
		returnedValue = getCost(steward);
		assertTest(returnedValue, 3, "'steward' returns 3");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'tribute' returns 5
	*/
		// Test
		returnedValue = getCost(tribute);
		assertTest(returnedValue, 5, "'tribute' returns 5");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'ambassador' returns 3
	*/
		// Test
		returnedValue = getCost(ambassador);
		assertTest(returnedValue, 3, "'ambassador' returns 3");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'cutpurse' returns 4
	*/
		// Test
		returnedValue = getCost(cutpurse);
		assertTest(returnedValue, 4, "'cutpurse' returns 4");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'embargo' returns 2
	*/
		// Test
		returnedValue = getCost(embargo);
		assertTest(returnedValue, 2, "'embargo' returns 2");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'outpost' returns 5
	*/
		// Test
		returnedValue = getCost(outpost);
		assertTest(returnedValue, 5, "'outpost' returns 5");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'salvager' returns 4
	*/
		// Test
		returnedValue = getCost(salvager);
		assertTest(returnedValue, 4, "'salvager' returns 4");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'sea_hag' returns 4
	*/
		// Test
		returnedValue = getCost(sea_hag);
		assertTest(returnedValue, 4, "'sea_hag' returns 4");

		// After Test Cleanup
		returnedValue = -50;

	/*
	* TEST: 'treasure_map' returns 4
	*/
		// Test
		returnedValue = getCost(treasure_map);
		assertTest(returnedValue, 4, "'treasure_map' returns 4");

		// After Test Cleanup
		returnedValue = -50;

}