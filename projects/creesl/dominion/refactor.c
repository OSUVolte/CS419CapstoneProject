/*
Refactor documentation
Assignment 2

adventurer:
Added adventurerEffect() prototype to dominion_helpers.h
Parameters: int drawntreasure, struct gameState *state, int currentPlayer, int z, int temphand
Bug: Line 1251; temphand[z]; should be z-1

smithy:
Added smithyEffect() prototype to dominion_helpers.h
Parameters: int currentPlayer, struct *state, int handPos
Bug: Line 1266; discardCard(handPos, currentPlayer, state, 1); 1 should be 0

treasure map:
Added treasuremapEffect() prototype to dominion_helpers.h
Parameters: int index, struct gameState *state, int currentPlayer, int i, int handPos
Return value: int
Bug: Line 1295; return -1; should be 1

sea hag:
Added seahagEffect() prototype to dominion_helpers.h
Parameters: struct gameState *state, int currentPlayer, int i
Bug: Line 1306; i == currentPlayer; should be !=

minion:
Added minionEffect() prototype to dominion_helpers.h
Parameters: struct gameState *state, int handPos, int currentPlayer, int choice1, int choice2, int i, int j
Bug: Line 1326; state->coins + 1; should be 2

*/