Nathalie Blume
CS362
Assignment 3: coverage.c


*GOAL OF TEST SUITE: OVERVIEW

testSuite.c calls 8 test functions. Four of these test methods and 4 test
card implementations in cardEffect().

The following methods are tested:
    updateCoins()          implemented in unittest1.c
    discardCard()          implemented in unittest2.c
    buyCard()              implemented in unittest3.c
    isGameOver()           implemented in unittest4.c

The following cards are tested:
    smithy                 implemented in cardtest1.c
    adventurer             implemented in cardtest1.c
    feast                  implemented in cardtest1.c
    council_room           implemented in cardtest1.c


*COVERAGE ACHIEVEVED BY TEST SUITE: OVERVIEW

The cummulative code coverage of dominion.c acheived by testSuite.c is:

File 'dominion.c'
Lines executed:34.49% of 548
Branches executed:40.53% of 417
Taken at least once:26.38% of 417
Calls executed:25.56% of 90


*COVERAGE OF FUNCTIONS AND FUNCTION CALLS

Not reported above is that 59% (13 out of 22) of functions in dominion.c were called.
By contrast, as reported above, only 25.56% of calls were executed. This suggests that
some of the functions not covered in testSuite.c are called with disproportionate
frequency across dominion.c. The next version of testSuite.c should cover these functions
since there is a reatively greater likelihood that these functions will be called and that
errors in them will become manifest.

These functions were called at least once when running testSuite.c:
    compare();initializeGame(); shuffle();buyCard(); supplyCount();
    whoseTurn(); isGameOver(); drawCards(); getCost(); cardEffect();
    discardCard(); gainCard(); updateCoins();

The functions were never called when running testSuite.c:
    newGame();kingdomCards();playCard();numHandCards(); handCard();
    fullDeckCount(); endTurn(); scoreFor(); getWinners();

Functions with greater call-frequency in dominion.c:
    fullDeckCount(); scoreFor()

Functions to include in the future because they are pivotal to every game:
    endTurn(); getWinners(); playCard();


*LINE COVERAGE

Of the 548 lines of executable code in dominion.c, 34.49% were covered. The rest (65.51%)
are marked #####.

Lines from functions and cards that were not tested were never executed. Better function
and card coverage may improve testSuite.c.

Lines returning an error value to a function call were often not executed. This suggests
that the next version of testSuite.s may explore boundary conditions more thoroughly,
especially conditions that result in error. One example is in initializeGame(), where
an excess in the number of players was never tested. (Note: a significant number of
error-catching conditions were nevertheless included.)

Lines specific to a game with more than 2 players were not executed. This reflects my
bias toward testing a 2-player game, since that was the type of game simulated by the
instructor. For instance, in initializeGame(), all lines in a numPlayer > 2 branch were
ignored.

Lines specific to shuffling the deck were not executed. testSuite.c is largely limited
to the 1st play in a new game. Simulating cases where a game has gone through a few hands
would increase realism and improve the quality of the testing.


*BRANCH COVERAGE

Of the 417 branches in dominion.c, 40.53% were covered. Branch coverage was higher than
line coverage, suggesting that testSuite.c is biased toward covering the branches of
targetted functions and cards, rather than ignoring branching conditions. In writing
the files called by testSuite.c I was careful to implement each option that was
available in a given play.

In analyzing line coverage I already noted that I under-tested branches that led to a
return value of -1, indicating an error. Better coverage of error conditions will increase
branch coverage. Similarly, better coverage of conditions that expand the game to more
players will improve branch coverage.

*BOUNDARY CONDITIONS

Boundary conditions that affected a valid outcome to a play were well covered.
Boundary conditions that determined whether a play was vs. was not valid were
not as well covered.

