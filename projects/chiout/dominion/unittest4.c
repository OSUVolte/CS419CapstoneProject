/***
Name: Tiffany Chiou
Assignment: 3
Testcase: unittest4.c
Testing Function: updateCoins function in dominion.c
***/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

/**
- Set up a game state with different amount of treasure cards in their hand
- set state->coin value, make sure it doesn't have an impact on the results
- validate that the coin amount is correct
- validate that the player's hand is unaffected - same cards as before
- validate that other player's hands are unaffected too
- test different bonus values
**/

void testUpdateCoins(struct gameState* gS, struct gameState* dup, int curr, int nC, int nS, int nG, int bonus) {

	// calculate the expected results first
	int value = 0;
	int a, b, result, nCopper, nSilver, nGold, nSmithy, diff;

	for (a=0;a<nC;a++)
		value = value + 1;
	for (a=0;a<nS;a++)
		value = value + 2;
	for (a=0;a<nG;a++)
		value = value + 3;
	value = value+bonus;

	// perform updateCoins on gS
	result = updateCoins(curr,gS,bonus);

	if (result == 0)
		printf("The function returned with a return code of 0.\n");
	else
		printf("The function did not return with a return code of 0.\n");

	if (gS->coins == value)
		printf("SUCCESS: The correct coin value was returned.\n");
	else
		printf("FAILURE: The incorrect coin value was returned.\n");

	// compare gS with dup, make sure nothing has changed
	// all player's hands should be exactly the same - same positions since no shuffling has occured
	// the handcounts should also be the same
	// dup should be an exact copy of gS

	for (a=0;a<dup->numPlayers;a++) {
		if (a == curr)
			printf("Current Player:\n");
		else
			printf("Player %d:\n",a);
		if (dup->handCount[a] == gS->handCount[a]) {
			printf("SUCCESS: The hand count is unchanged.\n");
			diff = 0;
			for (b=0;b<dup->handCount[a];b++) {
				if (dup->hand[a][b] != gS->hand[a][b]) {
					diff = 1;
					break;
				}
			}
			if (diff == 0)
				printf("SUCCESS: The hand cards stayed the same.\n");
			else
				printf("FAILURE: The hand cards are different.\n");
		} else 
			printf("FAILURE: The hand count changed. The hand cards may be different.\n");
	}
}


/**
- Sets up gameState by filling up all the player's hands with the same cards.
**/
struct gameState* prepareState(int numPlayers, int curr, int numCards, int nC, int nS, int nG) {

	struct gameState* state = (struct gameState*)malloc(sizeof(struct gameState));
	state->numPlayers = numPlayers;
	state->whoseTurn = curr;
	int i,a,b,c,d;

	if (nC+nS+nG > numCards) {
		printf("Testing parameters are incorrect.\n");
		return;
	}

	// set up cards in hand for all players
	// all players will have the same cards for simplicity and testing sake
	for (i=0;i<numPlayers;i++) {
		a=0; // set a to 0
		for (b=0;b<nC;b++) {
			state->hand[i][a] = copper; //2
			a++;
		}
		for (b=0;b<nS;b++) {
			state->hand[i][a] = silver; //2
			a++;
		}
		for (b=0;b<nG;b++) {
			state->hand[i][a] = gold; //1
			a++;
		}
		// if numCards has not been reached, add smithy to the hand until it is
		for (b=a;b<numCards;b++) {
			state->hand[i][b] = smithy;
		}
		state->handCount[i] = numCards;
	}
	return state;
}


int main() {

	struct gameState* gS;
	struct gameState* dup; // used to compare gS to
	int numPlayers, curr, numCards, nC, nS, nG, bonus, coins;

	printf("\n-----Testing updateCoins function with unittest4.c-----\n");

	// Test 1
	// use dup to compare gS with
	numPlayers = 2;
	curr = 1;
	numCards = 5;
	nC = 1;
	nS = 1;
	nG = 1;
	bonus = 1;
	coins = 5;
	printf("\nTest 1: %d Copper, %d Silver, %d Gold, %d Bonus\n",nC,nS,nG,bonus);
	gS = prepareState(numPlayers,curr,numCards,nC,nS,nG);
	dup = prepareState(numPlayers,curr,numCards,nC,nS,nG);
	gS->coins = coins;
	testUpdateCoins(gS,dup,curr,nC,nS,nG,bonus);
	free(gS);
	free(dup);
	gS = NULL;
	dup = NULL;


	// Test 2
	// use dup to compare gS with
	numPlayers = 4;
	curr = 3;
	numCards = 7;
	nC = 1;
	nS = 3;
	nG = 2;
	bonus = 4;
	coins = 10;
	printf("\nTest 2: %d Copper, %d Silver, %d Gold, %d Bonus\n",nC,nS,nG,bonus);
	gS = prepareState(numPlayers,curr,numCards,nC,nS,nG);
	dup = prepareState(numPlayers,curr,numCards,nC,nS,nG);
	gS->coins = coins;
	testUpdateCoins(gS,dup,curr,nC,nS,nG,bonus);
	free(gS);
	free(dup);
	gS = NULL;
	dup = NULL;


	// Test 3
	// use dup to compare gS with
	numPlayers = 2;
	curr = 0;
	numCards = 5;
	nC = 4;
	nS = 0;
	nG = 1;
	bonus = 3;
	coins = 15;
	printf("\nTest 3: %d Copper, %d Silver, %d Gold, %d Bonus\n",nC,nS,nG,bonus);
	gS = prepareState(numPlayers,curr,numCards,nC,nS,nG);
	dup = prepareState(numPlayers,curr,numCards,nC,nS,nG);
	gS->coins = coins;
	testUpdateCoins(gS,dup,curr,nC,nS,nG,bonus);
	free(gS);
	free(dup);
	gS = NULL;
	dup = NULL;

	// Test 4
	// use dup to compare gS with
	numPlayers = 3;
	curr = 1;
	numCards = 2;
	nC = 1;
	nS = 1;
	nG = 0;
	bonus = 0;
	coins = 0;
	printf("\nTest 4: %d Copper, %d Silver, %d Gold, %d Bonus\n",nC,nS,nG,bonus);
	gS = prepareState(numPlayers,curr,numCards,nC,nS,nG);
	dup = prepareState(numPlayers,curr,numCards,nC,nS,nG);
	gS->coins = coins;
	testUpdateCoins(gS,dup,curr,nC,nS,nG,bonus);
	free(gS);
	free(dup);
	gS = NULL;
	dup = NULL;

	return 0;
}

