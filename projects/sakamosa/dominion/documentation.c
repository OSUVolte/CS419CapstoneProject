Sara Sakamoto

smithy
	Call the drawCard function for the current player three(3) times.
	Discard the smithy card from the player's hand.
    

adventurer
	While the player has not drawn two treasure cards:
	If the deck is empty, shuffle the discard and add to deck
	Draw a card
	If the card is a treasure card (copper, silver or gold).
		Keep it in the player's hand.
	Else
		Add it to the temporary hand
		Update the temporary hand size.
		Remove it from the player's hand.

	After two treasure cards have been drawn, empty the temporary hand.


			
discardCard()
	Takes as parameters the position of the card to be discarded, the player, the current game and whether the card is to go in the discard pile or be trashed.

	If card isn't set to be trashed, add to discard pile and update its count.

	Set the value fo the played card to -1 so it can't be played.
	If it was the only card in the hand or the last card in the hand, 
		remove the card from the player's hand.

	Else,
		swap it with the last card in the hand and then remove last card.

	Reduce the number of cards in the hand.



updateCoins()
	Takes as parameters the player, the current game and any bonus coins.

	Reset the player's coin count.
	Add 1 for each copper card
	Add 2 for each solver card
	Add 3 for each gold card in the player's hand.

	Add any bonus coins.

	Return the coin count.

