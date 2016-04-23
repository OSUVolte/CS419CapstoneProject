#include "testUtilities.h"
#include <string.h>
#include "dominion.h"

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

void cpyDeck(int* dest, int* src, int n){
    int* end = src + n;
    for(;src<end; ++src, ++dest) *dest = *src;
}
