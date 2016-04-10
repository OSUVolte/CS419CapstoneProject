/*

Name: Eugene Pak
Course: CS362 Spring 2016
Assignment 2 - refactor.c

Adventurer Card:
	pAdventurer() function to play the Adventurer card.
	pAdventurer() takes three arguments:
		integer handPos for hand position
		integer currentPlayer for current player
		struct gameState *state
	Bug: Changed while loop for counting treasure cards from 2 to 1.

Smithy Card:
	pSmithy() function to play the Smithy card.
	pSmithy() takes three arguments:
		integer handPos for hand position
		integer currentPlayer for current player
		struct gameState *state
	Bug: Changed for loop to draw 2 cards (less than instead of less than or equal).
*/