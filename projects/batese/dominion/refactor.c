/*
Refactoring changes:
-The smithy, adventurer, council room, embargo, and village cards have been refactored from the switch statement into their own functions, which can be found at the end of 
 dominion.c. The functions are called in place of the original code in the switch statement. The original code has been copied into the functions.
-In the adventurerCard function, a bug has been introducted. "|| cardDrawn == gold" has been removed so that no gold cards will be added to the players hand if they are drawn.
-In the smithyCard function, a bug has been introduced. "i < 3" has been changed to "i > 3" so that now the for loop won't execute.
-In the villageCard function, a bug has been introduced. "numActions + 2" has been changed to "numActions + 1" so that the player only gets one additional action.
-In the council_roomCard function, a bug has been introduced. In the for loop where each other player draws a card, "i = 0" has been changed to "i = 1" so that if the player is
 in position 0 then they will not draw a card.
-In the embargoCard function, a bug has been introduced. A 0 is passed to the discardCard function instead of a 1, so that the card is not trashed.                                                                                                                       

*/