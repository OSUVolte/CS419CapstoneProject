//getCost() unit test

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {
	int i;

	printf("-------getCost unit test-------\n");

	/**********Check cost of cards ************/
	//cards to test
	const char* cards[] = {"curse", "estate", "duchy", "province", "copper", 
		"silver", "gold", "adventurer", "council_room", "feast", "gardens", 
		"mine", "remodel", "smithy", "village", "baron", "great_hall", "minion",
		"steward", "tribute", "ambassador", "cutpurse", "embargo", "outpost",
		"salvager", "sea_hag", "treasure_map", "bad_card"};

	//costs to test
	int cost[] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4,-1};

	for (i = 0; i < 28; i++) {
		if(getCost(i) == cost[i]) {
			printf("getCost: PASS for %s card.\n", cards[i]);
		}
		else {
			printf("getCost: FAIL for %s card.\n", cards[i]);
		}
	}

	printf("\n");

	return 0;
}