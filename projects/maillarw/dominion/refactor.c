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

---playSmithy()---
Smithy was taken from the switch statement in cardEffect() and made into its own function.
Input: struct gameState *state, int handPos 
Output: Returns 0 on success
Changes: The following variables were declared locally inside playSmithy to promote abstraction:
  int currentPlayer = whoseTurn(state);
  int i;
  
---playVillage()---
Village was taken from the switch statement in cardEffect() and made into its own function.
Input: struct gameState *state, int handPos 
Output: Returns 0 on success
Changes: The following variables were declared locally inside playVillage to promote abstraction:
  int currentPlayer = whoseTurn(state);

---playFeast()---
Feast was taken from the switch statement in cardEffect() and made into its own function.
Input: struct gameState *state, int choice1
Output: Returns 0 on success
Changes: The following variables were declared locally inside playVillage to promote abstraction:
  int currentPlayer = whoseTurn(state);
  int temphand[MAX_HAND];
  int i;
  int x;

---playCouncil_Room()---
Council_room was taken from the switch statement in cardEffect() and made into its own function.
Input: struct gameState *state, int handPos
Output: Returns 0 on success
Changes: The following variables were declared locally inside playVillage to promote abstraction:
  int currentPlayer = whoseTurn(state);
  int i;
  