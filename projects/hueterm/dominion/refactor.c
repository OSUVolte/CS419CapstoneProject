/*******************************************************************************
Michael Hueter | CS362 Assignment 2 | 10 April 2016

Five Cards converted to functions from switch cases:
  (1) Adventurer has become `int playAdventurerCard(struct gameState *state)` on line 648
  (2) Smithy has become `int playSmithyCard(struct gameState *state, int handPos)`on line 678
  (3) Feast has become `int playFeastCard(struct gameState *state, int choice1)` on line 691
  (4) Village has become `int playVillageCard(struct gameState *state, int handPos)` on line 744
  (5) Minion has become `int playMinionCard(struct gameState *state, int choice1, int choice2, int handPos)` on line 758

  The `cardEffect()` function has had several variables, exclusive to the five above functions, removed. The switch statement
  cases for all of the above cards have been replaced with corresponding function returns, e.g. `return playAdventurerCard(state)`
  
*******************************************************************************/
