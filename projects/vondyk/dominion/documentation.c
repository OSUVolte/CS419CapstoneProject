****************
** File name: documentation.c
** Description: This file provides a brief explanation of
** 		the smithy and adventurer cards as well as the two 
** 		functions discardCard() and updateCoins() from the
** 		file dominion.c provided by the professor.
****************

Smithy
	--This card type is (originally) part of the cardEffect() function. 
	I separated it into it's own function called from the switch case 
	smithy (per the third part of this assignment). This card increases 
	the card count for the current player by drawing 3 cards and then 
	the smithy card is discarded.


Adventurer
	--This card type is also part of the cardEffect() function and is 
	affected by the third part of this assignment where I call a separate 
	function from the switch case. This card requires more code than most, 
	as the card is a complicated strategic play. If the deck is empty, the 
	adventurer card will shuffle the discard pile and add one card to the 
	deck. If the drawn card is a treasure card, the drawntreasure count is 
	incremented. The player will continue to draw cards until the 
	drawntreasure count is equal to 2, and all cards that were drawn which 
	were not treasure cards are discarded.


discardCard()
	--This function is passed variables for hand position (handpos), the 
	current player, a pointer to the state of the game, and a trashFlag 
	variable which determined if the card was trashed or played. The function 
	then follows a series of if statements to determine whether the last card 
	in the hand was played, there is only one card in hand or other situation 
	(handled by the else part). Each of the if statements end up reducing the 
	number of cards in the hand.


updateCoins()
	--This function is located at the very bottom of the dominion.c file. It 
	is passed variables for player, bonus, and a pointer to the state of the 
	game. After resetting the coin count for the particular player (i.e. the 
	one passed to the function) the function then cycles through the player's 
	hand and adds the Treasure Card values that are present to the players 
	coin count. If the player earned a bonus, this is added to the players new 
	coin count before the function returns.