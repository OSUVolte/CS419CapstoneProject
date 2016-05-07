/*
	This is a unit test for the buyCard() method. Test criteria will be:
		Errors:
		Not enough money
		Not enough buys
		Not enough supply (pile empty)
		Checks:
		Check phase
		Check supply count of purchased card
		Check that purchased card is at top of discard pile
		Check that multiple buys work

		gainCard functionality tested in separate unit test 3.

*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
//tests 
int lowMoney(struct gameState *);
int noBuys(struct gameState *);
int noSupply(struct gameState *);
int checkCost(struct gameState *);
int checkPhase(struct gameState *);
int checkMultipleBuys(struct gameState *);


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
    printf("Test for: buyCard()\n===================\n");
    //initialize gamestate
    r = initializeGame(numPlayers,kingdom,seed,&state);
    state.whoseTurn = player;
    assert(lowMoney(&state)==-1);
    assert(notEnoughBuys(&state)==-1);
    assert(noSupply(&state)==-1);
    assert(checkCost(&state)==1);
    assert(checkPhase(&state)==1);
    assert(checkMultipleBuys(&state)==1);
    printf("All tests succesful!\n\n");
    return 0;
}

int lowMoney(struct gameState * state){
	//return variable
	int result;
	state->phase=0;
	state->numBuys=2;
	//give current player no money
	state->coins=0;
	printf("\tRunning test: insufficient coins.\n");
	result = buyCard(adventurer,state);
	if (result==-1) printf("\tTest succesful.\n");
	else printf("\t##TEST FAILED##\n");
	return result;
}

int notEnoughBuys(struct gameState * state){
	int result;
	state->phase=0;
	//give an ample amout of coins
	state->coins = 10;
	//take away all buys from current turn
	state->numBuys = 0;
	printf("\tRunning test: insufficient buys.\n");
	result = buyCard(adventurer,state);
	if (result==-1) printf("\tTest succesful.\n");
	else printf("\t##TEST FAILED##\n");
	//restore buys
	state->numBuys = 2;
	return result;
}

int noSupply(struct gameState * state){
	int result;
	state->phase=0;
	state->numBuys=2;
	//take one supply pile (say Adventurer) down to zero
	state->supplyCount[adventurer]=0;
	printf("\tRunning test: insufficient supply.\n");
	result = buyCard(adventurer,state);
	if (result==-1) printf("\tTest succesful.\n");
	else printf("\t##TEST FAILED##\n");
	//restore supply
	state->supplyCount[adventurer]=10;
	return result;
}

int checkPhase(struct gameState * state){
	int result;
	state->phase=0;
	state->coins = 10;
	state->numBuys=2;
	//buy an affordable item, say Gardens
	buyCard(gardens,state);
	//result should be 1 (fail is 0)
	result = state->phase;
	if (result) printf("\tTest succesful. State properly changed to 1.\n");
	else printf("\t##TEST FAILED. State phase: %d, proper phase: 1##\n",state->phase);
	//restore supply
	state->supplyCount[gardens]=10;
	return result;
}

int checkCost(struct gameState * state){
	int initCoins, finalCoins;
	int result = 0;
	state->phase=0;
	state->coins = 10;
	state->numBuys = 2;
	printf("numBuys: %d",state->numBuys);
	initCoins = state->coins;
	finalCoins = initCoins - getCost(gardens);
	state->numBuys=1;
	//buy an affordable item, say Gardens
	buyCard(gardens,state);
	//check that the cost of gardens has been subtracted from coins
	if (state->coins == finalCoins) result = 1;
	if (result) printf("\tTest succesful. State coins: %d, Proper coins: %d\n",state->coins,finalCoins);
	else printf("\t##TEST FAILED. State coins: %d, Proper coins: %d##\n",state->coins,finalCoins);
	//restore supply
	state->supplyCount[gardens]=10;
	return result;
}

int checkMultipleBuys(struct gameState * state){
	int result = 0;
	state->phase=0;
	state->coins = 10;
	state->numBuys = 2;
	int initBuys = state->numBuys;
	//buy an affordable item, say Gardens
	if(buyCard(gardens,state)==0) result = 1;
	else result = 0;
	//check success of second buy
	if(buyCard(gardens,state)==0) result = 1;
	else result = 0;
	if (result) printf("\tTest succesful. Initial buys: %d, Buys after two rounds: %d\n",initBuys,state->numBuys);
	else printf("\t##TEST FAILED. Initial buys: %d, Buys after two rounds: %d##\n",initBuys,state->numBuys);
	//restore supply
	state->supplyCount[gardens]=10;
	return result;
}