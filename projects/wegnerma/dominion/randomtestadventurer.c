/**********************************************************
* Name: Marta Wegner
* CS 372
* Assignment #4
* Description: Random test for the adventurer card
**********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>
#include<stdlib.h>
#include <stdio.h>

int main() {
	struct gameState state;
	int handPos;
	int totalCards;
	int numCards;
	int numDeck;
	int numDiscard;
	int numPlay;
	int deckTreasure;
	int discardTreasure;
	int numRuns = 100; //# of times to run test
	int i;
	int k;

	//seed
	srand(time(NULL));

	printf("------playAdventurer random test-------\n\n");
	for(k = 0; k < numRuns; k++) { //run count
	//randomly generate whoseTurn
	//0 to 3
	state.whoseTurn = rand() % 4;

	//total cards should not exceed MAX_DECK
	//randomly generate cards in hand
	//genrate hand 1 to 250
	numCards = rand() % 250 + 1;
	totalCards = numCards;
	state.handCount[state.whoseTurn] = numCards;

	//randomly place adventurer card in hand
	handPos = rand() % numCards;
	state.hand[state.whoseTurn][handPos] = adventurer;

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

	//randomly generate deck
	//From 1 to 250 - totalCards + 1 
	//So range is 1 to a max of 251
	numDeck = rand() % (250 - totalCards + 1) + 1;
	totalCards += numDeck;
	state.deckCount[state.whoseTurn] = numDeck;

	deckTreasure = 0;
	//randomly select cards for deck
	for (i = 0; i < numDeck; i++) {
		//set as random card
		state.deck[state.whoseTurn][i] = rand() % 27;

		if(state.deck[state.whoseTurn][i] == copper ||
			state.deck[state.whoseTurn][i] == silver ||
			state.deck[state.whoseTurn][i] == gold){
				deckTreasure++;
		}
	}

	//randomly select cards for discard
	//From 1 to 248
	numDiscard = rand() % 248 + 1;
	totalCards += numDiscard;
	state.discardCount[state.whoseTurn] = numDiscard;
	
	discardTreasure = 0;
	//randomly select cards for deck
	for (i = 0; i < numDiscard; i++) {
		//set as random card
		state.discard[state.whoseTurn][i] = rand() % 27;

		if(state.discard[state.whoseTurn][i] == copper ||
			state.discard[state.whoseTurn][i] == silver ||
			state.discard[state.whoseTurn][i] == gold){
				discardTreasure++;
		}
	}

	//randomly generate cards for playedCards
	//From 1 to MAX-DECK - totalCards
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
	printf("Cards in hand: %d\n", numCards);
	printf("Cards in deck: %d\n", numDeck);
	printf("Cards in discard: %d\n", numDiscard);
	printf("Cards in played: %d\n", numPlay);
	printf("Deck Treasure Count: %d\n", deckTreasure);
	printf("Discard Treasure Count: %d\n\n", discardTreasure);

	//run test
	playAdventurer(&state, handPos);

	/***************Discard card *************/
	//PASS or FAIL
	//Pass if card is discarded and in playedCards
	if (state.playedCards[numPlay] == adventurer && state.playedCardCount == numPlay + 1) {
		printf("playAdventurer: PASS discard card\n");
	}
	else {
		printf("playAdventurer: FAIL discard card\n");
	}

	/***************Draw Two Cards************/
	//PASS of FAIL
	//Pass if two cards are drawn
	if (state.handCount[state.whoseTurn] == numCards + 1) {
		printf("playAdventurer: PASS draw 2 cards\n");
	}
	else {
		printf("playAdventurer: FAIL draw 2 cards\n");
	}

	/***************Draw Treasures************/
	//PASS or FAIL
	//Pass if two cards drawn are treasures
	if ((state.hand[state.whoseTurn][numCards] == copper || 
		state.hand[state.whoseTurn][numCards] == silver ||
		state.hand[state.whoseTurn][numCards] == gold) &&
		(state.hand[state.whoseTurn][handPos] == copper ||
		state.hand[state.whoseTurn][handPos] == silver ||
		state.hand[state.whoseTurn][handPos] == gold)) {
		
			printf("playAdventurer: PASS draw 2 treasures\n");
	}
	else {
		printf("playAdventurer: FAIL draw 2 treasures\nn");
	}

	/*******************All cards remain*****************/
	//PASS or FAIL
	//Pass if all the cards remain somewhere in play after
	//card is played - to test that no cards are lost  when
	//the function is called
	if ((state.handCount[state.whoseTurn] + state.discardCount[state.whoseTurn] +
		state.deckCount[state.whoseTurn] + state.playedCardCount) == totalCards) {
			printf("playAdventurer: PASS all cards remain\n\n");
	}
	else {
		printf("playAdventurer: FAIL all cards remain\n\n");
	}

	}

	return 0;
}
