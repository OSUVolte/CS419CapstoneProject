My unittest's covered a fair portion of the code however I would argue a considerable amount of work remains. First the coverage 
stats from gcov indicated that all 8 unit tests 40.71% of the code and 46.76% of all the brances were taken. This is probably respectable for 
the 8 unit tests that I ran however it clearly missed a fair bit of code. 

First I looked at the unit tests I ran to get a better idea of what I missed in here than i went on to the rest of program. 

Unit 1 Tests: Update Coins evaluated every line and branch in the unit test was also passing the tests. 

Unit 2 Tests IsGameOver:  Isgameover evaluated almost every line and branch of code.  While this doesn't indicate it is error free, it does provide added confidence it will run
smoothly during operation. 

Unit 3 Tests Scorefor:   This test didn't evaluate every branch and line of code in operation.  It left out a few options in the garden scoring method and a few other branch conditions. It also
failed its unit tests.  This is a function which most likely has a bug in it as I detailed in the bug report. The unit tests should be expanded and the bug reported to the developer. 

Unit 4 Tests GetWinner:  This test touched almost every line of code however a few branches related to number of players did not get called and few lines of code too.  The unit tests passed but if the owner 
wanted 100% percent branch coverage we would have to go back to this unit test. 

Cardtest 1 Adventurer Tests:      GCOV showed that not every line of code and several branchs was executed here.  The unittests failed so and a bug was likely present here.  This could be a unit test
we may want to expand in the future just from the presence of bugs.  

Cardtest 2 Smity Tests:  This was a test that ultimately failed and has some serious bugs in it (by my design per assigment1).  The unit tests caught these failures and GCOV showed that we 
touched every line of code and branch. Because of the error, it would have to go back to the developers and the test rerun.  

Cardtest 3 Village Tests:  This was a unit test that passed with no errors. Using GCOV we see that every line of code was touched and every branch was taken. 

Cardtest 4 Great Hall Tests: This unit test was relatively simple and it covered every branch and line of code. Every unit test passed succesfully which indicates this function will likely function. 
The card itself was only a few lines of code. 


These tests as stated above covered only 40% of the code which by itself isn't a great surprise with only 8 tests.  In order to improve coverage for future tests, we can add a little bit more for the units tests
for scorefor and adventurer to start. A better measure would be to evaluate more card effects as  I only covered 4 here (smithy, adventurer, village and great hall).  Dominion has numerous other cards that are used in the card effect statement 
so that is first and foremost a area for future testing to concentrate on. GCOV revealed that outside of those 4 cards involved in unit testing, the rest were not even touched or evaluated.

The unit tests for functions could also be expanded greatly again with only 4 functions being evaluated directly. GCOV revealed that a number of these functions were at least touched
to some degree. For example the intialize game function while not a specific unit test had partial coverage but left a number of branch statements unevaluated.  This was true for a number
of functions in the program. Other functions like Playcard, buycard, newGame were never run. This is where some major holes in the program lie. 

In summary, the unit tests covered around 40% of the code involved with dominion.c.  To improve this coverage, we need to cover more card effects, and a number of the functions involved with the game. 



