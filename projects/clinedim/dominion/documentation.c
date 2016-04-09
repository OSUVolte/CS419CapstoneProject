/*
	In this file, I will be providing documentation for the Smithy and Adventurer
	cards, as well as an expanation of the discardCard and updateCoins functions.
	This documentation appears below.

	* Smithy Card: The Smithy Card is an action card that allows the player to 
	add draw three cards and add them to their hand.  The player then discards 
	the Smithy Card.  The code does calling the drawCard function three times
	using a for loop, followed by calling the discardCard function to get rid of
	the played Smithy Card.

	* Adventurer Card:  The Adventurer card is an action card that allows the player
	to continually remove cards from the deck until the player finds two coin cards;
	these coin cards are added to the player's hand and all of the other revealed
	cards are discarded.  The code for this card is one of the more complicated cards.
	While the user has drawn fewer than two treasure cards, the function loops and the
	current player draws a card.  If the card that the user draws is copper, silver, or
	gold, then the number of drawn treasure is incremented.  Otherwise, the card is placed
	in a temporary hand.  If the deck ever becomes empty, it's reshuffled.  Once the player
	has two coin cards, all the other drawn cards are discarded.

	* discardCard:  The discardCard function has a decent amount of code, but it's fairly
	straight forward.  If the card passed to the function has not been trashed, it's
	simply removed from the player's hand (which has its size decremented) and added to the
	played pile.  The card is "removed" by setting its value to -1.  A separate field tracks
	the size of the player's hand.

	* updateCoins:  The updateCoins function counts the number of coins that are currently
	in a player's hand and updates the state of the came to account for this.  It begins by
	initializing the coin count to 0 and then loops through each card in the deck.  If the
	current card is a copper card, then the count is incremented by 1.  If the card is a 
	silver, then the count is incremented by 2.  If the card is a gold, then the count is
	incremented by 3.  Finally, if there is any bonus to be added, this bonus is added to the
	count.  The state of the game is updated any time an incrementation occurs.
*/