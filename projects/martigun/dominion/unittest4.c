#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define TRACERS 0

#define SEED_VAL 7

int checkHandCard(int p, int handPos, struct gameState *post, int test_run, int hand_card) {

	//print run complete
	if (TRACERS) printf("Test run #%d starting...\n", test_run);
	if (TRACERS) printf("Player #%d \n", p);
	if (TRACERS) printf("hand_card #%d \n", hand_card);

	
	if (TRACERS) printf("handpos: %d\n",post->hand[p][handPos]);
	
	//run shuffle and set r to zero
	int r = handCard(handPos, post);
	
	//assert that r = the expected card count
	assert (r == hand_card);
	
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
	
	
	if (state_option==1) state->whoseTurn = 0;
	if (state_option==2) state->whoseTurn = 1;
	if (state_option==3) state->whoseTurn = 2;
	if (state_option==4) state->whoseTurn = 3;
	
	
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
	state->hand[player_nbr][0] = 1;
	state->hand[player_nbr][1] = 2;
	state->hand[player_nbr][2] = 1;
	state->hand[player_nbr][3] = 9;
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
		state->hand[player_nbr][0] = 12;
		state->hand[player_nbr][1] = 2;
		state->hand[player_nbr][2] = 1;
		state->handCount[player_nbr] = 3; //count
		
		state->deckCount[player_nbr] = 0; //count
		
		state->discard[player_nbr][0] = 8;
		state->discard[player_nbr][1] = 9;
		state->discardCount[player_nbr] = 2; //count
	}
	
	if(state_option >= 3){
		
		player_nbr = 3;
		
		state->numPlayers = 4;
		
		state->hand[player_nbr][0] = 12;
		state->hand[player_nbr][1] = 1;
		state->handCount[player_nbr] = 2; //count
		
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
	printf ("Testing handCard....\n");

	//init the test run
	int test_run = 1;
	
	//set game state 1 and run tests
	set_state(&G, 1);
	
	checkHandCard(0, 1, &G, test_run, 2); //should be 2
	test_run++;
	checkHandCard(0, 1, &G, test_run, 2); //should be 2
	test_run++;
	
	//update game state
	set_state(&G, 2);
	
	checkHandCard(1, 3, &G, test_run, 9); //should be 9
	test_run++;
	
	//update game state
	set_state(&G, 3);
	
	checkHandCard(2, 0, &G, test_run, 12); //should be 12
	test_run++;
	
	//update game state
	set_state(&G, 4);
	
	checkHandCard(3, 1, &G, test_run, 1); //should be 1
	test_run++;
	
	
	//print that tests are done
	printf ("ALL handCard TESTS OK\n");

	return 0;
}
