James Guera coverage.c


For the code coverage portion of this assignment, I am unsure of the validity of what I found.  

I have the code coverage reports from gcov for each of my unit tests, as well as for dominion.c as a whole,
but nothing where the two are combined.  I had thought the purpose of a code coverage report for a 
test-suite would be to report on the amount of code covererd by the entire suit, ie how much of dominion.c was covered by using
the 8 unit tests,however I was unable to figure out a way  to find that measure.  

For what I do have, the call coverage of each test varies between 66% and 88% of their respective files, with the varience likely due to the number of if statements and on 
the lowest percentage, a loop that exits if a certain value is not found in the hand we are iterating through.  These numbers are relatively high, in part due to the level of 
hardcoding required for the test and the low number of calls required for the simple quality of the testing done.
If user input was required, or a menue given to chose between tests, the coverage percentage would be much lower. 
The branch coverage avoids the issue with if statements and reports on average a much higher percentage, between 85 and 100%.  For these tests, where values returned by functions and 
tests on correct gamestates were desired, branch coverage gives a better metric for code coverage, as it takes into account these types of questions in the code.    

For the dominion.c code coverage, a low, call coverage 27.37% was reported.  This is possibly due to code for functions that are not used, such as the compare function as well as the functions 
created for individual cards in assignment 2 that may not be called by the given game.  Furthermore, the errors purposely coded iinto the code during previous assignemnts might be impacting the
amount of untouched code, for example I removed the shuffle function from one of the cards I altered during a previous assignemnt. 
The branch coverage reported was a bit higher, 45% as it took into acount the many if state,ents throughout the code, which check for things like came state and the cards in the players
hands.   


exact test findings:

cardtest1.c:
Lines executed:85.71% of 28
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:70.00% of 10
Creating 'cardtest1.c.gcov'

cardtest2.c:
Lines executed:82.86% of 35
Branches executed:87.50% of 16
Taken at least once:43.75% of 16
Calls executed:66.67% of 12
Creating 'cardtest2.c.gcov'

cardtest3.c:
File 'cardtest3.c'
Lines executed:78.95% of 38
Branches executed:85.71% of 14
Taken at least once:57.14% of 14
Calls executed:69.23% of 13
Creating 'cardtest3.c.gcov'

cardtest4.c:
Lines executed:82.86% of 35
Branches executed:100.00% of 8
Taken at least once:50.00% of 8
Calls executed:76.92% of 13
Creating 'cardtest4.c.gcov'

results for running unit-tests for functions
unittest1.c:
Lines executed:88.24% of 34
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:84.62% of 13
Creating 'unittest1.c.gcov'

unittest2.c:
File 'unittest2.c'
Lines executed:88.89% of 36
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:85.71% of 14
Creating 'unittest2.c.gcov'

unittest3.c:
Lines executed:87.10% of 31
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:84.62% of 13
Creating 'unittest3.c.gcov'

unittest4.c:
Lines executed:82.35% of 34
Branches executed:100.00% of 8
Taken at least once:50.00% of 8
Calls executed:80.00% of 15
Creating 'unittest4.c.gcov'

code coverage for dominon.c:
File 'dominion.c'
Lines executed:36.74% of 558
Branches executed:45.06% of 415
Taken at least once:27.95% of 415
Calls executed:27.37% of 95
Creating 'dominion.c.gcov'

 

