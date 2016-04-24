// Diana O'Haver
// Assignment 2
// Refactor.c

// Specs:
// Your implementation of at least 4 of these 5 cards should be incorrect in some way, i.e., you should introduce subtle bugs that are hard to catch in your changes.
// Introducing bugs in smithy and adventurer is mandatory.  Write information of your bugs also in refactor.c

// Bug in drawGardens:
//    - Returns 1 instead of -1

// Bug in drawSmithy:
//    - Draws 4 cards for the player instead of 3

// Bug in drawAdventurer:
//    - Increments drawntreasure by 2 if card drawn is silver/copper/gold, instead of 1

// Bug in drawCouncilRoom:
//    - Increments numBuy's by 2 instead of 1
//    - Draws 3 cards for the player instead of 4

// Bug in drawGreatHall:
//    - drawCard called twice instead of once
//    - numActions incremented twice instead of once
