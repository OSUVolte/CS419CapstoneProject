#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);

// Refactored cardEffect cards
void adventurerEffect(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int z, int temphand[]);
void smithyEffect(int currentPlayer, struct gameState *state, int handPos, int i);
int treasuremapEffect(int index, struct gameState *state, int currentPlayer, int i, int handPos);
void seahagEffect(struct gameState *state, int currentPlayer, int i);
void minionEffect(struct gameState *state, int handPos, int currentPlayer, int choice1, int choice2, int i, int j);

#endif
