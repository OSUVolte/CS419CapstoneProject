

Documentation:
    Cards:
        smithy:
            Card Effect: 
                Add three(3) cards to players hand
                
            Code:
                /**** Found in : dominion.c ****/
                /**** Code Begin ****/
                
                 case smithy:
                    //+3 Cards
                    for (i = 0; i < 3; i++)
                    {
                        drawCard(currentPlayer, state);
                    }
                            
                    //discard card from hand
                    discardCard(handPos, currentPlayer, state, 0);
                    return 0;
                    
                /**** Code End ****/

            Code Breakdown:
                    /**** Code Begin ****/
                    for (i = 0; i < 3; i++)
                    {
                        drawCard(currentPlayer, state);
                    }
                    /**** Code End ****/
                        This for loop calls the method 'drawCard' three(3) times. Each time, the 'currentPlayer' variable
                        is passed by value while the 'state' variable is passed by reference as a pointer. The effect of
                        this is an additional three cards being added to the players hand.
                 
                    /**** Code Begin ****/
                    discardCard(handPos, currentPlayer, state, 0);
                    return 0;
                    /**** Code End ****/
                        The remainder of the case statement first calls 'discardCard'. The 'handPos', 'currentPlayer', and
                        'trashFlag' variables are all passed by value. The 'currentPlayer' variable is passed by reference
                        as a pointer. The effect of this is the current 'smithy' card being removed from the players hand.
                        
                        Finally, the switch statement and method is exited through a return of 0.   
                        
            Notes:
                The declaration/prototype for 'smithy' can be found in dominion.h within the enum Card object.
                The functionality for the 'smithy' card is found in dominion.c as a case within a switch statement.
                
                The card 'smithy' costs 4 coins to purchase. This logic is contained in the dominion.c 
                method 'getCost'.
                
                The logic controlling the card effects of 'smithy' can be found in the dominion.c method 'CardEffect'
                as a case within a switch statement.
        
        
        
        adventurer:
            Card Effect:
                Reveal cards from your deck until two(2) treasure cards are revealed. Put the
                revealed treasure cards into players hand and discard all other revealed cards.
                
            Code:
                /**** Found in : dominion.c ****/
                /**** Code Begin ****/
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
                /**** Code End ****/
                
            Code Breakdown:
                First, a while loop controls the process of revealing cards and either discarding them or putting them into a temporary hand. 
                This continues until 'drawntreasure' (the number of treasures drawn) is equal to two(2).
                
                /**** Code Begin ****/
                if (state->deckCount[currentPlayer] <1){
                    shuffle(currentPlayer, state);
                }
                /**** Code End ****/
                    This if statement checks if the 'currentPlayer' has cards to draw. If not (deckCount < 1), then
                    the 'currentPlayers' discarded deck is shuffled.
                    
                /**** Code Begin ****/
                drawCard(currentPlayer, state);
                cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
                /**** Code End ****/
                    The method 'drawCard' is called and places a new card in the playes hand. Then the card which was drawn is placed 
                    into 'cardDrawn' by getting the top card in the players hand.
                
                
                /**** Code Begin ****/
                if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
                    drawntreasure++;
                else{
                    temphand[z]=cardDrawn;
                    state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
                    z++;
                }
                /**** Code End ****/
                    This if-else statement checks for the type of card that was drawn. If a treasure was drawn (copper, silver, or gold), then
                    the while loop conditional variable is incremented. Otherwise, the card is placed in a temporary hand, the number of
                    cards the player has is decremented, and the index-counter for the temporary hand is incremented.
                
                /**** Code Begin ****/
                while(z-1>=0){
                    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
                    z=z-1;
                }
                /**** Code End ****/
                    Once the player has drawn two(2) treasures, the temporary hand is discarded. 
                
            Notes:
                The declaration/prototype for 'adventurer' can be found in dominion.h within the enum Card object.
                The functionality for the 'adventurer' card is found in dominion.c as a case within a switch statement.
                
                The card 'adventurer' costs 6 coins to purchase. This logic is contained in the dominion.c 
                method 'getCost'.
                
                The logic controlling the card effects of 'adventurer' can be found in the dominion.c method 'CardEffect'
                as a case within a switch statement.
        
        
        
        
    Functions

        discardCard()
            Code:
                /**** Code Begin ****/
                    int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
                    {  
                        //if card is not trashed, added to Played pile 
                        if (trashFlag < 1)
                        {
                            //add card to played pile
                            state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
                            state->playedCardCount++;
                        }
                            
                        //set played card to -1
                        state->hand[currentPlayer][handPos] = -1;
                            
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
                            
                        return 0;
                    }
                /**** Code End ****/
                
            Code Breakdown:
                /**** Code Begin ****/
                if (trashFlag < 1)
                {
                    //add card to played pile
                    state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
                    state->playedCardCount++;
                }
                
                state->hand[currentPlayer][handPos] = -1;
                /**** Code End ****/
                    This if statement checks the 'trashFlag' flag. If the flag is raised, the card is placed in the 'played' pile.
                    Following this, the card which was played is placed at the end of the hand array.
                    
                /**** Code Begin ****/
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
                    return 0;
                /**** Code End ****/
                    This if-else statement determines how to handle the players hand following the discard.
                    If the discarded card occupied position -1 (the end), then the players handcount is decremented.
                    If the player only have one card in their hand, their handcount is decremented as well.
                    Otherwise, the discarded card is placed at the end of the hand array and the handcount is decremented.
                    Finally, the method is exited by returning the value zero(0).
               
            
            Notes:
                The declaration/prototype for 'discardCard' can be found in dominion.h.
                The functionality for the 'discardCard' card is found in dominion.c.
        
        
        updateCoins()
            Code:
            
                /**** Code Begin ****/
                int updateCoins(int player, struct gameState *state, int bonus)
                {
                    int i;
                        
                    //reset coin count
                    state->coins = 0;

                    //add coins for each Treasure card in player's hand
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

                    //add bonus
                    state->coins += bonus;

                    return 0;
                }
                /**** Code End ****/
            
            Code Breakdown:
                /**** Code Begin ****/
                int i;
                
                state->coins = 0;
                /**** Code End ****/
                    First, an integer variable 'i' is declared.
                    Then the current coin count is set to 0.
                
                /**** Code Begin ****/
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
                /**** Code End ****/
                    This for loop is run as many times as the number of the players hand count. 
                    Each card is examined. If the card is copper, silver, or gold, then their respective
                    values (1, 2, or 3) are added to the coins variable.
                
                /**** Code Begin ****/
                state->coins += bonus;

                return 0;
                /**** Code End ****/
                    If there is a bonus passed to 'updateCoins', then the value of 'bonus' is added to the coin count.
                    Finally, the method returns the value of zero();
                
            Notes:
                The declaration/prototype for 'updateCoins' can be found in dominion.h.
                The functionality for the 'updateCoins' card is found in dominion.c.