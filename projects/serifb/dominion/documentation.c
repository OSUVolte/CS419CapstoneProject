/*
Name:		Bryan Serif
filename:	documentation.c
Date:		04/10/2016

Cards:

	Smithy: Smithy is an action card that allows the player to draw three
	additional cards. The player then discards the smithy card. The code performs
	this by first calling the drawCard() function in a for loop for 3 iterations.
	It then calls the discardCard() function using the handPos of the played
	Smithy card.

	Adventurer: Adventurer is an action card that allows the user to thumb through
	their draw pile until two treasure cards are drawn. The treasure cards are then
	added to the player's hand and the remaining cards revealed are discarded. The
	cade performs this by the following:

		while (player has not drawn two treasure cardse)
			if the draw pile is empty, shuffle the deck
			drawCard()
			if (the card is a tresure card (copper, silver, or gold)
				increment the treasure count
			else
				add the drawn card to a temp hand

		while (cards are in temp hand)
			discard cards

Methods:

	discardCard(): performs a discard on a single card or the player's entire hand
	
		check if the card has been trashed
		mark the card as played
		remove the card from the player's hand and decrement the hand size

	updateCoins(): updated the number of coins the player has in his hand

		set the total to 0
		iterate through the cards and if they are treasure then increment the total
			by the value of the treasure
		add a bonus if needed
*/