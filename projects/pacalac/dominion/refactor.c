Adventurer:
	Changed while(z-1>=0) to while(z-1>0). This will prevent the last card from being discarded.
	
Smithy:
	Removed call to discardCard() so smithy will not be discarded after use.
	
Council:
	Removed increment of buy count for player. Also removed check for current player when looping through
	players to give everyone but the card player a card (so the person who plays the card will receive 5 cards).
	
Remodel:
	Changed gainCard(choice2, state, 0, currentPlayer); to gainCard(choice1, state, 0, currentPlayer); (changed choice2 to choice1)
	
Steward:
	Only add one coin instead of adding 2 coins. Removed else statement to discard 2 cards in hand if choice1 != 1 or 2
	(as a result, function isn't passed choice2 or choice3 as those variables are no longer used).