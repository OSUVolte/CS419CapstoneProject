Overall coverage:
------------------------------------
File 'dominion.c'
Lines executed:28.44% of 654
Branches executed:28.54% of 417
Taken at least once:20.86% of 417

My overall coverage is fairly low, but if you look more closely at the coverage
for the functions that I was testing, the coverage is a lot better.  It makes
sense that the overall coverage is low since I was only explicitly testing 8 functions
for this assignment.  Obviously, this means that there is a lot of room for improvement
to get better overall coverage by adding more tests to cover the remaining functions.adding



Function Specific Tests:
------------------------------------
cardtest1.c covers smithy:
Function 'playSmithy'
Lines executed:100.00% of 5
Branches executed:100.00% of 2
Taken at least once:100.00% of 2

cardtest2.c covers adventurer:
Function 'playAdventurer'
Lines executed:88.89% of 18
Branches executed:100.00% of 12
Taken at least once:83.33% of 12

cardtest3.c covers village:
Function 'playVillage'
Lines executed:100.00% of 4
No branches

cardtest4.c covers council room:
Lines executed:100.00% of 11
Branches executed:100.00% of 6
Taken at least once:100.00% of 6

unittest1.c covers the discardCard() function:
Function 'discardCard'
Lines executed:88.24% of 17
Branches executed:100.00% of 6
Taken at least once:83.33% of 6

unittest2.c covers the updateCoins() function:
Function 'updateCoins'
Lines executed:100.00% of 14
Branches executed:100.00% of 8
Taken at least once:100.00% of 8

unittest3.c covers the gainCard() function:
Function 'gainCard'
Lines executed:100.00% of 15
Branches executed:100.00% of 6
Taken at least once:100.00% of 6

unittest4.c covers the drawCard() function:
Function 'drawCard'
Lines executed:33.33% of 24
Branches executed:33.33% of 6
Taken at least once:16.67% of 6

You will notice that the above function tests provide 100% branch execution for
all 7 functions tested (I have not finished drawCard yet).  This shows that the testing was fairly thourough.  The
functions like smithy, and adventurer which don't have 100% line execution reflect
the bugs that were inserted for Assignment2.  For this assignment, I found an
additional bug in discardCard which explains why it doesn't have 100% line execution.
In my testing, I tried to cover all of the scenarios that I thought the game would
reasonably get into based on how functions and variables were used.  Therefore,
I made the decision not to test calls to a out-of-bounds hand position, for example.
The testing could be improved by better covering boundary conditions such as array
references for parts of the hand/deck/discard arrays that are currently out-of-bounds
based on the current game state.