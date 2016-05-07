/* * * * * * * * * * * * * * * * * * * * * *
* randomhistory.c
* Lauren Crees
* Last Modified: 5/4/2016
* Description: Documentation of random testing in randomtestadventurer.c
* and randomtestcard.c.
* * * * * * * * * * * * * * * * * * * * * * *

Adventurer
	Inputs:
	int drawntreasure - starts at 0
	struct gameState *state - many inputs that can vary
	int currentPlayer - 0 to number of players - 1
	int cardDrawn - starts at 0
	int z - starts at 0
	int temphand[] - starts empty
	
	This means that the game state will be what affects the operation of the adventurer card.  More specifically, the player's deck and the existence of copper, silver, and gold cards in the deck will affect the operation of adventurer. Other states of the game, such as player number and other player's hands, decks, and moves should not affect a play of adventurer.

	Plan:
		Randomize number of players and amount of coin cards in deck. Run test until failure or up to 10 million times (value can be changed to run more tests, this is to ensure the program will not infinitely loop).

	Tests:
		Adventurer is passing tests when run for 10 million tests. It's possible that running more tests would produce failure.

Treasure Map
	Inputs:
	int index - starts at 0
	struct gameState *state - many inputs can vary
	int currentPlayer - 0 to number of players - 1
	int i - starts at 0
	int handPos - between 0 and number in hand

	Treasure map will possibly be affected by game state and can be affected by hand position and whether there are other treasure map cards in the player's hand.

	Plan:
		Randomize position of treasure map in hand, number of treasure maps in hand, number of players, number of supply for gold cards. Run test until failure or up to 10 million times (value can be changed to run more tests, this is to ensure the program will not infinitely loop).

	Tests:
		Treasure map is failing two tests.
		First test: 1 Treasure Map, no gold gained: FAIL
		Second test: 2 Treasure Maps, should return 1: FAIL
		Each of these tests is failing in a number of different configurations.

Coverage
	Adventurer
		Adventurer was called 10 million times and had a coverage of 79%. More specifically, there are three branches that are never taken, so some edge cases could be set up to test those branches. The coverage is not bad, but not as good as it could be.

	Treasure Map
		In one instance of failure, treasure_map was called once and had 88% coverage.  This is high, espcially for one call.

		In another instance of different failure, treasure_map was called once and had 94% coverage.  There still seems to be some missed branches, but bugs are being caught.

*/