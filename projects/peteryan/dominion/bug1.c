/*
buyCard()
	There is no bound checking for whose turn it is.  The function executed
	without a problem when state.whoseTurn was an invalid number [negative and
	more than max players].  When using invalid input for state.whoseTurn 
	the test PASSED when I expect it to FAIL.  
	
	The function failed to add the card to the player's hand or deck.
	
	There is no bound checking for the supplyPos of card to buy.  An invalid
	card can be passed to getCost([card]).  If an invalid card is passed the
	getCost() the player gains a coin.
	
isGameOver()
	If there is a miscalculation in the number of cards in the supple stacks
	and a stack or stacks ended up with a negative number it will not be viewed
	as empty.  Game over was not triggered when all stacks had negative values.
	
updateCoins()
	There is no input validation for updateCoins().  When passed a bonus that
	is negative, the bonus is taken away from the total coins.
	
playSmithy()
	The smithy card failed when drawing three cards and discarding one.  There 
	should have been a net gain of two cards.  The function to play the smithy
	card does not return 0 when it executes successfully.  The smithy card was
	added to the played stack.  These bugs are the ones I introduced into the
	smithy card effect.
*/