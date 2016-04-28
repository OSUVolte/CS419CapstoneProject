/******************************************************************************
* ASSIGNMENT 3 - bug1.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 04/24/2016
* NOTES: bug discussion for Assignment 3
******************************************************************************/

/******************************************************************************
* unittest1 - discardCard()
*
* All tests here appeared to be normal, however, my coverage here is 
* not all it could be in actuality. The test I wrote does not actually
* check to make sure that the cards discarded are shuffling into order
* correctly.
******************************************************************************/

/******************************************************************************
* unittest2 - fullDeckCount()
*
* Either I made a mistake here, or something is seriously wrong with this
* function. I strongly suspect it is my mistake. Counts were almost always
* discrepant.
******************************************************************************/

/******************************************************************************
* unittest3 - scoreFor()
* 
* I was unable to get gardens to calculate their scores correctly without 
* calling fullDeckCount(). I abstained from doing this because there is still
* a possibility (unlikely though it may be) that I did have the tail end of 
* a bug in it, and calling it would further muddy the water.
******************************************************************************/

/******************************************************************************
* unittest4 - updateCoins()
* 
* This was the most comprehensive test because I built off the instructor's
* examples and added my own. There were no bugs found here.
******************************************************************************/

/******************************************************************************
* cardtest1 - playSmithy()
* 
* I was able to catch the bug I introduced in my refactoring, which gave too
* many cards.
******************************************************************************/

/******************************************************************************
* cardtest2 - playAdventurer()
*
* I was able to catch the bug I introduced in my refactoring, which caused
* the function to disregard the discard pile.
******************************************************************************/

/******************************************************************************
* cardtest3 - playCouncilRoom()
*
* I may have found a bug that I did not introduce. This refactor was bug-free
* (or so I thought). Somehow the discard numbers here are always discrepant.
* It appears that the council room is not being discarded correctly, though
* an inpsection of the code reveals no clues as to why.
******************************************************************************/

/******************************************************************************
* cardtest4 - playSalvager()
*
* I was unable to catch the bug I introduced through refactoring. I believe
* the bug I introduced (not checking for a chosen discard card) may actually
* crash the game once it's tripped, and it will be difficult to catch.
******************************************************************************/