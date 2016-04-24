#include "testUtilities.h"
#include <string.h>
#include "dominion.h"
#include <stdio.h>

void copyGameState(struct gameState* dest, struct gameState* src) {
    memcpy(dest, src, sizeof(*dest));
}

int equalGameStates(struct gameState* a, struct gameState* b) {
    return (memcmp(a,b,sizeof(*a)) == 0);
}

int cardArraysAreEqual(int *a, int aSize, int *b, int bSize){
    if (aSize != bSize) return 0;
    int counta[treasure_map+1];
    int countb[treasure_map+1];

    bzero(counta,sizeof(counta));
    bzero(countb,sizeof(countb));

    int i=0;
    for(;i<aSize; ++i){
        counta[a[i]]++;
        countb[b[i]]++;
    }

    for (i=0; i<treasure_map; ++i){
        if (counta[i] != countb[i]) return 0;
    }

    return 1;
}

// Checks if combination of Deck, Hand, Discard, played piles for one player are the same between game states
int playerHasSameCards(struct gameState* a, struct gameState* b, int player) {
    int counta[treasure_map+1];
    int countb[treasure_map+1];
    int i;

    bzero(counta,sizeof(counta));
    bzero(countb,sizeof(countb));

    for (i=0; i < a->deckCount[player] || i < a->handCount[player] || i< a->discardCount[player] || i < a->playedCardCount; ++i){
        if (i< a->deckCount[player])counta[a->deck[player][i]]++;
        if (i< a->handCount[player])counta[a->hand[player][i]]++;
        if (i< a->discardCount[player])counta[a->discard[player][i]]++;
        if (i< a->playedCardCount) counta[a->playedCards[i]]++;
    }

    for (i=0; i < b->deckCount[player] || i < b->handCount[player] || i< b->discardCount[player] || i < b->playedCardCount; ++i){
        if (i< b->deckCount[player])countb[b->deck[player][i]]++;
        if (i< b->handCount[player])countb[b->hand[player][i]]++;
        if (i< b->discardCount[player])countb[b->discard[player][i]]++;
        if (i< b->playedCardCount) countb[b->playedCards[i]]++;
    }

/*    for (i=0; i<treasure_map; ++i){
        printf("%i a:%d b:%d   %d\n", i, counta[i],countb[i], counta[i] ==countb[i]);
    }*/
    for (i=0; i<treasure_map; ++i){
        if (counta[i] != countb[i]) return 0;
    }

    return 1;
}

void cpyDeck(int* dest, int* src, int n){
    int* end = src + n;
    for(;src<end; ++src, ++dest) *dest = *src;
}
