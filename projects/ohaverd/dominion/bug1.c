// Diana O'Haver
// bugs1.c
// Bugs found while writing unit tests for assignment 3

// 1.  Line 446 of dominion.c: should be deckCount, not discardCount

// 2. Found bugs introduced in previous assignment:
//      - great_hall increases numActions by 2 instead of 1
//      - great_hall draws 2 cards instead of 1
//      - council_room draws 3 cards instead of 4
//      - council_room increments numBuys by 2 instead of 1
//      - adventurer causes drawntreasure to increment by 2 instead of 1, causing only 1 card to be drawn
//      - smithy causes 4 cards to be drawn instead of 3

// 3. Gardens card does not function as expected because card of value 0 is being passed in
