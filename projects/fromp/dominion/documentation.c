************************   Documentation.c **************************************
*smithy
*Description:
*This action card gets three cards from the draw pile and adds them to the player's hand *using a for loop and the drawCard function. Then, a card is discarded from the player's hand *using the discardCard function. Finally, 0 is returned.
*
*adventurer
*Description:
*The purpose of this card is to: Draw cards from your deck until you have drawn 2 treasure *cards. Put those Treasure cards into your hand and discard the other cards. 
*This is implement in the code using the following process.
*This action card first checks the state of the player's deck and shuffles the discard pile *using the shuffle function and adds it to the deck. Next a card is drawn for the current *player using the drawCard function. A card is then “drawn” by setting the cardDrawn variable *equal to the top most recently drawn card (which is accessed by taking the last element of *the current player array in the hand array in the state structure). If cardDrawn is a *copper, silver, or gold card, drawntreasure is incremented, otherwise cardDrawn is added to *the temphand array and the current player's handCount (which is part of the state structure) *is decremented. The index for temphand is then incremented. Finally, all cards in temphand *are discarded using a while loop to move cards from temphand to the current player's discard *array (which is part of the state structure). Finally, 0 is returned.
*
*discardCard() 
*Input: int handPos, int currentPlayer, struct gameState * state, int trashFlag
*Result: Card indicated by handPos is removed from currentPlayer hand and added to discard *pile if trashFlag is less than 1, and currentPlayer's hand is modified to reflect the *discard.
*Description:
*If trashFlag is less than 1, then the card to be discarded (indicated by handPos) is added *to the playedCards array (in the state structure) and the playedCardCount (in the state *structure) is incremented. The discarded card is set equal to -1. 
*Next, the player's hand is adjusted as necessary. If the last card in the hand array was *played (in other words, if handPos equals the handCount of the current player minus one), *the handCount (in the state structure) corresponding to the currentPlayer is decremented. If *there is only one card in the hand, the number of cards in hand is decremented (essentially *setting it equal to zero). Otherwise, the discarded card is replaced with the last card in *the hand, the last card is set to -1, and the number of cards in hand is decremented.
*Finally, 0 is returned.
*
*updateCoins() 
*Input: int player, struct gameState * state, int bonus
*Result: The coins variable (in the state structure) is equal to the sum of all the values of *all the copper, silver, and gold cards plus the bonus.
*Description:
*First the coin count is reset by setting coins (in the state structure) equal to 0. Then, a *for loop is used to check each card in currentPlayer's hand. Each card is checked, and coins *(in the state structure) is incremented by 1 if a card is copper, 2 if a card is silver, and *3 if a card is gold. Once the for loop is completed, the bonus is added to coins. Finally, 0 *is returned.
**********************************************************************************
