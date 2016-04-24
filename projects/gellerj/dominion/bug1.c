/*
 * unittest1: No bugs detected in gameOver()
 *
 * unittest2: No bugs detected in gainCard()
 *
 * unittest3: No bugs detected in whoseTurn()
 *
 * unittest4: No bugs detected in shuffle()
 *
 * cardtest1: Originally my test checked for 3 cards added to the hand, but this test was failing and reporting
 * that the hand count was only incremented by two. This was a false positive test, since a net gain of two
 * cards (-1 discard) is the expected behavior. This test was improved by actually inspecting the contents of
 * the hand in conjunction with the hand count. Due to a bug introduced in assignment 1, the smithy card is
 * improperly discarded, and not marked to be trashed after play. This test fails, e.g.:
 *
 *      Check smithy card was added to played pile...FAILED.
 *
 * cardtest2: A bug introduced in the first assignment causes Adventurer to skip over gold cards when looking
 * for treasure cards in the deck. This bug is caught by the final unit test in the suite, e.g:
 *
 *      Check that gold treasure cards are gained by adventurer...
 *      Initial hand count was 5, new hand count is 4, expected 7...FAILED.
 *
 * cardtest3: The test which checks the number of actions in the current game state fails due to a bug that was
 * introduced during the first assignment. Village is supposed to increment the number of actions by 2, but due to
 * the bug, does not increment, but rather replaces the state, e.g.:
 *
 *      Check number of actions is +2...
 *      Num actions is 2, expected 3...FAILED.
 *
 * cardtest4: No bugs detected in Great Hall card
 *
 */