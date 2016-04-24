#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 0
#define NOISY_TEST 1

int main(void) {
	srand(time(NULL));
	int number_of_players = 2,
		kingdom_cards[] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall },
		random_seed = 1,
		choice1 = 0,
		choice2 = 0,
		choice3 = 0,
		hand_position = 0,
		bonus = 0,
		index;
	struct gameState game_state;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);

	int player_0_hand_count_before_council_room = game_state.handCount[0];
	int player_0_deck_count_before_council_room = game_state.deckCount[0];
	int player_0_discard_count_before_council_room = game_state.discardCount[0];
	int player_1_hand_count_before_council_room = game_state.handCount[1];
	int player_1_deck_count_before_council_room = game_state.deckCount[1];
	int player_1_discard_count_before_council_room = game_state.discardCount[1];
	int played_card_count_before_council_room = game_state.playedCardCount;
	int supply_count_before_council_room[treasure_map+1];
	for (index = 0; index < treasure_map+1; index++) {
		supply_count_before_council_room[index] = supplyCount(index, &game_state);
	}
	int embargo_tokens_before_council_room[treasure_map+1];
	for (index = 0; index < treasure_map+1; index++) {
		embargo_tokens_before_council_room[index] = game_state.embargoTokens[index];
	}
	int outpost_played_before_council_room = game_state.outpostPlayed;
  	int outpost_turn_before_council_room = game_state.outpostTurn;
  	int whose_turn_before_council_room = game_state.whoseTurn;
  	int phase_before_council_room = game_state.phase;
  	int number_of_actions_before_council_room = game_state.numActions;
  	int coins_before_council_room = game_state.coins;
  	int num_buys_before_council_room = game_state.numBuys;

	printf("********** TESTING council_room CARD **********\n");
	printf("\tBEFORE PLAYING CARD\n");
	printf("Player 0 has %d cards in hand.\n", player_0_hand_count_before_council_room);
	printf("Player 0 has %d cards in deck.\n", player_0_deck_count_before_council_room);
	printf("Player 0 has %d cards in discard pile.\n", player_0_discard_count_before_council_room);
	printf("Player 1 has %d cards in hand.\n", player_1_hand_count_before_council_room);
	printf("Player 1 has %d cards in deck.\n", player_1_deck_count_before_council_room);
	printf("Player 1 has %d cards in discard pile.\n", player_1_discard_count_before_council_room);
	printf("There have been %d played cards.\n", played_card_count_before_council_room);

	cardEffect(council_room, choice1, choice2, choice3, &game_state, hand_position, &bonus);

	int player_0_hand_count_after_council_room = game_state.handCount[0];
	int player_0_deck_count_after_council_room = game_state.deckCount[0];
	int player_0_discard_count_after_council_room = game_state.discardCount[0];
	int player_1_hand_count_after_council_room = game_state.handCount[1];
	int player_1_deck_count_after_council_room = game_state.deckCount[1];
	int player_1_discard_count_after_council_room = game_state.discardCount[1];
	int played_card_count_after_council_room = game_state.playedCardCount;
	int supply_count_after_council_room[treasure_map+1];
	for (index = 0; index < treasure_map+1; index++) {
		supply_count_after_council_room[index] = supplyCount(index, &game_state);
	}
	int embargo_tokens_after_council_room[treasure_map+1];
	for (index = 0; index < treasure_map+1; index++) {
		embargo_tokens_after_council_room[index] = game_state.embargoTokens[index];
	}
	int outpost_played_after_council_room = game_state.outpostPlayed;
  	int outpost_turn_after_council_room = game_state.outpostTurn;
  	int whose_turn_after_council_room = game_state.whoseTurn;
  	int phase_after_council_room = game_state.phase;
  	int number_of_actions_after_council_room = game_state.numActions;
  	int coins_after_council_room = game_state.coins;
  	int num_buys_after_council_room = game_state.numBuys;

	printf("\tAFTER PLAYING CARD\n");
	printf("Player 0 has %d cards in hand.\n", player_0_hand_count_after_council_room);
	printf("Player 0 has %d cards in deck.\n", player_0_deck_count_after_council_room);
	printf("Player 0 has %d cards in discard pile.\n", player_0_discard_count_after_council_room);
	printf("Player 1 has %d cards in hand.\n", player_1_hand_count_after_council_room);
	printf("Player 1 has %d cards in deck.\n", player_1_deck_count_after_council_room);
	printf("Player 1 has %d cards in discard pile.\n", player_1_discard_count_after_council_room);
	printf("There have been %d played cards.\n", played_card_count_after_council_room);

	int number_of_errors = 0;
	printf("********** CHECKING FOR ERRORS **********\n");
	int expected_player_0_hand_count_after_council_room = player_0_hand_count_before_council_room + (4 - 1);
	if (player_0_hand_count_after_council_room != expected_player_0_hand_count_after_council_room) {
		printf("Error: Player 0 should have %d cards in hand after playing council_room.\n", expected_player_0_hand_count_after_council_room);
		number_of_errors++;
	}

	int expected_player_0_deck_count_after_council_room = player_0_deck_count_before_council_room - 4;
	if (expected_player_0_deck_count_after_council_room != player_0_deck_count_after_council_room) {
		printf("Error: Player 0 should have %d cards in deck after playing council_room.\n", expected_player_0_deck_count_after_council_room);
		number_of_errors++;
	}

	int expected_player_0_discard_count_after_council_room = 0;
	if (expected_player_0_discard_count_after_council_room != player_0_discard_count_after_council_room) {
		printf("Error: Player 0 should have %d cards in discard pile after playing council_room.\n", expected_player_0_discard_count_after_council_room);
		number_of_errors++;
	}

	int expected_player_1_hand_count_after_council_room = player_1_hand_count_before_council_room + 1;
	if (expected_player_1_hand_count_after_council_room != player_1_hand_count_after_council_room) {
		printf("Error: Player 1 should have %d cards in hand after playing council_room.\n", expected_player_1_hand_count_after_council_room);
		number_of_errors++;
	}

	int expected_player_1_deck_count_after_council_room = player_1_deck_count_before_council_room - 1;
	if (expected_player_1_deck_count_after_council_room != player_1_deck_count_after_council_room) {
		printf("Error: Player 1 should have %d cards in deck after playing council_room.\n", expected_player_1_deck_count_after_council_room);
		number_of_errors++;
	}

	int expected_player_1_discard_count_after_council_room = 0;
	if (expected_player_1_discard_count_after_council_room != player_1_discard_count_after_council_room) {
		printf("Error: Player 0 should have %d cards in discard pile after playing council_room.\n", expected_player_1_discard_count_after_council_room);
		number_of_errors++;
	}

	int expected_played_cards_count = 1;
	if (expected_played_cards_count != played_card_count_after_council_room) {
		printf("Error: Expected %d played card count.\n", expected_played_cards_count);
		number_of_errors++;
	}

	for (index = 0; index < treasure_map+1; index++) {
		if (supply_count_before_council_room[index] != supply_count_after_council_room[index]) {
			printf("Error: Supply counts changed as a result of playing council_room.\n");
			number_of_errors++;
		}
	}

	for (index = 0; index < treasure_map+1; index++) {
		if (embargo_tokens_before_council_room[index] != embargo_tokens_after_council_room[index]) {
			printf("Error: Embargo tokens counts changed as a result of playing council_room.\n");
			number_of_errors++;
		}
	}

	if (outpost_played_before_council_room != outpost_played_after_council_room) {
		printf("Error: Outposts played changed as a result of playing council_room.\n");
		number_of_errors++;
	}

	if (outpost_turn_before_council_room != outpost_turn_after_council_room) {
		printf("Error: Outpost turn changed as a result of playing council_room.\n");
		number_of_errors++;
	}

	if (whose_turn_before_council_room != whose_turn_after_council_room) {
		printf("Error: Turn changed as a result of playing council_room.\n");
		number_of_errors++;
	}

	if (phase_before_council_room != phase_after_council_room) {
		printf("Error:  Phase changed as a result of playing council_room.\n");
		number_of_errors++;
	}

	if (number_of_actions_before_council_room != number_of_actions_after_council_room) {
		printf("Error: Number of actions changed as a result of playing council_room.\n");
		number_of_errors++;
	}

	if (coins_before_council_room != coins_after_council_room) {
		printf("Error: Number of coins changed as a result of playing council_room.\n");
		number_of_errors++;
	}

	int expected_number_of_buys = num_buys_before_council_room + 1;
	if (expected_number_of_buys != num_buys_after_council_room) {
		printf("Error: There should be %d buys after playing council_room.\n", expected_number_of_buys);
		number_of_errors++;
	}

	printf("Number of errors found: %d\n", number_of_errors);

	return 0;
}