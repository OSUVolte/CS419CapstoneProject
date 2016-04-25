/*
	File Name:				unittest1.c
	Author:					Marc Clinedinst
	Functionality Tested:	This unit test test the getCost function.  It does so by testing comparing the
							actual cost of each individual card to the value returned by the getCost 
							function for that card.
*/
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 0
#define NOISY_TEST 1

/*
	Function Name:	get_card_name
	Parameters:		An enumerated value representing a CARD.
	Returns:		This function returns a string value representing the name of an enumerated CARD.
	Description:    This function returns a string value representing the name of an enumerated CARD.
					It is a simple helper funciton used to prettify the output of the tests.
*/
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

/*
	Perform the unit test.
*/
int main(void) {
	srand(time(NULL));
	/*
		This is simply an array of all of the available cards.  It is used in conjunction with the
		card_costs array to determine the cost of each card.
	*/
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

	/*
		This array holds the costs of the cards listed above, so that a comparison is easy. These
		are the actual costs of each card.
	*/
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

	/*
		This unit test is fairly simply--we just loop through every available card and compare its
		actual cost from the card_costs array with the value that is returned by the getCost function.
		If any discrepancies are found, the failure is printed to the screen.
	*/
	printf("**********\n");
	printf("UNIT TEST # 1\n");
	printf("*********\n");
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

	return 0;
}