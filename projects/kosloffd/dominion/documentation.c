

When a card is played, the results are carried out through the cardEffect() function.

smithy:
	The smithy card is an action card that allows the person playing it to draw three cards from his deck.  This card is discarded normally once it is played.  

	The procedure for this in cardEffect() is to:
	1. Call drawCard() three times
	2. Call discardCard()

adventurer:
	The adventurer card is an action card that causes the player to draw from her deck repeatedly until she has uncovered two treasure cards.  All the drawn cards other than the treasure cards will be discarded and the two treasure cards will be put into her hand.  This card is discarded normally once it is played. 

	The procedure for this in cardEffect() is to
		1. If the deck is empty, shuffle the discard into the deck by calling shuffle().  This step isn't necessary because the drawCard() function in step 2 both checks for an empty deck and calls shuffle() before drawing.
		2. Draw a card and put it into the player's hand by calling drawCard()
		3. Check if it's a copper, silver, or gold card.  If it is, increment the handCount for that player (state->handCount[player]) and increment a local count of treasure cards drawn.  If it isn't:
			a.	The card is moved to a temporary hand just to keep track of it.
			b. 	The count of the cards in the player's hand (state->handCount[player])
			 	is decremented, effectively removing the card from his hand.
		4. Repeat steps 1-3 until two treasure cards are drawn. 
		5. Discard all the cards in the temporary hand by assigning the cards in discard[currentPlayer][discardCount] to them.

discardCard()
	1. Checks the value of the "trash card" flag in the function call and if it's value is negative, it adds the card to the playedCards array.  (For some reason there is no effect in this function if the trashFlag is set to a positive value.)
	2. Changes the value of the card in the player's hand array to -1 ("erases" the card in the hand)
	3. If the last card in the hand was played, it simply reduces the count of cards in the player's hand by one.
	4. Does a redundant and unreachable check to see if the player has only one card in his/her hand and reduces the count of cards by one (this case is covered by step 3).
	5. Otherwise it replaces the card in that position with the card in the last position in the hand and reduces the card count by one.


updateCoins()
	1. Initializes the coin count to zero
	2. Checks each card in the player's hand to see if it is a copper, silver, or gold coin and adds 1, 2 or 3 to the coint count, respectively.
	3. Adds to the coin count any bonus value that was passed in as a parameter.