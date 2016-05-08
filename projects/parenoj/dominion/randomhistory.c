/*
	Justin Pareno - Assignment 4 Write-up
	
	Firstly, the most difficult part of this assignment was the refining process in order to figure out all of
	the preconditions to make the functions operate in a "sane" gameState. This was certainly an iterative process
	that took a lot of work to stop the segfaults. But throughout the process of debugging to "find" a way to make
	a "sane" gameState, I found some interesting things out about drawCard and how it works with the adventurer Card.
	
	If a deck is empty, and the discard pile is empty, the adventurer card will still call the drawCard function, which
	as the lecture illustrated, does nothing if the deck AND discard piles are empty. This ends up with cardDrawn being
	assigned an uninitialized value which messes everything up. SegFault. 
	
	In terms of trying to improve coverage, I found that the adventurerCard and the great_hallCard (the other one I chose
	to test), were mostly straightforward in terms of their operation. I ran my tests enough times with different seed values
	and I was able to easily achieve 100% code coverage, granted some of the paths were very rare due to their nature. 

	I had some challenges checking the correctness of my specification, though. Especially with the great_hallCard. In my 2000 or so
	iterations, there were always a few that returned an unexpected result, but not one that I was initially able to understand. I
	dug in with gdb and followed the code looking at variables during execution and realized the behavior was caused because the deck
	was empty, so the discard pile was then shuffled into the deck (Which I wasn't accounting for in my oracle). But once I found
	this behavior, I was able to account for it in my oracle. 
	
	My oracles consist of the most important checks from my unit tests for these cards. They basically, verify that the changes that should
	have been made to card counts have been made. I also left in the assert functoins to be sure that the return values are correct. 
	
	Again, I want to revist the process of figuring out how to make a "sane" gameState for these random tests to iterate through. I used
	a lot of gdb which I had tried to avoid and found it very useful and helpful. I also used trace statements, but less than I have in the
	past because of gdb. I could see a lot of my variables were remaining uninitialized when I thought they were initialized. This allowed
	my to fine-tune the "set-up" I did to the gameState before running each random test. 

	In order to get my random test for the adventurer card to not segFault, I had to "fix" the bug I introduced in an earlier assignment, 
	where state->deckCount[currentPlayer] is assigned a value of 0, not compared to < 1. Almost all of the tests for the adventurerCard 
	failed because of the bug where there is no call to discardCard at the end of the card's function.
	
	Great_hall on the other hand, did not have any bugs introduced into it, and no other bugs were found.


*/