/*
 * (40 points) Use gcov to measure code coverage for all of these tests.
 * Report your findings by discussing your tests' coverages (statement, branch, boundary, etc.),
 * and describe their implications for the tests in a file called coverage1.c, also checked in to
 * your dominion directory. I want you to look at the dominion code coverage and
 * find out what parts of your code are not covered so that in future you can improve your test suite.
 *
 *  TEST COVERAGE :
 *
 *  43.18% Coverage by GCVO
 *  File 'dominion.c'
	Lines executed:43.18% of 572
	Branches executed:42.59% of 425
	Taken at least once:31.06% of 425
	Calls executed:28.42% of 95
 *
 *
 * *  IMPLICATIONS FOR COVERED CARDS(the ones I was tasked with covering)
 *  While 100% branch coverage is unlikely to truly help, and good test cases are required in order to make the
 *  test work, the above code has strong branch coverage. I have worked to test the boundaries of each function to
 *  test edge cases. Statement coverage is also very high. While it does not mean the functions 100% perform as they should
 *  the high branch and edge cases used in the test suite give the functions some confidence (if they can pass the unit test) that
 *  they will work as intended. Test suit needs to work to have 100% branch coverage as well as double check to make sure any/all edge cases
 *  are used.
 *
 * OF FUNCTIONS TESTED:
 *
 * Card 1 - Baron - function baronPlay called 8 returned 100% blocks executed 94%
 * I could not execute some of the code on baron due to a critical error/infinite loop.
 *
 * Card 2 - Adventurer - called 10 returned 100% blocks executed 94%
 * I could not execute some of the code on Adventurer to to a critical error/infinite loop.
 *
 * Card 3 - Sea Hag called 10 returned 100% blocks executed 100%
 *
 *  Seahag has full code coverage. Improvements can be made in amount of calls made from function. Also,
 *  the test never find out why the card isn't put on the top, it just shows it is incorrectly put somewhere
 *  else in the deck.
 *
 *  Card 4 - Baron -  called 8 returned 100% blocks executed 94%
 *
 *  Easiest improvement would be to take branch #1. Most important thing gleamed from baron test coverage data
 *  is that explicit test meant to call the "isGameOver(state) are *never* executed. Code can be improved by
 *  figuring out why this is the case and changeing test suit.
 *
 *
 *  Unit Test 1: Shuffle - called 104 returned 100% blocks executed 100%
 *
 *   Shuffle is tested well and has 100% code coverage. Logic is tested on the function it calls to sort as well
 *   as making sure only cards are shuffled in one deck. Test can be expanded upon, however all big
 *   areas appear to be accounted for inside unit test.
 *
 *   Unit Test 2: discardCard called 204 returned 100% blocks executed 89%
 *	DiscardCard never is called with only 1 card in the hand. This is the easiest improvement to the test sweet.
 *	Discard Card could use more testing with the trashflag as the branch is covered, but 99% of the time not used.
 *
 *	 Unit Test 3: drawCard called 346 returned 100% blocks executed 100%
 *
 *	 Drawcard has 100% coverage. All major sides are tested. The logic appears to work correctly.
 *	 Much like shuffle, draw card has no obvious bugs and nothing was teased out by any of the unit test.
 *
 *	 Unit Test 4: UpdateCoins: function updateCoins called 44 returned 100% blocks executed 100%
 *
 *	 All blocks of UpdateCoins are tested. Overall there is little in the way of lines of code that can be tested further.
 *   In testing updateCoins a bug in buy-card was found. Because update coins takes in a player argument and the state struct is
 *   what holds only 1 copy of the current amount of coins by the player this card can be tweaked to only take in
 *   the structure gameState. This might save confusion and possible bugs down the road.
 *
 *   An example is on player 0 turn if updateCoins(int 1, gamestate*state) is called, player 0 will have all the coins in player
 *   1 hand and not his/her own hand. This is hard to tease out under code coverage such as gcov as it is a logic error.
 *

 * 	OVERALL TEST COVERAGE:
 *
 * 	 Overall the test coverage is rather low. It is significantly under 50% and some of the unit test ran failed
 *	To improve the test suite the first thing I would do would be to start testing other functions. The functions I
 *	would put in top priority would be buyCard, endTurn, gainCard, and playCard.
 *
 *	Several cards require these functions to not be broken in order to work correctly in order for them to be implemented correctly.
 *	Currently it appears that they are broken in some way.
 *
 *	To improve the current test suite I have I would work on getting 100% branch coverage where able, and reviewing all code to make sure all
 *	edge cases have been improved upon.
 *
 *
 */
