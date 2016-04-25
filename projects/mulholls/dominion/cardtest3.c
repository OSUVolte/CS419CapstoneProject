void villageCard(struct gameState* state, int currentPlayer, int handPos){

      drawCard(currentPlayer, state);
      state->numActions = 2;
			
      //discard played card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return;
}


