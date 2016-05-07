/*
	Bryan Serif
	CS 362
	coverage1.c
	04/24/2016
	
	The full results can be found in unittestresults.outp
	
	
unittest1: updatedCoins
	Function 'updateCoins'
	Lines executed:100.00% of 11
	Branches executed:100.00% of 8
	Taken at least once:100.00% of 8
	No calls
	
	For update coins I reached 100% coverage. It was tested by going through
	both players and then checking for each branch possibility by slowly
	adding more cards and testing for copper, silver, and gold to respond
	accordingly.

unittest2: isGameOver
	Function 'isGameOver'
	Lines executed:100.00% of 10
	Branches executed:100.00% of 8
	Taken at least once:100.00% of 8
	No calls
	
	For isGameOver I was also able to acheive 100% coverage. This was done first
	by checking the state with no province cards. Then checking the state with one
	province card. Then from the point of having one province card reamin, the 
	three states of 1, 2, and 3 piles being empty was tested.

unittest3: getCost
	Function 'getCost'
	Lines executed:96.67% of 30
	Branches executed:100.00% of 28
	Taken at least once:96.43% of 28
	No calls
	
	For getCost I came just under 100%. All branches were executed but there was
	a missing line. I did not test for the default exit case of no cards matching
	the switch statement and returning a -1.

unittest4: fullDeckCount
	Function 'fullDeckCount'
	Lines executed:88.89% of 9
	Branches executed:83.33% of 12
	Taken at least once:58.33% of 12
	No calls
	
	For fullDeckCount I only obtained 88.89% line coverage. This could have 
	been remedied by adding an additional tests to check for the game states
	for discard, hand, and deck counts.

cardtest1: smithy
	Function 'playSmithy'
	Lines executed:100.00% of 4
	No branches
	Calls executed:100.00% of 2
	
	For smithy I achevied 100% coverage. I did this by first initializing the game state.
	From there I gave five cards to the players I was iterating through. When they had
	their cards cardEffect was called. I think tested to make sure that that number
	of cards played increased and the number of cards in hand increased.

cardtest2: adventurer
	Function 'playAdventurer'
	Lines executed:94.12% of 17
	Branches executed:100.00% of 10
	Taken at least once:80.00% of 10
	Calls executed:50.00% of 2
	
	Adventurer was tested by setting the game states. The function was then called and
	the return was checked for the number of cards in hand increasing by 1 and that the
	two cards added were treasure cards. 

cardtest3: great hall
	Function 'playGreatHall'
	Lines executed:100.00% of 5
	No branches
	Calls executed:100.00% of 2
	
	Great hall was another function that reached 100% coverage. This is a straight forward
	function where you only needed to check that the correct number of cards added and 
	actions added were correct.

cardtest4: council room
	Function 'playCouncilRoom'
	Lines executed:100.00% of 10
	Branches executed:100.00% of 6
	Taken at least once:100.00% of 6
	Calls executed:100.00% of 3
	
	Council room as also 100% covered. I did the testing by running the function and then
	verifying that the correct number of cards were added for all players and that the
	number of buys was increased.
	
	
File 'dominion.c'
Lines executed:35.12% of 561
Branches executed:38.01% of 413
Taken at least once:28.57% of 413
Calls executed:17.71% of 96
Creating 'dominion.c.gcov'

Overall coverage was only at 35%. This is due in part to the limited number of functions
that were tested with this testing suite. Take into consideration to function for card
effect. It is marked as a 4% coverage. This could be remedied by implementing test for
all card calls. The other functions in Dominion were not also directly tested from
the unit tests which created some coverage in them as they were called by dependent
functions that were tested. This does not create an inclusive coverage map however.
*/