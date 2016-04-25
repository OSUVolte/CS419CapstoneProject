David Hite
bug1.c

In unittest1 I found that in kingdomCards() there is no checking if the cards in the arguments are valid.

In unittest2 I found what appears to be a bug, but perhaps is the intended behavior of the function. The
resulting gameState after initializeGame() results in player 1 having fewer than 7 copper. I also found
that there is no checking in the initializeGame() function for whether the cards in the kingdomCard 
array are valid.

No bugs found in shuffle() with unittest3.

No bugs found in fullDeckCount() with unittest4, though there is no checking for a valid card range.

No bugs found with cardtest1. The bug I introduced in the previous assignment was not tested for because
I ran out of time.

The bug I introduced to playAdventurer() was found in cardtest2, but not narrowed down.

With cardTest3, the bug I introduced in the previous assignment was found.