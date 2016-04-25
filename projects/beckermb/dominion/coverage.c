/*
Ben Beckerman
Assignment 3
4/24/16


Overall Coverage:
* Line coverage came in at 31%, and much of that was only due to calling the long initialize game method in the unit tests. To expand line coverage, the obvious next step is to create unit tests for the rest of the methods in the game. The test sweet only covers 8 of them, which is a small amount. Branch coverage was 28%. To expand this type of coverage, in addition to the method specific unit tests, I would start creating some integration tests. No where in the testing sweet was the actual playing of a game simulated, which I belive would greatly enhance the branch coverage.

unittest1.c / isGameOver
* This method had 100% statement and branch coverage.
* Given the high coverage percentage, I believe the best way to improve testing for this method would be conduct random testing. The logic was tested with most game states, but some combinations might produce unexpected results.

unittest2.c / updateCoins
* This function had 100% branch and statement coverage.
* This function has good coverage of its logic, but again might benefit from random coverage. There might be some boundary conditions for counting the cards that could be uncovered by testing many combinations of possible hands.

unittest3.c / fullDeckCount
* Statement coverage for this method was 100%, as was branch coverage.
* Although statment and branch coverage was 100%, this function looks to be particularly suspceptible to boundary conditions. Testing was adequate, but could be improved by explicitly testing for the presence of a card in the first and last positions of the hand, discard pile, and deck.

unittest 4.c / numHandCards
* Thie method had 100% statment coverage, and it has no branches so branch coverage is not applicable.
* Given the relative simpliciy of this method, and the coverage percentage, I believe it would be best to focus any additional development on the test suite elsewhere.

cardtest1.c / smithy
* This method had 100% branch and statement coverage.
* This method is relatively short and was well covered. Given the relative lack of inputs, it's not a particularly good candidate for random testing.

cardtest2.c / outpost
* This method had 100% branch coverage.
* Although the logic that occurs within the card was well tested, most of the actual 'effect' of the card takes place during end of turn clean up. That effect was not tested as it was not part of this method, but it would be an essential part of adequately testing this card, just not the play card method for it.

cardtest3.c / village
* This method had 100% statement coverage, and it doesn't contain any branches.
* This is a very simple method, and I believe it's well tested in the existing test suite.

cardtest4.c / adventurer
* This method had 100% statement and branch coverage.
* Despite the high coverage percentage, the bug I introduced in assignment 2, where the method would crash if more than 7 cards had to be turned over was not triggered, because the composition of the deck was never right for it.
* This omission shows the weakness of relying on statement coverage, and the value of random testing. If I had used random testing to seed the deck thousands of time, that condition would almost certainly have come up and the bug exposed.
*/
