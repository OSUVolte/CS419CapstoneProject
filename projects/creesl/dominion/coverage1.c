/* * * * * * * * * * * * * * * * * * * * * * * * * * *
* coverage1.c
* Lauren Crees
* Discussion of coverage of tests.
* * * * * * * * * * * * * * * * * * * * * * * * * * * *

File 'dominion.c'
Lines executed:33.04% of 563
Branches executed:38.37% of 417
Taken at least once:33.81% of 417
Calls executed:17.89% of 95

Overall Coverage:
	The overall coverage is okay. The tests are covering about a third of the dominion code, so there is definitely room to expand coverage. While 100% coverage wouldn't be a guarantee of fully functioning code, more coverage would be appropriate. A significant portion not covered is likey due to the fact that cardEffect was never called. The card tests called the refactored cards and did not go through cardEffect.

Coverage by Test:

unittest1.c - isGameOver()
	function isGameOver called 3 returned 100% blocks executed 100%

unittest2.c - fullDeckCount()
	function fullDeckCount called 11 returned 100% blocks executed 100%

unittest3.c - scoreFor()
	function scoreFor called 5 returned 100% blocks executed 100%

unittest4.c - discardCard()
	function discardCard called 7 returned 100% blocks executed 89%

cardtest1.c - smithy
	function smithyEffect called 1 returned 100% blocks executed 100%

cardtest2.c - adventurer
	function adventurerEffect called 1 returned 100% blocks executed 64%

cardtest3.c - treasure_map
	function treasuremapEffect called 2 returned 100% blocks executed 100%

cardtest4.c - sea_hag
	function seahagEffect called 2 returned 100% blocks executed 100%


	Most of the tests covered 100% of their targets. While some of the tests failed, it is encouraging in that it raises confidence that these tests would find bugs.  Both adventurer and discardCard() had incomplete test coverage.  DiscardCard's coverage was high but adventurer was relatively low compared to the others.

Improvement:
	In terms of tests already written, discardCard and especially adventurer need some more attention to get better coverage. The rest of the tests would probably also benefit from becoming more robust by testing more gameState configurations or card configurations where appropriate.  Some edge cases could also use a closer look. Otherwise, more tests would likely help with the overall code coverage.

*/