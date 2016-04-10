/*
William Maillard
CS 362
The following refactoring was done for Assignment 2:

---playAdventurer()---
Adventurer was taken from the switch statement in cardEffect() and made into its own function.
Input: struct gameState *state
Output: Returns 0 on success
Changes: The following variables were declared locally inside playAdventurer to promote abstraction:
  int currentPlayer = whoseTurn(state);
  int temphand[MAX_HAND];
  int z = 0;
  int drawntreasure = 0;
  int cardDrawn;
  **Bug added: Line 1147 z=z-3 should be z=z-1, not all of the cards in paly that have been drawn will be discarded 

---playSmithy()---
Smithy was taken from the switch statement in cardEffect() and made into its own function.
Input: struct gameState *state, int handPos 
Output: Returns 0 on success
Changes: The following variables were declared locally inside playSmithy to promote abstraction:
  int currentPlayer = whoseTurn(state);
  int i;
  
  **Bug added: line 1156, i is no longer initialized to 0, will cause some strange behavior
  
---playVillage()---
Village was taken from the switch statement in cardEffect() and made into its own function.
Input: struct gameState *state, int handPos 
Output: Returns 0 on success
Changes: The following variables were declared locally inside playVillage to promote abstraction:
  int currentPlayer = whoseTurn(state);
	**Bug added: line 1167, currentPlayer is initialized to the wrong player (should delete '+1')

---playFeast()---
Feast was taken from the switch statement in cardEffect() and made into its own function.
Input: struct gameState *state, int choice1
Output: Returns 0 on success
Changes: The following variables were declared locally inside playVillage to promote abstraction:
  int currentPlayer = whoseTurn(state);
  int temphand[MAX_HAND];
  int i;
  int x;
  **Bug added: Lines 1218-1220: Wrapped gainCard in a loop so it executes 5 times instead of just once.

---playCouncil_Room()---
Council_room was taken from the switch statement in cardEffect() and made into its own function.
Input: struct gameState *state, int handPos
Output: Returns 0 on success
Changes: The following variables were declared locally inside playVillage to promote abstraction:
  int currentPlayer = whoseTurn(state);
  int i;
  




  