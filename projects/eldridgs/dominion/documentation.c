Susan Eldridge
eldridgs
CS 362
Spring 2016

Smithy:
This allows the current player to draw three cards, adding to the total number of cards in their hand.
Then, the Smithy card is discarded as it can only be used once.

Adventurer:
While drawntreasure is less than two, this reshuffles if the deck is empty, then draws a card.  If the
card that is drawn is a copper, silver, or gold (treasure), then drawntreasure is increased by 1.
Since drawntreasure starts with a value of 0, this makes the cards continue to be drawn until a total of
3 treasure cards are found.
If the drawn card is not a treasure card, cards are continued to be drawn.  The else statement keeps
track of the cards drawn.  Once drawntreasure is equal to 2, the second while statement
puts the "stack" of non-treasure cards that were drawn into the discard pile.

DiscardCard():
This function is given the hand position of the card to be discarded, the information about who's turn
it is, the state of the game, and the trash flag.
If the trash flag is 0, the card is not trashed.  This means that the card in the current player's
hand position is played. The card is set to a state of -1 meaning it has been used.
If this card happens to be in the last position of the player's hand array, then the array is just
reduced in size by one, thereby eliminating the played card.  If this was the last card in the
player's hand, then the hand count becomes size zero.  Otherwise, the played card is swapped places
with the card at the end of the array, so that the array can be reduced in size.
The main purpose is to cause the number of cards in the player's hand to decrease by one.

UpdateCoins():
This function is given the information for the player who's turn it is, the state of the game, and
any bonus.  Coin count starts at 0.
The number of coins is tallied from the treasure cards by adding up copper coins for +1, silver coins
for +2, and gold coins for +3.  Then the bonus (from other cards in the hand) is added to the total
number of coins found from the treasuer cards, giving the total number of coins available for the
"buy" phase of the turn.
