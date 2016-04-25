/*Analysis of Gcov outputs. John Brown

Using the statement coverage method, confirmed number of lines
executed:29.77% of 571.  This really is to be expected  as at this point my
testing suite is incomplete and only include testing for 8 functions.
Zeroing in on the 8 functions  I actually intended to test, gives a clearer
picture of how to improve the testing I already have.


updatecoins did have complete statement/branch coverage.  This function is
used by other functions so it had some fairly good  cross checking.  As
with all of the other cases, my unit tests are mainly edge cases and
further depth of testing would be  needed under actual game condition
during integration testing or possibly with some random testing.

For the isGameOver, failed to check statement where game is over due to 3
or more empty supply piles.  Need to Rework test for this.

Achived statemet/branch coverage for fullDeckCount.  This function is used
fairly regularly due to being called by other functions.   To improve the
unit test would like to include more cases with bad inputs and/or unusual
game states.

Much like update coins, gaincard has complete statement/branch coverage and
is a widly used function.  It too can benefit from  addition depth of test
cases to verify correctness.

The playSmithy function does not have complete statement or branch
coverage.  The one condition that has been tested yet is  the condition
where there are no more cards in the draw pile and pile needs to be
shuffled.  This might better be explored  under stress/random testing where
many many test cases were generated.

Similarly to the playSmithy function, we need to add coverag for the
shuffling condition.

The playCouncil_Room had good statement and branch coverage.  All statement
executed and no real branches in the function.  One additional item i need
to test for playCouncil_Room is whether the other player's drawing a card
is working correctly.

Achived statement/branch coverage for playVillage.  Need a greater number/
depth of test cases, various bad inputs and combinations  of game states.*/
