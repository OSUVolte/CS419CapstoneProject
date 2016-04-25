Alex Samuel
Assignment 3
big1.c

unittest1.c - Testing getCost() function
-No bugs found

unittest2.c - Testing fullDeckCount() function
-No bugs found

unittest3.c - Testing isGameOver() function
BUG: Function only iterates between curse and salvager cards and fails to check if sea_hag and treasure_map piles are empty.

unittest4.c - Testing scoreFor() function
BUG: scoreFor does not calculate the total scores for each player correctly. scoreFor()
tends to undercalculate the true score. One error in the function occurs when the function is trying
to calculate the total score from the cards in the deck. In this portion of the code, the function iterates 
between 0 and discardCount pile rather than deckCount (state->discardCount[player] should be state->deckCount[player]). 
This could lead to errors if deckCount is larger than discardCount as some cards will not be counter.
	Another error in this function occurs when it calculates the scores from gardens cards present in the player's
entire deck. scoreFor() calls the fullDeckCount() function but passes in the card number of curses and not any other 
card. As a result, the fullDeckCount function will only return the total number of curses cards in the player's possession 
rather than the total number of all cards in the player's poessession. As a result, gardens cards do not grant as many points 
to players as they should.

cardtest1.c - Testing smithy card
BUG: One bug that was found was the one that was introduced in assignment 2. Smithy, when working correctly, should grant the 
player 3 cards from the deck. The bug in this card function allows the player to draw 4 cards from the deck.

cardtest2.c - Testing adventurer card
BUG: One bug that is present in this card was introduced in assignment 2. The bug is that the player will keep drawing cards until 
3 treasure cards are drawn rather than 2. Another bug that was indicated from my tests was that a non-treasure card can be 
drawn by the player and enter the player's hand rather than only treasure cards. Finally, my tests also indicate that playing 
the adventurer card can affect the deck and hand of the other player. The total number of estate cards in player 2's deck and 
hand appeared to change after player 1 played the adventurer card.

cardtest3.c - Testing village card
-No bugs found

cardtest4.c - Testing great hall card
BUG: One bug present in great hall is that the player will draw 2 cards instead of just 1. In addition, the great hall card 
will not be discarded from the player's hand as it should be when it is played. This happens because the drawCard() function 
is called twice when this card is played and the discardCard() function is not called. In addition,,another bug that may be 
present is that the number of actions is incremented by 2 rather than just 1. But this may be occur because the number of 
actions is not decremented when only cardEffect() is called. The decrement action takes place in playCard() which executes 
at an earlier time during the player's turn before cardEffect() is executed. 
