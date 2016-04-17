/*Lucile Behmer
Assignment 2
CS 362

Smith Card: The ending curly bracket for the for loop is misplaced that not only do you draw three cards 
but after each draw the discardCard funtion is called as well. This negate all of the benefits of 
the smithy card. 


Adventurer Card: The bug that I introduced in this function was that this loops through 
until you get to 4 treasures instead of 2. This makes this card way too powerful and lets
the player really get beyond the intended benefits. 


Great Hall: The number of actions is actually decreased by one istead of increased by one. 
This makes this card less valuable and the player is not getting what they paid for with this
card anymore.

Minion Card: If the player chooses the second option and the other players have 2 or more cards 
then they are impacted! It used to be if they had more than 4 cards. Now they will have to discard
their hand and draw four more cards. 

Remodel Card: The bug for this one will be discarding the wrong card at the end of the function. 
It will now discard the first card that is not equal to the one that the player selected to get rid of. 
It is in the if statement in the for loop at the very end of the function. 



