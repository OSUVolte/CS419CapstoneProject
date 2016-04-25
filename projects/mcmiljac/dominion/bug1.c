// Jake McMillen; mcmiljac@oregonstate.edu
// CS 362 - Assignment 3
// 24 April 2016

Bugs found during unit testing:

handCard()
	No bugs found.

discardCard()
	Hand count after calling discardCard should decrease by 1. However this is not the happening. This problem persists regardless of whether or not card is trashed.

gainCard()
	No bugs found.

updateCoins()
	No bugs found.

playAdventurer()
	The number of actions a player has after playing the adventurer Card was not being modified at all. So, the player would have the same number of remaining actions after playing the card. The number of actions should decrease by 1. This error was caught by an assertion that checks the number of actions remaining.

	The adventurer card is not being discarded from the hand, which gives an incorrect handcount and also fails the check that the card at the back of the discard array is an adventurer. Furthmore, the check that the number of cards played increments by 1 also fails since the play count is updated in the discard method. 

playCouncilRoom()
	The number of actions a player has after playing the adventurer Card was not being modified at all. So, the player would have the same number of remaining actions after playing the card. The number of actions should decrease by 1. This error was caught by an assertion that checks the number of actions remaining.

playSmithy()
	The number of actions a player has after playing the smithy card was being increased by 1. The number of actions should decrease by 1. This error was caught by an assertion that checks the number of actions remaining.

playCouncilRoom()
	The number of actions a player has after playing the council room card was not being modified at all. So, the player would have the same number of remaining actions after playing the card. The number of actions should decrease by 1. This error was caught by an assertion that checks the number of actions remaining.