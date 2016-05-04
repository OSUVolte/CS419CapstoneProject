#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "adventurer cardEffect"

int main(){
    struct gameState og, tg;
    int k[10] = {adventurer, smithy, great_hall, village, mine, minion, council_room, gardens, feast, baron};
    int seed = 999;
    int num_players = 3;
    int result;
    initializeGame(num_players, k, seed, &og);
    memcpy(&tg, &og, sizeof(struct gameState));
    int player = whoseTurn(&tg);
    int player2 = (player + 1) % num_players;
    int player3 = (player + 2) % num_players;

    printf(">>> testing %s \n", TESTFUNCTION);

    // set first card in hand to adventurer
    tg.hand[player][0] = adventurer;

    // set top cards on deck 
    tg.deck[player][tg.deckCount[player] - 1] = smithy;
    tg.deck[player][tg.deckCount[player] - 2] = copper;
    tg.deck[player][tg.deckCount[player] - 3] = smithy;
    tg.deck[player][tg.deckCount[player] - 4] = gold;

    result = cardEffect(adventurer, 0, 0, 0, &tg, 0, 0);
    printf("last card in hand is %d, expecting %d\n", tg.hand[player][tg.handCount[player] - 1], gold);
    assert(tg.hand[player][tg.handCount[player] - 1] == gold);
    printf("second to last card in hand is %d, expecting %d\n", tg.hand[player][tg.handCount[player] - 2], copper);
    assert(tg.hand[player][tg.handCount[player] - 2] == copper);
    printf("cards in hand is %d, expecting %d\n", tg.handCount[player], og.handCount[player] + 2);
    assert(tg.handCount[player] == og.handCount[player] + 2);
    printf("%s returned %d, expecting 0\n", TESTFUNCTION, result);
    assert(result == 0);

    // play with empty deck 
    memcpy(&tg, &og, sizeof(struct gameState)); //reset game start
    tg.hand[player][0] = adventurer;
    while(tg.deckCount[player] > 1){
        tg.discard[player][tg.discardCount[player]++ -1] = tg.deck[player][tg.deckCount[player]-- -1]; 
    }
    //printf("%d cards in hand\n", tg.handCount[player]);
    result = cardEffect(adventurer, 0, 0, 0, &tg, 0, 0);
    //printf("%d cards in hand\n", tg.handCount[player]);
    int card;
    printf("cards in hand is %d, expecting %d\n", tg.handCount[player], og.handCount[player] + 2);
    assert(tg.handCount[player] == og.handCount[player] + 2);
    card = tg.hand[player][tg.handCount[player] - 1];
    printf("last card in hand is %d, expecting %d or %d or %d\n", card, copper, silver, gold);
    assert(card == gold || card == silver || card == copper);
    card = tg.hand[player][tg.handCount[player] - 2];
    printf("second to last card in hand is %d, expecting %d or %d or %d\n", card, copper, silver, gold);
    assert(card == gold || card == silver || card == copper);
     
    printf(">>> end of %s test \n\n", TESTFUNCTION);
    return 0;
}
