/* Corey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 2
 * April 10, 2016
 * documentation.c
 */

 // Documentation:

 // Smithy Card
  switch( card )
    }
	// ...
	case smithy:
		for (i = 0; i < 3; i++)
	}
		drawCard(currentPlayer, state);	
	}
		discardCard(handPos, currentPlayer, state, 0);
		return 0;
	// ...
    }
 // If the card value is "smithy", the code calls the drawCard function three times. 
 // Each time the drawCard function is called, it adds the newly drawn card to the 
 // player's current hand of cards. The code then calls the discardCard function to 
 // remove the smithy card that was just played by the player from the player's 
 // current hand.


 // Adventurer Card
  switch( card )
    }
	// ...
	case adventurer:
		while(drawntreasure<2){
			if (state->deckCount[currentPlayer] <1){
				shuffle(currentPlayer, state);
			}
			drawCard(currentPlayer, state);
			cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
			if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
				drawntreasure++;
			else{
				temphand[z]=cardDrawn;
				state->handCount[currentPlayer]--;
				z++;
			}
      		}
      		while(z-1>=0){
			state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; 	
			z=z-1;
      		}
      		return 0;    
	// ...
    }
 // While the number of treasure cards drawn is less than two, the first while loop runs. 
 // If the deck happens to be empty, the shuffle function is called which shuffles any 
 // previously discarded cards and puts them onto the deck. Otherwise, the code draws a 
 // card via drawCard function, then inserts it at the top of the player's current hand.
 // The code checks to see if the card most recently drawn is a copper, silver, or gold (a
 // treasure card). If the most recently drawn card is treasure, drawntreasure variable is
 // incremented and the while loop continues. Otherwise, the top card is removed and the
 // variable z is incremented. Once drawntreasure == 2, the first while loop will end and
 // the next while loop will begin. If the variable z - 1 is greater than or equal to zero,
 // the code discards the top card from the players hand until all the drawn non-treasure
 // cards are discarded from the player's current hand.


 // discardCard() method
  int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
    { 
	if (trashFlag < 1){
                state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
		state->playedCardCount++;
        }                       	
       	state->hand[currentPlayer][handPos] = -1;    	
	if ( handPos == (state->handCount[currentPlayer] - 1) ){
	        state->handCount[currentPlayer]--;
        }
        else if ( state->handCount[currentPlayer] == 1 ){
		
                state->handCount[currentPlayer]--;
        }
        else{ 	
                state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
                state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
                state->handCount[currentPlayer]--;
        }
	return 0;
    }
// The discardCard function takes in four parameters: handPos is the card to be discarded's position,
// the currentPlayer who is discarding the card, a pointer to the current game state, and the a
// trashFlag indicator. If the trashFlag indicator is less than 1, then the card was played, not trashed
// and the card is placed onto the played pile and the card's status is then set to -1 and removed from
// the current hand. Otherwise, the card is being discarded. Remove it from the player's current
// hand and reduce the count of the cards in the hand. If it is the last card in the hand, reduce the
// count. The function then replaces the discarded card with the next card in the hand. If there are no
// cards left in the hand, the hand state is set to -1.


 // updateCoins() method

int updateCoins(int player, struct gameState *state, int bonus)
  {
	int i;
	state->coins = 0;
	for (i = 0; i < state->handCount[player]; i++){
		if (state->hand[player][i] == copper){
			state->coins += 1;
	  	}
		else if (state->hand[player][i] == silver){
			state->coins += 2;
		}
		else if (state->hand[player][i] == gold){
			state->coins += 3;
		}	
	}	
	state->coins += bonus;
	return 0;
  }
// The updateCoins function takes in three parameters: player which is the current player identifier,
// a pointer to the current game state, and a bonus integer. Coins is initialized to zero. The for
// loop iterates through the number of cards in the player's current hand ands "coins" values for each
// treasure card in the player's current hand. If the current card is a copper, 1 is added to coins. 
// If the current card is silver, 2 is added to coins. If the current card is gold, then 3 is added
// to coins. Once the loop has iterated through the player's hand and a coin value is established,
// a bonus value is added to the value of coins and is returned to the player.


