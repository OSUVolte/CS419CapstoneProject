#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define TRACERS 0

#define SEED_VAL 7

int checkFullDeckCount(int p, int card, struct gameState *post, int test_run, int card_count) {

	//print run complete
	if (TRACERS) printf("Test run #%d starting...\n", test_run);
	if (TRACERS) printf("Player #%d \n", p);
	if (TRACERS) printf("card #%d \n", card);

	
	//run shuffle and set r to zero
	int r = fullDeckCount(p, card, post);
	
	//assert that r = the expected card count
	assert (r == card_count);
	
	//print run complete
	printf("Test run #%d complete.\n", test_run);
	
	//return zero
	return 0;
}

void set_state(struct gameState *state, int state_option){
	
	int player_nbr;
	
	if (state_option==1){
		
		//set for 2 players
		state->numPlayers = 2;
	}
	
	//set state
	state->outpostPlayed = 0;
	state->outpostTurn = 1;
	state->whoseTurn = 0;
	state->phase = 0;
	state->coins = 2;
	state->numBuys = 1;
	state->playedCardCount = 0;
	state->supplyCount[1] = 0;
	state->embargoTokens[1] = 0;
	
	//player 0
	player_nbr = 0;
	state->hand[player_nbr][0] = 1;
	state->hand[player_nbr][1] = 2;
	state->handCount[player_nbr] = 2; //count
	
	state->deck[player_nbr][0] = 7;
	state->deck[player_nbr][1] = 6;
	state->deck[player_nbr][2] = 2;
	state->deck[player_nbr][3] = 4;
	state->deck[player_nbr][4] = 3;
	state->deckCount[player_nbr] = 5; //count
	
	state->discard[player_nbr][0] = 8;
	state->discard[player_nbr][1] = 2;
	state->discard[player_nbr][2] = 10;
	state->discardCount[player_nbr] = 3; //count
	
	//player 1
	player_nbr = 1;
	state->handCount[player_nbr] = 0; //count
	
	state->deck[player_nbr][0] = 8;
	state->deck[player_nbr][1] = 9;
	state->deck[player_nbr][2] = 10;
	state->deck[player_nbr][3] = 11;
	state->deckCount[player_nbr] = 4; //count
	
	state->discard[player_nbr][0] = 8;
	state->discard[player_nbr][1] = 9;
	state->discardCount[player_nbr] = 2; //count
	
	if(state_option >= 2){
		
		player_nbr = 2;
		
		state->numPlayers = 3;
		
		//player 2 (deck count is zero)
		state->handCount[player_nbr] = 0; //count
		
		state->deckCount[player_nbr] = 0; //count
		
		state->discard[player_nbr][0] = 8;
		state->discard[player_nbr][1] = 9;
		state->discardCount[player_nbr] = 2; //count
	}
	
	if(state_option >= 3){
		
		player_nbr = 3;
		
		state->numPlayers = 4;
		
		state->handCount[player_nbr] = 0; //count
		
		state->deck[player_nbr][0] = 9;
		state->deckCount[player_nbr] = 1; //count
		
		state->discard[player_nbr][0] = 8;
		state->discard[player_nbr][1] = 9;
		state->discard[player_nbr][2] = 9;
		state->discard[player_nbr][3] = 11;
		state->discardCount[player_nbr] = 4; //count
	}

}

int main () {

	//initialize game state
	struct gameState G;

	//print what we are testing
	printf ("Testing fullDeckCount....\n");

	//init the test run
	int test_run = 1;
	
	//set game state 1 and run tests
	set_state(&G, 1);
	
	checkFullDeckCount(0, 2, &G, test_run, 3); //should be 3 of card 2
	test_run++;
	checkFullDeckCount(0, 2, &G, test_run, 3); //should be 3 of card 2
	test_run++;
	
	//next game state
	set_state(&G, 2);
	
	checkFullDeckCount(1, 8, &G, test_run, 2); //should be 2 of card 8
	test_run++;
	checkFullDeckCount(1, 8, &G, test_run, 2); //should be 2 of card 8
	test_run++;
	checkFullDeckCount(0, 2, &G, test_run, 3); //should be 3 of card 2
	test_run++;
	checkFullDeckCount(0, 2, &G, test_run, 3); //should be 3 of card 2
	test_run++;
	
	//next game state
	set_state(&G, 3);
	checkFullDeckCount(2, 7, &G, test_run, 0); //should be 0 of card 7
	test_run++;
	checkFullDeckCount(2, 7, &G, test_run, 0); //should be 0 of card 7
	test_run++;
	
	//next game state
	set_state(&G, 4);
	checkFullDeckCount(3, 9, &G, test_run, 3); //should be 3 of card 9
	test_run++;
	checkFullDeckCount(3, 9, &G, test_run, 3); //should be 3 of card 9
	test_run++;
	checkFullDeckCount(2, 7, &G, test_run, 0); //should be 0 of card 7
	test_run++;
	checkFullDeckCount(2, 7, &G, test_run, 0); //should be 0 of card 7
	test_run++;
	checkFullDeckCount(1, 8, &G, test_run, 2); //should be 2 of card 8
	test_run++;
	checkFullDeckCount(1, 8, &G, test_run, 2); //should be 2 of card 8
	test_run++;
	checkFullDeckCount(0, 2, &G, test_run, 3); //should be 3 of card 2
	test_run++;
	checkFullDeckCount(0, 2, &G, test_run, 3); //should be 3 of card 2
	test_run++;
	
	//print that tests are done
	printf ("ALL fullDeckCount TESTS OK\n");

	return 0;
}
