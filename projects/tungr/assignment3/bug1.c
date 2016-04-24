/*
	Rosa Tung
	CS362
	(10 points) Execute your unit tests and describe any bugs you find in a file named bug1.c. 
*/

Bugs Found:

	unittest1.c - initializeGame()
		No bugs found during testing, all tests passed. 
	
	unittest2.c - whoseTurn()
		No bugs found during testing, all tests passed.
		
	unittest3.c - getCost()
		No bugs found during testing, all tests passed. 
		
	unittest4.c - compare() 
		No bugs found during testing, all tests passed. 
		
	cardtest1.c - smithy
		Smithy does not return the appropriate signal, which is a known bug because I introduced it myself by not putting in a return value
		for the end of the function, so after it executes it will also execute the case right after it. 
		The deck count is not correct when smithy executes. It has one less card than it should and the discard pile is empty as well. This 
		might have something to do with the previous bug, as I introduced another bug in the case after it which was the village card effect.
	
	cardtest2.c - adventurer
		Adventurer also does not return the appropriate signal, which is a known bug because I introduced it myself by not putting in a 
		return value for the end of the case, so after it executes it will execute the case right after it. The one after it has a break not
		a return value so it will still return the wrong signal value.
		Player ends up with a hand of three more cards than they should have. This may have something to do with the previous bug. 
		Player ends up with an empty deck which is short 1 card from their hand. Discard pile is also empty as well. 
		
	cardtest3.c - great_hall
		No bugs found during testing, all tests passed.
		
	cardtest4.c - gardens
		No bugs found during testing, all tests passed. 