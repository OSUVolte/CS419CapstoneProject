Cards
	Smithy
		action card
		player draws three cards
		Implementation: drawCard() function called in a for loop that runs 3 times
		card at handPos discarded

	Adventurer
		action card
		Player draws cards from her deck until two treasure cards are revealed.
		Treasure cards are put in player's hand and other revealed cards are discared.
		Implementation: While loop until two treasure cards are drawn.
			In while loop
				if player's deck is empty discard pile is shuffled and added to deck
				card is drawn
				if card drawn is copper, silver, or gold
					treasure count is incrmemented
				else
					card is added to temp hand to be discarded later
			end while
			while there are cards in the temp hand
				discard card
			end while

Methods
	int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
	Discards cards from the current player's hand
	If the trashFlag is not set, cards are added to the played pile by setting the played cards to the current players hand position
	The current player's hand position is then set to -1
	Cards are removed from the player's hand
		if the hand position is equal to the handCount - 1 (number of cards in hand - 1), number of cards in hand decremented
		esle if only one card in hand, number of cards in hand decremented
		else discareded card is replaced with last card in hand, last card is set to -1, number of cards in hand decremented



	int updateCoins(int player, struct gameState *state, int bonus)
	This function sets the number of coins a player has to use that turn.
	The number of coins is set to 0, then the value of each coin in the players hand is added to the coins variable
	Copper coins are +1, Silver +2, gold +3
	If any bonus coins are available, those are added to coins variable

