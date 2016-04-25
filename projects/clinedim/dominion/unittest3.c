/*
	File Name:				unittest3
	Author:					Marc Clinedinst
	Functionality Tested:	This unit test test the getSupplyCount function.
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
	Funciton Name:	check_buy_estate_when_none_available
	Parameters: 	N/A
	Returns:		An integer representing whether the test was successful.
	Description:    This checks what happens when attempting to buy an estate even though none are
					available.  The number of estate cards and the player's hand should remain
					unchanged.
*/
void check_buy_estate_when_none_available() {
	int number_of_players = 2,
		kingdom_cards[] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall },
		random_seed = 1;
	struct gameState game_state;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);

	game_state.supplyCount[estate] = 0;
	printf("Checking supply counts after attempting to purchase estate cards when supply is 0.\n");

	int player_hand_count_before_attempted_purchase = numHandCards(&game_state);

	printf("\t Checking that inital number of estate cards is 0.");
	assert(supplyCount(estate, &game_state) == 0);
	printf(" --- PASSED!\n");
	buyCard(estate, &game_state);
	printf("\t Checking that number of estate cards is still 0 after attempted purchase.");
	assert(supplyCount(estate, &game_state) == 0);
	printf(" --- PASSED!\n");
	printf("\t Checking that player's hand count is unchanged.");
	assert(player_hand_count_before_attempted_purchase == numHandCards(&game_state));
	printf(" --- PASSED!\n");
}

/*
	Funciton Name:	check_supply_counts_before_and_after_buying_estate_card
	Parameters: 	N/A
	Returns:		An integer representing whether the test was successful.
	Description:    This checks the supply count before and after a player buys an estate card.
					The number of estate cards should be 8 before the purchase and 10 afterward.
*/
void check_supply_counts_before_and_after_buying_estate_card() {
	int number_of_players = 2,
		kingdom_cards[] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall },
		random_seed = 1;
	struct gameState game_state;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);

	printf("Checking supply counts after purchasing estate cards.\n");

	printf("\tChecking that initial number of estate cards is 8.");
	assert(supplyCount(estate, &game_state) == 8);
	printf(" --- PASSED!\n");
	printf("\tChecking that supply of estate cards is 7 after purchase.");
	buyCard(estate, &game_state);
	assert(supplyCount(estate, &game_state) == 7);
	printf(" --- PASSED!\n");
	printf("\tChecking that player now has 4 estate cards.");
	assert(fullDeckCount(0, estate, &game_state) == 4);
	printf(" --- PASSED!\n");
}

/*
	Funciton Name:	check_supply_counts_after_game_setup
	Parameters: 	The number of players.
	Returns:		An integer representing whether the test was successful.
	Description:    This checks the supply of all available cards after a game has been set up
					for a given number of players.  The correct number of cards are hard coded.
*/
void check_supply_counts_after_game_setup(int number_of_players) {	
	int kingdom_cards[] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall },
		random_seed = 1;
	struct gameState game_state;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
	
	printf("Checking initial supply counts for game with %d players.\n", number_of_players);

	printf("\t Checking correct supply of curse cards.");
	if (number_of_players == 2) {
		assert(supplyCount(curse, &game_state) == 10);
	} else if (number_of_players == 3) {
		assert(supplyCount(curse, &game_state) == 20);
	} else if (number_of_players == 4) {
		assert(supplyCount(curse, &game_state) == 30);
	}
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of estate, duchy, and province cards.");
	if (number_of_players == 2) {
		assert(supplyCount(estate, &game_state) == 8);
		assert(supplyCount(duchy, &game_state) == 8);
		assert(supplyCount(province, &game_state) == 8);
	} else {
		assert(supplyCount(estate, &game_state) == 12);
		assert(supplyCount(duchy, &game_state) == 12);
		assert(supplyCount(province, &game_state) == 12);
	}
	printf(" --- PASSED!\n");
	
	printf("\t Checking correct supply of copper cards.");
	if (number_of_players == 2) {
		assert(supplyCount(copper, &game_state) == 46);
	} else if (number_of_players == 3) {
		assert(supplyCount(copper, &game_state) == 39);
	} else if (number_of_players == 4) {
		assert(supplyCount(copper, &game_state) == 32);
	}
	printf(" --- PASSED!\n");
	
	printf("\t Checking correct supply of silver cards.");
	assert(supplyCount(silver, &game_state) == 40);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of gold cards.");
	assert(supplyCount(gold, &game_state) == 30);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of adventurer cards.");
	assert(supplyCount(adventurer, &game_state) == 10);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of council_room cards.");
	assert(supplyCount(council_room, &game_state) == 10);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of feast cards.");
	assert(supplyCount(feast, &game_state) == 10);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of gardens cards.");
	if (number_of_players == 2) {
		assert(supplyCount(gardens, &game_state) == 8);
	} else {
		assert(supplyCount(gardens, &game_state) == 12);
	}
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of mine cards.");
	assert(supplyCount(mine, &game_state) == 10);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of remodel cards.");
	assert(supplyCount(remodel, &game_state) == 10);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of smithy cards.");
	assert(supplyCount(smithy, &game_state) == 10);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of village cards.");
	assert(supplyCount(village, &game_state) == 10);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of baron cards.");
	assert(supplyCount(baron, &game_state) == 10);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of great_hall cards.");
	if (number_of_players == 2) {
		assert(supplyCount(great_hall, &game_state) == 8);
	} else {
		assert(supplyCount(great_hall, &game_state) == 12);
	}
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of minion cards.");
	assert(supplyCount(minion, &game_state) == -1);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of steward cards.");
	assert(supplyCount(steward, &game_state) == -1);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of tribute cards.");
	assert(supplyCount(tribute, &game_state) == -1);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of ambassador cards.");
	assert(supplyCount(ambassador, &game_state) == -1);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of cutpurse cards.");
	assert(supplyCount(cutpurse, &game_state) == -1);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of embargo cards.");
	assert(supplyCount(embargo, &game_state) == -1);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of outpost cards.");
	assert(supplyCount(outpost, &game_state) == -1);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of salvager cards.");
	assert(supplyCount(salvager, &game_state) == -1);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of sea_hag cards.");
	assert(supplyCount(sea_hag, &game_state) == -1);
	printf(" --- PASSED!\n");

	printf("\t Checking correct supply of treasure_map cards.");
	assert(supplyCount(treasure_map, &game_state) == -1);
	printf(" --- PASSED!\n");
}

/*
	Perform the tests and report the results.
*/
int main(void) {
	srand(time(NULL));

	printf("**********\n");
	printf("UNIT TEST # 3\n");
	printf("*********\n");
	check_supply_counts_after_game_setup(2);
	check_supply_counts_after_game_setup(3);
	check_supply_counts_after_game_setup(4);
	check_supply_counts_before_and_after_buying_estate_card();
	check_buy_estate_when_none_available();

	return 0;
}