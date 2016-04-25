Assignment 2

smithy
- Is implemented through the smithyCard() method in dominion.c . 
BUG: When the player plays the smithy card, the player draws 4 cards from their deck rather than 3.

adventurer
- Is implemented through the adventurerCard() method in dominion.c .
BUG: Player keeps drawing cards until 3 treasure cards are drawn rather than 2.

great_hall
- Is implemented through the greathallCard() method in dominion.c .
BUG: discardCard method replaced with drawCard method. This results in the player drawing 2 cards and does 
not discard great hall card from hand.

embargo
-Is implemented through the embargoCard() method in dominion.c .
BUG: Card is not trashed as it should be, merely discarded.
BUG: Card increases player's number of actions by 2 rather than number of coins.

sea_hag
-Is implemented through the seahagCard() method in dominion.c .