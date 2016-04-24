/******************************************************************************
** coverage1.c 
** Emily Snyder
** Spring 2016
** CS 362-400
** Discusses coverage provided by test suite.
*******************************************************************************

unittest1.c - getCost()

	getCost() should return the correct cost in coins for the card that is
	passed as a parameter. The tests compare the cost returned by the function
	to the costs given at http://wiki.dominionstrategy.com/.

  All tests pass successfully.	
 
  GCOV
		Function 'getCost'
		Lines executed:100.00% of 30
		Branches executed:100.00% of 28
		Taken at least once:100.00% of 28

  Since all the costs returned for all cards are tested, these tests provide
  100% coverage of the function.




endTurn (line 350)
  
  Requirements:
	 - After discard all cards in the hand of the current player should be set to
     -1
   - After discard the current player's hand count should be 0
   - All other players hands should be zero before and after (draw at the end
     of the the player that comes prior's turn)
   - Current player should be set to the next player
   - Beginning of next player's turn
       - 1 action and 1 buy allowed per rules
       - hand count should begin at 0 and be 5 after, all other players hand 
         counts should remain 0.
       - state->coins should be 0 before hand and not zero after ?

isGameOver (line 390)

  Requirements:
   - All Province cards are used up or three supply piles are 0 game is won
   - Otherwise game is not over

discardCard (line 1047)

  Requirements:
    - If a card is played not trashed, the played card count increases and it
      is added to the playedCards array
    - The card at the current position is changed to -1 and the hand count is
      decreased. No other players' hand counts should change (from 0)
    - If there are more cards in the hand, the new card at the same position
      should not be -1

gainCard (line 1085)

  Requirements:
    - supply count must be >= 1
    - Card should go to discard, the deck or the hand of the current player,
      depening on the flag used. The locations not indicated should not be 
      affected.
    - Number of cards in the supply file should decrease by one when the card
      is moved to a different location.



Write unit tests for four Dominion cards implemented in dominion.c.  These tests 
should be checked in as cardtest1.c, cardtest2.c,cardtest3.c, and cardtest4.c. 
(For example, create a test for smithy card.). It is mandatory to test smithy 
and adventurer card. 

Execute your unit tests and describe any bugs you find in a file named bug1.c. 

Use gcov to measure code coverage for all of these tests. Report your findings 
by discussing your tests' coverages (statement, branch, boundary, etc.), and 
describe their implications for the tests in a file called coverage1.c, also 
checked in to your dominion directory. I want you to look at the dominion code 
coverage and find out what parts of your code are not covered so that in future 
you can improve your test suite. 

Add a rule in Makefile that will generate and execute all of these tests, and 
append complete testing results (including % coverage) into a file called 
unittestresults.out. The rule should be named unittestresults.out and should 
depend on all your test code as well as the dominion code. The .out files 
contain the output of your running tests and coverage information. Basically 
.out file should act as a proof that your tests run correctly and you collected 
coverage information correctly.
Note: we prefer to run a single command "make unittestresults.out". This command 
should do everything. Compile all 8 tests, execute them, add any output 
information to unittestresult.out file,  collect coverage information and append 
it to the unittestresult.out file.

Update your refactor.c  file of Assignment 2 with some information about the 
bugs that you introduced in Assignment 2 in case you have not done it already 
and resubmit the file.

