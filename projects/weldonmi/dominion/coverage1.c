/*
Miranda Weldon
April 24, 2016
CS 362 Spring 2016
Assignment 3
coverage1.c

In terms of code coverage, most of the tests did very well, having high percentages for statement and branch execution. cardtest4 and unittest1 both had relatively less coverage, with cardtest4 having less statement coverage due to many statement appearing within conditions that wouldn't execute if the function tested worked correctly and with unittest1 have less branch coverage due to the use of elseif statements.

As for dominion.c, such low coverage is to be expected as we are testing functions alone. If we were to also test the functions they depend on or the function that later call these functions/cards, we would be much more likely to see higher statement and branch coverage for dominion.c.

Improvement will be needed for these test, as more robust testing can give us more confidence that the functions and cards we are testing have no bugs. I would particularly look into any functions using handCount, as they contributed to the issues with unittest3, unittest4, cardtest3, and cardtest4.

File 'dominion.c'
Lines executed:37.23% of 548
Branches executed:42.93% of 417
Taken at least once:28.06% of 417
Calls executed:25.56% of 90

File 'cardtest1.c'
Lines executed:100.00% of 25
Branches executed:100.00% of 20
Taken at least once:65.00% of 20
Calls executed:73.68% of 19

File 'cardtest2.c'
Lines executed:100.00% of 20
Branches executed:100.00% of 10
Taken at least once:60.00% of 10
Calls executed:75.00% of 16

File 'cardtest3.c'
Lines executed:92.86% of 28
Branches executed:100.00% of 16
Taken at least once:56.25% of 16
Calls executed:69.57% of 23

File 'cardtest4.c'
Lines executed:66.67% of 81
Branches executed:97.22% of 72
Taken at least once:52.78% of 72
Calls executed:73.68% of 19

File 'unittest1.c'
Lines executed:89.06% of 64
Branches executed:66.67% of 12
Taken at least once:41.67% of 12
Calls executed:83.33% of 30

File 'unittest2.c'
Lines executed:97.73% of 44
Branches executed:100.00% of 2
Taken at least once:50.00% of 2
Calls executed:95.45% of 22

File 'unittest3.c'
Lines executed:92.59% of 27
Branches executed:100.00% of 16
Taken at least once:81.25% of 16
Calls executed:85.71% of 14

File 'unittest4.c'
Lines executed:100.00% of 24
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
Calls executed:100.00% of 14

*/
