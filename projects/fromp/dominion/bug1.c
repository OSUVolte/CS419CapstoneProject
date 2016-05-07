gainCard():
	No bugs found

buyCard():
	No bugs found

updateCoins():
	No bugs found

fullDeckCount():
	No bugs found

smithyCard():
	Hand count is incorrect after using card. There is one more card than there should be.
	The deck count is incorrect after using card. There is one fewer card in the deck than there should be.
	The discard pile is incorrect after using card. The smithy card is trashed instead of put in discard pile after use.

adventurerCard():
	There is one more card in hand than there should be after using this card.
	The decks do not match after using this card. The deck is shuffled when it should not be.
	The discard pile is incorrect, this seems to be a result of incorrect shuffling.

council_roomCard():
	Cards in hands of both players are incorrect. Player 1 has too few cards, player 2 has too many cards.
		(Player 2 seems to be drawing cards when player 1 should be drawing.)
	Player 2 has zero buys after using this card, but the player should have 2 buys.
	
remodelCard():
	An incorrect card is discarded (the card one position less than the remodel card is discarded).
	The hand size is incorrect after using this card when invalid options are used.
		(The function is supposed to return -1 when the card to gain has a cost greater than 2 more than
		 the card to be trashed. This does not happen.)
	In some cases after using this card, the supply not match due to the above bug.
	The card to be trashed is not trashed, but only put in the cards played pile.
