Assignment 2

smithy:

for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
discardCard(handPos, currentPlayer, state, 0);
return 0;

-If the smithy card is played, the player who played the card draws three cards and the
smithy card is discarded from the hand. This is implemented by executing the darwCard() method
three times and then executing the discardCard() method which takes as an input the current hand position
which results in the smithy card being discarded from the hand. Returns 0 on success.



adventurer:

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

-Cards are drawn from the deck until 2 treasure cards are revealed which are added to the player's hand. All other 
revealed cards are discarded from the player's hand. This is implemented via a while loop which checks if the player 
has drawn less than 2 treasure cards. If so, the loop executes. An If loop then checks whether the player's deck is empty
and then calls the shuffle() function which shuffles the discard pile and creates a new deck for the player. The player
then draws a card via the drawCard() function. If the card is 1 of 3 possible treasure cards, then the drawntreasure flag
is incremented. If the player does not draw a treasure card, the drawn card is added to a temporary hand and the while 
loop repeats. After 2 treasure cards are drawn, the temporary hand is discarded. Returns 0 on success.

discardCard()
updateCoins()