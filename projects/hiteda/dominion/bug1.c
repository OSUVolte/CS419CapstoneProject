David Hite
bug1.c

In unittest1 I found that in kingdomCards() there is no checking if the cards in the arguments are valid.

In unittest2 I found what appears to be a bug, but perhaps is the intended behavior of the function. The
resulting gameState after initializeGame() results in player 1 having fewer than 7 copper. I also found
that there is no checking in the initializeGame() function for whether the cards in the kingdomCard 
array are valid.