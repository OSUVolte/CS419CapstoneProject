/*
	File Name:				cardtest1.c
	Author:					Marc Clinedinst
	Functionality Tested:	This unit test tests the Village card.
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

	/*
		In the lines below, we gather the relevant information for each of the
		players.  Specifically, we get their hand, deck, discard, and played
		card counts.  We also get the supply count, embargo tokens, outpost
		whose turn, number of actions, number of coins, and number of buys.
		This information is stored so that it can be compared after the
		card has its effect.
	*/
	int player_0_hand_count_before_village = game_state.handCount[0];
	int player_0_deck_count_before_village = game_state.deckCount[0];
	int player_0_discard_count_before_village = game_state.discardCount[0];
	int player_1_hand_count_before_village = game_state.handCount[1];
	int player_1_deck_count_before_village = game_state.deckCount[1];
	int player_1_discard_count_before_village = game_state.discardCount[1];
	int played_card_count_before_village = game_state.playedCardCount;
	int supply_count_before_village[treasure_map+1];
	for (index = 0; index < treasure_map+1; index++) {
		supply_count_before_village[index] = supplyCount(index, &game_state);
	}
	int embargo_tokens_before_village[treasure_map+1];
	for (index = 0; index < treasure_map+1; index++) {
		embargo_tokens_before_village[index] = game_state.embargoTokens[index];
	}
	int outpost_played_before_village = game_state.outpostPlayed;
  	int outpost_turn_before_village = game_state.outpostTurn;
  	int whose_turn_before_village = game_state.whoseTurn;
  	int phase_before_village = game_state.phase;
  	int number_of_actions_before_village = game_state.numActions;
  	int coins_before_village = game_state.coins;
  	int num_buys_before_village = game_state.numBuys;

  	/*
  		Print out the current state of the game.
  	*/
  	printf("**********\n");
	printf("CARD TEST # 3\n");
	printf("*********\n");
	printf("********** TESTING village CARD **********\n");
	printf("\tBEFORE PLAYING CARD\n");
	printf("Player 0 has %d cards in hand.\n", player_0_hand_count_before_village);
	printf("Player 0 has %d cards in deck.\n", player_0_deck_count_before_village);
	printf("Player 0 has %d cards in discard pile.\n", player_0_discard_count_before_village);
	printf("Player 1 has %d cards in hand.\n", player_1_hand_count_before_village);
	printf("Player 1 has %d cards in deck.\n", player_1_deck_count_before_village);
	printf("Player 1 has %d cards in discard pile.\n", player_1_discard_count_before_village);
	printf("There have been %d played cards.\n", played_card_count_before_village);

	/*
		Allow the card to have its effect.

		***NOTE:  The Village card should result in the player having 1 more card and
		2 more actions.  No additional changes sould occur to the game's state or the
		other player's hand.
	*/
	cardEffect(village, choice1, choice2, choice3, &game_state, hand_position, &bonus);

	/*
		Now that the card has had its effect, store the values of relevant game state
		data.  This data will then be compared to the state of the game before the 
		card was played, so that we can determine if the card had its intended effect
		on the state of the game.
	*/
	int player_0_hand_count_after_village = game_state.handCount[0];
	int player_0_deck_count_after_village = game_state.deckCount[0];
	int player_0_discard_count_after_village = game_state.discardCount[0];
	int player_1_hand_count_after_village = game_state.handCount[1];
	int player_1_deck_count_after_village = game_state.deckCount[1];
	int player_1_discard_count_after_village = game_state.discardCount[1];
	int played_card_count_after_village = game_state.playedCardCount;
	int supply_count_after_village[treasure_map+1];
	for (index = 0; index < treasure_map+1; index++) {
		supply_count_after_village[index] = supplyCount(index, &game_state);
	}
	int embargo_tokens_after_village[treasure_map+1];
	for (index = 0; index < treasure_map+1; index++) {
		embargo_tokens_after_village[index] = game_state.embargoTokens[index];
	}
	int outpost_played_after_village = game_state.outpostPlayed;
  	int outpost_turn_after_village = game_state.outpostTurn;
  	int whose_turn_after_village = game_state.whoseTurn;
  	int phase_after_village = game_state.phase;
  	int number_of_actions_after_village = game_state.numActions;
  	int coins_after_village = game_state.coins;
  	int num_buys_after_village = game_state.numBuys;

  	/*
  		Print out the game's state after playing the card.
  	*/
	printf("\tAFTER PLAYING CARD\n");
	printf("Player 0 has %d cards in hand.\n", player_0_hand_count_after_village);
	printf("Player 0 has %d cards in deck.\n", player_0_deck_count_after_village);
	printf("Player 0 has %d cards in discard pile.\n", player_0_discard_count_after_village);
	printf("Player 1 has %d cards in hand.\n", player_1_hand_count_after_village);
	printf("Player 1 has %d cards in deck.\n", player_1_deck_count_after_village);
	printf("Player 1 has %d cards in discard pile.\n", player_1_discard_count_after_village);
	printf("There have been %d played cards.\n", played_card_count_after_village);

	/*
		Below, we track the number of errors and print out any relevant error messages that
		occur.
	*/
	int number_of_errors = 0;
	printf("********** CHECKING FOR ERRORS **********\n");

	/*
		Player 0 should have the same number of cards but have discarded the Village card.
	*/
	int expected_player_0_hand_count_after_village = player_0_hand_count_before_village;
	if (player_0_hand_count_after_village != expected_player_0_hand_count_after_village) {
		printf("Error: Player 0 should have %d cards in hand after playing village.\n", expected_player_0_hand_count_after_village);
		number_of_errors++;
	}

	/*
		Player 0 should have 1 fewer cards in the deck.
	*/
	int expected_player_0_deck_count_after_village = player_0_deck_count_before_village - 1;
	if (expected_player_0_deck_count_after_village != player_0_deck_count_after_village) {
		printf("Error: Player 0 should have %d cards in deck after playing village.\n", expected_player_0_deck_count_after_village);
		number_of_errors++;
	}

	/*	
		Discards unchanged.
	*/
	int expected_player_0_discard_count_after_village = 0;
	if (expected_player_0_discard_count_after_village != player_0_discard_count_after_village) {
		printf("Error: Player 0 should have %d cards in discard pile after playing village.\n", expected_player_0_discard_count_after_village);
		number_of_errors++;
	}

	/*	
		Player 1 unchanged.
	*/
	int expected_player_1_hand_count_after_village = player_1_hand_count_before_village;
	if (expected_player_1_hand_count_after_village != player_1_hand_count_after_village) {
		printf("Error: Player 1 should have %d cards in hand after playing smith.\n", expected_player_1_hand_count_after_village);
		number_of_errors++;
	}

	/*	
		Player 1 unchanged.
	*/
	int expected_player_1_deck_count_after_village = player_1_deck_count_before_village;
	if (expected_player_1_deck_count_after_village != player_1_deck_count_after_village) {
		printf("Error: Player 1 should have %d cards in deck after playing smith.\n", expected_player_1_deck_count_after_village);
		number_of_errors++;
	}

	/*	
		Player 1 unchanged.
	*/
	int expected_player_1_discard_count_after_village = 0;
	if (expected_player_1_discard_count_after_village != player_1_discard_count_after_village) {
		printf("Error: Player 0 should have %d cards in discard pile after playing village.\n", expected_player_1_discard_count_after_village);
		number_of_errors++;
	}

	/*	
		Played 1 card (Village).
	*/
	int expected_played_cards_count = 1;
	if (expected_played_cards_count != played_card_count_after_village) {
		printf("Error: Expected %d played card count.\n", expected_played_cards_count);
		number_of_errors++;
	}

	/*
		Supply unchanged.
	*/
	for (index = 0; index < treasure_map+1; index++) {
		if (supply_count_before_village[index] != supply_count_after_village[index]) {
			printf("Error: Supply counts changed as a result of playing village.\n");
			number_of_errors++;
		}
	}

	/*
		Embargo unchanged.
	*/
	for (index = 0; index < treasure_map+1; index++) {
		if (embargo_tokens_before_village[index] != embargo_tokens_after_village[index]) {
			printf("Error: Embargo tokens counts changed as a result of playing village.\n");
			number_of_errors++;
		}
	}

	/*
		Outpost unchanged.
	*/
	if (outpost_played_before_village != outpost_played_after_village) {
		printf("Error: Outposts played changed as a result of playing village.\n");
		number_of_errors++;
	}

	/*
		Outpost unchanged.
	*/
	if (outpost_turn_before_village != outpost_turn_after_village) {
		printf("Error: Outpost turn changed as a result of playing village.\n");
		number_of_errors++;
	}

	/*
		Whose turn unchanged.
	*/
	if (whose_turn_before_village != whose_turn_after_village) {
		printf("Error: Turn changed as a result of playing village.\n");
		number_of_errors++;
	}

	/*
		Phase unchanged.
	*/
	if (phase_before_village != phase_after_village) {
		printf("Error:  Phase changed as a result of playing village.\n");
		number_of_errors++;
	}

	/*
		Player 0 should have 2 more actions.
	*/
	int expected_player_0_actions_after_village = number_of_actions_before_village + 2;
	if (expected_player_0_actions_after_village != number_of_actions_after_village) {
		printf("Error: Number of actions should be %d.\n", expected_player_0_actions_after_village);
		number_of_errors++;
	}

	/*
		No change in coins.		
	*/	
	if (coins_before_village != coins_after_village) {
		printf("Error: Number of coins changed as a result of playing village.\n");
		number_of_errors++;
	}

	/*
		No change in buys.
	*/
	if (num_buys_before_village != num_buys_after_village) {
		printf("Error: Number of buys changed as a result of playing village.\n");
		number_of_errors++;
	}

	printf("Number of errors found: %d\n", number_of_errors);

	return 0;
}