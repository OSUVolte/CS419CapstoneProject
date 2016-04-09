Brett Irvin
CS 362_400--Software Engineering II
4/3/16
Assignment 2--documentation.c 

Dominion Documentation

Smithy Card: 
	A Smithy card is an action card that allows the player to draw three cards from the top of the player's deck.  After the
	card is played, it is discarded. The card's cost is 4 coins.
	
Adventure Card:
	The Aventure card is an action card that allows a player to reveal cards from his or her deck until 2 Treasure cards are
	found.  The Treasure cards are placed in the player's hand and the other revealed cards are discarded.  The card's cost is 6 coins.

discardCard() function:
	The discardCard function lets a player discard a card.  When called, the function determines the card's
	position in the hand (handPos), which player is discarding (currentPlayer), the current state of the game (*state,
	which is a pointer to a gameState variable), and finally, sets the trashFlag to indicate that the card has been
	placed in the discard pile.
	
updateCoins() function:
	The updateCoins function updates a player's coin count.  When called, the function resets the player's coin count
	to zero, adds up the coins for each of the player's Treasure cards in his or her current hand, then adds in any bonus.