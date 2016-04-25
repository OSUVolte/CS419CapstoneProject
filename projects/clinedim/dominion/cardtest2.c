/*
	File Name:				cardtest1.c
	Author:					Marc Clinedinst
	Functionality Tested:	This unit test tests the adventurer card.
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
struct gameState {
  int outpostPlayed;
  int outpostTurn;
  int whoseTurn;
  int phase;
  int numActions; 
  int coins; 
  int numBuys;
*/

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
	int player_0_hand_count_before_adventurer = game_state.handCount[0];
	int player_0_deck_count_before_adventurer = game_state.deckCount[0];
	int player_0_discard_count_before_adventurer = game_state.discardCount[0];
	int player_0_treasure_count_before_adventurer = 0;
	for (index = 0; index < game_state.handCount[0]; index++) {
  		if (game_state.hand[0][index] == copper || game_state.hand[0][index] == silver || game_state.hand[0][index] == gold) {
  			player_0_treasure_count_before_adventurer++;
  		} 
  	}
	int player_1_hand_count_before_adventurer = game_state.handCount[1];
	int player_1_deck_count_before_adventurer = game_state.deckCount[1];
	int player_1_discard_count_before_adventurer = game_state.discardCount[1];
	int player_1_treasure_count_before_adventurer = 0;
	for (index = 0; index < game_state.handCount[1]; index++) {
  		if (game_state.hand[1][index] == copper || game_state.hand[1][index] == silver || game_state.hand[1][index] == gold) {
  			player_1_treasure_count_before_adventurer++;
  		} 
  	}
	int played_card_count_before_adventurer = game_state.playedCardCount;
	int supply_count_before_adventurer[treasure_map+1];
	for (index = 0; index < treasure_map+1; index++) {
		supply_count_before_adventurer[index] = supplyCount(index, &game_state);
	}
	int embargo_tokens_before_adventurer[treasure_map+1];
	for (index = 0; index < treasure_map+1; index++) {
		embargo_tokens_before_adventurer[index] = game_state.embargoTokens[index];
	}
	int outpost_played_before_adventurer = game_state.outpostPlayed;
  	int outpost_turn_before_adventurer = game_state.outpostTurn;
  	int whose_turn_before_adventurer = game_state.whoseTurn;
  	int phase_before_adventurer = game_state.phase;
  	int number_of_actions_before_adventurer = game_state.numActions;
  	int coins_before_adventurer = game_state.coins;
  	int num_buys_before_adventurer = game_state.numBuys;

  	/*
  		Print out the current state of the game.
  	*/
  	printf("**********\n");
	printf("CARD TEST # 2\n");
	printf("*********\n");
	printf("********** TESTING adventurer CARD **********\n");
	printf("\tBEFORE PLAYING CARD\n");
	printf("Player 0 has %d cards in hand.\n", player_0_hand_count_before_adventurer);
	printf("Player 0 has %d cards in deck.\n", player_0_deck_count_before_adventurer);
	printf("Player 0 has %d cards in discard pile.\n", player_0_discard_count_before_adventurer);
	printf("Player 0 has %d treasure in hand.\n", player_0_treasure_count_before_adventurer);
	printf("Player 1 has %d cards in hand.\n", player_1_hand_count_before_adventurer);
	printf("Player 1 has %d cards in deck.\n", player_1_deck_count_before_adventurer);
	printf("Player 1 has %d cards in discard pile.\n", player_1_discard_count_before_adventurer);
	printf("Player 1 has %d treasure in hand.\n", player_1_treasure_count_before_adventurer);
	printf("There have been %d played cards.\n", played_card_count_before_adventurer);

	/*
		Allow the card to have its effect.

		***NOTE:  The adventurer card should result in the Player drawing cards until
		the player has two additional treasure cards.  No additional changes to the game's
		state should occur.
	*/
	cardEffect(adventurer, choice1, choice2, choice3, &game_state, hand_position, &bonus);

	/*
		Now that the card has had its effect, store the values of relevant game state
		data.  This data will then be compared to the state of the game before the 
		card was played, so that we can determine if the card had its intended effect
		on the state of the game.
	*/
	int player_0_hand_count_after_adventurer = game_state.handCount[0];
	int player_0_deck_count_after_adventurer = game_state.deckCount[0];
	int player_0_discard_count_after_adventurer = game_state.discardCount[0];
	int player_0_treasure_count_after_adventurer = 0;
	for (index = 0; index < game_state.handCount[0]; index++) {
  		if (game_state.hand[0][index] == copper || game_state.hand[0][index] == silver || game_state.hand[0][index] == gold) {
  			player_0_treasure_count_after_adventurer++;
  		} 
  	}
	int player_1_hand_count_after_adventurer = game_state.handCount[1];
	int player_1_deck_count_after_adventurer = game_state.deckCount[1];
	int player_1_discard_count_after_adventurer = game_state.discardCount[1];
	int player_1_treasure_count_after_adventurer = 0;
	for (index = 0; index < game_state.handCount[1]; index++) {
  		if (game_state.hand[1][index] == copper || game_state.hand[1][index] == silver || game_state.hand[1][index] == gold) {
  			player_1_treasure_count_after_adventurer++;
  		} 
  	}
	int played_card_count_after_adventurer = game_state.playedCardCount;
	int supply_count_after_adventurer[treasure_map+1];
	for (index = 0; index < treasure_map+1; index++) {
		supply_count_after_adventurer[index] = supplyCount(index, &game_state);
	}
	int embargo_tokens_after_adventurer[treasure_map+1];
	for (index = 0; index < treasure_map+1; index++) {
		embargo_tokens_after_adventurer[index] = game_state.embargoTokens[index];
	}
	int outpost_played_after_adventurer = game_state.outpostPlayed;
  	int outpost_turn_after_adventurer = game_state.outpostTurn;
  	int whose_turn_after_adventurer = game_state.whoseTurn;
  	int phase_after_adventurer = game_state.phase;
  	int number_of_actions_after_adventurer = game_state.numActions;
  	int coins_after_adventurer = game_state.coins;
  	int num_buys_after_adventurer = game_state.numBuys;

  	/*
  		Print out the game's state after playing the card.
  	*/
	printf("\tAFTER PLAYING CARD\n");
	printf("Player 0 has %d cards in hand.\n", player_0_hand_count_after_adventurer);
	printf("Player 0 has %d cards in deck.\n", player_0_deck_count_after_adventurer);
	printf("Player 0 has %d cards in discard pile.\n", player_0_discard_count_after_adventurer);
	printf("Player 0 has %d treasure in hand.\n", player_0_treasure_count_after_adventurer);
	printf("Player 1 has %d cards in hand.\n", player_1_hand_count_after_adventurer);
	printf("Player 1 has %d cards in deck.\n", player_1_deck_count_after_adventurer);
	printf("Player 1 has %d cards in discard pile.\n", player_1_discard_count_after_adventurer);
	printf("Player 1 has %d treasure in hand.\n", player_1_treasure_count_after_adventurer);
	printf("There have been %d played cards.\n", played_card_count_after_adventurer);

	/*
		Below, we track the number of errors and print out any relevant error messages that
		occur.
	*/
	int number_of_errors = 0;
	printf("********** CHECKING FOR ERRORS **********\n");

	/*
		Player 0 should have 2 new treasure cards and have discarded the Adventurer card.
	*/
	int expected_player_0_hand_count_after_adventurer = player_0_hand_count_before_adventurer + 2 - 1;
	if (expected_player_0_hand_count_after_adventurer != player_0_hand_count_after_adventurer) {
		printf("Error: Player 0 should have %d cards in hand after playing adventurer.\n", expected_player_0_hand_count_after_adventurer);
		number_of_errors++;
	}

	/*
		Player 0 should have 2 fewer cards in the deck.
	*/
	int expected_player_0_deck_count_after_adventurer = player_0_deck_count_before_adventurer - 2;
	if (expected_player_0_deck_count_after_adventurer != player_0_deck_count_after_adventurer) {
		printf("Error: Player 0 should have %d cards in deck after playing adventurer.\n", expected_player_0_deck_count_after_adventurer);
		number_of_errors++;
	}

	/*	
		Discards unchanged.
	*/
	int expected_player_0_discard_count_after_adventurer = 0;
	if (expected_player_0_discard_count_after_adventurer != player_0_discard_count_after_adventurer) {
		printf("Error: Player 0 should have %d cards in discard pile after playing adventurer.\n", expected_player_0_discard_count_after_adventurer);
		number_of_errors++;
	}

	/*
		Player 0 should now have 2 more treasure than before.
	*/
	int expected_player_0_treasure_count_after_adventurer = player_0_treasure_count_before_adventurer + 2;
	if (expected_player_0_treasure_count_after_adventurer != player_0_treasure_count_after_adventurer) {
		printf("Error: Player 0 should have %d treasure in hand after playing adventurer.\n", expected_player_0_treasure_count_after_adventurer);
	}

	/*
		Player 1 unchanged.
	*/
	int expected_player_1_hand_count_after_smithy = player_1_hand_count_before_adventurer;
	if (expected_player_1_hand_count_after_smithy != player_1_hand_count_after_adventurer) {
		printf("Error: Player 1 should have %d cards in hand after playing smith.\n", expected_player_1_hand_count_after_smithy);
		number_of_errors++;
	}

	/*
		Player 1 unchanged.
	*/
	int expected_player_1_deck_count_after_smithy = player_1_deck_count_before_adventurer;
	if (expected_player_1_deck_count_after_smithy != player_1_deck_count_after_adventurer) {
		printf("Error: Player 1 should have %d cards in deck after playing smith.\n", expected_player_1_hand_count_after_smithy);
		number_of_errors++;
	}

	/*
		Player 1 unchanged.
	*/
	int expected_player_1_discard_count_after_adventurer = 0;
	if (expected_player_1_discard_count_after_adventurer != player_1_discard_count_after_adventurer) {
		printf("Error: Player 0 should have %d cards in discard pile after playing adventurer.\n", expected_player_1_discard_count_after_adventurer);
		number_of_errors++;
	}

	/*
		1 card has been played (Adventurer).
	*/
	int expected_played_cards_count = 1;
	if (expected_played_cards_count != played_card_count_after_adventurer) {
		printf("Error: Expected %d played card count.\n", expected_played_cards_count);
		number_of_errors++;
	}

	/*
		Supply count unchanged.
	*/
	for (index = 0; index < treasure_map+1; index++) {
		if (supply_count_before_adventurer[index] != supply_count_after_adventurer[index]) {
			printf("Error: Supply counts changed as a result of playing adventurer.\n");
			number_of_errors++;
		}
	}

	/*
		Embargo tokens unchanged.
	*/
	for (index = 0; index < treasure_map+1; index++) {
		if (embargo_tokens_before_adventurer[index] != embargo_tokens_after_adventurer[index]) {
			printf("Error: Embargo tokens counts changed as a result of playing adventurer.\n");
			number_of_errors++;
		}
	}

	/*
		Outposts unchanged.
	*/
	if (outpost_played_before_adventurer != outpost_played_after_adventurer) {
		printf("Error: Outposts played changed as a result of playing adventurer.\n");
		number_of_errors++;
	}

	/*
		Outposts unchanged.
	*/
	if (outpost_turn_before_adventurer != outpost_turn_after_adventurer) {
		printf("Error: Outpost turn changed as a result of playing adventurer.\n");
		number_of_errors++;
	}

	/*
		Whose turn unchanged.
	*/
	if (whose_turn_before_adventurer != whose_turn_after_adventurer) {
		printf("Error: Turn changed as a result of playing adventurer.\n");
		number_of_errors++;
	}

	/*
		Phase unchanged.
	*/
	if (phase_before_adventurer != phase_after_adventurer) {
		printf("Error:  Phase changed as a result of playing adventurer.\n");
		number_of_errors++;
	}

	/*
		Number of actions unchanged.
	*/
	if (number_of_actions_before_adventurer != number_of_actions_after_adventurer) {
		printf("Error: Number of actions changed as a result of playing adventurer.\n");
		number_of_errors++;
	}

	/*
		Coins unchanged.
	*/
	if (coins_before_adventurer != coins_after_adventurer) {
		printf("Error: Number of coins changed as a result of playing adventurer.\n");
		number_of_errors++;
	}

	/*
		Number of buys unchanged.
	*/
	if (num_buys_before_adventurer != num_buys_after_adventurer) {
		printf("Error: Number of buys changed as a result of playing adventurer.\n");
		number_of_errors++;
	}

	printf("Number of errors found: %d\n", number_of_errors);

	return 0;
}


