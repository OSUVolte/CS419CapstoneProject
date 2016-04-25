/*
Ryan Peters
04/20/16

General Info
	I tests for invalid inputs that are used to access an array by providing
	a number that is larger than number of indices or a negative number.  
	These test pass because I add information to the memory location right
	before using it.  I made the test expecting them to FAIL for using inputs
	that are out of bounds.
	
buyCard()
	There is no bound checking for whose turn it is.  The function executed
	without a problem when state.whoseTurn was an invalid number [negative and
	more than max players].  When using invalid input for state.whoseTurn 
	the test PASSED when I expect it to FAIL.  
	
	The function failed to add the card to the player's hand or deck.
	
	There is no bound checking for the supplyPos of card to buy.  An invalid
	card can be passed to getCost([card]).  If an invalid card is passed the
	getCost() the player gains a coin.
	
isGameOver()
	If there is a miscalculation in the number of cards in the supple stacks
	and a stack or stacks ended up with a negative number it will not be viewed
	as empty.  Game over was not triggered when all stacks had negative values.
	The loop for checking the count for each supply card does not check every
	card.  When salvager, sea_hag, and treasure_map have 0 cards isGameOver() 
	does not return 1, indicating the game is over.
	
updateCoins()
	There is no input validation for updateCoins().  When passed a bonus that
	is negative, the bonus is taken away from the total coins.
	
gainCard()
	There is no input validation for gainCard().  The function can take any number
	for the player or supplyPos and execute with out a problem.  Since supplyPos
	is used to access an array, if it is out of bounds there is no telling what
	data will be return.  The test passed because added information to the memory
	location right before using it.
	
	
Smithy Card
	The smithy card failed when drawing three cards and discarding one.  There 
	should have been a net gain of two cards.  The function to play the smithy
	card does not return 0 when it executes successfully.  The smithy card was
	added to the played stack.  These bugs are the ones I introduced into the
	smithy card effect.
	
Adventure Card
	The adventurer effect does not add two treaure cards to the player's hand.
	The adventurer does not add any cards to the player's hand.
	
Village Card	
	My test did not find any bugs when playing the village card.  There is no 
	input validation and C does not have bound checking for arrays.  I did not
	test for these conditions because the previous tests showed that when unsing
	out of bound input the functions operate with out a problem.  The data will
	probably be lost or overwrite other data since it is not stored in the 
	memory allocated for each array.
	
Council_room Card
	The council_room card passed all the tests.  There should not be a problem 
	with input validation because it uses only hard coded data and data from the
	game state.  As long as the game state is not corrupted it should execute
	without a problem.
*/