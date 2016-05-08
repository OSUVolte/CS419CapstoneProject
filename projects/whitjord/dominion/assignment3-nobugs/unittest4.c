#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "discardCard"

int main(){
    struct gameState og, tg;
    int k[10] = {adventurer, smithy, great_hall, village, mine, minion, council_room, gardens, feast, baron};
    int seed = 989;
    int num_players = 3;
    int result;
    initializeGame(num_players, k, seed, &og);
    memcpy(&tg, &og, sizeof(struct gameState));
    int player, prevPCCount, prevLastPC, prevFirstCard, prevLastCard; 
    player = whoseTurn(&tg);
    printf(">>> testing %s \n", TESTFUNCTION);

    int i;
    printf("printing initial hand....\n");
    for(i = 0; i < tg.handCount[player]; i++){
        printf("card %d: %d\n", i, tg.hand[player][i]);
    }

    // discard first card
    printf("> discard first card\n");
    prevPCCount = tg.playedCardCount;
    prevFirstCard = tg.hand[player][0];
    result = discardCard(0, player, &tg, 0);
    printf("last played card was %d expected %d\n", tg.playedCards[tg.playedCardCount - 1], prevFirstCard);
    assert(tg.playedCards[tg.playedCardCount - 1] == prevFirstCard);
    printf("playedCardCount is %d, expected %d\n", tg.playedCardCount, prevPCCount + 1);
    assert(tg.playedCardCount == prevPCCount + 1);
    printf("%s returned %d, expected 0\n", TESTFUNCTION, result);
    assert(result == 0);


    // discard last card in hand with more than one card
    printf("> discard last card in hand with more than one card\n");
    prevPCCount = tg.playedCardCount;
    prevLastCard = tg.hand[player][tg.handCount[player] - 1];
    result = discardCard(tg.handCount[player] - 1, player, &tg, 0);
    printf("last played card was %d expected %d\n", tg.playedCards[tg.playedCardCount - 1], prevLastCard);
    assert(tg.playedCards[tg.playedCardCount - 1] == prevLastCard);
    printf("playedCardCount is %d, expected %d\n", tg.playedCardCount, prevPCCount + 1);
    assert(tg.playedCardCount == prevPCCount + 1);
    printf("%s returned %d, expected 0\n", TESTFUNCTION, result);
    assert(result == 0);

    // trash card
    printf("> trashing card\n");
    prevPCCount = tg.playedCardCount;
    prevLastPC = tg.playedCards[tg.playedCardCount];
    result = discardCard( 2, player, &tg, 1);
    printf("played card count is %d expected %d\n", tg.playedCardCount, prevPCCount);
    assert(tg.playedCardCount == prevPCCount);
    printf("last played card is %d expected %d\n", tg.playedCards[tg.playedCardCount], prevLastPC);
    assert(tg.playedCards[tg.playedCardCount] == prevLastPC);
    printf("%s returned %d, expected 0\n", TESTFUNCTION, result);
    assert(result == 0);

    // discard card in hand with only one card
    // get down to one card
    while(tg.handCount[player] > 0){
        discardCard(0, player, &tg, 0);
    }
    printf("> discard last card in hand with one card in hand\n");
    prevPCCount = tg.playedCardCount;
    prevLastCard = tg.hand[player][tg.handCount[player] - 1];
    result = discardCard(tg.handCount[player] - 1, player, &tg, 0);
    printf("last played card was %d expected %d\n", tg.playedCards[tg.playedCardCount - 1], prevLastCard);
    assert(tg.playedCards[tg.playedCardCount - 1] == prevLastCard);
    printf("playedCardCount is %d, expected %d\n", tg.playedCardCount, prevPCCount + 1);
    assert(tg.playedCardCount == prevPCCount + 1);
    printf("%s returned %d, expected 0\n", TESTFUNCTION, result);
    assert(result == 0);


    // test discarding empty hand / card not in hand 
 
    printf(">>> end of %s test \n\n", TESTFUNCTION);
    return 0;
}
