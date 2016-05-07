/*
David DeRisi
CS 362 - 400
5/6/2016
randomhistory.c



Adventurer card:  For this random test exercise the paramaters that were randomzied include the deck size,
the cards in the deck themselves as well as the coin type and their placement in the deck themselves.
In the tests I am looking for whether or not the player hand card count increases, whether the deck card count decreases, 
the discard pile increases or remains the same, whether the players deck reflects a change and whether or not the opponents
various card states remain unchanged.


Council Room card:  For this random test, the deck was randomized in the same manner as the adventurer card,
and the number of buys is also randomized before the tests are executed as well.  In this tests I examine whether
or not the player gains cards, the deck decreases, the players buys increase, the opponent draws a card and if
the player discards the card that was played.

For both cards the tests executed are the same as they were in the cardtests from assignment 3.

The tests did not have total coverage, the adventurer tests actually had a slightly lower coverage
than it did in the previous assignment.  However, the tests for the the council room card had better
coverage this time around, though, nothing about the actual checks was changed.  Either way, the tests
still do not have total edge and branch coverage.  The failures that were recorded were again the result of
bugs introduced into these files as outlined in bug1.c, so the tests that were written are detecting them
accordingly.  There is still an issue in the adventurer tests where some if statements are not picking up
and as a result there is no output.  If I had to a venture a guess I would say this has to do with one of the 
loop parameters being zero when it shouldn't be or the if statements are not being tripped.  The tests were ran a total of twenty times each, with the 
results being the same essentially through each loop.

File 'randomtestadventurer.c'
Lines executed:76.40% of 89
Branches executed:87.50% of 32
Taken at least once:59.38% of 32
Calls executed:75.00% of 44
Creating 'randomtestadventurer.c.gcov'

File 'dominion.c'
Lines executed:20.14% of 561
Branches executed:19.18% of 417
Taken at least once:16.31% of 417
Calls executed:10.53% of 95
Creating 'dominion.c.gcov'

File 'randomtestcard.c'
Lines executed:89.47% of 57
Branches executed:100.00% of 14
Taken at least once:64.29% of 14
Calls executed:80.77% of 26
Creating 'randomtestcard.c.gcov'


File 'dominion.c'
Lines executed:19.07% of 561
Branches executed:18.23% of 417
Taken at least once:14.39% of 417
Calls executed:10.53% of 95
Creating 'dominion.c.gcov'






*/