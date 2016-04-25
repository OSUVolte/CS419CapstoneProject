#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define TRACERS 0

#define SEED_VAL 7

int checkSmithy(int p, struct gameState *post, int test_run, int handPos) {

	//print run complete
	if (TRACERS) printf("Test run #%d starting...\n", test_run);
	if (TRACERS) printf("Player #%d \n", p);

	
	//create struct for game state
	// before running function
	struct gameState pre;
	
	//copy the state to change onto pre
	memcpy (&pre, post, sizeof(struct gameState));
	
	// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
	
	if (TRACERS) printf("~~~post->handCount[player_nbr]: %d\n", post->handCount[p]);
	
	//card Effect
	int r = cardEffect(13, 0, 0, 0, post, handPos, 0);
	
	if (TRACERS) printf("~~~post->handCount[player_nbr]: %d\n", post->handCount[p]);
	
	//assert that it did not fail
	assert (r == 0);
	
	assert ((post->handCount[p] - pre.handCount[p])==2);
	
	//copy the post values onto the pre state
	//memcpy(pre.deck[p], post->deck[p], sizeof(int) * pre.deckCount[p]);
	
	
	//assert that post=pre
	//assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);
	
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
	state->deck[player_nbr][2] = 5;
	state->deck[player_nbr][3] = 4;
	state->deck[player_nbr][4] = 3;
	state->deckCount[player_nbr] = 5; //count
	
	state->discardCount[player_nbr] = 0; //count
	
	//player 1
	player_nbr = 1;
	state->handCount[player_nbr] = 0; //count
	
	state->deck[player_nbr][0] = 8;
	state->deck[player_nbr][1] = 9;
	state->deck[player_nbr][2] = 10;
	state->deck[player_nbr][3] = 11;
	state->deckCount[player_nbr] = 4; //count
	
	state->discard[player_nbr][0] = 8;
	state->discard[player_nbr][0] = 9;
	state->discardCount[player_nbr] = 2; //count
	
	if(state_option >= 2){
		
		player_nbr = 2;
		
		state->numPlayers = 3;
		
		//player 2 (deck count is zero)
		state->handCount[player_nbr] = 0; //count
		
		state->deckCount[player_nbr] = 0; //count
		
		state->discard[player_nbr][0] = 8;
		state->discard[player_nbr][0] = 9;
		state->discardCount[player_nbr] = 2; //count
	}
	
	if(state_option >= 3){
		
		player_nbr = 3;
		
		state->handCount[player_nbr] = 0; //count
		
		state->deck[player_nbr][0] = 8;
		state->deckCount[player_nbr] = 1; //count
		
		state->discard[player_nbr][0] = 8;
		state->discard[player_nbr][0] = 9;
		state->discard[player_nbr][0] = 9;
		state->discard[player_nbr][0] = 11;
		state->discardCount[player_nbr] = 4; //count
	}

}

int main () {

	//initialize game state
	struct gameState G;

	// //set up kingdom cards
	// int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		   // sea_hag, tribute, smithy};

	//print what we are testing
	printf ("Testing smithy....\n");

	//init the test run
	int test_run = 1;
	
	//init random values (for shuffle function, not for test)
	SelectStream(1);
	PutSeed((long)SEED_VAL);

	
	//set game state 1 and run tests
	set_state(&G, 1);
	
	checkSmithy(0, &G, test_run, 0);
	test_run++;
	
	
	//print that tests are done
	printf ("ALL smithy TESTS OK\n");

	return 0;
}
