Card:  Smithy
    Cost:  4
    Rules: 
        1:  This card is played during the action phase
        2:  Allows the player to immediately draw an additional 3 cards 
            from their deck and add them to the player's hand.
        3:  The card is then discard into the played cards pile.
 
 //--------------------------------------------------------------------------------------------
Card:  Adventurer
    Cost:  6
    Rules:
        1: This card is played during the action phase
        2: Allows the player to reveal cards from their deck until it reveals 2 treasure cards
        3: The treasure cards are added to the player's hand.
        4: The other revealed cards from the deck are placed in the discard pile after finished
           with revealing cards.
        5: If the deck is empty before 2 treasure cards are revealed, shuffle the player's 
           discarded pile and add them to deck. 
        6: Don't shuffle in the revealed cards.
        7: If you run out of cards after shuffling and still have less than two treasure cards, 
           then you get just the amount found.
        8: The card is then discard into the played cards pile.
		
//--------------------------------------------------------------------------------------------
Function:  discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)

    Rules:
        1: If the card is not trashed, add the card to the played cards pile 
	   and increment the number of played cards.
	2: Discard card from player's hand.
	    a. if the card is in the last position of the player's hand or the card is the
	       the only card in the player's hand, decrement the player's hand count.
	    b. Otherwise, 
	       i.   move the last card in the player's hand to position of the discarded card.
              ii.  decrement the number of cards in the player's hand.
	 
//--------------------------------------------------------------------------------------------	 
Function:  updateCoins(int player, struct gameState *state, int bonus)

    Rules:
        1:  Add up the value of all Treasure cards in the player's hand
        2:  Add value from step 1 with bonus
        3:  Set coin count to value from step 2.
	
	
	
