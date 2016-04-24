#include "dominion.h" 
#include "dominion_helpers.h"  
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//testing of getCost function

int main(){
    printf("*********************BEGIN UNIT TESTS OF SMITHY*********************\n\n");
//compare returned value to correct value for each card type
    struct gameState T;
    struct gameState A;
    int i, beg_count, end_count, total_cards;

    int k[10] = {gardens, adventurer, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &T);
    T.hand[0][0] = adventurer;
    
    total_cards = T.handCount[0] + T.deckCount[0] + T.discardCount[0];

    memcpy(&T, &A, sizeof(struct gameState));
    if(memcmp(&A, &T, sizeof(struct gameState)) != 0){
        printf("Error in setting game state. Abort Test\n");
        return 0;
    }
    //count current treasure cards in hand
    for(i = 0; i < T.handCount[0]; i++){
        if(T.hand[i] == copper ||
            T.hand[i] == silver ||
            T.hand[i] == gold){
                beg_count ++;
        }
    }
    //Play the adventurer card for the Test state player 0, position 0
    playAdventurer(&T, 0, 0);


    //check that two cards have added and one discarded
    if(T.handCount[0] != A.handCount[0] + 1){
        printf("FAIL incorrect number of cards in player hand\n");
    }

    //check that the treasure count has increased by 2
    for(i = 0; i < T.handCount[0]; i++){
        if(T.hand[i] == copper ||
            T.hand[i] == silver ||
            T.hand[i] == gold){
                end_count ++;
        }
    }
    if(end_count != beg_count + 2){
        printf("FAIL two treasure cards were not added to hand\n");
    }
    
    //check that the card was added to discard pile
    if(T.discardCount[0] != A.discardCount[0] + 1){
        printf("FAIL incorrect number of cards in player discard pile\n");
    }
    
    //check that no cards were thrown away
    if(total_cards != T.handCount[0] + T.deckCount[0] + T.discardCount[0]){
        printf("FAIL total player cards is incorrect\n");
    }
    
    //check that nothing else has changed
    if(A.handCount[1] + A.deckCount[1] + A.discardCount[1] != T.handCount[1] + T.deckCount[1] + T.discardCount[1]){
        printf("FAIL total opponent cards is incorrect\n");
    }
    
    if(T.deckCount[1] != A.deckCount[1]){
        printf("FAIL opponents deck altered\n");
        printf("Is %d and should be %d\n", T.deckCount[1], A.deckCount[1]);
    }

    if(T.handCount[1] != A.handCount[1]){
        printf("FAIL opponents hand altered\n");
        printf("Is %d and should be %d\n", T.handCount[1], A.handCount[1]);
                
    }

    if(T.discardCount[1] != A.discardCount[1]){
        printf("FAIL opponents discard pile altered\n");
        printf("Is %d and should be %d\n", T.discardCount[1], A.discardCount[1]);
    }

    printf("**********************TESTS COMPLETE*************************\n\n")
    return 0;

}

//adventurer: reveal cards from your deck until you get two treasure cards, discard rest
int playAdventurer(struct gameState *state, int currentPlayer, int handPos){
    int drawntreasure=0;
    int temphand[MAX_HAND];
    int z = 0;
    while(drawntreasure<2){
	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
	  shuffle(currentPlayer, state);
	}
	drawCard(currentPlayer, state);
	int cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold){
	  drawntreasure++;
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