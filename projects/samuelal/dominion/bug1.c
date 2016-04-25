Alex Samuel
Assignment 3

unittest1.c - Testing getCost() function
-No bugs found

unittest2.c - Testing fullDeckCount() function
-No bugs found

unittest3.c - Testing isGameOver() function
-No bugs found

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

cardtest3.c - Testing village card

cardtest4.c - Testing great hall card
