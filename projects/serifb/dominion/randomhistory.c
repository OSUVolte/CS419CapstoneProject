/*
	Bryan Serif
	CS 362 Assignment 4
	05/08/2016
	randomhistory.c
	
	
	This file details the design of the two random card testing programs. These
	random testers cover both the adventurer card and the smithy card. The two
	file names are:
	
		randomtestcard.c
		randomtestadventurer.c
	
	These files can be compiled and run using the Makefile with the folloeing
	commands:
	
		make randomtestcard.out
		make randomtestadventurer.out

	When these commands are run they will create the two files randomtestcar.out
	and randomtestadventurer.out. In these files there will be details on the
	number of tests run, the results of the tests, and the coveregae information.
	
	
	---randomtestcard.c---
	
		randomtestcard.c covers the random testing of the smithy card. When the player
		plays  smithy the following actions are to occur. The player draws two cards
		from his deck and the player then discards the smithy card. This should result 
		in a net +1 gain to the player's hand and a net -1 loss to the player's deck
		and discard combined. The design for this test is as follows:
		
			1. For ease of use I created a more OOP approach to the testing. This meant
			creating structs for the player information, the run error information, and
			the total testing error information.
			2. In the testing the game state was chosen to be completely randomized.
			This means that the game is able to be tested in conditions where the
			size of the hand, deck, and discard piles all varied.
			3. Hand size is determinined first by using the max hand size and moddding
			it with a random number. The first card in the hand is set to a smithy.
			Next the hand cards are iterated through to count the number of treasure
			cards and store it into a Player struct holder. 
			4. The above is then done again for the deck and the discard piles. The
			deck size if found by modding (MAX_HAND - hand size). The discard deck 
			size is found by rand() & (MAX_HAND - hand size - deck size + 1). This
			is done to cover all options from a completely empty hand / deck / discard
			to a combination that reaches the maximum allowable. Both of these are
			iterated through as well to count the number of treasure cards.
			5. The number of actions, buys, and coins are then genereated and stored
			for the pre-game state. These can all range from 0 - 99.
			6. Last for the randomization the measurements are taken for the opponent
			conditions in a matrix opponents[Max_PLAYERS - 1][3]. This allows for the
			number of playes to be changed without having to change the test for the
			change.
			7. The error counters are set and the cars is played.
			8. It check for the conditions of the actions, buys, and coins. 
			9. It then checks that the hand count has changed accordingly.
			10. Check for the deck + discard count
			11. During the checking of the hand, deck, and discard counts the
			treasure count is accumulated.
			12. Check that the number of treasures remains the same.
			13. Check the opponent conditinos to verify that none of those have
			changed.
			14. Print the test run errors if any and sum the errors into the 
			total errors
			15. When all individual runs have completed, print the total stats from
			the test.
		
		This was the dominion coverage number for 100 runs of the tests:
		
			Lines executed:26.38% of 561
			Branches executed:26.39% of 413
			Taken at least once:17.92% of 413
			Calls executed:15.63% of 96
			
		The smithy coverage was:
			
			Function 'playSmithy'
			Lines executed:100.00% of 4
			No branches
			Calls executed:100.00% of 2
			
		This shows a decent amount of coverage for just the one card being tested.
		Much of this comes from the runnong of initialize game and the associated
		functions inside of card effect such as discard and shuffle. The full
		testing results can be found in randamtestcar.out. One error i did
		notice was that the card counts were consistently incorrect. They both
		varied by 1 which leads me to believe (as I am testing my refactored
		version with the added bug) the the bug is introduced correctly and only
		has the player draw 1 card. The one bug that I was not expecting was the
		discrepancy in the treasure count between pre and post conditions. This
		tended to only vary by 1 or 2 but sometimes was as much as 9. I believe
		this has to do with the introduced bug and how it affects the ability to
		run through the total number of cards after a possible shuffle.
		
	---randomtestadventurer.c---
		
		randomtestadventurer.c covers the random testing of the adventurer card. When 
		the player plays adventurer the following actions are to occur. The player draws 
		cards from his deck until the player has drawn two treasure cards. This 
		should result in a net +1 gain to the player's hand and a net -1 loss to the 
		player's deck and discard combined The deck and discard should also lose 2 
		treasure cards and the hand should gain two treasure cards. 
		The design for this test is as follows:
		
			1. For ease of use I created a more OOP approach to the testing. This meant
			creating structs for the player information, the run error information, and
			the total testing error information.
			2. In the testing the game state was chosen to be completely randomized.
			This means that the game is able to be tested in conditions where the
			size of the hand, deck, and discard piles all varied.
			3. Hand size is determinined first by using the max hand size and moddding
			it with a random number. The first card in the hand is set to an adventurer.
			Next the hand cards are iterated through to count the number of treasure
			cards total and each type of treasure and store it into a Player struct holder. 
			4. The above is then done again for the deck and the discard piles. The
			deck size if found by modding (MAX_HAND - hand size). The discard deck 
			size is found by rand() & (MAX_HAND - hand size - deck size + 1). This
			is done to cover all options from a completely empty hand / deck / discard
			to a combination that reaches the maximum allowable. Both of these are
			iterated through as well to count the number of treasure cards.
			5. The number of actions, buys, and coins are then genereated and stored
			for the pre-game state. These can all range from 0 - 99.
			6. Last for the randomization the measurements are taken for the opponent
			conditions in a matrix opponents[Max_PLAYERS - 1][3]. This allows for the
			number of playes to be changed without having to change the test for the
			change.
			7. This is done in a loop to control the number of treasure cards needed
			as to not throw the test into a possibly infinite loop / seg fault
			8. The error counters are set and the cars is played.
			9. It check for the conditions of the actions, buys, and coins. 
			10. It then checks that the hand count has changed accordingly.
			11. Check for the deck + discard count
			12. During the checking of the hand, deck, and discard counts the
			treasure count is accumulated.
			13. Check that the number of treasures remains the same.
			14. Check the opponent conditinos to verify that none of those have
			changed.
			15. Print the test run errors if any and sum the errors into the 
			total errors
			16. When all individual runs have completed, print the total stats from
			the test.
			
		This was the dominion coverage number for 100 runs of the tests:
		
			Lines executed:23.53% of 561
			Branches executed:24.94% of 413
			Taken at least once:16.95% of 413
			Calls executed:12.50% of 96
			
		The adventurer coverage was:
		
			Function 'playAdventurer'
			Lines executed:100.00% of 17
			Branches executed:100.00% of 10
			Taken at least once:90.00% of 10
			Calls executed:100.00% of 2
			
		There was not one succesfful run of the adventurer card in 100 tests. 
		There were deck/discard count and tresure count errors in every single
		run of the tests. I believe this is due to the fact the the adventurer
		function does not call discardCard() which does not allow the drawn
		cards that are not tresure to be accounted for. The next highest error
		count was the hand treasure count. 89% of the time the number of 
		treasure actually in the hand was greater than the number expected. This
		does not concern me as the bug introduces in this was to not count gold
		cards when drawing cards. Combine this with the function not discarding 
		the cards back into the discard pile this would account for the discrepancy.
		One functionality that I should have expanded for to properly check for
		this possibility would have been to check which treasure counts increased
		in the hand. When one was noted to increase then the number should have been
		checked in the deck/discard piles to confirm if those number actually
		decreased.
	*/