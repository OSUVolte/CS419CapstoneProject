/***********************************************
 * *Name:Suyana Lozada
 * *Assignment #4 CS 362
 * *Date:05-07-2015
 * *randomhistory.c
 * *
 * ***************************************************/
randomtestadventurer.c

The present random test performed the following checks for the adventurer card: 
	1.Determine if the player hand contains two treasure cards.
	2.Determine if deck decreased by at least two cards.
	3.Determine if the other pleyer(s) hand remained unchanged.

The following game variables were randomly generated each test run:
	1.Game seed.
	2.Number of players.
	3.desckCount, discardCount, and handCount for each player in the game.

The randomtestadventurer.c test uncovered a known bug which was introduced in a previous
assignment. Instead of drawing two treasure cards, the player will draw three treasure cards
from the deck.

In order to improve the random test coverage, the number of random test was increased accordingly. 
At a total number or 100 runs the test yields a coverage of 23.81% for dominion.c and 100% coverage for 
the adventurerCard function. 			

File 'dominion.c'
Lines executed:23.81% of 567
Branches executed:24.82% of 415
Taken at least once:17.35% of 415
Calls executed:12.63% of 95
Creating 'dominion.c.gcov'

Function 'adventurerCard'
Lines executed:100.00% of 15
Branches executed:100.00% of 10
Taken at least once:90.00% of 10
Calls executed:100.00% of 2


randomtestcard.c

The present random test performed the following checks for the council_room card: 
	1.Determine if player draws a total of four cards from deck.
	2.Determine if 1 buy is added to the game.
	3.Determine if each player in the game draws one card.

The randontestcard.c uncovered a know bug which was introduced in a previous card. The player draws only three cards instead of four cards from the deck.

In order to improve the random test coverage, the number of random test was increased accordingly. 
At a total number or 500 runs the test yields a coverage of 27.87% for dominion.c and 100% coverage for concil_roomCard function.

File 'dominion.c'
Lines executed:27.87% of 567
Branches executed:27.71% of 415
Taken at least once:19.76% of 415
Calls executed:16.84% of 95
Creating 'dominion.c.gcov'


File 'dominion.c'
Lines executed:27.87% of 567
Branches executed:27.71% of 415
Taken at least once:19.76% of 415
Calls executed:16.84% of 95
Creating 'dominion.c.gcov'
