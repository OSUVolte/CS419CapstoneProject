//Shawn Seibert
//Card Test 1
//adventureCard() 

int adventureCard(int handPos, int currentPlayer, struct gameState *state)
{
    int cardDrawn = 0;
	int temphand[MAX_HAND];
	int drawntreasure = 0;
	int z = 0;
	
	while(drawntreasure<2){
	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
	  shuffle(currentPlayer, state);
	}
	drawCard(currentPlayer, state);
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]]-1;//top card of hand is most recently drawn card.

	
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
}
