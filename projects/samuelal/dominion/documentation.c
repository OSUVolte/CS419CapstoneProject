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

discardCard()
updateCoins()