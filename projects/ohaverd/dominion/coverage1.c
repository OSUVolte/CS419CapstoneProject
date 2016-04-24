// Diana O'Haver
// Assignment 3
// coverage1.c

/*** unittest1.c - endTurn ***/

// Function 'endTurn'
// Lines executed:95.00% of 20
// Branches executed:100.00% of 6
// Taken at least once:83.33% of 6
// Calls executed:100.00% of 3

// File 'dominion.c'
// Lines executed:19.50% of 564
// Branches executed:17.06% of 422
// Taken at least once:13.74% of 422
// Calls executed:10.42% of 96

/*** unittest2.c - updateCoins ***/

// Function 'updateCoins'
// Lines executed:100.00% of 11
// Branches executed:100.00% of 8
// Taken at least once:100.00% of 8
// No calls

// File 'dominion.c'
// Lines executed:19.86% of 564
// Branches executed:17.06% of 422
// Taken at least once:14.22% of 422
// Calls executed:10.42% of 96

/*** unittest3.c - scoreFor ***/

// Function 'scoreFor'
// Lines executed:100.00% of 24
// Branches executed:100.00% of 42
// Taken at least once:76.19% of 42
// Calls executed:33.33% of 3

// File 'dominion.c'
// Lines executed:25.35% of 564
// Branches executed:28.91% of 422
// Taken at least once:22.99% of 422
// Calls executed:11.46% of 96

/*** unittest4.c - isGameOver ***/

// Function 'isGameOver'
// Lines executed:90.00% of 10
// Branches executed:100.00% of 8
// Taken at least once:87.50% of 8
// No calls

// File 'dominion.c'
// Lines executed:26.95% of 564
// Branches executed:30.81% of 422
// Taken at least once:24.64% of 422
// Calls executed:11.46% of 96

/*** cardtest1.c - smithy ***/

// Function 'drawSmithy'
// Lines executed:100.00% of 5
// Branches executed:100.00% of 2
// Taken at least once:100.00% of 2
// Calls executed:100.00% of 2

// File 'dominion.c'
// Lines executed:32.45% of 564
// Branches executed:39.34% of 422
// Taken at least once:27.49% of 422
// Calls executed:15.63% of 96

/*** cardtest2.c - adventurer ***/

// Function 'drawAdventurer'
// Lines executed:100.00% of 15
// Branches executed:100.00% of 12
// Taken at least once:83.33% of 12
// Calls executed:100.00% of 2

// File 'dominion.c'
// Lines executed:37.94% of 564
// Branches executed:43.13% of 422
// Taken at least once:31.75% of 422
// Calls executed:19.79% of 96

/*** cardtest3.c - council_room ***/

// Function 'drawCouncilRoom'
// Lines executed:100.00% of 9
// Branches executed:100.00% of 6
// Taken at least once:100.00% of 6
// Calls executed:100.00% of 3

// File 'dominion.c'
// Lines executed:39.72% of 564
// Branches executed:44.55% of 422
// Taken at least once:33.41% of 422
// Calls executed:23.96% of 96

/*** cardtest4.c - great_hall ***/

// Function 'drawGreatHall'
// Lines executed:100.00% of 6
// No branches
// Calls executed:100.00% of 3

// File 'dominion.c'
// Lines executed:40.96% of 564
// Branches executed:44.55% of 422
// Taken at least once:33.65% of 422
// Calls executed:28.13% of 96

/*** Analysis ***/

// Much of my testing seemed to be sufficient for the functions chosen. I achieved 100% line execution on all functions aside from endTurn and
// isGameOver. I also achieved 100% branch execution on all functions that had branches. When calls were made, I had 100% coverage on all functions
// aside from scoreFor.

// Deficiencies in endTurn:
//   There are some additional details in testing that I bypassed for the sake of expediency that may have helped my testing coverage. While I tested
//   the effect of drawCard, I didn't test the effect of updateCoins. In being more concerned with the effect of discard and drawing, I missed the opportunity
//   to test that updateCoins was correctly being called at the end of the turn.

// Deficiencies in isGameOver:
//   In retrospect, two tests was not enough to provide sufficient coverage of isGameOver, even though it is one of the more simple functions. I tested the
//   return value of the function, but did not "crack open" the function to ensure that everything was being correctly manipulated outside of the return value.
//   I additionally did not account for a case where the game was not over - this was a critical case that I should have tested for, rather than only testing
//   cases where the game was over.

// Deficiencies in scoreFor:
//   There were a couple errors that I found as a result of investigating scoreFor. First, line 446 uses the discardCount to iterate through the deck, rather
//   than the deckCount. Additionally, fullDeckCount, called in the gardens if statement, does not seem to correctly return the value I expected from a garden
//   card. That said, I'm not fully clear why only 1 of 3 calls were executed.

// Overall dominion.c performance:
//   It is not surprise that lines executed, branches executed, and calls executed were all very low - each test was only testing against a single function, which
//   may or may not call a certain amount of the over functions. This kept the overall coverage very low, as each test was designed to only test a specific portion
//   of the program.
