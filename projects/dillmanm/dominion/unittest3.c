/*
	Unit test 3 tests the function gainCard, which is related to the buy card
	function but can even be used when it is not your turn (Ambassador) or in situations
	where you get cards for free. Therefore, there is a call to this function in
	buy function and the subroutines shall only be tested here.
	Check fault:
	Exhausted supply.
	Out-of-play card.
	Check for behavior in state:
	Check for decrement in supply pile.
	Check for card transfer to hand
	Check for card transfer to deck
	Check for card transfer to discard ("normal behavior")
	Gain from every kingdom
	Gain from every treasure
	Gain from every victory
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>

int exhausted(struct gameState *);
int outOfPlay(struct gameState *);
int decrement(struct gameState *);
int transferHand(struct gameState *);
int transferDeck(struct gameState *);
int transferDiscard(struct gameState *);

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
    printf("Test for: gainCard()\n===================\n");
    r = initializeGame(2,kingdom,seed,&state);
    //all tests conducted on first player
    state.whoseTurn = player;
    assert(exhausted(&state)==-1);
    assert(outOfPlay(&state)==-1);
    assert(decrement(&state)==1);
    assert(transferHand(&state)==1);
    assert(transferDeck(&state)==1);
    assert(transferDiscard(&state)==1);
    printf("All tests passed!\n\n");
    return 0;
}

int exhausted(struct gameState* state){
	int result;
	//deplete supply of baron
	state->supplyCount[baron] = 0;
	printf("\tTesting attempt to gain a depleted card stock:\n");
	result = gainCard(baron,state,0,state->whoseTurn);
	if (result==-1)
		printf("\tTest passed.\n");
	else printf("\t##TEST FAILED.##\n");
	return result;
}

int outOfPlay(struct gameState* state){
	int result;
	printf("\tTesting attempt to gain an unused card:\n");
	result = gainCard(steward,state,0,state->whoseTurn);
	if (result==-1) printf("\tTest passed.\n");
	else printf("\t##TEST FAILED.##\n");
	return result;
}

int decrement(struct gameState* state){
	int result = 0;
	int initSupply, targetSupply;
	int player = state->whoseTurn;
	state->supplyCount[baron] = 10;
	initSupply = state->supplyCount[baron];
	targetSupply = initSupply - 1;
	printf("\tTesting: checking proper kingdom card decrement:\n");
	gainCard(baron,state,0,player);
	if (targetSupply == state->supplyCount[baron]) result = 1;
	if (result) printf("\tTest passed! Target supply: %d, Supply after gain: %d\n",targetSupply,state->supplyCount[baron]);
	else printf("\t##TEST FAILED! Target supply: %d, Supply after gain: %d##\n",targetSupply,state->supplyCount[baron]);
	return result;
}

int transferHand(struct gameState* state){
	int result,i;
	int player = state->whoseTurn;
	gainCard(baron,state,2,player);
	//check to see if card is at max in player's hand
	int targetIndex = state->handCount[player]-1;
	if (baron == handCard(targetIndex,state)) result = 1;
	else result = 0;
	if (result)
		printf("\tTest passed. Card at hand position %d has enum %d\n",targetIndex,baron);
	else printf("\t##TEST FAILED. Card at hand position %d has enum %d: target: %d\n",targetIndex,handCard(targetIndex,state),baron);
	return result;
}

int transferDeck(struct gameState* state){
	int result;
	int player = state->whoseTurn;
	gainCard(baron,state,1,player);
	//check to see if card is at max in player's deck
	int targetIndex = state->deckCount[player]-1;
	if (baron == state->deck[player][targetIndex]) result = 1;
	else result = 0;
	if (result)
		printf("\tTest passed. Card at deck position %d has enum %d\n",targetIndex,baron);
	else printf("\t##TEST FAILED. Card at deck position %d has enum %d: target: %d\n",targetIndex,state->deck[player][targetIndex],baron);
	return result;
}

int transferDiscard(struct gameState* state){
	int result,i;
	int player = state->whoseTurn;
	//place 5 non-baron cards in the discard pile
	for (i=0;i<6;i++){
		state->discard[player][i]=copper;
		state->discardCount[player]++;
	}
	gainCard(baron,state,0,player);
	//check to see if card is at max in player's discard
	int targetIndex = (state->discardCount[player]-1);
	if (baron == state->discard[player][targetIndex]) result = 1;
	else result = 0;
	if (result)
		printf("\tTest passed. Card at discard position %d has enum %d\n",targetIndex,baron);
	else printf("\t##TEST FAILED. Card at discard position %d has enum %d: target: %d\n",targetIndex,state->discard[player][targetIndex],baron);
	return result;
}

