/*

Author: 	Charles Siebert
Class:	CS362-400
Date:	4/24/16 
File:	bug1.c

Description: File used to describe the bugs found and reported in the unittesting.

cardSmithy(): results ended in a bug, where the expected handsize is one less than was received.
Tested this function with a starting hand size of 3. When Smithy is played, the expected results:

	Expected: +3 to card hand, discard Smithy when played.
	handsize = 3;
	Expected handsize = +3 -1 = 5
	
	Results: handsize = 6
	handsize = +4 -1 = 6
	
	The results show this because we also test the discardCard function, where it displayed the
	playedCardCuont as increasing after the card was played.
	
cardVillage(): results ended in a bug, where the expected handsize is two less than was received.
The test that failed is handsize, where the starting hand size was 3, and resulted in 2.
	
	Expected: +1 card to hand, discard card that is played
	handsize = 3;
	expected size = +1 -1 = 3
	
	Results: handsize = 2
	resulted: -1 (discard hand)
	
	The result shwos that the card was never drawn, as the card is actually played and discared
	Looking at the code, it shows that the drawCard is calling the currentPlayer +1, meaning the
	other player actually draws the card. This is harder to test for, since having other players draw
	is not originally part of this function to test for.

cardCouncilRoom(): results ended in a bug, the card modifies currentPlayer buys, cards drawn, and playedCount
This function also changes other players card count, as it allows them to draw one. each player starts
with one card in hand, and 0 buys.

	Expected: +4 to currentPlayer, +1 to all other players, -1 card played
	expected size(currentPlayer) = +4 -1 = 4
	expected size(otherPlayer) = +1 = 2
	
	Results: 
	size(currentPlayer) = 5
	size(otherPlayer) = 2
	
	The result shows the player draws one extra card. Looking at the code, it cycles through
	all current players in the game, and allows them all to draw one (for otherPlayer).
	This loop doesn't add and exception for currentPlayer to not draw during this. Results in
	the extra drawn card, making the result 5.

cardAdventurer(): results ended up in a bug, the card adds two treasures to the currentPlayer hand
This function also is removed once it is played, and removed two cards from the deck (two treasures)
While this card gave the player two cards, coin changes were not in line to the expected values

	expected: 1 adventurer in hand, discard, and draw 2 copper.
	expected hand size = 1 -1  +2 (treasures) = 2
	expected deck size = 3 -2; (treasures drawn)
	expected coins = 2; (2 copper gained)
	
	results: -2 deck, -1 hand, +1 coin
	result hand size = 2
	result deck size = 1
	coins returned = 1.
	
	The results show that the treasure that was drawn isn't a coin, like it's defined to be.
	The treasure table in cardAdventurer() shows that estate is a card that is eligible to be
	drawn, and against the basic logic of Adventurer.
	
	
*/
