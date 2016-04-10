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

  --- Bugs Introduced ---
  (1) Adventurer - `int drawntreasure` on line 650 is not initialized to zero. So it is presumably referencing a memory value when it is incremented.
      This changes the behavior of the game in a big way but it's not easy to spot.
  (2) Smithy - Changed the for loop on line 682 so i is set to 0 but the condition is if i > 3. This makes drawCard() never executed because the false
      condition skips the loop body. Also, the discardCard() trashFlag has been set to 1 on line 687 so the card will be trashed each time instead of put
      in the played pile.
  (3) Feast - `gainCard(choice1, state, 0, currentPlayer);//Gain the card` has been pulled out of the `else` statement and now simply executes after
      the conditionals check. It is difficult to say what this does exactly, but my theory is that it lets you get your first choice card even if it is
      supposed to be unavailable / unaffordable.
  (4) Village - on line 751 - changed number of actions to be a for loop instead of + 2. This would work perfectly, but instead I set the conditional
      to be less than 3 instead of less than 2. This might slip past someone who forgets to count from 0.
  (5) Minion - switched the order of the for loop to draw 4 cards with the while loop to discard hand. I think this will cause you to discard your entire
      hand every time you play this card instead of getting to discard and then draw more.

*******************************************************************************/
