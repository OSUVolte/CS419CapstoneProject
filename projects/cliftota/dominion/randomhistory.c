/**********************************************************************
CS362-400
Assignment 4
File: randomhistory.c
Author: Tatsiana Clifton
Date: 5/3/2016
***********************************************************************/

/*
TEST ADVENTURER CARD

The random testing of the adventurer card was based on the covering of
the following test cases:
    1. The number of treasure cards in hands of the current player must be
    increased by 2.
    2. The number of cards in hands of the current player must be
    increased by 2.
    3. The number of cards in deck of the current player must be
    decreased by 2.
    4. The deck count of other players must be unchanged.
    5. The hand count of other players must be unchanged.
    6. The played count must be increased by 1.
    7. The victory cards pile must be unchanged.
    8. The kingdom cards pile must be unchanged.

It was set up to run tests 5000 times. Each time the following values
were set randomly:
    1. The number of player in the range between 2 and 4.
    2. The seed for initializing the game.
    3. The deck count for each player.
    4. The discard count for each player.
    5. The hand count for each player.

The random testing results of the adventure card proved the results
of the unit testing of this card. However, we can notice that 2 test cases
of random testing did not fail 5000 times. The test of number of treasure
cards in hand failed 30 times. The test of number of cards in hand failed
also 30 times. Both of this test failed during unit testing also.
However, it seems that if the test runs only one time it will be
possible to pass these two cases. Thus, the random testing due to
high number of loops gives more reliable results in this case.
Other test cases failed 5000 times or did not fail at all. It means that
the unit testing could be reliable in these cases.

The number of the for loop that runs random tester was increased gradually
in order to get better coverage. This strategy worked, because the coverage
was getting better with bigger number of loops. The coverage did not changed
with increasing from 1000 to 5000. Thus, probably it would be enough to have
1000 loops to have a rather good coverage. The lines executed
in randomtestadventurer.c will not be 100% because of the multiple if else
statements.
With 10 loops the coverage is:
    File 'randomtestadventurer.c'
    Lines executed:81.91% of 94
    Branches executed:100.00% of 58
    Taken at least once:63.79% of 58
    Calls executed:100.00% of 27
    Creating 'randomtestadventurer.c.gcov'

    File 'dominion.c'
    Lines executed:20.60% of 568
    Branches executed:19.18% of 417
    Taken at least once:16.55% of 417
    Calls executed:10.00% of 100
    Creating 'dominion.c.gcov'

With 100 loops the coverage is:
    File 'randomtestadventurer.c'
    Lines executed:81.91% of 94
    Branches executed:100.00% of 58
    Taken at least once:63.79% of 58
    Calls executed:100.00% of 27
    Creating 'randomtestadventurer.c.gcov'

    File 'dominion.c'
    Lines executed:20.60% of 568
    Branches executed:19.18% of 417
    Taken at least once:16.55% of 417
    Calls executed:10.00% of 100
    Creating 'dominion.c.gcov'

With 1000 loops the coverage is:
    File 'randomtestadventurer.c'
    Lines executed:84.04% of 94
    Branches executed:100.00% of 58
    Taken at least once:67.24% of 58
    Calls executed:100.00% of 27
    Creating 'randomtestadventurer.c.gcov'

    File 'dominion.c'
    Lines executed:23.24% of 568
    Branches executed:20.14% of 417
    Taken at least once:18.23% of 417
    Calls executed:11.00% of 100
    Creating 'dominion.c.gcov'

With 5000 loops the coverage is:
    File 'randomtestadventurer.c'
    Lines executed:84.04% of 94
    Branches executed:100.00% of 58
    Taken at least once:67.24% of 58
    Calls executed:100.00% of 27
    Creating 'randomtestadventurer.c.gcov'

    File 'dominion.c'
    Lines executed:23.24% of 568
    Branches executed:20.14% of 417
    Taken at least once:18.23% of 417
    Calls executed:11.00% of 100
    Creating 'dominion.c.gcov'


TEST VILLAGE CARD

The random testing of the village card was based on the covering of
the following cases:
    1. The number of cards in hands of the current player must be
    increased by 1.
    2. The number of actions must be increased by 2.
    3. The number of cards in deck of the current player must be
    decreased by 1.
    4. The number of cards in the discard must be unchanged if the
    discard was not added to the deck (it happens when the deck is empty).
    Otherwise, if it was added to the deck, the number of cards in
    the discard must be 0.
    4. The deck count of other players must be unchanged.
    5. The hand count of other players must be unchanged.
    6. The played count must be increased by 1.
    7. The victory cards pile must be unchanged.
    8. The kingdom cards pile must be unchanged.

It was set up to run tests 5000 times. Each time the following values were
set randomly:
    1. The number of player in the range between 2 and 4.
    2. The seed for initializing the game.
    3. The deck count for each player.
    4. The discard count for each player.
    5. The hand count for each player.

The random testing results of the adventure card proved the results
of the unit testing of this card. All tests passed.

The number of the for loop that runs random tester was increased gradually
in order to get better coverage. This technique worked, because the coverage
was getting better with higher number of loops. The coverage did not changed
with increasing from 1000 to 5000. Thus, probably it would be enough to have
1000 loops to have a rather good coverage. The lines executed
in randomtestcard.c will not be 100% because of the multiple if else
statements.
With 10 loops the coverage is:
    File 'randomtestcard.c'
    Lines executed:73.00% of 100
    Branches executed:90.32% of 62
    Taken at least once:51.61% of 62
    Calls executed:100.00% of 29
    Creating 'randomtestcard.c.gcov'

    File 'dominion.c'
    Lines executed:21.30% of 568
    Branches executed:23.26% of 417
    Taken at least once:15.35% of 417
    Calls executed:10.00% of 100
    Creating 'dominion.c.gcov'

With 100 loops the coverage is:
    File 'randomtestcard.c'
    Lines executed:73.00% of 100
    Branches executed:90.32% of 62
    Taken at least once:51.61% of 62
    Calls executed:100.00% of 29
    Creating 'randomtestcard.c.gcov'

    File 'dominion.c'
    Lines executed:21.30% of 568
    Branches executed:23.26% of 417
    Taken at least once:15.35% of 417
    Calls executed:10.00% of 100
    Creating 'dominion.c.gcov'

With 1000 the coverage is:
    File 'randomtestcard.c'
    Lines executed:76.00% of 100
    Branches executed:100.00% of 62
    Taken at least once:61.29% of 62
    Calls executed:100.00% of 29
    Creating 'randomtestcard.c.gcov'

    File 'dominion.c'
    Lines executed:23.77% of 568
    Branches executed:24.22% of 417
    Taken at least once:16.55% of 417
    Calls executed:11.00% of 100
    Creating 'dominion.c.gcov'

With 5000 loops the coverage is:
    File 'randomtestcard.c'
    Lines executed:76.00% of 100
    Branches executed:100.00% of 62
    Taken at least once:61.29% of 62
    Calls executed:100.00% of 29
    Creating 'randomtestcard.c.gcov'

    File 'dominion.c'
    Lines executed:23.77% of 568
    Branches executed:24.22% of 417
    Taken at least once:16.55% of 417
    Calls executed:11.00% of 100
    Creating 'dominion.c.gcov'
*/
