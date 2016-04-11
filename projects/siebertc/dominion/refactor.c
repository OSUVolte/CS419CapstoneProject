/*

Author: 	Charles Siebert
Class:	CS362-400
Date:	4/10/16 
File:	refactor.c

Description: A document describing changes made in dominion.c and dominion.h files. These changes are
	to show and describe the changes in making the switch statements in cardEffects() into separate
	functions for kingdom cards, including Smithy and Adventurer.

Changes Made:
	
	cardAdventurer() : 
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == estate)
		
		this line incorrectly states that "estate" is a treasure to be drawn by the Adventurer Card.
		Won't properly draw two treasure cards as it should.
		
	cardSmithy() : 
		for (i = 0; i <= 3; i++)
		
		this line makes it so it loops the drawCard function four times, instead of 3, as stated for
		the Smithy card.
		
	cardVillage() : 
		drawCard(state->whoseTurn + 1, state);
		
		This line makes the village card draw one for the next player, instead of the currentPlayer.
		
	cardCouncilRoom() : 
		for (i = 0; i < state->numPlayers; i++) {
			drawCard(i, state);
		}
		
		these lines make it so when cardCouncilRoom is played, the currentPlayer will get 5 total cards
		and each player will still get one card drawn to them. It basically omits the check condition statements
		if i != currentPlayer.
		
	cardMine() : 
		gainCard(choice2, state, 1, currentPlayer);
		
		this line makes it so when a card is chosen, gainCard is flagged to put the card into the deck
		as opposed to putting it into the player's hand. 
*/