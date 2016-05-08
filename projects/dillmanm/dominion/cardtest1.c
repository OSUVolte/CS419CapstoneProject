/*
	This is the smithy test routine. The smithy card serves to draw 3 cards.
	We will check:
		To see if hand increase is correct.
		To see if draw continues across a reshuffle of the deck.
		Check that played smithy is discarded.
*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>

int handIncrease(struct gameState*);
int emptyDeck(struct gameState*);

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
    printf("Test for smithy card effect\n===================\n");
    //initialize gamestate
    memset(&state, 0, sizeof(struct gameState));
    r = initializeGame(numPlayers,kingdom,seed,&state);
    state.whoseTurn = player;
    assert(handIncrease(&state)==1);
    memset(&state, 0, sizeof(struct gameState));
    r = initializeGame(numPlayers,kingdom,seed,&state);
    state.whoseTurn = player;
    assert(emptyDeck(&state)==1);
    printf("All tests successful!\n\n");
    return 0;
}

int handIncrease(struct gameState *state){
	int result = 0;
	int player = state->whoseTurn;
	//this will work from a new game state
	printf("\tTest that hand increase is correct.\n");
	//save handcount
	int targetCount = state->handCount[player]+2;//draw 3 discard 1 net 2
	//change first card in hand to smithy
	state->hand[player][0]=smithy;
	//play card
	playCard(0,0,0,0,state);
	if (state->handCount[player] == targetCount) result = 1;
	if (result) printf("\tTest passed. ");
	else printf("\t##TEST FAILED##. ");
	printf("Target handcount: %d, Actual: %d\n",targetCount,state->handCount[player]);
	return result;
}

int emptyDeck(struct gameState *state){
	int i;
	int result = 0;
	int player = state->whoseTurn;
	printf("\tTest that empty deck will reshuffle for smithy.\n");
	int targetCount = state->handCount[player]+2;
	int initCount = state->deckCount[player];
	//move all cards in deck to discard
	for (i=(state->deckCount[player]-1);i>=0;i--){
		state->discard[player][(state->discardCount[player]++)]=state->deck[player][i];
		state->deckCount[player]--;
	}
	printf("\tDiscard count: %d, Deck count: %d",state->discardCount[player],state->deckCount[player]);
	//change first card in hand to smithy
	state->hand[player][0]=smithy;
	//play card
	playCard(0,0,0,0,state);
	if (state->handCount[player] == targetCount) result = 1;
	if (result) printf("\tTest passed. ");
	else printf("\t##TEST FAILED##. ");
	printf("Target handcount: %d, Actual: %d\n",targetCount,state->handCount[player]);
	return result;
}


