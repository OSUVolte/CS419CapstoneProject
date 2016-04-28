/*
	This test examines the behavior of the discardCard method. There are two different
	final locations for a discarded card. One is the playedCard pile, which becomes
	the discard after the turn is over.
	Test:
		Discard only card in hand
		Discard all cards in mutli-card hand and check proper played-card order.
		Trash card.
		Check order preservation when discard comes from middle of hand.
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>

int discardSingleCard(struct gameState*);
int discardWholeHand(struct gameState*);
int trashCard(struct gameState*);
int checkTop(struct gameState*);
int checkHandOrder(struct gameState*);


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
    memset(&state, 0, sizeof(struct gameState));
    printf("Test for: discardCard()\n===================\n");
    r = initializeGame(2,kingdom,seed,&state);
    //all tests conducted on first player
    state.whoseTurn = player;
    assert(discardSingleCard(&state) == 1);
    memset(&state, 0, sizeof(struct gameState));
    r = initializeGame(2,kingdom,seed,&state);
    assert(discardWholeHand(&state)==1);
    memset(&state, 0, sizeof(struct gameState));
    r = initializeGame(2,kingdom,seed,&state);
    assert(trashCard(&state)==1);
    memset(&state, 0, sizeof(struct gameState));
    r = initializeGame(2,kingdom,seed,&state);
    assert(checkHandOrder(&state)==1);
    printf("All tests passed!\n\n");
    return 0;
}

int discardSingleCard(struct gameState *state){
	//get rid of whole hand but first card
	int i;
	int result = 0;
	int player = state->whoseTurn;
	int targetCard = state->hand[player][0];
	for(i=1;i<state->handCount[player];i++){
		state->hand[player][i] = -1;
		state->handCount[player]--;
	}
	printf("\tTesting discard of last card in hand:\n");
	discardCard(0,player,state,0);
	if (state->playedCards[(state->playedCardCount-1)]==targetCard) result = 1;
	if (result) printf("\tTest passed. Target:%d, Last played card %d\n",targetCard,state->playedCards[(state->playedCardCount-1)]);
	else printf("\t##TEST FAILED. Target:%d, Last played card %d##\n");
	return result;
}

int discardWholeHand(struct gameState *state){
	//copy hand array
	int i,j;
	int result = 1;
	int player = state->whoseTurn;
	int originalHandSize = state->handCount[player];
	int targetArray[(state->handCount[player])];
	printf("\tTesting discard of every card in hand:\n");
	for (i=0;i<state->handCount[player];i++){
		targetArray[i] = state->hand[player][i];
	}
	for (j=(originalHandSize-1);j>=0;j--){
		printf("\t\tDiscarding card at hand index %d\n",j);
		discardCard(j,player,state,0);
	}
	for (i=0;i<originalHandSize;i++){
		if (targetArray[i] != state->playedCards[(state->playedCardCount-i-1)]) result = 0;
		printf("\t\tCard in played: %d, Target: %d\n",state->playedCards[(state->playedCardCount-i-1)],targetArray[i]);
	}
	if (result) printf("\tTest passed.\n");
	else printf("\t##TEST FAILED.##\n");
	return result;
}

int trashCard(struct gameState *state){
	//we will test by checking that handCount is reduced but playedCards did not grow
	int result = 0;
	int player = state->whoseTurn;
	int targetHandSize = state->handCount[player]-1;
	int targetPlayedCount = state->playedCardCount;//should not grow
	printf("\tTesting trash discard:\n");
	discardCard(0,player,state,1);//trash flag on
	if (targetHandSize == state->handCount[player] && targetPlayedCount == state->playedCardCount) result = 1;
	if (result) printf("\tTest passed. ");
	else printf("\t##TEST FAILED. ");
	printf("Target hand count: %d, Actual: %d; Target played count: %d, Actual: %d\n",targetHandSize,state->handCount[player],targetPlayedCount,state->playedCardCount);
	return result;
}

int checkHandOrder(struct gameState *state){
	//discard from middle of hand and then check that last card of hand is preserved
	int result = 0;
	int player = state->whoseTurn;
	int middle = (state->handCount[player]/2);//floor rounded
	int targetCard = state->handCount[player]-1;
	printf("\tTesting that hand is not re-ordered post discard:\n");
	discardCard(middle,player,state,0);
	if (targetCard == state->hand[player][(state->handCount[player]-1)]) result = 1;
	if (result) printf("\tTest passed. ");
	else printf("\t##TEST FAILED. ");
	printf("Target card: %d, Actual: %d; Order preserved.\n",targetCard,state->hand[player][(state->handCount[player]-1)]);
	return result;
}

