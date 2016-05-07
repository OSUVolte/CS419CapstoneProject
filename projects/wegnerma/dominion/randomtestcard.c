/**********************************************************
* Name: Marta Wegner
* CS 372
* Assignment #4
* Description: Random test for the village card
**********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include<time.h>
#include<stdlib.h>
#include <stdio.h>

int main() {
	struct gameState state;
	int handPos;
	int numCards;
	int numActions;
	int numDeck;
	int numDiscard;
	int numPlay;
	int totalCards;
	int numRuns = 100; //# of times to run test
	int i;
	int k;

	//seed
	srand(time(NULL));

	printf("------playVillage random test-------\n\n");
	for (k = 0; k < numRuns; k++) {//run test 5 times

	//randomly generate whoseTurn
	//0 to 3
	state.whoseTurn = rand() % 4;

	//total should not exceed MAX_DECK
	//randomly generate cards in hand
	//genrate hand 1 to 250
	numCards = rand() % 250 + 1;
	totalCards = numCards;
	state.handCount[state.whoseTurn] = numCards;

	//randomly place village card in hand
	handPos = rand() % numCards;
	state.hand[state.whoseTurn][handPos] = village;

	//randomly select cards for hand
	for (i = 0; i < numCards; i++) {
		if (i == handPos) {
			//do nothing if village card
		}
		else {
			//set as random card
			state.hand[state.whoseTurn][i] = rand() % 27;
		}
	}

	//randomly set number of actions
	numActions = rand() % 5;
	state.numActions = numActions;

	//randomly generate deck
	//From 1 to 250 - totalCards + 1
	//So range is 1 to a max of 251
	numDeck = rand() % (250 - totalCards  + 1) + 1;
	totalCards += numDeck;
	state.deckCount[state.whoseTurn] = numDeck;

	//randomly select cards for deck
	for (i = 0; i < numDeck; i++) {
		//set as random card
		state.deck[state.whoseTurn][i] = rand() % 27;
	}

	//randomly generate discard cards
	//From 1 to 248
	numDiscard = rand() % 248 + 1;
	totalCards += numDiscard;
	state.discardCount[state.whoseTurn] = numDiscard;

	//randomly select cards for discard
	for (i = 0; i < numDiscard; i++) {
		//set as random card
		state.discard[state.whoseTurn][i] = rand() % 27;
	}

	//randomly generate cards for playedCards
	//From 1 to MAX_DECK - totalCards
	//So range is 1 to 497
	numPlay = rand() % (MAX_DECK - totalCards) + 1;
	totalCards += numPlay;
	state.playedCardCount = numPlay;

	//randomly select cards for playedCards
	for (i = 0; i < numPlay; i++) {
		//set as random card
		state.playedCards[i] = rand() % 27;
	}

	//Test information
	printf("------Test #%d-------\n", k+1);
	printf("Whose turn: %d\n", state.whoseTurn);
	printf("Hand position: %d\n", handPos);
	printf("Number of actions %d\n", state.numActions);
	printf("Cards in hand: %d\n", numCards);
	printf("Cards in deck: %d\n", numDeck);
	printf("Cards in discard: %d\n", numDiscard);
	printf("Cards in played: %d\n\n", numPlay);

	//run test
	playVillage(&state, handPos); //play

	/****************Add actions*************/
	//PASS or FAIL
	//Pass if 2 actions are added to numActions
	if (state.numActions == numActions + 2) {
		printf("playVillage: PASS add actions\n");
	}
	else {
		printf("playVillage: FAIL add actions\n");
	}

	/***************Discard card *************/
	//PASS or FAIL
	//Pass if card is discarded and in playedCards
	if (state.playedCards[numPlay] == village && state.playedCardCount == numPlay + 1) {
		printf("playVillage: PASS discard card\n");
	}
	else {
		printf("playVillage: FAIL discard card\n");
	}

	/*************Draws card ****************/
	//PASS or FAIL
	//Passes if hand count == hand count before action
	if (state.handCount[state.whoseTurn] == numCards) {
		printf("playVillage: PASS draw card\n\n");
	}
	else {
		printf("playVillage: FAIL draw card\n\n");
	}
	}

	return 0;
}
