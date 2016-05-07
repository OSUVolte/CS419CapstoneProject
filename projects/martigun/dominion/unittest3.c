#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define TRACERS 0


int checkUpdateCoins(int p, struct gameState *post, int bonus, int test_run, int coin_val) {

	//print run complete
	if (TRACERS) printf("Test run #%d starting...\n", test_run);
	if (TRACERS) printf("Player #%d \n", p);

	//create struct for game state
	// before running function
	struct gameState pre;
	
	//copy the state to change onto pre
	memcpy (&pre, post, sizeof(struct gameState));
	
	//trace statements
	int i;
	if (TRACERS) printf("pre-coin update:\n");
	if (TRACERS) for(i=0; i<post->handCount[p]; i++) printf("i=%d %d\n",i,post->hand[p][i]);
	
	//run shuffle and set r to zero
	int r = updateCoins(p, post, bonus);
	
	//assert that it did not fail
	assert (r == 0);
	
	if (TRACERS) printf("post->coins:%d\n",post->coins);
	
	assert (post->coins == coin_val);
	
	//copy the post values onto the pre state
	pre.coins = post->coins;
	
	//assert that post=pre
	assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);
	
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
	state->hand[player_nbr][2] = 2;
	state->hand[player_nbr][3] = copper;
	state->hand[player_nbr][4] = silver;
	state->hand[player_nbr][5] = gold;
	state->handCount[player_nbr] = 6; //count
	
	state->deck[player_nbr][0] = 7;
	state->deck[player_nbr][1] = 6;
	state->deck[player_nbr][2] = 5;
	state->deck[player_nbr][3] = 4;
	state->deck[player_nbr][4] = 3;
	state->deckCount[player_nbr] = 5; //count
	
	state->discardCount[player_nbr] = 0; //count
	
	//player 1
	player_nbr = 1;
	state->hand[player_nbr][0] = 1;
	state->hand[player_nbr][1] = 2;
	state->hand[player_nbr][2] = 2;
	state->hand[player_nbr][3] = copper;
	state->hand[player_nbr][4] = copper;
	state->hand[player_nbr][5] = gold;
	state->handCount[player_nbr] = 6; //count
	
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
		
		state->hand[player_nbr][0] = 1;
		state->hand[player_nbr][1] = 2;
		state->hand[player_nbr][2] = 2;
		state->hand[player_nbr][3] = gold;
		state->hand[player_nbr][4] = gold;
		state->hand[player_nbr][5] = gold;
		state->hand[player_nbr][6] = gold;
		state->hand[player_nbr][7] = gold;
		state->handCount[player_nbr] = 8; //count
		
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

	//print what we are testing
	printf ("Testing updateCoins....\n");

	//init the test run
	int test_run = 1;
	
	//set game state 1 and run tests
	set_state(&G, 1);
	
	checkUpdateCoins(0, &G, 0, test_run, 6); //should be 6 coins
	test_run++;
	checkUpdateCoins(0, &G, 0, test_run, 6); //should be 6 coins
	test_run++;
	checkUpdateCoins(1, &G, 0, test_run, 5); //should be 5 coins
	test_run++;
	checkUpdateCoins(1, &G, 0, test_run, 5); //should be 5 coins
	test_run++;
	checkUpdateCoins(1, &G, 2, test_run, 7); //should be 7 coins
	test_run++;
	
	//next state
	set_state(&G, 2);
	
	checkUpdateCoins(2, &G, 0, test_run, 0); //should be 0 coins
	test_run++;
	checkUpdateCoins(2, &G, 0, test_run, 0); //should be 0 coins
	test_run++;
	checkUpdateCoins(2, &G, 1, test_run, 1); //should be 1 coins
	test_run++;
	
	//next state
	set_state(&G, 3);
	
	checkUpdateCoins(3, &G, 0, test_run, 15); //should be 15 coins
	test_run++;
	checkUpdateCoins(3, &G, 1, test_run, 16); //should be 15 coins
	test_run++;
	checkUpdateCoins(3, &G, 2, test_run, 17); //should be 15 coins
	test_run++;

	
	//print that tests are done
	printf ("ALL updateCoins TESTS OK\n");

	return 0;
}
