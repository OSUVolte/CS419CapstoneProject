/*
	Name:						Daniel OFarrell
	Course:						cs362-400
	Date Created:					22 April 2016
	Last Modification Date:				24 April 2016

	Summary:
		bug1.c is a report of all bugs found through all 8 tests performed.

	1. cardtest1.c		smithy card
		test 01: (+2 -discard) cards fails.
		handCount and deckCount do not match. this is due to a bug introduced during 
		refactor.c's first round where the amount of cards to be drawn are changed to only
		be +1 card, not +2
	2. cardtest2.c		great_hall card
		All tests pass.
	3. cardtest3.c		council_room card
		All tests pass.
	4. cardtest4.c		adventurer card
		All tests pass. An earlier bug that was introduced was removed in order to facilitate
		the running of the tests. see refactor.c for more information.
	5. unittest1.c		shuffle()
		All tests pass.
	6. unittest2.c		getCost()
		All tests pass.
	7. unittest3.c		scoreFor()
		test 03: curse in deck failed.
		test 06: estate in deck failed.
		test 09: duchy in deck failed.
		test 12: province in deck failed.
		test 15: great_hall in deck failed.
		Every test where a card of value is added only to the deck and no where else fails
		each time it is run. According to scoreFor(), the for loop iterates based on 
		state.discardCount, not state.deckCount.

		test 16: gardens in hand failed.
		test 17: gardens in discard failed.
		test 18: gardens in deck failed.
		These three tests are related. According to the official Dominion documentation,
		Gardens add +1 point for every 10 cards in a player's possession. However, the 
		implementation is wrong. in scoreFor(), there is a call using fullDeckCount().
		However, this is wrong, as fullDeckCount() will just return the number of a 
		particular card, rather than all the cards in ther deck. Instead, the programmer
		should consider (state.deckCount + state.discardCount + state.handCount). 

	8. unittest4.c		updateCoins()
		All tests pass.


*/
