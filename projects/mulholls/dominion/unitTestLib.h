#ifndef _UNITTESTLIB_H
#define _UNITTESTLIB_H

int checkDeck(struct gameState*,struct gameState*);
int checkDeckCount(struct gameState*,struct gameState*);

int checkDiscard(struct gameState*,struct gameState*);
int checkDiscardCount(struct gameState*,struct gameState*);
int checkState(struct gameState*, struct gameState*);

//Sets up a game for int players
void setupRandomTestState(int, struct gameState*);

//Sets up entirely random gamestate
void setupRandomTestState2(struct gameState*);

int* getDeckCount(int, struct gameState*);
int checkGameOver(struct gameState*);

void printGameState(int, struct gameState*, struct gameState*);
void printGameStateDifferences(int, struct gameState*, struct gameState*);
#endif
