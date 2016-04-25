/* * * * * * * * * * * * * * * * * * * * * * * * * * *
* bug1.c
* Lauren Crees
* Description of bugs founds by unit tests and card tests.
* Tests were run against code in local folder i.e. code I have
* modified to have bugs.
* * * * * * * * * * * * * * * * * * * * * * * * * * * *

unittest1.c - isGameOver()
	All tests pass.

unittest2.c - fullDeckCount()
	All tests pass.

unittest3.c - scoreFor()
	All tests pass.

unittest4.c - discardCard()
	All tests pass.

cardtest1.c - smithy
	All tests pass.

cardtest2.c - adventurer
	All tests pass.

cardtest3.c - treasure_map
	Test 6 does not pass.
	When player has 2 treasure map cards, the function does not return 1.

cardtest4.c - sea_hag
	None of the tests pass.
	Top of player's deck is not the same before and after running seahagEffect.
	Other player's discard is not put on top of deck.
	Other player's top of deck is not a curse card.
*/