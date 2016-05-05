#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define PLAYER 1
#define NUM_STATES 9
#define HAND_COUNT 5
#define COPPER_VAL 1
#define SILVER_VAL 2
#define GOLD_VAL 3
enum STATE
  { noCards = 0,
    noTreasure,
    oneCopper,
    allCopper,
    oneSilver,
    allSilver,
    oneGold,
    allGold,
    oneOfEach
  };
    
void setAllCardsTo(struct gameState *state, int card){
    int i;
    for(i = 0; i < state->handCount[PLAYER]; i++){
        state->hand[PLAYER][i] = card;
    }
}

int main(){
    printf(">>> testing updateCoins \n");
    struct gameState game[NUM_STATES];
    int expectedCoins[NUM_STATES];
    int result;

    // initialize all game states
    int i;
    for(i = 0; i < NUM_STATES; i++){
        game[i].handCount[PLAYER] = HAND_COUNT;
        setAllCardsTo(&game[i], smithy);
    }

    // set things up for individual game states
    
    game[noCards].handCount[PLAYER] = 0;
    expectedCoins[noCards] = 0;

    expectedCoins[noTreasure] = 0;
    
    // for oneCopper we'll set the first card
    game[oneCopper].hand[PLAYER][0] = copper;
    expectedCoins[oneCopper] = COPPER_VAL;

    // for silver we'll set the last card;
    game[oneSilver].hand[PLAYER][HAND_COUNT - 1] = silver;
    expectedCoins[oneSilver] = SILVER_VAL;

    game[oneGold].hand[PLAYER][1] = gold;
    expectedCoins[oneGold] = GOLD_VAL;

    setAllCardsTo(&game[allCopper], copper);
    expectedCoins[allCopper] = HAND_COUNT * COPPER_VAL;

    setAllCardsTo(&game[allSilver], silver);
    expectedCoins[allSilver] = HAND_COUNT * SILVER_VAL;

    setAllCardsTo(&game[allGold], gold);
    expectedCoins[allGold] = HAND_COUNT * GOLD_VAL;

    game[oneOfEach].hand[PLAYER][0] = copper;
    game[oneOfEach].hand[PLAYER][1] = silver;
    game[oneOfEach].hand[PLAYER][2] = gold;
    expectedCoins[oneOfEach] = COPPER_VAL + SILVER_VAL + GOLD_VAL;

    // run through tests
    int bonus = 0;
    for(i = 0; i  < NUM_STATES; i++){
       result = updateCoins(PLAYER, &game[i], bonus);
       printf("actual coins: %d  expected coins: %d \n", game[i].coins, expectedCoins[i]);
       assert(game[i].coins == expectedCoins[i]);
       printf("%d returned  0 expected\n", result);
       assert(result == 0);
    }

    // run through tests with bonus
    bonus = 1;
    for(i = 0; i  < NUM_STATES; i++){
       expectedCoins[i] = expectedCoins[i] + 1;
       result = updateCoins(PLAYER, &game[i], bonus);
       printf("actual coins: %d  expected coins: %d \n", game[i].coins, expectedCoins[i]);
       assert(game[i].coins == expectedCoins[i]);
       printf("%d returned  0 expected\n", result);
       assert(result == 0);
    }

    printf(">>> end of updateCoins test \n\n");
    return 0;
}
