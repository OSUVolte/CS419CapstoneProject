smithy
- Is implemented through the smithyCard() method in dominion.c . 
BUG: When the player plays the smithy card, the player draws 30 cards from their deck.

adventurer
- Is implemented through the adventurerCard() method in dominion.c .
BUG: Player keeps drawing cards until 3 treasure cards are drawn.
BUG: If player draws a gold card, it does not count as one of the 3 treasure cards that need to be drawn.

