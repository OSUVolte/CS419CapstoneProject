/******************************************************************************
** unittest1.c 
** Emily Snyder
** Spring 2016
** CS 362-400
** Unit tests for getCost function.
** getCost() should return the correct cost in coins for the card that is
** passed as a parameter. These tests compare the cost returned by the function
** to the costs given at http://wiki.dominionstrategy.com/.
******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>

int main() {
  int cost;
  int i;
  int numCards = 27;  // total number of cards in enum in dominion.h
  int bugFound = 0;

  printf("****************************************************************\n");
  printf("***                        getCost()                         ***\n");
  printf("****************************************************************\n");
  // Loop through each of the possible cards plus an additional time to simulate
  // a card that does not exist in this implementation of Dominion.
  printf("---------- TESTING CARD COSTS ----------\n");
  for (i = 0; i < numCards; i++) {
		cost = getCost(curse);
		if(cost != 0) {
    	printf("  ERROR: Curse card cost should be 0 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(estate);
		if(cost != 2) {
    	printf("  ERROR: Estate card cost should be 2 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(duchy);
		if(cost != 5) {
    	printf("  ERROR: Duchy card cost should be 5 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(province);
		if(cost != 8) {
    	printf("  ERROR: Province card cost should be 8 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(copper);
		if(cost != 0) {
    	printf("  ERROR: Copper card cost should be 0 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(silver);
		if(cost != 3) {
    	printf("  ERROR: Silver card cost should be 3 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(gold);
		if(cost != 6) {
    	printf("  ERROR: Gold card cost should be 6 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(adventurer);
		if(cost != 6) {
    	printf("  ERROR: Adventurer card cost should be 6 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(council_room);
		if(cost != 5) {
    	printf("  ERROR: Council Room card cost should be 5 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(feast);
		if(cost != 4) {
    	printf("  ERROR: Feast card cost should be 4 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(gardens);
		if(cost != 4) {
    	printf("  ERROR: Gardens card cost should be 4 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(mine);
		if(cost != 5) {
    	printf("  ERROR: Mine card cost should be 5 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(remodel);
		if(cost != 4) {
    	printf("  ERROR: Remodel card cost should be 4 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(smithy);
		if(cost != 4) {
    	printf("  ERROR: Smithy card cost should be 4 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(village);
		if(cost != 3) {
    	printf("  ERROR: Village card cost should be 3 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(baron); 
		if(cost != 4) {
    	printf("  ERROR: Baron card cost should be 4 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(great_hall);
		if(cost != 3) {
    	printf("  ERROR: Great Hall card cost should be 3 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(minion); 
		if(cost != 5) {
    	printf("  ERROR: Minion card cost should be 5 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(steward); 
		if(cost != 3) {
    	printf("  ERROR: Steward card cost should be 3 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(tribute);
		if(cost != 5) {
    	printf("  ERROR: Tribute card cost should be 5 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(ambassador); 
		if(cost != 3) {
    	printf("  ERROR: Ambassador card cost should be 3 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(cutpurse);
		if(cost != 4) {
    	printf("  ERROR: Cutpurse card cost should be 4 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(embargo); 
		if(cost != 2) {
    	printf("  ERROR: Embargo card cost should be 2 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(outpost);
		if(cost != 5) {
    	printf("  ERROR: Outpost card cost should be 5 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(salvager);
		if(cost != 4) {
    	printf("  ERROR: Salvager card cost should be 4 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(sea_hag);
		if(cost != 4) {
    	printf("  ERROR: Sea Hag card cost should be 4 not %d\n", cost);
      bugFound = 1;
    }
		cost = getCost(treasure_map);
		if(cost != 4) {
    	printf("  ERROR: Treasure Map card cost should be 4 not %d\n", cost);
      bugFound = 1;
    }
  }
  
  // Testing card that does not exist
  cost = getCost(i);
	if(cost != -1) {
   	printf("  ERROR: This card does not exist, the cost should be -1 not %d\n", cost);
     bugFound = 1;
   }

  if (!bugFound) {
    printf("  SUCCESS: all card costs are correct\n");
  }

  return 0;
}
