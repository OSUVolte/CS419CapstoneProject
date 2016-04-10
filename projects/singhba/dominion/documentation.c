Smithy Card: Smithy Card is action card. It has ability to increase the hand size of player by 
			 drawing 3 cards from deck. So in the file dominion.c inside function cardEffect, player 
			 draws 3 card from the deck using for loop. After drawing 3 cards smithy card is discarded 
			 from player’s hand using discardCard.
Adventure Card: It is also an action card. The effect is to reveal cards from deck until 2 Treasure cards 
				are revealed. Put those Treasure cards in your hand and discard the other revealed card. 
				So in the file dominion.c inside function cardEffect, drawntreasure is set to 0 and player 
				draws the card from deck until the drawntreasure is less than 2 using while loop. Also the 
				condition inside while loop checks if deckCount is less than 1 it shuffles the state for current player. 
discardCard(): This function is used to remove the card from player’s hand. It first checks if card is thrashed or 
				not, if it is not it is added to played pile. 
updateCoins(): This function counts the number of coins based on treasure cards in player’s hand. It also adds the bonus to coins if any.
