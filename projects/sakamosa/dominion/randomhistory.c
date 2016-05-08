Random Testing of Adventurer and Great Hall
_____________________________________________________________
/*
Overall

The code coverage did not improve much with the random tests because I chose cards that already had unit
tests and an analysis of my code coverage after the unit tests and card tests showed that my biggest gaps were in 
whole functions that never ran. However, I did achieve better test results by randomizing the intial game state (through the seed) 
and the number of players.


great hall:
In retrospect, this card was not a good candidate for random testing because the bugs I had caught with my initial card
test seemed to be related to internal functions and not affected by the parameters for great hall. However, it was useful in that
it did not uncover any new bugs and it showed that the two previous bugs found were consistent even with varied inputs.

adventurer:
The random tests for adventurer showed a weakness in the game state after a discard. It appears that for games with more than
two players, the current player's hand has the wrong number of cards after play as does the discard pile. 
My initial tests only tested for two players so I had missed those bugs.
I achieved slightly higher code coverage but it was due to more error codes and branching being run.
*/