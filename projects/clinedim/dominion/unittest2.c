#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 0
#define NOISY_TEST 1

int check_curse_cards(struct gameState game_state) {
	if (game_state.numPlayers == 2) {
		return game_state.supplyCount[curse] == 10;
	} else if (game_state.numPlayers == 3) {
		return game_state.supplyCount[curse] == 20;
	} else {
		return game_state.supplyCount[curse] == 30;
	}
}

int check_embargo_tokens(struct gameState game_state) {
	int index;

	for (index = 0; index < treasure_map; index++) {
		if (game_state.embargoTokens[index] != 0) {
			return 0;
		}
	}

	return 1;
}

int check_first_turn_setup(struct gameState game_state) {
	if (game_state.outpostPlayed != 0) {
		return 0;
	}
	if (game_state.phase != 0) {
		return 0;
	}
	if (game_state.numActions != 1) {
		return 0;
	}
	if (game_state.numBuys != 1) {
		return 0;
	}
	if (game_state.playedCardCount != 0) {
		return 0;
	}
	if (game_state.whoseTurn != 0) {
		return 0;
	}
	if (game_state.handCount[game_state.whoseTurn] != 5) {
		return 0;
	}
	return 1;
}


int check_kingdom_cards(struct gameState game_state) {
	int card,
		number_of_kingdom_cards = 0;
	
	for (card = adventurer; card <= treasure_map; card++) {
		if (game_state.supplyCount[card] > 0) {
			number_of_kingdom_cards++;
		}
	}

	return number_of_kingdom_cards == 10;
}

int check_number_of_players(struct gameState game_state, int expected_number_of_players) {
	return game_state.numPlayers == expected_number_of_players;
}

int check_other_players_setup(struct gameState game_state) {
	int current_player;

	for (current_player = 1; current_player < game_state.numPlayers; current_player++) {
		int copper_count = 0,
			estate_count = 0,
			index;

		for (index = 0; index < 10; index++) {
			if (game_state.deck[current_player][index] == copper) {
				copper_count++;
			} else if (game_state.deck[current_player][index] == estate) {
				estate_count++;
			} else {
				return 0;
			}
		}

		if ((copper_count != 7) || (estate_count != 3)) {
			return 0;
		}
	}

	return 1;
}

int check_player_one_setup(struct gameState game_state) {
	int copper_count = 0,
		estate_count = 0,
		index;
	
	for (index = 0; index < 5; index++) {
		if (game_state.hand[0][index] == copper) {
			copper_count++;
		} else if (game_state.hand[0][index] == estate) {
			estate_count++;
		} else {
			return 0;
		}
	}

	for (index = 0; index < 5; index++) {
		if (game_state.deck[0][index] == copper) {
			copper_count++;
		} else if (game_state.deck[0][index] == estate) {
			estate_count++;
		} else {
			return 0;
		}
	}

	return copper_count == 7 && estate_count == 3;
}

int check_treasure_cards(struct gameState game_state) {
	if (game_state.numPlayers == 2) {
		return game_state.supplyCount[copper] == 46 &&
			   game_state.supplyCount[silver] == 40 &&
			   game_state.supplyCount[gold] == 30;
	} else if (game_state.numPlayers == 3) {
		return game_state.supplyCount[copper] == 39 &&
			   game_state.supplyCount[silver] == 40 &&
			   game_state.supplyCount[gold] == 30;
	} else {
		return game_state.supplyCount[copper] == 32 &&
			   game_state.supplyCount[silver] == 40 &&
			   game_state.supplyCount[gold] == 30;
	}
}

int check_victory_cards(struct gameState game_state) {
	if (game_state.numPlayers == 2) {
		return game_state.supplyCount[estate] == 8 && 
			   game_state.supplyCount[duchy] == 8 &&
			   game_state.supplyCount[province] == 8;
	} else {
		return game_state.supplyCount[estate] == 12 && 
			   game_state.supplyCount[duchy] == 12 &&
			   game_state.supplyCount[province] == 12;
	}
}

void perform_all_checks(struct gameState game_state, int number_of_players) {
	printf("Checking intializeGame for game with %d players.\n", number_of_players);
	
	assert(check_curse_cards(game_state) == 1);
	printf("\tCurse cards check passed.\n");

	assert(check_embargo_tokens(game_state) == 1);
	printf("\tEmbargo tokens check passed.\n");

	assert(check_first_turn_setup(game_state) == 1);
	printf("\tFirst turn setup passed.\n");

	assert(check_kingdom_cards(game_state) == 1);
	printf("\tKingdom cards check passed.\n");

	assert(check_number_of_players(game_state, number_of_players) == 1);
	printf("\tNumber of players check passed.\n");

	assert(check_other_players_setup(game_state) == 1);
	printf("\tOther players setup check passed.\n");

	assert(check_player_one_setup(game_state) == 1);
	printf("\tPlayer one setup check passed.\n");

	assert(check_treasure_cards(game_state) == 1);
	printf("\tTreasure cards setup check passed.\n");

	assert(check_victory_cards(game_state) == 1);
	printf("\tVictory cards setup check passed.\n");
}

int main(void) {
	int number_of_players = 2,
		kingdom_cards[] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall },
		random_seed = 1;
	struct gameState game_state;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
	perform_all_checks(game_state, number_of_players);

	number_of_players = 3;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
	perform_all_checks(game_state, number_of_players);	

	number_of_players = 4;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
	perform_all_checks(game_state, number_of_players);

	return 0;
}