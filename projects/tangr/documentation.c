smithy
	function with no parameters in dominion.c
	in dominion.h 	- handPos (position of card in hand)
					- gameState *state (current state of game pointer)
	function draws 3 cards for the 'current' player (currentPlayer)
	discards the used smithy card (handPos)

adverturer
	attempts to draw 2 'treasures'
	state 1 : deck is empty
				shuffle deck (shuffle discard cards)
	drawCard
	if a 'treasure card'
		true - +1 to drawn treasures 
		false - 'discard' the card
			put 'card in hand' into 'temphand'
			'discard' current card from 'temphand'

	(can this function be simplified? 
		combine the else statement with the following while statement?)
	(is there a possible infinite loop? 
		if there are > 1 treasures in the discard pile AND deck, 
		then drawntreasure > 1 will never be possible
		How can we account for this?)

discardCard
	4 parameters
	handPos - card position to 'discard'
	currentPlayer 
	gameState *state
	trashFlag

	if (trashFlag > 0)
		the card is trashed
	card position in current hand is set to -1 (played)
	ie hand[player ID][hand position in the hand] = in hand or played

	if handPos is the last card, remove the last card 
	else if it is the last card, remove last card 
		(how does this work different from the 'if'?)
		(there does not seem to be a difference)
	else
		move card to be discarded to "end" of hand
		set "card" value to -1 (or invalid)
		reduce the number of cards in hand as above

updateCoins
	sets coins to 0
	checks for :
		copper	(+1)
		Silver	(+2)
		gold	(+3)
	bonus (+bonus)

	adjusts state->coins value for each accordingly
	function returns 0
