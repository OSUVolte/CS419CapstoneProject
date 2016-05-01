#tatyana vlaskin
#cs362, spring 2016
#04/10/2016
#documentation.c
#refference: http://wiki.dominionstrategy.com/index.php/



CARDS:

Smithy:

    Smithy is a terminal card, meaning it provides no +Action. This card lets the user to draw 3 additional cards.
    The implementation of the card is a simple for loop that calles the drawCard(currentPlayer, state) method 3 times.
    After 3 cards are drawn, the discardCard(handPos, currentPlayer, state, 0) method is called to discard the smithy
    card to the discarded pile. Taken from the dominion.c file:

			    case smithy:
			      //+3 Cards
			      for (i = 0; i < 3; i++)
				{
				  drawCard(currentPlayer, state);
				}

			      //discard card from hand
			      discardCard(handPos, currentPlayer, state, 0);
			      return 0;


Adventurer:

    Adventure is an action card with the terminal action that digs for treasure cards in the deck. The palayer
    draws cards from their deck until they get 2 treasure cards. The treasure cards are added to the deck of the
    player and the rest of the cards that were revealed are placed in the discard pile. In case the deck is empty
    before the player find 2 treasure cards, the discarded cards are shuffled and placed on the deck. The implementation of the card:
        while
            if the deck is empty before the player find 2 treasure cards, the discarded cards are shuffled and placed on the deck
            player draws the card
            if card that was drawn is copper, or silver, or gold
                increment the treasure count by 1
            else
                place the card in the drawn card pile that will be discarded later
        end while

        while cards are present in the drawn card pile that will be discarded later
            discard card
        end while

    Taken from the dominion.c:
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

METHODS:

Discard card:

    Discards cards from the player. This function can be either called by the card or called at the end of the turn.
    The card discarded can end up in the different piles depending to the value of the trashFlag.
    The trashFlag flag indicats whether the card will be trashed or placed in the played card pile.
    If the trashFlag is set to trash the cards, a card is removed from the game to the trash.
    If the trashFlag is set to discard the card, the card is moved to the players to the discarded pile, the number
    of cards in the players hands is decremented. Taken from the dominion.c file:


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


UpdateCoins:

    This function calculate the total amount of treasure cards that the player has.
    When the player draws new card, the UpdateCoins method is called the update the coin value
    in case the card that was drawn is the coin card. Dending on the treasure[copper, silver, gold ]
    different values are added to the total amount. There is also a bonus value, which is used for action
    cards that has a coin value. Taken from the domunion.c:
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
