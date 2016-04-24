/************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  coverage1.c
** Date:  4/23/16
** Due Date: 4/24/16
**
** Description:  This is a text file that will discuss the 
** coverage of my unit/card tests and the implications of
** said coverage (statement, branch, boundary).
*************************************************************/

//NOTE:  There was some disagreement about this part of the assignment in the forums
//I will be as thorough as possible to cover all my bases.

/*
First of all, the assignment 3 part 4 requirements were somewhat vague in terms of
what coverage we should be report/be looking at.  I decided to look at the coverage of each
unittest.c / cardtest.c file and found it to be fairly useless. A lot of my unit/card test.c 
files include many conditional statements that were PASS / FAIL in nature; meaning that the 
coverage when running the unit tests would never really yield a high percentage. Nor would I
want it too.  As a semi-PASS FAIL result is not practical. This encouraged me to ask the question,
"Why would I even be interested in this?" This lead me to the realization that this was not the coverage that this section of Assignment 3
was looking for. Woops.

Overall, the goal of this section was to look at the coverage that is obtained from running your
tests on dominion.c.  "Wow, I make dumb mistakes sometime."  Either way, i felt the best way to 
look at the coverage that my unit/card tests had over dominion.c was to look at the functional 
coverage.  The reason for this is because we were only tasked with testing 4 internal functions
and 4 cardEffects implementations.  This left a of source code that was out of our "focus" during
the assignment.  The overall line and branch coverage for dominion.c was 36.43% and 35.73% respectively.
If I was testing the entire dominion.c this would be very poor coverage.  However, since we were
only responsible for partial testing, these values cannot be considered poor.

Either way, when looking at line and branch coverage for the functions/cards that I was testing.
These were my respective results:

Unit Test 1:
Function 'initializeGame'
Lines executed:98.39% of 62
Branches executed:100.00% of 46
Taken at least once:95.65% of 46
Calls executed:100.00% of 5

Unit Test 2:
Function 'getCost'
Lines executed:100.00% of 30
Branches executed:100.00% of 28
Taken at least once:100.00% of 28
No calls

Unit Test 3:
Function 'updateCoins'
Lines executed:100.00% of 11
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Unit Test 4:
Function 'isGameOver'
Lines executed:100.00% of 10
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Card Test 1:
Function 'smithyFunction'
Lines executed:100.00% of 6
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 2

Card Test 2:
Function 'adventurerFunction'
Lines executed:72.22% of 18
Branches executed:66.67% of 12
Taken at least once:50.00% of 12
Calls executed:100.00% of 2

Card Test 3:
Function 'great_hallFunction'
Lines executed:100.00% of 5
No branches
Calls executed:100.00% of 2

Card Test 4:
Function 'embargoFunction'
Lines executed:100.00% of 7
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 1

In terms of line coverage, 6/8 tests resulted in 100% functional coverage for the
functions they were designed to test.  1/8 had 98.39%, and the last test (Adventurer)
had a line coverage of 72.22%.  In general, this showed that my tests as a unit performed
well in terms of covering each line.  This also showed that my test for the Adventurer card
may require some additional work.  Keep in mind, this by no means leads me to the conclusion
that my tests are correct and will reveal all bugs.  Only that my tests touched on a lot of
source code that they were supposed to.

In terms of branch coverage, my tests also performed quite well when considering the functions
that tey were designed for.  7/8 tests had 100% branch coverage; and once again the test for
the Adventurer card had the worst coverage of 66.67% (Once again, reinforcing teh notion that my
test may require some more thought).  Regardless, the overall branch coverage of my test suite 
was acceptable.  

In order to address boundary coverage.  You'd have to look at the test cases that I used when
designing my unit/card tests.  In general, for test that I expected to fail, I chose values that
were close to a value that would succeed.  This would improve my boundary coverage.  For example,
in the unittest1: isGameOver(), I created and initialized a gameState and then modified the state to 
include two empty supply piles knowing that three would end the game.  I tested to make sure that then
function would return zero (game continues), and it PASSED.

Now, even though the overall coverage of dominion.c is not as important for this particular assignment,
it helps to give me an idea of what other functions I may want to include in the future, as some of the
functions were covered, by running my unit tests for my functions of choice (i.e discardCard/drawCard).  
A list of the functions in dominion.c that were sparsely covered are listed below. I developed this list 
based on the dominion.c.gcov file that is appended to my unittestresults.o file. I looked at functions
with poor coverage that had a lot of lines.

Functions That Could Possibly Use Some Future Testing
_____________________________________________________

1. EVERY Card / cardEffect() that was not chosen as a card test
2. gainCard()
3. getWinners()
4. scoreFor()
5. endTurn()
6. fullDeckCount()
7. buyCard()
8. playCard()
9. shuffle()

This ends my discussion.  Enjoy.
*/
  