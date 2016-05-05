/******************************************************************************
 * Author: Kelby Faessler
 * Class: CS362
 * Project: Assignment 3
 *****************************************************************************/

/*
Coverage:

I set up my makefile like the example given so that it runs gcov and prints the
results in a file along with the unit test results. After my tests were run I 
covered 9.31% of dominion.c. It is not surprising this is so low because that
file is very large with many functions. For the assignment we were required to
test 8 functions and this is a small fraction of the total, so the coverage
will correspondingly be low. 

I tried to get some coverage of boundaries and in fact I was successful in 
finding some bugs this way. I talk about this in my bug1.c file, but I found
a bug where the code was indexing outside of an array and also where a loop
was not looping over all of the items it should have been. I'm sure there are
some boundaries I missed with my tests so this is probably an area for
improvement.

Some of the functions I tested had several different paths of execution 
depending on the values of the arguments to the function. I tried to test 
all possible branches of exectution because the functions I tested were not
too long. In some cases (e.g. the gainCard() function) the function will 
call different functions in these different branches. So, I think its 
important to cover all of these different branches if it doesn't become
too much work in the longer functions.

*/
