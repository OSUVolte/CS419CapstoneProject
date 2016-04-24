#include "dominion.h" 
#include "dominion_helpers.h"  
#include <stdio.h> 
#include <stdlib.h>

//testing of getCost function

int main(){
    printf("*********************BEGIN UNIT TESTS OF SMITHY*********************\n\n");
//compare returned value to correct value for each card type
struct gameState T;
struct gameState A;

int k[10] = {gardens, adventurer, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

initializeGame(2, k, 5, &T);
T.hand[0][0] = smithy;
T.hand[1][0] = smithy;

memcpy(&T, &A, sizeof(struct gameState));
if((memcmp(&A, &T, sizeof(struct gameState)) != 0){
    printf("Error in setting game state. Abort Test\n");
    return 0;
 }
//Play the smithy card for the Test state player 0, position 0
playSmithy(&T, 0, 0);

//check that three cards have been taken from deck
if(T.deckCount[0] != A.deckCount[0] - 3){
    printf("FAIL incorrect number of cards in player deck\n");
}

//check that three cards have added and one discarded
if(T.handCount[0] != A.handCount[0] + 2){
    printf("FAIL incorrect number of cards in player hand\n");
}

//check that the card was added to discard pile
if(T.discardCount[0] != A.discareCount[0] + 1){
    printf("FAIL incorrect number of cards in player discard pile\n");
}
//check that nothing else has changed
if(T.deckCount[1] != A.deckCount[1]){
    printf("FAIL opponents deck altered\n");
}

if(T.handCount[1] != A.handCount[1]){
    printf("FAIL opponents hand altered\n");
}

if(T.discardCount[1] != A.discardCount[1]){
    printf("FAIL opponents discard pile altered\n");
}

if(T.hand[1][0] != smithy){
    printf("FAIL smithy removed from opponents deck\n");
}

return 0;

}
