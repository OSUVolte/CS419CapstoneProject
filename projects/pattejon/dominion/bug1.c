/* ---------------------------------------------------------------------
* Jon Patterson
* Assignment 3
* bug1.c
* Discussion of bugs found
*----------------------------------------------------------------------*/

unittest1.c - updateCoins() method
	This method didn't appear to have any bugs that my test cases found.
	I know that it wasn't necessary, but I wrote some random tests to try
	creating some random hands of treasure cards to ensure that the
	correct values were calculated every time, and it seemed to do that
	well for both players on 100 different random hands for hands
	in the interval of (1, MAX_HAND)

unittest2.c - buyCard() method
	This method found some bugs. The drawCard() method functions properly
	until the deck runs out of cards. If we try to shuffle an empty
	discard pile into our empty deck, we get a segmentation fault. This,
	in practice, is not going to be a very likely scenario, but it is one
	that should be handled by the code logic.

unittest3.c - discardCard() method
	This method has a curious implementation that works in the game but
	should probably be made safer. For instance, because it uses a fixed
	int array indicating what cards are in the hand, but using another
	int to shorten the array and swap the last element of the array with
	whatever gets played, once the array is down to the last card it just
	swaps it with itself, but the function doesn't test to see if we can't
	just provide position 0 again.

unittest4.c - isGameOver() method
	This method is pretty straightforward and quite easy to write a random
	test for. As I was writing it I realized there's some interesting
	design decisions going into this. The state->supplyCount array has 
	every card available, which is probably fine, but position 3 in that
	array is the "province" position. So, in my test, I excluded that
	position from being assigned randomly. Otherwise this method does a 
	good job of identifying when the game is indeed over.

cardtest1.c - playCard() for smithy
	Initially I tried to implement this at the cardEffect() level but I ran
	into some concerns with that, so I re-implemented this at the playCard()
	level. This seemed to fix one of the small bugs that I encountered that
	was probably just due to how the game was implemented. However, I ran
	into some bugs with drawing the incorrect number of cards, which is due
	to a bug that I introduced in an earlier assignment.

cardtest2.c playCard() for adventurer
	I added a bug to this in the previous assignment, but this code already 
	had a significant problem before I messed with it. As the code is written
	now, there is a scenario where the card will not be able to find the 
	required number of treasure cards in the deck and loop forever. It likely
	will not happen in most cases, but it could occur.
