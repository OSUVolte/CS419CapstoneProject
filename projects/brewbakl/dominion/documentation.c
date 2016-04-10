Smithy Card:

	Smithy card will allow you to draw three new cards and adds them to your draw pile or your hand.  It loops the DrawCard() function to achieve this.  After the user draws 3 cards, discardCard() is run to remove the smithy card from the players hand.

Adventurer Card:

	Adventurer card allows the player to continue to draw cards until two treasure cards are found.  When they are found, the user is allowed to put them into their hand.
	
	The card uses a while loop to continue drawing until 2 treasure cards are found.  A simply psuedocode is as follows:
	
		Adventuer while (lTreasure Card < 2) 
			shuffle discard pile into deck
			draw card into hand
			if Treasure, Treasure + 1
			Else, put card in temp, remove from hand
				increase temp counter
		After While Loop
			Loop through temp, adding all temp to discard pile
			
discardCard()
	Dominion uses this functino to remove a card from the players hand.  Can be invoked by a card, but usually occurs as the end of a turn.  The card discarded ends up in the discard pil stack.  It has several inputs, including position of the card in your hand, current player, game, and a flag to show which pile the card goes to.  
	
updateCoins()
	This function is called usually before the buy stage of a turn, but it can also be invoked by a card.  It adds coins to a players turn based on the value of treasure cards played, and the bonuses from cards and/or actions.
	
