/********************************************************
*														*
* Author: Sam Nelson									*
* Class: CS 362											*
* Assignment: Assignment 2 								*
* Date: 4/1/2016										*
* Description: Give documentation on smith, adventurer	*
* cards and also on discardCard() and updateCoins() 	*
* functions												*
*														*
*********************************************************

Smithy Card: 
Each hand starts out with an action phase where the player can play action 
cards (including the smithy and adventurer), once this phase has been completed
the player then purchases additional cards or passes.  The rounds start out
with each player having 5 cards or less, each round ends with the entire hand being discarded.
The smithy action card puts 3 cards into the users hand.  This invokes the drawCard() functions
3 seperate times.

Adventurer Card: 
Player draws cards until 2 treasure cards (gold, silver, or copper) are found...all other cards 
that are not treasure are discarded.  Card invokes draw card which places the new card at the 
top, then checks to see if it is copper silver or gold, if so it increases a drawntreasure 
var that keeps track of drawn treasures.  Loop continues until drawntreasure is 2 or greater.
as seen on lines 670-682 on dominion.c

discardCard():
Function takes all trashflags of less than 1 and discards the card, removes card from players hand
increases discard pile counter by 1.  The discard pile is called the playedCards array.
If the trashflag is 1 it indicates the card will be trashed which means they are removed from game.
As seen on lines 1226-1262 in dominion.c

updateCoins():
Each round the user starts of with 0 monies; updateCoins goes through and tallys up all of the users worth
by looking for copper, silver, and gold and adding up their total money along with any bonuses that 
they received from action cards.
As seen on lines 1301-1329