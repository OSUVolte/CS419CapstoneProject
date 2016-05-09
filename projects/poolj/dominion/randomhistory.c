/***************************************************************************
** Author: James Pool
** ONID: 932664412
** OSU Email: poolj@oregonstate.edu
** Date: 8 May 2016
**
** Program Filename: randomhistory.c
** Description: This is the report file for bugs discovered from performing
**				the random tests.
***************************************************************************/

The random testers developed for this assignment utilized the same randomization routine and only varied slightly based on the specific needs of the adventurer card. The general randomization method writes completly random data to the entire gameState data structure using the following loop (contained in the _randomizeGameState() method):
	for (i = 0; i < sizeof(struct gameState); i++) {
		((char*)G)[i] = rand() % 256;
	}

After the data structure is initalized, some properties are required to be set to specific ranges to produce a valid test. These properties are:
	- Current player
	- Number of players
	- Current player's deck count
	- Current player's discard count
	- Current player's hand count
	- Current player's played card count
Without setting these properties, the game can attempt to use an invalid index to an array. In addition, the discard and hand counts are adjusted such that they do not overflow based on the size of the deck.

Also, the adventurer card has an additional routine that adds 2 random treasure cards to the current player's deck. This prevents the adventurer card from creating an infinite loop as it searches for treasure cards that do not exist. The probability of having a card initilized to a valid treasure card by the randomization routine is practically zero.

Each of the cards is run through a series of tests that compares the actual game state to a predicted game state based on the standard dominion card actions. The tests performed include:
	- Current player value
	- Number of players
	- Current player's action count
	- Current player's buy count
	- Current player's coin count
	- All players' deck counts
	- All players' discard counts
	- All players' hand count
	- All players' played count
	- Supply Card counts
All of the above are validated against the perdicted results.

Card: Adventurer
File: randomtestadventurer.out
Coverage (randomtestadventurer.c):
	Lines executed: 90.00% of 190
	Branches executed: 100.00% of 92
	Taken at least once: 73.91% of 92
	Calls executed: 85.92% of 71
The lines that were not executed corrospond to failure cases where the cardEffect() and _testCurrentPlayer() methods fail to complete. The remainder of lines not executed are from the print statements for failed test criterias.

The results from running an initial set of 100 tests are:
	PASS: 1711 of 1911
	FAIL: 200 of 1911
The failed tests appear to all be the same and stem from a mismatch of played cards and the current player's hand count. The sum of these two properties is the same and therefore it appears to be only a single issue coming from removing the adventurer card from the player's hand.

Card: Village
File: randomtestcard
Coverage (randomtestcardc):
	Lines executed: 75.68% of 185
	Branches executed: 78.26% of 92
	Taken at least once: 54.35% of 92
	Calls executed: 74.24% of 66
The coverage for this test is lower than that for the adventurer card due to the inclusion, but not execution of routines that are associated with the adventurer card (such as _addDeckTreasure and _printValidDeck). Otherwise, the coverage is very similar to that from the previously tested card.

The results from running an initial set of 100 tests are:
	PASS: 1920 of 1920
	FAIL: 0 of 1920
This corrosponds to the fact that there are no bugs that were introduced to the Village card and therefore none were detected.