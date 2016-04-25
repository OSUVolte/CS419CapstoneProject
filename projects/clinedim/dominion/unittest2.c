/*
	File Name:				unittest2.c
	Author:					Marc Clinedinst
	Functionality Tested:	This unit test tests the initializeGame function.  It does so by initializing
							games with different number of players and checking that the state of the game
							is correct.
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
	Funciton Name:	check_curse_cards
	Parameters: 	A gameState structure.
	Returns:		An integer representing whether the test was successful.
	Description:    This function tests that the correct number of curse cards are present based
					on the number of players.  The correct values are hard coded.
*/
int check_curse_cards(struct gameState game_state) {
	if (game_state.numPlayers == 2) {
		return game_state.supplyCount[curse] == 10;
	} else if (game_state.numPlayers == 3) {
		return game_state.supplyCount[curse] == 20;
	} else {
		return game_state.supplyCount[curse] == 30;
	}
}

/*
	Funciton Name:	check_embargo_tokens
	Parameters: 	A gameState structure.
	Returns:		An integer representing whether the test was successful.
	Description:    This function tests that the correct number of embargo tokens are present based
					on the number of players.  The correct values are hard coded.
*/
int check_embargo_tokens(struct gameState game_state) {
	int index;

	for (index = 0; index < treasure_map; index++) {
		if (game_state.embargoTokens[index] != 0) {
			return 0;
		}
	}

	return 1;
}

/*
	Funciton Name:	check_first_turn_setup
	Parameters: 	A gameState structure.
	Returns:		An integer representing whether the test was successful.
	Description:    This function tests that the outpostPlayed, phase, numActions,
					numBuys, playedCardCount, whoseTurn, and handCount values are
					correct for the game.  The correct values are hard coded.
*/
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

/*
	Funciton Name:	check_cking_cards
	Parameters: 	A gameState structure.
	Returns:		An integer representing whether the test was successful.
	Description:    This function tests that the correct number of king cards are present based
					on the number of players.  The correct values are hard coded.
*/
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

/*
	Funciton Name:	check_number_of_players
	Parameters: 	A gameState structure and number of players.
	Returns:		An integer representing whether the test was successful.
	Description:    This function tests that the correct number of players are present based
					on the number of players.  The correct value is passed to the function.
*/
int check_number_of_players(struct gameState game_state, int expected_number_of_players) {
	return game_state.numPlayers == expected_number_of_players;
}

/*
	Funciton Name:	check_other_players_setup
	Parameters: 	A gameState structure.
	Returns:		An integer representing whether the test was successful.
	Description:    This function tests that the other players have the correct number of
					copper and estate cards.  The correct values are hardcoded.
*/
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

/*
	Funciton Name:	check_player_one_setup
	Parameters: 	A gameState structure.
	Returns:		An integer representing whether the test was successful.
	Description:    This function tests that the correct number of copper and estate are present 
					for player one. The correct values are hard coded.
*/
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

/*
	Funciton Name:	check_treasure_cards
	Parameters: 	A gameState structure.
	Returns:		An integer representing whether the test was successful.
	Description:    This function tests that the correct number of treasure cards are present based
					on the number of players.  The correct values are hard coded.
*/
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

/*
	Funciton Name:	check_victory_cards
	Parameters: 	A gameState structure.
	Returns:		An integer representing whether the test was successful.
	Description:    This function tests that the correct number of treasure cards are present based
					on the number of players.  The correct values are hard coded.
*/
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

/*
	Funciton Name:	perform_all_checks
	Parameters: 	A gameState structure and a number of players.
	Returns:		An integer representing whether the test was successful.
	Description:    This function performs all the checks defined in functions above.
*/
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

/*
	Perform all the checks.
*/
int main(void) {
	printf("**********\n");
	printf("UNIT TEST # 2\n");
	printf("*********\n");

	/*
		Test initial state for 2 players.
	*/
	int number_of_players = 2,
		kingdom_cards[] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall },
		random_seed = 1;
	struct gameState game_state;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
	perform_all_checks(game_state, number_of_players);

	/*
		Test initial state for 3 players.
	*/
	number_of_players = 3;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
	perform_all_checks(game_state, number_of_players);	


	/*
		Test initial state for 4 players.
	*/
	number_of_players = 4;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
	perform_all_checks(game_state, number_of_players);

	return 0;
}