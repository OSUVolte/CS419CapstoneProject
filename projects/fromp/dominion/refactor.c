Five new functions were added for various action cards. Those functions were:
	adventurerCard
	council_roomCard
	feastCard
	remodelCard
	smithyCard
Function declarations were added to dominion.h and function definitions were added to dominion.c.

Bugs were introduced to all of the fuctions listed above. The details of the bugs are noted below:

int adventurerCard(int currentPlayer, struct gameState *state)
	Modified while loop so the discard deck is shuffled each time, even if the deck is not empty.
	Modified while loop to continue while less than 3 (instead of 2).

int council_roomCard(int currentPlayer, int handPos, struct gameState *state)
	Modified so that number of buys decreases (instead of increasing by 1)
	Modified second for loop so that current player gets to draw (instead of other player)

int feastCard(int currentPlayer, int choice1, struct gameState *state)
	Modified x to be equal 2 (so two cards are selected instead of 1)

int remodelCard(int currentPlayer, int handPos, int choice1, int choice2, struct gameState *state)
	Modified handPos to be 1 less than selected (as long as it is greater than 0).
		
int smithyCard(int currentPlayer, int handPos, struct gameState *state)
	Modified for loop so 4 cards are drawn (instead of 3)
	Modified function call to discardCard with trashFlag set to 1 (instead of 0)

