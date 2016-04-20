#include <stdlib.h>
#include "testkit.h"
#include "dominion.h"

int handIsUntouched(struct gameState *before, struct gameState *after, int player) {
    int i;
    for (i = 0; i < before->handCount[player]; i++) {
        if (before->hand[player][i] != after->hand[player][i])
            return 0;
    }
    return 1;
}

int deckIsUntouched(struct gameState *before, struct gameState *after, int player) {
    int i;
    for (i = 0; i < before->deckCount[player]; i++) {
        if (before->deck[player][i] != after->deck[player][i])
            return 0;
    }
    return 1;
}

int victoryPileIsUntouched(struct gameState *before, struct gameState *after) {
    if (
            before->supplyCount[estate] == after->supplyCount[estate] &&
            before->supplyCount[duchy] == after->supplyCount[duchy] &&
            before->supplyCount[province] == after->supplyCount[province]
            ) {
        return 1;
    }
    return 0;
}

int kingdomPileIsUntouched(struct gameState *before, struct gameState *after) {
    int i = 0, card;
    int kingdomCards[10] = {
            adventurer,
            gardens,
            embargo,
            village,
            minion,
            mine,
            cutpurse,
            sea_hag,
            tribute,
            smithy
    };
    card = kingdomCards[i];
    for (i = 0; i < 10; i++) {

        if (before->supplyCount[card] != after->supplyCount[card]) {
            return 0;
        }
    }
    return 1;
}

int playedPileIsUntouched(struct gameState *before, struct gameState *after) {
    int i = 0, card;
    for (i = 0; i < after->playedCardCount; i++) {
        if (before->playedCards[i] != after->playedCards[i]) {
            return 0;
        }
    }
    return 1;
}

int cardWasPlayed(struct gameState *game, int card, int position) {
    if (game->playedCards[position] == card) {
        return 1;
    }
    return 0;
}

int playedCardsWasIncremented(struct gameState *before, struct gameState *after, int numCards) {
    if (before->playedCardCount == after->playedCardCount - numCards) {
        return 1;
    }
    return 0;
}

int deckWasShuffled(struct gameState *before, struct gameState *after, int player) {
    int i, sameCardCount = 0;
    for (i = 0; i < before->deckCount[player]; i++) {
        if (before->deck[player][i] == after->deck[player][i]) {
            sameCardCount++;
        }
    }
    if (sameCardCount != before->deckCount[player]) {
        return 1;
    }
    return 0;
}

int checkHandCard(struct gameState *game, int player, int position, int card) {
    if (game->hand[player][position] == card) {
        return 1;
    }
    return 0;
}

void diffHand(struct gameState *before, struct gameState *after, int player, int diffCards[MAX_HAND]) {
    int i, diffPos = 0;
    qsort((void *) (before->hand[player]), (size_t) before->handCount[player], sizeof(int), compare);
    qsort((void *) (after->hand[player]), (size_t) after->handCount[player], sizeof(int), compare);
    for (i = 0; i < MAX_HAND; i++) {
        if (before->hand[player][i] != after->hand[player][i]) {
            diffCards[diffPos] = after->hand[player][i];
            diffPos++;
        }
    }
}

void diffDeckSupply(struct gameState *before, struct gameState *after, int player, int supplyDiff[MAX_DECK]) {
    int supplyBefore[MAX_DECK];
    int supplyAfter[MAX_DECK];
    int i = 0;
    int card = 0;
    for (i = 0; i < MAX_DECK; i++) {
        supplyBefore[i] = 0;
        supplyAfter[i] = 0;
        supplyDiff[i] = 0;
    }
    for (i = 0; i < before->deckCount[player]; i++) {
        card = before->deck[player][i];
        supplyBefore[card]++;
    }
    for (i = 0; i < after->deckCount[player]; i++) {
        card = before->deck[player][i];
        supplyAfter[card]++;
    }
    for (i = 0; i < MAX_DECK; i++) {
        supplyDiff[i] = supplyBefore[i] - supplyAfter[i];
    }
}

int countHandSupply(struct gameState *game, int player, int card) {
    int supply = 0;
    for (int i = 0; i < game->handCount[player]; i++) {
        if (game->hand[player][i] == card) {
            supply++;
        }
    }
    return supply;
}

