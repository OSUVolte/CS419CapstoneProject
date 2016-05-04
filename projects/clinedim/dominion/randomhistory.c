/*
	********** Introduction ********** 
	In this file, I will be providing details regarding the random testers I wrote for the Adventurer
	and Village cards.  These random testers are located in the following files:

				randomtestadventurer.c
				randomtestcard.c

	These tests can be run with the following commands:

				make randomtestadventurer.out
				make randomtestcard.out

	Running these commands will produce two files called randomtestadventurer.out and randomtestcard.out.  Each of these
	files will contain the output of the tests, along with the gcov informationat the bottom of the file.  These scripts
	can also be compliled and run from the command line using the following commands:

				make randomtestadventurer
				make randomtestcard

	This will produce two executable files, randomtestadventurer and randdomtestcard, which can be executed from the command
	line.  The files needed for gcov will also be produced.

	********** randomtestadventurer.c **********
	The randomtestadventurer.c file contains the random tests I wrote for the Adventurer card in the Dominion base deck.  When
	the player plays this card, the player is able to draw cards from their deck until they have two additional treasure cards
	in their hand. Playing this card does not have any impact on the hands or decks of other players, or the supply counts of 
	the game.

	In testing the effects of this card, I chose to test four different game states:

				1.  The player playing the card has a random hand (containing at least one adventurer card).
				2.  The player playing the card has a random deck.
				3.  The player playing the card has a random hand (containing at least one adventurer card) and random deck.
				4.  There is a random number of players, and the player playing the card has a random hand (containing at least 
				one adventurer card) and a random deck).

	My test code gets each random test in the initial state described above, and then causes the card to have its effect.  The 
	state of the game before the card effect is compared to the state of the game after the card effect.  Each relevant aspect
	of the game state is checked to make sure that only the intended effects occur and that there are no unintended effects. More
	specifically, there is a test oracle which performs the following checks:

				1.  Confirms the player hand counts after the card has been played.  The current player should have one additional
				card in hand.  There should be no impact on the hands of other players.
				2.  Confirms that the deck counts of other players were not impacted by the card having been played.
				3.  Confirms that the discard counts of other players were not impacted by the card having been played.
				4.  Confirms that the current player has received two additional treasure cards and that the treasure counts of
				other players was not impaced.
				5.  Confirms that the played card count has increased by 1.
				6.  Confirms that the supply counts of kingdom cards has not changed.
				7.  Confirms that the embargo tokens counts have not changed.
				8.  Confirms that the outpost played counts have not changed.
				9.  Confirms that the outpost turn has not changed.
				10.  Confirms that whose turn has not changed.
				11.  Confirms that the number of actions after the card has been played has not changed.
				12.  Confirms that the number of coins has not changed.
				13.  Confirms that the number of buys has not changed.

	Each of the random tests occurs 100 times per run of the program, and all 13 checks above occur each time.  The tests print out
	the results of each test to standard output or to a file, depending on how the test is triggered.

	In addition to the information above, I have also measured the coverage that this test produced.  This information is below:

				Lines executed:23.25% of 572
				Branches executed:25.53% of 427
				Taken at least once:17.10% of 427
				Calls executed:10.31% of 97

	Given that I am testing only a single card, this is a relatively high level of line and branch coverage.  Both approach a quarter
	of the code in dominion.c.  I also examined the coverage of the Adventurer code in the gcov output, an all but one line of the
	Adventurer code is executed, so this is a fairly high level of coverage for the Adventurer card code from the unit tests.  The
	only line that wasn't called was a call to the shuffle function; this occurred because the deck was never empty in my tests. I
	could improve these tests by introducing some additional tests that occur when the deck is empty.

	********** randomtestcard.c **********
	The randomtestcard.c file contains the random tests I wrote for the Village card in the Dominion base deck.  When the player plays
	this card, the player is granted one additional card and two additional actions.  Playing this card does not have any impact on the
	hands or decks of other players, or the supply counts of the game.

	In testing the effects of this card, I chose to test four different game states:

				1.  The player playing the card has a random hand (containing at least one village card).
				2.  The game has a random number of players.
				3.  The player playing the card has a random number of actions, and there are a random number of player.
				4.  The player playing the card has a random hand (containing at least one village card).  There are also a random number 
				of players, and the player playing the card has a random number of actions.

	My test code gets each random test in the initial state described above, and then causes the card to have its effect.  The 
	state of the game before the card effect is compared to the state of the game after the card effect.  Each relevant aspect
	of the game state is checked to make sure that only the intended effects occur and that there are no unintended effects. More
	specifically, there is a test oracle which performs the following checks:

				1.  The oracle confirms the player hand counts after the card has been played.  The current player's number of cards in the
				hand should not change (the player gets 1 card but also discards the Village card for a net of +0 cards).  There should be
				no impact on the hands of other players.
				2.  Confirms that the deck counts of other players were not impacted by the card having been played.
				3.  Confirms that the discard counts of other players were not impacted by the card having been played.
				4.  Confirms that the played card count has increased by 1.
				5.  Confirms that the supply counts have not changed as a result of playing the card.
				6.  Confirms that the embargo tokens have not changed as a result of playing the card.
				7.  Confirms that the outpost played have not changed as a result of playing the card.
				8.  Confirms that the outpost turn has not changed as a result of playing the card.
				9.  Confirms that whose turn has not changed as a result of playing the card.
				10.  Confirms that the number of actions for the current player has increased by 2.
				11.  Confirms that the number of coins after playing the card has not changed.
				12.  Confirms that the number of buys after playing the card has not changed.

	Each of the random tests occurs 100 times per run of the program, and all 12 checks above occur each time.  The tests print out
	the results of each test to standard output or to a file, depending on how the test is triggered.

	In addition to the information above, I have also measured the coverage that this test produced.  This information is below:

				Lines executed:21.85% of 572
				Branches executed:22.72% of 427
				Taken at least once:14.99% of 427
				Calls executed:11.34% of 97

	As with the previous test, I am testing only a single card in my testrandomcard.c file, so the levels of coverage above are not all that
	surprising.  A bit over one in five lines of code and one in five branches is being executed by the tests in this file, which isn't terrible.
	Moreover, 100% of the lines of code of the playVillageCard function are covered under this test, so the code coverage for this function is as
	good as can be.

	********** Final Notes **********
	I tested both the Adventurer and Village cards very thoroughly using the random tests that I wrote in randomtestadventurer.c and randomtestcard.c.
	In order to make sure that my tests were catching errors, I introduced bugs into the code for the cards.  For instance, for the Adventurer card,
	I removed the didscardCard function and this bug was caught by my tests.  As another example, for the Village card, I gave the player one too many
	actions and the code caught this bug as well.  I also checked the tests with correct implementations of the card functions, and all tests passed.
*/