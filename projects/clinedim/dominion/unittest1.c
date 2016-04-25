#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 0
#define NOISY_TEST 1

char *get_card_name(enum CARD card) {
	switch (card) {
		case curse:
			return "curse";
		case estate:
			return "estate";
		case duchy:
			return "duchy";
		case province:
			return "province";
		case copper:
			return "copper";
		case silver:
			return "silver";
		case gold:
			return "gold";
		case adventurer:
			return "adventurer";
		case council_room:
			return "council_room";
		case feast:
			return "feast";
		case gardens:
			return "gardens";
		case mine:
			return "mine";
		case remodel:
			return "remodel";
		case smithy:
			return "smithy";
		case village:
			return "village";
		case baron:
			return "baron";
		case great_hall:
			return "great_hall";
		case minion:
			return "minion";
		case steward:
			return "steward";
		case tribute:
			return "tribute";
		case ambassador:
			return "ambassador";
		case cutpurse:
			return "cutpurse";
		case embargo:
			return "embargo";
		case outpost:
			return "outpost";
		case salvager:
			return "salvager";
		case sea_hag:
			return "sea_hag";
		case treasure_map:
			return "treasure_map";
	}
	return "";
}

int main(void) {
	srand(time(NULL));
	enum CARD cards[] = {
		curse,
		estate,
		duchy,
		province,
		copper,
		silver,
		gold,
		adventurer,
		council_room,
		feast,
		gardens,
		mine,
		remodel,
		smithy,
		village,
		baron,
		great_hall,
		minion,
		steward,
		tribute,
		ambassador,
		cutpurse,
		embargo,
		outpost,
		salvager,
		sea_hag,
		treasure_map
	};

	int card_costs[] = {
		0,
		2,
		5,
		8,
		0,
		3,
		6,
		6,
		5,
		4,
		4,
		5,
		4,
		4,
		3,
		4,
		3,
		5,
		3,
		5,
		3,
		4,
		2,
		5,
		4,
		4,
		4,
	};

	int index,
		tests_passed = 0;

	printf("Compare value of getCost() to each card's actual cost.\n");
	for (index = 0; index < 27; index++) {
		int actual_cost = card_costs[index],
			get_cost_value = getCost(cards[index]);
		printf("\t\tComparing value of getCost (%d) to actual cost (%d) for %s card.", get_cost_value, actual_cost, get_card_name(cards[index]));
		if (get_cost_value == actual_cost) {
			printf(" - PASSED!\n");
			tests_passed++;
		} else {
			printf(" - FAILED!\n");
		}
	}
	printf("\t\t%d of %d tests passed.\n", tests_passed, index);

	int iteration,
		tests_failed = 0;
	printf("Performing 100 random tests, camparing value of getCost() to each card's actual cost.\n");
	for (iteration = 0; iteration < 100; iteration++) {
		index = rand() % 27;
		int actual_cost = card_costs[index],
			get_cost_value = getCost(cards[index]);
		if (!(get_cost_value == actual_cost)) {
			printf("\t\tTEST FAILED! - Expected %d for getCost(%s), but got %d.\n", card_costs[index], get_card_name(cards[index]), get_cost_value);
			tests_failed++;
		}
	}
	printf("\t\t%d of %d tests failed.\n", tests_failed, iteration);

	return 0;
}