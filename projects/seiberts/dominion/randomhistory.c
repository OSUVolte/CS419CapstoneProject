Shawn Seibert
4/29/2016
CS362
Assignment 4

	Starting with the random tests on the adventure card, I focused on
	testing whether or not the player would discard two cards. I designed
	the random test to randomly select the number of players that will be
	playing the game, and randomly selecting the number of cards in the
	players hands. I decided to run the test 300 times within a for loop
	that after each iteration would perfom the randomization of players 
	and card amount.
	
	After successfully running the test using statement and branch coverage,
	I found that my tests executed 90.24% of the lines, 100% of the branches, 
	62.50% of the branches were taken at least once, and finally I had 85.19% 
	calls were executed. In terms of coverage for the dominion.c file, I was able
	to have 25.62% coverage. With that being said, this is an increase in 
	coverage of about 7% when compared to the unit tests.
	
	As far as the testing results go, all tests failed when the random testing
	was conducted. I ran this test several times, and out of coincidence, a 
	test every now and then would pass.

	<-----------Coverage for adventurer ------------->
	File 'randomtestadventurer.c'
	Lines executed:90.24% of 41
	Branches executed:100.00% of 8
	Taken at least once:62.50% of 8
	Calls executed:85.19% of 27
	Creating 'randomtestadventurer.c.gcov'

	File 'dominion.c'
	Lines executed:25.62% of 566
	Creating 'dominion.c.gcov'
	<----------------End of Coverage------------------>
	
	For the other random card test, I choose to use the smithy card. For this test,
	I wanted to focus my testing on whether or not the player drew 3 cards. Similarly
	to the adventure card test, the testing involved a random number of players playing
	and a random of cards in the players hand. I also ran this test 300 times within 
    for loop, and after each iteration, a new number of players and cards in hand were 
	implemented
	
	After successfully running the test using statement and branch coverage,
	I found that my tests executed 90.00% of the lines, 100% of the branches, 
	62.50% of the branches were taken at least once, and finally I had 84.62% 
	calls were executed. In terms of coverage for the dominion.c file, I was able
	to have 22.26% coverage. With that being said, this is an increase in 
	coverage of about 5% when compared to the unit tests. However, this is a decrease
	in coverage when compared to the adventurer card random tests.
	
	As far as the testing results go, all tests failed when the random testing
	was conducted. I ran this test several times and everytime the same results would
	occur with the player discarding 4 cards instead of 3.
	
	<-----------Coverage for smithy ------------->
	Number of passed tests: 0
	Number of failed tests: 300
	File 'randomtestcard.c'
	Lines executed:90.00% of 40
	Creating 'randomtestcard.c.gcov'

	File 'randomtestcard.c'
	Lines executed:90.00% of 40
	Branches executed:100.00% of 8
	Taken at least once:62.50% of 8
	Calls executed:84.62% of 26
	Creating 'randomtestcard.c.gcov'

	File 'dominion.c'
	Lines executed:22.26% of 566
	Creating 'dominion.c.gcov'
	<----------------End of Coverage------------------>
	