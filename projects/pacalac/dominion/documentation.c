Cards:

	Smithy: 
		loop 3 times and calls drawCard() to draw 3 cards for the current player.
	
	Adventure:
		Loops through the deck drawing cards. Checks if the top card in the deck is a treasure card and adds it to the hand if it is.
		After 2 treasure cards added to player's deck, discards all non-treasure cards drawn.



Functions:

	discardCard()
		Places a card in the played pile if the trash flag is not set. Sets the handPos of the played card to -1.
		If card to discard is last in the hand array or there is only one card in the hand, reduce the handCount by 1 to play card.
		Otherwise, replace the discarded card with the last card in the array and reduce handCount by 1.
		
	updateCoins()
		Loops through all cards in players hand. If the card is a treasure card, update the player's coin count by the appropriate
		level based on if it is a copper, silver, or gold card.