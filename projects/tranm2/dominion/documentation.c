# Author: tranm2
# CS362 - Spring 2016

# Documentation for 'smithy' card code
Location: dominion.c
Effect: current player draws 3 cards using drawCard() method
After applying effect, return card back to discard pile using discardCard() method

# Documentation for 'adventurer' card code
Location: dominion.c
Effect: reveal cards from deck until you reveal 2 Treasure cards (drawntreasure == 2).
drawntreasure doesn't seem to have a starting value.
Put those Treasure cards in your hand and discard the other revealed card to discard pile.
The non treasure cards are stored temporarily in temphand[] array.
	  
# Documentation for discardCard() method
Location: dominion_helper.h
Description: validate the played card and execute the card's effect. Return 0 on success
Input: 
	- handPos: position of the card in the hand
	- currentPlayer: player that has the turn
	- state: pointer of gameState variable
	- trashFlag: determine if the card will be trashed (1)
	
# Documentation for updateCoins() method
Location: see dominion_helper.h
Description: Returns the coin count for all played cards plus the card bonus effect
Input:
	- player: player that has the turn
	- state: pointer of gameState variable
	- bonus: bonus coin from card's effect

