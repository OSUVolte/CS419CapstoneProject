/**************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 3
* Filename: coverage1.c
* Description: Describes coverage of unittests
*
***************************** COVERAGE ***********************************
* unittest1: Lines executed:17.13% of 648
* This unit test was responsible for testing updateCoins(). This unit
* test did a good job of covering all lines in the function. All line
* were executed 2500+ times. All the branches were also covered for this
* function. Based on the coverage, it appears this unit test is sufficient
* for this function.
*
* unittest2: Lines executed:19.60% of 648
* This unit test was responsible for testing drawCard(). This unit test
* did covered all the non-debugging statements of the function. The majority
* of lines were only excuted 32 times, the exception to this being some loops
* that were executed more times and line 560. 
* line 560: This line is executed when the player's deck is empty and the
* player's discard pile is also empty. A unit test should be added to future
* test suites to accomodate this condition, and ensure a card is not drawn at
* that time.
*
* unittest3: Lines executed:21.91% of 648
* This unit test was responsible for testing discardCard(). Within in the
* discardCard function, there is 100% statement coverage. Most of the lines
* were run over 5000 times, with the exception of the lines for when a
* player has one card left in their hand or if we are removing the last
* card from the player's hand. Some of these runs are most likely due to
* running the cards and not the unittest for this function. Based on the coverage, 
* it appears this unit test is sufficient for this function, but we may want to
* check the coverage of the unit test alone to be sure.
*
* unittest4: Lines executed:25.46% of 648
* This unit test was responsible for testing endTurn(). All of the statements
* in the endTurn function were run, but mostly only 2 times. Both of these
* times are from unittest 4, as no where else in our testsuite do we call
* the function. Since the unit test only ran this function twice, we should 
* add additonal tests to the unit test. This may include having players with
* different size hands, more players, etc.
*
* cardtest1: Lines executed:27.62% of 648
* This unit test was responsible for testing playAdventurer(). Not all
* statements were run within the playAdventurer function. In particular, the
* shuffle function called is the player's deckCount is less than 1 was
* never called. 
*
* cardtest2: Lines executed:28.24% of 648
* This unit test was responsible for testing playSmithy(). All the statements
* in playSmithy were covered by the unit test. The majority of lines
* were run 32 times. Since there are is only one branch, we also have 100% branch
* coverage. That being said, the unit test revealed there is some bugs and we
* should also expect the fixed code to have 100% coverage.
*
* cardtest3: Lines executed:29.17% of 648
* This unit test was responsible for testing playEmbargo(). All but one statement
* of the playEmbargo code was run 60 times. The line that did not run has 
* already been identified as a bug - as the supplyCount is 0 when empty not -1. The
* one branch (an if statement) is never executed, since it is impossible to acheive.
* Once the bug is correct, we should expect 100% branch coverage.
*
* cardtest4: Lines executed:30.86% of 648
* This unit test was responsible for testing playCutpurse(). A majority of the
* statements were run during the unit test - the expections being: 
* 	lines 1388-9: This was a bug incorporated during the refactoring. The unittest 
* populated the other players hands with bronze (what is suppose to be removed), 
* but the refactored code is looking for gold and thus the lines are not executed.
* Even if the refactored code was fixed, there would still be an issue due to the
* way the code is integrated with the endTurn function. Each time a player ends their
* turn their hand is discarded and only the nextPlayers hand is filled. Therfore, at all
* times only the currentPlayer's hand is full. 
*	line 1393-1399: this is if you get to the other player's last card and have 
* not revealed a bronze yet. This is a bug since j will never equal handCount. The
* if statement on line 1391 needs to be changed to if (j == state->handCount[i] - 1)
* If we were to fix the two bugs, then we should expect 100% statement coverage with
* the current test suite. Our unit test covers 100% of the branches - that is if
* there is bronze in the other players hand and if there is no bronze in the other
* players hands. 
*
* Overall, the test suit covered 30.86% of statements. When we take a deeper look at
* each individual test, each does a good job at covering all the statements within the
* function its testing. That being said, there is still a substantial portion of the
* code that has not been covered. Further development of unit tests is recommended to
* gain coverage of these portions.
*
* Other portions of the code to cover:
* gainCard()
* Initializing the code with 3 and 3+ players
* playCard()
* isGameOver()
* getWinners ()
* getCost()
* cardEffect()
* gainCard()
**************************************************************************/