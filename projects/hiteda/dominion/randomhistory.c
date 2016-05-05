randomhistory.c
David Hite

==== randomtestadventurer.c ====
I found that my random test for playAdventurer had 100% coverage right away,
which was good. At first I was including invalid inputs for every input,
including state->whoseTurn. I ended up needing to restrict that to a valid
range because drawCard(), which is called from playAdventurer(), was not 
checking for valid inputs and ended up causing segmentation faults because it
was trying to access an array outside of its valid range.

I also found with my random test that there is no checking if any of the cards
in the hand, deck, or discard pile are invalid cards.

I originally ran this test 100 times, and I got 95.45% coverage on drawCard().
When I upped the number of iterations to 1000, I got 100% coverage of drawCard().


==== randomtestcard.c ====
I started my random test for playVillage() with 1000 iterations. While it had
100% coverage on playVillage(), there was only 36.36% coverage on drawCard(),
and 84.62% coverage of discardCard().

Increasing the number of iterations to 10,000 did not improve the coverage on
drawCard() or on discardCard(). Neither did increasing it to 30,000.

I found again a lack of validation of input cards in playVillage().

My random test for playVillage() also found the bug that I introduced in the 
first assignment. The number of actions should be incremented by two, but it
is only incremented once.