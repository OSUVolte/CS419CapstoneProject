unittest1: updateCoins()
	This test goes through 2 players, max hand of 5 with max bonus of 10, looping through all possible combinations
	For each combination, users gets hands of all coppers, silvers, golds and no treasure cards.
	The result of updateCoins (bonus + treasure cards) is compared to exepected.  

	Of the entire dominion.c, this test executed 22% of lines and 20% of branches.  7% of calls were executed.
	Of updateCoins(), this test called the funcitons 3,300 times and returned 100% and executed 100% of blocks.  Every line and branch was taken.

unittest2: getCost()
	This test passes all valid inputs (0 through 26) as well as nonvalid inputs (-1, 27) to ensure the correct cost of the card is returned

	Of dominion.c, this test executed 5% of lines, 7% of branchs and 0% of calls. These lower numbers are to be expected
	Of getCost(), this was called 29 times and returned 100% and exececuted 100% of blocks.
		Each branch was taken 3% or 7% of times.

unitteset3: isGameOver()
	This test sets the provadence supply to 10 and then 0 to test if the function correctly determines when the game is over
	The test then sets all supply to 25, then changes 1 to 0, 2 to 0, 3 to 0, 4 to 0 and then all 25 to 0. 
	This tests to see if it correctly ends the game when 3 supplys get to 0.

	Of dominion.c, this test executed 18% of lines, 18% of brances and 8% of calls
	of isGameOver(), returned 100% and executed 100% of blocks.  Each branch was taken between 4% and 96%
	
unittest4: compare()
	This test puts different, equal and negative numbers into the compare function to ensure it works
	
	Of dominion.c this test executed 1% of lines, 1% of branches and 0 calls.
	Of compare(), this test returned 100% and executed 100% of blocks.
		each branch was taken between 25% and 75%

unittest5: scoreFor()  (Note: this extra unit test was done since I only modified unittest1)
	This test gives players decks consisting of each of the victory point cards as well as a control (smithy)

	of dominion.c this test executed 22% of lines, 29% of branches and executed 11% of calls
	of scoreFor(), this test was called 9 times, returned 100% and executed 100% of blocks
		each branch was taken between 13% and 88%

cardtest1: smithy
	This test records number of actions / buys / coins and ensures they stay the same before and after playing card
	This test records opponents counts in their deck / discard / hand to ensure they stay the same
	This test records number of cards in each supply to ensure they are the same
	This test tests that the discard pile increased 1, players hand increased 2 and deck decreases 3.

	Of dominion.c, this test executed 18% of lines, 22% of branches and 11% of calls
	Of card effect, this test returned 100% of times and executed 3% of blocks
	Of the smithy portion of card effect, returned 100% and executed 100% of blocks

cardtest2: Adventurer
	This test records number of actions/buys/coins and ensures they stay the same before and after playing card
	This test records opponents counts in their deck/discard/hand to ensure they stay the same
	This test records number of cards in each supply to ensure they are the same
	This test records the number of treasure in hand before and after.  This is expected to increase by 2.
	This test records the number of treasure in deck/discard (combined since they can be shuffled) before and after.  
		This is expected to decrease by 2
	This test records the hand count before and after.  This is expected to increase by 1.
	This test records the deck/discard count before and after.  This is expected to decrease by 1.

	Of dominion.c, this test executed 20% of lines, 23% of branches and 11% of calls
	of card effect, this test returned 100% and executed 3% of blocks
	for the adventurer portion of card effect, returned 100% and executed 64% of blocks

cardtest3: Gardens
	This test records number of actions / buys / coins and ensures they stay the same before and after playing card
	This test records opponents counts in their deck / discard / hand to ensure they stay the same
	This test records number of cards in each supply to ensure they are the same
	This test records the hand count before and after.This is expected to decrease by 1.
	This test records the deck / discard count before and after.This is expected to increase by 1.

	of dominion.c, this test executed 19% of lines, 22% of branches and 10% of calls
	of card effect, this test returned 100% and executed 3% of blocks
	of the Gradens portion of cardeffects, returned 100% and executed 100% of blocks

cardtest4: Village
	This test records number of buys / coins and ensures they stay the same before and after playing card
	This test records opponents counts in their deck / discard / hand to ensure they stay the same
	This test records number of cards in each supply to ensure they are the same
	This test records the hand count before and after.This is expected to remain the same
	This test records the deck counts before and after.  This is expected to decrease 1.
	This test record the discard count before and after.  This is expected to increase 1.
	This test records the number of actions before and after.  This is expected to increase 2.

	Of dominion.c, this test exeucted 20% of lines, 23% of breanches and 11% of calls
	Of Cardeffect, this test returned 100% and executed 4% blocks.
	Of the Village portionsof cardeffects, exectuted 100% of lines.

Results of all tests together:
	Dominion.c: 38% of lines, 47% of branches, 19% of calls

Obviously 38% of lines and 47% of branches is not great, but considering tests for many functions were not even attempted.
Just scanning through the dominion.c.gcov file, functions like kingdomCards, playcard, buycard, endTurn, getWinners were not even called
once and thus many lines and branches were not tested.  The best way to improve coverage would simply be test more functions.

While those percentages are a little disapointed after around 10 hours of work, the coverage of the functions that were covered is promising.
Of the 9 unit tests, only 1 did not have 100% line coverage.  This coverage was lower because the deck did not need to be schuffled and only coppers
were drawn.  Additional test cases could be implemented to force a schuffle and force other cards to be drawn to increase coverage.
