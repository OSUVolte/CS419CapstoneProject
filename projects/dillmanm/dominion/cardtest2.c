/*
	Test adventurer. Success condition will test for:
		Adventurer discard
		Adventurer hand increase of two treasures.
		Operation when deck has no treasure cards left.
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
int handTreasures(struct gameState*);

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
    printf("Test for adventurer card effect\n===================\n");
    //initialize gamestate
    memset(&state, 0, sizeof(struct gameState));
    r = initializeGame(numPlayers,kingdom,seed,&state);
    state.whoseTurn = player;
    assert(discard(&state)==1);
    memset(&state, 0, sizeof(struct gameState));
    r = initializeGame(numPlayers,kingdom,seed,&state);
    state.whoseTurn = player;
    assert(handTreasures(&state)==1);
    printf("All tests successful!\n\n");
    return 0;
}

int discard(struct gameState* state){
	int i;
	int result = 0;
	int player = state->whoseTurn;
	//this will work from a new game state
	printf("\tTest that Adventurer card discard is correct.\n");
	//fill discard with some stuff
	for (i=0;i<6;i++){
		state->discard[player][(state->discardCount[player]++)] = estate;
	}
	for (i=0;i<state->deckCount[player];i++){
		state->deck[player][i]=copper;
	}
	//change first card in hand to adventurer
	state->hand[player][0]=adventurer;
	//play card
	playCard(0,0,0,0,state);
	//search discard for adventurer
	for (i=0;i<state->playedCardCount;i++){
		if (state->playedCards[i]==adventurer) result = 1;
	}
	//print results
	if (result) printf("\tTest succeeds. Adventurer present in discard.\n");
	else printf("\t##TEST FAIL## Adventurer not present in final discard.\n");
	return result;
}

int handTreasures(struct gameState* state){
	int i, topHand;
	int result = 0;
	int player = state->whoseTurn;
	//this will work from a new game state
	printf("\tTest that Adventurer gets 2 new treasure cards in hand.\n");
	//fill discard with some stuff
	for (i=0;i<6;i++){
		state->discard[player][(state->discardCount[player]++)] = estate;
	}
	for (i=0;i<state->deckCount[player];i++){
		state->deck[player][i]=copper;
	}
	//change first card in hand to adventurer
	state->hand[player][0]=adventurer;
	//play card
	for (i=0;i<state->handCount[player];i++){
		printf("%d ",state->hand[player][i]);
	}
	playCard(0,0,0,0,state);
	//check that top two cards in hand are treasures
	topHand = state->handCount[player]-1;
	//because of how discard works, the old index of Adventurer (0) will be a treasure
	if (state->hand[player][topHand] == copper || state->hand[player][topHand] == silver || state->hand[player][topHand] == gold){
		if (state->hand[player][0] == copper || state->hand[player][0] == silver || state->hand[player][0] == gold){
			result = 1;
		}
	}
		if (result) printf("\tTest succeeds. Newest cards in hand are treasure.\n");
	else printf("\t##TEST FAIL## Adventurer postcondition not met. Cards other than treasure in hand.\n");
	return result;
}