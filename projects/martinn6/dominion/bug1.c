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

cardtest1: 
Testing 'smithy':
Although it looks like the card is removed from the user's hand. The card is not added to the 'discard' pile or placed back in the deck.
hand count before=5; hand count after=7; expected=7 PASSED
discard count before=0; discard count after=0; expected = 1 FAILED
deck count before=5; deck count after=2; expected = 3 FAILED

cardtest2: 
Testing 'adventurer':
Function is working correctly as it only puts 2 cards in a users hand. They are also 2 treasure cards.
Before:card=4; card=4; card=1; card=4; card=4; 
After:card=4; card=4; card=1; card=4; card=4; card=4; card=4; 
hand count before=5; hand count after=7; expected=7 PASSED
treaure card count before =4; treaure card count after=6; expected=6 PASSED

cardtest3: 
Testing 'great_hall':
Function is adding actions correctly. However, I do not believe that it is discarding properly. I cant see any changes in the cards either.

Before:[card=4; card=4; card=1; card=4; card=4; ]
After:[card=4; card=4; card=1; card=4; card=4; ]

action count before=1; action count after=2; expected=2 PASSED
hand count before=5; hand count after=5; expected=5 PASSED
discount count before=0; discount count after=0; expected=1 FAILED
Discarded:[] = No discarded cards

cardtest4: 
Testing 'embargo':
Function is adding embargo token and coins. However, not sure if it is discarding properly. It does not go into the discarded pile.

Before:[card=4; card=4; card=1; card=4; card=4; card=22; ]
After:[card=4; card=4; card=1; card=4; card=4; ]

action count before=1; action count after=1; expected=1 PASSED
hand count before=6; hand count after=5; expected=5 PASSED
coin count before=4; coin count after=6; expected=6 PASSED
embargo tokens count before=0; embargo tokens count after=1; expected=1 PASSED
discount count before=0; discount count after=0; expected=1 FAILED
Discarded:[]
