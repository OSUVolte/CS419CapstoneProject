Assignment 2 - refactor.c

Lauren Miller
Software Engineering II (CS362)
4/24/2016

The refactored cards are Adventurer, Smithy, Council Room, Sea Hag, and Treasure Map. Their implementation is below. Comments in the code indicate where errors have been introductd. These comments were not included in dominion.c. The errors for these functions are as follows:

adventurer_card: z, the counter of cards in the temp hand is not incremented when a card is added to temp_hand. The unit test for this function  indicated that while at least two treasure cards required for the card were added to the player's hand, the total number of cards in the players hand was one higher than it should have been, indicating that either the adventurer card wasn't removed from the player's hand or an additional card, (possibly an additional treasure card although the value was unchecked), was added.

smithy_card: the loop adding cards increments until i <= 3 instead of until i < 3, so that 4 cards are drawn rather than the desired 3. This is demonstrated in the unit tests for Assignment 3.

council_room_card: in council room, the loop letting other players other than the current one draw an extra card only increments until the currentPlayer, rather than through all other players

treasure_map_card: the if loop lookng for a treasure card accidently sets state->hand[currentPlayer][i] to treasure_map rather than comparing the two, meaning that incorrect cards may be discarded

//two treasure cards are drawn and the rest of the drawn cards are discarded
//takes the int representing the current player, the pointer to the state of the game, and the temphand array and updates
int adventurer_card(int currentPlayer, struct gameState *state, int *temphand) {
	int drawntreasure = 0;//the number of treasure cards drawn
	int z = 0;// this is the counter for the temp hand
	int cardDrawn;//the array placement of the card drawn
	
	while(drawntreasure < 2){
		if (state->deckCount[currentPlayer] < 1) {//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else{
			temphand[z]=cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			//z++ should be here
		}
    }
    while(z-1>=0){
	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
	z=z-1;
    }
	return 0;
}

//three extra cards are drawn
//takes the int representing the current player, the pointer to the state of the game, the int that is the position of the hand, and a pointer to the current bonus
int smithy_card(int currentPlayer, struct gameState *state, int handPos, int *bonus) {
	int i;
	
	//+3 Cards
    for (i = 0; i <= 3; i++) {//should increment only until i < 3
	  drawCard(currentPlayer, state);
	}
			
	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	
	return 0;
}

//four extra cards are drawn, the number of buys is increased by one, and each other players draws a card
//takes the int representing the current player, the pointer to the state of the game, and the int that is the position of the hand
int council_room_card(struct gameState *state, int currentPlayer,int handPos) {
	int i;
	
	//+4 Cards
    for (i = 0; i < 4; i++) {
		drawCard(currentPlayer, state);
	}
			
	//+1 Buy
	state->numBuys++;
		
	//Each other player draws a card
	for (i = 0; i < currentPlayer; i++)//should increment until state->numPlayers
	{
	    if ( i != currentPlayer ) {
	      drawCard(i, state);
	    }
	}
			
	//put played card in played card pile
	discardCard(handPos, currentPlayer, state, 0);
	
	return 0;
}

//trashes the treasure map currently in play and another treasure map in hand in exchange for 4 gold
//takes the int representing the current player, the pointer to the state of the game, the int that is the position of the hand
int treasure_map_card(int currentPlayer, struct gameState *state, int handPos) {
	int i;
	
	//search hand for another treasure_map
    int index = -1;
    for (i = 0; i < state->handCount[currentPlayer]; i++)
	{
		if (state->hand[currentPlayer][i] = treasure_map && i != handPos) { //accidently sets state->hand[currentPlayer][i] to treasure_map rather than comparing the two
			index = i;
			break;
		}
	}
    if (index > -1)
	{
		//trash both treasure cards
		discardCard(handPos, currentPlayer, state, 1);
		discardCard(index, currentPlayer, state, 1);

		//gain 4 Gold cards
		for (i = 0; i < 4; i++) {
			gainCard(gold, state, 1, currentPlayer);
		}

		//return success
		return 1;
	}
			
	//no second treasure_map found in hand
	return -1;
}

//every other player discards the top card of their deck in exchange for a curse card
//takes the int representing the current player and the pointer to the state of the game
int sea_hag_card(int currentPlayer, struct gameState *state, int handPos, int *bonus) {
	int i;
	
	for (i = 0; i < state->numPlayers; i++){
		if (i != currentPlayer){
			state->discard[i][state->discardCount[i]] = state->deck[i][state->deckCount[i]--];			    state->deckCount[i]--;
			state->discardCount[i]++;
			state->deck[i][state->deckCount[i]--] = curse;//Top card now a curse
		}
    }
	
	return 0;
}