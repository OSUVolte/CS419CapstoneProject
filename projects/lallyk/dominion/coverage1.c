/********************************************************************
 * Kara Franco
 * coverage1.c
 * Due Date: April 24, 2016
 * ****************************************************************/

/*
Unit Test 1: compare()
	The line execution of unittest1.c was 85.71% with 100% of branches covered. This means that this file
ran each of the 6 branches successfully and half of these branches were taken at least once. 80.00% of 
the calls were executed. This makes sense, since the calls to print FAIL were not given if the test passed,
or vice versa. Within the dominion.c.gcov file, the overall line coverage was 28.65% with only 29.16% of the 
branches executed. The function compare() itself had a 100% line execution with all branches covered. 
  	Upon looking at unittest1.c.gcov file, it is clear that the path that the test took included each branch.
This is good, seeing that we wanted to test each case (< > =). In the dominion file, we see that the coverage of 
the compare function is 100% which helps ensure us that each branch was tested.

Unit Test 2: numHandCards()
	The line execution of unittest2.c was 90.48% with 100% of branches covered. This means that this file
ran each of the 4 branches successfully and half of these branches were taken at least once. 85.00% of 
the calls were executed. This makes sense, since the calls to print FAIL were not given if the test passed,
or vice versa. Within the dominion.c.gcov file, the overall line coverage was 28.65% with only 29.16% of the 
branches executed. The function numHandCards() itself had a 100% line execution with one call to whoseTurn(). 
  	In the dominion file, we see that the coverage of the numHandCards function is 100% which helps ensure 
us that each branch was tested. Upon looking at unittest2.c.gcov file, it is clear that the path that the test took 
included each branch. whoseTurn was called in this function, and the coverage of this function is explained below. 

Unit Test 3: isGameOver()
	The line execution of unittest3.c was 87.18% with 100% of branches covered. This means that this file
ran each of the 10 branches successfully and half of these branches were taken at least once. 80.95% of 
the calls were executed. This makes sense, since the calls to print FAIL were not given if the test passed,
or vice versa. Within the dominion.c file, the overall line coverage was 28.65% with only 29.16% of the 
branches executed. The function isGameOver() itself had a 90% line execution with all 8 branches covered. 
  	Upon looking at unittest3.c.gcov file, it is clear that the path that the test took included each branch.
This is good, seeing that we wanted to test each case that brings the game to an end. This test should be improved.
The test failed (when three non-Province cards are empty, the game continues), and even though the function has 90%
coverage, more tests are needed to see how the game is ending. 

Unit Test 4: whoseTurn()
	The block coverage of unittest4.c was 88% with 100% of branches covered. This means that this file
ran each of the 4 branches successfully and half of these branches were taken at least once. 80.00% of 
the calls were executed. This makes sense, since the calls to print FAIL were not given if the test passed,
or vice versa. Within the dominion.c file, the overall line coverage was 28.65% with only 29.16% of the 
branches executed. The function whoseTurn() itself had a 100% line execution. 
  	Upon looking at unittest4.c.gcov file, it is clear that the path that the test took included each branch.
This is good, seeing that we wanted to test each case of the player's turn. In the dominion file, we see that the coverage of 
the compare function is 100% which helps ensure us that each branch was tested. whoseTurn() works in conjunction with 
numHandCards() and many other functions. So it is vital to ensure that is has no errors. From the tests, we see that it appears 
that whoseTurn() is working correctly, however more tests are needed; such as testing with more players.

Card Test 1: adventurer()
	The line execution of cardtest1.c was 84.38% with 100% of branches covered. This means that this file
ran each of the 8 branches successfully and half of these branches were taken at least once. 80.00% of 
the calls were executed. This makes sense, since the calls to print FAIL were not given if the test passed,
or vice versa. Within the dominion.c.gcov file, the overall line coverage was 28.65% with only 29.16% of the 
branches executed. The function adventurer() itself had a 94% line execution with all 10 branches covered. 
  	Upon looking at cardtest1.c.gcov file, it is clear that the path that the test took included each branch.
This is good, seeing that we wanted to test each case of cards received, cards in deck, victory points earned and 
buys/coins earned. In the dominion gcov file, even though we had 94% line execution in the adventurer function, there are 
still areas that can be tested. For instance we can test if other players have been effected by the card or if cards 
have been removed or added to other decks or piles.

Card Test 2: smithy()
	The line execution of cardtest2.c was 85% with 100% of branches covered. This means that this file
ran each of the 8 branches successfully and half of these branches were taken at least once. 80.00% of 
the calls were executed. This makes sense, since the calls to print FAIL were not given if the test passed,
or vice versa. Within the dominion.c.gcov file, the overall line coverage was 28.65% with only 29.16% of the 
branches executed. The function smithy() itself had a 100% line execution with all 2 branches covered. 
  	Upon looking at cardtest2.c.gcov file, it is clear that the path that the test took included each branch.
This is good, seeing that we wanted to test each case of cards received, cards in deck, victory points earned and 
buys/coins earned. In the dominion gcov file, even though we had 100% line execution in the smithy function, there are 
still areas that can be tested. We can see that the call to shuffle, at line 1284 is never executed. More tests to 
investigate this will be needed.

Card Test 3: village card
	The line execution of cardtest3.c was 78.95% with 100% of branches covered. This means that this file
ran each of the 10 branches successfully and half of these branches were taken at least once. 80.00% of 
the calls were executed. This makes sense, since the calls to print FAIL were not given if the test passed,
or vice versa. Within the dominion.c.gcov file, the overall line coverage was 28.65% with only 29.16% of the 
branches executed. The village case itself was executed and had returned from each of the 2 calls 100%. 
  	Upon looking at cardtest3.c.gcov file, it is clear that the path that the test took included each branch.
This is good, seeing that we wanted to test each case of cards received, cards in deck, victory points earned and 
buys/coins earned. The player never receives a new card. The next tests should look at where the new card goes, if it
is to the other player or not.

Card Test 4: council_room card
	The line execution of cardtest4.c was 78.95% with 100% of branches covered. This means that this file
ran each of the 10 branches successfully and half of these branches were taken at least once. 80.00% of 
the calls were executed. This makes sense, since the calls to print FAIL were not given if the test passed,
or vice versa. Within the dominion.c.gcov file, the overall line coverage was 28.65% with only 29.16% of the 
branches executed. The council_room case itself was executed and had returned successfully from all the calls. 
  	Upon looking at cardtest4.c.gcov file, it is clear that the path that the test took included each branch.
This is good, seeing that we wanted to test each case of cards received, cards in deck, victory points earned and 
buys/coins earned. In the dominion gcov file, we can see that the first for loop branch is taken 80%. This raises a flag.
This case needs more testing, including more tests on how the card is effecting other players and a look into why the player
is only getting 3 cards, rather than 4.
*/