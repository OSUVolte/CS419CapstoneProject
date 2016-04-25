/***********************************
* Trent Richardson
* Assignment 3 - bug1.c
* CS362-400
***********************************/

unittest1.c: updateCoins()
     No bugs detected.

unittest2.c: isGameOver()
     I struggled with the amount of cards checked for isGameOver().

unittest3.c: fullDeckCount()
    No bugs detected.

unittest4.c: gainCard()
     No bugs detected.

cardtest1.c: playSmithy()
     The card test found the introduced bug where the for loop begins at
     1 rather than 0, which only adds 2 cards instead of 3.


cardtest2.c: playAdventurer()
     I was hoping that this one would find an error with my refactored code; however,
     for some reason, it does not recognize that there is an error with drawing
     three treasure cards (introduced error) instead of the intended two cards.


cardtest3.c: playSalvager()
   To test this, I moved it to the refactored code section; however, I did not alter
   the code.  I had a number of tests fail; however, I did not have the time to fully
   investigate if the failed tests were due to my testing error or something else.

cardtest4.c: playVillage()
     This test did find the introduced bug from my refactored code where the
     number of actions is four instead of the intended two.
