/***********************************
* Name: Trent Richardson
* Assignment 3 - coverage1.c
* CS362-400
***********************************/

File 'dominion.c'
Lines executed:36.48% of 562
Branches executed:34.05% of 417
Taken at least once:30.22% of 417
Calls executed:19.79% of 96
Creating 'dominion.c.gcov'

function playSalvager called 54 returned 100% blocks executed 100%
function playVillage called 2 returned 100% blocks executed 100%
function playSmithy called 2 returned 100% blocks executed 100%
function playAdventurer called 2 returned 100% blocks executed 100%
function updateCoins called 72536 returned 100% blocks executed 100%
function gainCard called 270 returned 100% blocks executed 100%
function isGameOver called 12722 returned 100% blocks executed 100%
function fullDeckCount called 71874 returned 100% blocks executed 100%

The testing coverage is about what I expected when beginning this assigment.  I
wanted to test functions that did not rely on too many other functions because
I did not want to get too in-depth with my first unit tests.  The above tests achieved
a line execution of 36.48% and branch execution of 34.05%. These numbers will improve
as more and more functions are tested.  The calls executed is 19.79%, which is fairly
low.  I assume this is due to the functions I chose to test (they did not rely or call
on many outside functions).  I expect my testing to improve the more I work on it.
