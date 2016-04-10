/*

Miranda Weldon
April 10, 2016
CS 362
Assignment #2
refactor.c

I refactored the following cards: Smithy, Adventurer, Remodel, Council Room, and Ambassador. There are delibarate bugs in the 
implemenations of each, described below.

Smithy:
	In the smithyCard function, drawCard is given the parameters i and state instead of currentPlayer and state. This will
	give a single card to three different player instead of giving three cards to the current player (the one who played 
	the Smithy card).

Adventurer:
	Inside the else statement of adventurerCard(), z is never incremented, resulting in the program being unable to keep 
	track of how many non-treasure cards were drawn before the two tresure cards wer added to the player's hand. 

Remodel:
	The remodelCard function is unchanged, but the case block containing the function call is missing a return statement.

Council Room:
	The second for loop in councilRoomCard has been changed to a while loop. The second conditional (i != currentPlayer)
	is checked in the wrong place, resulting in only the players added before the current player being able to draw a
	card.

Ambassador:
	In ambassadorCard(), the variables choice1 and choice2 are switched in every appearance. 

*/
