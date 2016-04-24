#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
    int handCount1, handCount2, deckCount1, deckCount2, playedCount;
    int estateCount, duchyCount, provinceCount;
    int adventurerCount, feastCount, gardensCount, mineCount, remodelCount, smithyCount, villageCount, baronCount, sea_hagCount, great_hallCount;
    int k[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, baron, sea_hag, great_hall};
    struct gameState G;
    memset(&G, 0, sizeof(struct gameState));   // clear the game state
    initializeGame(2, k, 10, &G); //initialize game
    G.whoseTurn = 0; //1st player turn

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    G.hand[0][0] = smithy;
    handCount1 = G.handCount[0]; //count number of cards in 1st player's hands
    handCount2 = G.handCount[1]; //count number of cards in 2nd player's hands
    deckCount1 = G.deckCount[0]; //count number of cards in 1st player's hands
    deckCount2 = G.deckCount[1]; //count number of cards in 2nd player's hands
    //save number of victory cards
    estateCount = G.supplyCount[estate];
    duchyCount = G.supplyCount[duchy];
    provinceCount = G.supplyCount[province];
    adventurerCount = G.supplyCount[adventurer];
    feastCount = G.supplyCount[feast];
    gardensCount = G.supplyCount[gardens];
    mineCount = G.supplyCount[mine];
    remodelCount = G.supplyCount[remodel];
    smithyCount = G.supplyCount[smithy];
    villageCount = G.supplyCount[village];
    baronCount = G.supplyCount[baron];
    sea_hagCount = G.supplyCount[sea_hag];
    great_hallCount = G.supplyCount[great_hall];

    playedCount = G.playedCardCount;
    smithyPlay(0, &G);

    printf("Test if current player receives exact 3 cards\n");
    if (G.handCount[0] == handCount1+2){
        printf ("PASS. EXPECTED: hand count %d. ACTUAL: hand count %d.\n\n", handCount1+2, G.handCount[0]);
    }
    else{
        printf ("FAIL. EXPECTED: hand count %d. ACTUAL: hand count %d.\n\n", handCount1+2, G.handCount[0]);
    }

    printf("Test if 3 cards come from the right pile\n");
    if (G.deckCount[0] == deckCount1-3){
        printf ("PASS. EXPECTED: deck count %d. ACTUAL: deck count %d.\n", deckCount1-3, G.deckCount[0]);
    }
    else{
        printf ("FAIL. EXPECTED: deck count %d. ACTUAL: deck count %d.\n", deckCount1-3, G.deckCount[0]);
    }
    if (G.playedCardCount == playedCount+1){
        printf ("PASS. EXPECTED: played count %d. ACTUAL: played count %d.\n\n", playedCount+1, G.playedCardCount);
    }
    else{
        printf ("FAIL. EXPECTED: played count %d. ACTUAL: played count %d.\n\n", playedCount+1, G.playedCardCount);
    }

    printf("Test that no change occurred for other player's hand\n");
    if (G.handCount[1] == handCount2){
        printf ("PASS. EXPECTED: hand count %d. ACTUAL: hand count %d.\n\n", handCount2, G.handCount[1]);
    }
    else{
        printf ("FAIL. EXPECTED: hand count %d. ACTUAL: hand count %d.\n\n", handCount2, G.handCount[1]);
    }

    printf("Test that no change occurred for other player's deck\n");
    if (G.deckCount[1] == deckCount2){
        printf ("PASS. EXPECTED: deck count %d. ACTUAL: deck count %d.\n\n", deckCount2, G.deckCount[1]);
    }
    else{
        printf ("FAIL. EXPECTED: deck count %d. ACTUAL: deck count %d.\n\n", deckCount2, G.deckCount[1]);
    }

    printf("Test that no change occurred to the victory cards pile\n");
    if (G.supplyCount[estate] == estateCount){
        printf ("PASS. EXPECTED: estate cards %d. ACTUAL: estate cards %d.\n", estateCount, G.supplyCount[estate]);
    }
    else{
        printf ("FAIL. EXPECTED: estate cards %d. ACTUAL: estate cards %d.\n", estateCount, G.supplyCount[estate]);
    }
    if (G.supplyCount[duchy] == duchyCount){
        printf ("PASS. EXPECTED: duchy cards %d. ACTUAL: duchy cards %d.\n", duchyCount, G.supplyCount[duchy]);
    }
    else{
        printf ("FAIL. EXPECTED: duchy cards %d. ACTUAL: duchy cards %d.\n", duchyCount, G.supplyCount[duchy]);
    }
    if (G.supplyCount[province] == provinceCount){
        printf ("PASS. EXPECTED: province cards %d. ACTUAL: province cards %d.\n\n", provinceCount, G.supplyCount[province]);
    }
    else{
        printf ("FAIL. EXPECTED: province cards %d. ACTUAL: province cards %d.\n\n", provinceCount, G.supplyCount[province]);
    }

    printf("Test that no change occurred to the kingdom cards pile\n");
    if (G.supplyCount[adventurer] == adventurerCount){
        printf ("PASS. EXPECTED: adventurer cards %d. ACTUAL: adventurer cards %d.\n", adventurerCount, G.supplyCount[adventurer]);
    }
    else{
        printf ("FAIL. EXPECTED: adventurer cards %d. ACTUAL: adventurer cards %d.\n", adventurerCount, G.supplyCount[adventurer]);
    }
    if (G.supplyCount[feast] == feastCount){
        printf ("PASS. EXPECTED: feast cards %d. ACTUAL: feast cards %d.\n", feastCount, G.supplyCount[feast]);
    }
    else{
        printf ("FAIL. EXPECTED: feast cards %d. ACTUAL: feast cards %d.\n", feastCount, G.supplyCount[feast]);
    }
    if (G.supplyCount[gardens] == gardensCount){
        printf ("PASS. EXPECTED: gardens cards %d. ACTUAL: gardens cards %d.\n", gardensCount, G.supplyCount[gardens]);
    }
    else{
        printf ("FAIL. EXPECTED: gardens cards %d. ACTUAL: gardens cards %d.\n", gardensCount, G.supplyCount[gardens]);
    }
    if (G.supplyCount[mine] == mineCount){
        printf ("PASS. EXPECTED: mine cards %d. ACTUAL: mine cards %d.\n", mineCount, G.supplyCount[mine]);
    }
    else{
        printf ("FAIL. EXPECTED: mine cards %d. ACTUAL: mine cards %d.\n", mineCount, G.supplyCount[mine]);
    }
    if (G.supplyCount[remodel] == remodelCount){
        printf ("PASS. EXPECTED: remodel cards %d. ACTUAL: remodel cards %d.\n", remodelCount, G.supplyCount[remodel]);
    }
    else{
        printf ("FAIL. EXPECTED: remodel cards %d. ACTUAL: remodel cards %d.\n", remodelCount, G.supplyCount[remodel]);
    }
    if (G.supplyCount[smithy] == smithyCount){
        printf ("PASS. EXPECTED: smithy cards %d. ACTUAL: smithy cards %d.\n", smithyCount, G.supplyCount[smithy]);
    }
    else{
        printf ("FAIL. EXPECTED: smithy cards %d. ACTUAL: smithy cards %d.\n", smithyCount, G.supplyCount[smithy]);
    }
    if (G.supplyCount[village] == villageCount){
        printf ("PASS. EXPECTED: village cards %d. ACTUAL: village cards %d.\n", villageCount, G.supplyCount[village]);
    }
    else{
        printf ("FAIL. EXPECTED: village cards %d. ACTUAL: village cards %d.\n", villageCount, G.supplyCount[village]);
    }
    if (G.supplyCount[baron] == baronCount){
        printf ("PASS. EXPECTED: baron cards %d. ACTUAL: baron cards %d.\n", baronCount, G.supplyCount[baron]);
    }
    else{
        printf ("FAIL. EXPECTED: baron cards %d. ACTUAL: baron cards %d.\n", baronCount, G.supplyCount[baron]);
    }
    if (G.supplyCount[sea_hag] == sea_hagCount){
        printf ("PASS. EXPECTED: sea_hag cards %d. ACTUAL: sea_hag cards %d.\n", sea_hagCount, G.supplyCount[sea_hag]);
    }
    else{
        printf ("FAIL. EXPECTED: sea_hag cards %d. ACTUAL: sea_hag cards %d.\n", sea_hagCount, G.supplyCount[sea_hag]);
    }
    if (G.supplyCount[great_hall] == great_hallCount){
        printf ("PASS. EXPECTED: great_hall cards %d. ACTUAL: great_hall cards %d.\n\n", great_hallCount, G.supplyCount[great_hall]);
    }
    else{
        printf ("FAIL. EXPECTED: great_hall cards %d. ACTUAL: great_hall cards %d.\n\n", great_hallCount, G.supplyCount[great_hall]);
    }
    printf("---------------------------------------------------------\n");
	return 0;
}
