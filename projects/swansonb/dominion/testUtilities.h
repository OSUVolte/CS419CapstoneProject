#include "dominion.h"
#include "dominion_helpers.h"

void copyGameState(struct gameState* dest, struct gameState* src);
int equalGameStates(struct gameState* a, struct gameState* b);
void cpyDeck(int* dest, int* src, int n);
int cardArraysAreEqual(int *a, int aSize, int *b, int bSize);
int playerHasSameCards(struct gameState* a, struct gameState* b, int player);
int cardsCHaveBeenAddedtoAinB(int *a, int aSize, int *b, int bSize, int* c, int cSize);
