/*
Brandon Swanson
Assignment 3
Coverage report of unit and card tests

All of my tests had 100% branch and line coverage, This is particularily
because I was devloping the tests in a 'white-box' fashion and evaluated all
possible branches and created test cases to trigger them.
After examining the coverage results I did make changes to the playAdventurer 
test file, I wanted to be able to carefully examine if the function had
correctly drawn and discarded cards until 2 treasure cards had been found, but
these test cases did not invovle the branch of playAdventurer that required
shuffling the discard pile back into the deck.  To cover that branch, I added
tests that moved most of the draw deck into the discard pile and would cause a
shuffle in some of the calls to playAdventurer.

As has been pointed out in lectures, 100% line and branch coverage does not 
mean that the code is bug free,  there are of course the bugs I introduced in
assignment 2 and some of these tests reveal them.  There are however other bugs
that had be left undected by these test cases because they either led to
infinite loops or segmentation fault (and all of the unit tests needed to run
in sequence).

There are other bugs in the code not introduced by me that were not
discoverable simply by having 100% code coverage.  My first implementation 
of the endTurn unit test was based on examining what the function purpoted to
do and testing that it accomplished all of those correctly.  But it was also
important to look at important functions it was not executing that the rules of
the game dictated should be occuring.  The function was not moving the cards
in the playedCards array back to the players discard.  This bug was not found
only through achieving 100% coverage but also by carfully designed tests.


----------------------------------------
File summary
----------------------------------------
File 'dominion.c'
Lines executed:35.96% of 570
Branches executed:25.90% of 417
Taken at least once:23.74% of 417
Calls executed:25.49% of 102

----------------------------------------
Unit Test 1 shuffle()
----------------------------------------
Function 'shuffle'
Lines executed:100.00% of 16
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
Calls executed:100.00% of 2


----------------------------------------
Unit Test 2 drawCard()
----------------------------------------
Function 'drawCard'
Lines executed:100.00% of 22
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1


----------------------------------------
Unit Test 3 endTurn()
----------------------------------------
Function 'endTurn'
Lines executed:100.00% of 20
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 3


----------------------------------------
Unit Test 4 gainCard()
----------------------------------------
Function 'gainCard'
Lines executed:100.00% of 13
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 1


----------------------------------------
Card Test 1 playSmithy()
----------------------------------------
Function 'playSmithy'
Lines executed:100.00% of 7
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 3


----------------------------------------
Card Test 2 playAdventurer()
----------------------------------------
Function 'playAdventurer'
Lines executed:100.00% of 20
Branches executed:100.00% of 12
Taken at least once:100.00% of 12
Calls executed:100.00% of 4


----------------------------------------
Card Test 3 playVillage() 
----------------------------------------
Function 'playVillage'
Lines executed:100.00% of 7
No branches
Calls executed:100.00% of 3


----------------------------------------
Card Test 4 playCouncil_Room()
----------------------------------------
Function 'playCouncil_Room'
Lines executed:100.00% of 12
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 4

*/
