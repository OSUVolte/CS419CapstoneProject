#ifndef _UNITTESTLIB_H
#define _UNITTESTLIB_H

int checkDeck(struct gameState*,struct gameState*);
int checkDeckCount(struct gameState*,struct gameState*);

int checkDiscard(struct gameState*,struct gameState*);
int checkDiscardCount(struct gameState*,struct gameState*);
int checkState(struct gameState*, struct gameState*);

void setupRandomTestState(int, struct gameState*);

int* getDeckCount(int, struct gameState*);
int checkGameOver(struct gameState*);

#endif
