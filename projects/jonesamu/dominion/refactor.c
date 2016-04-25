Assignment 2

smithy:
- implemented through the smithyCard() method 
BUG: When the player plays the smithy card, the player draws 2 cards from their deck rather than 3.

adventurer:
 implemented through the adventurerCard() method
BUG: Player keeps drawing cards until 4 treasure cards are drawn rather than 2.
BUG: If player draws a gold card, it will not count as one of the 4 treasure cards that need to be drawn.

great_hall:
implemented through the greathallCard() method 
BUG: discardCard method swapped with drawCard method. 

embargo:
implemented through the embargoCard() method 
BUG: Card is not trashed as it should be, merely discarded.
BUG: Card increases player's number of actions by 2 rather than number of coins.

minion:
implemented through the minionCard() method
BUG: Both for loops were modified to use an equal sign Now players draw an addional card 
