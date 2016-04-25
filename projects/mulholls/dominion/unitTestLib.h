#ifndef _UNITTESTLIB_H
#define _UNITTESTLIB_H

//Accepts two gamestates and checks decks to see if there are an equal count of card types;
int checkDeck(struct gameState*, struct gameState*);

//Accepts a player number, and a gamestate and returns an array with key=cardnum val=cardcount;
int* getDeckCount(int, struct gameState*);

//Accepts two gamestates and checks hands to see if there are an equal count of card types;
int checkHand(struct gameState*, struct gameState*);

//Accepts two gamestates and checks discard to see if there are an equal count of card types;
int checkDiscard(struct gameState*, struct gameState*);

//Accepts two gamestates and checks deckCount to see if equal
int checkDeckCount(struct gameState*, struct gameState*);

//Accepts two gamestates and checks discardCount to see if equal
int checkDiscardCount(struct gameState*, struct gameState*);

//Accepts two gamestates and checks each of the properties to see if they're equal
int checkState(struct gameState*, struct gameState*);

//Accepts a gamestate and evaluates to see if game over conditions exist
int checkGameOver(struct gameState*);

//Accepts a player count and a gamestate to create a random state for that set of players
//Attributes taken at random from appropriate range of values for parameter
//Has a minimum deck size of 1 for each player
void setupRandomTestState(int, struct gameState*);

#endif
