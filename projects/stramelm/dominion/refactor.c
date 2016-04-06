Cash Stramel
CS362
Spring 2016
Assignment #2

The following five (5) functions were added such that smith, adventurer,
council_room, village, and great_hall cards are implemented in their own
functions.

int smithyCardEffect(int currentPlayer, int handPos, struct gameState *state);
int adventurerCardEffect(int currentPlayer, struct gameState *state);
int council_roomCardEffect(int currentPlayer, int handPos, struct gameState *state);
int villageCardEffect(int currentPlayer, int handPos, struct gameState *state);
int great_hallCardEffect(int currentPlayer, int handPos, struct gameState *state);

Four (4) of the cards above were modified to introduce subtle bugs as
described below.

smithy:
The trashFlag in the call to discardCard() was changed from 0 to 1 so that
the card will be trashed instead of put into the discard pile.

adventurer:
Changed the while statement from <2 to <=2 so that the function will continue
until three(3) treasure cards have been drawn.

council_room:
Canged i != currentPlayer to i == currentPlayer.  This will have the current
player draw a card when actually everyone else should draw a card.

village:
The trashFlag in the call to discardCard() was changed from 0 to 1 so that
the card will be trashed instead of put into the discard pile.
