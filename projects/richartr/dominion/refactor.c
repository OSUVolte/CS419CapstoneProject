/*********************************************
** Name: Trent Richardson
** File: Assignment 2 - refactor.c
** Class: CS362-400
*********************************************/

Changes:

dominion.c - updated file to reflect changes as required by Assignment 2.  The following 5 cards are now implemented as functions
             (sectioned off at the bottom of dominion.c): Adventurer, Smithy, Village, Cutpurse, and Sea Hag.  4 of 5 of these
             cards now contain a bug (outlined below).

Bugs:
     playAdventurer() - changed drawntreasue<2 to drawntreasure<3 so 3 cards are drawn.
     playSmithy() - changed i = 0 in the for loop to (i = 1; i < 3; i++).
     playVillage() - changed state->numActions = state->numActions + 2 to state->numActions = state->numActions + 4.
     playCutpurse() - changed if (state->hand[i][j] == copper) to if (state->hand[i][j] == gold).
     play_sea_hag() - no changes
     playSalvager() - no changes, just moved to its own function for testing
