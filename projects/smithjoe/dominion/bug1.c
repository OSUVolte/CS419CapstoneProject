----------------- Testing Card: adventurer ----------------
TEST 1: choice1 = 1 = +2 cards
hand count = 7, expected = 7
deck count = 3, expected = 2
coins = 4, expected = 4
Assertion failed: (testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards), function main, file cardtest4.c, line 60.
Abort trap: 6

For the adventurer card, deckCount does not add up to the correct amounts.


