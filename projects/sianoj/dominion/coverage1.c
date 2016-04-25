Gcov Results

The results are shown in my unittestresults.out file at the very bottom.

Coverage for all 8 test files:

File 'dominion.c'
Lines executed:25.10% of 580
Branches executed:30.05% of 415
Taken at least once:21.00% of 415
Calls executed:21.00% of 100

All of my tests could have been improved.  None of them reached full statement or branch coverage, as can bee seen since I did not even cover a third of the lines in branch coverage, and around a fifth or a quarter of the other types of coverage.  This happened because I wasn't checking all of the possible branches or testing all of the conditionals. I only used basic cases and always had players start with the normal 5 card hand.  I never checked any boundry cases.  I also set the number of players manually to 3 during my card tests which did not allow for test cases with more or less players.  


