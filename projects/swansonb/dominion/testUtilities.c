#include "testUtilities.h"
#include <string.h>

void copyGameState(struct gameState* dest, struct gameState* src) {
    memcpy(dest, src, sizeof(*dest));
}

int equalGameStates(struct gameState* a, struct gameState* b) {
    return (memcmp(a,b,sizeof(*a)) == 0);
}
