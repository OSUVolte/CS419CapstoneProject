/*******START 5 CUSTOM CARD FUNCTIONs******/

int playAdventurer(struct gameState *state, int handPos, int currentPlayer) {
  int drawnTreasure = 0;
  int cardDrawn;
  int z = 0; //counter for temp hand
  int temphand[MAX_HAND];
  
  while (drawnTreasure < 2) {
    if (state->deckCount[currentPlayer] < 1) {
      //if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];
    //top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      drawntreasure++;
    else {
      temphand[z] = cardDrawn;
      state->handCount[currentPlayer]--; 
      //this should just remove the top card (the most recently drawn one).
      z++;
    }
  }
  return 0;
}

int playSmithy(struct gameState *state, int handPos, int currentPlayer) {
  int i = 0;
  
  //+3 Cards
  for (i = 0; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  }
  
  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}

int playVillage(struct gameState *state, int handPos, int currentPlayer) {
  //+1 Card
  drawCard(currentPlayer, state);
  
  //+2 Actions
  state->numActions = state->numActions + 2;
  
  //discard played card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}

int playRemodel(struct gameState *state, int handPos, int currentPlayer, int trashChoice, int getChoice) {
  int i = 0;
  int j = state->hand[currentPlayer][trashChoice];  //store card we will trash

  if ( (getCost(state->hand[currentPlayer][trashChoice]) + 2) > getCost(getChoice) )
  {
    return -1;
  }

  gainCard(getChoice, state, 0, currentPlayer);

  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);

  //discard trashed card
  for (i = 0; i < state->handCount[currentPlayer]; i++) {
    if (state->hand[currentPlayer][i] == j) {
        discardCard(i, currentPlayer, state, 0);			
        break;
    }
	}
  
  return 0;
}

int playMine(struct gameState *state, int handPos, in currentPlayer, int trashChoice, int getChoice) {
  int i = 0;
  int j = state->hand[currentPlayer][trashChoice];  //store card we will trash

  if (state->hand[currentPlayer][trashChoice] < copper || state->hand[currentPlayer][trashChoice] > gold)
	{
	  //treasure card not chosen to trash
    return -1;
	}
		
  if (getChoice > treasure_map || getChoice < curse)
	{
	  //not a valid card
    return -1;
	}

  if ( (getCost(state->hand[currentPlayer][trashChoice]) + 3) > getCost(getChoice) )
	{
	  return -1;
	}

  gainCard(getChoice, state, 2, currentPlayer);

  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);

  //discard trashed card
  for (i = 0; i < state->handCount[currentPlayer]; i++)
	{
	  if (state->hand[currentPlayer][i] == j)
	    {
	      discardCard(i, currentPlayer, state, 0);			
	      break;
	    }
	}
			
  return 0;
}



/*******END 5 CUSTOM CARD FUNCTIONS********/
