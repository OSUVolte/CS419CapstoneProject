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


//Refactored player card functions
void adventurerCard(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int z, int temphand[]);
void council_roomCard(struct gameState *state, int handPos, int currentPlayer, int i);
void smithyCard(int currentPlayer, struct gameState *state, int handPos, int i);
int embargoCard(struct gameState *state, int choice1, int currentPlayer, int handPos);
int treasure_mapCard(int index, struct gameState *state, int currentPlayer, int i, int handPos);

#endif
