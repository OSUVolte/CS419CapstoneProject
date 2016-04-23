/*
Ryan Peters
4/22/16

The overall coverage for my unit tests and card tests is 52.84% statement coverage and
54.44% branch coverage.  The number of calls executed was 34.74%.  The totals is not 
that good but I was not trying to test the entire program.  Looking at dominion.c.gcov
I have 100% statement and branch coverage for the four unit tests and the two card test
that were implemented in functions.  It looks like the other two card tests have 100% 
statement coverage and 100% branch coverage but I do not have enough exprience with gcov
and its output to know for sure.  I did bound checking for inputs until it became 
apparent that the only input validation is done in itializing the game.  If a bug was
introduced to the game state after it was intialized most functions if not all will
execute as normal.  The majority of what was not covered in the tests where functions 
that are not called by functions and cards that were tested and the cards that were not
tested.  For a better test suite I would make test for every function and card.

*/