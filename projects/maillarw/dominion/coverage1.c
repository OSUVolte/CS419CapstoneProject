William Maillard
CS 362
Assignment 3

In the Assignment 3 testing suite the folling functions were tested: 
updateCoins(), isGameOver(), scoreFor(), fullDeckCount(), playSmithy(), 
playAdventurer(), playCouncilRoom(), and playVillage().  Gcov was run on the 
dominion.c file after all of these functions were tested and the following 
paragraphs will discuss how well these tests covered both the overall dominion 
code and each of the functions individually.

Overall Coverage
The overall coverage of the dominion.c file is as follows:

File 'dominion.c'
Lines executed:38.16% of 566
Branches executed:39.62% of 419
Taken at least once:35.08% of 419
Calls executed:23.00% of 100

As you can see, the overall lines and branches executed were both just under 
40%.  These values are pretty low, but they make since as the test suite only 
tested eight functions.  Calls executed was very low, at 23%, but again, this 
was just do to only testing eight functions.  In general, I think the coverage 
needs a lot of improvement, but it is reasonable that it was so low because we 
were testing so few functions.

Function Specific Coverage
First we will look at coverage specific to the functions that we tested then we 
we look at other functions that we happened to have gotten good coverage for.

The following data is for functions that we were testing that received 100% 
coverage:

Function 'playCouncil_Room'
Lines executed:100.00% of 10
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 4

Function 'updateCoins'
Lines executed:100.00% of 11
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Function 'scoreFor'
Lines executed:100.00% of 24
Branches executed:100.00% of 42
Taken at least once:88.10% of 42
Calls executed:66.67% of 3

Function 'isGameOver'
Lines executed:100.00% of 10
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Function 'fullDeckCount'
Lines executed:100.00% of 9
Branches executed:100.00% of 12
Taken at least once:100.00% of 12
No calls

Function 'playVillage'
Lines executed:100.00% of 6
No branches
Calls executed:100.00% of 3


As you can see, six out of the eight functions tested had both lines executed 
and branches executed of 100%. This is great coverage and emphasizes how 
thorough the testing suite is.

The following functions were part of the test suite but received less than 100% 
coverage.

Function 'playSmithy'
Lines executed:83.33% of 6
Branches executed:100.00% of 2
Taken at least once:50.00% of 2
Calls executed:66.67% of 3

Function 'playAdventurer'
Lines executed:72.22% of 18
Branches executed:100.00% of 12
Taken at least once:83.33% of 12
Calls executed:100.00% of 3

Interestingly, all of the branches for these two functions were executed while 
about three quarters of their lines were executed.  Therefore, the branch 
execution was great, but the line execution was a little lacking.  The reason 
for this lower line coverage (statement coverage) is due to some of the bugs 
that were introduced in these functions for Assignment 2.  These bugs make it 
impossible (or highly unlikely) that some lines will be executed.

Lastly, the following functions got very high coverage even though they were 
not the functions that were in focus:

Function 'drawCard'
Lines executed:100.00% of 22
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1

Function 'supplyCount'
Lines executed:100.00% of 2
No branches
No calls

Function 'shuffle'
Lines executed:100.00% of 16
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
Calls executed:100.00% of 2

Function 'initializeGame'
Lines executed:95.16% of 62
Branches executed:100.00% of 46
Taken at least once:91.30% of 46
Calls executed:100.00% of 5

Function 'newGame'
Lines executed:100.00% of 3
No branches
No calls

Obviously, these functions were either called by the functions under test or 
they are necessary to game play.  It is interesting to note these functions in 
case they are tested in the future as an addition to the current suite.  If new 
tests are created to test these functions it may be difficult to tell if the 
new tests have good coverage or if it is just a rollover from the tests in this 
suite.


Boundary Coverage

I made the boundary coverage in this suite as high as possible by including 
tests for many boundary conditions in each function.  These conditions included 
empty decks, empty hands, empty discard piles, the maximum and minimum number 
of players, overfull hands, relatively high values for number of actions and 
others.  I tried to keep all values within the realm of the game so as not to 
be ridiculous and useless but close enough to the edge of reason that they gave 
a good representation of the game’s boundaries.

Conclusion

Even though the overall coverage of the dominion.c file was relatively low, I 
think that the coverage (boundary, branch, statement, etc.) of the functions 
specifically being tested was excellent.  Therefore, in regard to coverage, 
this test suite was a success and will make a good start of a complete test 
suite that can be build on this initial design.
