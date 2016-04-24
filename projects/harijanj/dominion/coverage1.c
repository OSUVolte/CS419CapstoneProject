/*TEST COVERAGE 
--------------------------------------------------------------------------------

--> Test Coverage for DOMINION

[harijanj@flip2 dominion]$ gcov -b dominion
File 'dominion.c'
Lines executed:44.11% of 569
Branches executed:45.54% of 415
Taken at least once:37.11% of 415
Calls executed:34.34% of 99
Creating 'dominion.c.gcov'

Explanation:
The coeverage results 44.11% means only around 
250 lines are covered with the tests provided.
The coverage test for dominion is relatively low,
one of the reason because there are only 8 test units
testing 8 different functions, where there actually
more than 8 functions exists in dominion.c
In order to increase the coverage results, more tests
must be created in order to cover the other functions
in dominion.c

Result from 'dominion.c.gcov' (summary):

newGame called 0 times (0% blocks executed)
kingdomCards called 0 times (0%)
initializeGame called 108 times (100%)
shuffle called 15309 times (100%)
playCard called 0 times (0%)
buyCard called 0 times (0%)
numHandCards called 0 times (0%)
handCard called 0 times (0%)
supplyCount called 0 times (0%)
fullDeckCount called 68 times (100%)
whoseTurn called 607 times (100%)
endTurn called 87 times (100%)
isGameOver called 23 times (100%)
scoreFor called 6 times (74%)
getWinners called 0 times (0%)
drawCard called 9449 times (100%)
adventurerCard called 30 times (100%)
smithyCard called 96 times (100%)
councilRoomCard called 89 times (100%)
villageCard called 44 times (100%)
greatHallCard called 0 times (0%)
getCost called 0 times (0%)
cardEffect called 261 times (100%)
discardCard called 249 times (89%)
gainCard called 0 times (0%)
updateCoins called 199 times (100%)

Conclusion:
This show that actually testing 8 functions are
not enough to be consider as "real testing".
However, this is for assignment purpose and want to
give the experience to students about "how to test"
a program. Therefore, 8 functions consider to be enough.
The only way to increase the "%" coverage is simply by
create more test.

Below are the "more-specific" gcov test coverage result
for each of the 8 functions.

--------------------------------------------------------------------------------

--> Test Coverage for UNITTEST

[harijanj@flip3 dominion]$ gcov -b unittest1
File 'unittest1.c'
Lines executed:95.77% of 71
Branches executed:100.00% of 20
Taken at least once:80.00% of 20
Calls executed:83.33% of 18
Creating 'unittest1.c.gcov'

[harijanj@flip3 dominion]$ gcov -b unittest2
File 'unittest2.c'
Lines executed:93.75% of 64
Branches executed:100.00% of 14
Taken at least once:64.29% of 14
Calls executed:82.61% of 23
Creating 'unittest2.c.gcov'

[harijanj@flip3 dominion]$ gcov -b unittest3
File 'unittest3.c'
Lines executed:91.89% of 74
Branches executed:100.00% of 30
Taken at least once:80.00% of 30
Calls executed:83.87% of 31
Creating 'unittest3.c.gcov'

[harijanj@flip3 dominion]$ gcov -b unittest4
File 'unittest4.c'
Lines executed:95.12% of 82
Branches executed:100.00% of 34
Taken at least once:85.29% of 34
Calls executed:83.33% of 24
Creating 'unittest4.c.gcov'

--------------------------------------------------------------------------------

--> Test Coverage for CARDTEST

[harijanj@flip3 dominion]$ gcov -b cardtest1
File 'cardtest1.c'
Lines executed:89.86% of 69
Branches executed:100.00% of 22
Taken at least once:54.55% of 22
Calls executed:81.48% of 27
Creating 'cardtest1.c.gcov'

[harijanj@flip3 dominion]$ gcov -b cardtest2
cardtest2.c:source file is newer than notes file 'cardtest2.gcno'
(the message is only displayed one per source file)
File 'cardtest2.c'
Lines executed:91.57% of 83
Branches executed:100.00% of 22
Taken at least once:54.55% of 22
Calls executed:86.49% of 37
Creating 'cardtest2.c.gcov'

[harijanj@flip3 dominion]$ gcov -b cardtest3
File 'cardtest3.c'
Lines executed:91.18% of 68
Branches executed:100.00% of 20
Taken at least once:55.00% of 20
Calls executed:80.77% of 26
Creating 'cardtest3.c.gcov'

[harijanj@flip3 dominion]$ gcov -b cardtest4
cardtest4.c:source file is newer than notes file 'cardtest4.gcno'
(the message is only displayed one per source file)
File 'cardtest4.c'
Lines executed:89.86% of 69
Branches executed:100.00% of 22
Taken at least once:54.55% of 22
Calls executed:81.48% of 27
Creating 'cardtest4.c.gcov'

*/