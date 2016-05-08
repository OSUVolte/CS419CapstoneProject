Name: Lauren Miller
Class: CS362
Assighnment: Assignment 3
Date: 4/23/2016

I created unit tests for four functions in dominion.c and four cards, as required. The tests were for drawCard, discardCard, fullDeckCount, buyCard, Smithy, Adventurer Sea Hag, and Village. Given the lack of documentation for the functions and because I wrote them first, (so I was less familiar with the program), the unit tests for the functions were relatively more complicated than those for the cards, with me guessing, a little, at precisely what they were supposed to accomplish. I'm a little less confident in the bugs found for these. Nevertheless, here are the bugs my tests found in each unit test:

drawCard
	•For the first player only the expected hand and deck counts were off, as this first player started with five cards already drawn. This was true no matter how many other players were in the game. It might reflect some un-noticed quirk of the game initialization function, as this was noticed when making tests for other functions and cards. 

discardCard
	•While the handCount for the player was correctly updated after each discard, the discardCount was not. It remained at 0.
	
fullDeckCount
	•No bugs were found.
	
buyCard
	•No bugs were found.
	
Smithy
	•The number of cards added to the players' hands was consistently one more than the expected number of 3, so 4.
	
Adventurer
	•While at least two treasure cards required for the card were added to the player's hand, the total number of cards in the players hand was one higher than it should have been, indicating that either the adventurer card wasn't removed from the player's hand or an additional card, (possibly an additional treasure card although the value was unchecked), was added.
	
Sea Hag
	•The card should have removed one card from every other players' decks, discarded it into their respective discard piles, and added a curse card to the top of the deck. The deck, however, had a net of three cards removed.
	•Addtiionally, the curse card was not added to the top of the other player's deck.
	
Village
	•No bugs were found.




















