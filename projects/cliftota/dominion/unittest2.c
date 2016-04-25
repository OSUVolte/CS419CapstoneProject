#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){
    int testresult;
    int k[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, baron, sea_hag, great_hall};
    int numPlayers = 2;
    struct gameState G;
    memset(&G, 0, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayers, k, 10, &G); //initialize game

    printf ("------------------TESTING gainCard():--------------------\n\n");

    //test when pile of cards that is attempt to be gained is empty
    printf ("Test when supply pile of adventure cards is empty.\n");
    G.supplyCount[adventurer] = 0;
    testresult = gainCard(adventurer, &G, 0, 1);
    if(testresult == -1){
        printf ("PASS. EXPECTED: Cannot gain an adventure card. ACTUAL: Cannot gain an adventure card.\n");
    }
    else{
        printf ("FAIL. EXPECTED: Cannot gain an adventure card. ACTUAL: Can gain an adventure card.\n");
    }

    //test when card is not used in the game
    printf ("Test when card is not in the game.\n");
    testresult = gainCard(council_room, &G, 0, 1);
    if(testresult == -1){
        printf ("PASS. EXPECTED: Cannot gain a council_room card. ACTUAL: Cannot gain a council_room card.\n\n");
    }
    else{
        printf ("FAIL. EXPECTED: Cannot gain a council_room card. ACTUAL: Can gain a council_room card.\n\n");
    }


    //test when flag set to add card to deck
    printf ("Test when card must be moved to deck.\n");
    int deckCount1 = G.deckCount[1]; //save current number of deck cards for player 1
    int deckCount2 = G.deckCount[2]; //save current number of deck cards for player 2
    G.supplyCount[adventurer] = 5;
    gainCard(adventurer, &G, 1, 1);
    //check that deck count is incremented for 1st player
    if(G.deckCount[1] == deckCount1+1){
        printf ("PASS. EXPECTED: Deck count for player 1 is incremented. ACTUAL: Deck count for player 1 is incremented.\n");
    }
    else{
        printf ("PASS. EXPECTED: Deck count for player 1 is not incremented. ACTUAL: Deck count for player 1 is not incremented.\n");
    }
    //check that right card was added to the deck of 1st player
    if(G.deck[1][deckCount1] == adventurer){
        printf ("PASS. EXPECTED: Adventurer is added to the end of deck. ACTUAL: Adventurer is added to the end of deck.\n");
    }
    else{
        printf ("FAIL. EXPECTED: Adventurer is added to the end of deck. ACTUAL: Adventurer is not at the end of deck.\n");
    }
    //check that deck count for player 2 is not changed
    if(G.deckCount[2] == deckCount2){
        printf ("PASS. EXPECTED: Deck count for player 2 is not changed. ACTUAL: Deck count for player 2 is not changed.\n");
    }
    else{
        printf ("PASS. EXPECTED: Deck count for player 2 is not changed. ACTUAL: Deck count for player 2 is changed.\n");
    }
    //test supply count of adventurer is decremented
    if(G.supplyCount[adventurer] == 4){
        printf ("PASS. EXPECTED: Supply count for adventurer is 4. ACTUAL: Supply count for adventurer is %d.\n\n", G.supplyCount[adventurer]);
    }
    else{
        printf ("FAIL. EXPECTED: Supply count for adventurer is 4. ACTUAL: Supply count for adventurer is %d.\n\n", G.supplyCount[adventurer]);
    }


    //test when flag set to add card to hand
    printf ("Test when card must be moved to hand.\n");
    int handCount1 = G.handCount[1]; //save current number of hand cards for player 1
    int handCount2 = G.handCount[2]; //save current number of hand cards for player 2
    G.supplyCount[adventurer] = 5;
    gainCard(adventurer, &G, 2, 1);
    //check that hand count is incremented for 1st player
    if(G.handCount[1] == handCount1+1){
        printf ("PASS. EXPECTED: Hand count for player 1 is incremented. ACTUAL: Hand count for player 1 is incremented.\n");
    }
    else{
        printf ("PASS. EXPECTED: Hand count for player 1 is not incremented. ACTUAL: Hand count for player 1 is not incremented.\n");
    }
    //check that right card was added to the hand of 1st player
    if(G.hand[1][handCount1] == adventurer){
        printf ("PASS. EXPECTED: Adventurer is added to the end of hand. ACTUAL: Adventurer is added to the end of hand.\n");
    }
    else{
        printf ("FAIL. EXPECTED: Adventurer is added to the end of hand. ACTUAL: Adventurer is not at the end of hand.\n");
    }
    //check that hand count for player 2 is not changed
    if(G.handCount[2] == handCount2){
        printf ("PASS. EXPECTED: Hand count for player 2 is not changed. ACTUAL: Hand count for player 2 is not changed.\n");
    }
    else{
        printf ("PASS. EXPECTED: Hand count for player 2 is not changed. ACTUAL: Hand count for player 2 is changed.\n");
    }
    //test supply count of adventurer is decremented
    if(G.supplyCount[adventurer] == 4){
        printf ("PASS. EXPECTED: Supply count for adventurer is 4. ACTUAL: Supply count for adventurer is %d.\n\n", G.supplyCount[adventurer]);
    }
    else{
        printf ("FAIL. EXPECTED: Supply count for adventurer is 4. ACTUAL: Supply count for adventurer is %d.\n\n", G.supplyCount[adventurer]);
    }


    //test when flag set to add card to discard
    printf ("Test when card must be moved to discard.\n");
    int discardCount1 = G.discardCount[1]; //save current number of discard cards for player 1
    int discardCount2 = G.discardCount[2]; //save current number of discard cards for player 2
    G.supplyCount[adventurer] = 5;
    gainCard(adventurer, &G, 0, 1);
    //check that discard count is incremented for 1st player
    if(G.discardCount[1] == discardCount1+1){
        printf ("PASS. EXPECTED: Discard count for player 1 is incremented. ACTUAL: Discard count for player 1 is incremented.\n");
    }
    else{
        printf ("PASS. EXPECTED: Discard count for player 1 is not incremented. ACTUAL: Discard count for player 1 is not incremented.\n");
    }
    //check that right card was added to the discard of 1st player
    if(G.discard[1][discardCount1] == adventurer){
        printf ("PASS. EXPECTED: Adventurer is added to the end of discard. ACTUAL: Adventurer is added to the end of discard.\n");
    }
    else{
        printf ("FAIL. EXPECTED: Adventurer is added to the end of discard. ACTUAL: Adventurer is not at the end of discard.\n");
    }
    //check that discard count for player 2 is not changed
    if(G.discardCount[2] == discardCount2){
        printf ("PASS. EXPECTED: Discard count for player 2 is not changed. ACTUAL: Discard count for player 2 is not changed.\n");
    }
    else{
        printf ("PASS. EXPECTED: Discard count for player 2 is not changed. ACTUAL: Discard count for player 2 is changed.\n");
    }
    //test supply count of adventurer is decremented
    if(G.supplyCount[adventurer] == 4){
        printf ("PASS. EXPECTED: Supply count for adventurer is 4. ACTUAL: Supply count for adventurer is %d.\n\n", G.supplyCount[adventurer]);
    }
    else{
        printf ("FAIL. EXPECTED: Supply count for adventurer is 4. ACTUAL: Supply count for adventurer is %d.\n\n", G.supplyCount[adventurer]);
    }

    printf("---------------------------------------------------------\n");

    return 0;
}
