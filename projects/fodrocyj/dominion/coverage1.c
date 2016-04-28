John Fodrocy
Assignment 3 Bug Report

Unit Test 1 - getWinners()

	File 'dominion.c'
	Lines executed:27.50% of 560
	Branches executed:34.53% of 417
	Taken at least once:28.78% of 417
	Calls executed:9.47% of 95
	
	This test covered the getWinners() function in dominion.
	It has fairly good coverage, because of the nature of the function.
	Of all the functions I tested, this one warrented to most tests.
	This is becaus of the various scenarios in which a game can end.
	
Unit Test 2 - fullDeckCount()

	File 'dominion.c'
	Lines executed:27.50% of 560
	Branches executed:34.53% of 417
	Taken at least once:28.78% of 417
	Calls executed:9.47% of 95
	
	This function covered fullDeckCount() from dominion.c.
	It covered a lot of the specific area of a player's cards.
	This is because it had to cycle through the player's deck, discard and hand piles.
	This test also required quite a few calls to other function, mainly to set up scenarios.
	
Unit Test 3 - isGameOver()

	File 'dominion.c'
	Lines executed:29.11% of 560
	Branches executed:36.45% of 417
	Taken at least once:30.46% of 417
	Calls executed:9.47% of 95
	
	These tests checked the isGameOver() function.
	I was surprised by the amount of branches executed because the function is fairly simple.

Unit Test 4 - scoreFor()
	
	File 'dominion.c'
	Lines executed:29.11% of 560
	Branches executed:36.45% of 417
	Taken at least once:30.94% of 417
	Calls executed:9.47% of 95
	
	This function walks through each of the player's piles of cards.
	It then calculates a score based on what it finds.
	It is a very simply function, but it has fairly good coverage.
	I think this is caused by the cycling of scoreFor() through piles.
	
Card Test 1 - Smithy Card

	File 'dominion.c'
	Lines executed:37.32% of 560
	Branches executed:46.28% of 417
	Taken at least once:34.29% of 417
	Calls executed:16.84% of 95
	
	This function tests the Smithy card.
	Coverage is surprisingly high with this card since its role is very simple.
	I think once again that setting up for tests for the card is the reason for a lot of the coverage.
	This was also one of the cards I introduced a bug into.
	
Card Test 2 - Adventurer Card

	File 'dominion.c'
	Lines executed:39.46% of 560
	Branches executed:49.16% of 417
	Taken at least once:36.69% of 417
	Calls executed:18.95% of 95
	
	Of all the cards I tested, this one seemed to me like it would produce the best coverage.
	This card is a little more complicated and has more branches than other cards.
	I think the results show this, as it has high branch and execution coverage.
	
Card Test 3 - Village Card

	File 'dominion.c'
	Lines executed:40.36% of 560
	Branches executed:49.16% of 417
	Taken at least once:37.17% of 417
	Calls executed:21.05% of 95
	
	This was very surprising to me, as I thought the village card was very simple.
	Once again, I think the reason for the higher than expected coverage was the setup.
	
Card Test 4 - Great Hall

	File 'dominion.c'
	Lines executed:43.39% of 560
	Branches executed:51.56% of 417
	Taken at least once:38.61% of 417
	Calls executed:27.37% of 95
	
	For my last card test, I tested the Great Hall card.
	This card is also fairly straight forward but it seemed to have executed a surprising amount of calls.
	Specifically calls which hadn't been executed at the time.