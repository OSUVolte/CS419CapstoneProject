#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 0
#define NOISY_TEST 1

void check_full_deck_count_after_initial_setup(int number_of_players) {
	int kingdom_cards[] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall },
		random_seed = 1;
	struct gameState game_state;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);
	int current_player;

	printf("*** TESTING fullDeckCount ON INITIAL SETUP OF GAME WITH %d PLAYERS***\n", number_of_players);
	printf("Checking initial counts of each player's full deck.\n");
	for (current_player = 0; current_player < number_of_players; current_player++) {
		printf("\tChecking that player %d has 3 estate cards.", current_player);
		assert(fullDeckCount(current_player, estate, &game_state) == 3);
		printf(" --- PASSED!\n");
		printf("\tChecking that player %d has 7 copper cards.", current_player);
		assert(fullDeckCount(current_player, copper, &game_state) == 7);
		printf(" --- PASSED!\n");
	}
}

void check_full_deck_count_after_buying_card() {
	int number_of_players = 2,
		kingdom_cards[] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall },
		random_seed = 1;
	struct gameState game_state;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);

	printf("*** TESTING fullDeckCount AFTER PURCHASING CARD ***\n");
	printf("\tChecking that player has 3 estate cards.");
	assert(fullDeckCount(0, estate, &game_state) == 3);
	printf(" --- PASSED!\n");
	printf("\tChecking that player has 7 copper cards.");
	assert(fullDeckCount(0, copper, &game_state) == 7);
	printf(" --- PASSED!\n");
	printf("\tChecking that player has 4 estate cards after purchasing estate.");
	buyCard(estate, &game_state);
	assert(fullDeckCount(0, estate, &game_state) == 4);
	printf(" --- PASSED!\n");
}

void check_full_deck_count_after_discarding_card() {
	int number_of_players = 2,
		kingdom_cards[] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall },
		random_seed = 1;
	struct gameState game_state;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);

	printf("*** TESTING fullDeckCount AFTER DISCARDING CARD ***\n");
	printf("\tChecking that player's deck has 3 estate cards.");
	assert(fullDeckCount(0, estate, &game_state) == 3);
	printf(" --- PASSED!\n");
	printf("\tChecking that player's deck has 7 copper cards.");
	assert(fullDeckCount(0, copper, &game_state) == 7);
	printf(" --- PASSED!\n");
	printf("\tChecking that player's deck has 1 fewer card after discarding card.");
	discardCard(0, 0, &game_state, 0);
	assert(fullDeckCount(0, estate, &game_state) + fullDeckCount(0, copper, &game_state) == 9);
	printf(" --- PASSED!\n");
}

void check_full_deck_count_after_mix_of_buys_and_discards() {
	int number_of_players = 2,
		kingdom_cards[] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall },
		random_seed = 1;
	struct gameState game_state;
	initializeGame(number_of_players, kingdom_cards, random_seed, &game_state);	

  	game_state.numBuys = 2;
  	game_state.hand[0][0] = gold;
  	game_state.hand[0][1] = gold;
  	game_state.hand[0][2] = estate;
  	game_state.hand[0][3] = estate;
  	game_state.handCount[0] = 4;
  	game_state.deck[0][0] = estate;
  	game_state.deck[0][1] = adventurer;
  	game_state.deck[0][2] = copper;
  	game_state.deck[0][3] = copper;
  	game_state.deck[0][4] = copper;
  	game_state.deck[0][5] = copper;
  	game_state.deck[0][6] = copper;
  	game_state.deck[0][7] = copper;
  	game_state.deck[0][8] = copper;
  	game_state.deck[0][9] = great_hall;
  	game_state.deckCount[0] = 10;
  	game_state.discard[0][0] = gardens;
  	game_state.discard[0][1] = gardens;
  	game_state.discardCount[0] = 2;

  	updateCoins(0, &game_state, 0);

	printf("*** TESTING fullDeckCount AFTER MIX OF BUYS AND PURCHASES ***\n");
	printf("*** Deck initially contains 1 adventure, 7 copper, 3 estate, 2 gardens, 2 gold, 1 great hall.");
	printf("*** Player has 2 buys and 6 coins in hand at beginning of test.\n");
	printf("\tChecking that player's deck initially has 1 adventurer card.");
	assert(fullDeckCount(0, adventurer, &game_state) == 1);
	printf(" --- PASSED!\n");
	assert(fullDeckCount(0, estate, &game_state) == 3);
	printf("\tChecking that player's deck has 7 copper cards.");
	assert(fullDeckCount(0, copper, &game_state) == 7);
	printf(" --- PASSED!\n");	
	printf("\tChecking that player's deck has 3 estate cards.");
	assert(fullDeckCount(0, estate, &game_state) == 3);
	printf(" --- PASSED!\n");
	printf("\tChecking that player's deck has 2 garden cards.");
	assert(fullDeckCount(0, gardens, &game_state) == 2);
	printf(" --- PASSED!\n");
	printf("\tChecking that player's deck has 2 gold cards.");
	assert(fullDeckCount(0, gold, &game_state) == 2);
	printf(" --- PASSED!\n");
	printf("\tChecking that player's deck has 1 great hall card.");
	assert(fullDeckCount(0, great_hall, &game_state) == 1);
	printf(" --- PASSED!\n");
	printf("\tBuying village card.\n");
	buyCard(village, &game_state);
	printf("\tChecking that player's deck has 1 village card.");
	assert(fullDeckCount(0, village, &game_state) == 1);
	printf(" --- PASSED!\n");
	printf("\tBuying great_hall card.\n");
	buyCard(great_hall, &game_state);
	printf("\tChecking that player's deck has 2 great hall cards.");
	assert(fullDeckCount(0, great_hall, &game_state) == 2);
	printf(" --- PASSED!\n");
	printf("\tDiscarding gold.\n");
	discardCard(0, 0, &game_state, 0);
	printf("\tChecking that player's deck has 1 gold card.");
	assert(fullDeckCount(0, gold, &game_state) == 1);
	printf(" --- PASSED!\n");
	printf("\tDiscarding gold.\n");
	discardCard(1, 0, &game_state, 0);
	printf("\tChecking that player's deck has 0 gold cards.");
	assert(fullDeckCount(0, gold, &game_state) == 0);
	printf(" --- PASSED!\n");
	printf("\tDiscarding estate.\n");
	discardCard(2, 0, &game_state, 0);
	printf("\tChecking that player's deck has 2 estate cards.");
	assert(fullDeckCount(0, estate, &game_state) == 2);
	printf(" --- PASSED!\n");
	printf("\tDiscarding estate.\n");
	discardCard(3, 0, &game_state, 0);
	printf("\tChecking that player's deck has 1 estate cards.");
	assert(fullDeckCount(0, estate, &game_state) == 1);
	printf(" --- PASSED!\n");
}

int main(void) {
	check_full_deck_count_after_initial_setup(2);
	check_full_deck_count_after_initial_setup(3);
	check_full_deck_count_after_initial_setup(4);
	check_full_deck_count_after_buying_card();
	check_full_deck_count_after_discarding_card();
	check_full_deck_count_after_mix_of_buys_and_discards();

	return 0;
}