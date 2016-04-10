/*

---playAdventurer()---
Adventurer was taken from the switch statement in cardEffect() and made into its own function.
Input: struct gameState *state
Output: Returns 0 on success
Changes: The following variables were declared locally inside adventurer to promote abstraction:
  int currentPlayer = whoseTurn(state);
  int temphand[MAX_HAND];
  int z = 0;
  int drawntreasure = 0;
  int cardDrawn;

---playSmithy()---
Smithy was taken from the switch statement in cardEffect() and made into its own function.
Input: struct gameState *state, int handPos 
Output: Returns 0 on success
Changes: The following variables were declared locally inside smithy to promote abstraction:
  int currentPlayer = whoseTurn(state);

