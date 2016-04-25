#ifndef TEST_HELPERS_UNIT_H
#define TEST_HELPERS_UNIT_H

#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"

struct compareReturn{
	int handCount;
	int hand;
	int deckCount;
	int deck;	
	int discardCount;
	int discard;
	int playedCardCount;	
	int playedCards;
	int coins;
	int actions;	
	int playerCount;	
	int buys;
	int supply;
	int supplyCount;
};  

void printCurGameState(struct gameState *G);
void printAllCardsForPlayer(struct gameState *G, int playerNumber);
void printResults(struct gameState *G, struct gameState *I);
struct compareReturn compareGameStates(struct gameState *start, struct gameState *finish, int player);
int printCompareResults(struct compareReturn results);

#endif
