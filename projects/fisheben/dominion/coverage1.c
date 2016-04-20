/***************************************************************************************************************************************
* Description of the coverage achieved in unit tests of dominion code
*
* Note: Every funtion is tested with 2 players.  Each function is tested for no unexpected changes in 
* the victory card deck for the active player, no unexpected changes in the deck for the active player, no 
* unexpected state changes to the unactive player's deck, discardDeck, and hand.  The notes below discuss the
* additional tests that were conducted.
* 
* File 'unittest1.c'
* Lines executed:65.44% of 136
* Branches executed:83.67% of 98
* Taken at least once:46.94% of 98
* Calls executed:39.53% of 43
* Creating 'unittest1.c.gcov'
* Discussion: unittest1.c tests the updateCoins function.  The statement coverage of the test is 65.44%
* This low coverage reflects the fact that no bugs were found and due to this the print function (which is fairly large) was
* not executed.  The branch coverage is better at 83.67%, this more representative of the coverage as the print function
* has no branches.  Boundary cases tested in unittest1 are testing hands with a range of bonus coins from 0 to 10. It also tests the case 
* with no treasure cards in the players hand, another case where the player has no cards at all in hand or deck or discard deck.
* In both these cases the coins in the post call should equal the bonus coins.  Lastly the code tests 3 different max hands of gold, 
* silver and copper, to make sure the coins are summed properly.
* 
* File 'unittest2.c'
* Lines executed:66.90% of 142
* Branches executed:84.62% of 104
* Taken at least once:45.19% of 104
* Calls executed:36.59% of 41
* Creating 'unittest2.c.gcov'
* Discussion: unittest2.c tests the drawCard function.  The statement coverage of the test is 66.90%
* This low coverage reflects the fact that no bugs were found and due to this the print function (which is fairly large) was
* not executed.  The branch coverage is better at 84.62%, this more representative of the coverage as the print function
* has no branches.  Boundary cases tested in unittest2 are drawing a card from an empty deck and empty discard deck.  This ensures 
* that no additional cards are drawn.  Drawing a card from a empty deck but and a non empty discard deck.  This tests that the cards in 
* the discard deck are properly shuffled back into the deck before a card is drawn.  Lastly the code tests for a game state with cards in deck
* and cards in discard deck, and looks for any unexpected game states pre and post call.
*
* File 'unittest3.c'
* Lines executed:70.18% of 114
* Branches executed:75.56% of 90
* Taken at least once:47.78% of 90
* Calls executed:57.50% of 40
* Creating 'unittest3.c.gcov'
* Discussion: unittest3.c tests the discardCard function.  The statement coverage of the test is 70.18%
* This low coverage reflects the fact that only 1 bug was found.  The branch coverage is better at 75.56%, and it's value
* reflects that only one bug was found, some branches and statements are triggered from a finding bugs that are not executed.  Boundary cases tested
* in this unit test; different hand sizes from 1 to 10, different values for the trash flag, and different positions of the card to
* be discarded in the hand, from the 1st position to the last position in the hand.  The code then tests for no unexpected game states, correct hand
* count, and that the correct card was discarded.  The bug that was found was from the discardCount not being incremented after the call to 
* discardCard to reflect a card was discarded.
* 
* File 'unittest4.c'
* Lines executed:70.45% of 132
* Branches executed:100.00% of 70
* Taken at least once:75.71% of 70
* Calls executed:35.14% of 37
* Creating 'unittest4.c.gcov'
* Discussion: unittest4.c tests the getCost function.  The statement coverage of the test is 70.45%
* This low coverage reflects the fact that no bugs were found and so the cases and statements in which errrors are found are not executed.  
* The branch coverage is perfect at 100.00%, this more representative of the coverage as the print function
* has no branches but many statements.  Boundary cases tested in unittest4 are getting the cost of all the possible cards and then comparing the values 
* returned with a local copy of the correct values.  Unfortunately this will not test any new cards added at a later time.  It would be better if the 
* card values were stored in a static constant array so that any changes could be tested in the future.
* 
* File 'cardtest1.c'
* Lines executed:56.19% of 105
* Branches executed:91.18% of 68
* Taken at least once:51.47% of 68
* Calls executed:27.50% of 40
* Creating 'cardtest1.c.gcov'
* Discussion: cardtest1.c tests the smithy card.  The statement coverage of the test is a very low 56.19% coverage.
* This low coverage reflects the fact that no bugs were found and so the cases and statements in which errrors are found are not executed.  
* The branch coverage is very good at 91.18%, this more representative of the coverage as most branches are executed but few error functions 
* are called.  Boundary cases tested in this card test, different hand sizes from 1 to 10, and different positions of the card to be
* discarded in the hand, from the 1st position to the last position in the hand.  The unit test then looks for the correct number of cards and
* that the smithy card was discarded properly after it was played.
*
* File 'cardtest2.c'
* Lines executed:82.61% of 161
* Branches executed:73.58% of 106
* Taken at least once:49.06% of 106
* Calls executed:73.08% of 52
* Creating 'cardtest2.c.gcov'
* Discussion: cardtest2.c tests the adventurer card.  The statement coverage of the test is 82.61% coverage reflecting lots of bugs found.
* This higher coverage reflects the fact that bugs were found and so the cases and statements in which errrors are found are executed.  
* The branch coverage is 73.58%, this is reflective of most of the unittests that have been analyzed in this discussion and seems to be the
* normal average.  Boundary cases tested in this card test, all treasure decks are tested using all gold deck, all silver deck and a all copper
* deck.  This tests that no cards are discarded and the correct hand count is found (should've also tested correct cards are added to hand but
* this wasn't done here).  The unit test then tests that the adventurer card is discard properly, this test fails and influences some of the 
* game state tests.  The next test is to see if the a deck with two treasure cards at the start of the deck will execute properly, ie all cards
* should be added to the discarded deck.  This test also fails, due to a bug I introduced into the adventurer card.  The final test is to test
* a deck with no treasure cards, this test again fails due to the bug that was introduced in the the adventurer card.  I noticed that the adventurer
* card implementation will enter an infinite loop if the deck has no treasure cards, this needs to be addressed.
* 
* File 'cardtest3.c'
* Lines executed:54.87% of 113
* Branches executed:82.50% of 80
* Taken at least once:45.00% of 80
* Calls executed:23.81% of 42
* Creating 'cardtest3.c.gcov'
* Discussion: cardtest3.c tests the village card.   The statement coverage of the test is 54.87%
* This low coverage reflects the fact that no bugs were found and so the cases and statements in which errrors are found are not executed. 
* The branch coverage is better at 82.50%, this more representative of the coverage because when bugs are detected function calls execute
* with little branching in the functions.  Boundary cases tested in this card test; different hand sizes from 1 to 10, and different positions of the card to be
* discarded in the hand, from the 1st position to the last position in the hand.  The unit test then looks for the correct number of cards and
* that the village card was discarded properly after it was played, and also if the player has the correct number of actions. 
* 
* File 'cardtest4.c'
* Lines executed:54.31% of 116
* Branches executed:81.40% of 86
* Taken at least once:44.19% of 86
* Calls executed:26.67% of 45
* Creating 'cardtest4.c.gcov'
* Discussion: cardtest4.c tests the great hall card.   The statement coverage of the test is 54.31%
* This low coverage reflects the fact that no bugs were found and so the cases and statements in which errrors are found are not executed. 
* The branch coverage is better at 81.40%, this more representative of the coverage because when bugs are detected some function calls execute
* with little branching in the functions.  Boundary cases tested in this card test, different hand sizes from 1 to 10, and different positions of the card to be
* discarded in the hand, from the 1st position to the last position in the hand.  The unit test then looks for the correct number of cards and
* that the great hall card was discarded properly after it was played, and also if the player has the correct victory points after playing the victory card, which
* should be 1 less than the pre call.
* 
* File 'dominion.c'
* Lines executed:35.21% of 568
* Branches executed:37.65% of 417
* Taken at least once:29.98% of 417
* Calls executed:18.75% of 96
* Creating 'dominion.c.gcov'
* Discussion: dominion.c statement coverage of the test is 35.21%.  This low coverage reflects the fact that few of the function in dominion were tested.
* and also some of the functions that were tested were did not have very good coverage, eg;  the card effect function.  The branch coverage for dominion.c
* is 37.65% and is also low.  The low branch coverage is due to the same reason the statement coverage is low, not very much of the code was tested.
*
*