Author: Jonathan Hardman
File Name: bug1.c

NOTE: I turned off all of the assertions for card tests for compiling purposes.
If you want the turn them on, then set AssertON = 1 at the top of each card test.

initializeGame: Does not pull out 5 cards for other players hand's.

numHandCards: No bugs found

whoseTurn: No bugs found

getCost: No bugs found

Village: No bugs found

Council Room: One extra card is being pulled out of player 1's deck and put in player 1's hand.

Adventurer: Too many cards are being pulled out of player 1's deck and put into player 1's hand
			and the number of buys increased by 1. Also does not discard adventurer card.

Smithy: One too many cards is being pulled out of player 1's deck and put into player 1's hand.

