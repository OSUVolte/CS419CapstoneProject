Brianna Carter
documentation.c
4/10/16

Smithy: The smithy card allows the user to draw 3 additional cards. The code is a simple for loop that calls the 
draw card method three times and upon completion calls the discard card method on the smithy card to place it in 
the discard pile. 

			    case smithy:
			      //+3 Cards
			      for (i = 0; i < 3; i++)
				{
				  drawCard(currentPlayer, state);
				}
						
			      //discard card from hand
			      discardCard(handPos, currentPlayer, state, 0);
			      return 0;


Adventurer: The adventurer card has the player reveal cards from their deck until they get two treasure cards.
Those two treasure cards are added to their hand and the cards that were revealed are placed in the discard pile. 
If the deck is empty before two treasures are revealed, the discard pile is shuffled and placed in the deck.
This code keeps track of how many treasures are revealed, checks the deck count and shuffles if it is empty.
The draw card method is called, if it is a treasure, it is indicated and another card is drawn. If it is not 
a treasure, it is added to a temporary hand and removed from the players hand (it was added within the drawCard method).
As soon as two treasure cards are found, each card in the temporary hand is added to the discard pile. 

			    case adventurer:
			      while(drawntreasure<2){
				if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
				  shuffle(currentPlayer, state);
				}
				drawCard(currentPlayer, state);
				cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
				if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
				  drawntreasure++;
				else{
				  temphand[z]=cardDrawn;
				  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
				  z++;
				}
			      }
			      while(z-1>=0){
				state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
				z=z-1;
			      }
			      return 0;

Discard card: This method removes a played card from the players hand and put it into the discard (played card) pile 
at the end of the action turn. This has a flag indicating if the card type is trashed or placed in the played card pile. 
If the card is not trashed, the card is added to the played pile and its hand position is set to -1. The players hand is 
rearranged so there are no gaps in the array, if the played card was at the end or it was the only card in the hand, the 
hand count is simply reduced by one. If the played card was in the middle of the hand, the last card in the hand is moved 
to the empty location and the hand cound it reduced by one.  
The trashing of a card is handled in the appropriate case in the cardEffect method. 


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
				  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
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


UpdateCoins: Each time a player draws a new hand before their turn the updateCoins method is called 
so the amount of money the player can spend that turn is up to date. If a player draws an extra card 
as the result of an action card, the method is called again to update in case more coins were drawn.
The bonus variable is for action cards that say to gain a card up to x amount, x is added to the coin 
total so the player can purchase that card. The method loops over the players hand and assigns values 
based on which cards are available (copper, silver, or gold). 


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