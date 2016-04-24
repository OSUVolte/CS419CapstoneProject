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
}

void check_supply_counts_before_and_after_buying_random_card() {
	int number_of_players = 2,
		kingdom_cards[] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall },
		random_seed = 1;
	struct gameState game_state;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
	enum CARD card = kingdom_cards[random() % 10];

	// give player enough to buy any of the available kingdom cards
	game_state.coins = 6;

	int expected_supply_count;

	printf("Checking supply counts before and after purchasing %s\n", get_card_name(card));

	switch (card) {
		case adventurer:
		case council_room:
		case feast:
		case mine:
		case remodel:
		case smithy:
		case village:
		case baron:
			expected_supply_count = 10;
			break;
		case gardens:
		case great_hall:
			expected_supply_count = 8;
			break;
		default:
			exit(1);
			break;
	}

	printf("\tChecking that initial supply of %s is %d.", get_card_name(card), expected_supply_count);
	assert(supplyCount(card, &game_state) == expected_supply_count);
	printf(" --- PASSED!\n");
	printf("\tChecking that supply of %s after purchasing one card is %d.", get_card_name(card), expected_supply_count - 1);
	buyCard(card, &game_state);
	assert(supplyCount(card, &game_state) == expected_supply_count - 1);
	printf(" --- PASSED!\n");
}

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

int main(void) {
	srand(time(NULL));
	int random_test_number;

	printf("*** PERFORMING NON-RANDOM TESTS ***\n");
	check_supply_counts_after_game_setup(2);
	check_supply_counts_after_game_setup(3);
	check_supply_counts_after_game_setup(4);
	check_supply_counts_before_and_after_buying_estate_card();
	check_buy_estate_when_none_available();

	printf("*** PERFORMING 10 RANDOM TESTS ***\n");
	for (random_test_number = 0; random_test_number < 10; random_test_number++) {
		check_supply_counts_before_and_after_buying_random_card();
	}

	return 0;
}