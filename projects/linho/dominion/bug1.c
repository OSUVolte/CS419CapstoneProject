// No bugs showed up for the unit tests for four functions.

// The bugs that appeared in the unit tests for four Dominion cards are caused by the changes in the dominion.c file.

// For cardtest1:

// ----------------- Testing Card: smithy ----------------
// checking for +3 cards...
// hand count = 6, expected = 7
// deck count = 3, expected = 2
// Assertion failed: (testGame.handCount[thisPlayer] == game.handCount[thisPlayer] + newCards - discarded), function main, file cardtest1.c, line 48.
// Abort trap: 6

// this is caused by the bugs in runSmithy function that I modified for assignment 2. runSmithy adds 2 cards instead of 3.

// For cardtest2:

// ----------------- Testing Card: village ----------------
// Checking for +1 cards...
// Hand count = 5, expected = 5
// Deck count = 4, expected = 4
// ...PASSED
// Checking for +2 actions...
// Actions = 1, expected = 3
// Assertion failed: (testGame.numActions == game.numActions + 2), function main, file cardtest2.c, line 63.
// Abort trap: 6

// +1 card was passed successfuly, but because runVillage -2 actions instead of +2 actinos.

// For cardtest3:

// ----------------- Testing Card: council_room ----------------
// Checking for +4 cards...
// Hand count = 9, expected = 8
// Deck count = 0, expected = 1
// Assertion failed: (testGame.handCount[thisPlayer] == game.handCount[thisPlayer] + newCards - discarded), function main, file cardtest3.c, line 50.
// Abort trap: 6

// The runCouncil_room function + 5 cards instead of +4 cards, which caused this error.

// For cardtest4:

// ----------------- Testing Card: adventurer ----------------
// Checking for adventurer cards...
// Hand count = 5, expected = 5
// Hand count = 5, expected = 6
// Assertion failed: (testGame.handCount[thisPlayer] == game.handCount[thisPlayer] + xtraCoins + discarded), function main, file cardtest4.c, line 60.
// Abort trap: 6

// Also gives an error of cards because in runAdventurer function card are discarded while drawn treasure cards are equal or more than 2 instead of less 2.