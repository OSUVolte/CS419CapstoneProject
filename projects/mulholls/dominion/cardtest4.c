void stewardCard(struct gameState* state, int currentPlayer, int handPos, int choice1, int choice2, int choice3){
   if (choice1 == 1)
   {
      //+2 cards
      drawCard(currentPlayer, state);
      drawCard(currentPlayer, state);
   }
   else if (choice1 == 2)
   {
      //+2 coins
      state->coins = state->coins + 2;
   }
   else
   {
      //trash 2 cards in hand
      discardCard(choice2, currentPlayer, state, 1);
      discardCard(choice3, currentPlayer, state, 1);
   }
	       
   //discard card from hand
   discardCard(handPos, currentPlayer, state, 0);
   return;
}


