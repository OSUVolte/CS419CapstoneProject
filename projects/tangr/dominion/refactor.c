playSmithy 
draws 4 cards (not 3)
discards smithy card and next card (not only smithy)
//////////////////////////////////////////////////////////////////////////
playAdventurer
draws 2 Treasures
if cards are shuffled more than once
	reduce Treasures drawn by 1
(note I think i figured out how to resolve the possible infinite loop bug i thought of)

just in case, 
smithy counts as 1
////////////////////////////////////////////////////////////////////////
playVillage
draws an extra card
discards an extra card
gain 3 rather than 2 actions
////////////////////////////////////////////////////////////////////////
playFeast
gain a card up to a cost of 4 rather than 5
///////////////////////////////////////////////////////////////////////

// added functions


int playAdventurer(struct gameState *state)
{
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
}

/////////////////////////////////////////////////////////////////////

int playSmithy(struct gameState *state, int handPos)
{
  //+3 Cards
  for (i = 0; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  }
      
  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);
  discardCard(handPos, currentPlayer, state, 0);
}

////////////////////////////////////////////////////////////////////////

int playVillage(struct gameState *state, int handPos)
{
      //+1 Card
      drawCard(currentPlayer, state);
      
      //+2 Actions
      state->numActions = state->numActions + 2;
      
      //discard played card from hand
      discardCard(handPos, currentPlayer, state, 0);
}

///////////////////////////////////////////////////////////////////////////

int playFeast(struct gameState *state, int choice1)
{
      //gain card with cost up to 5
      //Backup hand
      for (i = 0; i <= state->handCount[currentPlayer]; i++){
  temphand[i] = state->hand[currentPlayer][i];//Backup card
  state->hand[currentPlayer][i] = -1;//Set to nothing
      }
      //Backup hand

      //Update Coins for Buy
      updateCoins(currentPlayer, state, 5);
      x = 1;//Condition to loop on
      while( x == 1) {//Buy one card
  if (supplyCount(choice1, state) <= 0){
    if (DEBUG)
      printf("None of that card left, sorry!\n");

    if (DEBUG){
      printf("Cards Left: %d\n", supplyCount(choice1, state));
    }
  }
  else if (state->coins < getCost(choice1)){
    printf("That card is too expensive!\n");

    if (DEBUG){
      printf("Coins: %d < %d\n", state->coins, getCost(choice1));
    }
  }
  else{

    if (DEBUG){
      printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
    }

    gainCard(choice1, state, 0, currentPlayer);//Gain the card
    x = 0;//No more buying cards

    if (DEBUG){
      printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
    }

  }
      }     

      //Reset Hand
      for (i = 0; i <= state->handCount[currentPlayer]; i++){
  state->hand[currentPlayer][i] = temphand[i];
  temphand[i] = -1;
      }
      //Reset Hand
}

////////////////////////////////////////////////////////////////////////

int playCouncil_Room(struct gameState *state, int handPos)
{
        //+4 Cards
      for (i = 0; i < 4; i++)
  {
    drawCard(currentPlayer, state);
  }
      
      //+1 Buy
      state->numBuys++;
      
      //Each other player draws a card
      for (i = 0; i < state->numPlayers; i++)
  {
    if ( i != currentPlayer )
      {
        drawCard(i, state);
      }
  }
      
      //put played card in played card pile
      discardCard(handPos, currentPlayer, state, 0);
}

//end of added functions for dominion.c