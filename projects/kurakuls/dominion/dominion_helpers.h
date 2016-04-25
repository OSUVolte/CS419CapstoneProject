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

int playMySmithy(int i, int currentPlayer, struct gameState *state, int handPos);           
int playMyAdventurer(int z, int cardDrawn, int drawntreasure, int temphand[], int currentPlayer, struct gameState *state, int handPos );
int playMyGardens();
int playMySteward(int choice1, int choice2, int choice3, int currentPlayer, struct gameState *state, int handPos);
int playMyVillage(int currentPlayer, struct gameState *state, int handPos);          
           
#endif
