//Name: Marta Wegner
//CS 362 Assignment #3
//Coverage of unit tests

Only about 24% of the lines in dominion.c were executed using these
unit test. Although this is faily low, considering only eight out of
the many functions the program uses were tested, this seems like a 
resonable percentage. Similary, 17% of the branches were executed. As
like before, this low number is likely due to the small number of 
functions tested.

Reviewing the dominion.c.gcov file indicates that all of the functions 
that were tested in the unit tests were thoughroughly covered. Except
for in the case where a bug I introduced into the code caused it to skip
over part of a function that was being tested, like how most of 
playAdventurer is not executed due to a bug, each of these functions 
has a very high line and branch coverage. For example, in the 
updateCoin() function each of the lines is covered and all of the 
branches in the function are taken.

A few ways to improve code coverage in the future are to test more 
functions, to remove bugs that prevent code from executing, or to
test functions that are more complex/call additional functions. Another 
area in which the coverage of my code may be weak is in testing 
boundaries. Writing more tests that test the functions at their 
boundaries could benefit code coverage in the future. 