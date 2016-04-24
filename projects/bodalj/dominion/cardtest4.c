/******************************************************************************
 * Filename: cardtest4.c
 * Author: Jens Bodal
 * Date: April 24, 2016
 * Description: unit test for great_hall
 *****************************************************************************/


#include "dominion.h"
#include "dominion_helpers.h" 
#include "assert.h"
#include <stdio.h>
#include <string.h>

int drawSpecificCard(struct gameState *state, int player, int card);
int placeOnDeck(struct gameState *state, int player, int card);
void printCards(int *phand, int numCards, char *dtype);
char *getCardName(int card);
void printHand(struct gameState *state, int player);
int countCardInHand(struct gameState *state, int player, int card);
void checkPlayCard(struct gameState *state, int targetPlayer, int card);

int CARD = great_hall;
char *CARD_NAME = "Great Hall";
int NUM_CARD_DRAW = 1;
int NUM_ACTIONS = 1;
int NUM_BUYS = 0;
char *FUNCTION = "playGreatHall";

// change function depending on card used :: CARD MUST only affect cards and actions
void playFunction(int targetPlayer, int pos, struct gameState *state) {
    playGreatHall(targetPlayer, pos, state);
}

int main() {
    int players = 4;
    int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int seed = 187;
    int trash = 1;
    int targetPlayer = 0;
    int i;
    int iterations = 10;
    int FOUND_BUG = 0;
    struct gameState game;
    struct gameState *state = &game;
    initializeGame(players, cards, seed, &game);
    
    printf("TESTING great_hall card\n");

    checkPlayCard(state, targetPlayer, CARD);
    return 0;
}

// places specified card in deck then draws it
int drawSpecificCard(struct gameState *state, int player, int card) {
    int i;
    int pos = state->deckCount[player]++;
    state->deck[player][pos] = card;
    if (drawCard(player, state) == -1) {
        return -1;   
    }
    return pos; 
}

int placeOnDeck(struct gameState *state, int player, int card) {
    int i;
    int pos = state->deckCount[player]++;
    state->deck[player][pos] = card;
    return 1;
}

void printCards(int *pHand, int numCards, char *dtype) {
    int i;
    printf("Printing current %s:\n", dtype);
    for (i = 0; i < numCards; i++) {
        printf("  Pos [%d] Card [%d:%s]\n", i, pHand[i], getCardName(pHand[i]));
    }
    printf("  Cards in %s: %d\n\n", dtype, numCards);
}

void printHand(struct gameState *state, int player) {
    printCards(state->hand[player], state->handCount[player], "hand");
}

char *getCardName(int card) {
    switch(card) {
        case curse:
            return "curse";
        case estate:
            return "estate";
        case duchy:
            return "duchy";
        case province:
            return "province";
        case copper:
            return "copper";
        case silver:
            return "silver";
        case gold:
            return "gold";
        case adventurer:
            return "adventurer";
        case council_room:
            return "council_room";
        case feast:
            return "feast";
        case gardens:
            return "gardens";
        case mine:
            return "mine";
        case remodel:
            return "remodel";
        case smithy:
            return "smithy";
        case village:
            return "village";
        case baron:
            return "baron";
        case great_hall:
            return "great_hall";
        case minion:
            return "minion";
        case steward:
            return "steward";
        case tribute:
            return "tribute";
        case ambassador:
            return "ambassador";
        case cutpurse:
            return "cutpurse";
        case embargo:
            return "embargo";
        case outpost:
            return "outpost";
        case salvager:
            return "salvager";
        case sea_hag:
            return "sea_hag";
        case treasure_map:
            return "treasure_map";
        default:
            return "unknown";
    }
}

int countCardInHand(struct gameState *state, int player, int card) {
    int i;
    int count = 0;
    for (i = 0; i < state->handCount[player]; i++) {
        if (state->hand[player][i] == card) count++;
    }
    return count;
}

void checkPlayCard(struct gameState *state, int targetPlayer, int card) {
    // count targetCard
    int preCardCount = countCardInHand(state, targetPlayer, card);
    // count actions
    int preActionCount = state->numActions;
    // count number of card
    int preHandCount = state->handCount[targetPlayer];
    // count buys
    int preNumBuys = state->numBuys;

    // draw target card
    int pos = drawSpecificCard(state, targetPlayer, card);
   
    // play target card from previously acquired position
    if (card == CARD) {
        playFunction(targetPlayer, pos, state);
    }
    else {
        printf("INVALID FUNCTION USAGE SEE CODE\n");
    }

    // get post play stats
    int postCardCount = countCardInHand(state, targetPlayer, card);
    int postActionCount = state->numActions;
    int postHandCount = state->handCount[targetPlayer];
    int postNumBuys = state->numBuys;
    
    // test results
    // count of target card post-pre 
    int numCard = postCardCount - preCardCount;
   
    if (numCard != 0) {
        printf("FAIL: [%s] %s was not discarded\n", FUNCTION, CARD_NAME);
    }
    else {
        printf("SUCCESS: [%s] %s was correctly discarded\n", FUNCTION, CARD_NAME);
    }
    // number of actions
    int actionCount = postActionCount - preActionCount;
    if (actionCount != NUM_ACTIONS) {
        printf("FAIL: [%s] number of actions should have increased by [%d] but increased by [%d]\n", FUNCTION, NUM_ACTIONS, actionCount);
    }
    else {
        printf("SUCCESS: [%s] actions increased by [%d]\n", FUNCTION, actionCount);
    }
    // number of cards drawn
    int cardDraw = postHandCount - preHandCount;
    if (cardDraw != NUM_CARD_DRAW) {
        printf("FAIL: [%s] should have drawn [%d] card(s) but drew [%d]\n", FUNCTION, NUM_CARD_DRAW, cardDraw);
    }
    else {
        printf("SUCCESS: [%s] correctly drew [%d] card(s)\n", FUNCTION, cardDraw);
    }
    // number of buys
    int buyCount = postNumBuys - preNumBuys;
    if (buyCount != NUM_BUYS) {
        printf("FAIL: [%s] buy count should have increased by [%d] but increased by [%d]\n", FUNCTION, NUM_BUYS, buyCount);
    }
    else {
        printf("SUCCESS: [%s] buy count increased by [%d]\n", FUNCTION, buyCount);
    }
}

