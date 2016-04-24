I came across bugs for 3 of my unit tests, the following briefly summarizes what I came across. 

The unit tests for Smithy all came back negative.  It was never able to return the expected number of cards in the hand and deck after playing the smithy card.  The loop for this
went through 6 iterations instead of the expected 3 which was a bug introduced in refactor.c and the unit tests caught this bug. 

In scorefor the unit tests revealed multiple failure points. For the cards in the players hand, all the tests passed with the exception of the great hall. However when the tests
went on to evaluate cards not in the players hand (discard or deck) the unit tests failed every single single test. Every value returned was 0 for each test. One  possible mode of 
failure is the for loop used to evaluate these seperate decks used the same variable. 

Adventurer tests came back with errors in one of the units tests. The first set which was a normal test came back passing every single test. The second test involved putting 2 coins on the top of the deck
and this triggered all sorts of errors.  This may be a bug in the unit test or the actual program. 