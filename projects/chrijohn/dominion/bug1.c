The following bugs were found.  If a tested function or card is not listed, it means there were no bugs

scoreFor()
	Bug1: GradensFullDeckCount
	When entering a player with all 15 gardens throughout their hand, it gave them a score of 0 instead of 15.
	Gardens is suppose to give 1 vicotry point for every 10 cards in their deck. So a 15 garden deck should give
	15 points (1 for each Garden).
	The bug is in getting the number of total cards in the deck.  The current code is just getting the count of card 0

	Bug2: DeckScore
	The function is not calculating the correct score from the players deck.
	The bug is instead of iterating through the number of cards in the deck, it is iterating through the number of cards
	in the discard pile.  If the player has more cards in their deck, it means cards will be missed.

Smithy
	Bug1: DiscardCount
	The discard deck count is suppose to be 1 but is 0.  Looking at the source code, this is because the smithy card
	is not discarded.

	Bug2: DeckCount
	The players deck/draw pile is suppose to be 2 but is actually 3.  Looking at the source code, this is because the 
	player only draws 2 cards instead of 3.

	(Note, together these two bugs make the players hand count the same, meaning additional testing is required
		over just testing if the players hand is +2)

Adventurer
	Bug1: HandCount
	The players hand count is expected to increase by 1 but it actually increased 2.
	According to the source code, the adventurer is (incorrectly) never discarded

	Bug2: Discard/DeckCount
	This players combined amount of cards in their deck and discard is expected to decrease 1 but decreased 2
	This is also caused by not discarding the adventurer card.

Gardens
	Bug1: ActionCount
	The numbers of actions is suppose to remain the same, but this increased from 1 to 11.
	According to the source code, the player gets two extra actions for every card in their deck.  That is not right.

	Bug2: HandCount
	The players hand is suppose to decrease by 1 but it remaines the same.
	The code incorrectly does not discard the garden card

	Bug3: DiscardCount
	The players discard pile is suppose to increase by 1, but it remained the same.
	The code incorrectly does not discard the garden card

Village
	Bug1: DiscardCount 
	The number of cards should in the discard should increase 1, but it remains the same.
	The discardcard() function has a bug where it does not place the card in the discard pile.
	