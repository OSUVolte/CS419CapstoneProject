/* ---------------------------------------------------------------------
* Jon Patterson
* Assignment 4
* randomhistory.c
* Discussion of random test coverage
*----------------------------------------------------------------------*/

randomtestcard.c
	For this test I modified the existing village card test that I had
	written for the previous assignment. I elected to make some small
	additions to the code in order to better incorporate the random
	testing elements that I needed to implement for this assignment.
	I added another test struct that I used to compare against with
	the changed game struct to verify that the other player's deck and
	hands had remained unchanged from before and after calling the
	playCard() method.

	For the previous test, I got 97% code coverage. This was already
	pretty good coverage for what I had wrote. Implementing the random
	test moved this up just slightly, even with the code additions, to
	98.15%. I believe the additions I made caused a bit more of inputs 
	to be traversed and overall improved the test.

randomtestadventurer.c
	Similarly to the previous refactored card, this test also had 97% 
	code coverage in the previous assignment. With the reworks I added,
	I got to 98.65% code coverage. It was a good thing that I added some
	random elements to the deck generation - after looking at the source
	dominion code, I realized it made 3 cards estates and then the rest
	coppers, but I never tested the adventurer card in cases where some
	of the treasure cards found were NOT coppers. So I randomly 
	populated the deck with some silver and gold cards and ran the tests
	again. This turned out to continue to work as expected.

	