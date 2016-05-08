Author: Patrick Ho
Assignment 4
Due 5/8/2016

randomtestadventurer.c

Build Notes: Type 'make randomtestadventurer.out', this will produce an output 
file randomtestadventurer.out containing test and coverage results.

	Four game states have been tested on the adventurer cards using random 
testing methods. These random generation of game states were executed before the
effect of the adventurer card manifests and they are: 1.) Draw cards from
current player's deck, 'n' times (random variable from 0 to 5) to stimulate 
varying deck count, 2.) Start with 'n' (random variable from 0 to 10) number of 
treasure cards at the start of the game, 3.) Start selected kingdom card piles 
with 'n' (random variable from 0 to 10) supplies, and finally, 4.) Start with 
'n' (random variable from 2 to 4) number of players. Test oracles used to check 
the correctness of the card's specification follows similar specifications as 
designed during unit testing of the adventurer card. The random test will verify
that: 1.) If there were treasure cards in the deck, then the current player 
should receive at most 2 treasure cards, 2.) Treasure cards should come only 
from current player's pile, 3.) No changes to game state should occur for other
players, and 4.) No changes to the victory and kingdom card supply piles should
occur.
	In the previously performed unit tests, a branch in the playAdventurer() 
function was never executed because our deck was never empty. When the deck is 
empty, playAdventurer() calls shuffle() to shuffle the cards in the discard pile
back into the players deck. Now, our random test will branch into this once dead
code. In our previous unit test, 29.92% of the statements and 35.25% of the 
branches were executed, but only 78% of playAdventurer() was executed. This 
random test executes 24.03% statements and 26.14% branches in dominion.c and 
100% of playAdventurer() was executed. An interesting note, coverage of 
playAdventurer() has improved to 100%, but statement and branch coverage of 
dominion.c in the random tests have not improved as anticipated when compared 
to the unit tests. 

randomtestcard.c

Build Notes: Clean up previously built binaries by using 'make clean.' Next, 
		type, 'make randomtestcard.out'. Again, this will produce an output file
		called randomtestcard.out containing test and coverage results.

	randomtestcard.c will test the village card using random methods.  Four tests
are planned and four test oracles are used to check the correctness of the 
card's specification. The test plans will gage the game's response from playing
the village card and they include: 1.) Draw cards from current player's deck, 
'n' times (random variable from 0 to 5) to stimulate varying deck count, 
2.) Start selected kingdom card piles with 'n' (random variable from 0 to 10) 
supplies, and finally, 3.) Start with 'n' (random variable from 2 to 4) number 
of players, and 4.) Start seed value with 'n' (random variable from 0 to 8000).
Test oracles used to check the correctness of the card's specification follows 
similar specifications as designed during unit testing of the village card. The
random test will verify that: 1.) Current player's hand should have 1 extra 
minus 1 that was played and 2 additional actions, 2.) Number of buys or coins 
should not change, 3.) No changes to game state should occur for other players, 
and 4.) No changes to the victory and kingdom card supply piles should occur.
	In our previous unit test, initializeGame() was called 7 times and had a 
statement coverage of 87%. In this random test, initializeGame() is now called 
1021 times and has a statement coverage of 95%. playVillage() code coverage 
remains unchanged because the unit and random tests covers 100% of the 
statements. An interesting observation is discardCard() was called 9 times in
the previous unit test, but acheived 100% statement coverage. Meanwhile, the
random test called discardCard() 1220 times, but only acheived 80% statement
coverage, specifically the condition where:  
(handpos == (state->handCount[currentPlaer]) - 1) is never met out of 1220 
times.
