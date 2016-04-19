#include "testkit.h"

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

int playedCardsWasIncremented(struct gameState *before, struct gameState *after, int numCards) {
    if (before->playedCardCount == after->playedCardCount - numCards) {
        return 1;
    }
    return 0;
}