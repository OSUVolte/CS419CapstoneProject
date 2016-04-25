#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helpers_unit.h"

void printCurGameState(struct gameState *G){

	printf("Player 1 cards in hand: %i\n", G->handCount[0]);
	printf("Player 2 cards in hand: %i\n", G->handCount[1]);
	printf("Player 1 cards in deck: %i\n", G->deckCount[0]);
	printf("Player 2 cards in deck: %i\n", G->deckCount[1]);
	printf("Player 1 cards in discard: %i\n", G->discardCount[0]);
	printf("Player 2 cards in discard: %i\n", G->discardCount[1]);
	printf("Played card count: %i\n", G->playedCardCount);
	printf("Buys available: %i\n", G->numBuys);
	printf("Coins available: %i\n", G->coins);
	printf("\n");
}

void printAllCardsForPlayer(struct gameState *G, int playerNumber){

	printf("Cards in Player %i's hand: ", playerNumber+1);
	for(int i = 0; i < G->handCount[playerNumber]; i++){
		printf("%i ", G->hand[playerNumber][i]);	
	}
	printf("\n");
	printf("Cards in Player %i's discard pile: ", playerNumber+1);
	for(int i = 0; i < G->discardCount[playerNumber]; i++){
		printf("%i ", G->discard[playerNumber][i]);	
	}
	printf("\n");
	printf("Cards in Player %i's deck: ", playerNumber+1);
	for(int i = 0; i < G->deckCount[playerNumber]; i++){
		printf("%i ", G->deck[playerNumber][i]);	
	}
	printf("\n");
	printf("Cards played this turn: ");
	for(int i = 0; i < G->playedCardCount; i++){
		printf("%i ", G->playedCards[i]);
	}
	printf("\n");
}

void printResults(struct gameState *G, struct gameState *I){
	printf("***Cards held by regular G state***\n");
	printAllCardsForPlayer(G, 0);
	printAllCardsForPlayer(G, 1);
	printf("***Cards held by memcopy G state.***\n");
	printAllCardsForPlayer(I, 0);
	printAllCardsForPlayer(I, 1);



	printf("\n");
	printf("***Number of cards in regular G state.***\n");
	printCurGameState(G);
	printf("***Number of cards in memcopy G state.***\n");
	printCurGameState(I);	
}

void prepRetArr(struct compareReturn * arr){
	arr->handCount = 0;
	arr->hand = 0;
	arr->deckCount = 0;
	arr->deck = 0;	
	arr->discardCount = 0;
	arr->discard = 0;
	arr->playedCardCount = 0;	
	arr->playedCards = 0;
	arr->coins = 0;
	arr->actions = 0;	
	arr->playerCount = 0;	
	arr->buys = 0;
}

struct compareReturn compareGameStates(struct gameState *left, struct gameState *right, int player){
	
	struct compareReturn retArr;
	prepRetArr(&retArr);

	if(left->handCount[player] != right->handCount[player]) {
		retArr.handCount++;	
	}
	for(int i = 0; i < left->handCount[player]; i++){
		if(left->hand[player][i] != right->hand[player][i]){
			retArr.hand++;
		}
	}
	if(left->deckCount[player] != right->deckCount[player]) {
		retArr.deckCount++;
	} 	
	for(int i = 0; i < left->deckCount[player]; i++){
		if(left->deck[player][i] != right->deck[player][i]){
			retArr.deck++;
		}
	}
	if(left->discardCount[player] != right->discardCount[player])  {
		retArr.discardCount++;
	} 	
	for(int i = 0; i < left->discardCount[player]; i++){
		if(left->discard[player][i] != right->discard[player][i]){
			retArr.discard++;
		}
	}
	if(left->playedCardCount != right->playedCardCount) {
		retArr.playedCardCount++;
	} 	
	if(left->coins != right->coins) {
		retArr.coins++;
	} 	
	if(left->numActions != right->numActions) {
		retArr.actions++;
	} 
	if(left->numPlayers != right->numPlayers) {
		retArr.playerCount++;
	}
   	if(left->numBuys != right->numBuys){
		retArr.buys++;
	}
	return retArr;
}

int printCompareResults(struct compareReturn results){
	int noProblem = 1;
	if(results.handCount){
		printf("***Hand count does not match.\n");
		noProblem = 0;
	}
	if(results.hand){
		printf("***Hand does not match.\n");
		noProblem = 0;
	}
	if(results.deckCount){
		printf("***Deck count does not match.\n");
		noProblem = 0;
	}
	if(results.deck){
		printf("***Deck does not match.\n");
		noProblem = 0;
	}
	if(results.discardCount){
		printf("***Discard count does not match.\n");
		noProblem = 0;
	}
	if(results.discard){
		printf("***Discarded cards do not match.\n");
		noProblem = 0;
	}
	if(results.playedCardCount){
		printf("***Played card count does not match.\n");
		noProblem = 0;
	}
	if(results.playedCards){
		printf("***Played cards do not match.\n");
		noProblem = 0;
	}
	if(results.coins){
		printf("***Coins do not match.\n");
		noProblem = 0;
	}
	if(results.actions){
		printf("***Actions do not match.\n");
		noProblem = 0;
	}
	if(results.playerCount){
		printf("***Player count does not match.\n");
		noProblem = 0;
	}
	if(results.buys){
		printf("***Buys do not match.\n");
		noProblem = 0;
	}
	if(!noProblem) printf("\n");	
	return noProblem;
}
