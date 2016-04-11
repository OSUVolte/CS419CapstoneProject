Card Descriptions
	Card Name: Adventurer
	Card Type: action card
	Cost: 6 coins
	Effect: Reveal cards from your deck until you reveal 2 Treasure cards. 
	Put those Treasure cards in your hand and discard the other revealed cards.
	Implementation: Adveturer uses a while loop to go through your deck until two treasure cards are drawn.
		            While in that loop, it checks if the players deck is empty, if the card drawn is a 
					treasure card or if the card is a non-treasure card. If the deck is empty then it shuffles
					the discard pile and adds it back to the players deck. If the card is a treasure card, then 
					a counter "drawntreasure" is incremented. If the drawn card is a non-treasure card then it 
					goes to a temp hand to be discarded later. The loop continues to cycle until the "drawntreasure"
					counter reaches 2. Once this loop breaks out, a new loop is started to discard all of the cards 
					in the player's temp hand.
					
	Card Name: Smithy
	Card Type: action card
	Cost: 4 coins
	Effect: Adds 3 cards from the deck to the player's current hand
	Implementation: The function called drawCard() is called 3 times in a for loop, after which card in use 
	                (smithy) is discarded.

Methods
	Function: discardCard
	Description: Discards the card in use from the current player's hand
	Head: int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
	Implementation: First it checks if the trashFlag is not set, in which case the cards are added 
	                to the played pile. It does this by setting the played cards to the hand position
					of the active player, and then followed by incrementing played card counter. Then 
					the hand position of the active player is then set to -1. To then remove the card from
					the player's hand it checks if the hand position is either the last card in hand, the 
					only card in hand, or neither of those. If the hand position is the last card in hand,
					then it simply decrements the hand count by 1 and moves on. If its the only card in hand, then it
					also simply  decrements the hand count by 1 and moves on. If however its neither of these,
					then it replaces the card at the current hand position with the last card in hand and sets
					the last card to -1, followed by decrementing the hand count by 1.

	Function: updateCoins
	Description: This function updates the number of coins that a player can use that for their turn.
	Head: int updateCoins(int player, struct gameState *state, int bonus)
	Implementation: First the number of coins is set to 0, then in a for loop that cycles through the 
	                player's hand, the value of each coin come accross gets added to the coins variable
					for the player. Copper coins are valued at 1, Silver at 2, and gold at 3. Finally it
					adds any bonus coins the player	may have.