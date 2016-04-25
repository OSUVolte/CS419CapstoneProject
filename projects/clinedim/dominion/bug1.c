/*
	Card Tests:  I fond at least one bug in each of the cards that I tested.  Each of the cards is
	listed below, along with the bugs that were found.

	*** Smithy:
		Bug #1:  After playing the Smithy card, the player who played the card does not have the
		correct number of cards in their hand.  The player has one more card in their hand than
		the player should.  This is a result of a bug I introduced in an earlier assignment; I
		modified the code for this card by making it call the drawCard function four times
		instead of three.

		Bug #2:  After playing the smithy card, the player who played the card does not have the
		correct number of cards in their deck.  The player has one fewer card in their deck than
		the player should.  This is a result of a bug I introduced in an earlier assignment. As
		with Bug #1, I modified the code for this card by making it call the drawCard function
		four times instead of three.

		Final Thoughts:  Both Bug #1 and Bug #2 could be fixed relatively easily by changing the
		function code for the Smithy card so that it draws three cards instead of four.  I ran
		the code with this issue fixed, and my test code returned no errors.

	*** Adventurer:
		Bug #1:  After playing the Adventurer card, the player who played the card does not have
		the correct number of cards in their hand.  The player has one more card in their hand
		than they player should.  Unlike the Smithy card, this error is not caused by the player
		drawing too many cards.  Rather, it is caused by the discardCard function not being
		called in the Adventurer card's code.

		Bug #2:  After playing the Adventurer card, the number of played cards is not being 
		incremented.  This is not a desired effect of the card, and it is also a result of the
		card not being discarded after the card is played.  The discardCard function is what
		updates the number of cards.  This is definitely a bug.

		Final Thoughts:  Both Bug #1 and Bug #2 could be resolved by making sure that the
		Adventure card is discarded after it is played.

	*** Village:
		Bug #1:  After playing the Village card, the player who played the card does not have
		the correct number of cards in their hand.  The player has one fewer card than it should.
		This is a result of a subtle bug that I introduced into the function that implements
		this card.  Specifically, I changed the code so that the drawCard function is not called.
		This results in too few cards being in the deck.

		Bug #2:  After playing the Village card, the player who played the card does not have
		the correct number of cards in their deck.  The player hsa one more card than it should.
		This is also a result of the bug I introduced by removing the drawCard call that should
		be in the function.

		Bug #3:  After playing the Village card, the player who played the card does not have
		the correct number of actions.  The number of actions is one higher than it should be
		This is the result of a bug I introduced into the code in an earlier assignment. I changed a 
		line of code from 
			state->numActions = state->numActions + 2 
		to 
			state->numActions = state->numActions + 3.
		This resulted in the current bug that is occurring.

		Final Thoughts:  All of the bugs listed above are a result of changes that I made to the
		code to intentionally introduce bugs.  I confirmed this by changing the code back to what
		it was originally, and all of the tests I wrote passed.

	*** Council Room:
		Bug #1:  After playing the Council Room card, the player who played the card does not have
		the correct number of cards in their hand.  Specifically, the player has one card fewer
		than the player should have.  This is a result of a bug I introduced in an earlier assignment.

		Bug #2:  After playing the Council Room card, the player who played the card does not have
		the correct number of cards in their deck.  They have 1 more than they should.  This, too,
		is a result of a bug I introduced in an earlier assignment.

		Bug #3:  After playing the Council Room card, the player who played the card does not have
		the correct number of buys.  The player is supposed to get one my buy by laying the card,
		but the number of buys is actually being decremented.  This is a bug that I introduced 
		in an earlier assignment.

		Final Thoughts:  I re-ran the tests using the original code that was provided, and the
		tests passed.  The bugs that were found were those that I introduced during earlier intentional
		changes.

	*** All tests passed for unittest1, unttest2, unittest3, and unittest4.
*/