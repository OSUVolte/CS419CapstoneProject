/*
The makefile was adjusted to account for the new tests.

After copying the files to the directory, enter the following commands to ensure a clean run:

1. make clean (removes the old versions of whatever was there before)
2. make all (compiles, and runs tests from assignment 3 and 4)

To compile just the new tests do the following:

1. make adventuretest
2. make randomcard
3. make randomtests

Both the new random tests will export to randomtestcard.out and randomtestadventurer.out respectively.

Additionally I ammend unittestresults.out to include the new coverage percentage with the new tests.  Coverage was not significalty changed, it is up to 41.76% from 38.83%, which is 228 lines vs 212 lines.

*/

/*
Random Test Adventurer:

My random tests for the adventurer card are contained in a loop that runs them 10,000 times.  This does not take very long to run however, the longest run time was just under 2 minutes.  Once the game is initialized I randomly select cards from the hand, deck, and discard file.  This helps to ensure a random mix of cards in each pile.  After the random card draw takes place I call the cardEffect() function to invoke the adventurer card effect.  Once called, I check and print the results to the console.  My tests checks both the current player and next player (player 2) hand for:
	Hand count = + 2 cards (since the card draws 2 treasure cards).  Pass is current player gets +1 card and next player does not get any.  Fail otherwise.
	Deck count = -2 cards (since you drew 2 cards and shuffled the rest).  Pass is current player deck is -2 cards, fail otherwise.
	Estate card count, since this should not change.  Pass if estate card count does not change, fail otherwise.
	Adventurer card count -1. Pass if adventuerer card count is -1, fail otherwise.

With each iteration of the loop, the handCount, deckCount, and dicardCount is changed to a random number, and the cards drawn are all random as well. I feel as if this provides a good random testting scenario.  You can also change the amount of times the tests runs if necessary, although I tried to run it 100,000 times and it segmentation faulted.  Not sure why.

*/

/*
Random Test Card

For the random card to test I chose the Great Hall card. This seemed pretty easy functions to test,  and I wanted to test a different card than the card tests I wrote for assignment 3, so as to improve overall coverage.  The test is set up similar to the adventurer card, with the main loop running 10,000 times.  It also selects random numbers for handCount, deckCount, and discardCount, as well as random cards for the hand, discard pile, and deck.  Once the card effect function is invoked I check the following for each players hand:
	Hand count = +1.  Pass if only current player should get +1 card, fail otherwise.
	Deck count = -1 card. Fail otherwise.
	Estate card and great hall count are similar test scenarious as adventurer card.
	
I perform an additional check for the great hall, since you get +1 action from playing the card.  The test fails if numActions is not changed +1.  
	

*/

/*
For both tests, you could leave off the estate card check.  However, I included them to make the tests more conclusive.

*/