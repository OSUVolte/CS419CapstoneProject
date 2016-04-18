<<<<<<< HEAD
//Adventurer Scenario
//The Adventurer card allows the player to draw cards from his or her deck until they have obtained two treasure cards. They may then 
//keep those two treasure cards and discard the rest.
/*case adventurer:
      while(drawntreasure<2){
	if (state->deckCount[currentPlayer] <1){
	  shuffle(currentPlayer, state);
	}
	//We check to see if the deck is empty. In the case that it is we will shuffle, draw the card and then discard it.
	drawCard(currentPlayer, state);
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
	//First, you draw a card from the top of the deck
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	  drawntreasure++;
	else{
	  temphand[z]=cardDrawn;
	  state->handCount[currentPlayer]--;
	  z++;
	}
	//Remove cards until two treasure cards have been revealed
      }
      while(z-1>=0){
	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; 
	z=z-1;
      }
	 //Gets the cards that the player has drawn and then discards them.
      return 0;
	  */
	  
//The Smithy
//Straight forward card that allows you to draw three cards from the deck and add them to your hand.
/*
	for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
*/

/*
	DiscardCard function
	
	This function takes card(s) flagged as trash cards and then removes them from the player's hand. Also accounts for situations where cards get replaced.
	Also worth noting, there is a if statement dedicated to the scenario in which the player only has one card in their hand. In this case the removed card
	is also replaced.
*/

/*
updateCoins function

//This function resets the coins to be added to the player's total and then tallies up the next set of treasures to be added from the player's hand.

*/
=======
// Osbaldo Esquivel
// CS 362
// 09APR2016
// Assignment 2


1. According to the Smithy code, the cost of this card is four coins, which makes it a somewhat valuable card. With this card, a user is allowed to add three cards into their hand. The card is added to the user's deck using the playSmithy function which uses a simple loop to pick three cards from the deck. The discard function is then called to discard the Smithy card from the user's deck.

2. According to the Adventurer code, this card is worth six coins which makes it a valuable card. This card allows the user to draw cards until two treasure cards are chosen and these cards are then added to the user's deck. This works by using the drawCard function which is similar to the playSmithy function in that it loops until two treasure cards are picked.

3. The discardCard() function has four parameters it accepts: the index of the card in the user's deck as an integer (handPos), the current player as an integer, the state of the game as a struct, and a flag for if the card was trashed as an integer. If a card is not trashed which is indicated by the flag being less than one, then add it to the player's deck. Then, a card will be removed from the user's deck and the count will be decremented.

4. The updateCoins() function is fairly simple and accepts three parameters: the player integer, the state of the game as a struct, and an integer signifying a bonus. First, the coin count is reset and then coins are added to the player's count for each treasure card along with the bonus.
>>>>>>> 618c0030c8e0f4e3a294dc1563a59e22f8404734
