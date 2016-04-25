/*
	Tests the GreatHall card. Checks that:
	card is discarded
	draw offsets discard
	card is discarded correctly
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>

int discard(struct gameState*);
int handActionIncrease(struct gameState *);
int emptyDeck(struct gameState *);

int main(){
	//initialize loop variables and value return variables
	int i, j, k, p, r;
	//seed our RNG for different combos of 3 empty piles
	srand(time(NULL));
	//declare seed for RNG as initialize argument
	int seed = 19191;
	int numPlayers = 2;
	//declare player 1 (all tests are symmetric across players here)
	int player = 0;
	//set supply pile contents to anything, all that matters for this test
	//is their respective counts.
	int kingdom[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState state;
    printf("Test for great hall card effect\n===================\n");
    //initialize gamestate
    memset(&state, 0, sizeof(struct gameState));
    r = initializeGame(numPlayers,kingdom,seed,&state);
    state.whoseTurn = player;
    assert(handActionIncrease(&state)==1);
    memset(&state, 0, sizeof(struct gameState));
    r = initializeGame(numPlayers,kingdom,seed,&state);
    state.whoseTurn = player;
    assert(emptyDeck(&state)==1);
    memset(&state, 0, sizeof(struct gameState));
    r = initializeGame(numPlayers,kingdom,seed,&state);
    state.whoseTurn = player;
    assert(discard(&state)==1);
    printf("All tests successful!\n\n");
    return 0;
}

int discard(struct gameState* state){
	int i;
	int result = 0;
	int player = state->whoseTurn;
	//this will work from a new game state
	printf("\tTest that Great Hall card discard is correct.\n");
	//fill discard with some stuff
	for (i=0;i<6;i++){
		state->discard[player][(state->discardCount[player]++)] = estate;
	}
	//change first card in hand to great hall
	state->hand[player][0]=great_hall;
	//play card
	playCard(0,0,0,0,state);
	//search discard for adventurer
	for (i=0;i<state->playedCardCount;i++){
		if (state->playedCards[i]==great_hall) result = 1;
	}
	//print results
	if (result) printf("\tTest succeeds. Great hall present in discard.\n");
	else printf("\t##TEST FAIL## Great hall not present in final discard.\n");
	return result;
}

int handActionIncrease(struct gameState *state){
	int result = 0;
	int player = state->whoseTurn;
	//this will work from a new game state
	printf("\tTest that hand increase is correct.\n");
	//save handcount
	int targetCount = state->handCount[player];//discard offsets draw
	int targetAction = state->numActions;//action point gained will offset lost in playcard
	//change first card in hand to great hall
	state->hand[player][0]=great_hall;
	//play card
	playCard(0,0,0,0,state);
	if (state->handCount[player] == targetCount && state->numActions == targetAction) result = 1;
	if (result) printf("\tTest passed. ");
	else printf("\t##TEST FAILED##. ");
	printf("Target handcount: %d, Actual: %d; target action count = %d, Actual: %d\n",targetCount,state->handCount[player],targetAction,state->numActions);
	return result;
}

int emptyDeck(struct gameState *state){
	int i;
	int result = 0;
	int player = state->whoseTurn;
	printf("\tTest that empty deck will reshuffle for great hall.\n");
	int targetCount = state->handCount[player];
	int initCount = state->deckCount[player];
	//move all cards in deck to discard
	for (i=(state->deckCount[player]-1);i>=0;i--){
		state->discard[player][(state->discardCount[player]++)]=state->deck[player][i];
		state->deckCount[player]--;
	}
	printf("\tDiscard count: %d, Deck count: %d",state->discardCount[player],state->deckCount[player]);
	//change first card in hand to smithy
	state->hand[player][0]=great_hall;
	//play card
	playCard(0,0,0,0,state);
	if (state->handCount[player] == targetCount) result = 1;
	if (result) printf("\tTest passed. ");
	else printf("\t##TEST FAILED##. ");
	printf("Target handcount: %d, Actual: %d\n",targetCount,state->handCount[player]);
	return result;
}