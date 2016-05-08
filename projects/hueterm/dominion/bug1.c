/******************************************************************************
Michael Hueter
CS 362 Assignment 3
bug1.c - documenting all the bugs found by unit testing

I found no bugs in the four unit tests against getCost(), isGameOver(),
numHandCards(), and gainCard().

I did find bugs in each of the refactored cards, however:

(1) Adventurer is totally broken. It no longer adds any cards to a user's hand,
nor does it draw from the deck or shuffle in discarded cards. I confirmed this
was due to the bug I Introduced (not initializing drawntreasure to zero),
because when I undo my bug and run the tests it works as intended with no bugs.

(2) Smithy has also been totally broken. The player no longer gains any cards
because of the corrupted for loop bug I introduced last assignment. The card
basically has no affect. Also, one "bug" I tried to introduce before was modifying
the trash flag to 1, but it did not seem to have any effect on my tests. I am
not quite sure how discardCard works because it does not affect the discard pile
as one would expect. It needs further investigation.

(3) Village has 1 simple bug which was introduced and works as expected. The
player gets an extra action due to the for loop going to 3 instead of 2.

(4) Minion is mostly working except for 1 small bug. This is the bug I introduced
in refactor.c. It didn't work exactly like I thought. Previously I thought it
would make everyone discard all of their cards and not be able to draw any.
But the observed functionality is letting player 1 draw but not player 2.


******************************************************************************/
