John Fodrocy
Assignment 3 Bug Report

Smithy Card - cardtest1

	-Test 1 Failure
		After playing the Smithy card, the user has too many cards.
		The user should have three additional cards, but instead has more.
		
	-Test 2 Failure
		After playing the Smithy card, the user has too many cards.
		The user should have three additional cards, but instead has five more.
		
	-Test 3 Failure
		Once again, the player has too many cards after using the smithy card.
		Instead of three additional cards gained from the Smithy card, he has five.

Adventurer Card - cardtest2

	-Test 1 Failure
		In this test, the user fails the first part of the test.
		The user doesn't have the correct number of cards after playing Adventurer.
		The user passes the second part of the test, which is designed to make sure
		the user ends up with the correct cards.
		However, I think this is because test one is simple and focuses on card count.
		
	-Test 2 Failure
		In this test, the function fails both parts of the test.
		Like with the first test, the user ends up with the same number of cards.
		However, this test was able to pick up another bug.
		This test found that the cards the user drew from their deck aren't the correct ones.
		This test is more complicated and allowed me to expose this bug.