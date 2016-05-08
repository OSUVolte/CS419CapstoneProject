/*
	File Name:		randomtestadeventurer.c
	Author:			Marc Clinedinst
	Last Modified: 	1 May 2016
	Description:	This file contains a random tester for the Adventurer card in the dominion card game.
					Specifically, it performs several randomized tests to confirm the effect that the 
					Adventurer card has on the state of the game.  The randomized tests test the effect of 
					the Adventurer card under the following scenarios:
							1.  The player playing the card has a random hand (containing at least one
							adventurer card).
							2.  The player playing the card has a random deck.
							3.  The player playing the card has a random hand (containing at least one
							adventurer card) and random deck.
							4.  There is a random number of players, and the player playing the card has
							a random hand (containing at least one adventurer card) and a random deck).
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
	Function Name:  get_treasure_count
	Parameters:		This function expects a gameState structure and an integer representing the current player.
	Description:	This function counts the amount of treasure that is currently in the player's hand.  It does so
					by looping through the hand and checking each card; if the card is copper, silver, or gold, the
					number of treasure is incremented.  The amount of treasure is returned at the end of the function.
*/
int get_treasure_count(struct gameState game_state, int player) {
	int index,
		player_treasure_count = 0;

	for (index = 0; index < game_state.handCount[player]; index++) {
  		if (game_state.hand[player][index] == copper || game_state.hand[player][index] == silver || game_state.hand[player][index] == gold) {
  			player_treasure_count++;
  		} 
  	}

  	return player_treasure_count;
}

/*
	Function Name:  oracle_checks_expected_player_hand_counts_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played,
					and an integer representing the number of players.
	Description:	This function checks to make sure that the number of cards in each player's hand
					is correct after the current player has played the Adventurer card.  The current
					player's hand should increase by 1 (the player should receive to treasure cards
					and discard the Adventurer card, resulting in a net of +1 cards).  The hand counts
					should not change for any other player.
*/
void oracle_checks_expected_player_hand_counts_after_card_played(struct gameState game_state, struct gameState saved_game_state, int number_of_players) {
	if (game_state.handCount[0] != (saved_game_state.handCount[0] + 1)) {
		printf("\tFAILED:  Player 0 should have %d cards in hand but has %d.\n", (saved_game_state.handCount[0] + 2 - 1), game_state.handCount[0]);
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
	Function Name:  oracle_checks_expected_player_treasure_counts_after_card_played
	Parameters:		This function expects a gameState structure representing the current game state,
					a gameState structure representing the game state before the card was played,
					and an integer representing the number of players.
	Description:	This function checks to make sure that the treasure count for the current player
					increased by 2 as a result of playing the card.  It also checks to make sure that
					the other player's treasure counts did not change as a result of playing the card.
*/
void oracle_checks_expected_player_treasure_counts_after_card_played(struct gameState game_state, struct gameState saved_game_state, int number_of_players) {
	if (get_treasure_count(game_state, 0) != (get_treasure_count(saved_game_state, 0) + 2)) {
		printf("\tFAILED:  Player 0's treasure count should be %d but is %d.\n", (get_treasure_count(saved_game_state, 0) + 2), get_treasure_count(game_state, 0));
	} else {
		printf("\tPASSED:  Player 0's treasure count is correct.\n");
	}

	int index;
	for (index = 1; index < number_of_players; index++) {
		if (get_treasure_count(game_state, index) != get_treasure_count(saved_game_state, index)) {
			printf("\tFAILED:  Player %d's treasure count should be %d but is %d.\n", index, get_treasure_count(saved_game_state, index), get_treasure_count(game_state, index));
		} else {
			printf("\tPASSED:  Player %d's treasure count is correct.\n", index);
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
	Description:	This function checks to make sure that the number of actions did not change as a result
					of playing the card.
*/
void oracle_checks_number_of_actions_after_card_played(struct gameState game_state, struct gameState saved_game_state) {
	if (game_state.numActions != saved_game_state.numActions) {
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
	oracle_checks_expected_player_treasure_counts_after_card_played(game_state, saved_game_state, number_of_players);
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
		In this test, we begin by initializing the game so that the player has five cards in their hand.  We ensure that 
		the player has an adventurer card in their hand in the first position.  We then randomize the remaining cards in
		the player's hand.  After the player's hand is set up, we save the game_state so that we can perform the relevant
		comparisons.  We then alow the adventurer card to have its effect, and compare the game's current state to the
		saved state to make sure that everything is correct.  We repeat this test 100 times.
	*/
	printf("RANDOM TEST #1:  Testing random hand.\n");
	int test_iteration;
	for (test_iteration = 0; test_iteration < 100; test_iteration++) {
		initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
		game_state.hand[0][0] = adventurer;
		
		int hand_index;
		for (hand_index = 1; hand_index < 5; hand_index++) {
			game_state.hand[0][hand_index] = kingdom_cards[rand() % 10];
		}

		memcpy(&saved_game_state, &game_state, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &game_state, hand_position, &bonus);
		oracle_performs_all_checks(game_state, saved_game_state, number_of_players);
	}

	/*
		RANDOM TEST #2:  Random deck
		In this test, we begin by initializing the game so that the player has five cards in their hand.  We ensure that
		the player has an adventurer card in their hand in the first position.  We then assign the player a random number
		of treasure cards in their deck between 2 and 7.  The remaining cards are set up as estate cards.  We then copy
		the current game state over so that we can compare it after applying the card's effect.  Then we apply the card
		effect and compare the state before and after the card effect to make sure that everything is correct.  We repeat
		this test 100 times.
	*/
	printf("RANDOM TEST #2:  Testing random deck.\n");
	for (test_iteration = 0; test_iteration < 100; test_iteration++) {
		initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
		game_state.hand[0][0] = adventurer;

		int number_of_treasures = rand() % 6 + 2,
			deck_index;
		for (deck_index = 0; deck_index < number_of_treasures; deck_index++) {
			game_state.deck[0][deck_index] = copper;
		}
		for (; deck_index < 10; deck_index++) {
			game_state.deck[0][deck_index] = estate;
		}
		game_state.deckCount[0] = 10;

		memcpy(&saved_game_state, &game_state, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &game_state, hand_position, &bonus);
		oracle_performs_all_checks(game_state, saved_game_state, number_of_players);
	}

	/*
		RANDOM TEST #3:  Random hand and random deck
		In this test, we begin by initializing the game so that the player has five cards in their hand.  We ensure that
		the player has an adventurer card in their hand in the first position.  We then assign the player a random hand
		of cards from the kingdom cards that are available.  We then assign the player a random number of treasure cards
		in their deck between 2 and 7.  The remaining cards are set up as estate cards.  We then copy the current game
		state over so that we can compare it after applying the card's effect.  Then we apply the card effect and compare
		the state before and after the card effect to make sure that everything is correct.  We repeat this test 100 times.
	*/
	printf("RANDOM TEST #3:  Testing random hand and random deck.\n");
	for (test_iteration = 0; test_iteration < 100; test_iteration++) {
		initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
		game_state.hand[0][0] = adventurer;
		
		int hand_index;
		for (hand_index = 1; hand_index < 5; hand_index++) {
			game_state.hand[0][hand_index] = kingdom_cards[rand() % 10];
		}

		int number_of_treasures = rand() % 6 + 2,
			deck_index;
		for (deck_index = 0; deck_index < number_of_treasures; deck_index++) {
			game_state.deck[0][deck_index] = copper;
		}
		for (; deck_index < 10; deck_index++) {
			game_state.deck[0][deck_index] = estate;
		}
		game_state.deckCount[0] = 10;

		memcpy(&saved_game_state, &game_state, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &game_state, hand_position, &bonus);
		oracle_performs_all_checks(game_state, saved_game_state, number_of_players);
	}

	/*
		RANDOM TEST #4:  Random hand, random deck, random number of players.
		In this test, we begin by randomizing the number of players; this number should be between 2 and 4. Next, we
		initialize the game so that the player has an adventurer card in their hand along with four other random cards
		from the available kingdom cards.  We then set up the deck so that it has a random number of treasure cards between
		2 and 7 in the deck.  We then copy this game state over to a saved state.  Finally, we apply the card effect and
		make sure that everything is correct using the oracle.  We repeat these steps 100 times.
	*/
	printf("RANDOM TEST #4:  Testing random hand, random deck, random number of players.\n");
	for (test_iteration = 0; test_iteration < 100; test_iteration++) {
		number_of_players = rand() % 3 + 2;
		initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
		game_state.hand[0][0] = adventurer;
		
		int hand_index;
		for (hand_index = 1; hand_index < 5; hand_index++) {
			game_state.hand[0][hand_index] = kingdom_cards[rand() % 10];
		}

		int number_of_treasures = rand() % 6 + 2,
			deck_index;
		for (deck_index = 0; deck_index < number_of_treasures; deck_index++) {
			game_state.deck[0][deck_index] = copper;
		}
		for (; deck_index < 10; deck_index++) {
			game_state.deck[0][deck_index] = estate;
		}
		game_state.deckCount[0] = 10;

		memcpy(&saved_game_state, &game_state, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &game_state, hand_position, &bonus);
		oracle_performs_all_checks(game_state, saved_game_state, number_of_players);
	}

	return 0;
}