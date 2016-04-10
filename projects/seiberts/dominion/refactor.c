//Name: Shawn Seibert
//Date: April 6, 2016
//File: Refactor.c
//Purpose: This is to explain the changes made to the dominion cards

Smithy card: Modified the for loop so that instead of incrementing 3 times it increments 4 times.
			 It may not be obvious be of the added "=" sign to the for loop.
			 
Adventurer card: Starting: When the player draws a card, the top card is no longer drawn because the -1 was removed
				 from the state->handCount[currentPlayer]. The -1 was then placed outside of all the brackets so the 
				 cardDrawn value is now minus one affecting when the while loop should end.
				 
Great_hall card: This card is supposed to increase the action allowed by 1, however a bug was inserted which 
				  allows for 2 actions to be played by the player.
				  
council_room card: This card is designed to draw 4 cards and increase the number of buys by one. However, within the 
					for loop, an equal sign was added which will now cause 5 cards to be drawn. Additionally, instead
					of the number of buys increasing by one, the player will recieve an action point instead .
					
minion card:	This card has the options of having each player discard their hand and redraw 4 cards. However, both 
				for loops were modified to include an equal sign that actually causes each player to draw 5 cards. Additionally,
				instead of an action increasing by one, the number of buys is implemented to increase by one.