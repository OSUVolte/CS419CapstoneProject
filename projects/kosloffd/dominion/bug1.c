Bugs found while testing:

The discardCard() function does not discard cards -it places them in playedCards[].  At first I thought this was expected, as the comments describe this behavior, but searching through the code it appears there is another bug that never allows the cards in playedCards[] to be shuffled back into the pile.  They are only changed with discardCard and the tribute card.

The scoreFor() function doesn't count all the cards in the player's deck.  It says in the comments that the code will do that, but the loop is set up to only count up to the amount in the player's discard pile.  So unless scoreFor() is called when the count of both players' decks are exactly equal to the count in their discard, it will not count the correct value.

In the scoreFor() function: when calculating the value to add for the gardens cards, it calls a function called fullDeckCount(), which sounds like it would be the correct function to add all the cards in the players deck, but it actually returns a count of a passed in card value and the value passed in is 0, or the curse card.  The effect is: for every ten curse cards the player has, they will gain one point.  It should be for every card of ANY type in the player's entire deck, the player will score one point.

The playSmithy() function trashes the smithy card when it should be put into the playedCards area.

The playAdventurer() method has multiple bugs.  First, the count of draw treasure is initialized to -1, so the player ends up drawing three treasure cards instead of two.  The function never puts the adventurer card in playedCard[], so it remains in the player's hand after being played.  

Remodel card:
When the remodel card is played, it doesn't trash the card it's supposed to, it calls discardCard() for it as well as the remodel card, leaving them both in the playedCards[] until the turn changes, when they vanish.

The error-checking for cost is faulty, there is a >indicating that if the value of the card being traded in +2 is GREATER than the value of the card to trade for, then the value -1 will be returned.  So as long as you don't try to trade for something fewer than two coins less than the cost of your card, you'll never get an error.