/********************************
** filename: coverage1.c
** author: Candis Pike
** date: April 22, 2016
** description: bug analysis
***********************************/

**********Unit 1 Test*********
File 'unittest1.c'
Lines executed:89.19% of 74
Branches executed:100.00% of 12
Taken at least once:66.67% of 12
Calls executed:87.50% of 32

Function 'updateCoins'
Lines executed:100.00% of 11
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

**********Unit 2 Test*********
File 'unittest2.c'
Lines executed:78.57% of 112
Branches executed:100.00% of 42
Taken at least once:69.05% of 42
Calls executed:81.54% of 65

Function 'gainCard'
Lines executed:100.00% of 13
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1

**********Unit 3 Test*********
File 'unittest2.c'
Lines executed:78.57% of 112
Branches executed:100.00% of 42
Taken at least once:69.05% of 42
Calls executed:81.54% of 65
Creating 'unittest2.c.gcov'

Function 'drawCard'
Lines executed:95.45% of 22
Branches executed:100.00% of 6
Taken at least once:83.33% of 6
Calls executed:100.00% of 1


**********Unit 4 Test*********
File 'unittest4.c'
Lines executed:70.63% of 126
Branches executed:88.89% of 90
Taken at least once:58.89% of 90
Calls executed:71.60% of 81
Creating 'unittest4.c.gcov'

Function 'initializeGame'
Lines executed:96.77% of 62
Branches executed:100.00% of 46
Taken at least once:93.48% of 46
Calls executed:100.00% of 5


******Analysis of unit tests***********
The coverage of the unit tests is in line with expected outputs.
Lines that are not executed are part of if/else statements where the else was never executed within the unit test iteself.
As for the funcitons the unit test provide 95-100% line coverage of the functions being tested with 88-100% branch cover. 
This provides a fair degree of certainty that those functions have been adequately tested. The untit tests can be further refined, 
to ensure that no function tested has calls executed: none.

**********************************************************************************************************************
**********Card 1 Test*********
File 'cardtest1.c'
Lines executed:58.12% of 117
Branches executed:100.00% of 54
Taken at least once:50.00% of 54
Calls executed:66.22% of 74

Lines executed:100.00% of 6
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 3

**********Card 2 Test*********
File 'cardtest2.c'
Lines executed:61.22% of 147
Branches executed:89.19% of 74
Taken at least once:45.95% of 74
Calls executed:67.03% of 91

Lines executed:66.67% of 18
Branches executed:80.00% of 10
Taken at least once:50.00% of 10
Calls executed:66.67% of 3


**********Card 3 Test*********
File 'cardtest3.c'
Lines executed:59.35% of 123
Branches executed:96.43% of 56
Taken at least once:48.21% of 56
Calls executed:66.67% of 78

Function 'playVillage'
Lines executed:100.00% of 6
No branches
Calls executed:100.00% of 3

**********Card 4 Test*********
File 'cardtest4.c'
Lines executed:71.72% of 145
Branches executed:100.00% of 64
Taken at least once:59.38% of 64
Calls executed:72.62% of 84

Function 'playCutpurse'
Lines executed:78.57% of 14
Branches executed:66.67% of 12
Taken at least once:50.00% of 12
Calls executed:100.00% of 4


******Analysis of unit tests***********
The coverage of the unit tests is in line with expected outputs.
Lines that are not executed are part of if/else statements where the else was never executed within the unit test iteself.
100% branch coverage does not equate to 100% statement coverage.
As for the funcitons the unit test provide 78-100% line coverage of the functions being tested with 66-100% branch cover. 
This provides a degree of knowledge that those functions may not be adequately tested. Upon further evaluation, 
it is noted that for testing Adventurer (cardtest2), the condition to trigger a shuffle is never achieved and since the original
initialized conditions are used, the player deck is filled with coin cards resulting in a failure to adequately test for the proper discard of non 
coin cards.  For testing cutpurse (cardtest 4),  when the gcov data for dominion is analyzed the branches that are never executed belong 
to debug statements, therefore, the line and branch coverage results could be off.

********************************************************************************************************************
***************** Dominion Overall analysis ******************************
unction 'updateCoins'
Lines executed:100.00% of 11
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Function 'gainCard'
Lines executed:100.00% of 13
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1

Function 'discardCard'
Lines executed:84.62% of 13
Branches executed:100.00% of 6
Taken at least once:66.67% of 6
No calls

Function 'cardEffect'
Lines executed:6.25% of 192
Branches executed:14.11% of 163
Taken at least once:3.07% of 163
Calls executed:9.09% of 55

Function 'getCost'
Lines executed:0.00% of 30
Branches executed:0.00% of 28
Taken at least once:0.00% of 28
No calls

Function 'drawCard'
Lines executed:95.45% of 22
Branches executed:100.00% of 6
Taken at least once:83.33% of 6
Calls executed:100.00% of 1

Function 'getWinners'
Lines executed:0.00% of 24
Branches executed:0.00% of 22
Taken at least once:0.00% of 22
Calls executed:0.00% of 2

Function 'scoreFor'
Lines executed:0.00% of 24
Branches executed:0.00% of 42
Taken at least once:0.00% of 42
Calls executed:0.00% of 3

Function 'isGameOver'
Lines executed:0.00% of 10
Branches executed:0.00% of 8
Taken at least once:0.00% of 8
No calls

Function 'endTurn'
Lines executed:0.00% of 20
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 3

Function 'whoseTurn'
Lines executed:100.00% of 2
No branches
No calls

Function 'fullDeckCount'
Lines executed:0.00% of 9
Branches executed:0.00% of 12
Taken at least once:0.00% of 12
No calls

Function 'supplyCount'
Lines executed:100.00% of 2
No branches
No calls

Function 'handCard'
Lines executed:0.00% of 3
No branches
Calls executed:0.00% of 1

Function 'numHandCards'
Lines executed:0.00% of 2
No branches
Calls executed:0.00% of 1

Function 'buyCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 4

Function 'playCard'
Lines executed:0.00% of 14
Branches executed:0.00% of 10
Taken at least once:0.00% of 10
Calls executed:0.00% of 3

Function 'shuffle'
Lines executed:93.75% of 16
Branches executed:100.00% of 8
Taken at least once:87.50% of 8
Calls executed:100.00% of 2

Function 'initializeGame'
Lines executed:96.77% of 62
Branches executed:100.00% of 46
Taken at least once:93.48% of 46
Calls executed:100.00% of 5

Function 'kingdomCards'
Lines executed:0.00% of 13
No branches
No calls

Function 'newGame'
Lines executed:0.00% of 3
No branches
No calls

Function 'compare'
Lines executed:100.00% of 6
Branches executed:100.00% of 4
Taken at least once:100.00% of 4
No calls

Function 'playCutpurse'
Lines executed:78.57% of 14
Branches executed:66.67% of 12
Taken at least once:50.00% of 12
Calls executed:100.00% of 4

Function 'playVillage'
Lines executed:100.00% of 6
No branches
Calls executed:100.00% of 3

Function 'playFeast'
Lines executed:0.00% of 17
Branches executed:0.00% of 10
Taken at least once:0.00% of 10
Calls executed:0.00% of 6

Function 'playSmithy'
Lines executed:100.00% of 6
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 3

Function 'playAdventurer'
Lines executed:66.67% of 18
Branches executed:80.00% of 10
Taken at least once:50.00% of 10
Calls executed:66.67% of 3

Overall
Lines executed:33.27% of 565
Branches executed:30.12% of 415
Taken at least once:22.89% of 415
Calls executed:26.00% of 100

33% line coverage and 30% branch coverage implies that large section of the code has not been analyzed and in fact this is the case. When looking
at the function breakdown for dominion there are functions that are never called by any unit or card test. To improve overall confidence in the dominion code
futher unit and card tests need to be developed. Unit tests should focus on the remaining major functions such as "buyCard()", "playCard()", "endTurn()", 
"getWinners()", etc. Also further testing of the action cards would be advisable since no 2 cards have the same functionality.  




