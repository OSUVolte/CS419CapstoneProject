/************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  documentation.c
** Date:  4/8/16
** Due Date: 4/10/16
** Description:  Documentation for/of...
**		1. Smithy Card Source
**		2. Adventurer Card Source
**		3. discardCard() Method
**		4. updateCoins() Method
**  Document Requirements:  Must Contain 100 Words
*************************************************************/


/************************************************************
** SMITHY SOURCE - For Reference - From dominion.c
*************************************************************/

case smithy:
  
		//+3 Cards
	  
		for (i = 0; i < 3; i++)
		{
			drawCard(currentPlayer, state);
		}
			
		//discard card from hand
		discardCard(handPos, currentPlayer, state, 0);
		
    return 0;

/************************************************************
** SMITHY DESCRIPTION:  
**
** When the Smithy card is chosen as an action card, the user
** draws three additional cards via the drawCard method. The 
** action is controlled via a for loop which loops from 0 to 
** 2 for a total of 3 iterations. Once the loop has completed 
** and the player's current hand/"state" has been updated by 
** drawCard(), a call to the function discardCard() is made 
** to remove the "used" Smithy card from the player's current
** hand. 
**
** NOTE: 
** Action points are decremented prior to a call to cardEffect
** in the playCard() function.
*************************************************************/



/************************************************************
** ADVENTURER SOURCE - For Reference - From dominion.c
*************************************************************/

case adventurer:
      
	while(drawntreasure<2)
	{
		//if the deck is empty we need to shuffle discard and add to deck
		if (state->deckCount[currentPlayer] <1)
		{
			shuffle(currentPlayer, state);
		}
		
			drawCard(currentPlayer, state);
			
			//top card of hand is most recently drawn card.
			cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
			
	
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else
		{
			temphand[z]=cardDrawn;
			
			//this should just remove the top card (the most recently drawn one).
			state->handCount[currentPlayer]--; 
			z++;
		}
    }
	
    while(z-1>=0)
	{
		// discard all cards in play that have been drawn
		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; 
		z=z-1;
    }
	
return 0;

/************************************************************
** ADVENTURER DESCRIPTION 
**
** When the Adventurer card is played as an action card, a 
** while loop is used to make calls to the drawCard() function
** until the drawntreasure variable is incremented to 2. The 
** drawntreasure var is incremented when copper, silver, or 
** gold is drawn. At this point, the first while loop will end.  
** 
** NOTE: Within the initial while loop there is a conditional 
** statement that will cause a shuffle if the player's current 
** deck becomes "empty" within the loop. The initial while 
** loop also builds a "temp" hand holding the cards that will 
** be discarded once two treasure cards are drawn.  
**
** The second while loop removes all non treasure cards drawn 
** during the initial while loop   
*************************************************************/



/************************************************************
** discardCard() SOURCE - For Reference - From dominion.c
*************************************************************/

int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
{
	
	//if card is not trashed, added to Played pile 
	if (trashFlag < 1)
    {
		//add card to played pile
		state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
		state->playedCardCount++;
    }
	
		//set played card to -1
		state->hand[currentPlayer][handPos] = -1;
	
  //remove card from player's hand
	if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
	{
		//reduce number of cards in hand
		state->handCount[currentPlayer]--;
    }
	else if ( state->handCount[currentPlayer] == 1 ) 	//only one card in hand
	{
		//reduce number of cards in hand
		state->handCount[currentPlayer]--;
    }
	else 	
    {
		//replace discarded card with last card in hand
		state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
      
		//set last card to -1
		state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
      
		//reduce number of cards in hand
		state->handCount[currentPlayer]--;
    }
	
	return 0;
}

/************************************************************
** discardCard() DESCRIPTION
**
** The discardCard() method is used to manipulate a player's 
** hand state when a card is discarded.  The method begins
** with a conditional statement to check whether or not the 
** card will be "trashed" or placed into "played" cards.
** Once the discarded card has been placed into played cards
** OR not, the state of the current players hand at 
** the discarded card's position is set to -1.  Once this is
** complete, the card is removed by a series of conditional 
** statements which modify the state of the current players 
** hand, keeping mind to check for situtations in which the 
** current player's last card is played and when the current
** player only has a single card in his/her hand.  In all   
** Other sitations, the discarded card is replaced with the
** last current card in the hand and the player's handCount
** is decremented.
*************************************************************/



/************************************************************
** updateCoins() SOURCE - For Reference - From dominion.c
*************************************************************/

int updateCoins(int player, struct gameState *state, int bonus)
{
	int i;
	
	//reset coin count
	state->coins = 0;

	//add coins for each Treasure card in player's hand
	for (i = 0; i < state->handCount[player]; i++)
    {
		if (state->hand[player][i] == copper)
		{
			state->coins += 1;
		}
		else if (state->hand[player][i] == silver)
		{
			state->coins += 2;
		}
		else if (state->hand[player][i] == gold)
		{
			state->coins += 3;
		}	
    }	

	//add bonus
	state->coins += bonus;

  return 0;
}

/************************************************************
** updateCoins() DESCRIPTION
**
** The update coins method is used to "update" the total coin
** value that is present in a player's hand. The total value
** is initialized, and a for loop is used to loop through a 
** player's hand to count the number of copper, silver, and 
** gold cards are present and increment the "total" based 
** their respective value.  Once the for loop is complete, 
** the bonus which can be added to the total from a card 
** effect is factored into the total. 
**
** NOTE: The total value of the treasure cards is represented
** in the player's state->coins 
  
*************************************************************/
