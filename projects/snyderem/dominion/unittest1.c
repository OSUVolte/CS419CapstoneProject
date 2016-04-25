/* whoseTurn */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>

int main() {
  int cost;
  int i;
  int numCards = 27;  // total number of cards in enum in dominion.h

  for (i = 0; i < numCards; i++) {
		cost = getCost(curse);
		assert(cost == 0);
		cost = getCost(estate);
		assert(cost == 2);
		cost = getCost(duchy);
		assert(cost == 5);
		cost = getCost(province);
		assert(cost == 8);
		cost = getCost(copper);
		assert(cost == 0);
		cost = getCost(silver);
		assert(cost == 3);
		cost = getCost(gold);
		assert(cost == 6);
		cost = getCost(adventurer);
		assert(cost == 6);
		cost = getCost(council_room);
		assert(cost == 5);
		cost = getCost(feast);
		assert(cost == 4);
		cost = getCost(gardens);
		assert(cost == 4);
		cost = getCost(mine);
		assert(cost == 5);
		cost = getCost(remodel);
		assert(cost == 4);
		cost = getCost(smithy);
		assert(cost == 4);
		cost = getCost(village);
		assert(cost == 3);
		cost = getCost(baron); 
		assert(cost == 4);
		cost = getCost(great_hall);
		assert(cost == 3);
		cost = getCost(minion); 
		assert(cost == 5);
		cost = getCost(steward); 
		assert(cost == 3);
		cost = getCost(tribute);
		assert(cost == 5);
		cost = getCost(ambassador); 
		assert(cost == 3);
		cost = getCost(cutpurse);
		assert(cost == 4);
		cost = getCost(embargo); 
		assert(cost == 2);
		cost = getCost(outpost);
		assert(cost == 5);
		cost = getCost(salvager);
		assert(cost == 4);
		cost = getCost(sea_hag);
		assert(cost == 4);
		cost = getCost(treasure_map);
		assert(cost == 4);
  }
  
  // Testing card that does not exist
  cost = getCost(i);
  assert(cost == -1);

  return 0;
}
