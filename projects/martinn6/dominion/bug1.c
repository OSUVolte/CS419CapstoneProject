unittest1:
Ran tests for all coin values: copper, silver, and gold.
Alo ran tests for no coins. 
All tests passed. The only issues I had where problem with my test code. 
After running unittest1.c, 'updateCoins' lines executed:100.00% of 11.

unittest2:
Testing int getCost(int cardNumber)
After running unittest1.c, getCost lines were only executed to 23.33% of 30.
Bug 1: When trying to run getCost(), I recieve a "Undefined reference to 'function' error in C". This happeend to be an issue with the makefile.
Created tests for each card value and compared it to outside resource: http://wiki.dominionstrategy.com
All cards passed.
Tested outer boundaries with values: -10 and 28. Function returned -1. PASSED.
New lines exectued: 
Function 'getCost'
Lines executed:100.00% of 30.

unittest3:
before tests, coverage was: 53.85% 
Testing gainCard(). Ran fine until the 'minion' card where I recieved a failure saying there are no minions in supply count and it ruined my tests.
Runing gainCard() to add 'minion' to deck...
player 0 starting deckcount=22; ending deckcount=22 PASSED
cardDrawn = great_hall FAILED
Starting Supply Count for minion = -1; Ending Supply Count = -1 PASSED
I added a part to skip if the supply was set to -1.
New % of lines executed after tests: 

Function 'gainCard'
Lines executed:100.00% of 13

unittest4:
Bug: I do not believe that the function getWinners() is implemented.
Current % ran:
Function 'getWinners'
Lines executed:0.00% of 24

Bug: Problem with scorefor(): line 444 is supposed to be for deck but is reading from discardCount:
	for (i = 0; i < state->discardCount[player]; i++)

Bug: Tying does not result in two winners.

new function coverage:
Function 'getWinners'
Lines executed:100.00% of 24