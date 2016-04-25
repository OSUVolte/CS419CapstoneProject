/*

Author: 	Charles Siebert
Class:	CS362-400
Date:	4/10/16 
File:	documentation.c

Description: A document describing current implementations of functions.

	1- Smithy Card : This kingdom card allows the current player to draw three cards into their hand,
		and discards the card that is played.
		
	2- Adventurer Card : This kingdom card allows the player to continuously draw from the top of the deck
		until they pull exactly two treasure cards (copper, silver, or gold) and discards the card that
		is played. The deck will shuffle if it runs out of cards in current player's deck. Each card drawn
		that is not a treasure is stored into a tempHand and them discarded into a discard pile.
		
	3- discardCard() : this method will move the cardPos given to either a "played" or "trashed" pile,
		where trashed cards will not be reshuffled back into their hands, while the played pile are
		just cards discarded and will be reshuffled back into the current players hand. The cards 
		that are flagged for both properties are changing states from currentPlayer's hand, and reduces
		their handCount by 1.
		
		Since a card is played from the currentPlayer's hand, states of hand and handCount are changed
		to reduce total count of hand by 1, changes the last card in hand by -1, and replaces the discarded card
		with the last card in hand.
		
	4- updateCoins() : For each turn played, this updates the player's coin count to 0, and acts as if the game
		plays all coins in hand to start the turn. It goes through the player's hand and finds the treasure cards
		copper, silver, and gold, and allocates 1, 2, 3 coins respectively to the player. There is a field for "bonus"
		coins to be added to the player.

*/