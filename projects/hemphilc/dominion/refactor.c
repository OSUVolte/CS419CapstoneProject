/* Corey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 2
 * April 10, 2016
 * refactor.c
 */

 // Refactored:

 // Bugs Added to Smithy
	// - drawCard() parameter changed from currentPlayer to handPos.
	// - discardCard() parameter changed from handPos to handPos - 1. 

 // Bugs Added to Adventurer
	// - If the drawn card is copper/silver/gold, drawnteasure is increased
	//   by two instead of one.
	// - In the first while loop, the else statement, temphand[z] changed to
	//   temphand[z + 1].
	// - In the first while loop, the else statement, handCount incremented
	//   instead of decremented.
	// - In the second while loop conditional statement, z - 1 >= 0 changed
	//   z - 1 > 0. 

 // Bugs Added to Village
	// - drawCard() parameter changed from currentPlayer to handPos.
	// - discardCard() parameter changed from handPos to handPos - 1.

 // Bugs Added to Feast
	// - updatedCoin() parameter changed from 5 to 10.
	// - In the else if conditional statement, changed state->coins to
	//   state->coins - 1.
	// - In else statement, gainCard() parameter changed from currentPlayer
	//   to 1.

 // Bugs Added to Remodel
	// - In first if conditional statement, + 2 changed to + 1.
	// - gainCard() parameter changed from choice1 to choice2.
	// - discardCard() parameter changed from handPos to handPos - 1.
	// - In for loop, discardCard() parameter changed from i to choice2.
