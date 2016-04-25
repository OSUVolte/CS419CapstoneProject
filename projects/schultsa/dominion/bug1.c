/*
Bug1.c

My unit tests used assert statements which at first I thought would make everything simpler. However when it came down to things failing assertions it would crash compilation and stop the log.
In order to have the unittestresults.out file execute correctly I had to comment out all failing assertions.

Bugs I found:
assertions that failed in unittest1.c
//assert(compState->coins == testState1->coins);
This means that the coins are not the same between the states even though no new coin has been added.

//assert(compState->coins+2 == testState2->coins);
We set the bonus to +2 so the state should have 2 more coins than compstate, but this is failing.

//assert(compState->coins-3 == testState3->coins);
I put in a negative value for bonus and the expected value did not line up with the actual value leading to failure.

assertions that failed in unittest2.c:
None
gainCard is functioning normal.

No assertion failures in unittest3.c

No assertion failures in unittest4.c

assertion failures for cardtest1.c:
//assert(testState->discardCount[testState->whoseTurn]+1 == state->discardCount[state->whoseTurn]);
the states have diferent number of cards discarded which should not happen. leading to assertion failure.

assertion failures for cardtest2.c
//assert(state->discardCount[state->whoseTurn] > 1);
at least 1 card should have been discarded when using adventurer, this failing is saying that cards are not being discarded correctly.
//assert(state->coins > testState->coins);
This tests to make sure that the state has more coins than it did before using adventurer. This failure means there is a bug in how coins are handled in adventurer.

assertion failures for cardtest3.c:
//assert(state->discardCount[state->whoseTurn] == testState->discardCount[testState->whoseTurn]+2);
tests to make sure 2 cards were discarded after using remodel. This failure means the cards are not being sent to the discard pile correctly.

assertion failures for cardtest4.c:
//assert(state->discardCount[state->whoseTurn] == testState->discardCount[testState->whoseTurn]+1);
tests that only 1 card was discarded. Bug in discard management.










*/