Code Coverage
_____________________________________________________________
/*
Overall

I had very high branch coverage for all unit tests but had a lower percentage 
for lines covered. This is partly due to the fact that many lines will not execute unless
there is a bug in the code (ie lines to print error messages).

In the dominion program I had minimal coverage with just 35% of lines executed and 36% branch coverage.
This is because there are a number of functions that were never called. It makes it very obvious how effective
function-based testing can be. If I were to write unit tests for each function, I would estimate 80-90% of branch coverage
without even wrtiting broad program-based tests. However, the fact that testing individual functions can give such high coverage is
a good reminder that coverage is not always a good indicator of quality.

My tests do not test how the flow of the game works which is a very importand part of the program.


GetCost:
This test had good coverage but did not catch any bugs.
Lines executed:88.24% of 17
Branches executed:100.00% of 6
Taken at least once:66.67% of 6
Calls executed:75.00% of 8


initializeGame:
This test caught one bug. There was only 70% line coverage but high branch coverage. I think it would
be beneficial to add more variables to the tests.
Lines executed:69.70% of 33
Branches executed:94.12% of 34
Taken at least once:47.06% of 34
Calls executed:37.50% of 16


buyCard:
In this function I caught one bug but have low coverage. I think it would benefit from Random testing.
Lines executed:64.29% of 28
Branches executed:77.78% of 18
Taken at least once:38.89% of 18
Calls executed:38.46% of 13

fullDeckCount:
This test caught a bug relating to a change of state when there should be none. Even though it has good coverage, 
I think there needs to be additional tests to check for other incorrect state changes because the current tests
don't give a very broad picture.
Lines executed:88.24% of 17
Branches executed:100.00% of 6
Taken at least once:66.67% of 6
Calls executed:75.00% of 8

smithy:
The unit tests here caught multiple errors. I believe most of them are due to errors in the draw and discard functions.
I think it is difficult to separate where functions fail when they have many dependencies.
Lines executed:74.29% of 35
Branches executed:100.00% of 20
Taken at least once:50.00% of 20
Calls executed:52.94% of 17


adventurer:
Again, I think there are problems with the internal functions. At the same time, I know I introduced a bug in this function
that will cause similar problems so even thought coverage is high I think I need to imporve my tests to make them more specific.
Lines executed:91.67% of 36
Branches executed:100.00% of 28
Taken at least once:64.29% of 28
Calls executed:70.00% of 10

great hall:
I had high branch coverage here and almost 89% line coverage which is good if you exclude printf lines for error reporting.
The only bugs I caught were die to discard and draw functions.
Lines executed:88.46% of 26
Branches executed:100.00% of 12
Taken at least once:50.00% of 12
Calls executed:70.00% of 10

outpost:
Results here were almost identical to great hall. I think my test suite would benefit from making my tests more specific
and independent of other functions whenever possible.
Lines executed:88.46% of 26
Branches executed:100.00% of 12
Taken at least once:50.00% of 12
Calls executed:70.00% of 10
*/