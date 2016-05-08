**Coverage Result****


Lines executed:32.80% of 567
Branches executed:41.69% of 415
Taken at least once:31.57% of 415
Calls executed:17.89% of 95
Creating 'dominion.c.gcov'


The present test suite executed 32.80% , 41.69 % branches and performed 17.89% calls. These results show that the coverage of the 8 test performed for this assignment was rather low.
Naturally these results are expected as a limited number of functions were covered by the test suit. 
In general, the coverage results show that several of the functions tested on the test suite present 100 % coverage results: scoreFor, smithyCard, isGameOver, fullDeckCount etc.
The functions that presented low coverage and thus present an opportunity for further testing are: shuffle, discardCard, remodelCard among others.
Overall, in order to improve the test suite coverage further tests will need to be wrtten to cover a wider range of functions
within the dominion game implementation. 


Unit Test #1 
TESTING updateCoins():
Test player 0 with 5 COPPER treasure card(s) and 0 bonus.
PASS:test = 5, expected = 5
Test player 0 with 5 SILVER treasure card(s) and 0 bonus.
PASS:test = 10, expected = 10
Test player 0 with 5 GOLD treasure card(s) and 0 bonus.
PASS:test = 15, expected = 15
Test player 0 with 5 COPPER treasure card(s) and 1 bonus.
PASS:test = 6, expected = 6
Test player 0 with 5 SILVER treasure card(s) and 1 bonus.
PASS:test = 11, expected = 11
Test player 0 with 5 GOLD treasure card(s) and 1 bonus.
PASS:test = 16, expected = 16
Test player 0 with 5 COPPER treasure card(s) and 2 bonus.
PASS:test = 7, expected = 7
Test player 0 with 5 SILVER treasure card(s) and 2 bonus.
PASS:test = 12, expected = 12
Test player 0 with 5 GOLD treasure card(s) and 2 bonus.
PASS:test = 17, expected = 17
Test player 0 with 5 COPPER treasure card(s) and 3 bonus.
PASS:test = 8, expected = 8
Test player 0 with 5 SILVER treasure card(s) and 3 bonus.
PASS:test = 13, expected = 13
Test player 0 with 5 GOLD treasure card(s) and 3 bonus.
PASS:test = 18, expected = 18
Test player 0 with 5 COPPER treasure card(s) and 4 bonus.
PASS:test = 9, expected = 9
Test player 0 with 5 SILVER treasure card(s) and 4 bonus.
PASS:test = 14, expected = 14
Test player 0 with 5 GOLD treasure card(s) and 4 bonus.
PASS:test = 19, expected = 19
Test player 0 with 5 COPPER treasure card(s) and 5 bonus.
PASS:test = 10, expected = 10
Test player 0 with 5 SILVER treasure card(s) and 5 bonus.
PASS:test = 15, expected = 15
Test player 0 with 5 GOLD treasure card(s) and 5 bonus.
PASS:test = 20, expected = 20
Test player 1 with 5 COPPER treasure card(s) and 0 bonus.
PASS:test = 5, expected = 5
Test player 1 with 5 SILVER treasure card(s) and 0 bonus.
PASS:test = 10, expected = 10
Test player 1 with 5 GOLD treasure card(s) and 0 bonus.
PASS:test = 15, expected = 15
Test player 1 with 5 COPPER treasure card(s) and 1 bonus.
PASS:test = 6, expected = 6
Test player 1 with 5 SILVER treasure card(s) and 1 bonus.
PASS:test = 11, expected = 11
Test player 1 with 5 GOLD treasure card(s) and 1 bonus.
PASS:test = 16, expected = 16
Test player 1 with 5 COPPER treasure card(s) and 2 bonus.
PASS:test = 7, expected = 7
Test player 1 with 5 SILVER treasure card(s) and 2 bonus.
PASS:test = 12, expected = 12
Test player 1 with 5 GOLD treasure card(s) and 2 bonus.
PASS:test = 17, expected = 17
Test player 1 with 5 COPPER treasure card(s) and 3 bonus.
PASS:test = 8, expected = 8
Test player 1 with 5 SILVER treasure card(s) and 3 bonus.
PASS:test = 13, expected = 13
Test player 1 with 5 GOLD treasure card(s) and 3 bonus.
PASS:test = 18, expected = 18
Test player 1 with 5 COPPER treasure card(s) and 4 bonus.
PASS:test = 9, expected = 9
Test player 1 with 5 SILVER treasure card(s) and 4 bonus.
PASS:test = 14, expected = 14
Test player 1 with 5 GOLD treasure card(s) and 4 bonus.
PASS:test = 19, expected = 19
Test player 1 with 5 COPPER treasure card(s) and 5 bonus.
PASS:test = 10, expected = 10
Test player 1 with 5 SILVER treasure card(s) and 5 bonus.
PASS:test = 15, expected = 15
Test player 1 with 5 GOLD treasure card(s) and 5 bonus.
PASS:test = 20, expected = 20
End Unit Test #1
Unit Test #2 
TESTING isGameOver():
TESTING if game is over after game initialization:
PASS:test: 0, expected:0 
TESTING if game is over when stack of Province cards is empty:
PASS:test: 1, expected:1 
TESTING if game is over when 1 supply pile is empty:
PASS:test: 0, expected:0 
TESTING if game is over when 3 supply piles are empty:
PASS:test: 1, expected:1 
End Unit Test #2
Unit Test #3 
TESTING scorFor():
Test scoreFor player 0.
PASS:test = 24, expected = 24
Test scoreFor player 1.
PASS:test = 24, expected = 24
End Unit Test #3
Unit Test #4
TESTING fullDeckCount():
Test player 0 with 0 adventurer card(s) in hand
PASS:test = 0, expected = 0
Test player 0 with 0 adventurer card(s) in hand and in deck
PASS:test = 0, expected = 0
Test player 0 with 0 adventurer card(s) in hand, in deck, and in discard 
PASS:test = 0, expected = 0
Test player 0 with 1 adventurer card(s) in hand
PASS:test = 1, expected = 1
Test player 0 with 1 adventurer card(s) in hand and in deck
PASS:test = 2, expected = 2
Test player 0 with 1 adventurer card(s) in hand, in deck, and in discard 
PASS:test = 3, expected = 3
Test player 0 with 2 adventurer card(s) in hand
PASS:test = 2, expected = 2
Test player 0 with 2 adventurer card(s) in hand and in deck
PASS:test = 4, expected = 4
Test player 0 with 2 adventurer card(s) in hand, in deck, and in discard 
PASS:test = 6, expected = 6
Test player 0 with 3 adventurer card(s) in hand
PASS:test = 3, expected = 3
Test player 0 with 3 adventurer card(s) in hand and in deck
PASS:test = 6, expected = 6
Test player 0 with 3 adventurer card(s) in hand, in deck, and in discard 
PASS:test = 9, expected = 9
Test player 0 with 4 adventurer card(s) in hand
PASS:test = 4, expected = 4
Test player 0 with 4 adventurer card(s) in hand and in deck
PASS:test = 8, expected = 8
Test player 0 with 4 adventurer card(s) in hand, in deck, and in discard 
PASS:test = 12, expected = 12
Test player 0 with 5 adventurer card(s) in hand
PASS:test = 5, expected = 5
Test player 0 with 5 adventurer card(s) in hand and in deck
PASS:test = 10, expected = 10
Test player 0 with 5 adventurer card(s) in hand, in deck, and in discard 
PASS:test = 15, expected = 15
Test player 1 with 0 adventurer card(s) in hand
PASS:test = 0, expected = 0
Test player 1 with 0 adventurer card(s) in hand and in deck
PASS:test = 0, expected = 0
Test player 1 with 0 adventurer card(s) in hand, in deck, and in discard 
PASS:test = 0, expected = 0
Test player 1 with 1 adventurer card(s) in hand
PASS:test = 1, expected = 1
Test player 1 with 1 adventurer card(s) in hand and in deck
PASS:test = 2, expected = 2
Test player 1 with 1 adventurer card(s) in hand, in deck, and in discard 
PASS:test = 3, expected = 3
Test player 1 with 2 adventurer card(s) in hand
PASS:test = 2, expected = 2
Test player 1 with 2 adventurer card(s) in hand and in deck
PASS:test = 4, expected = 4
Test player 1 with 2 adventurer card(s) in hand, in deck, and in discard 
PASS:test = 6, expected = 6
Test player 1 with 3 adventurer card(s) in hand
PASS:test = 3, expected = 3
Test player 1 with 3 adventurer card(s) in hand and in deck
PASS:test = 6, expected = 6
Test player 1 with 3 adventurer card(s) in hand, in deck, and in discard 
PASS:test = 9, expected = 9
Test player 1 with 4 adventurer card(s) in hand
PASS:test = 4, expected = 4
Test player 1 with 4 adventurer card(s) in hand and in deck
PASS:test = 8, expected = 8
Test player 1 with 4 adventurer card(s) in hand, in deck, and in discard 
PASS:test = 12, expected = 12
Test player 1 with 5 adventurer card(s) in hand
PASS:test = 5, expected = 5
Test player 1 with 5 adventurer card(s) in hand and in deck
PASS:test = 10, expected = 10
Test player 1 with 5 adventurer card(s) in hand, in deck, and in discard 
PASS:test = 15, expected = 15
End Unit Test #4
Testing smithy()
Test 1: player 0 draws the correct number of cards (3 cards)
FAIL: test = 6, expected = 7
Test 1: correct number of cards in player 0 deck (1 card discarted)
FAIL: test = 3, expected = 2
Test 2: player 0 draws cards from the correct pile
FAIL: test = 3, expected = 2
Test 3: player 1 deck remains unchanged
PASS: test = 10, expected = 10

Testing complete 

Testing adventurer()
Test 1: player 0 draws two treasury cards from deck
FAIL: test = 7, expected = 8
Test 2: player 1 deck remains unchanged
PASS: test = 10, expected = 10
Test 3: discard deck should not have any treasure cads
PASS: test = 0, expected = 0

Testing complete 

Testing council_room ()
Test 1: player 0 draws 4 cards from deck
FAIL: test = 9, expected = 8
Test 2: 1 buy is added to the state of the game
PASS: test = 2, expected = 2
Test 3:Each other player in the game draws one card
PASS: test = 1, expected = 1
Testing cutpurseCard()
Test 1: player 0 update coins by 2
PASS: test = 4, expected = 4
Test 2:Each other player in the game discards a copper card from hand
PASS: test = 0, expected = 0
Function 'updateCoins'
Lines executed:100.00% of 11
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Function 'gainCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 1

Function 'discardCard'
Lines executed:84.62% of 13
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
No calls

Function 'cardEffect'
Lines executed:7.07% of 198
Branches executed:14.29% of 161
Taken at least once:2.48% of 161
Calls executed:7.41% of 54

Function 'remodelCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 5

Function 'cutpurseCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 12
Taken at least once:0.00% of 12
Calls executed:0.00% of 3

Function 'council_roomCard'
Lines executed:100.00% of 10
Branches executed:100.00% of 6
Taken at least once:100.00% of 6
Calls executed:100.00% of 3

Function 'smithyCard'
Lines executed:100.00% of 6
Branches executed:100.00% of 2
Taken at least once:100.00% of 2
Calls executed:100.00% of 2

Function 'adventurerCard'
Lines executed:60.00% of 15
Branches executed:80.00% of 10
Taken at least once:50.00% of 10
Calls executed:50.00% of 2

Function 'getCost'
Lines executed:0.00% of 30
Branches executed:0.00% of 28
Taken at least once:0.00% of 28
No calls

Function 'drawCard'
Lines executed:36.36% of 22
Branches executed:33.33% of 6
Taken at least once:16.67% of 6
Calls executed:0.00% of 1

Function 'getWinners'
Lines executed:0.00% of 24
Branches executed:0.00% of 22
Taken at least once:0.00% of 22
Calls executed:0.00% of 2

Function 'scoreFor'
Lines executed:100.00% of 24
Branches executed:100.00% of 42
Taken at least once:88.10% of 42
Calls executed:0.00% of 3

Function 'isGameOver'
Lines executed:100.00% of 10
Branches executed:100.00% of 8
Taken at least once:100.00% of 8
No calls

Function 'endTurn'
Lines executed:0.00% of 20
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 3

Function 'whoseTurn'
Lines executed:100.00% of 2
No branches
No calls

Function 'fullDeckCount'
Lines executed:100.00% of 9
Branches executed:100.00% of 12
Taken at least once:83.33% of 12
No calls

Function 'supplyCount'
Lines executed:0.00% of 2
No branches
No calls

Function 'handCard'
Lines executed:0.00% of 3
No branches
Calls executed:0.00% of 1

Function 'numHandCards'
Lines executed:0.00% of 2
No branches
Calls executed:0.00% of 1

Function 'buyCard'
Lines executed:0.00% of 13
Branches executed:0.00% of 6
Taken at least once:0.00% of 6
Calls executed:0.00% of 4

Function 'playCard'
Lines executed:0.00% of 14
Branches executed:0.00% of 10
Taken at least once:0.00% of 10
Calls executed:0.00% of 3

Function 'shuffle'
Lines executed:93.75% of 16
Branches executed:100.00% of 8
Taken at least once:87.50% of 8
Calls executed:100.00% of 2

Function 'initializeGame'
Lines executed:83.87% of 62
Branches executed:95.65% of 46
Taken at least once:80.43% of 46
Calls executed:100.00% of 5

Function 'kingdomCards'
Lines executed:0.00% of 13
No branches
No calls

Function 'newGame'
Lines executed:0.00% of 3
No branches
No calls

Function 'compare'
Lines executed:83.33% of 6
Branches executed:100.00% of 4
Taken at least once:75.00% of 4
No calls

File 'dominion.c'
Lines executed:32.80% of 567
Branches executed:41.69% of 415
Taken at least once:31.57% of 415
Calls executed:17.89% of 95
Creating 'dominion.c.gcov'

