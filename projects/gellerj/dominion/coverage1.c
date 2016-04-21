/*
 * The total coverage of dominion.c is 35.3% of lines executed and 32.05% of branches executed.
 *
 * Among the statements and branches that were specifically tested by the unit tests and card tests,
 * coverage is much better, as expected.
 *
 * unittest1 (gameOver): This function has 100% block, statement, and branch coverage. There are 8
 * possible branches in this function, and gcov indicates that each branch was covered at least one time.
 * Some branches are taken fewer times than the alternatives, so it may be worth developing tests that
 * access these branches more often, to ensure a more robust test. All statements are covered.
 *
 * unittest2 (gainCard): This function has 100% block, statement, and branch coverage. There are 6
 * possible branches in this function, and each branch is covered at least once. Again, it may be possible
 * to develop new tests that access some of the branches that were not covered as much. This will help to
 * catch any bugs that may be not have been caught in a single run of the branch logic. There aren't any
 * statements which are not covered.
 *
 * unittest3 (whoseTurn): This function has 100% statement/block coverage. There are no branches to test
 * in this function. This function is a very simple state getter, so high coverage does not necessarily
 * indicate a good test.
 *
 * unittest4 (shuffle): This function has 100% block, statement, and branch coverage. All statements are
 * executed, and all 8 branches are covered. Branches which are covered fewer times tend to be part of
 * control logic to break out of for and while loops, so there is not much concern here.
 *
 * cardtest1 (smithy): This function has 100% block, statement, and branch coverage. All statements are
 * executed, and 2 branches are covered. The branch is part of a for loop, so there is no need to increase
 * the number of times branch 1 is taken.
 *
 * cardtest2 (adventurer): This function has 100% block, statement, and branch coverage. All statements are
 * executed, and all 10 possible branches are covered. Coverage across branches looks uniform, so no attention
 * needs to be paid to improving branch coverage.
 *
 * cardtest3 (village): This function has 100% block/statement coverage. There are no branches in this
 * function. Each statement is only called once, so we can probably improve these tests by calling this
 * function with different game states. This function is mostly composed of helper functions like gainCard
 * and discardCard, so this test may not be as useful as some others.
 *
 * cardtest4 (great hall): This function has 100% statement coverage. There are no branches in this
 * function. Like the previous test, each statement is only called once. Again, this card is composed of
 * simple helper functions.
 * 
 */


