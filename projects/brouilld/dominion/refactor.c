

Functions:
    card_adventurer:
        Code:
            /**** Code Begin ****/
            void card_adventurer(int currentPlayer, struct gameState *state){
                int cardDrawn;
                int temphand[MAX_HAND];
                int drawntreasure = 0;
                int z = 0;
                
                while(drawntreasure <= 2){
                    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
                        shuffle(currentPlayer, state);
                    }
                    
                    drawCard(currentPlayer, state);
                    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
                    
                    if (cardDrawn == copper && cardDrawn == silver || cardDrawn == gold)
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
            /**** Code End ****/
            
        Code Changes:
            Created a void function as all changes are made to 'state' which is passed by reference.
            Used 'card_' as a standard function signature for card action functions.
            Created variables 'cardDrawn', 'temphand', 'drawntreasure', and 'z' locally as not all cards need them.
                        
        
    
    card_councilRoom:
        Code:
            /**** Code Begin ****/
            void card_councilRoom(int currentPlayer, struct gameState *state, int handPos){
                int i;
                //+4 Cards
                for (i = 0; i < 4; ++i)
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
            /**** Code End ****/
            
        Code Changes:
            Created a void function as all changes are made to 'state' which is passed by reference.
            Used 'card_' as a standard function signature for card action functions.
            Created variable 'i', locally as not all cards need them.
        
    card_remodel:
        Code:
            /**** Code Begin ****/
            int card_remodel(int currentPlayer, struct gameState *state, int handPos, int choice1, int choice2){
                int i;
                int j = state->hand[currentPlayer][choice2];  //store card we will trash

                if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
                {
                return -1;
                }

                gainCard(choice2, state, 0, currentPlayer);

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
            /**** Code End ****/
            
        Code Changes:
            Created an int function as either '-1' or '0' are returned based on results.
            Used 'card_' as a standard function signature for card action functions.
            Created variables 'i' and 'j' locally as not all cards need them.
        
        
    
    card_smithy:
        Code:
            /**** Code Begin ****/
            void card_smithy(int currentPlayer, struct gameState *state, int handPos){
                int i;
                
                for (i = 0; i < 3; i++)
                {
                drawCard(currentPlayer, state);
                }
                        
                //discard card from hand
                discardCard(0, currentPlayer, state, handPos);		
            }
            
            /**** Code End ****/
            
        Code Changes:
            Created a void function as all changes are made to 'state' which is passed by reference.
            Used 'card_' as a standard function signature for card action functions.
            Created variable 'i' locally as not all cards need them.
    
    card_village:
        Code:
            /**** Code Begin ****/
            void card_village(int currentPlayer, struct gameState *state, int handPos){
                //+1 Card
                drawCard(currentPlayer, state);
                        
                //+2 Actions
                state->numActions = state->numActions + 2;
                        
                //discard played card from hand
                discardCard(handPos, currentPlayer, state, 0);
            }
            /**** Code End ****/
            
        Code Changes:
            Created a void function as all changes are made to 'state' which is passed by reference.
            Used 'card_' as a standard function signature for card action functions.



Bugs Introduced:
    card_adventurer:
        1.) Conditional of first while loop set to <=
        2.) Conditional of second if statement in first while loop
                set to &&
                
    card_smithy:
        1.) Passed arguments to 'discardCard' in wrong order
    
    card_councilRoom:
        1.) Changed when for loop counter increments: 'i++' to '++i'
    
    card_remodel:
        1.) Changed stored card that is trashed from 'choice1' to 'choice2'
    
        