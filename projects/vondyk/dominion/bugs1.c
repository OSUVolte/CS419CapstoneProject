// Author: Kayla Vondy
// Filename: bugs1.c 
// Describe any bugs (i.e. fail flags) that occur when running unit tests

***** Smithy Test *****
	This card failed several tests: 
		First, the Smithy card should cause the player to draw 3 cards.
		but it actually draws 4.
		Second, since it draws more cards that it's supposed to from its
		pile, the pile count test fails.
		Third, the Smithy card was not discarded to the played pile.
	These test confirm all bugs that I introduced to the function.

***** Adventurer Test *****
	This card also failed several tests:
		First, the Adventurer card should draw cards until two coins are gained
		but it seems to discard 6 cards instead.
		Second, even when the function is forced to draw a gold card, it still
		seems to discard 6 cards.
		Third, the discard amount failed .
		Fourth, the deck count fails due to inappropriate drawing/discarding.
		Fifth, the playe pile fails due to inappropriate drawing/discarding.
	These tests confirm the bugs that I introduced to the funciton.

***** Village Test *****
	All tests passed. Looking back at the refactor.c I altered Village 
	in such a way that it is difficult to test. I altered the handpos 
	variable which changes which card is discarded but since it still 
	discards a crad the test technically passes. This would be a test 
	that I would need to improve since the bug I introduced was not caught.

***** Council Room Test *****
	All tests passed. This verifies that common tests between the cardtest
	files work on a card that was not altered (i.e. I did not introduce bugs
	into the this card).

***** isGameOver Test *****
	All tests passed.
	Coverage: 100% of lines executed and branches covered 

***** gainCard Test *****
	All tests passed.
	Coverage: 100% of lines executed and branches covered 

***** updateCoin Test *****
	All tests passed.
	Coverage: 100% of lines executed and branches covered

***** discardCard Test *****
	All tests passed.
	Coverage: 92.31% of lines executed, 100% of branches covered