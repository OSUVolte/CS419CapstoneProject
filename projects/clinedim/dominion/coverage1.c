/*
	*** Overall Coverage
	Overall, my unit tests and card tests had the following level of coverage for dominion.c:
	
		Lines executed:36.67% of 570
		Branches executed:38.64% of 427
		Taken at least once:29.98% of 427
		Calls executed:25.26% of 95

	Given that I was directly testing only eight functions, these results while low are not all that
	surprising.  The most obvious way to improve the test coverage that I currently have would be to
	implement unit tests for all of the functions within dominion.c and implement tests for all of the
	cards in the dominion game.  With that said, we'll take a look at the coverage for each of the
	individual tests wrote.  These appear below.

	*** cardtest1.c
	The tests in cardtest1 resulted in the following level of coverage for dominion.c:

		Lines executed:20.70% of 570
		Branches executed:22.72% of 427
		Taken at least once:14.29% of 427
		Calls executed:11.58% of 95

	In this test, I was testing the Smithy card using the cardEffect function.  Despite testing one
	card only, I managed to cover almost a fifth of the lines in and over a fifth of the branches in
	dominion.c, which is a pretty decent amount of the code.  My tests of this card mainly focused on
	making sure that the state of the game was correct after playing the cards.  I could have achieved
	a higher level of coverage by calling additional functions in my tests and introducing additional
	test cases.

	*** cardtest2.c
	The tests in cardtest2.c resulted in the following levels of coverage for dominion.c:

		Lines executed:19.12% of 570
		Branches executed:22.72% of 427
		Taken at least once:14.29% of 427
		Calls executed:9.47% of 95

	In this test, I was testing the Aventurer card using the cardEffect function.  These tests also
	resulted in a decent percentage of coverage both in terms of lines and branches.  With that said,
	there was some obvious overlap because both tests rely on the cardEffect function.  Once again, my
	tests mainly focused on making sure that the game was in the correct state after the card had its
	effect on the state of the game.  I could improve this by introducing additional test cases and
	calling additional functions.

	*** cardtest3.c
	The tests in cardtest3.c resulted in the following levels of coverage for dominion.c:

		Lines executed:20.53% of 570
		Branches executed:22.25% of 427
		Taken at least once:13.82% of 427
		Calls executed:10.53% of 95

	In this test, I focused on testing the Village card. As can be seen in the results above, I managed
	to cover a fifth of the code in dominion.c by testing the effects of only a single card.  This test
	could definitely be improved by introducing additional test cases and by calling more functions, but
	there is a decent level of coverage here, particularly since I am testing only a single card in the
	deck. 

	*** cardtest4.c
	The tests in cardtest4.c resulted in the following levels of coverage for dominion.c:

		Lines executed:21.40% of 570
		Branches executed:23.65% of 427
		Taken at least once:15.22% of 427
		Calls executed:12.63% of 95

	In this test, I tested the Council Room card.  As can be seen in the results above, I achieved coverage
	of a bit over a fifth of line coverage and a bit over a fifth of branche coverage testing only a single
	card.  This is a fairly decent amount of coverage, and it could be improved by adding additional cases
	and calling additional functions within the dominion.c file.  

	*** unittest1.c
	The tests in unittest1.c resulted in the following levels of coverage for dominion.c:

		Lines executed:5.09% of 570
		Branches executed:6.56% of 427
		Taken at least once:6.32% of 427
		Calls executed:0.00% of 95

	This was by far the least effective test in terms of achieving a high level of code coverage.  Both
	in terms of lines and brances, the level of coverage was low.  This is likely because I tested the 
	getCost function, which is used only a handful of times throughout dominion.c.  This function simply
	isn't used very frequently within the code and has only very specific uses.  As a result, calling
	this function doesn't have a huge impact on code coverage.


	*** unittest2.c
	The tests in unittest2.c resulted in the following levels of coverage for dominion.c:

		Lines executed:16.84% of 570
		Branches executed:15.93% of 427
		Taken at least once:13.82% of 427
		Calls executed:7.37% of 95

	In this function, I tested the initializeGame function.  This is one of the most important functions
	in the dominion.c file, because it is required to be called in order to play the game.  It also touches
	a significant percentage of the code, as can be seen by the code coverage.  Although the coverage for
	both lines and brances is still between only 15 and 20 percent, that is still a pretty decent amount
	of coverage for calling only one function in dominion.c.  This level of coverage could be increased
	even further by calling other functions within dominion.c when verifying that the intializeGame
	function is working properly (for instance, by calling he numHandCards function to determine the number
	of cards in each player's hands).  Additional test cases could also be added to get a higher level of
	coverage.

	*** unittest3.c
	The tests in unittest3.c resulted in the following levels of coverage for dominion.c:

		Lines executed:22.81% of 570
		Branches executed:25.29% of 427
		Taken at least once:17.10% of 427
		Calls executed:13.68% of 95

	In this unit test, I focused on testing the getSupplyCount function.  This is a fairly specific function,
	but I managed to get a decent amount of coverage in lines and branches while testing it.  This is partly
	due to the fact that I also used the initializeGame function in my tests, so that I could test the 
	supply counts for cards after the intial setup of games for 2, 3, and 4 players.  Using multiple functions
	in this file definitely helped me achieve a higher level of test coverage in this unit test.

	*** unittest4.c
	The tests in unittest.4 resulted in the following levels of coverage for dominion.c:

		Lines executed:25.09% of 570
		Branches executed:29.51% of 427
		Taken at least once:19.91% of 427
		Calls executed:12.63% of 95
	
	In this unit test, I focused on testing the fullDeckCount function.  This function has a fairly singular
	purpose--that of counting the number of a specific card in a player's available cards.  Even so, I was
	able to achieve my highest levels of line and branch coverage in this unit test.  I wrote this test toward
	the end of this assignment and began to realize that using other functions within a unittest resulted in
	higher levels of coverage.  The main other function that I used in this test was the initializeGame
	function, so that I could set up games for 2, 3, and 4 players.  I then used the fullDeckCount to test the
	number of cards in each deck were correct.  I also did some random testing.  In all, these efforts led to
	almost a third of branches being covered and a quarter of lines being covered.  This was a pretty decent
	test set.

	*** Areas For Improvement
	One of the things that I notice in hindsight is that a lot of my tests test specific functionality within
	different functions and cards but do not do so in a way that actually simulates games.  For instance, in
	my cardtest*.c tests, I could have improved my test coverage by calling the playCard function, rather than
	just testing the card effect.  The playCard function has about 40 lines, and calls 3 other functions, which
	also call other functions.  This would definitely have improved my overall level of coverage and would be
	something I'd want to revisit in the event of improving these test cases.

	In addition, in reviewing the overall coverage of dominion.c, the functions below are those that I should
	focus on when improving my test suite:

		kingdomCards
		playCard
		handCard
		endTurn
		isGameOver
		scoreFor
		getWinners
		drawCard

	In addition the the functions above, I could improve my test squite by implementing tests of the following
	cards:

		feast
		gardens
		mine
		remodel
		baron
		great_hall
		minion
		steward
		tribute
		ambassador
		cutpurse
		embargo
		outpost
		salvager
		sea_hag
		treasure_map

	As can be seen above, theare are a lot of functions and cards left ot test, which would definitely go a long
	way toward improving my overall test coverage.  Hopefully I will have the opportunity to work on improving
	test coverage in a future assignment.
*/