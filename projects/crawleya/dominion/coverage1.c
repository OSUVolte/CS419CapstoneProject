/* -----------------------------------------------------------------------
 * Alisha Crawley-Davis
 * CS 362 Assn 3
 * coverage1.c
 * Description of code coverage
 * -----------------------------------------------------------------------
 */


/*
Using line coverage, my unit tests ended up covering 44.09% of dominion.c.
Because I only tested 8 functions or partial functions, this is not a 
surprising result.

Upon closer examination of the functions I did test, this is what I found:

For the numHandCard() function, I had both 100% statement and branch coverage.

For the scoreFor() function, I had 100% both statement and branch coverage.

For the getCost() function, I had 100% both statement and branch coverage.

Of the isGameOver() function, I had 100% both statement and branchcoverage.

For the cards I tested, this is what I found:

For the smithy card, I had 100% statement coverage. I was also able to see
branch coverage, as I had implemented this as its own function. I also had
100% branch coverage of this.

For the gardens card, I had 100% statement coverage.

For the village card, I had 100% statement coverage. I had implemented this
card separately for Assignment 1, so I was also able to check the branch coverage.
There was 100% branch coverage of this function.

I implemented this card as its own function, so was able to check the branch coverage.
I had 93% branch coverage for this function. I had missed the case where the deck needed 
to be shuffled. This is a good example of how code coverage can help testers write
better unit tests. I will use this information to improve my test cases for this function
in the future.

While most of my tests had extremely good coverage of what I had focused on testing, this
shows a flaw on solely focusing on coverage. There are many tests (and probably bugs) that I
missed with these unit tests. This is a great example of the idea that good coverage does not
necessarily indicate a good test suite.

Overall, though, the coverage information is very useful. It will help me better test the functions
that I have already tested for this assignment. Further, it will help me design future tests
to ensure that I cover the rest of the dominion code well.
*?

