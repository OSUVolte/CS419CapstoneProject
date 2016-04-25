The first bug I encountered was in Smithy:

Test for smithy card effect
===================
	Test that hand increase is correct.
	Test passed. Target handcount: 7, Actual: 7
	Test that empty deck will reshuffle for smithy.
	##TEST FAILED##. Target handcount: 7, Actual: 5

This indicated that a reshuffle did not occur and that the effect function terminated.
This was a bug that I introduced into smithy. I was able to correct it by allowing
the draw card functionality to do the empty deck check so that three cards will be
drawn in any scenario.

Test for adventurer card effect
===================
Test that Adventurer card discard is correct.
##TEST FAIL## Adventurer not present in final discard.
Assertion failed: (discard(&state)==1), function main, file cardtest2.c, line 40.
Abort trap: 6

This indicated that there was no discarded adventurer card. I corrected this in my refactored code.

Test for great hall card effect
===================
	Test that hand increase is correct.
	Test passed. Target handcount: 5, Actual: 5; target action count = 1, Actual: 1
	Test that empty deck will reshuffle for great hall.
	Discard count: 5, Deck count: 0	Test passed. Target handcount: 5, Actual: 5
	Test that Adventurer card discard is correct.
	##TEST FAIL## Great hall not present in final discard.

This indicated there was a bug with the discard. Tracing back the code led me to my original
introduced bug, which was that handPos was changed with the enum value of great_hall, which
led to discard of a random card in or out of bounds of the tracked hand array. Correcting
this resolved the error.

