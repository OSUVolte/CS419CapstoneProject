
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Dominion Documentation
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//	Card: Smithy Card
//
//	Action: When played, the Smithy card adds 3 cards to the player's hand
//			from a player's deck.
//			Using the Smithy card uses up one action.
//
//	Code:
//
//	The below code fire when the card ID is smithy 
case smithy:

	//for loop runs 3 times
	for (i = 0; i < 3; i++)
	{
		
		//Each time the loop runs, the function `drawCard` is called
		// which moves a card from the player's deck to his hand
		drawCard(currentPlayer, state);
	}

	//Then, the function `discardCard` is called once
	// which moves this card to the player's deck
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// 
//	Card: Adventurer Card
//
//	Action: When played, the Adventurer card puts the next two treasure cards in your
//			deck into your current hand, while discarding any cards in-between.
//
//	Code:
//
//	The below code fire when the card ID is adventurer
case adventurer:

	//This loop continues to run while the variable `drawntreasure` is less than 2
	while(drawntreasure<2){
		
		//First, check to see if the player's deck is empty
		if (state->deckCount[currentPlayer] <1){
			
			//If the deck is empty, the function `shuffle` is called
			// which will shuffle the discard pile and move it to the deck
			shuffle(currentPlayer, state);
		}
		
		//The `drawCard` function is called
		// which moves a card from the top of a player's deck to his hand
		drawCard(currentPlayer, state);
		
		//The variable `cardDrawn` is set to the last card that was drawn
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
		
		//If the most recent card drawn was gold, silver, or copper
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			
			//Then increase the `drawntreasure` variable by one
			// and do not alter the player's hand otherwise
			drawntreasure++;
		
		//If the most recent card drawn was NOT gold, silver, or copper
		else{
			
			//Then copy it into an array called `temphand`, which will be discarded at the end of
			// the process
			temphand[z]=cardDrawn;
			
			//Set the player's handCount back by one to exclude the drawn non-treasure card
			state->handCount[currentPlayer]--;
			
			//Increment the counter for the array `temphand`
			z++;
		}
	}
	
	//This clean-up step will go through each card of the `temphand` array
	while(z-1>=0){
		
		//add each card to the player's discard pile
		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; 
		
		//increment the counter
		z=z-1;
	}
	return 0;			
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// 
//	Function: discardCard()
//
//	Inputs:
//		int handPos: This card's position in the player's hand
//		int currentPlayer: ID of the player that is "using" this function
//		struct gameState: A pointer to a struct containing all important data to the gameState
//		int trashFlag: A binary flag indicating if this card is being trashed
//
// 	Description:
//		First, a test is run to check if this card is being trashed.
//		If the card is NOT being trashed, then the card is added to the `playedCards` array
//		
//		Next, the value of this card in the player's hand is set to -1, meaning it no longer playable
//
//		Then the last if statement removes this card from the player's hand
//			First, if this card's position `handPos` is equal to the last card in then hand
//				Then the player's `handCount` is reduced by one, making the last card inaccessible
//			Next, if the player only has one card in his hand,
//				Then the player's `handCount` is reduced by one, making the last card inaccessible
//			Finally, if there are more than one cards in his hand, and this card is not the last
//				Three steps take place:
//					1) This card is replaced by the last card in the hand
//					2) The value of the last card is set to -1, meaning it is no longer playable
//					3) The player's `handCount` is reduced by one, make the last card inaccessible
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// 
//	Function: updateCoins()
//
//	Inputs:
//		int player: ID of the player that is "using" this function
//		struct gameState: A pointer to a struct containing all important data to the gameState
//		int bonus: Count of bonus coins to be added this turn
//
// 	Description:
//		First, the coin count for this turn is reset by setting `coins` to zero
//		Next, coins get added by the amount of treasure cards in the player's hand
//			By starting a for loop, that goes from zero to the count of the player's hand
//				For each card,
//					Copper increases coins by 1
//					Silver increases coins by 2
//					Gold increases coins by 3
//	
//		Finally, at the end, coins are increase by any bonus coins passed into the function
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//































