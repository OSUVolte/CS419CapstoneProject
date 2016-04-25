Patrick Ho
Assignment 3
Due April 24, 2016

Bug Report

unittest1, unittest2, unittest3, unittest4

	All test cases PASSED

cardtest1 - smithy card

	* In test case 1, the current player does not receive 3 cards, but only 1 
	  extra card. The drawCard() function is called only once instead of 3 times 
	  as instructed by the loop.

	* In test case 2, the expected deck count should reflect 
	  10 - 5 (initial hand) - 3 (smithy action) cards drawn, which should leave 
	  2 cards in the deck. However, the test shows 3 cards are in the deck, which 
	  means 2 cards were drawn as an effect of the smithy card action.  In the 
	  previous bug, we noted that only 1 card was drawn.  The extra card drawn is 
	  another bug. In the cardEffect() function, a switch statement controls what 
	  action to take when a card is played.  The case that controls playSmithy() 
	  does not have a break statement to terminate the case. This causes the function 
	  to fall through to the next case, which is the playVillage() function. 
	  playVillage() function will draw a card, therefore, the additional card was 
	  detected in our test.

cardtest2 - adventurer card

	* In test case 2, the expected deck count should be between 3 and 5.  However,
	  the test shows that the remaining number of cards in our deck is 2 meaning an
	  extra card was drawn as an effect of playing the adventurer card. This is a bug
	  in playAdventurer(). The draw loop to find treasure cards executes once more 
	  because the breaking condition is not met until after the third treasure card is
	  found.

cardtest3, cardtest4

	All test cases PASSED
	

