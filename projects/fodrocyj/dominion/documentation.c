Documentation of Dominion
John Fodrocy

Smithy Card:
	This is a simple card which causes the user to draw three additional cards.
	This card uses the drawCard() function three times.
	This function will remove a card from the game state's deck of the player.
	It then moves that card to the game state's hand of the player.
	The smithy card also uses the discardCard() function to discard the smithy card.
	The discardCard() function, which usually puts the card back into the player's hand.
	However, the discardCard() function has an option to trash the card.
	The discardCard() function also manages the number of cards in the player's hand.
	
Adventurer Card:
	This card looks through your hand from the top until it finds two treasure cards.
	Every non-treasure card you drew is put back into the deck, but the two treasure cards are added to your current hand.
	Like the smithy card, the adventurer card uses drawCard() and discardCard(), but it is more complicated.
	It first makes a temporary array of cards that will be filled by the cards drawn, which may be more than two.
	It also keeps track of the amount of cards drawn and the amount of tresure cards drawn.
	It executes a while loop that goes until two treasure cards have been drawn.
	Finally, it has to discard all of the cards that have been drawn by the use of the adventurer card.
	
discardCard():
	This function is used when a card is put back in the deck or is trashed.
	First, the functon checks if the trash flag exists.
	If it doesn't, then the function adds the card to the array of played cards.
	It also increments the index of played cards this hand.
	It then sets the hand position value of the played card to -1, indicating the card has been played.
	Finally, the function removes the card from the hand of the current player.
	
	
updateCoins():
	This function updates the number of coins on the table at any given moment.
	It function does not update the number of coins a specific player has.
	This function looks through all the cards in a specific players hand.
	If a card is a coin card, it adds the appropriate value to the number of coins on the table.
	The function updateCoins() also takes an argument to add bonus coins.