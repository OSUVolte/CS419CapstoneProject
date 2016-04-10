//Process of Refactoring
/*
	I started by looking over the dominion header and C file. I made a seperate function for adventurer
	but named it "Adventurer". This didn't work as expected. Upon closer examination of the header file
	I noticed the playAdventurer() prototype function. Afterwards I added that to the main source file as 
	my function seperate from the switch statement. Then it was just a matter of looking up how to pass 
	structs and arrays to functions before they all worked.
	
	The errors that I created are  playAdventurer() while(z-2>=0) and discardCard(handPos, currentPlayer, state, 1) should start at 0 not 1 in the playSmithy function.
*/