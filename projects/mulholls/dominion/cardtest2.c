void smithyCard(struct gameState* state, int currentPlayer, int handPos){
   int cardDrawn;
   int temphand[MAX_HAND];

   int i;
   //+3 Cards
   for (i = 0; i < 3; i++)
   {
      drawCard(currentPlayer, state);
      cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
      temphand[i] = cardDrawn;
   }
   
   for(i = 0; i < 3; i++){
      cardDrawn = temphand[i];		  
      //discard card from hand
      discardCard(handPos, currentPlayer, state, cardDrawn);
   }
   return;
}


