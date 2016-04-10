/***
Documentation on smithy & adventurer cards, as well as a description of both the discardCard() and updateCoins() methods.

Smithy - An action card that gives a player 3 new cards(via the DrawCard loop) during the action step that it is played, and then the Smithy card is 
	discarded.

Adventurer - An action card that allows a player to reveal cards from their deck until they have drawn two treasure cards, which could be a copper,
	silver or gold coin. All of the cards that are drawn before retrieving two Treasure cards are then discarded. In code, this is done with a while loop
	that requires 'drawntreasure' to increment to two before it exits the loop. Until it does, all cards are placed into the 'temphand' array which are 
	then discarded once two treasure are drawn.
	

discardCard() - Takes four arguments: Current position in the player's hand of the card to discard, the current player, a pointer to the gameState 
	variable, and a flag that sets whether or not the card is trashed or goes into to the user's 'played card' pile. Within the method, if the trash flag
	is not set, it is then added to the player's 'played card' file for future use. The card is then set to -1 so that it cannot be drawn again. Then, the
	card is removed from the player's hand and their handCount is decremented. 
	
updateCoins() - Takes three arguments: Current player, a pointer to the GameState variable, and any bonus that the player may receive from a card. Within 
	the method, coins is set to 0, then a loop counts each treasure card in the player's hand and totals the amount of coins. Finally, if a bonus is to be 
	added, it is done so before the method is returned. 
	
***/