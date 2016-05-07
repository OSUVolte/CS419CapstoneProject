/************
Author: James Taylor
Date: 4/24/16

coverage1.c: Discussion about gcov results from unit and card tests
including dominion.c coverage. 

************/

unittest1:

Lines executed:85.71% of 56
Branches executed:100% of 16
Taken at least once:50% of 16

The unittest is successfully iterating through all the branches while line coverage is around 85%. 
This leads me to believe that the test is successfully running through its intended paths, and since there 
are not test cases to cause both pass and fail for each test, line coverage is not 100%. 

unittest2:
Lines executed:82.35% of 68
Branches executed:100% of 24
Taken at least once:50% of 24

Again, the unittest is iterating through all its branches and since the test cases don't provide pass and fail
opportunities for each test, line coverage is around 82% with branch coverage at 100%. 

cardtest1:
Lines executed: 90.91% of 22
Branches executed:100% of 4
Taken at least once:50% of 4 

cardtest1 successfully iterates through its individual tests as shown by the Branch and line coverage numbers. 
100% is not achieve because again test cases do not provide both pass and fail opportunities. 

cardtest2:
Lines executed:93.55% of 31
Branches executed:100% of 4
Taken at least once:50% of 4

cardtest2 successfully reaches all its test cases and follows through to a pass/fail state as indicated by the 
100% branch execution, 50% branches taken, and 93% statement coverage. Again, the only way to increase these coverage numbers is
to manipulate the test cases to provide both pass and fail opportunities. 

cardtest3:
Lines execute:90.91% of 33
Branches executed:100.00% of 6
Taken at least once:50.00% of 68

cardtest3 reached all its test cases and reached pass/fail conclusions on all tests. Again, the only way to increase coverage
is to manipulate the test cases to provide pass and fail opportunities.


For the unit tests, all my unit test successfully reach all their branches and complete their test cases.
The unittest1 executes 17.71% of 559 of dominion.c code. The unittest2 executes 16.28% of the 559 lines of dominion.c 
code. Given that each unittest only interacts with specific pieces of the code this is not unexpected. Also, the relative
simple nature of isGameOver() and supplyCount() there will not be widespread interaction with all the components of 
of the program. Increasing the number of functions tested and integrating them into a comprehensive test suite will
help get improved branch and line coverage and better overall metrics to help determine if and when the test suite
reaches sufficient coverage. 

The coverage numbers for cardtests are nearly identical to the unit tests. High branch coverage and high statement coverage
suggest that all the test cases reach their conclusions. Dominion.c coverage stats reached line exectution for cardtest1, cardtest2 and cardtest3 of 
18.96%, 19.14%, and 18.78% respectively. Adding more refactored cards or fully testing cardEffect() will
will improve overall dominion.c coverage stats as some cards interact with more or diffent functions from within
dominion.c.