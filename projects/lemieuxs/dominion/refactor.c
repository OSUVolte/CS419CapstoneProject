I added functions for the Smithy, Adventurer, Minion, Embargo, and Outpost cards.

Here are the function prototypes:
int play_smithy(int currentPlayer, struct gameState * state, int handPos);

int play_adventurer(int currentPlayer, struct gameState * state, int drawntreasure, int cardDrawn, int temphand [], int z);

int play_minion(int currentPlayer, struct gameState * state, int handPos, int choice1, int choice2);

int play_embargo(int currentPlayer, struct gameState * state, int handPos, int choice1);

int play_outpost(int currentPlayer, struct gameState * state, int handPos);

The function definitions are at the end of the dominion.c file.

Bugs
1. On line 1246, in the play_smithy function, drawcard() is called an extra time.
2. On line 1261, in the play_adventurer function, the smithy card is treated as a treasure card even though it is not one.
3. On line 1321, in the play_minion function, the i++ statement causes some players to not have to discard their hand and draw 4 cards.
4. On line 1340, in the play_embargo function, state->numPlayers is increased by 1.