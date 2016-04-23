#include "testUtilities.h"
#include <string.h>

struct gameState copyGameState(struct gameState g) {
    struct gameState output;
    memcpy(&output, &g, sizeof(output));
    return output;
}

int equalGameStates(struct gameState a, struct gameState b) {
    return (memcmp(&a,&b,sizeof(a)) == 0);
}
