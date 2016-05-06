/************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  randomhistory.c
** Date:  4/28/16
** Due Date: 5/1/16
**
** Description:  This is a text file that is will be used to 
** document the development of our two random testers
**		1. randomtestcard.c
**		2. randomtestadventurer.c
** Per the assignment requirements:
** "Write up and check in the development of your random 
** testers, including improvements in coverage and effort to 
** check the correctness of your specification, as 
** randomhistory.c. Be detailed and thorough!"
*************************************************************/

//Development of My Random Testers

/*
In order to develop my random testers I first started by taking a look at
betterTestDraw card which was provided in our base dominion folder.  This gave
me the framework for developing a way to randomize the deckCount, handCount, and 
discardCount for multiple players in order to initialize a random gameState before 
making a call to both adventurer and great_hall card effects.  I then adapted the
conditional source code from my original unit tests from assignment three to test
each random gamestate.  Once I was able to run my tests, I discovered the expected
issues/bugs that I had implemented (SEE refactor.c).

After the implementation of the randomtestadventure, randomtestcard was fairly simple
as I was able to use a lot of the same source code, in addition to once again use the 
unit test conditional statements that I had used to test the great_hall card from
assignment three.  The random test was able to reveal the bug that I introduced regarding
that the discard card was trashed instead of left instead of being recycled into the player's
hand.

When testing adventurer 1000 times randomly, I ran into a bug which happened at a
rate of approximatly 1 in 1000 with each test run.  Since it was difficult to find the bug in
my randomtestadventure.out file, I decided to both capitalize the printf return statement
for that specific failure, and also add a few extra print statements to further
familiarize myself with what was going on with that specific iteration of the random
test.  I found that this specific bug arose when the deckCount for the currentPlayer
was set to 0.  This would result in no cards being able to be drawn, which would yield 
no decks being changed after the card effect versus a typical "one" deck being changed.
I think that this is more of an issue with my test code wrather than the source code.
This gave me insight to how I could change my randomtestadventurer.  Instead of looping 
through all player, I only chose to loop through the remaining players to check for any
changes.  This was a logical change, that I probably should have realized initially.
*/


//Coverage Analysis of Random Testers

/*
Here is the functional coverage for the randomtestadventurer and randomtestcard tests 
respectively.  I chose to compare them to the card unit tests from teh previous 
assignment to see if my random approach yielded equivalent/improved coverage.

RANDOM
Function 'adventurerFunction'
Lines executed:100.00% of 18
Branches executed:100.00% of 12
Taken at least once:91.67% of 12
Calls executed:100.00% of 2

UNIT
Card Test 2:
Function 'adventurerFunction'
Lines executed:72.22% of 18
Branches executed:66.67% of 12
Taken at least once:50.00% of 12
Calls executed:100.00% of 2

As you can see, the randomtestadventurer had much improved coverage compared to its'
unit test counterpart.  Through testing I found that the randomtestadventurer had both
better line and branch coverage.  This does by no means imply that one test would find 
more bugs, but may increase the probability that the random test would cover a piece of 
code which may contain a bug.

RANDOM
Function 'great_hallFunction'
Lines executed:100.00% of 5
No branches
Calls executed:100.00% of 2

UNIT
Function 'great_hallFunction'
Lines executed:100.00% of 5
No branches
Calls executed:100.00% of 2

In terms of the great_hall card effect coverage, both methods random/unit were able to
achieve 100% line and branch coverage.  This shows that for a simple case such as 
great_hall, there may not be a need for adapting my testing to a more processor heavy 
random test.  But to be safe...why not?; As implementation was fairly easy once I had
a method, a lot of copy paste.
*/