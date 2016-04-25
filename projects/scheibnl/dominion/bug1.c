/*

Please note: I've commented out failing asserts so that the programs can still run through completely.

cardtest1-
Testing: smithy

I introduced a bug into smithy that would make it draw four cards instead of three.
I was able to catch this bug with my first two tests, which showed that four new cards were added
to the hand instead of three and that four cards were removed from the player's deck.

This card passed all of my other tests.

cardtest2-
Testing: adventurer

I caught a couple of bugs in adventurer. First, adventurer does not discard itself
before allowing the game to move on. I caught this when I saw that I had one more card on hand than expected.

Then, there is something wrong that is causing too many cards to be discarded. However, none of the discarded cards
are treasure cards, which is strange (or at least I would find it strange if I hadn't introduced this bug myself...
which is a mistake in the conditions of a while loop).

cardtest3-
Testing: cutpurse

I found my own bug here. I changed it so that the bad effects of cutpurse (the removal of a copper from the hand)
applied to the current player instead of the others players. I found this when I checked to make sure the current 
player's number of cards in hand and in deck didn't change (they did).

cardtest4-
Testing: sea_hag

I personally didn't introduce any bugs into sea_hag, but I found a lot of problems with my tests.

Like adventurer, sea_hag doesn't discard itself, so there are too many cards on hand.

The players deck also shrinks by three cards, even though it shouldn't.

Also, the other players don't gain a curse card in their deck like they should.

Finally, the supply count of curse cards doesn't shrink.

The largest problem in the code for this card is that the function uses a variable-- in order to try to access
something stored at that variable - 1. But using -- with a variable decrements the variable by one. It does this
several times in the code, causing all sorts of problems, as one can see.

Other things, like decrementing the curse card supply count, I just think the programmers didn't consider or remember.

unittest1- 
Testing: discardCard

All of my tests passed/ I found no bugs.

unittest2-
Testing: updateCoins

All of my tests passed/ I found no bugs.

unittest3-
Testing: gainCard

All of my tests passed/ I found no bugs.

unittest4-
Testing: isGameOver

All of my tests passed/ I found no bugs.

*/