Adventurer:
	Changed while(z-1>=0) to while(z-1>0). This will prevent the last card from being discarded.
	
Smithy:
	Removed call to discardCard() so smithy will not be discarded after use.
	
Council:
	Removed increment of buy count for player. Also removed check for current player when looping through
	players to give everyone but the card player a card (so the person who plays the card will receive 5 cards).
	
Remodel:
	Changed gainCard(choice2, state, 0, currentPlayer); to gainCard(choice1, state, 0, currentPlayer); (changed choice2 to choice1)