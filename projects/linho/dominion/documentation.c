//
//  documentation.c
//  CS 362
//  HW 2
//  Created by Hong Lin
//  Student ID: 932-050-646
//

smithy:
    The smithy card lets player take 3 more card from the pile.
        for (i = 0; i < 3; i++)
        {
            drawCard(currentPlayer, state);
        }
    It uses drawCard 3 times to draw a new card 3 times.
        discardCard(handPos, currentPlayer, state, 0);
    It then use discardCard to discard itself.


adventurer:
    The adventurer card lets player to reveal card from player's deck until the player reveal 2 treasure cards.
    Then put the treasure card into hands and discard other revealed cards.

        while(drawntreasure<2){
    While the number of treasure card is less than 2.
            
        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
            shuffle(currentPlayer, state);
        }
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
    If the deck is empty then shuffle player's card and add cards to deck.

            if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
                drawntreasure++;
            else{
                temphand[z]=cardDrawn;
                state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
                z++;
            }
    If the card drawn is a treasure card, then add 1 to drawntreasure. Otherwise just remove the top card and
    continue.

            while(z-1>=0){
                state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
                z=z-1;
            }
    Discard all cards.
            
discardCard:
    discardCard is a function that discard the card from player's hand and put it into played pile.
            //if card is not trashed, added to Played pile
            if (trashFlag < 1)
            {
                //add card to played pile
                state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
                state->playedCardCount++;
            }
    If a card is not trashed and is discarded, then it adds the card into played pile.
            //set played card to -1
            state->hand[currentPlayer][handPos] = -1;
    Then set the hand position to -1.
            //remove card from player's hand
            if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
            {
                //reduce number of cards in hand
                state->handCount[currentPlayer]--;
            }
            else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
            {
                //reduce number of cards in hand
                state->handCount[currentPlayer]--;
            }
            else
            {
                //replace discarded card with last card in hand
                state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
                //set last card to -1
                state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
                //reduce number of cards in hand
                state->handCount[currentPlayer]--;
            }
    3 situations will be considered when discard the card from hand. If it is the last card in hand then reduce
    number of cards in hand. If there is only one card in hand then reduce number of cards in hand. Otherwise
    replace the discarded card with last card in hand and first set the last card to -1, then reduce the number
    of cards in hand.
            
            

updateCoins:
    updateCoins is a function to update the number of coins the player has for now.
    For situations like drawing card, there might be treasure cards drawn so updateCoins will be called to
    update the number of coins.be
    For situation of buying cards or coins, it also need to be called to update the number of coins after the
    action is made.

        //reset coin count
        state->coins = 0;
    Reset the coin count first.
        for (i = 0; i < state->handCount[player]; i++)
        {
            if (state->hand[player][i] == copper)
            {
                state->coins += 1;
            }
            else if (state->hand[player][i] == silver)
            {
                state->coins += 2;
            }
            else if (state->hand[player][i] == gold)
            {
                state->coins += 3;
            }
        }
    Add coins for treasure cards in hand for copper-plus 1 coin, silver-2 coins and gold-3 coins.
        //add bonus
        state->coins += bonus;
    Then add bonus.
