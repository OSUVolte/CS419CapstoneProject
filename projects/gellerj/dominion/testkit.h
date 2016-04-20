#ifndef DOMINION_TESTKIT_H
#define DOMINION_TESTKIT_H

#include "dominion.h"

int handIsUntouched(struct gameState *before, struct gameState *after, int player);
int deckIsUntouched(struct gameState *before, struct gameState *after, int player);
int victoryPileIsUntouched(struct gameState *before, struct gameState *after);
int kingdomPileIsUntouched(struct gameState *before, struct gameState *after);
int playedCardsWasIncremented(struct gameState *before, struct gameState *after, int numCards);
int cardWasPlayed(struct gameState *game, int card, int position);
int playedPileIsUntouched(struct gameState *before, struct gameState *after);
int deckWasShuffled(struct gameState *before, struct gameState *after, int player);
void diffHand(struct gameState *before, struct gameState *after, int player, int diffCards[MAX_HAND]);
int checkHandCard(struct gameState *game, int player, int position, int card);
void diffDeckSupply(struct gameState *before, struct gameState *after, int player, int supplyDiffs[MAX_DECK]);

#endif //DOMINION_TESTKIT_H
