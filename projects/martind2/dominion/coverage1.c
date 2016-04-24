/* Coverage report, assignment 3
 * By Dave Martinez, martind2@oregonstate.edu

  I focused my coverage analysis on parts of the code which I tested. In
  particular, this included the functions:
    * buyCard
    * endTurn
    * isGameOver
    * updateCoins
    * playSmithy
    * playAdventurer
    * playVillage
    * playCouncil_Room

  Using the command-line tool 'sed', I was able to isolate these 
  lines of code from the dominion.c.gcov file and redirect the output
  to the unittestresults.out file. 

  Statement coverage of my tested functions was nearly complete. I did
  find one line that did not execute. playCouncil_Room (lines 1347-1373)
  failed to execute the 'drawCard' function for each other player. This
  was picked up by my test suite and was one of the bugs I introduced 
  during a previous assignment.

  Otherwise, it appears that all other areas of concern gathered by this
  assignment were executing. Branch coveregae seemed to be at 100% for my
  tested functions.

  I did find numerous bugs, mostly of my own introduction. I commented
  my test suite's 'assert' function to allow the suite to gather accurate 
  coverage information. 

*/