/************************************************
                   COVERAGE
File 'dominion.c'
Lines executed:37.68% of 568
Branches executed:43.41% of 417
Taken at least once:33.57% of 417
Calls executed:22.00% of 100
Creating 'dominion.c.gcov'

It means the 36.97% lines is covered by the testsuite.
The branch coverage is higher. It can be noticed
that 43.41% of 417 branches were covered.
Overall, the coverage is rather low because the testsuite
covers only 8 functions and the methods
that were called from these functions.
Obviously, the testsuite needs to be expanded
to create better testing.

Examining dominion.c.gcov we can see which lines were
not executed. It will allow to decide on needed
tests.
The following functions should be
tested, because they were called 0 returned 0% blocks
executed 0%:
- minionPlay, remodelPlay, councilRoomPlay, newGame,
kingdomCards, playCard, buyCard, numHandCards, handCard,
endTurn, getWinners, getCost

The following function should be tested additionally,
because the coverage is low:
- cardEffect (Lines executed 8%),

The following functions have a good coverage. However, there may be
possible improvements. Thus, they should be examine to see what parts
were not covered:
- initializeGame (Lines executed 84%), discardCard (Lines executed 85%),
updateCoins (Lines executed 82%)

The following functions have a very good coverage:
- compare (Lines executed 100%), shuffle (Lines executed 94%),
supplyCount (Lines executed 100%), fullDeckCount (Lines executed 100%),
whoseTurn (Lines executed 100%), isGameOver (Lines executed 100%),
drawCard (Lines executed 95%), gainCard (Lines executed 100%),
scoreFor (Lines executed 100%), smithyPlay (Lines executed 100%),
adventurerPlay(Lines executed 100%)
********************************************/
