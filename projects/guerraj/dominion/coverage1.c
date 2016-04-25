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

