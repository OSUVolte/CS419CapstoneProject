/**************************
Bugs found:

unittest1: isGameOver 
-Test fails when I set two non-province cards to 0, while rules state that 3 need to be empty for game to be over.

unittest2: updateCoins
-Both pass and fail are printing with the copper card unit test, perhaps a logic error in the code. 

cardtest1: adventurer
-Deck was not re-shuffled when deckCount reached 0.
-Player did not receive 2 extra cards when playing adventurer

cardtest2: smithy
-Zero bugs found
***************************/