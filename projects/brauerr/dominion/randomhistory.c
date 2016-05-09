//writeup on the development of the random testers for assignment 4
//including improvements in coverage and effort to check the correctness of spec

//development of adventurer random testers and test criteria
/*
//business rules
//should shuffle discard once to review contents
//after shuffling discard once - if still not 2 treasure cards found - should return with 
  //just 1 or 0
//should discard revealed cards that are not treasure
//should add 2 treasure cards to hand
//played adventurer should be added to played card pile
*/


//development of smithy random tester and test criteria
/*
  User should have at least one action remaining
  number of actions remaining should be decremented by one
  Current player should receive exactly 3 cards
  3 cards should come from his own pile.
  No state change should occur for other players
  played smithy should be added to played card pile
*/

//efforts made to check correctness of specification and improve coverage
/*
  The tester initializes a game with 25 cards in each players deck -
  ensures that the test card (adventurer or smithy) is in the players hand
  by adding it to the top of the deck
  and then simulates a hand while running tests (same as developed for these cards in Assignment 3)
  Results of tests 
  
  both random testers implement randomness in the selection of the kingdom cards - 
  aside from adventurer and smithy - the other 8 are randomly selected from all 18 possibilities
  the random methods were tested by printing results 10 times and finding no duplicates or
  values out of range
  
  both random testers also implement randomness in the selection of the players deck
  both decks include 7 coppers, 3 estates, 2 golds, and 2 silvers
  then the decks have 9 kingdom cards added randomly, and lastly
  a smithy or adventurer is added depending on which test is being run
  this was validated by printing the values for the decks
  
  both random testers implement randomness by shuffling the decks prior to running the test hand
  resulting in a 4 random cards in addition to the adventurer card begin available
  shuffling results were validated by again printing the values for the decks, and
  comparing to the sequence of values and count of each before shuffling
  Found through this validation and development that there must be a bug in the shuffle() method
  inspecting the hand at the beginning of each run showed that part of the hand
  was always identical - which could limit the coverage of this testing until the method
  is improved/fixed
  
  the random testers randomly assign 1 or 2 actions remaining - to enable play of
  additional actions if available in hand.  these actions are randomly selected out of the hand
  if more than one action is available
  
  The smithy or adventurer card is always played first, and the status checks done and tabulated
  at that point
  
  the random testers assign a random buy of any card with a cost equal to or less than the 
  amount of coins the player has
  
  A final batch of status checks is also done after the turn is ended - to ensure none of the
  additional plays threw off the status of the game outside of realistic bounds
*/

//Overall coverage and testing results from smithy 
//(can also be seen by running code and viewing the .out file)
/*
Testing Smithy 10 times...
Decrement Deck Passed 10 times
Increment Hand Passed 10 times
Other Player State Passed 10 times
Decrement Actions Passed 10 times
File 'dominion.c'
Lines executed:49.17% of 600
Branches executed:55.46% of 449
Taken at least once:42.54% of 449
Calls executed:32.38% of 105
Creating 'dominion.c.gcov'

Testing Smithy 50 times...
Decrement Deck Passed 50 times
Increment Hand Passed 50 times
Other Player State Passed 50 times
Decrement Actions Passed 50 times
File 'dominion.c'
Lines executed:59.17% of 600
Branches executed:67.04% of 449
Taken at least once:54.12% of 449
Calls executed:42.86% of 105
Creating 'dominion.c.gcov'

Testing Smithy 250 times...
Decrement Deck Passed 250 times
Increment Hand Passed 250 times
Other Player State Passed 250 times
Decrement Actions Passed 250 times
File 'dominion.c'
Lines executed:66.17% of 600
Branches executed:72.83% of 449
Taken at least once:61.25% of 449
Calls executed:52.38% of 105
Creating 'dominion.c.gcov'
  
*/

//Overall coverage and test results from adventurer
//(can also be seen by running code and viewing the .out file)
/*
Testing Adventurer 10 times...
Cards to Discard Passed 6 times
Treasure to Hand Passed 10 times
Adventurer to Played Passed 0 times
Other Player State Passed 10 times
Decrement Actions Passed 10 times
File 'dominion.c'
Lines executed:66.17% of 600
Branches executed:72.83% of 449
Taken at least once:61.25% of 449
Calls executed:52.38% of 105
Creating 'dominion.c.gcov'

Testing Adventurer 50 times...
Cards to Discard Passed 35 times
Treasure to Hand Passed 50 times
Adventurer to Played Passed 0 times
Other Player State Passed 50 times
Decrement Actions Passed 50 times
File 'dominion.c'
Lines executed:66.17% of 600
Branches executed:72.83% of 449
Taken at least once:61.25% of 449
Calls executed:52.38% of 105
Creating 'dominion.c.gcov'

Testing Adventurer 250 times...
Cards to Discard Passed 189 times
Treasure to Hand Passed 250 times
Adventurer to Played Passed 0 times
Other Player State Passed 250 times
Decrement Actions Passed 250 times
File 'dominion.c'
Lines executed:66.17% of 600
Branches executed:72.83% of 449
Taken at least once:61.25% of 449
Calls executed:52.38% of 105
Creating 'dominion.c.gcov'

*/