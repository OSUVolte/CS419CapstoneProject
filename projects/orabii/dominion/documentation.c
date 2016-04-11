The smithy card allows the player to draw 3 cards and then place the card in the discard pile.

The adventurer card allows the player to draw cards until 2 treasure cards picked. Once the 2 treasure cards are drawn,
all the other cards drawn will be discarded.

The discardCard() method decides the actions to be performed to discard a card based on the state of the game.
When the card is not trashed it is added to the played pile. If the last card in the hand is played or the player
only has one card in their hand, the cards are reduced by one. Otherwise, the discarded card is replaced by the last
card in the player's hand and the card count decreases by one.

The updateCoins() method resets the coin count for the player and adds coins to the coin count for each corresponding treasure card
in the player's hand. A bonus can also be added at this time.
