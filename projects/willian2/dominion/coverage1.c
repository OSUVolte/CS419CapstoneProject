/******************************************************************************
* ASSIGNMENT 3 - coverage1.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 04/24/2016
* NOTES: coverage discussion for Assignment 3
******************************************************************************/

/******************************************************************************
* dominion.c COVERAGE
* Lines executed:34.59% of 558
* Branches executed:42.89% of 415
* Taken at least once:33.01% of 415
* Calls executed:23.40% of 94
* Creating 'dominion.c.gcov'
******************************************************************************/

/******************************************************************************
* UNIT TEST COVERAGES
* File 'unittest1.c'
* Lines executed:100.00% of 28
* Creating 'unittest1.c.gcov'
* 
* File 'unittest2.c'
* Lines executed:97.22% of 36
* Creating 'unittest2.c.gcov'
* 
* File 'unittest3.c'
* Lines executed:98.08% of 52
* Creating 'unittest3.c.gcov'
* 
* File 'unittest4.c'
* Lines executed:100.00% of 50
* Creating 'unittest4.c.gcov'
* 
* File 'cardtest1.c'
* Lines executed:91.67% of 36
* Creating 'cardtest1.c.gcov'
* 
* File 'cardtest2.c'
* Lines executed:89.47% of 38
* Creating 'cardtest2.c.gcov'
* 
* File 'cardtest3.c'
* Lines executed:84.21% of 38
* Creating 'cardtest3.c.gcov'
* 
* File 'cardtest4.c'
* Lines executed:80.56% of 36
* Creating 'cardtest4.c.gcov'
******************************************************************************/

/******************************************************************************
* DISCUSSION
* Coverage of dominion.c was expectedly fairly low, as I naturally have not
* implemented tests for most of the program. Because I chose functions that
* for the most part did not call other functions (the exception being the
* scoreFor() and fullDeckCount() functions; scoreFor() relies on fullDeckCount()
* to count cards for use by the garden). What surprised me was the coverage for
* my card tests, which turned out to be a little lower than I expected. In
* retrospect I realized that I did not test for my own bug in cardtest4, but
* somehow it throws errors anyway. I also noticed that in cardtest3 the number
* of discarded cards is discrepant, which surprised me. Somehow on tests 2,
* 3, and 4, I have unexpectedly low coverage. The unit testing was remarkably
* higher than I expected, because I found a lot of bugs that I could not
* account for. 
******************************************************************************/