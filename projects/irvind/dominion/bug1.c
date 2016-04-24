/*---------------------------------------
* Brett Irvin
* 4/20/16
* CS362_400 Software Engineering II
* Assignment 3--bug1.c
* Describes any bugs found in Assignment 3.
*---------------------------------------*/
Unit test 1, updateCoins function:
With the updateCoins function, I focused primarily on testing the three Treasure cards.  All of the tests I performed were successful; however,
my implementation is fairly short and simple, and there's other aspects of updateCoins that could be tested as well.  The tests I have in unittest1
address the most common use cases of Treasure cards, but again, there's still plenty of room for further testing, especially when considering edge
cases.

Unit test 2, shuffle function:
I tried several different approaches to testing the shuffle function.  At first, it didn't seem to be working correctly.  Every time 
I ran the unit test, both players ended up with the same deck before and after calling the shuffle.  I went back and looked over my refactor.c
file to make sure this wasn't a bug I had inadvertently introduced as part of an earlier assignment, but that didn't seem to be the case.  With 
the unit test as it is now, it appears to shuffle the deck, but doesn't do so at random.  Both Player 1 and Player 2 end up with the same card 
order after calling the function, which can't be correct. 

Unit test 3, isGameOver function:
I didn't notice any bugs in the isGameOver function.  All of the conditions that were defined in dominion.c caused the correct game over outcome
when tested in this unit test.  I'm not sure that I correctly tested whether or not running out of both duchy and estate cards will end the game.
It passes that test (which it should), but it may be a fluke since I'm not sure   

Unit test 4, numHandCards function:
After testing, I didn't notice any obvious bugs in numHandCards.  However, the tester is set up where it would be easy to run additional tests if
you wanted to do a brute-force approach. All that is needed is to increase the stop value in the for loop.  


**Note: When implementing cardtest2.c during Assignment 3, I ended up having to undo one of my deliberate bugs from an earlier assignment (described
in refactor.c).  The bug I had created instantly caused a segmentation fault whenever the adventurer card was called.  Since my card tests wouldn't
run at all with that fault, I removed it so that Assignment 3's tests could execute.