//// Jake McMillen; mcmiljac@oregonstate.edu
// CS 362 - Assignment 4
// 8 May 2016

NOTE: To compile and run random testers type "make randomtestcard.out" or "make randomtestadventurer.out" at the command prompt.

The randomtestcard and randomtestadventurer programs test the refactored playSmithy() and playAdventurer() functions, respectively, from the dominion.c file. (A more natural name for the randomtestcard file would be randomtestsmithy, but I tried to follow the directions for the assignment precisely). Both work by generaterating numerous randomized game states (within certain parameters) and then calling the testPlaySmithy() and testPlayAdventurer() functions in order to check whether the result of playing the specified card matches expectations.

The randomized game state is constructed as follows:
	1. Number of Player is selected to be 2-4.
	2. A random integer seed for the initializeGame() function is chosen in the range 1-10.
	3. Then each player:
		a. gains between 1 and 10 random cards to her deck
		b. shuffles the deck
		c. draws between 1 and 8 cards
		d. gains between 0 and 8 random cards to her discard pile
	4. Next, a random player is chosen to have the next turn.
	5. A random position is chosen in their hand, and this position is overwritten with the card to be tested (smithy or adventurer).
	6. The player plays the test card from its current position and the existing test function is called to verify the results.
	
The randomtestcard and randomtestadventurer write the results of the tests to the files randomtestcard.out and randomtestadventurer.out. As currently written, each random tester generates 1000 test cases.

The random testers written for assignment 4 improve upon the coverage from the unit tests written in assignment 3. For the playSmithy function, the unit tests already had 100% statement coverage (seen in the gcov file), but the random tester maintains 100% statement coverage while testing many more different configurations. For playAdventurer(), the unit tests did not provide full coverage of the function, only 66.6%. This was due to the different types of treasure cards that could be drawn. The random tester, however generally achieves 100% statement coverage of the playAdventurer() function with little difficulty. This is a substantial improvement.