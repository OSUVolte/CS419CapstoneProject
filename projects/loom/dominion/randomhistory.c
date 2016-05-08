
/*

Randomtestadventurer

This code was pretty simple to test the very simple features of the card.  All it
does is make sure the deck has no treasure card as well as the players hands.

It then randomly adds two treasure cards to the deck and records their value.  This ensures
that they will be chosen.  It plays the adventure card, and then checks the value of the
hand of the player.  If the player has the same amount of value in his hand that was
added to the deck, the test passes.  This test fails very often.  I believe this is
due to the fact that I introduced many bugs into the adventurer card, as the test does
pass occassionally so we know that it isn't a flawed test.

Interestingly, I tried to add more randomness by randomly choosing a player, but
kept having floating point errors with the random function.  I was unable to determine
why this was, though, none of my tests were fruitful, so it always tests the first player.

Randomtestcard

I tested the smithy card, which is very simple and straightforward.  I randomly picked a player
and a hand size, created them, then played the smithy card to see if it would always add the
correct number of cards.  Of course, because I introduced a bug, it fails every single test
however compensating for that bug shows that the test would pass every time.

Coverage

flip1 ~/CS362/dominion 153% gcov -b randomtestadventurer
File 'randomtestadventurer.c'
Lines executed:94.44% of 72
Branches executed:100.00% of 46
Taken at least once:91.30% of 46
Calls executed:100.00% of 17
Creating 'randomtestadventurer.c.gcov'

flip1 ~/CS362/dominion 154% gcov -b randomtestcard
File 'randomtestcard.c'
Lines executed:96.00% of 25
Branches executed:100.00% of 8
Taken at least once:75.00% of 8
Calls executed:100.00% of 10
Creating 'randomtestcard.c.gcov'


as we can see my tests covered almost the entire code, so they had good coverage.