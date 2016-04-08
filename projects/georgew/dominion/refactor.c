#include "dominion.h"
#include "dominion_helpers.h"
//draw smithy
//Change for bug: Draws 2 cards instead of 3
int smithyCard(int handPos, int currentPlayer, struct gameState *state){	
    
    int i;   
    //+3 Cards
    for (i = 1; i < 3; i++){
        drawCard(currentPlayer, state);
    }
			
    //discard card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;	
}

//draw adventurer
//Change for bug: Changed logic of drawn treasure conditional so that you can only draw copper
int adventurerCard(int currentPlayer, struct gameState *state, int temphand[MAX_HAND]){
    int cardDrawn;
    int drawntreasure = 0;
    int z = 0; 
    while(drawntreasure<2){
        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
	    shuffle(currentPlayer, state);
	}
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver && cardDrawn == gold)
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
}

//draw greatHall
//Change for bugs: No added bugs
int greatHallCard(int handPos, int currentPlayer, struct gameState *state){
		
    //+1 Card
    drawCard(currentPlayer, state);
			
    //+1 Actions
    state->numActions++;
			
    //discard card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}

//draw steward card
//Change for bug: set choice one to the same thing for both options in conditional
int stewardCard(int handPos, int choice1, int choice2, int choice3, int currentPlayer, struct gameState *state){
		
    if (choice1 == 1)
    {
        //+2 cards
        drawCard(currentPlayer, state);
	drawCard(currentPlayer, state);
    }
    else if (choice1 == 1)
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
    return 0;
}

//draw councilRoom
//Change for bug: Not every player gets a new card 
int councilRoomCard(int handPos, int currentPlayer, struct gameState *state){			    
    int i;
    //+4 Cards
    for (i = 0; i < 4; i++)
    {
        drawCard(currentPlayer, state);
    }
			
    //+1 Buy
    state->numBuys++;
			
    //Each other player draws a card
    for (i = 1; i < state->numPlayers; i++)
    {
        if ( i != currentPlayer )
	{
	     drawCard(i, state);
	}
    }
			
    //put played card in played card pile
    discardCard(handPos, currentPlayer, state, 0);
			
    return 0;
}
