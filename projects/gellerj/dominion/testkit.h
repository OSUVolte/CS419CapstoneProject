#ifndef DOMINION_TESTKIT_H
#define DOMINION_TESTKIT_H

#include "dominion.h"

int handIsUntouched(struct gameState *before, struct gameState *after, int player);
int deckIsUntouched(struct gameState *before, struct gameState *after, int player);
int victoryPileIsUntouched(struct gameState *before, struct gameState *after);
int kingdomPileIsUntouched(struct gameState *before, struct gameState *after);
int playedCardsWasIncremented(struct gameState *before, struct gameState *after, int numCards);

#endif //DOMINION_TESTKIT_H
