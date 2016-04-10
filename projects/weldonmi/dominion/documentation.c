/*
Miranda Weldon
4/9/2016
CS 362 Spring 2016
Assignment #2
documentation.c

Smithy:
	The smithy card draws three cards for and adds them to the player's hand. It does this by calling drawCard() in a for loop 
	and then calling discardCard() on the smithy card itself. Then it returns 0 to signal success.

Adventurer:
	The adventurer card adds two treasure cards to the player's hand from the deck. In code, it tallies the amount of treasure
	cards	drawn from the deck and adds it to the player's hand. It does this by shuffling the discard pile into the deck if the
	deck was empty and then drawing cards in a loop until the drawntreasure variable reaches 2. If the card drawn was a copper,
	silver, or gold, drawntreasure variable is incremented, otherwise the card is marked in a different variable and removed from
	the player's hand. Then it will discard all non-treasure cards that have been drawn in another while loop. It will then
	return 0 for success.

discardCard():
	This method 'validates the card being played then calls cardEffect to play the card'. It takes the gamestate, the position in
	the player's had where the card is, the current player, and a trash flag. If the trash flag is 0, then a card will be added
	to the played card pile, then it will remove a card form the player's hand. This involves reducing the amount of card in the
	player's hand and (if the players hand has multiple cards) replacing a discarded card with the last card in the hand. It will
	then return 0 to signal success.

updateCoins():
	This method 'returns the count of a specific card in a specific player's discard deck and hand'. It takes the gamestate, a
	particular players and the bonus. It resets the coin count and then uses a for loop to add up the values of the treasure
	cards played. It then adds the bonus to the player's coin total and return 0 for success.

*/
