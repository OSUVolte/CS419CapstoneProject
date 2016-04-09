Smithy card:
The smithy card starts out with a for loop that runs 3 times.  The player draws
a card each time through the for loop for a total of 3 cards.  Then, the player
discards the smithy card.  Finally, the cardEffect() function returns a value of
zero.

Advernturer card:
The adventurer card has two while loops.  The first while loop is for drawing cards.
The player draws cards until they have drawn two treasure cards.  If their deck
becomes empty, it gets shuffled so that they can continue drawing cards.  If the
card they draw is a treasure card, it gets added to their hand, if it is not a
treasure card, it gets added to a temporary hand.  Once two treasure cards have
been drawn, the second while loop goes through the cards in the temporary hand
and discards them.  Finally, the cardEffect() function returns a value of zero.

discardCard():
This is a function for discarding cards from the player's hand. If the card is
not trashed, it is added to the list of played cards and the count of played cards
is incremented.  Next, the value of the played card in the player's hand is set
to -1 to signify that it has been played.  Then, if the card is the last card in
the array of cards in the player's hand or if the player only has one card in their
hand, the count of cards in their hand is decremented.  Otherwise, the card is
located somewhere before the end of the array of cards in the player's hand so
the last card in the array of cards in the player's hand is moved to the position
of the played card in the hand array and that card's spot is set to -1 before
decrementing the count of the cards in their hand.  Lastly, the function returns
a value of zero.

updateCoins():
This is a function for updating the coins a player has available to use.  At the
beginning of the function, the coin count is reset to zero so that coins don't
get counted twice if they had been previously counted.  Then, the function loops
through the cards in the players hand and if a card is copper, silver, or gold, the
coin count is incremented by 1, 2, or 3 respectively.  Finally, any bonus coins
from cards that the player has played that turn are added to the coin count before
the function finishes by returning a value of zero.