/*
	File Name:		randomtestadeventurer.c
	Author:			Marc Clinedinst
	Last Modified: 	1 May 2016
	Description:	This file contains a random tester for the Village card in the dominion card game.
					Specifically, it performs several randomized tests to confirm the effect the Village 
					card has on the state of the game.  The randomized tests test the effect of the 
					Village card under the following scenarios:
							1.  The player playing the card has a random hand (containing at least one
							village card).
							2.  The game has a random number of players.
							3.  The player playing the card has a random number of actions, and there are
							a random number of player.
							4.  The player playing the card has a random hand (containing at least one
							village card).  There are also a random number of players, and the player
							playing the card has a random number of actions.
					Each of the four random tests above is performed 100 times per run of the tests.
*/
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Function Name:  oracle_checks_expected_player_hand_counts_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played,
					and an integer representing the number of players.
	Description:	This function checks to make sure that the number of cards in each player's hand
					is correct after the current player has played the Adventurer card.  The current
					player's hand should remain the same (the player should receive one more card
					and discard the Adventurer card, resulting in a net of +0 cards).  The hand counts
					should not change for any other player.
*/
void oracle_checks_expected_player_hand_counts_after_card_played(struct gameState game_state, struct gameState saved_game_state, int number_of_players) {
	if (game_state.handCount[0] != saved_game_state.handCount[0]) {
		printf("\tFAILED:  Player 0 should have %d cards in hand but has %d.\n", saved_game_state.handCount[0], game_state.handCount[0]);
	} else {
		printf("\tPASSED:  Player 0's hand count is correct after playing Adventurer card.\n");
	}

	int index;
	for (index = 1; index < number_of_players; index++) {
		if (game_state.handCount[index] != saved_game_state.handCount[index]) {
			printf("\tFAILED:  Player %d's hand count changed as a result of playing card.\n", index);
		} else {
			printf("\tPASSED:  Player %d's hand count did not change.\n", index);
		}
	}
}

/*
	Function Name:  oracle_checks_expected_player_deck_counts_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played,
					and an integer representing the number of players.
	Description:	This function checks to make sure that the deck counts for all players who are not
					current player did not change as a result of the card.
*/
void oracle_checks_expected_player_deck_counts_after_card_played(struct gameState game_state, struct gameState saved_game_state, int number_of_players) {
	int index;
	for (index = 1; index < number_of_players; index++) {
		if (game_state.deckCount[index] != saved_game_state.deckCount[index]) {
			printf("\tFAILED:  Player %d's deck count changed as a result of playing card.\n", index);
		} else {
			printf("\tPASSED:  Player %d's deck count did not change.\n", index);
		}
	}
}

/*
	Function Name:  oracle_checks_expected_player_discard_counts_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played,
					and an integer representing the number of players.
	Description:	This function checks to make sure that the discard counts for all players who are not
					current player did not change as a result of the card.
*/
void oracle_checks_expected_player_discard_counts_after_card_played(struct gameState game_state, struct gameState saved_game_state, int number_of_players) {
	int index;
	for (index = 1; index < number_of_players; index++) {
		if (game_state.discardCount[index] != saved_game_state.discardCount[index]) {
			printf("\tFAILED:  Player %d's discard count changed as a result of playing card.\n", index);
		} else {
			printf("\tPASSED:  Player %d's discard count did not change.\n", index);
		}
	}
}

/*
	Function Name:  oracle_checks_expected_played_card_count_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played.
	Description:	This function checks to make sure that the played card count is correct after the
					current player has played their card.  The played card count should increase by one.
*/
void oracle_checks_expected_played_card_count_after_card_played(struct gameState game_state, struct gameState saved_game_state) {
	if (game_state.playedCardCount != (saved_game_state.playedCardCount + 1)) {
		printf("\tFAILED:  Played card count should be %d but is %d.\n", (saved_game_state.playedCardCount + 1), game_state.playedCardCount);
	} else {
		printf("\tPASSED:  Played card count is correct.\n");
	}
}

/*
	Function Name:  oracle_checks_expected_supply_counts_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played.
	Description:	This function checks to make sure that the supply counts did not change as a result
					of playing the card.
*/
void oracle_checks_expected_supply_counts_after_card_played(struct gameState game_state, struct gameState saved_game_state) {
	int index, error = 0;
	for (index = 0; index < treasure_map + 1; index++) {
		if (supplyCount(index, &game_state) != supplyCount(index, &saved_game_state)) {
			error = 1;
			printf("\tFAILED:  Supply count is incorrect for card at index %d.\n", index);
		}
	}
	if (!error) {
		printf("\tPASSED:  Supply counts are correct.\n");
	}
}

/*
	Function Name:  oracle_checks_expected_embargo_token_counts_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played.
	Description:	This function checks to make sure that the embargo token counts did not change as a result
					of playing the card.
*/
void oracle_checks_expected_embargo_token_counts_after_card_played(struct gameState game_state, struct gameState saved_game_state) {
	int index, error = 0;
	for (index = 0; index < treasure_map + 1; index++) {
		if (game_state.embargoTokens[index] != saved_game_state.embargoTokens[index]) {
			error = 1;
			printf("\tFAILED:  Embargo tokens count is incorrect for card at index %d.\n", index);
		}
	}
	if (!error) {
		printf("\tPASSED:  Embargo tokens counts are correct.\n");
	}
}

/*
	Function Name:  oracle_checks_outpost_played_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played.
	Description:	This function checks to make sure that the outposts played counts did not change as a result
					of playing the card.
*/
void oracle_checks_outpost_played_after_card_played(struct gameState game_state, struct gameState saved_game_state) {
	if (game_state.outpostPlayed != saved_game_state.outpostPlayed) {
		printf("\tFAILED:  Outpost played is not correct.\n");
	} else {
		printf("\tPASSED:  Outpost played is correct.\n");
	}
}

/*
	Function Name:  oracle_checks_outpost_turn_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played.
	Description:	This function checks to make sure that the outposts turn did not change as a result
					of playing the card.
*/
void oracle_checks_outpost_turn_after_card_played(struct gameState game_state, struct gameState saved_game_state) {
	if (game_state.outpostTurn != saved_game_state.outpostTurn) {
		printf("\tFAILED:  Outpost turn is not correct.\n");
	} else {
		printf("\tPASSED:  Outpost turn is correct.\n");
	}
}

/*
	Function Name:  oracle_checks_whose_turn_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played.
	Description:	This function checks to make sure that the turn did not change as a result
					of playing the card.
*/
void oracle_checks_whose_turn_after_card_played(struct gameState game_state, struct gameState saved_game_state) {
	if (game_state.whoseTurn != saved_game_state.whoseTurn) {
		printf("\tFAILED:  Whose turn is not correct.\n");
	} else {
		printf("\tPASSED:  Whose turn is correct.\n");
	}
}

/*
	Function Name:  oracle_checks_phase_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played.
	Description:	This function checks to make sure that the phase did not change as a result
					of playing the card.
*/
void oracle_checks_phase_after_card_played(struct gameState game_state, struct gameState saved_game_state) {
	if (game_state.phase != saved_game_state.phase) {
		printf("\tFAILED:  Phase is not correct.\n");
	} else {
		printf("\tPASSED:  Phase is correct.\n");
	}
}

/*
	Function Name:  oracle_checks_number_of_actions_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played.
	Description:	This function checks to make sure that the number of actions increased by 2 for
					the current player aft the Village card is played.
*/
void oracle_checks_number_of_actions_after_card_played(struct gameState game_state, struct gameState saved_game_state) {
	if (game_state.numActions != (saved_game_state.numActions + 2)) {
		printf("\tFAILED:  Number of actions is not correct.\n");
	} else {
		printf("\tPASSED:  Number of actions is correct.\n");
	}
}

/*
	Function Name:  oracle_checks_number_of_coins_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played.
	Description:	This function checks to make sure that the number of coins did not change as a result
					of playing the card.
*/
void oracle_checks_number_of_coins_after_card_played(struct gameState game_state, struct gameState saved_game_state) {
	if (game_state.coins != saved_game_state.coins) {
		printf("\tFAILED:  Number of coins is not correct.\n");
	} else {
		printf("\tPASSED:  Number of coins is correct.\n");
	}
}

/*
	Function Name:  oracle_checks_number_of_buys_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played.
	Description:	This function checks to make sure that the number of buys did not change as a result
					of playing the card.
*/
void oracle_checks_number_of_buys_after_card_played(struct gameState game_state, struct gameState saved_game_state) {
	if (game_state.numBuys != saved_game_state.numBuys) {
		printf("\tFAILED:  Number of buys is not correct.\n");
	} else {
		printf("\tPASSED:  Number of buys is correct.\n");
	}
}

/*
	Function Name:  oracle_performs_all_checks
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played,
					and an integer representing the number of players.
	Description:	This function simply causes the oracle to perform all of the checks to verify that
					the state of the game is correct after the card has been played.
*/
void oracle_performs_all_checks(struct gameState game_state, struct gameState saved_game_state, int number_of_players) {
	oracle_checks_expected_player_hand_counts_after_card_played(game_state, saved_game_state, number_of_players);
	oracle_checks_expected_player_deck_counts_after_card_played(game_state, saved_game_state, number_of_players);
	oracle_checks_expected_player_discard_counts_after_card_played(game_state, saved_game_state, number_of_players);
	oracle_checks_expected_played_card_count_after_card_played(game_state, saved_game_state);
	oracle_checks_expected_supply_counts_after_card_played(game_state, saved_game_state);
	oracle_checks_expected_embargo_token_counts_after_card_played(game_state, saved_game_state);
	oracle_checks_outpost_played_after_card_played(game_state, saved_game_state);
	oracle_checks_outpost_turn_after_card_played(game_state, saved_game_state);
	oracle_checks_whose_turn_after_card_played(game_state, saved_game_state);
	oracle_checks_number_of_actions_after_card_played(game_state, saved_game_state);
	oracle_checks_number_of_coins_after_card_played(game_state, saved_game_state);
	oracle_checks_number_of_buys_after_card_played(game_state, saved_game_state);	
}

/*
	Function Name: 	main
	Parameters:     None
	Description:    This function holds the code for all of the random tests that will be performed.  Each of the random
					tests is described in detail by a descriptive comment which precedes the text.  These tests are prefaced
					by text in the following pattern:  RANDOM TEST #<digit>: <description of test>
*/
int main(void) {	
	srand(time(NULL));
	int number_of_players = 2,
		kingdom_cards[] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall },
		random_seed = 2,
		choice1 = 0,
		choice2 = 0,
		choice3 = 0,
		hand_position = 0,
		bonus = 0;
	struct gameState game_state, saved_game_state;

	/*
		RANDOM TEST #1:  Random hand
	*/
	printf("RANDOM TEST #1:  Testing random hand.\n");
	int test_iteration;
	for (test_iteration = 0; test_iteration < 100; test_iteration++) {
		initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
		game_state.hand[0][0] = village;
		
		int hand_index;
		for (hand_index = 1; hand_index < 5; hand_index++) {
			game_state.hand[0][hand_index] = kingdom_cards[rand() % 10];
		}

		memcpy(&saved_game_state, &game_state, sizeof(struct gameState));
		cardEffect(village, choice1, choice2, choice3, &game_state, hand_position, &bonus);
		oracle_performs_all_checks(game_state, saved_game_state, number_of_players);
	}

	/*
		RANDOM TEST #2:  Random number of players
	*/
	printf("RANDOM TEST #2:  Testing random number of players.\n");
	for (test_iteration = 0; test_iteration < 100; test_iteration++) {
		number_of_players = rand() % 3 + 2;
		initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
		game_state.hand[0][0] = village;
		memcpy(&saved_game_state, &game_state, sizeof(struct gameState));
		cardEffect(village, choice1, choice2, choice3, &game_state, hand_position, &bonus);
		oracle_performs_all_checks(game_state, saved_game_state, number_of_players);
	}

	/*
		Random TEST #3:  Random number of actions and random number of players
	*/
	printf("RANDOM TEST #3:  Testing random number of actions and random number of players.\n");
	for (test_iteration = 0; test_iteration < 100; test_iteration++) {
		number_of_players = rand() % 3 + 2;
		initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
		game_state.numActions = rand() % 4 + 1;
		game_state.hand[0][0] = village;
		memcpy(&saved_game_state, &game_state, sizeof(struct gameState));
		cardEffect(village, choice1, choice2, choice3, &game_state, hand_position, &bonus);
		oracle_performs_all_checks(game_state, saved_game_state, number_of_players);
	}

	/*
		RANDOM TEST #4:  Random hand, random number of players, random number of actions
	*/
	printf("RANDOM TEST #4:  Testing random hand, random number of players, random number of actions.\n");
	for (test_iteration = 0; test_iteration < 100; test_iteration++) {
		number_of_players = rand() % 3 + 2;
		initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
		game_state.numActions = rand() % 4 + 1;
		game_state.hand[0][0] = village;

		int hand_index;
		for (hand_index = 1; hand_index < 5; hand_index++) {
			game_state.hand[0][hand_index] = kingdom_cards[rand() % 10];
		}

		memcpy(&saved_game_state, &game_state, sizeof(struct gameState));
		cardEffect(village, choice1, choice2, choice3, &game_state, hand_position, &bonus);
		oracle_performs_all_checks(game_state, saved_game_state, number_of_players);
	}

	return 0;
}