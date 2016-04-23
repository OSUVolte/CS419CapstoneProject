/* Martha Gebremariam
CS362_Spring2016_Assignment2
Description: code in dominion.c was refactored so that 5 of the cards are implemented in their own functions, rather than as part of the switch statement in cardEffect. Furthermore, 4 of the 5 cards were made to be incorrect in some way, i.e., subtle bugs were included during the change that can be hard to catch.  This file documents the changes made to dominion.c and contains information about introduced bugs.


Smithy: made into a standalone function. 
	Bug Introduced: Made for loop iterate from i=0 to i<= 3 instead of from i=0 to i<3. This will make it draw 4 cards instead of 3.

adventurer: made into a standalone function.
	Bug Introduced: removed incrementation of z in else statement (removed z++)

council_room: made into a standalone function.
	Bug Introduced: in for loop, made current player draw card instead of the others (replaced if ( i != currentPlayer ) with if ( i == currentPlayer ))
	
village: made into a standalone function. No bugs were included.

great_hall: made into a standalone function.
	Bugs Introduced: Removed incrementation of numAction (removed state->numActions++) 

*/


