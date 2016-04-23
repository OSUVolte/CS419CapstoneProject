Heidi Binder-Vitti
CS362
Assignment 3
Coverage Report
Used gcov to measure line and branch coverage for each unit test created.

Summary:  My unit tests did not cover 100% of the statements. This is okay because
there were many if statements that meant lines were skipped if the test passed or 
failed. Branch coverage is at 100% for all tests.
	Many of the functions tested through cardtests and unittests had 100% coverage.
The tests that need to be added to are cardtest1 for the adventurer card, unitetest3
for discardCard, and unittest4 for playCard.  These functions all had less than 100%
coverage for statements and branches.  Expanding the unit tests to cover all lines and 
branches would be a good way to improve the tests.
	There are also several functions of dominion that were not covered at all or not
completely covered.  This is because the unit tests were written to test four specific
cards and four specific functions, not the entire program.  To have a complete test suite,
I would need to write tests that cover the entire program.

gcov cardtest1.c -b
File 'cardtest1.c'
Lines executed:70.00% of 80
Branches executed:100.00% of 28
Taken at least once:53.57% of 28
No calls
cardtest1.c:creating 'cardtest1.c.gcov'

gcov cardtest2.c -b
File 'cardtest2.c'
Lines executed:65.57% of 61
Branches executed:100.00% of 26
Taken at least once:53.85% of 26
No calls
cardtest2.c:creating 'cardtest2.c.gcov'

gcov cardtest3.c -b
File 'cardtest3.c'
Lines executed:68.18% of 66
Branches executed:100.00% of 28
Taken at least once:53.57% of 28
No calls
cardtest3.c:creating 'cardtest3.c.gcov'

gcov cardtest4.c -b
File 'cardtest4.c'
Lines executed:68.18% of 66
Branches executed:100.00% of 28
Taken at least once:53.57% of 28
No calls
cardtest4.c:creating 'cardtest4.c.gcov'

gcov unittest1.c -b
File 'unittest1.c'
Lines executed:88.10% of 42
Branches executed:100.00% of 10
Taken at least once:50.00% of 10
No calls
unittest1.c:creating 'unittest1.c.gcov'

gcov unittest2.c -b
File 'unittest2.c'
Lines executed:95.24% of 21
Branches executed:100.00% of 2
Taken at least once:50.00% of 2
No calls
unittest2.c:creating 'unittest2.c.gcov'

gcov unittest3.c -b
File 'unittest3.c'
Lines executed:90.00% of 20
Branches executed:100.00% of 4
Taken at least once:50.00% of 4
No calls
unittest3.c:creating 'unittest3.c.gcov'

gcov unittest4.c -b
File 'unittest4.c'
Lines executed:85.71% of 21
Branches executed:100.00% of 4
Taken at least once:50.00% of 4
No calls
unittest4.c:creating 'unittest4.c.gcov'

Function 'compare'
Lines executed:83.33% of 6
Branches executed:100.00% of 4
Taken at least once:75.00% of 4
No calls

Function 'newGame'
Lines executed:0.00% of 2
No branches
No calls

Function 'kingdomCards'
Lines executed:0.00% of 12
No branches
No calls

Function 'initializeGame'
Lines executed:85.90% of 78
Branches executed:95.65% of 46
Taken at least once:80.43% of 46
No calls

Function 'shuffle'
Lines executed:94.44% of 18
Branches executed:100.00% of 8
Taken at least once:87.50% of 8
No calls

Function 'playCard'
Lines executed:57.14% of 14
Branches executed:60.00% of 10
Taken at least once:40.00% of 10
No calls

Function 'buyCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
No calls

Function 'numHandCards'
Lines executed:0.00% of 1
No branches
No calls

Function 'handCard'
Lines executed:100.00% of 2
No branches
No calls

Function 'supplyCount'
Lines executed:100.00% of 1
No branches
No calls

Function 'fullDeckCount'
Lines executed:0.00% of 11
Branches executed:0.00% of 12
Taken at least once:0.00% of 12
No calls

Function 'whoseTurn'
Lines executed:100.00% of 1
No branches
No calls

Function 'endTurn'
Lines executed:0.00% of 22
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
No calls

Function 'isGameOver'
Lines executed:0.00% of 12
Branches executed:0.00% of 8
Taken at least once:0.00% of 8
No calls

Function 'scoreFor'
Lines executed:0.00% of 26
Branches executed:0.00% of 42
Taken at least once:0.00% of 42
No calls

Function 'getWinners'
Lines executed:0.00% of 33
Branches executed:0.00% of 22
Taken at least once:0.00% of 22
No calls

Function 'drawCard'
Lines executed:33.33% of 24
Branches executed:33.33% of 6
Taken at least once:16.67% of 6
No calls

Function 'getCost'
Lines executed:0.00% of 30
Branches executed:0.00% of 28
Taken at least once:0.00% of 28
No calls

Function 'cardEffect'
Lines executed:7.38% of 244
Branches executed:13.61% of 169
Taken at least once:2.96% of 169
No calls

Function 'discardCard'
Lines executed:73.33% of 15
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
No calls

Function 'gainCard'
Lines executed:100.00% of 15
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
No calls

Function 'updateCoins'
Lines executed:100.00% of 14
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Function 'playAdventurer'
Lines executed:59.09% of 22
Branches executed:100.00% of 10
Taken at least once:60.00% of 10
No calls

Function 'playSmithy'
Lines executed:100.00% of 6
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
No calls

Function 'playGreat_Hall'
Lines executed:100.00% of 5
No branches
No calls

Function 'playFeast'
Lines executed:0.00% of 20
Branches executed:0.00% of 10
Taken at least once:0.00% of 10
No calls

Function 'playRemodel'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
No calls

File 'dominion.c'
Lines executed:28.94% of 660
Branches executed:28.67% of 415
Taken at least once:19.76% of 415
No calls
dominion.c:creating 'dominion.c.gcov'

