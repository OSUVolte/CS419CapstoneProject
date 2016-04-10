/*

Eric Walters

	Smithy: The Smithy card is an action card that a player uses and allows them to draw
	3 cards. It calls the drawCard function in order to do this. The player can then
	choose to discard a card by the program calling discardCard.
	
	Adventurer: The Adventurer card gives the player the ability to draw cards until
	they are able to remove coin cards. The code also discards all cards in play that
	have been drawn.
	
	discardCard(): This function checks to see if the card has been played and if it 
	has it will put it in a played pile. If a card is played it will reduce the number
	of cards in the player's hand by 1. If there is only one card in the hand, the number
	is reduced by 1. Essentially, the function reduces the number of cards in the player's
	hand by one for several scenarios.
	
	updateCoins(): This function checks if the player has treasure coins in his/her 
	hand. If they have treasure cards, the player's coin count is increased in proportion
	to the type of treasure they hold.



*/