/***************************************************************************************************************************************
* Description of the coverage achieved in random tests of dominion code
*
* A random test case generator was used to generate the test cases.  The 
* function to intialize a random game performs this task.  It assigns random values to the following game attributes
* A random number of players (between 0 and MAX_PLAYERS)
* A random player (between 0 and MAX_PLAYERS -1)
* A random deck size (between 0 and MAX_DECK)
* A random discard deck size (between (MAX_DECK - decksize) and 0)
* A random hand size (between MAX_HAND and 0)
* A random deck
* A random discard deck
* A random hand
* A random card position in the hand

  A test oracle function is used to test for no unexpected changes in game state. It tests for no unexpected changes
* of the victory card deck for the active player, tests for no unexpected changes in the deck for the active player, no 
* unexpected state changes to the unactive player's deck, discardDeck, and hand.  The game state is also tested
* for no unexpected changes in the the hand count, deck count, discard deck count, played card count, and that
* the proper card was discarded properly.  The test oracle function calls the card effect function and then calls the mock
* card effect function.  The mock card effect function changes a games state struct as I would expect the correct call
* to the card to change the game state.  The two game states are then compared for unexpected changes.  I can say that
* when a test case fails using random testing it ussually requires more thought to try and understand why the test case
* is failing.  This is due to the random test case generators ability to find edge cases that produce unexpected results.
*
* randomtestadventurer
*
* Discussion:
*
* The randomtestadventurer program ran 300000 tests and found 10 bugs.  Bug 1 indicates the the hand counts should be the 
* same, this test fails because the adventurer card is not being discarded properly.  Bug 2, is triggered if the deck
* counts are off, this error is triggered because of a bug introduced into the adventurer card where an equality 
* statement is changed to an assignment statement.  Bug 3 shows the discard counts are different, this is related to 
* Bug 2. Bug 4 tests the played card counts are the same, this is related to Bug 1.  Bug five tests the card at the proper
* position is being discarded, again this is related to bug 1.  Bug 6 tests that the hands are the same, this fails due
* Bug 2.  Bug 7 tests that the discard counts are the same, again this fails from Bug 2.  Bug 8, test 11 fails due to Bug 2, where
* some Victory cards are being assigned to gold. Bug 9 this is from test 9 failing saying that the hand count is off for one of 
* the other players, this is unexpected, and needs to be investigated further.  Bug 10 shows that the dominion cards have changed,
* again this is related to Bug2.
*
* Code coverage randomtestadventurer:
* 
File 'randomtestadventurer.c'
Lines executed:91.48% of 176
Branches executed:89.06% of 128
Taken at least once:76.56% of 128
Calls executed:87.30% of 63
Creating 'randomtestadventurer.c.gcov'
*
* The code coverage shows that 91.48% of the lines were executed and 89.06% of the branches were executed.  By examining the 
* randomtestadventurer.c.gcov file it shows some unexecuted print statements in the code. The code that is not executed
* is related to notification of passed test cases.  Since all of the test cases failed this is the expected outcome.
*
 randomtestcard
*
* Discussion:
* The randomtestcard program tested the smithy card.  Using random testing the program found 3 bugs on 300000 tests.  Bug1, test 
* 4 failed which tests that played card counts are the same, this may be related to the bug that was introduced into the smithy code.  
* The bug sets the destroy flag for the card to be discarded and results in the card being removed from the deck.  Bug 2, test 5 failed  
* indicating that the card was not removed from the players hand properly.  Bug 3, test 7 fails which indicates that there is an  
* unexpected change somewhere in the game state.  It's unclear where this error is occuring and needs to be investigate closer.  
* It's possible that one of the functions that smithy is calling is failing and needs to be investigated.
*
* Code coverage randomtestcard:
*
File 'randomtestcard.c'
Lines executed:78.98% of 157
Branches executed:84.91% of 106
Taken at least once:60.38% of 106
Calls executed:70.00% of 60
Creating 'randomtestcard.c.gcov'
*
* The code coverage shows that 78.98% of the lines were executed and 84.91% of the branches were executed.  Examination of the 
* randomtestcard.c.gcov file shows that most of the unexecuted lines of code are related to test cases that do not fail.  A large
* number of these lines are in the noPlayerStateChanges function.
* Code coverage dominion:
*
File 'dominion.c'
Lines executed:40.39% of 567
Branches executed:46.76% of 417
Taken at least once:41.49% of 417
Calls executed:22.11% of 95
Creating 'dominion.c.gcov'
*
* The code coverage shows that 40.39% of the lines were executed and 46.76% of the branches were executed. This is an improvement
* from the unit tests where 35.21% of the dominion.c code was executed and 37.65% of the branches were executed.  This I think
* demonstrates the power of random testing in finding edge cases that unit testing does not find as easily.
