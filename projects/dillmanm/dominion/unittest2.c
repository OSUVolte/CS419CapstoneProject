/*
	This is a unit test for the isGameOver query. It will run the following
	test routine:
		- Check that there are no faults BEYOND end game conditions
			aka All supply piles or All territory card piles empty
		- Check that 1 is returned if there are no provice cards
		- Check that 1 is returned if there are three empty supply decks
		  (no need to check unity of above 2 conditions since they )
*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
//forward declaration
typedef struct gameState gameState;
//tests for conditions like ALL victory cards gone (overshoot)
int testNoVictory(struct gameState *);
//test if end occurs if no kingdom cards are left (overshoot)
int testNoKingdom(struct gameState *,int*);
//test exact end condition (NO PROVINCE LEFT)
int testNoProvince(struct gameState *);
//test exact end condition 3 empty kingdom piles
int testThreeSuppliesGone(struct gameState *,int*);
int testContinuation(struct gameState *,int*);
//generates 3 random number kingdom cards to deplete to 0
int* uniqueInts();

int main(){
	//initialize loop variables and value return variables
	int i, j, k, p, r;
	//seed our RNG for different combos of 3 empty piles
	srand(time(NULL));
	//declare seed for RNG as initialize argument
	int seed = 19191;
	//set supply pile contents to anything, all that matters for this test
	//is their respective counts.
	int kingdom[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState state;
    memset(&state, 0, sizeof(struct gameState));
    //loop over all possible numbers of players
    printf("Test for: isGameOver()\n===================\n");
    for(p=2;p<=4;p++){
    	printf("Test routine for : %d Players\n", p);
    	r = initializeGame(2,kingdom,seed,&state);
    	assert (testNoVictory(&state) == 1);
    	memset(&state, 0, sizeof(struct gameState));
    	r = initializeGame(2,kingdom,seed,&state);
    	assert (testNoKingdom(&state,kingdom) == 1);
    	memset(&state, 0, sizeof(struct gameState));
    	r = initializeGame(2,kingdom,seed,&state);
    	assert (testNoProvince(&state) == 1);
    	memset(&state, 0, sizeof(struct gameState));
    	r = initializeGame(2,kingdom,seed,&state);
    	assert (testThreeSuppliesGone(&state,kingdom) == 1);
    	memset(&state, 0, sizeof(struct gameState));
    	r = initializeGame(2,kingdom,seed,&state);
    	assert (testContinuation(&state,kingdom) == 1);
    }
    printf("All tests succesful!\n");
    return 0;
}

int testNoVictory(struct gameState *state){
	int isEnd;
	//get rid of ALL territory cards
	printf("\tTest no victory cards:\n");
	state->supplyCount[estate] = 0;
	state->supplyCount[duchy] = 0;
	state->supplyCount[province] = 0;
	isEnd = isGameOver(state);
	if (isEnd) printf("\tTest succesful.\n");
	else printf("\t##TEST FAILED##\n");
	return isEnd;
}

int testNoKingdom(struct gameState *state, int* kingdom){
	int i,isEnd;
	//get kid of ALL kingdom cards
	printf("\tTest no kingdom cards:\n");
	//iterate over kingdom cards in play and set all to 0
	for (i=0;i<10;i++){
		state->supplyCount[kingdom[i]]=0;
	}
	//precondition is that only seleted kingdom cards will have 0,
	//others not in play are -1
	isEnd = isGameOver(state);
	if (isEnd) printf("\tTest succesful.\n");
	else printf("\t##TEST FAILED##\n");
	return isEnd;
}

int testNoProvince(struct gameState *state){
	printf("\tTesting game end after depletion of province pile:\n");
	int isEnd;
	state->supplyCount[province] = 0;
	isEnd = isGameOver(state);
	if (isEnd) printf("\tTest succesful.\n");
	else printf("\t##TEST FAILED##\n");
	return isEnd;
}

int testThreeSuppliesGone(struct gameState *state, int* kingdom){
	int i, isEnd;
	int * indexes = uniqueInts();
	int index1 = indexes[0];
	int index2 = indexes[1];
	int index3 = indexes[2];
	int card1 = kingdom[index1];
	int card2 = kingdom[index2];
	int card3 = kingdom[index3];
	//set 3 random piles to 0;
	state->supplyCount[card1]=0;
	state->supplyCount[card2]=0;
	state->supplyCount[card3]=0;
	printf("\tTesting 3 empty kingdom decks: %d, %d, %d",card1,card2,card3);
	isEnd = isGameOver(state);
	if (isEnd) printf("\tTest succesful.\n");
	else printf("\t##TEST FAILED##\n");
	return isEnd;
}

int testContinuation(struct gameState *state, int* kingdom){
	int i, isEnd;
	int * indexes = uniqueInts();
	int index1 = indexes[0];
	int index2 = indexes[1];
	int index3 = indexes[2];
	int amount = kingdom[index1]+1;//add 1 to ensure nonzero
	int card1 = kingdom[index2];
	int card2 = kingdom[index3];
	printf("\tTest: Fresh game continuation:\n");
	isEnd = isGameOver(state);
	if (!isEnd) printf("\tTest succesful.\n");
	else {
		printf("\t##TEST FAILED##\n");
		return 0;
	}
	printf("\tTest: Random nonzero number of provinces (%d):\n",amount);
	state->supplyCount[province] = amount;//plus one assures nonzero
	isEnd = isGameOver(state);
	if (!isEnd) printf("\tTest succesful.\n");
	else {
		printf("\t##TEST FAILED##\n");
		return 0;
	}
	printf("\tTest: One kingdom pile (%d) empty:\n",card1);
	state->supplyCount[card1]=0;
	isEnd = isGameOver(state);
	if (!isEnd) printf("\tTest succesful.\n");
	else {
		printf("\t##TEST FAILED##\n");
		return 0;
	}
	printf("\tTest: Two kingdom pile (%d,%d) empty:\n",card1,card2);
	state->supplyCount[card2]=0;
	isEnd = isGameOver(state);
	if (!isEnd) printf("\tTest succesful.\n");
	else {
		printf("\t##TEST FAILED##\n");
		return 0;
	}
	return 1;
}

int* uniqueInts(){
	int array[3];
	array[0] = rand() % 10;
	do {
		array[1] = rand() % 10;
	} while (array[0] == array[1]);
	do {
		array[2] = rand() % 10;
	} while (array[2] == array[0] || array[2] == array[1]);
	return array;
}