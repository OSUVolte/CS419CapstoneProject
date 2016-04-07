//Name: Shawn Seibert
//Date: April 6, 2016
//File: Refactor.c
//Purpose: This is to explain the changes made to the dominion cards

Smithy card: Modified the for loop so that instead of incrementing 3 times it increments 4 times.
			 It may not be obvious be of the added "=" sign to the for loop.
			 
Adventurer card: Starting: When the player draws a card, the top card is no longer drawn because the -1 was removed
				 from the state->handCount[currentPlayer]. The -1 was then placed outside of all the brackets so the 
				 cardDrawn value is now minus one affecting when the while loop should end.