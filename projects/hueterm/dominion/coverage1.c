/******************************************************************************

Michael Hueter
CS 362 Assignment 3
coverage1.c - Analyzing gcov info from all 8 tests

- Overall Coverage from all tests
Looking at the coverage of dominion.c for all 8 tests combined, we can see that
38.73% of 568 lines were executed; 34.84% of 419 branches were executed (30.31%
of 419 were taken at least once); and 25.00% of 100 calls were executed.

This is pretty good coverage for only 8 tests. The reason this is this high is
likely because of the tests which make calls to initializeGame() and the testing
of isGameOver() which account for over 17% of all line coverage. These functions
are quite extensive because they "touch" a lot of other functions and paths.

Obviously, the way to improve coverage would be to write more unit tests. My
test suite should in theory have a unit test for every function. However, getting
maximal coverage is not always desirable. A simple integration test or two could
easily get 100% line or even branch coverage, but it wouldn't necessarily show
edge cases and obsure game states.

- Individual unit test analysis

(1) unittest1.c - testing the getCost function
function getCost called 27 returned 100% blocks executed 97%. This is basically
optimal coverage. I wasn't able to execute only 1 line, which is return -1. What
I should do is pass it a bad input to get that covered, which I could easily amend
in my unittest1.c.

(2) unittest2.c - testing the isGameOver function
function isGameOver called 7 returned 100% blocks executed 100%. I got 100%
here because I was able to isolate all branches because there were really only
2 scenarios to end the game, and both were included in the unittest2.c.

(3) unittest3.c - testing the numHandCards function
function numHandCards called 10 returned 100% blocks executed 100%. This was a
relatively simple function to cover because it only has 1 statement in it. My
unit tests were a little bit more integration-test-like in response to this.

(4) unittest4.c - testing the gainCard() function
function gainCard called 9 returned 100% blocks executed 100%. I was able to
achieve 100% block coverage and got most of the branches covered because I made
sure to pass in each of the toFlag statuses (0, 1, and 2). I don't think it
could be further optimized exept with redundancy.

(5) cardtest1.c - testing the adventurer card
function playAdventurerCard called 3 returned 100% blocks executed 44%. My unit
tests were only able to get 44% block coverage here with 10 branches never
executed. This is actually due to the faulty logic I introduced as part of the
refactor.c bugs. I changed the value of drawntreasure, so the while loop
dependant on that will not get called. However, in the original version of
dominion.c this test would have closer to 100% coverage.

(6) cardtest2.c - testing the smithy card
function playSmithyCard called 3 returned 100% blocks executed 75%. Similar to
the above, I introduced a bug in refactor.c for assignment 2 which made it so
the test will not achieve full coverage because the logic in the for loop is
faulty. It is good that my tests were able to identify these faults, however!

(7) cardtest3.c - testing the village card
function playVillageCard called 1 returned 100% blocks executed 100%. Unlike
the above two, my bug with the village card did not affect the coverage. I was
able to get 100% block and branch execution, which is optimal.

(8) cardtest4.c - testing the minion card
function playMinionCard called 2 returned 100% blocks executed 100%. Just like
village, the minion card was able to get 100% block and branch coverage, which
is ideal.

******************************************************************************/
