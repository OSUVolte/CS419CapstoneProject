/********************************************************************************************************************************************************
*** Filename: coverage1.c
*** Author: Aleksandr Balab
*** Class: CS362-400
*** Spring 2016
*** Assignment 3
*** Description: Report your findings by discussing your tests' coverages (statement, branch, boundary, etc.), and describe their implications
***              for the tests in a file called coverage1.c, also checked in to your dominion directory. I want you to look at the dominion code coverage
***              and find out what parts of your code are not covered so that in future you can improve your test suite.
*******************************************************************************************************************************************************


/*
dominion.c coverage:

Lines executed:33.57% of 563
Branches executed:38.61% of 417
Taken at least once:25.42% of 417
Calls executed:26.32% of 95

----------------------------------------------------------------------
cardtest1- lines executed:95.83% of 24 Branches executed:100.00% of 10
cardtest2- Lines executed:100.00% of 24 Branches executed:100.00% of 8
cardtest3 -Lines executed:100.00% of 26 Branches executed:100.00% of 10
cardtest4 -Lines executed:96.43% of 28 Branches executed:83.33% of 12
unitest1 - Lines executed:92.31% of 39 Branches executed:100.00% of 14
unittest2 -Lines executed:96.97% of 33 Branches executed:100.00% of 20
unittest3 - Lines executed:96.15% of 26 Branches executed:100.00% of 10
unittest4 - Lines executed:97.83% of 46 Branches executed:100.00% of 18

In terms of dominion code coverage, the unit tests and card tests did well. Getting close to 100% statement and branch coverage
for the chosen functions and card effects except for Salavager card since i've implemented test on  the number of cards and
never checked for the card selection ( the one to be trashed from your hand). 

As per dominion.c. The Lines exectured - 33.57% and branches executed -38.61% is what one should expect based on the unittests since
we are teting the funtions directly withouth the dependant functions. This would just give us a small window on what is happening in 
those specific funtions. So 30-40% is what one should expect just based on the amount tests performed. 
The calls executed follows the same explanation - the more unittests one has the more likely that all the calls to other functions will
be exectuded. 


*/

