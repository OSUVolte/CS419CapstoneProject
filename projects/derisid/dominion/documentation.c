/*documentation.c
Summarize understanding of Smithy, Adventurer, discardCard and updateCoins functions


Smithy:  Playing the Smithy card enables the user to to draw three cards, the smithy card is subsequently discarded

Adventurer:  An action card, that when played, allows the user to draw cards until two treasure cards have
			accumulated.  These two treasure cards are added to the player's hand, while any non treasure cards
			that were drawn are discarded.

discardCard:  This function checks to see if the card currently held has been trashed via the trash flag
			  if this flag is not set, the card is set on the played pile, it is removed from player's hand
			  decrementing the amount of cards in the hand, if it is not the last or only card in the hand
			  the last card in the hand replaces the discarded card.

updateCoin:  Upon its invocation this function sets the player's coin count back to 0, it then 
			 looks through the player's hand and adds up the values of all found treasure cards.
			 It then adds in the bonus in one final update of the count.			  